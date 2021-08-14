/**
 * @file mavlink_interface.cpp
 * @brief 
 * @author Hang Zhong (zhonghanghnueeit@gmail.com)
 * @version 1.0
 * @date 2020-05-08
 * 
 * @copyright Copyright (c) 2020  aimijia tech
 * 
 * @par Modify log:
 * <table>
 * <tr><th>Date       <th>Version <th>Author  <th>Description
 * <tr><td>2020-05-08 <td>1.0     <td>Hang Zhong     <td>***
 * </table>
 */

// ------------------------------------------------------------------------------
//   Includes
// ------------------------------------------------------------------------------

#include "../include/legacy/mavlink_interface.h"
#include <iostream>
//#include <pthread.h> // This uses POSIX Threads
#include <thread>
#include <unistd.h>  // UNIX standard function definitions
// ----------------------------------------------------------------------------------
//   Mavlink interface Class
// ----------------------------------------------------------------------------------

using namespace std;

uint8_t Cmd_Mode_AckFlag = AMB_RESULT_FALSE;
uint8_t Cmd_Velocity_AckFlag = AMB_RESULT_FALSE;
uint8_t Cmd_Torque_AckFlag = AMB_RESULT_FALSE;
uint8_t Cmd_Acceleration_AckFlag = AMB_RESULT_FALSE;
uint8_t Cmd_GPIO_AckFlag = AMB_RESULT_FALSE;
uint8_t Cmd_Analog_AckFlag = AMB_RESULT_FALSE;
uint8_t Cmd_Frequency_AckFlag = AMB_RESULT_FALSE;

extern uint32_t global_cur_count;

/**
 * @brief Construct a new Mavlink_Interface::Mavlink_Interface object
 */
Mavlink_Interface::Mavlink_Interface()
{
    initialize_defaults();
    //~ port = new Serial_Port(uart_name, baudrate);
}

/**
 * @brief Construct a new Mavlink_Interface::Mavlink_Interface object
 * @param  uart_name_       the uart name pointer
 * @param  baudrate_        baud rate
 */
//~ Mavlink_Interface::Mavlink_Interface(const char *uart_name_, int baudrate_)
//~ {
    //~ initialize_defaults();
    //~ uart_name = uart_name_;
	//~ baudrate  = baudrate_;
    //~ port = new Serial_Port(uart_name, baudrate);
//~ }

/**
 * @brief Destroy the Mavlink_Interface::Mavlink_Interface object
 */
Mavlink_Interface::~Mavlink_Interface()
{
    delete port;
}


void Mavlink_Interface::Set_Serial(const char *uart_name_, int baudrate_)
{
    initialize_defaults();
    uart_name = uart_name_;
	baudrate  = baudrate_;
    port = new Serial_Port(uart_name, baudrate);
}


/**
 * @brief initialize defaults values
 */
void Mavlink_Interface::initialize_defaults()
{
    uart_name = (char*)"/dev/ttyUSB1";
	baudrate = 921600;
    is_open = false;
}

/**
 * @brief open the general port
 * @return int 
 * @retval 0        open success
 * @retval -1       open failed
 * @retval -2       setup failed
 */
int Mavlink_Interface::start()
{
    //open and setup the port
    if(port->Open() != -3)
    {
        if(!port->Setup())
        {
            is_open = true;
        }else
        {
            return(-2);
        } 
    }else
    {
        return(-1);
    }
    
    return(0);
}

/**
 * @brief close the general port
 * @return int 
 * @retval 0        close success
 */
int Mavlink_Interface::stop()
{
    //close the port
    port->Close();
    is_open = false;

    return(0);
}

/**
 * @brief return the status of the port
 * @return true         open
 * @return false        close
 */
bool Mavlink_Interface::is_running()
{
    return(is_open);
}

/**
 * @brief  read mavlink message from port, one time get one byte
 * @param  message          mavlink_message_t data
 * @return int 
 * @retval 0                0 if no message could be decoded or bad CRC
 * @retval 1                1 on good message and CRC
 */
int Mavlink_Interface::read_message(mavlink_message_t &message)
{
    unsigned char       cp = 0;
	mavlink_status_t    status;
	uint8_t             msgReceived = false;
    int                 result = true;
    
    //read one byte order, when a message is complete or no data available
    while(result and (!msgReceived))
    {
        result = port->Read(&cp, 1);
      
        if(result)
        {		
            // the parsing
		    msgReceived = mavlink_parse_char(MAVLINK_COMM_1, cp, &message, &status);
		    
        }
    }
    
    /*//read one byte
    int result = port->Read(cp, 1);

    //PARSE MESSAGE
    if(result > 0)
    {
        // the parsing
		msgReceived = mavlink_parse_char(MAVLINK_COMM_1, *cp, &message, &status);
    }*/
    return msgReceived;
}

/**
 * @brief Write mavlink message to port
 * @param  message          My Param doc
 * @return int 
 */
int Mavlink_Interface::write_message(const mavlink_message_t &message)
{
    unsigned char buff[256];

    // Translate message to buffer
	unsigned len = mavlink_msg_to_send_buffer((uint8_t*)buff, &message);

	// Write buffer to serial port, locks port while writing
	int bytesWritten = port->Write(buff, len);

	return bytesWritten;
}

/**
 * @brief   Handle the message recieved from the Usart by mavlink protocol
 * @param   r_message  pointer to the data recieved from the Usart
 * @param   msg_register    pointer to the data register which used to store the message
 * @return  0
 */
int Mavlink_Interface::Mav_Msg_Handler(mavlink_message_t* r_message,Mavlink_Msg_Register_t* msg_register)
{
	uint8_t ret = 0;
    uint8_t result ;
    uint16_t Com_ID ;
	switch(r_message->msgid)
	{
		
		case MAVLINK_MSG_ID_HEARTBEAT:
		        mavlink_msg_heartbeat_decode(r_message,&msg_register->Mav_Heartbeat_Data);		//!< get the msg
                ret = 1;
		break;
        case MAVLINK_MSG_ID_SYS_CORE_STATUS:
                mavlink_msg_sys_core_status_decode(r_message,&msg_register->Mav_SysStatus_Data);
				 global_cur_count++;
				 ret = 2;
        break;
        case MAVLINK_MSG_ID_SYS_INFO_VERSION:
                mavlink_msg_sys_info_version_decode(r_message,&msg_register->Mav_SysInfo_Data);
                ret = 3;
        break;
        case MAVLINK_MSG_ID_SCALED_IMU:
                mavlink_msg_scaled_imu_decode(r_message,&msg_register->Mav_ScaledIMU_Data);
                ret = 6;
        break;
        case MAVLINK_MSG_ID_ATTITUDE:
                mavlink_msg_attitude_decode(r_message,&msg_register->Mav_Attitude_Data);
                ret = 7;
        break;
        case MAVLINK_MSG_ID_TWIST:
                mavlink_msg_twist_decode(r_message,&msg_register->Mav_Twist_Data);
                ret = 5;
        break;
        case MAVLINK_MSG_ID_TORQUE:
                mavlink_msg_torque_decode(r_message,&msg_register->Mav_Torque_Data);
        break;
        case MAVLINK_MSG_ID_GPIO:
                mavlink_msg_gpio_decode(r_message,&msg_register->Mav_GPIO_Data);
                ret = 4;
        break;
        case MAVLINK_MSG_ID_ANALOG:
                mavlink_msg_analog_decode(r_message,&msg_register->Mav_Analog_Data);
        break;
        case MAVLINK_MSG_ID_Infrared:
                mavlink_msg_infrared_decode(r_message,&msg_register->Mav_Infrared_Data);
        break;
        case MAVLINK_MSG_ID_Ultrasonic:
                mavlink_msg_ultrasonic_decode(r_message,&msg_register->Mav_Sonic_Data);
        break;
        case MAVLINK_MSG_ID_COMMAND_ACK:
                 result = mavlink_msg_command_ack_get_result(r_message);        //!< Get the confirming result
                 Com_ID = mavlink_msg_command_ack_get_command(r_message);       //!< get the ID that shows this confirmation's command type
 //              cout << "got_ack: ID = "<< Com_ID <<endl;
                 ret = Com_ID;      //just for test
                switch (Com_ID)
                {
                    case AMB_CMD_MSG_FREQUENCY_CTL:
                    if (result == AMB_RESULT_TRUE)
                    {
                        Cmd_Frequency_AckFlag = AMB_RESULT_TRUE;      //!< got the confirmation and set the flag
                    }
                        break;
                    default:
                        break;
                }
        break;
		default:
		break;
	}
	
	return ret;	//success
}


/**
 * @brief   Set teh command long data
 * @param   target_sys_id   the systerm ID of the one that you want to send it this command
 * @param   AMB_CMD_enum    the type of the command 
 * @param   confirm_flag    0: the system do not send confirmation. 1-255: the system must send back the confirmation.
 * @param   Parm_X          the value of the special parameter according to the type of the command [AMB_CMD_enum]
 * @return  0 
 */
int Mavlink_Interface::Mav_Set_Cmd_Long(uint8_t target_sys_id,AMB_CMD AMB_CMD_enum,uint8_t confirm_flag,
                                        float Parm_1,
                                        float Parm_2,
                                        float Parm_3,
                                        float Parm_4,
                                        float Parm_5,
                                        float Parm_6,
                                        float Parm_7)
{
    mavlink_message_t mavink_msg;

    /*! pack the command_long  */
    mavlink_msg_command_long_pack(Aimibot_Mav_Sys_ID,Aimibot_Mav_Component_ID,&mavink_msg,target_sys_id,AMB_CMD_enum,confirm_flag,
                                        Parm_1,Parm_2,Parm_3,Parm_4,Parm_5,Parm_6,Parm_7);

	/*! send the message */ 
	write_message(mavink_msg);

    return 0;
}


/**
 * @brief   Set the robot mode 
 * @param   confirm_flag    0: the system do not send confirmation. 1-255: the system must send back the confirmation.
 * @param   robot_mode      robot mode @AMB_MODE_FLAG
 * @return  0 -> success
 */
int Mavlink_Interface::Mav_Set_Cmd_Long_Mode(uint8_t confirm_flag,AMB_MODE_FLAG robot_mode)
{
    float Parm_1,Parm_2,Parm_3,Parm_4,Parm_5,Parm_6,Parm_7;
    mavlink_message_t mavink_msg;

    /*! check and modify the parameter */
    if(robot_mode > AMB_MODE_FLAG_ENUM_END)
    {
        return 1;   //!< paramter error
    }
    /*! assignment */
    Parm_1 = robot_mode;   

    /*! pack the command_long  */
    mavlink_msg_command_long_pack(Aimibot_Mav_Sys_ID,Aimibot_Mav_Component_ID,&mavink_msg,Aimibot_Mav_Target_Sys_ID,AMB_CMD_MODE_CTL,confirm_flag,
                                  Parm_1,Parm_2,Parm_3,Parm_4,Parm_5,Parm_6,Parm_7);

	/*! send the message */ 
	write_message(mavink_msg);  
    
    return 0;
}


/**
 * @brief   Set the robot velocity  
 * @param   confirm_flag    0: the system do not send confirmation. 1-255: the system must send back the confirmation.
 * @param   Vx              line speed,unit: m/s ,range:[-1~+1]
 * @param   Wz              angular speed,unit: rad/s,range:[-PI~+PI]
 * @return  0 
 */
int Mavlink_Interface::Mav_Set_Cmd_Long_Velocity(uint8_t confirm_flag,float Vx,float Wz)
{
    float Parm_1,Parm_2,Parm_3,Parm_4,Parm_5,Parm_6,Parm_7;
    mavlink_message_t mavink_msg;

    /*! check and modify the parameter */
    if(fabs(Vx) > Aimibot_LineSpeed_MAX)
    {
        if(Vx>0)
        {
            Vx = Aimibot_LineSpeed_MAX;
        }
        else
        {
            Vx = -Aimibot_LineSpeed_MAX;
        }
    }
    if(fabs(Wz) > Aimibot_AngularSpeed_MAX)
    {
        if(Wz>0)
        {
            Wz = Aimibot_AngularSpeed_MAX;
        }
        else
        {
            Wz = -Aimibot_AngularSpeed_MAX;
        }
    }   

    /*! assignment */
    Parm_1 = Vx;   
    Parm_6 = Wz;

    /*! pack the command_long  */
    mavlink_msg_command_long_pack(Aimibot_Mav_Sys_ID,Aimibot_Mav_Component_ID,&mavink_msg,Aimibot_Mav_Target_Sys_ID,AMB_CMD_VELOCITY_CTL,confirm_flag,
                                  Parm_1,Parm_2,Parm_3,Parm_4,Parm_5,Parm_6,Parm_7);

	/*! send the message */ 
	write_message(mavink_msg);

    return 0;
}


/**
 * @brief   Set the robot torque  
 * @param   confirm_flag    0: the system do not send confirmation. 1-255: the system must send back the confirmation.
 * @param   Joint_1         uint:n/m
 * @return  0 
 */
int Mavlink_Interface::Mav_Set_Cmd_Long_Torque(uint8_t confirm_flag,float Joint_1,float Joint_2,float Joint_3,float Joint_4,float Joint_5,float Joint_6)
{
    float Parm_1,Parm_2,Parm_3,Parm_4,Parm_5,Parm_6,Parm_7;
    mavlink_message_t mavink_msg;

    /*! assignment */
    Parm_1 = Joint_1;   
    Parm_2 = Joint_2;
    Parm_3 = Joint_3;
    Parm_4 = Joint_4;
    Parm_5 = Joint_5;
    Parm_6 = Joint_6;

    /*! pack the command_long  */
    mavlink_msg_command_long_pack(Aimibot_Mav_Sys_ID,Aimibot_Mav_Component_ID,&mavink_msg,Aimibot_Mav_Target_Sys_ID,AMB_CMD_TORQUE_CTL,confirm_flag,
                                  Parm_1,Parm_2,Parm_3,Parm_4,Parm_5,Parm_6,Parm_7);

	/*! send the message */ 
	write_message(mavink_msg);    

    return 0;
}


/**
 * @brief   Set the robot acceleration 
 * @param   confirm_flag    0: the system do not send confirmation. 1-255: the system must send back the confirmation.
 * @param   accel           the acceleration of the robot ,uint:m/s^2 ,range:[0, 65535]. 
 * @return  0  
 */
int Mavlink_Interface::Mav_Set_Cmd_Long_Acceleration(uint8_t confirm_flag,float accel)
{
    float Parm_1,Parm_2,Parm_3,Parm_4,Parm_5,Parm_6,Parm_7;
    mavlink_message_t mavink_msg;

    /*! check and modify the parameter */
    if(fabs(accel) > Aimibot_Acceleration_MAX)
    {
        if(accel>0)
        {
            accel = Aimibot_Acceleration_MAX;
        }
        else
        {
            accel = -Aimibot_Acceleration_MAX;
        }
    }
    if(accel = 0)
    {
        /* The motor will stop */
    }

    /*! assignment */
    Parm_1 = accel;   

    /*! pack the command_long  */
    mavlink_msg_command_long_pack(Aimibot_Mav_Sys_ID,Aimibot_Mav_Component_ID,&mavink_msg,Aimibot_Mav_Target_Sys_ID,AMB_CMD_ACCELERATION_CTL,confirm_flag,
                                  Parm_1,Parm_2,Parm_3,Parm_4,Parm_5,Parm_6,Parm_7);

	/*! send the message */ 
	write_message(mavink_msg);

    return 0;
}


/**
 * @brief   Set the robot GPIO_Output 
 * @param   confirm_flag    0: the system do not send confirmation. 1-255: the system must send back the confirmation.
 * @param   GPIO_Bit_Mapping    the bit mapping of the Output Port 
 * @return  0 
 */
int Mavlink_Interface::Mav_Set_Cmd_Long_GPIO_Output(uint8_t confirm_flag,uint16_t GPIO_Bit_Mapping) 
{
    float Parm_1,Parm_2,Parm_3,Parm_4,Parm_5,Parm_6,Parm_7;
    mavlink_message_t mavink_msg;

    /*! assignment */
    Parm_1 = GPIO_Bit_Mapping;   

    /*! pack the command_long  */
    mavlink_msg_command_long_pack(Aimibot_Mav_Sys_ID,Aimibot_Mav_Component_ID,&mavink_msg,Aimibot_Mav_Target_Sys_ID,AMB_CMD_GPIO_OUTPUT_CTL,confirm_flag,
                                  Parm_1,Parm_2,Parm_3,Parm_4,Parm_5,Parm_6,Parm_7);

 	/*! send the message */ 
	write_message(mavink_msg);

    return 0;
}


/**
 * @brief   Set the robot analog_Output 
 * @param   confirm_flag    0: the system do not send confirmation. 1-255: the system must send back the confirmation.
 * @param   Channel_X       the analog channel output ,unit: mv ,range: [0-65535]
 * @return  0 
 */
int Mavlink_Interface::Mav_Set_Cmd_Long_Analog_Output(uint8_t confirm_flag,float Channel_1,float Channel_2,float Channel_3,float Channel_4,float Channel_5,float Channel_6,float Channel_7)
{
    float Parm_1,Parm_2,Parm_3,Parm_4,Parm_5,Parm_6,Parm_7;
    mavlink_message_t mavink_msg;

    /*! assignment */
    Parm_1 = Channel_1;   
    Parm_2 = Channel_2;
    Parm_3 = Channel_3;
    Parm_4 = Channel_4;
    Parm_5 = Channel_5;
    Parm_6 = Channel_6;   
    Parm_7 = Channel_7;

    /*! pack the command_long  */
    mavlink_msg_command_long_pack(Aimibot_Mav_Sys_ID,Aimibot_Mav_Component_ID,&mavink_msg,Aimibot_Mav_Target_Sys_ID,AMB_CMD_ANALOG_OUTPUT_CTL,confirm_flag,
                                  Parm_1,Parm_2,Parm_3,Parm_4,Parm_5,Parm_6,Parm_7);
    
	/*! send the message */ 
	write_message(mavink_msg);

    return 0;
}


/**
 * @brief   Set the robot feedback freqency of special datatype 
 * @param   confirm_flag    0: the system do not send confirmation. 1-255: the system must send back the confirmation.
 * @param   Freq_Sys_Core_Status    the feedback frequency of the Sys_Core_Status data,unit: Hz ,range:[0-50] ,if the value = 0,this Msg will be closed
 * @param   Freq_IMU        the feedback frequency of the IMU, unit: Hz ,range:[0-50] ,if the value = 0,this Msg will be closed
 * @param   Freq_Attitude   the feedback frequency of the Attitude, unit: Hz ,range:[0-50] ,if the value = 0,this Msg will be closed
 * @param   Freq_Twist      the feedback frequency of the Twist, unit: Hz ,range:[0-50] ,if the value = 0,this Msg will be closed
 * @param   Freq_Torque     the feedback frequency of the Torque, unit: Hz ,range:[0-50] ,if the value = 0,this Msg will be closed
 * @param   Freq_GPIO       the feedback frequency of the GPIO, unit: Hz ,range:[0-50] ,if the value = 0,this Msg will be closed
 * @return  0 
 */
int Mavlink_Interface::Mav_Set_Cmd_Long_Frequency(uint8_t confirm_flag, uint8_t Freq_Sys_Core_Status,uint8_t Freq_IMU,uint8_t Freq_Attitude,uint8_t Freq_Twist,uint8_t Freq_Torque,uint8_t Freq_GPIO)
{
    float Parm_1,Parm_2,Parm_3,Parm_4,Parm_5,Parm_6,Parm_7;
    mavlink_message_t mavink_msg;
    uint16_t count;
    uint8_t ret = 0;

    /*! check and modify the parameter */
    Freq_Sys_Core_Status = (Freq_Sys_Core_Status>Aimibot_Feedback_Frequency_MAX)?Aimibot_Feedback_Frequency_MAX:Freq_Sys_Core_Status;
    Freq_IMU = (Freq_IMU>Aimibot_Feedback_Frequency_MAX)?Aimibot_Feedback_Frequency_MAX:Freq_IMU;
    Freq_Attitude = (Freq_Attitude>Aimibot_Feedback_Frequency_MAX)?Aimibot_Feedback_Frequency_MAX:Freq_Attitude;
    Freq_Twist = (Freq_Twist>Aimibot_Feedback_Frequency_MAX)?Aimibot_Feedback_Frequency_MAX:Freq_Twist;
    Freq_Torque = (Freq_Torque>Aimibot_Feedback_Frequency_MAX)?Aimibot_Feedback_Frequency_MAX:Freq_Torque;
    Freq_GPIO = (Freq_GPIO>Aimibot_Feedback_Frequency_MAX)?Aimibot_Feedback_Frequency_MAX:Freq_GPIO;
    
    /*! assignment */
    Parm_1 = Freq_Sys_Core_Status;
    Parm_2 = Freq_IMU;
    Parm_3 = Freq_Attitude;
    Parm_4 = Freq_Twist;
    Parm_5 = Freq_Torque;
    Parm_6 = Freq_GPIO;

    /*! pack the command_long  */
    mavlink_msg_command_long_pack(Aimibot_Mav_Sys_ID,Aimibot_Mav_Component_ID,&mavink_msg,Aimibot_Mav_Target_Sys_ID,AMB_CMD_MSG_FREQUENCY_CTL,confirm_flag,
                                  Parm_1,Parm_2,Parm_3,Parm_4,Parm_5,Parm_6,Parm_7);
    
    /*! send the message */ 
	write_message(mavink_msg);
    cout << "------------------------------------------------------------------- " << count <<endl;
    cout << "Write done ！" <<endl;

    if(confirm_flag)
    {
		
        Cmd_Frequency_AckFlag = AMB_RESULT_FALSE;     //!< reset the flag
        while(!Cmd_Frequency_AckFlag)
        {
            /*! keep wait for the confirmation  */
            this_thread::sleep_for(std::chrono::microseconds(10));  //!< wait 10us
            //usleep(10);
            count++;
            if(count > 1000)
            {
                ret = 1;    //!< time out 10ms
                cout << "timeout!: " << count <<endl;
                break;
            }
        }
    }

    return ret;     //!< 0 -> success
}


/**
 * @brief   Set the heatbeat data
 * @param   error_code   the error code of this machine
 * @return  0
 */
int Mavlink_Interface::Mav_Set_Heatbeat(uint32_t error_code)
{
    mavlink_message_t mavink_msg;

    /*! pack the heartbeat data */
    mavlink_msg_heartbeat_pack(Aimibot_Mav_Sys_ID, 
                                Aimibot_Mav_Component_ID,
                                &mavink_msg,
                                Aimibot_Mav_Robot_Type,
                                Aimibot_Mav_Robot_Mode,
                                Aimibot_Mav_Robot_Status,
                                error_code);

	/*! send the message */ 
	write_message(mavink_msg);

    return 0;
}
