#pragma once
// MESSAGE Infrared PACKING

#define MAVLINK_MSG_ID_Infrared 58

MAVPACKED(
typedef struct __mavlink_infrared_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 uint16_t infrared_1; /*< [mm]  the distance data between the cliff sensor 1 and the ground*/
 uint16_t infrared_2; /*< [mm]  the distance data between the cliff sensor 2 and the ground*/
 uint16_t infrared_3; /*< [mm]  the distance data between the cliff sensor 3 and the ground*/
}) mavlink_infrared_t;

#define MAVLINK_MSG_ID_Infrared_LEN 10
#define MAVLINK_MSG_ID_Infrared_MIN_LEN 10
#define MAVLINK_MSG_ID_58_LEN 10
#define MAVLINK_MSG_ID_58_MIN_LEN 10

#define MAVLINK_MSG_ID_Infrared_CRC 163
#define MAVLINK_MSG_ID_58_CRC 163



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_Infrared { \
    58, \
    "Infrared", \
    4, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_infrared_t, time_boot_ms) }, \
         { "infrared_1", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_infrared_t, infrared_1) }, \
         { "infrared_2", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_infrared_t, infrared_2) }, \
         { "infrared_3", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_infrared_t, infrared_3) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_Infrared { \
    "Infrared", \
    4, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_infrared_t, time_boot_ms) }, \
         { "infrared_1", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_infrared_t, infrared_1) }, \
         { "infrared_2", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_infrared_t, infrared_2) }, \
         { "infrared_3", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_infrared_t, infrared_3) }, \
         } \
}
#endif

/**
 * @brief Pack a infrared message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param infrared_1 [mm]  the distance data between the cliff sensor 1 and the ground
 * @param infrared_2 [mm]  the distance data between the cliff sensor 2 and the ground
 * @param infrared_3 [mm]  the distance data between the cliff sensor 3 and the ground
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_infrared_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint16_t infrared_1, uint16_t infrared_2, uint16_t infrared_3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_Infrared_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint16_t(buf, 4, infrared_1);
    _mav_put_uint16_t(buf, 6, infrared_2);
    _mav_put_uint16_t(buf, 8, infrared_3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Infrared_LEN);
#else
    mavlink_infrared_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.infrared_1 = infrared_1;
    packet.infrared_2 = infrared_2;
    packet.infrared_3 = infrared_3;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Infrared_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_Infrared;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_Infrared_MIN_LEN, MAVLINK_MSG_ID_Infrared_LEN, MAVLINK_MSG_ID_Infrared_CRC);
}

/**
 * @brief Pack a infrared message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param infrared_1 [mm]  the distance data between the cliff sensor 1 and the ground
 * @param infrared_2 [mm]  the distance data between the cliff sensor 2 and the ground
 * @param infrared_3 [mm]  the distance data between the cliff sensor 3 and the ground
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_infrared_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint16_t infrared_1,uint16_t infrared_2,uint16_t infrared_3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_Infrared_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint16_t(buf, 4, infrared_1);
    _mav_put_uint16_t(buf, 6, infrared_2);
    _mav_put_uint16_t(buf, 8, infrared_3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Infrared_LEN);
#else
    mavlink_infrared_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.infrared_1 = infrared_1;
    packet.infrared_2 = infrared_2;
    packet.infrared_3 = infrared_3;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Infrared_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_Infrared;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_Infrared_MIN_LEN, MAVLINK_MSG_ID_Infrared_LEN, MAVLINK_MSG_ID_Infrared_CRC);
}

/**
 * @brief Encode a infrared struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param infrared C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_infrared_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_infrared_t* infrared)
{
    return mavlink_msg_infrared_pack(system_id, component_id, msg, infrared->time_boot_ms, infrared->infrared_1, infrared->infrared_2, infrared->infrared_3);
}

/**
 * @brief Encode a infrared struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param infrared C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_infrared_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_infrared_t* infrared)
{
    return mavlink_msg_infrared_pack_chan(system_id, component_id, chan, msg, infrared->time_boot_ms, infrared->infrared_1, infrared->infrared_2, infrared->infrared_3);
}

/**
 * @brief Send a infrared message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param infrared_1 [mm]  the distance data between the cliff sensor 1 and the ground
 * @param infrared_2 [mm]  the distance data between the cliff sensor 2 and the ground
 * @param infrared_3 [mm]  the distance data between the cliff sensor 3 and the ground
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_infrared_send(mavlink_channel_t chan, uint32_t time_boot_ms, uint16_t infrared_1, uint16_t infrared_2, uint16_t infrared_3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_Infrared_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint16_t(buf, 4, infrared_1);
    _mav_put_uint16_t(buf, 6, infrared_2);
    _mav_put_uint16_t(buf, 8, infrared_3);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Infrared, buf, MAVLINK_MSG_ID_Infrared_MIN_LEN, MAVLINK_MSG_ID_Infrared_LEN, MAVLINK_MSG_ID_Infrared_CRC);
#else
    mavlink_infrared_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.infrared_1 = infrared_1;
    packet.infrared_2 = infrared_2;
    packet.infrared_3 = infrared_3;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Infrared, (const char *)&packet, MAVLINK_MSG_ID_Infrared_MIN_LEN, MAVLINK_MSG_ID_Infrared_LEN, MAVLINK_MSG_ID_Infrared_CRC);
#endif
}

/**
 * @brief Send a infrared message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_infrared_send_struct(mavlink_channel_t chan, const mavlink_infrared_t* infrared)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_infrared_send(chan, infrared->time_boot_ms, infrared->infrared_1, infrared->infrared_2, infrared->infrared_3);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Infrared, (const char *)infrared, MAVLINK_MSG_ID_Infrared_MIN_LEN, MAVLINK_MSG_ID_Infrared_LEN, MAVLINK_MSG_ID_Infrared_CRC);
#endif
}

#if MAVLINK_MSG_ID_Infrared_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_infrared_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, uint16_t infrared_1, uint16_t infrared_2, uint16_t infrared_3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint16_t(buf, 4, infrared_1);
    _mav_put_uint16_t(buf, 6, infrared_2);
    _mav_put_uint16_t(buf, 8, infrared_3);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Infrared, buf, MAVLINK_MSG_ID_Infrared_MIN_LEN, MAVLINK_MSG_ID_Infrared_LEN, MAVLINK_MSG_ID_Infrared_CRC);
#else
    mavlink_infrared_t *packet = (mavlink_infrared_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->infrared_1 = infrared_1;
    packet->infrared_2 = infrared_2;
    packet->infrared_3 = infrared_3;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Infrared, (const char *)packet, MAVLINK_MSG_ID_Infrared_MIN_LEN, MAVLINK_MSG_ID_Infrared_LEN, MAVLINK_MSG_ID_Infrared_CRC);
#endif
}
#endif

#endif

// MESSAGE Infrared UNPACKING


/**
 * @brief Get field time_boot_ms from infrared message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_infrared_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field infrared_1 from infrared message
 *
 * @return [mm]  the distance data between the cliff sensor 1 and the ground
 */
static inline uint16_t mavlink_msg_infrared_get_infrared_1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field infrared_2 from infrared message
 *
 * @return [mm]  the distance data between the cliff sensor 2 and the ground
 */
static inline uint16_t mavlink_msg_infrared_get_infrared_2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field infrared_3 from infrared message
 *
 * @return [mm]  the distance data between the cliff sensor 3 and the ground
 */
static inline uint16_t mavlink_msg_infrared_get_infrared_3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Decode a infrared message into a struct
 *
 * @param msg The message to decode
 * @param infrared C-struct to decode the message contents into
 */
static inline void mavlink_msg_infrared_decode(const mavlink_message_t* msg, mavlink_infrared_t* infrared)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    infrared->time_boot_ms = mavlink_msg_infrared_get_time_boot_ms(msg);
    infrared->infrared_1 = mavlink_msg_infrared_get_infrared_1(msg);
    infrared->infrared_2 = mavlink_msg_infrared_get_infrared_2(msg);
    infrared->infrared_3 = mavlink_msg_infrared_get_infrared_3(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_Infrared_LEN? msg->len : MAVLINK_MSG_ID_Infrared_LEN;
        memset(infrared, 0, MAVLINK_MSG_ID_Infrared_LEN);
    memcpy(infrared, _MAV_PAYLOAD(msg), len);
#endif
}
