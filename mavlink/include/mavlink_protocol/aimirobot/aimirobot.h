/** @file
 *  @brief MAVLink comm protocol generated from aimirobot.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_AIMIROBOT_H
#define MAVLINK_AIMIROBOT_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_AIMIROBOT.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{0, 164, 8, 8, 0, 0, 0}, {2, 100, 13, 13, 1, 12, 0}, {20, 255, 19, 19, 1, 2, 0}, {21, 253, 1, 1, 1, 0, 0}, {22, 220, 25, 25, 0, 0, 0}, {23, 39, 22, 22, 1, 4, 0}, {30, 198, 32, 32, 1, 30, 0}, {31, 143, 3, 3, 0, 0, 0}, {50, 204, 17, 17, 0, 0, 0}, {51, 237, 12, 12, 0, 0, 0}, {52, 170, 22, 24, 0, 0, 0}, {53, 39, 28, 28, 0, 0, 0}, {54, 16, 28, 28, 0, 0, 0}, {55, 31, 32, 32, 0, 0, 0}, {56, 149, 12, 12, 0, 0, 0}, {57, 139, 60, 60, 0, 0, 0}, {58, 163, 10, 10, 0, 0, 0}, {59, 154, 16, 16, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_AIMIROBOT

// ENUM DEFINITIONS


/** @brief Autonomous mobile robot type enum classes. This identifies the robot type model. */
#ifndef HAVE_ENUM_AMB_TYPE
#define HAVE_ENUM_AMB_TYPE
typedef enum AMB_TYPE
{
   AMB_TYPE_DIFFERENTIAL=0, /* Differential drive mobile robot. | */
   AMB_TYPE_OMNIDIRECTIONAL=1, /* Omnidirectional drive mobile robot. | */
   AMB_TYPE_ACKERMANN=2, /* Ackerman drive mobile robot, like car. | */
   AMB_TYPE_ENUM_END=3, /*  | */
} AMB_TYPE;
#endif

/** @brief These flags encode the AMR mode. */
#ifndef HAVE_ENUM_AMB_MODE_FLAG
#define HAVE_ENUM_AMB_MODE_FLAG
typedef enum AMB_MODE_FLAG
{
   AMB_MODE_FLAG_DISARMED=0, /* 0b00000000 AMB set to disarmed. Motors are disenabled. | */
   AMB_MODE_FLAG_ARMED=1, /* 0b00000001 AMB set to armed. Motors are enabled / running / can start. Ready to Move. | */
   AMB_MODE_FLAG_TORQUE_MODE_ENABLED=2, /* 0b00000010 AMB set to torque(current) control mode. | */
   AMB_MODE_FLAG_SPEED_MODE_ENABLED=4, /* 0b00000100 AMB set to speed control mode. | */
   AMB_MODE_FLAG_ENUM_END=5, /*  | */
} AMB_MODE_FLAG;
#endif

/** @brief These flags encode the AMR status. */
#ifndef HAVE_ENUM_AMB_STATE
#define HAVE_ENUM_AMB_STATE
typedef enum AMB_STATE
{
   AMB_STATE_UNINIT=0, /* Uninitialized system, state is unknown. | */
   AMB_STATE_BOOTING=1, /* System is booting up. | */
   AMB_STATE_CALIBRATING=2, /* System is calibrating and not move ready. | */
   AMB_STATE_STANDBY=3, /* System is on standby. It can be move any time. | */
   AMB_STATE_ACTIVE=4, /* System is active and moving. Motors are engaged. | */
   AMB_STATE_EMERGENCYSTOP=5, /* System is in emergency stop, it may be cased by . | */
   AMB_STATE_ERROR=6, /* System is in error mode. | */
   AMB_STATE_ENUM_END=7, /*  | */
} AMB_STATE;
#endif

/** @brief The confirming result of the COMMAND_LONG. */
#ifndef HAVE_ENUM_AMB_RESULT
#define HAVE_ENUM_AMB_RESULT
typedef enum AMB_RESULT
{
   AMB_RESULT_FALSE=0, /* Success. | */
   AMB_RESULT_TRUE=1, /* False. | */
   AMB_RESULT_ENUM_END=2, /*  | */
} AMB_RESULT;
#endif

/** @brief These encode the sensors whose status is sent as part of the SYS_CORE_STATUS message. */
#ifndef HAVE_ENUM_AMB_SYS_STATUS_SENSOR
#define HAVE_ENUM_AMB_SYS_STATUS_SENSOR
typedef enum AMB_SYS_STATUS_SENSOR
{
   AMB_SYS_STATUS_SENSOR_3D_GYRO=1, /* 0x01 3D gyro | */
   AMB_SYS_STATUS_SENSOR_3D_ACCEL=2, /* 0x02 3D accelerometer | */
   AMB_SYS_STATUS_SENSOR_3D_MAG=4, /* 0x04 3D magnetometer | */
   MAV_SYS_STATUS_SENSOR_ULTRASONIC=8, /* 0x08 ultrasonic array | */
   MAV_SYS_STATUS_SENSOR_INFRARED=16, /* 0x10 infrared array | */
   MAV_SYS_STATUS_SENSOR_PM25=32, /* 0x20 PM2.5 sensor | */
   MAV_SYS_STATUS_SENSOR_TEMPERATURE_HUMIDITY=64, /* 0x40 temperature and humidity sensor | */
   MAV_SYS_STATUS_SENSOR_CARBON=128, /* 0x80 carbon dioxide sensor | */
   MAV_SYS_STATUS_SENSOR_TOTAL_VOC=256, /* 0x100 laser based total VOC sensor | */
   MAV_SYS_STATUS_SENSOR_GRID_EYE=512, /* 0x200 panasonic infrared array sensor (grid eye) | */
   AMB_SYS_STATUS_SENSOR_ENUM_END=513, /*  | */
} AMB_SYS_STATUS_SENSOR;
#endif

/** @brief Specifies the datatype of a MAVLink parameter. */
#ifndef HAVE_ENUM_AMB_PARAM_TYPE
#define HAVE_ENUM_AMB_PARAM_TYPE
typedef enum AMB_PARAM_TYPE
{
   AMB_PARAM_TYPE_UINT8=1, /* 8-bit unsigned integer | */
   AMB_PARAM_TYPE_INT8=2, /* 8-bit signed integer | */
   AMB_PARAM_TYPE_UINT16=3, /* 16-bit unsigned integer | */
   AMB_PARAM_TYPE_INT16=4, /* 16-bit signed integer | */
   AMB_PARAM_TYPE_UINT32=5, /* 32-bit unsigned integer | */
   AMB_PARAM_TYPE_INT32=6, /* 32-bit signed integer | */
   AMB_PARAM_TYPE_UINT64=7, /* 64-bit unsigned integer | */
   AMB_PARAM_TYPE_INT64=8, /* 64-bit signed integer | */
   AMB_PARAM_TYPE_REAL32=9, /* 32-bit floating-point | */
   AMB_PARAM_TYPE_REAL64=10, /* 64-bit floating-point | */
   AMB_PARAM_TYPE_ENUM_END=11, /*  | */
} AMB_PARAM_TYPE;
#endif

/** @brief Commands to be executed by the AMB. They can be executed on user request, or as part of a mission script. */
#ifndef HAVE_ENUM_AMB_CMD
#define HAVE_ENUM_AMB_CMD
typedef enum AMB_CMD
{
   AMB_CMD_MODE_CTL=1, /* Control the vehicle mode. |Setting mode for the robot.| Empty| Empty| Empty| Empty| Empty| Empty|  */
   AMB_CMD_VELOCITY_CTL=2, /* Setting the vehicle moving speed. This entry is valid only in AMB_MODE_FLAG_SPEED_MODE_ENABLED mode. |Linear speed in X direction| Linear speed in Y direction| Linear speed in Z direction| Angular speed in X direction| Angular speed in Y direction| Angular speed in Z direction| Empty|  */
   AMB_CMD_TORQUE_CTL=3, /* Setting the vehicle moving torque. This entry is valid only in AMB_MODE_FLAG_TORQUE_MODE_ENABLED mode. |Joint one torque| Joint two torque| Joint three torque| Joint four torque| Joint five torque| Joint six torque| Empty|  */
   AMB_CMD_ACCELERATION_CTL=4, /* Setting the vehicle moving acceleration ratio.  Value range:[0, 65535]. |Acceleration for all joint| Empty| Empty| Empty| Empty| Empty| Empty|  */
   AMB_CMD_GPIO_OUTPUT_CTL=5, /* Setting the vehicle onboard GPIO output. |GPIO bit mapping| Empty| Empty| Empty| Empty| Empty| Empty|  */
   AMB_CMD_ANALOG_OUTPUT_CTL=6, /* Setting the vehicle onboard analog output. |Analog output channel one| Analog output channel two| Analog output channel three| Analog output channel four| Analog output channel five| Analog output channel six| Analog output channel seven|  */
   AMB_CMD_MSG_FREQUENCY_CTL=7, /* Setting the vehicle onboard analog output. |if the value = 0,this Msg will be close| if the value = 0,this Msg will be close| if the value = 0,this Msg will be close| if the value = 0,this Msg will be close| if the value = 0,this Msg will be close| if the value = 0,this Msg will be close|  Empty|  */
   AMB_CMD_ENUM_END=8, /*  | */
} AMB_CMD;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_heartbeat.h"
#include "./mavlink_msg_ping.h"
#include "./mavlink_msg_param_request_read.h"
#include "./mavlink_msg_param_request_list.h"
#include "./mavlink_msg_param_value.h"
#include "./mavlink_msg_param_set.h"
#include "./mavlink_msg_command_long.h"
#include "./mavlink_msg_command_ack.h"
#include "./mavlink_msg_sys_core_status.h"
#include "./mavlink_msg_sys_info_version.h"
#include "./mavlink_msg_scaled_imu.h"
#include "./mavlink_msg_attitude.h"
#include "./mavlink_msg_twist.h"
#include "./mavlink_msg_torque.h"
#include "./mavlink_msg_gpio.h"
#include "./mavlink_msg_analog.h"
#include "./mavlink_msg_infrared.h"
#include "./mavlink_msg_ultrasonic.h"

// base include


#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_HEARTBEAT, MAVLINK_MESSAGE_INFO_PING, MAVLINK_MESSAGE_INFO_PARAM_REQUEST_READ, MAVLINK_MESSAGE_INFO_PARAM_REQUEST_LIST, MAVLINK_MESSAGE_INFO_PARAM_VALUE, MAVLINK_MESSAGE_INFO_PARAM_SET, MAVLINK_MESSAGE_INFO_COMMAND_LONG, MAVLINK_MESSAGE_INFO_COMMAND_ACK, MAVLINK_MESSAGE_INFO_SYS_CORE_STATUS, MAVLINK_MESSAGE_INFO_SYS_INFO_VERSION, MAVLINK_MESSAGE_INFO_SCALED_IMU, MAVLINK_MESSAGE_INFO_ATTITUDE, MAVLINK_MESSAGE_INFO_TWIST, MAVLINK_MESSAGE_INFO_TORQUE, MAVLINK_MESSAGE_INFO_GPIO, MAVLINK_MESSAGE_INFO_ANALOG, MAVLINK_MESSAGE_INFO_Infrared, MAVLINK_MESSAGE_INFO_Ultrasonic}
# define MAVLINK_MESSAGE_NAMES {{ "ANALOG", 57 }, { "ATTITUDE", 53 }, { "COMMAND_ACK", 31 }, { "COMMAND_LONG", 30 }, { "GPIO", 56 }, { "HEARTBEAT", 0 }, { "Infrared", 58 }, { "PARAM_REQUEST_LIST", 21 }, { "PARAM_REQUEST_READ", 20 }, { "PARAM_SET", 23 }, { "PARAM_VALUE", 22 }, { "PING", 2 }, { "SCALED_IMU", 52 }, { "SYS_CORE_STATUS", 50 }, { "SYS_INFO_VERSION", 51 }, { "TORQUE", 55 }, { "TWIST", 54 }, { "Ultrasonic", 59 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_AIMIROBOT_H
