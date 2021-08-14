/**
 * @file mavlink_interface.h
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

#ifndef MAVLINK_INTERFACE_H_
#define MAVLINK_INTERFACE_H_

// ------------------------------------------------------------------------------
//   Includes
// ------------------------------------------------------------------------------
#include "../legacy/generic_port.h"
#include "../mavlink_protocol/aimirobot/mavlink.h"
#include "../legacy/linux_serial.h"

// ------------------------------------------------------------------------------
//   Defines
// ------------------------------------------------------------------------------
#define Aimibot_Mav_Sys_ID        0         //!< the systerm ID of this machine
#define Aimibot_Mav_Target_Sys_ID 1         //!< the systerm ID of target systerm 
#define Aimibot_Mav_Component_ID  1         //!< the Component ID of this machine
#define Aimibot_Mav_Robot_Type    AMB_TYPE_DIFFERENTIAL   //!< the type of robot
#define Aimibot_Mav_Robot_Mode    AMB_MODE_FLAG_ARMED   //!< the type of robot
#define Aimibot_Mav_Robot_Status    AMB_STATE_ACTIVE   //!< the type of robot

#define Aimibot_PI          3.1416         //!< PI
#define Aimibot_Wheel_DIAMETER          0.33         //!< Wheel diameter unit:m
#define Aimibot_LineSpeed_MAX           1.5         //!< the max value of the line speed, unit:m/s
#define Aimibot_AngularSpeed_MAX        Aimibot_PI/2        //!< the max value of the angular speed, unit:rad/s
#define Aimibot_Acceleration_MAX        1         //!< the max value of the line speed, unit:m/s^2
#define Aimibot_Feedback_Frequency_MAX  50        //!< the max frequency of the feedback data, unit:hz

// ------------------------------------------------------------------------------
//   Prototypes
// ------------------------------------------------------------------------------
struct Mavlink_Msg_Register_t {
	

    /* define the Command data structure */
//   mavlink_heartbeat_t  Mav_HeartBeat_Cmd;
    // mavlink_ping_t  Mav_PING_Cmd;
    // mavlink_param_request_read_t  Mav_Param_Request_Read_Cmd;
    // mavlink_param_request_list_t  Mav_Param_Request_List_Cmd;
    // mavlink_param_value_t  Mav_Param_Value_Cmd;
    // mavlink_param_set_t  Mav_Param_Set_Cmd;
    // mavlink_command_long_t  Mav_Command_Long_Cmd;

    mavlink_command_ack_t Mav_Cmd_ACK_Data;
    /* define the Feedback data structure */
    mavlink_heartbeat_t	 Mav_Heartbeat_Data;
    mavlink_sys_core_status_t  Mav_SysStatus_Data;
    mavlink_sys_info_version_t  Mav_SysInfo_Data;
    mavlink_scaled_imu_t  Mav_ScaledIMU_Data;
    mavlink_attitude_t  Mav_Attitude_Data;
    mavlink_twist_t  Mav_Twist_Data;
    mavlink_torque_t  Mav_Torque_Data;
    mavlink_gpio_t  Mav_GPIO_Data;
    mavlink_analog_t  Mav_Analog_Data;
    mavlink_infrared_t  Mav_Infrared_Data;
    mavlink_ultrasonic_t  Mav_Sonic_Data;

};


// ----------------------------------------------------------------------------------
//   Mavlink interface Class
// ----------------------------------------------------------------------------------
class Mavlink_Interface
{
public:
    Mavlink_Interface();
    Mavlink_Interface(const char *uart_name_, int baudrate_);
    ~Mavlink_Interface();

    uint8_t Mav_AimibotSys_ID = 0;
    void Set_Serial(const char *uart_name_, int baudrate_);
	int start();
	int stop();
    bool is_running();
    int read_message(mavlink_message_t &message);
    int write_message(const mavlink_message_t &message);

    int Mav_Msg_Handler(mavlink_message_t* r_message,Mavlink_Msg_Register_t* msg_register);
    int Mav_Set_Heatbeat(uint32_t error_code);
    int Mav_Set_Cmd_Long(uint8_t target_sys_id, AMB_CMD AMB_CMD_enum,uint8_t confirm_flag,float Parm_1,float Parm_2,float Parm_3,float Parm_4,float Parm_5,float Parm_6,float Parm_7);
    int Mav_Set_Cmd_Long_Mode(uint8_t confirm_flag,AMB_MODE_FLAG robot_mode); 
    int Mav_Set_Cmd_Long_Velocity(uint8_t confirm_flag,float Vx,float Wz);
    int Mav_Set_Cmd_Long_Torque(uint8_t confirm_flag,float Joint_1,float Joint_2,float Joint_3,float Joint_4,float Joint_5,float Joint_6);
    int Mav_Set_Cmd_Long_Acceleration(uint8_t confirm_flag,float accel);
    int Mav_Set_Cmd_Long_GPIO_Output(uint8_t confirm_flag,uint16_t GPIO_Bit_Mapping);
    int Mav_Set_Cmd_Long_Analog_Output(uint8_t confirm_flag,float Channel_1,float Channel_2,float Channel_3,float Channel_4,float Channel_5,float Channel_6,float Channel_7);
    int Mav_Set_Cmd_Long_Frequency(uint8_t confirm_flag, uint8_t Freq_Sys_Core_Status,uint8_t Freq_IMU,uint8_t Freq_Attitude,uint8_t Freq_Twist,uint8_t Freq_Torque,uint8_t Freq_GPIO);

private:
    const char *uart_name;
	int  baudrate;
    bool is_open;
    Generic_Port *port;

    void initialize_defaults();
};





#endif // MAVLINK_INTERFACE_H_
