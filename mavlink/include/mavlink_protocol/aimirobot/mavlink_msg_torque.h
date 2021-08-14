#pragma once
// MESSAGE TORQUE PACKING

#define MAVLINK_MSG_ID_TORQUE 55

MAVPACKED(
typedef struct __mavlink_torque_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 float J1; /*< [Nm] Joint One torque*/
 float J2; /*< [Nm] Joint two torque*/
 float J3; /*< [Nm] Joint three torque*/
 float J4; /*< [Nm] Joint four torque*/
 float J5; /*< [Nm] Joint five torque*/
 float J6; /*< [Nm] Joint six torque*/
 float J7; /*< [Nm] Joint seven torque*/
}) mavlink_torque_t;

#define MAVLINK_MSG_ID_TORQUE_LEN 32
#define MAVLINK_MSG_ID_TORQUE_MIN_LEN 32
#define MAVLINK_MSG_ID_55_LEN 32
#define MAVLINK_MSG_ID_55_MIN_LEN 32

#define MAVLINK_MSG_ID_TORQUE_CRC 31
#define MAVLINK_MSG_ID_55_CRC 31



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TORQUE { \
    55, \
    "TORQUE", \
    8, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_torque_t, time_boot_ms) }, \
         { "J1", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_torque_t, J1) }, \
         { "J2", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_torque_t, J2) }, \
         { "J3", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_torque_t, J3) }, \
         { "J4", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_torque_t, J4) }, \
         { "J5", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_torque_t, J5) }, \
         { "J6", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_torque_t, J6) }, \
         { "J7", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_torque_t, J7) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TORQUE { \
    "TORQUE", \
    8, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_torque_t, time_boot_ms) }, \
         { "J1", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_torque_t, J1) }, \
         { "J2", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_torque_t, J2) }, \
         { "J3", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_torque_t, J3) }, \
         { "J4", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_torque_t, J4) }, \
         { "J5", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_torque_t, J5) }, \
         { "J6", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_torque_t, J6) }, \
         { "J7", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_torque_t, J7) }, \
         } \
}
#endif

/**
 * @brief Pack a torque message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param J1 [Nm] Joint One torque
 * @param J2 [Nm] Joint two torque
 * @param J3 [Nm] Joint three torque
 * @param J4 [Nm] Joint four torque
 * @param J5 [Nm] Joint five torque
 * @param J6 [Nm] Joint six torque
 * @param J7 [Nm] Joint seven torque
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_torque_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, float J1, float J2, float J3, float J4, float J5, float J6, float J7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TORQUE_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, J1);
    _mav_put_float(buf, 8, J2);
    _mav_put_float(buf, 12, J3);
    _mav_put_float(buf, 16, J4);
    _mav_put_float(buf, 20, J5);
    _mav_put_float(buf, 24, J6);
    _mav_put_float(buf, 28, J7);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TORQUE_LEN);
#else
    mavlink_torque_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.J1 = J1;
    packet.J2 = J2;
    packet.J3 = J3;
    packet.J4 = J4;
    packet.J5 = J5;
    packet.J6 = J6;
    packet.J7 = J7;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TORQUE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TORQUE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TORQUE_MIN_LEN, MAVLINK_MSG_ID_TORQUE_LEN, MAVLINK_MSG_ID_TORQUE_CRC);
}

/**
 * @brief Pack a torque message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param J1 [Nm] Joint One torque
 * @param J2 [Nm] Joint two torque
 * @param J3 [Nm] Joint three torque
 * @param J4 [Nm] Joint four torque
 * @param J5 [Nm] Joint five torque
 * @param J6 [Nm] Joint six torque
 * @param J7 [Nm] Joint seven torque
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_torque_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,float J1,float J2,float J3,float J4,float J5,float J6,float J7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TORQUE_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, J1);
    _mav_put_float(buf, 8, J2);
    _mav_put_float(buf, 12, J3);
    _mav_put_float(buf, 16, J4);
    _mav_put_float(buf, 20, J5);
    _mav_put_float(buf, 24, J6);
    _mav_put_float(buf, 28, J7);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TORQUE_LEN);
#else
    mavlink_torque_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.J1 = J1;
    packet.J2 = J2;
    packet.J3 = J3;
    packet.J4 = J4;
    packet.J5 = J5;
    packet.J6 = J6;
    packet.J7 = J7;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TORQUE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TORQUE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TORQUE_MIN_LEN, MAVLINK_MSG_ID_TORQUE_LEN, MAVLINK_MSG_ID_TORQUE_CRC);
}

/**
 * @brief Encode a torque struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param torque C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_torque_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_torque_t* torque)
{
    return mavlink_msg_torque_pack(system_id, component_id, msg, torque->time_boot_ms, torque->J1, torque->J2, torque->J3, torque->J4, torque->J5, torque->J6, torque->J7);
}

/**
 * @brief Encode a torque struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param torque C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_torque_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_torque_t* torque)
{
    return mavlink_msg_torque_pack_chan(system_id, component_id, chan, msg, torque->time_boot_ms, torque->J1, torque->J2, torque->J3, torque->J4, torque->J5, torque->J6, torque->J7);
}

/**
 * @brief Send a torque message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param J1 [Nm] Joint One torque
 * @param J2 [Nm] Joint two torque
 * @param J3 [Nm] Joint three torque
 * @param J4 [Nm] Joint four torque
 * @param J5 [Nm] Joint five torque
 * @param J6 [Nm] Joint six torque
 * @param J7 [Nm] Joint seven torque
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_torque_send(mavlink_channel_t chan, uint32_t time_boot_ms, float J1, float J2, float J3, float J4, float J5, float J6, float J7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TORQUE_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, J1);
    _mav_put_float(buf, 8, J2);
    _mav_put_float(buf, 12, J3);
    _mav_put_float(buf, 16, J4);
    _mav_put_float(buf, 20, J5);
    _mav_put_float(buf, 24, J6);
    _mav_put_float(buf, 28, J7);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TORQUE, buf, MAVLINK_MSG_ID_TORQUE_MIN_LEN, MAVLINK_MSG_ID_TORQUE_LEN, MAVLINK_MSG_ID_TORQUE_CRC);
#else
    mavlink_torque_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.J1 = J1;
    packet.J2 = J2;
    packet.J3 = J3;
    packet.J4 = J4;
    packet.J5 = J5;
    packet.J6 = J6;
    packet.J7 = J7;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TORQUE, (const char *)&packet, MAVLINK_MSG_ID_TORQUE_MIN_LEN, MAVLINK_MSG_ID_TORQUE_LEN, MAVLINK_MSG_ID_TORQUE_CRC);
#endif
}

/**
 * @brief Send a torque message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_torque_send_struct(mavlink_channel_t chan, const mavlink_torque_t* torque)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_torque_send(chan, torque->time_boot_ms, torque->J1, torque->J2, torque->J3, torque->J4, torque->J5, torque->J6, torque->J7);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TORQUE, (const char *)torque, MAVLINK_MSG_ID_TORQUE_MIN_LEN, MAVLINK_MSG_ID_TORQUE_LEN, MAVLINK_MSG_ID_TORQUE_CRC);
#endif
}

#if MAVLINK_MSG_ID_TORQUE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_torque_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, float J1, float J2, float J3, float J4, float J5, float J6, float J7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, J1);
    _mav_put_float(buf, 8, J2);
    _mav_put_float(buf, 12, J3);
    _mav_put_float(buf, 16, J4);
    _mav_put_float(buf, 20, J5);
    _mav_put_float(buf, 24, J6);
    _mav_put_float(buf, 28, J7);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TORQUE, buf, MAVLINK_MSG_ID_TORQUE_MIN_LEN, MAVLINK_MSG_ID_TORQUE_LEN, MAVLINK_MSG_ID_TORQUE_CRC);
#else
    mavlink_torque_t *packet = (mavlink_torque_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->J1 = J1;
    packet->J2 = J2;
    packet->J3 = J3;
    packet->J4 = J4;
    packet->J5 = J5;
    packet->J6 = J6;
    packet->J7 = J7;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TORQUE, (const char *)packet, MAVLINK_MSG_ID_TORQUE_MIN_LEN, MAVLINK_MSG_ID_TORQUE_LEN, MAVLINK_MSG_ID_TORQUE_CRC);
#endif
}
#endif

#endif

// MESSAGE TORQUE UNPACKING


/**
 * @brief Get field time_boot_ms from torque message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_torque_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field J1 from torque message
 *
 * @return [Nm] Joint One torque
 */
static inline float mavlink_msg_torque_get_J1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field J2 from torque message
 *
 * @return [Nm] Joint two torque
 */
static inline float mavlink_msg_torque_get_J2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field J3 from torque message
 *
 * @return [Nm] Joint three torque
 */
static inline float mavlink_msg_torque_get_J3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field J4 from torque message
 *
 * @return [Nm] Joint four torque
 */
static inline float mavlink_msg_torque_get_J4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field J5 from torque message
 *
 * @return [Nm] Joint five torque
 */
static inline float mavlink_msg_torque_get_J5(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field J6 from torque message
 *
 * @return [Nm] Joint six torque
 */
static inline float mavlink_msg_torque_get_J6(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field J7 from torque message
 *
 * @return [Nm] Joint seven torque
 */
static inline float mavlink_msg_torque_get_J7(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Decode a torque message into a struct
 *
 * @param msg The message to decode
 * @param torque C-struct to decode the message contents into
 */
static inline void mavlink_msg_torque_decode(const mavlink_message_t* msg, mavlink_torque_t* torque)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    torque->time_boot_ms = mavlink_msg_torque_get_time_boot_ms(msg);
    torque->J1 = mavlink_msg_torque_get_J1(msg);
    torque->J2 = mavlink_msg_torque_get_J2(msg);
    torque->J3 = mavlink_msg_torque_get_J3(msg);
    torque->J4 = mavlink_msg_torque_get_J4(msg);
    torque->J5 = mavlink_msg_torque_get_J5(msg);
    torque->J6 = mavlink_msg_torque_get_J6(msg);
    torque->J7 = mavlink_msg_torque_get_J7(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TORQUE_LEN? msg->len : MAVLINK_MSG_ID_TORQUE_LEN;
        memset(torque, 0, MAVLINK_MSG_ID_TORQUE_LEN);
    memcpy(torque, _MAV_PAYLOAD(msg), len);
#endif
}
