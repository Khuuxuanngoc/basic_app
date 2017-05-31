#ifndef _SHELL_H_
#define _SHELL_H_

#include "../common/cmd_line.h"
#include "../platform_setup.h"

#if defined(ARDUINO_IDE)
    #include "arduino.h"
#endif

#define	_DISABLE_	0
#define	_ENABLE_	!_DISABLE_

extern uint8_t enable_info;

/*****************************************************************************/
/*  command function declare
 */
/*****************************************************************************/
extern int8_t shell_help(void* argv);
extern int8_t shell_info(void* argv);
extern int8_t shell_name(void* argv);
extern int8_t shell_ver(void* argv);

// /*****************************************************************************/
// /*  command table
 // */
// /*****************************************************************************/
extern cmd_line_t lgn_cmd_table[];

#endif
