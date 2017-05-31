#ifndef _hardware_serial_h_
#define _hardware_serial_h_

#include "../platform_setup.h"
#include "cmd_line.h"

#define SHELL_BUFFER_LENGHT				(16)

typedef struct {
    uint8_t index;
    uint8_t data[SHELL_BUFFER_LENGHT];
} shell_test;

typedef struct {
    uint8_t c_char;
    cmd_line_t* table;
    shell_test* shell;
} serial_pare_data;

#if defined(ARDUINO_IDE)
    #define serial_read             Serial.read
    #define serial_begin(x)         Serial.begin(x)
    #define serial_print(x)         Serial.print(x)
    #define serial_println(x)       Serial.println(x)
    #define serial_available        Serial.available
#else
    #define serial_available        (1)
    #define serial_read
    #define serial_begin(x)
    #define serial_print(x)
    #define serial_println(x)

    #error please choose platform for app kxn
#endif

extern shell_test shell;
extern shell_test shell__test;
//extern void serial_begin(uint32_t _baud_);
//extern void serial_print(void*);
//extern int8_t serial_read_char();
extern cmd_line_t lgn_cmd_table[];
extern void serial_iqr();
extern void serial_iqr(void*);
extern void Read_Serial_F(void*);

#endif
