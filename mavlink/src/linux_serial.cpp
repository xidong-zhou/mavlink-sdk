/**
 * @file linux_serial.cpp
 * @brief Linux serial interface definition
 * 
 * Functions for opening, closing, reading and writing via serial ports
 * 
 * @author Hang Zhong (zhonghanghnueeit@gmail.com)
 * @version 1.0
 * @date 2020-05-06
 * 
 * @copyright Copyright (c) 2020  aimijia tech
 * 
 * @par Modify log:
 * <table>
 * <tr><th>Date       <th>Version <th>Author  <th>Description
 * <tr><td>2020-05-06 <td>1.0     <td>Hang Zhong     <td>first add
 * </table>
 */



// ------------------------------------------------------------------------------
//   Includes
// ------------------------------------------------------------------------------
#include "../include/legacy/linux_serial.h"  /* Std. function protos */
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <stdlib.h>  /* Malloc */
#include <assert.h>
#include <iostream>

// ----------------------------------------------------------------------------------
//   Serial Port Manager Class
// ----------------------------------------------------------------------------------


/**
 * @brief serial port constructor
 * @param none
 * @return none
 */
Serial_Port::Serial_Port()
{
    initialize_defaults();
}

/**
 * @brief serial port constructor
 * @param uart_name_    the uart name pointer
 * @param baudrate_     the baudrate
 * @return none
 */
Serial_Port::Serial_Port(const char *uart_name_, int baudrate_)
{
    initialize_defaults();
    uart_name = uart_name_;
    baudrate = baudrate_;
}

/**
 * @brief initial values
 * @param none
 * @return none
 */
void Serial_Port::initialize_defaults()
{
    // Initialize attributes
    uart_name = (char*)"/dev/ttyUSB0";
    baudrate = 115200;
    is_open = false;
}

/**
 * @brief open the serial port
 * @param none
 * @return the serial open status
 * @retval -3 open failed, unable open the serial port
 * @retval others is success
 */
int Serial_Port::Open()
{
    int fd; /* File descriptor for the port */

    fd = open(uart_name, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1)
    {
        fprintf(stderr, "Unable to open %s\n\r", uart_name);
        return -3;
    }

    // Verify it is a serial port
    if (!isatty(fd))
    {
        close(fd);
        fprintf(stderr, "%s is not a serial port\n", uart_name);
        return -3;
    }

    // Finalize: non-blocking
    //fcntl(fd, F_SETFL, FNDELAY);
    
    is_open = true;
    handle = fd;
    return fd;
}

/**
 * @brief setup the serial port
 * @param none
 * @return setup serial status
 * @retval 0 open success
 */
int Serial_Port::Setup()
{
    struct termios options;

    // Get the current options for the port...
    tcgetattr(handle, &options);

    /*// 8 bits, 1 stop, no parity
    options.c_cflag &= ~(CSIZE | PARENB);
    options.c_cflag |= CS8;         // 8-bit input

    // Enable the receiver and set local mode...
    options.c_cflag |= (CLOCAL | CREAD);

    // Set the baud rates to 115200...
    cfsetispeed(&options, baudrate);
    cfsetospeed(&options, baudrate);

    // No input processing
    options.c_iflag = 0;

    // No output processing
    options.c_oflag = 0;

    // No line processing
    options.c_lflag = 0;

    // read timeout
    options.c_cc[VMIN] = 0;    // non-blocking
    options.c_cc[VTIME] = 1;    // always return after 0.1 seconds*/

    // Input flags - Turn off input processing
	// convert break to null byte, no CR to NL translation,
	// no NL to CR translation, don't mark parity errors or breaks
	// no input parity check, don't strip high bit off,
	// no XON/XOFF software flow control
	options.c_iflag &= ~(IGNBRK | BRKINT | ICRNL |
						INLCR | PARMRK | INPCK | ISTRIP | IXON);

	// Output flags - Turn off output processing
	// no CR to NL translation, no NL to CR-NL translation,
	// no NL to CR translation, no column 0 CR suppression,
	// no Ctrl-D suppression, no fill characters, no case mapping,
	// no local output processing
	options.c_oflag &= ~(OCRNL | ONLCR | ONLRET |
						 ONOCR | OFILL | OPOST);

	#ifdef OLCUC
		options.c_oflag &= ~OLCUC;
	#endif

	#ifdef ONOEOT
		options.c_oflag &= ~ONOEOT;
	#endif

	// No line processing:
	// echo off, echo newline off, canonical mode off,
	// extended input processing off, signal chars off
    options.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN | ISIG);

	// Turn off character processing
	// clear current char size mask, no parity checking,
	// no output processing, force 8 bit input
	options.c_cflag &= ~(CSIZE | PARENB);
	options.c_cflag |= CS8;

	// One input byte is enough to return from read()
	// Inter-character timer off
	options.c_cc[VMIN]  = 0;
	options.c_cc[VTIME] = 1; // was 0

	// Get the current options for the port
	////struct termios options;
	////tcgetattr(fd, &options);

    // Apply baudrate
	switch (baudrate)
	{
		case 1200:
			if (cfsetispeed(&options, B1200) < 0 || cfsetospeed(&options, B1200) < 0)
			{
				fprintf(stderr, "\nERROR: Could not set desired baud rate of %d Baud\n", baudrate);
				return false;
			}
			break;
		case 1800:
			cfsetispeed(&options, B1800);
			cfsetospeed(&options, B1800);
			break;
		case 9600:
			cfsetispeed(&options, B9600);
			cfsetospeed(&options, B9600);
			break;
		case 19200:
			cfsetispeed(&options, B19200);
			cfsetospeed(&options, B19200);
			break;
		case 38400:
			if (cfsetispeed(&options, B38400) < 0 || cfsetospeed(&options, B38400) < 0)
			{
				fprintf(stderr, "\nERROR: Could not set desired baud rate of %d Baud\n", baudrate);
				return false;
			}
			break;
		case 57600:
			if (cfsetispeed(&options, B57600) < 0 || cfsetospeed(&options, B57600) < 0)
			{
				fprintf(stderr, "\nERROR: Could not set desired baud rate of %d Baud\n", baudrate);
				return false;
			}
			break;
		case 115200:
			if (cfsetispeed(&options, B115200) < 0 || cfsetospeed(&options, B115200) < 0)
			{
				fprintf(stderr, "\nERROR: Could not set desired baud rate of %d Baud\n", baudrate);
				return false;
			}
			break;

		// These two non-standard (by the 70'ties ) rates are fully supported on
		// current Debian and Mac OS versions (tested since 2010).
		case 460800:
			if (cfsetispeed(&options, B460800) < 0 || cfsetospeed(&options, B460800) < 0)
			{
				fprintf(stderr, "\nERROR: Could not set desired baud rate of %d Baud\n", baudrate);
				return false;
			}
			break;
		case 921600:
			if (cfsetispeed(&options, B921600) < 0 || cfsetospeed(&options, B921600) < 0)
			{
				fprintf(stderr, "\nERROR: Could not set desired baud rate of %d Baud\n", baudrate);
				return false;
			}
			break;
		default:
			fprintf(stderr, "ERROR: Desired baud rate %d could not be set, aborting.\n", baudrate);
			return false;

			break;
	}

    // Set the new options for the port...
    tcsetattr(handle, TCSAFLUSH, &options);

    return 0;
}

/**
 * @brief write data to the serial port
 * @param buffer the buffer address of the write data
 * @param length length of the data written 
 * @return write status
 * @retval 0 success
 * @retval -1 error
 */
int Serial_Port::Write(const unsigned char *buffer, int length)
{
    int n = write(handle, buffer, length);
    if (n < 0)
    {
        fprintf(stderr, "Error in serial write\r\n");
        return -1;
    }

    // serial port output monitor
    //#define TX_DEBUG
    #ifdef TX_DEBUG
        printf("TX:");
        int i;
        for (i=0; i<length; ++i) printf(" %x", (unsigned char)(buffer[i]));
        printf("\r\n");
    #endif

    return n;
}

/**
 * @brief read data from the serial port
 * @param buffer the buffer address of the read data
 * @param length length of the read data 
 * @return read status
 * @retval 0 error or no data
 * @retval others the length of the read data 
 */
int Serial_Port::Read(unsigned char *buffer, int length)
{
    int bytesRead = read(handle, buffer, length);
    if (bytesRead <= 0)
    {
        return 0;
    }

    // serial port input monitor
    //#define RX_DEBUG
    #ifdef RX_DEBUG
        printf("RX:");
        int i;
        for (i=0; i<bytesRead; ++i) printf(" %x", (unsigned char)buffer[i]);
        printf("\r\n");
    #endif

    return bytesRead;
}

/**
 * @brief close the serial port
 * @return int 
 * @retval 0 success
 */
int Serial_Port::Close()
{
    if (!is_open)
    {
        return 0;
    }
    close(handle);
    is_open = false;
    return 0;
}
