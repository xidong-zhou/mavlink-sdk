#pragma once
// MESSAGE TWIST PACKING

#define MAVLINK_MSG_ID_TWIST 54

MAVPACKED(
typedef struct __mavlink_twist_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 float Vx; /*< [m/s] X axis speed*/
 float Vy; /*< [m/s] Y axis speed*/
 float Vz; /*< [m/s] Z axis speed*/
 float Wx; /*< [rad/s] Roll angular speed*/
 float Wy; /*< [rad/s] Pitch angular speed*/
 float Wz; /*< [rad/s] Yaw angular speed*/
}) mavlink_twist_t;

#define MAVLINK_MSG_ID_TWIST_LEN 28
#define MAVLINK_MSG_ID_TWIST_MIN_LEN 28
#define MAVLINK_MSG_ID_54_LEN 28
#define MAVLINK_MSG_ID_54_MIN_LEN 28

#define MAVLINK_MSG_ID_TWIST_CRC 16
#define MAVLINK_MSG_ID_54_CRC 16



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TWIST { \
    54, \
    "TWIST", \
    7, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_twist_t, time_boot_ms) }, \
         { "Vx", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_twist_t, Vx) }, \
         { "Vy", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_twist_t, Vy) }, \
         { "Vz", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_twist_t, Vz) }, \
         { "Wx", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_twist_t, Wx) }, \
         { "Wy", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_twist_t, Wy) }, \
         { "Wz", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_twist_t, Wz) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TWIST { \
    "TWIST", \
    7, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_twist_t, time_boot_ms) }, \
         { "Vx", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_twist_t, Vx) }, \
         { "Vy", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_twist_t, Vy) }, \
         { "Vz", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_twist_t, Vz) }, \
         { "Wx", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_twist_t, Wx) }, \
         { "Wy", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_twist_t, Wy) }, \
         { "Wz", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_twist_t, Wz) }, \
         } \
}
#endif

/**
 * @brief Pack a twist message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param Vx [m/s] X axis speed
 * @param Vy [m/s] Y axis speed
 * @param Vz [m/s] Z axis speed
 * @param Wx [rad/s] Roll angular speed
 * @param Wy [rad/s] Pitch angular speed
 * @param Wz [rad/s] Yaw angular speed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_twist_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, float Vx, float Vy, float Vz, float Wx, float Wy, float Wz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TWIST_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, Vx);
    _mav_put_float(buf, 8, Vy);
    _mav_put_float(buf, 12, Vz);
    _mav_put_float(buf, 16, Wx);
    _mav_put_float(buf, 20, Wy);
    _mav_put_float(buf, 24, Wz);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TWIST_LEN);
#else
    mavlink_twist_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.Vx = Vx;
    packet.Vy = Vy;
    packet.Vz = Vz;
    packet.Wx = Wx;
    packet.Wy = Wy;
    packet.Wz = Wz;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TWIST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TWIST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TWIST_MIN_LEN, MAVLINK_MSG_ID_TWIST_LEN, MAVLINK_MSG_ID_TWIST_CRC);
}

/**
 * @brief Pack a twist message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param Vx [m/s] X axis speed
 * @param Vy [m/s] Y axis speed
 * @param Vz [m/s] Z axis speed
 * @param Wx [rad/s] Roll angular speed
 * @param Wy [rad/s] Pitch angular speed
 * @param Wz [rad/s] Yaw angular speed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_twist_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,float Vx,float Vy,float Vz,float Wx,float Wy,float Wz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TWIST_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, Vx);
    _mav_put_float(buf, 8, Vy);
    _mav_put_float(buf, 12, Vz);
    _mav_put_float(buf, 16, Wx);
    _mav_put_float(buf, 20, Wy);
    _mav_put_float(buf, 24, Wz);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TWIST_LEN);
#else
    mavlink_twist_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.Vx = Vx;
    packet.Vy = Vy;
    packet.Vz = Vz;
    packet.Wx = Wx;
    packet.Wy = Wy;
    packet.Wz = Wz;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TWIST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TWIST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TWIST_MIN_LEN, MAVLINK_MSG_ID_TWIST_LEN, MAVLINK_MSG_ID_TWIST_CRC);
}

/**
 * @brief Encode a twist struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param twist C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_twist_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_twist_t* twist)
{
    return mavlink_msg_twist_pack(system_id, component_id, msg, twist->time_boot_ms, twist->Vx, twist->Vy, twist->Vz, twist->Wx, twist->Wy, twist->Wz);
}

/**
 * @brief Encode a twist struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param twist C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_twist_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_twist_t* twist)
{
    return mavlink_msg_twist_pack_chan(system_id, component_id, chan, msg, twist->time_boot_ms, twist->Vx, twist->Vy, twist->Vz, twist->Wx, twist->Wy, twist->Wz);
}

/**
 * @brief Send a twist message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param Vx [m/s] X axis speed
 * @param Vy [m/s] Y axis speed
 * @param Vz [m/s] Z axis speed
 * @param Wx [rad/s] Roll angular speed
 * @param Wy [rad/s] Pitch angular speed
 * @param Wz [rad/s] Yaw angular speed
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_twist_send(mavlink_channel_t chan, uint32_t time_boot_ms, float Vx, float Vy, float Vz, float Wx, float Wy, float Wz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TWIST_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, Vx);
    _mav_put_float(buf, 8, Vy);
    _mav_put_float(buf, 12, Vz);
    _mav_put_float(buf, 16, Wx);
    _mav_put_float(buf, 20, Wy);
    _mav_put_float(buf, 24, Wz);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TWIST, buf, MAVLINK_MSG_ID_TWIST_MIN_LEN, MAVLINK_MSG_ID_TWIST_LEN, MAVLINK_MSG_ID_TWIST_CRC);
#else
    mavlink_twist_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.Vx = Vx;
    packet.Vy = Vy;
    packet.Vz = Vz;
    packet.Wx = Wx;
    packet.Wy = Wy;
    packet.Wz = Wz;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TWIST, (const char *)&packet, MAVLINK_MSG_ID_TWIST_MIN_LEN, MAVLINK_MSG_ID_TWIST_LEN, MAVLINK_MSG_ID_TWIST_CRC);
#endif
}

/**
 * @brief Send a twist message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_twist_send_struct(mavlink_channel_t chan, const mavlink_twist_t* twist)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_twist_send(chan, twist->time_boot_ms, twist->Vx, twist->Vy, twist->Vz, twist->Wx, twist->Wy, twist->Wz);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TWIST, (const char *)twist, MAVLINK_MSG_ID_TWIST_MIN_LEN, MAVLINK_MSG_ID_TWIST_LEN, MAVLINK_MSG_ID_TWIST_CRC);
#endif
}

#if MAVLINK_MSG_ID_TWIST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_twist_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, float Vx, float Vy, float Vz, float Wx, float Wy, float Wz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, Vx);
    _mav_put_float(buf, 8, Vy);
    _mav_put_float(buf, 12, Vz);
    _mav_put_float(buf, 16, Wx);
    _mav_put_float(buf, 20, Wy);
    _mav_put_float(buf, 24, Wz);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TWIST, buf, MAVLINK_MSG_ID_TWIST_MIN_LEN, MAVLINK_MSG_ID_TWIST_LEN, MAVLINK_MSG_ID_TWIST_CRC);
#else
    mavlink_twist_t *packet = (mavlink_twist_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->Vx = Vx;
    packet->Vy = Vy;
    packet->Vz = Vz;
    packet->Wx = Wx;
    packet->Wy = Wy;
    packet->Wz = Wz;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TWIST, (const char *)packet, MAVLINK_MSG_ID_TWIST_MIN_LEN, MAVLINK_MSG_ID_TWIST_LEN, MAVLINK_MSG_ID_TWIST_CRC);
#endif
}
#endif

#endif

// MESSAGE TWIST UNPACKING


/**
 * @brief Get field time_boot_ms from twist message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_twist_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field Vx from twist message
 *
 * @return [m/s] X axis speed
 */
static inline float mavlink_msg_twist_get_Vx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field Vy from twist message
 *
 * @return [m/s] Y axis speed
 */
static inline float mavlink_msg_twist_get_Vy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field Vz from twist message
 *
 * @return [m/s] Z axis speed
 */
static inline float mavlink_msg_twist_get_Vz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field Wx from twist message
 *
 * @return [rad/s] Roll angular speed
 */
static inline float mavlink_msg_twist_get_Wx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field Wy from twist message
 *
 * @return [rad/s] Pitch angular speed
 */
static inline float mavlink_msg_twist_get_Wy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field Wz from twist message
 *
 * @return [rad/s] Yaw angular speed
 */
static inline float mavlink_msg_twist_get_Wz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Decode a twist message into a struct
 *
 * @param msg The message to decode
 * @param twist C-struct to decode the message contents into
 */
static inline void mavlink_msg_twist_decode(const mavlink_message_t* msg, mavlink_twist_t* twist)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    twist->time_boot_ms = mavlink_msg_twist_get_time_boot_ms(msg);
    twist->Vx = mavlink_msg_twist_get_Vx(msg);
    twist->Vy = mavlink_msg_twist_get_Vy(msg);
    twist->Vz = mavlink_msg_twist_get_Vz(msg);
    twist->Wx = mavlink_msg_twist_get_Wx(msg);
    twist->Wy = mavlink_msg_twist_get_Wy(msg);
    twist->Wz = mavlink_msg_twist_get_Wz(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TWIST_LEN? msg->len : MAVLINK_MSG_ID_TWIST_LEN;
        memset(twist, 0, MAVLINK_MSG_ID_TWIST_LEN);
    memcpy(twist, _MAV_PAYLOAD(msg), len);
#endif
}
