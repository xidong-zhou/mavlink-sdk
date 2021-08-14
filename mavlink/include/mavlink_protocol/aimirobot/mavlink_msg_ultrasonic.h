#pragma once
// MESSAGE Ultrasonic PACKING

#define MAVLINK_MSG_ID_Ultrasonic 59

MAVPACKED(
typedef struct __mavlink_ultrasonic_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 uint16_t Ultrasonic_1; /*< [mm]  the distance data of ultrasonic sensor 1 */
 uint16_t Ultrasonic_2; /*< [mm]  the distance data of ultrasonic sensor 2 */
 uint16_t Ultrasonic_3; /*< [mm]  the distance data of ultrasonic sensor 3 */
 uint16_t Ultrasonic_4; /*< [mm]  the distance data of ultrasonic sensor 4 */
 uint16_t Ultrasonic_5; /*< [mm]  the distance data of ultrasonic sensor 5 */
 uint16_t Ultrasonic_6; /*< [mm]  the distance data of ultrasonic sensor 6 */
}) mavlink_ultrasonic_t;

#define MAVLINK_MSG_ID_Ultrasonic_LEN 16
#define MAVLINK_MSG_ID_Ultrasonic_MIN_LEN 16
#define MAVLINK_MSG_ID_59_LEN 16
#define MAVLINK_MSG_ID_59_MIN_LEN 16

#define MAVLINK_MSG_ID_Ultrasonic_CRC 154
#define MAVLINK_MSG_ID_59_CRC 154



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_Ultrasonic { \
    59, \
    "Ultrasonic", \
    7, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ultrasonic_t, time_boot_ms) }, \
         { "Ultrasonic_1", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_ultrasonic_t, Ultrasonic_1) }, \
         { "Ultrasonic_2", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_ultrasonic_t, Ultrasonic_2) }, \
         { "Ultrasonic_3", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_ultrasonic_t, Ultrasonic_3) }, \
         { "Ultrasonic_4", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_ultrasonic_t, Ultrasonic_4) }, \
         { "Ultrasonic_5", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_ultrasonic_t, Ultrasonic_5) }, \
         { "Ultrasonic_6", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_ultrasonic_t, Ultrasonic_6) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_Ultrasonic { \
    "Ultrasonic", \
    7, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ultrasonic_t, time_boot_ms) }, \
         { "Ultrasonic_1", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_ultrasonic_t, Ultrasonic_1) }, \
         { "Ultrasonic_2", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_ultrasonic_t, Ultrasonic_2) }, \
         { "Ultrasonic_3", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_ultrasonic_t, Ultrasonic_3) }, \
         { "Ultrasonic_4", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_ultrasonic_t, Ultrasonic_4) }, \
         { "Ultrasonic_5", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_ultrasonic_t, Ultrasonic_5) }, \
         { "Ultrasonic_6", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_ultrasonic_t, Ultrasonic_6) }, \
         } \
}
#endif

/**
 * @brief Pack a ultrasonic message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param Ultrasonic_1 [mm]  the distance data of ultrasonic sensor 1 
 * @param Ultrasonic_2 [mm]  the distance data of ultrasonic sensor 2 
 * @param Ultrasonic_3 [mm]  the distance data of ultrasonic sensor 3 
 * @param Ultrasonic_4 [mm]  the distance data of ultrasonic sensor 4 
 * @param Ultrasonic_5 [mm]  the distance data of ultrasonic sensor 5 
 * @param Ultrasonic_6 [mm]  the distance data of ultrasonic sensor 6 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ultrasonic_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint16_t Ultrasonic_1, uint16_t Ultrasonic_2, uint16_t Ultrasonic_3, uint16_t Ultrasonic_4, uint16_t Ultrasonic_5, uint16_t Ultrasonic_6)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_Ultrasonic_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint16_t(buf, 4, Ultrasonic_1);
    _mav_put_uint16_t(buf, 6, Ultrasonic_2);
    _mav_put_uint16_t(buf, 8, Ultrasonic_3);
    _mav_put_uint16_t(buf, 10, Ultrasonic_4);
    _mav_put_uint16_t(buf, 12, Ultrasonic_5);
    _mav_put_uint16_t(buf, 14, Ultrasonic_6);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Ultrasonic_LEN);
#else
    mavlink_ultrasonic_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.Ultrasonic_1 = Ultrasonic_1;
    packet.Ultrasonic_2 = Ultrasonic_2;
    packet.Ultrasonic_3 = Ultrasonic_3;
    packet.Ultrasonic_4 = Ultrasonic_4;
    packet.Ultrasonic_5 = Ultrasonic_5;
    packet.Ultrasonic_6 = Ultrasonic_6;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Ultrasonic_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_Ultrasonic;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_Ultrasonic_MIN_LEN, MAVLINK_MSG_ID_Ultrasonic_LEN, MAVLINK_MSG_ID_Ultrasonic_CRC);
}

/**
 * @brief Pack a ultrasonic message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param Ultrasonic_1 [mm]  the distance data of ultrasonic sensor 1 
 * @param Ultrasonic_2 [mm]  the distance data of ultrasonic sensor 2 
 * @param Ultrasonic_3 [mm]  the distance data of ultrasonic sensor 3 
 * @param Ultrasonic_4 [mm]  the distance data of ultrasonic sensor 4 
 * @param Ultrasonic_5 [mm]  the distance data of ultrasonic sensor 5 
 * @param Ultrasonic_6 [mm]  the distance data of ultrasonic sensor 6 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ultrasonic_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint16_t Ultrasonic_1,uint16_t Ultrasonic_2,uint16_t Ultrasonic_3,uint16_t Ultrasonic_4,uint16_t Ultrasonic_5,uint16_t Ultrasonic_6)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_Ultrasonic_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint16_t(buf, 4, Ultrasonic_1);
    _mav_put_uint16_t(buf, 6, Ultrasonic_2);
    _mav_put_uint16_t(buf, 8, Ultrasonic_3);
    _mav_put_uint16_t(buf, 10, Ultrasonic_4);
    _mav_put_uint16_t(buf, 12, Ultrasonic_5);
    _mav_put_uint16_t(buf, 14, Ultrasonic_6);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Ultrasonic_LEN);
#else
    mavlink_ultrasonic_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.Ultrasonic_1 = Ultrasonic_1;
    packet.Ultrasonic_2 = Ultrasonic_2;
    packet.Ultrasonic_3 = Ultrasonic_3;
    packet.Ultrasonic_4 = Ultrasonic_4;
    packet.Ultrasonic_5 = Ultrasonic_5;
    packet.Ultrasonic_6 = Ultrasonic_6;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Ultrasonic_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_Ultrasonic;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_Ultrasonic_MIN_LEN, MAVLINK_MSG_ID_Ultrasonic_LEN, MAVLINK_MSG_ID_Ultrasonic_CRC);
}

/**
 * @brief Encode a ultrasonic struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ultrasonic C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ultrasonic_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ultrasonic_t* ultrasonic)
{
    return mavlink_msg_ultrasonic_pack(system_id, component_id, msg, ultrasonic->time_boot_ms, ultrasonic->Ultrasonic_1, ultrasonic->Ultrasonic_2, ultrasonic->Ultrasonic_3, ultrasonic->Ultrasonic_4, ultrasonic->Ultrasonic_5, ultrasonic->Ultrasonic_6);
}

/**
 * @brief Encode a ultrasonic struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ultrasonic C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ultrasonic_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ultrasonic_t* ultrasonic)
{
    return mavlink_msg_ultrasonic_pack_chan(system_id, component_id, chan, msg, ultrasonic->time_boot_ms, ultrasonic->Ultrasonic_1, ultrasonic->Ultrasonic_2, ultrasonic->Ultrasonic_3, ultrasonic->Ultrasonic_4, ultrasonic->Ultrasonic_5, ultrasonic->Ultrasonic_6);
}

/**
 * @brief Send a ultrasonic message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param Ultrasonic_1 [mm]  the distance data of ultrasonic sensor 1 
 * @param Ultrasonic_2 [mm]  the distance data of ultrasonic sensor 2 
 * @param Ultrasonic_3 [mm]  the distance data of ultrasonic sensor 3 
 * @param Ultrasonic_4 [mm]  the distance data of ultrasonic sensor 4 
 * @param Ultrasonic_5 [mm]  the distance data of ultrasonic sensor 5 
 * @param Ultrasonic_6 [mm]  the distance data of ultrasonic sensor 6 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ultrasonic_send(mavlink_channel_t chan, uint32_t time_boot_ms, uint16_t Ultrasonic_1, uint16_t Ultrasonic_2, uint16_t Ultrasonic_3, uint16_t Ultrasonic_4, uint16_t Ultrasonic_5, uint16_t Ultrasonic_6)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_Ultrasonic_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint16_t(buf, 4, Ultrasonic_1);
    _mav_put_uint16_t(buf, 6, Ultrasonic_2);
    _mav_put_uint16_t(buf, 8, Ultrasonic_3);
    _mav_put_uint16_t(buf, 10, Ultrasonic_4);
    _mav_put_uint16_t(buf, 12, Ultrasonic_5);
    _mav_put_uint16_t(buf, 14, Ultrasonic_6);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Ultrasonic, buf, MAVLINK_MSG_ID_Ultrasonic_MIN_LEN, MAVLINK_MSG_ID_Ultrasonic_LEN, MAVLINK_MSG_ID_Ultrasonic_CRC);
#else
    mavlink_ultrasonic_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.Ultrasonic_1 = Ultrasonic_1;
    packet.Ultrasonic_2 = Ultrasonic_2;
    packet.Ultrasonic_3 = Ultrasonic_3;
    packet.Ultrasonic_4 = Ultrasonic_4;
    packet.Ultrasonic_5 = Ultrasonic_5;
    packet.Ultrasonic_6 = Ultrasonic_6;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Ultrasonic, (const char *)&packet, MAVLINK_MSG_ID_Ultrasonic_MIN_LEN, MAVLINK_MSG_ID_Ultrasonic_LEN, MAVLINK_MSG_ID_Ultrasonic_CRC);
#endif
}

/**
 * @brief Send a ultrasonic message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ultrasonic_send_struct(mavlink_channel_t chan, const mavlink_ultrasonic_t* ultrasonic)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ultrasonic_send(chan, ultrasonic->time_boot_ms, ultrasonic->Ultrasonic_1, ultrasonic->Ultrasonic_2, ultrasonic->Ultrasonic_3, ultrasonic->Ultrasonic_4, ultrasonic->Ultrasonic_5, ultrasonic->Ultrasonic_6);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Ultrasonic, (const char *)ultrasonic, MAVLINK_MSG_ID_Ultrasonic_MIN_LEN, MAVLINK_MSG_ID_Ultrasonic_LEN, MAVLINK_MSG_ID_Ultrasonic_CRC);
#endif
}

#if MAVLINK_MSG_ID_Ultrasonic_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ultrasonic_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, uint16_t Ultrasonic_1, uint16_t Ultrasonic_2, uint16_t Ultrasonic_3, uint16_t Ultrasonic_4, uint16_t Ultrasonic_5, uint16_t Ultrasonic_6)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint16_t(buf, 4, Ultrasonic_1);
    _mav_put_uint16_t(buf, 6, Ultrasonic_2);
    _mav_put_uint16_t(buf, 8, Ultrasonic_3);
    _mav_put_uint16_t(buf, 10, Ultrasonic_4);
    _mav_put_uint16_t(buf, 12, Ultrasonic_5);
    _mav_put_uint16_t(buf, 14, Ultrasonic_6);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Ultrasonic, buf, MAVLINK_MSG_ID_Ultrasonic_MIN_LEN, MAVLINK_MSG_ID_Ultrasonic_LEN, MAVLINK_MSG_ID_Ultrasonic_CRC);
#else
    mavlink_ultrasonic_t *packet = (mavlink_ultrasonic_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->Ultrasonic_1 = Ultrasonic_1;
    packet->Ultrasonic_2 = Ultrasonic_2;
    packet->Ultrasonic_3 = Ultrasonic_3;
    packet->Ultrasonic_4 = Ultrasonic_4;
    packet->Ultrasonic_5 = Ultrasonic_5;
    packet->Ultrasonic_6 = Ultrasonic_6;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Ultrasonic, (const char *)packet, MAVLINK_MSG_ID_Ultrasonic_MIN_LEN, MAVLINK_MSG_ID_Ultrasonic_LEN, MAVLINK_MSG_ID_Ultrasonic_CRC);
#endif
}
#endif

#endif

// MESSAGE Ultrasonic UNPACKING


/**
 * @brief Get field time_boot_ms from ultrasonic message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_ultrasonic_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field Ultrasonic_1 from ultrasonic message
 *
 * @return [mm]  the distance data of ultrasonic sensor 1 
 */
static inline uint16_t mavlink_msg_ultrasonic_get_Ultrasonic_1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field Ultrasonic_2 from ultrasonic message
 *
 * @return [mm]  the distance data of ultrasonic sensor 2 
 */
static inline uint16_t mavlink_msg_ultrasonic_get_Ultrasonic_2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field Ultrasonic_3 from ultrasonic message
 *
 * @return [mm]  the distance data of ultrasonic sensor 3 
 */
static inline uint16_t mavlink_msg_ultrasonic_get_Ultrasonic_3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field Ultrasonic_4 from ultrasonic message
 *
 * @return [mm]  the distance data of ultrasonic sensor 4 
 */
static inline uint16_t mavlink_msg_ultrasonic_get_Ultrasonic_4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  10);
}

/**
 * @brief Get field Ultrasonic_5 from ultrasonic message
 *
 * @return [mm]  the distance data of ultrasonic sensor 5 
 */
static inline uint16_t mavlink_msg_ultrasonic_get_Ultrasonic_5(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field Ultrasonic_6 from ultrasonic message
 *
 * @return [mm]  the distance data of ultrasonic sensor 6 
 */
static inline uint16_t mavlink_msg_ultrasonic_get_Ultrasonic_6(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Decode a ultrasonic message into a struct
 *
 * @param msg The message to decode
 * @param ultrasonic C-struct to decode the message contents into
 */
static inline void mavlink_msg_ultrasonic_decode(const mavlink_message_t* msg, mavlink_ultrasonic_t* ultrasonic)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ultrasonic->time_boot_ms = mavlink_msg_ultrasonic_get_time_boot_ms(msg);
    ultrasonic->Ultrasonic_1 = mavlink_msg_ultrasonic_get_Ultrasonic_1(msg);
    ultrasonic->Ultrasonic_2 = mavlink_msg_ultrasonic_get_Ultrasonic_2(msg);
    ultrasonic->Ultrasonic_3 = mavlink_msg_ultrasonic_get_Ultrasonic_3(msg);
    ultrasonic->Ultrasonic_4 = mavlink_msg_ultrasonic_get_Ultrasonic_4(msg);
    ultrasonic->Ultrasonic_5 = mavlink_msg_ultrasonic_get_Ultrasonic_5(msg);
    ultrasonic->Ultrasonic_6 = mavlink_msg_ultrasonic_get_Ultrasonic_6(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_Ultrasonic_LEN? msg->len : MAVLINK_MSG_ID_Ultrasonic_LEN;
        memset(ultrasonic, 0, MAVLINK_MSG_ID_Ultrasonic_LEN);
    memcpy(ultrasonic, _MAV_PAYLOAD(msg), len);
#endif
}
