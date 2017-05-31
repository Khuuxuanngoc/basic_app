/**
 ******************************************************************************
 * @author: ThanNT
 * @date:   13/08/2016
 ******************************************************************************
**/

#ifndef __CMD_LINE_H__
#define __CMD_LINE_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

#define MAX_CMD_SIZE			12

#define CMD_TBL_NOT_FOUND		0
#define CMD_SUCCESS				1
#define CMD_NOT_FOUND			2
#define CMD_TOO_LONG			3

typedef int8_t (*pf_cmd_func)(void* argv);		// kxn edit

typedef struct {
	const int8_t* cmd;
	pf_cmd_func func;
	const int8_t* info;
}cmd_line_t;

extern uint8_t cmd_line_parser(cmd_line_t* cmd_table, uint8_t* command);

#ifdef __cplusplus
}
#endif

#endif //__CMD_LINE_H__
