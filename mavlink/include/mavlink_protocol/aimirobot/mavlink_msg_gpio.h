#pragma once
// MESSAGE GPIO PACKING

#define MAVLINK_MSG_ID_GPIO 56

MAVPACKED(
typedef struct __mavlink_gpio_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 uint32_t Input; /*<  GPIO input value bit mapping*/
 uint32_t Output; /*<  GPIO output value bit mapping*/
}) mavlink_gpio_t;

#define MAVLINK_MSG_ID_GPIO_LEN 12
#define MAVLINK_MSG_ID_GPIO_MIN_LEN 12
#define MAVLINK_MSG_ID_56_LEN 12
#define MAVLINK_MSG_ID_56_MIN_LEN 12

#define MAVLINK_MSG_ID_GPIO_CRC 149
#define MAVLINK_MSG_ID_56_CRC 149



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GPIO { \
    56, \
    "GPIO", \
    3, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_gpio_t, time_boot_ms) }, \
         { "Input", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_gpio_t, Input) }, \
         { "Output", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_gpio_t, Output) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GPIO { \
    "GPIO", \
    3, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_gpio_t, time_boot_ms) }, \
         { "Input", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_gpio_t, Input) }, \
         { "Output", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_gpio_t, Output) }, \
         } \
}
#endif

/**
 * @brief Pack a gpio message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param Input  GPIO input value bit mapping
 * @param Output  GPIO output value bit mapping
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gpio_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint32_t Input, uint32_t Output)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GPIO_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, Input);
    _mav_put_uint32_t(buf, 8, Output);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPIO_LEN);
#else
    mavlink_gpio_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.Input = Input;
    packet.Output = Output;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPIO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GPIO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPIO_MIN_LEN, MAVLINK_MSG_ID_GPIO_LEN, MAVLINK_MSG_ID_GPIO_CRC);
}

/**
 * @brief Pack a gpio message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param Input  GPIO input value bit mapping
 * @param Output  GPIO output value bit mapping
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gpio_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint32_t Input,uint32_t Output)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GPIO_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, Input);
    _mav_put_uint32_t(buf, 8, Output);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPIO_LEN);
#else
    mavlink_gpio_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.Input = Input;
    packet.Output = Output;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPIO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GPIO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GPIO_MIN_LEN, MAVLINK_MSG_ID_GPIO_LEN, MAVLINK_MSG_ID_GPIO_CRC);
}

/**
 * @brief Encode a gpio struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gpio C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gpio_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gpio_t* gpio)
{
    return mavlink_msg_gpio_pack(system_id, component_id, msg, gpio->time_boot_ms, gpio->Input, gpio->Output);
}

/**
 * @brief Encode a gpio struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gpio C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gpio_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gpio_t* gpio)
{
    return mavlink_msg_gpio_pack_chan(system_id, component_id, chan, msg, gpio->time_boot_ms, gpio->Input, gpio->Output);
}

/**
 * @brief Send a gpio message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param Input  GPIO input value bit mapping
 * @param Output  GPIO output value bit mapping
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gpio_send(mavlink_channel_t chan, uint32_t time_boot_ms, uint32_t Input, uint32_t Output)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GPIO_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, Input);
    _mav_put_uint32_t(buf, 8, Output);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPIO, buf, MAVLINK_MSG_ID_GPIO_MIN_LEN, MAVLINK_MSG_ID_GPIO_LEN, MAVLINK_MSG_ID_GPIO_CRC);
#else
    mavlink_gpio_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.Input = Input;
    packet.Output = Output;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPIO, (const char *)&packet, MAVLINK_MSG_ID_GPIO_MIN_LEN, MAVLINK_MSG_ID_GPIO_LEN, MAVLINK_MSG_ID_GPIO_CRC);
#endif
}

/**
 * @brief Send a gpio message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gpio_send_struct(mavlink_channel_t chan, const mavlink_gpio_t* gpio)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gpio_send(chan, gpio->time_boot_ms, gpio->Input, gpio->Output);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPIO, (const char *)gpio, MAVLINK_MSG_ID_GPIO_MIN_LEN, MAVLINK_MSG_ID_GPIO_LEN, MAVLINK_MSG_ID_GPIO_CRC);
#endif
}

#if MAVLINK_MSG_ID_GPIO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gpio_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, uint32_t Input, uint32_t Output)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, Input);
    _mav_put_uint32_t(buf, 8, Output);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPIO, buf, MAVLINK_MSG_ID_GPIO_MIN_LEN, MAVLINK_MSG_ID_GPIO_LEN, MAVLINK_MSG_ID_GPIO_CRC);
#else
    mavlink_gpio_t *packet = (mavlink_gpio_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->Input = Input;
    packet->Output = Output;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPIO, (const char *)packet, MAVLINK_MSG_ID_GPIO_MIN_LEN, MAVLINK_MSG_ID_GPIO_LEN, MAVLINK_MSG_ID_GPIO_CRC);
#endif
}
#endif

#endif

// MESSAGE GPIO UNPACKING


/**
 * @brief Get field time_boot_ms from gpio message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_gpio_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field Input from gpio message
 *
 * @return  GPIO input value bit mapping
 */
static inline uint32_t mavlink_msg_gpio_get_Input(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field Output from gpio message
 *
 * @return  GPIO output value bit mapping
 */
static inline uint32_t mavlink_msg_gpio_get_Output(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Decode a gpio message into a struct
 *
 * @param msg The message to decode
 * @param gpio C-struct to decode the message contents into
 */
static inline void mavlink_msg_gpio_decode(const mavlink_message_t* msg, mavlink_gpio_t* gpio)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    gpio->time_boot_ms = mavlink_msg_gpio_get_time_boot_ms(msg);
    gpio->Input = mavlink_msg_gpio_get_Input(msg);
    gpio->Output = mavlink_msg_gpio_get_Output(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GPIO_LEN? msg->len : MAVLINK_MSG_ID_GPIO_LEN;
        memset(gpio, 0, MAVLINK_MSG_ID_GPIO_LEN);
    memcpy(gpio, _MAV_PAYLOAD(msg), len);
#endif
}
