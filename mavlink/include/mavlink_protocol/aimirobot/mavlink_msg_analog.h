#pragma once
// MESSAGE ANALOG PACKING

#define MAVLINK_MSG_ID_ANALOG 57

MAVPACKED(
typedef struct __mavlink_analog_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 float Input[7]; /*< [v] Input channel analog value*/
 float Output[7]; /*< [v] Output channel analog value*/
}) mavlink_analog_t;

#define MAVLINK_MSG_ID_ANALOG_LEN 60
#define MAVLINK_MSG_ID_ANALOG_MIN_LEN 60
#define MAVLINK_MSG_ID_57_LEN 60
#define MAVLINK_MSG_ID_57_MIN_LEN 60

#define MAVLINK_MSG_ID_ANALOG_CRC 139
#define MAVLINK_MSG_ID_57_CRC 139

#define MAVLINK_MSG_ANALOG_FIELD_INPUT_LEN 7
#define MAVLINK_MSG_ANALOG_FIELD_OUTPUT_LEN 7

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ANALOG { \
    57, \
    "ANALOG", \
    3, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_analog_t, time_boot_ms) }, \
         { "Input", NULL, MAVLINK_TYPE_FLOAT, 7, 4, offsetof(mavlink_analog_t, Input) }, \
         { "Output", NULL, MAVLINK_TYPE_FLOAT, 7, 32, offsetof(mavlink_analog_t, Output) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ANALOG { \
    "ANALOG", \
    3, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_analog_t, time_boot_ms) }, \
         { "Input", NULL, MAVLINK_TYPE_FLOAT, 7, 4, offsetof(mavlink_analog_t, Input) }, \
         { "Output", NULL, MAVLINK_TYPE_FLOAT, 7, 32, offsetof(mavlink_analog_t, Output) }, \
         } \
}
#endif

/**
 * @brief Pack a analog message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param Input [v] Input channel analog value
 * @param Output [v] Output channel analog value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_analog_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, const float *Input, const float *Output)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ANALOG_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float_array(buf, 4, Input, 7);
    _mav_put_float_array(buf, 32, Output, 7);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ANALOG_LEN);
#else
    mavlink_analog_t packet;
    packet.time_boot_ms = time_boot_ms;
    mav_array_memcpy(packet.Input, Input, sizeof(float)*7);
    mav_array_memcpy(packet.Output, Output, sizeof(float)*7);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ANALOG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ANALOG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ANALOG_MIN_LEN, MAVLINK_MSG_ID_ANALOG_LEN, MAVLINK_MSG_ID_ANALOG_CRC);
}

/**
 * @brief Pack a analog message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param Input [v] Input channel analog value
 * @param Output [v] Output channel analog value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_analog_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,const float *Input,const float *Output)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ANALOG_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float_array(buf, 4, Input, 7);
    _mav_put_float_array(buf, 32, Output, 7);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ANALOG_LEN);
#else
    mavlink_analog_t packet;
    packet.time_boot_ms = time_boot_ms;
    mav_array_memcpy(packet.Input, Input, sizeof(float)*7);
    mav_array_memcpy(packet.Output, Output, sizeof(float)*7);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ANALOG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ANALOG;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ANALOG_MIN_LEN, MAVLINK_MSG_ID_ANALOG_LEN, MAVLINK_MSG_ID_ANALOG_CRC);
}

/**
 * @brief Encode a analog struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param analog C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_analog_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_analog_t* analog)
{
    return mavlink_msg_analog_pack(system_id, component_id, msg, analog->time_boot_ms, analog->Input, analog->Output);
}

/**
 * @brief Encode a analog struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param analog C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_analog_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_analog_t* analog)
{
    return mavlink_msg_analog_pack_chan(system_id, component_id, chan, msg, analog->time_boot_ms, analog->Input, analog->Output);
}

/**
 * @brief Send a analog message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param Input [v] Input channel analog value
 * @param Output [v] Output channel analog value
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_analog_send(mavlink_channel_t chan, uint32_t time_boot_ms, const float *Input, const float *Output)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ANALOG_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float_array(buf, 4, Input, 7);
    _mav_put_float_array(buf, 32, Output, 7);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANALOG, buf, MAVLINK_MSG_ID_ANALOG_MIN_LEN, MAVLINK_MSG_ID_ANALOG_LEN, MAVLINK_MSG_ID_ANALOG_CRC);
#else
    mavlink_analog_t packet;
    packet.time_boot_ms = time_boot_ms;
    mav_array_memcpy(packet.Input, Input, sizeof(float)*7);
    mav_array_memcpy(packet.Output, Output, sizeof(float)*7);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANALOG, (const char *)&packet, MAVLINK_MSG_ID_ANALOG_MIN_LEN, MAVLINK_MSG_ID_ANALOG_LEN, MAVLINK_MSG_ID_ANALOG_CRC);
#endif
}

/**
 * @brief Send a analog message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_analog_send_struct(mavlink_channel_t chan, const mavlink_analog_t* analog)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_analog_send(chan, analog->time_boot_ms, analog->Input, analog->Output);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANALOG, (const char *)analog, MAVLINK_MSG_ID_ANALOG_MIN_LEN, MAVLINK_MSG_ID_ANALOG_LEN, MAVLINK_MSG_ID_ANALOG_CRC);
#endif
}

#if MAVLINK_MSG_ID_ANALOG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_analog_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, const float *Input, const float *Output)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float_array(buf, 4, Input, 7);
    _mav_put_float_array(buf, 32, Output, 7);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANALOG, buf, MAVLINK_MSG_ID_ANALOG_MIN_LEN, MAVLINK_MSG_ID_ANALOG_LEN, MAVLINK_MSG_ID_ANALOG_CRC);
#else
    mavlink_analog_t *packet = (mavlink_analog_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    mav_array_memcpy(packet->Input, Input, sizeof(float)*7);
    mav_array_memcpy(packet->Output, Output, sizeof(float)*7);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANALOG, (const char *)packet, MAVLINK_MSG_ID_ANALOG_MIN_LEN, MAVLINK_MSG_ID_ANALOG_LEN, MAVLINK_MSG_ID_ANALOG_CRC);
#endif
}
#endif

#endif

// MESSAGE ANALOG UNPACKING


/**
 * @brief Get field time_boot_ms from analog message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_analog_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field Input from analog message
 *
 * @return [v] Input channel analog value
 */
static inline uint16_t mavlink_msg_analog_get_Input(const mavlink_message_t* msg, float *Input)
{
    return _MAV_RETURN_float_array(msg, Input, 7,  4);
}

/**
 * @brief Get field Output from analog message
 *
 * @return [v] Output channel analog value
 */
static inline uint16_t mavlink_msg_analog_get_Output(const mavlink_message_t* msg, float *Output)
{
    return _MAV_RETURN_float_array(msg, Output, 7,  32);
}

/**
 * @brief Decode a analog message into a struct
 *
 * @param msg The message to decode
 * @param analog C-struct to decode the message contents into
 */
static inline void mavlink_msg_analog_decode(const mavlink_message_t* msg, mavlink_analog_t* analog)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    analog->time_boot_ms = mavlink_msg_analog_get_time_boot_ms(msg);
    mavlink_msg_analog_get_Input(msg, analog->Input);
    mavlink_msg_analog_get_Output(msg, analog->Output);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ANALOG_LEN? msg->len : MAVLINK_MSG_ID_ANALOG_LEN;
        memset(analog, 0, MAVLINK_MSG_ID_ANALOG_LEN);
    memcpy(analog, _MAV_PAYLOAD(msg), len);
#endif
}
