#pragma once
// MESSAGE SYS_INFO_VERSION PACKING

#define MAVLINK_MSG_ID_SYS_INFO_VERSION 51

MAVPACKED(
typedef struct __mavlink_sys_info_version_t {
 uint32_t hardware_ver; /*<  System hardware version.*/
 uint32_t software_ver; /*<  System software version.*/
 uint32_t uiud; /*<  System UIUD data*/
}) mavlink_sys_info_version_t;

#define MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN 12
#define MAVLINK_MSG_ID_SYS_INFO_VERSION_MIN_LEN 12
#define MAVLINK_MSG_ID_51_LEN 12
#define MAVLINK_MSG_ID_51_MIN_LEN 12

#define MAVLINK_MSG_ID_SYS_INFO_VERSION_CRC 237
#define MAVLINK_MSG_ID_51_CRC 237



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SYS_INFO_VERSION { \
    51, \
    "SYS_INFO_VERSION", \
    3, \
    {  { "hardware_ver", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_sys_info_version_t, hardware_ver) }, \
         { "software_ver", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_sys_info_version_t, software_ver) }, \
         { "uiud", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_sys_info_version_t, uiud) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SYS_INFO_VERSION { \
    "SYS_INFO_VERSION", \
    3, \
    {  { "hardware_ver", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_sys_info_version_t, hardware_ver) }, \
         { "software_ver", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_sys_info_version_t, software_ver) }, \
         { "uiud", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_sys_info_version_t, uiud) }, \
         } \
}
#endif

/**
 * @brief Pack a sys_info_version message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param hardware_ver  System hardware version.
 * @param software_ver  System software version.
 * @param uiud  System UIUD data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sys_info_version_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t hardware_ver, uint32_t software_ver, uint32_t uiud)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN];
    _mav_put_uint32_t(buf, 0, hardware_ver);
    _mav_put_uint32_t(buf, 4, software_ver);
    _mav_put_uint32_t(buf, 8, uiud);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN);
#else
    mavlink_sys_info_version_t packet;
    packet.hardware_ver = hardware_ver;
    packet.software_ver = software_ver;
    packet.uiud = uiud;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYS_INFO_VERSION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SYS_INFO_VERSION_MIN_LEN, MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN, MAVLINK_MSG_ID_SYS_INFO_VERSION_CRC);
}

/**
 * @brief Pack a sys_info_version message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param hardware_ver  System hardware version.
 * @param software_ver  System software version.
 * @param uiud  System UIUD data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sys_info_version_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t hardware_ver,uint32_t software_ver,uint32_t uiud)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN];
    _mav_put_uint32_t(buf, 0, hardware_ver);
    _mav_put_uint32_t(buf, 4, software_ver);
    _mav_put_uint32_t(buf, 8, uiud);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN);
#else
    mavlink_sys_info_version_t packet;
    packet.hardware_ver = hardware_ver;
    packet.software_ver = software_ver;
    packet.uiud = uiud;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYS_INFO_VERSION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SYS_INFO_VERSION_MIN_LEN, MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN, MAVLINK_MSG_ID_SYS_INFO_VERSION_CRC);
}

/**
 * @brief Encode a sys_info_version struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sys_info_version C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sys_info_version_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sys_info_version_t* sys_info_version)
{
    return mavlink_msg_sys_info_version_pack(system_id, component_id, msg, sys_info_version->hardware_ver, sys_info_version->software_ver, sys_info_version->uiud);
}

/**
 * @brief Encode a sys_info_version struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sys_info_version C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sys_info_version_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sys_info_version_t* sys_info_version)
{
    return mavlink_msg_sys_info_version_pack_chan(system_id, component_id, chan, msg, sys_info_version->hardware_ver, sys_info_version->software_ver, sys_info_version->uiud);
}

/**
 * @brief Send a sys_info_version message
 * @param chan MAVLink channel to send the message
 *
 * @param hardware_ver  System hardware version.
 * @param software_ver  System software version.
 * @param uiud  System UIUD data
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sys_info_version_send(mavlink_channel_t chan, uint32_t hardware_ver, uint32_t software_ver, uint32_t uiud)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN];
    _mav_put_uint32_t(buf, 0, hardware_ver);
    _mav_put_uint32_t(buf, 4, software_ver);
    _mav_put_uint32_t(buf, 8, uiud);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYS_INFO_VERSION, buf, MAVLINK_MSG_ID_SYS_INFO_VERSION_MIN_LEN, MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN, MAVLINK_MSG_ID_SYS_INFO_VERSION_CRC);
#else
    mavlink_sys_info_version_t packet;
    packet.hardware_ver = hardware_ver;
    packet.software_ver = software_ver;
    packet.uiud = uiud;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYS_INFO_VERSION, (const char *)&packet, MAVLINK_MSG_ID_SYS_INFO_VERSION_MIN_LEN, MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN, MAVLINK_MSG_ID_SYS_INFO_VERSION_CRC);
#endif
}

/**
 * @brief Send a sys_info_version message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sys_info_version_send_struct(mavlink_channel_t chan, const mavlink_sys_info_version_t* sys_info_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sys_info_version_send(chan, sys_info_version->hardware_ver, sys_info_version->software_ver, sys_info_version->uiud);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYS_INFO_VERSION, (const char *)sys_info_version, MAVLINK_MSG_ID_SYS_INFO_VERSION_MIN_LEN, MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN, MAVLINK_MSG_ID_SYS_INFO_VERSION_CRC);
#endif
}

#if MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sys_info_version_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t hardware_ver, uint32_t software_ver, uint32_t uiud)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, hardware_ver);
    _mav_put_uint32_t(buf, 4, software_ver);
    _mav_put_uint32_t(buf, 8, uiud);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYS_INFO_VERSION, buf, MAVLINK_MSG_ID_SYS_INFO_VERSION_MIN_LEN, MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN, MAVLINK_MSG_ID_SYS_INFO_VERSION_CRC);
#else
    mavlink_sys_info_version_t *packet = (mavlink_sys_info_version_t *)msgbuf;
    packet->hardware_ver = hardware_ver;
    packet->software_ver = software_ver;
    packet->uiud = uiud;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYS_INFO_VERSION, (const char *)packet, MAVLINK_MSG_ID_SYS_INFO_VERSION_MIN_LEN, MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN, MAVLINK_MSG_ID_SYS_INFO_VERSION_CRC);
#endif
}
#endif

#endif

// MESSAGE SYS_INFO_VERSION UNPACKING


/**
 * @brief Get field hardware_ver from sys_info_version message
 *
 * @return  System hardware version.
 */
static inline uint32_t mavlink_msg_sys_info_version_get_hardware_ver(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field software_ver from sys_info_version message
 *
 * @return  System software version.
 */
static inline uint32_t mavlink_msg_sys_info_version_get_software_ver(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field uiud from sys_info_version message
 *
 * @return  System UIUD data
 */
static inline uint32_t mavlink_msg_sys_info_version_get_uiud(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Decode a sys_info_version message into a struct
 *
 * @param msg The message to decode
 * @param sys_info_version C-struct to decode the message contents into
 */
static inline void mavlink_msg_sys_info_version_decode(const mavlink_message_t* msg, mavlink_sys_info_version_t* sys_info_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    sys_info_version->hardware_ver = mavlink_msg_sys_info_version_get_hardware_ver(msg);
    sys_info_version->software_ver = mavlink_msg_sys_info_version_get_software_ver(msg);
    sys_info_version->uiud = mavlink_msg_sys_info_version_get_uiud(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN? msg->len : MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN;
        memset(sys_info_version, 0, MAVLINK_MSG_ID_SYS_INFO_VERSION_LEN);
    memcpy(sys_info_version, _MAV_PAYLOAD(msg), len);
#endif
}
