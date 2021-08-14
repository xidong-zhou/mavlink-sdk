#pragma once
// MESSAGE SYS_CORE_STATUS PACKING

#define MAVLINK_MSG_ID_SYS_CORE_STATUS 50

MAVPACKED(
typedef struct __mavlink_sys_core_status_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 uint32_t onboard_control_sensors_health; /*<  Bitmap showing which onboard sensors have an error (or are operational). Value of 0: error. Value of 1: healthy.*/
 uint16_t load; /*< [d%] Maximum usage in percent of the mainloop time. Values: [0-1000] - should always be below 1000*/
 uint16_t voltage_battery; /*< [mV] Battery voltage, UINT16_MAX: Voltage not sent by robot*/
 int16_t current_battery; /*< [mA] Battery current, -1: Current not sent by autopilot*/
 int16_t temperature; /*< [mC] Robot temperature*/
 int8_t battery_remaining; /*< [%] Battery energy remaining, Values: [0-100]%, -1: Battery remaining energy not sent by robot*/
}) mavlink_sys_core_status_t;

#define MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN 17
#define MAVLINK_MSG_ID_SYS_CORE_STATUS_MIN_LEN 17
#define MAVLINK_MSG_ID_50_LEN 17
#define MAVLINK_MSG_ID_50_MIN_LEN 17

#define MAVLINK_MSG_ID_SYS_CORE_STATUS_CRC 204
#define MAVLINK_MSG_ID_50_CRC 204



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SYS_CORE_STATUS { \
    50, \
    "SYS_CORE_STATUS", \
    7, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_sys_core_status_t, time_boot_ms) }, \
         { "onboard_control_sensors_health", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_sys_core_status_t, onboard_control_sensors_health) }, \
         { "load", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_sys_core_status_t, load) }, \
         { "voltage_battery", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_sys_core_status_t, voltage_battery) }, \
         { "current_battery", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_sys_core_status_t, current_battery) }, \
         { "battery_remaining", NULL, MAVLINK_TYPE_INT8_T, 0, 16, offsetof(mavlink_sys_core_status_t, battery_remaining) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_sys_core_status_t, temperature) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SYS_CORE_STATUS { \
    "SYS_CORE_STATUS", \
    7, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_sys_core_status_t, time_boot_ms) }, \
         { "onboard_control_sensors_health", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_sys_core_status_t, onboard_control_sensors_health) }, \
         { "load", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_sys_core_status_t, load) }, \
         { "voltage_battery", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_sys_core_status_t, voltage_battery) }, \
         { "current_battery", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_sys_core_status_t, current_battery) }, \
         { "battery_remaining", NULL, MAVLINK_TYPE_INT8_T, 0, 16, offsetof(mavlink_sys_core_status_t, battery_remaining) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_sys_core_status_t, temperature) }, \
         } \
}
#endif

/**
 * @brief Pack a sys_core_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param onboard_control_sensors_health  Bitmap showing which onboard sensors have an error (or are operational). Value of 0: error. Value of 1: healthy.
 * @param load [d%] Maximum usage in percent of the mainloop time. Values: [0-1000] - should always be below 1000
 * @param voltage_battery [mV] Battery voltage, UINT16_MAX: Voltage not sent by robot
 * @param current_battery [mA] Battery current, -1: Current not sent by autopilot
 * @param battery_remaining [%] Battery energy remaining, Values: [0-100]%, -1: Battery remaining energy not sent by robot
 * @param temperature [mC] Robot temperature
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sys_core_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint32_t onboard_control_sensors_health, uint16_t load, uint16_t voltage_battery, int16_t current_battery, int8_t battery_remaining, int16_t temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, onboard_control_sensors_health);
    _mav_put_uint16_t(buf, 8, load);
    _mav_put_uint16_t(buf, 10, voltage_battery);
    _mav_put_int16_t(buf, 12, current_battery);
    _mav_put_int16_t(buf, 14, temperature);
    _mav_put_int8_t(buf, 16, battery_remaining);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN);
#else
    mavlink_sys_core_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.onboard_control_sensors_health = onboard_control_sensors_health;
    packet.load = load;
    packet.voltage_battery = voltage_battery;
    packet.current_battery = current_battery;
    packet.temperature = temperature;
    packet.battery_remaining = battery_remaining;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYS_CORE_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SYS_CORE_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN, MAVLINK_MSG_ID_SYS_CORE_STATUS_CRC);
}

/**
 * @brief Pack a sys_core_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param onboard_control_sensors_health  Bitmap showing which onboard sensors have an error (or are operational). Value of 0: error. Value of 1: healthy.
 * @param load [d%] Maximum usage in percent of the mainloop time. Values: [0-1000] - should always be below 1000
 * @param voltage_battery [mV] Battery voltage, UINT16_MAX: Voltage not sent by robot
 * @param current_battery [mA] Battery current, -1: Current not sent by autopilot
 * @param battery_remaining [%] Battery energy remaining, Values: [0-100]%, -1: Battery remaining energy not sent by robot
 * @param temperature [mC] Robot temperature
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sys_core_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint32_t onboard_control_sensors_health,uint16_t load,uint16_t voltage_battery,int16_t current_battery,int8_t battery_remaining,int16_t temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, onboard_control_sensors_health);
    _mav_put_uint16_t(buf, 8, load);
    _mav_put_uint16_t(buf, 10, voltage_battery);
    _mav_put_int16_t(buf, 12, current_battery);
    _mav_put_int16_t(buf, 14, temperature);
    _mav_put_int8_t(buf, 16, battery_remaining);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN);
#else
    mavlink_sys_core_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.onboard_control_sensors_health = onboard_control_sensors_health;
    packet.load = load;
    packet.voltage_battery = voltage_battery;
    packet.current_battery = current_battery;
    packet.temperature = temperature;
    packet.battery_remaining = battery_remaining;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYS_CORE_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SYS_CORE_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN, MAVLINK_MSG_ID_SYS_CORE_STATUS_CRC);
}

/**
 * @brief Encode a sys_core_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sys_core_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sys_core_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sys_core_status_t* sys_core_status)
{
    return mavlink_msg_sys_core_status_pack(system_id, component_id, msg, sys_core_status->time_boot_ms, sys_core_status->onboard_control_sensors_health, sys_core_status->load, sys_core_status->voltage_battery, sys_core_status->current_battery, sys_core_status->battery_remaining, sys_core_status->temperature);
}

/**
 * @brief Encode a sys_core_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sys_core_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sys_core_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sys_core_status_t* sys_core_status)
{
    return mavlink_msg_sys_core_status_pack_chan(system_id, component_id, chan, msg, sys_core_status->time_boot_ms, sys_core_status->onboard_control_sensors_health, sys_core_status->load, sys_core_status->voltage_battery, sys_core_status->current_battery, sys_core_status->battery_remaining, sys_core_status->temperature);
}

/**
 * @brief Send a sys_core_status message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param onboard_control_sensors_health  Bitmap showing which onboard sensors have an error (or are operational). Value of 0: error. Value of 1: healthy.
 * @param load [d%] Maximum usage in percent of the mainloop time. Values: [0-1000] - should always be below 1000
 * @param voltage_battery [mV] Battery voltage, UINT16_MAX: Voltage not sent by robot
 * @param current_battery [mA] Battery current, -1: Current not sent by autopilot
 * @param battery_remaining [%] Battery energy remaining, Values: [0-100]%, -1: Battery remaining energy not sent by robot
 * @param temperature [mC] Robot temperature
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sys_core_status_send(mavlink_channel_t chan, uint32_t time_boot_ms, uint32_t onboard_control_sensors_health, uint16_t load, uint16_t voltage_battery, int16_t current_battery, int8_t battery_remaining, int16_t temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, onboard_control_sensors_health);
    _mav_put_uint16_t(buf, 8, load);
    _mav_put_uint16_t(buf, 10, voltage_battery);
    _mav_put_int16_t(buf, 12, current_battery);
    _mav_put_int16_t(buf, 14, temperature);
    _mav_put_int8_t(buf, 16, battery_remaining);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYS_CORE_STATUS, buf, MAVLINK_MSG_ID_SYS_CORE_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN, MAVLINK_MSG_ID_SYS_CORE_STATUS_CRC);
#else
    mavlink_sys_core_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.onboard_control_sensors_health = onboard_control_sensors_health;
    packet.load = load;
    packet.voltage_battery = voltage_battery;
    packet.current_battery = current_battery;
    packet.temperature = temperature;
    packet.battery_remaining = battery_remaining;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYS_CORE_STATUS, (const char *)&packet, MAVLINK_MSG_ID_SYS_CORE_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN, MAVLINK_MSG_ID_SYS_CORE_STATUS_CRC);
#endif
}

/**
 * @brief Send a sys_core_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sys_core_status_send_struct(mavlink_channel_t chan, const mavlink_sys_core_status_t* sys_core_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sys_core_status_send(chan, sys_core_status->time_boot_ms, sys_core_status->onboard_control_sensors_health, sys_core_status->load, sys_core_status->voltage_battery, sys_core_status->current_battery, sys_core_status->battery_remaining, sys_core_status->temperature);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYS_CORE_STATUS, (const char *)sys_core_status, MAVLINK_MSG_ID_SYS_CORE_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN, MAVLINK_MSG_ID_SYS_CORE_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sys_core_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, uint32_t onboard_control_sensors_health, uint16_t load, uint16_t voltage_battery, int16_t current_battery, int8_t battery_remaining, int16_t temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, onboard_control_sensors_health);
    _mav_put_uint16_t(buf, 8, load);
    _mav_put_uint16_t(buf, 10, voltage_battery);
    _mav_put_int16_t(buf, 12, current_battery);
    _mav_put_int16_t(buf, 14, temperature);
    _mav_put_int8_t(buf, 16, battery_remaining);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYS_CORE_STATUS, buf, MAVLINK_MSG_ID_SYS_CORE_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN, MAVLINK_MSG_ID_SYS_CORE_STATUS_CRC);
#else
    mavlink_sys_core_status_t *packet = (mavlink_sys_core_status_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->onboard_control_sensors_health = onboard_control_sensors_health;
    packet->load = load;
    packet->voltage_battery = voltage_battery;
    packet->current_battery = current_battery;
    packet->temperature = temperature;
    packet->battery_remaining = battery_remaining;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYS_CORE_STATUS, (const char *)packet, MAVLINK_MSG_ID_SYS_CORE_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN, MAVLINK_MSG_ID_SYS_CORE_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE SYS_CORE_STATUS UNPACKING


/**
 * @brief Get field time_boot_ms from sys_core_status message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_sys_core_status_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field onboard_control_sensors_health from sys_core_status message
 *
 * @return  Bitmap showing which onboard sensors have an error (or are operational). Value of 0: error. Value of 1: healthy.
 */
static inline uint32_t mavlink_msg_sys_core_status_get_onboard_control_sensors_health(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field load from sys_core_status message
 *
 * @return [d%] Maximum usage in percent of the mainloop time. Values: [0-1000] - should always be below 1000
 */
static inline uint16_t mavlink_msg_sys_core_status_get_load(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field voltage_battery from sys_core_status message
 *
 * @return [mV] Battery voltage, UINT16_MAX: Voltage not sent by robot
 */
static inline uint16_t mavlink_msg_sys_core_status_get_voltage_battery(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  10);
}

/**
 * @brief Get field current_battery from sys_core_status message
 *
 * @return [mA] Battery current, -1: Current not sent by autopilot
 */
static inline int16_t mavlink_msg_sys_core_status_get_current_battery(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field battery_remaining from sys_core_status message
 *
 * @return [%] Battery energy remaining, Values: [0-100]%, -1: Battery remaining energy not sent by robot
 */
static inline int8_t mavlink_msg_sys_core_status_get_battery_remaining(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  16);
}

/**
 * @brief Get field temperature from sys_core_status message
 *
 * @return [mC] Robot temperature
 */
static inline int16_t mavlink_msg_sys_core_status_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Decode a sys_core_status message into a struct
 *
 * @param msg The message to decode
 * @param sys_core_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_sys_core_status_decode(const mavlink_message_t* msg, mavlink_sys_core_status_t* sys_core_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    sys_core_status->time_boot_ms = mavlink_msg_sys_core_status_get_time_boot_ms(msg);
    sys_core_status->onboard_control_sensors_health = mavlink_msg_sys_core_status_get_onboard_control_sensors_health(msg);
    sys_core_status->load = mavlink_msg_sys_core_status_get_load(msg);
    sys_core_status->voltage_battery = mavlink_msg_sys_core_status_get_voltage_battery(msg);
    sys_core_status->current_battery = mavlink_msg_sys_core_status_get_current_battery(msg);
    sys_core_status->temperature = mavlink_msg_sys_core_status_get_temperature(msg);
    sys_core_status->battery_remaining = mavlink_msg_sys_core_status_get_battery_remaining(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN? msg->len : MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN;
        memset(sys_core_status, 0, MAVLINK_MSG_ID_SYS_CORE_STATUS_LEN);
    memcpy(sys_core_status, _MAV_PAYLOAD(msg), len);
#endif
}
