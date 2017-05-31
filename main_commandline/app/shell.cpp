#include "shell.h"
#include "../sys/sys_debug.h"
#include "../common/hardware_serial.h"
#include "app.h"

uint8_t enable_info = _DISABLE_;

/*****************************************************************************/
/*  command table
 */
/*****************************************************************************/
cmd_line_t lgn_cmd_table[] = {

    /*************************************************************************/
    /* system command */
    /*************************************************************************/
    {(const int8_t*)"help",   shell_help,     (const int8_t*)"help command info"},
    {(const int8_t*)"info",   shell_info,     (const int8_t*)"on/off info"},
    {(const int8_t*)"ver",   shell_ver,     (const int8_t*)"Get version"},
    {(const int8_t*)"name",   shell_name,     (const int8_t*)"Get name"},

    /*************************************************************************/
    /* debug command */
    /*************************************************************************/

    /* End Of Table */
    {(const int8_t*)0,(pf_cmd_func)0,(const int8_t*)0}
};



/*****************************************************************************/
/*  command function definaion
 */
/*****************************************************************************/

int8_t shell_help(void* _argv) {
    if(enable_info == _ENABLE_){
        char* uuu = (char*)(_argv);
        serial_print("Shell help is running: ");
        serial_println(uuu);
    }

    uint8_t count_cmd = 0;
    while(lgn_cmd_table[count_cmd].cmd != NULL){

        serial_print((char*)lgn_cmd_table[count_cmd].cmd);
        serial_print("\t");
        serial_println((char*)lgn_cmd_table[count_cmd].info);
        count_cmd++;
    }
  return 0;
}

int8_t shell_info(void* _argv) {
    enable_info = !enable_info;
    if(enable_info == _ENABLE_){
        serial_println("Info is ON");
    }else{
        serial_println("Info is OFF");
    }
}

int8_t shell_name(void* _argv) {
    enable_info = !enable_info;
    serial_print((char*) _argv);
    serial_println(NAME_APP);
}

int8_t shell_ver(void* _argv) {
    enable_info = !enable_info;
    serial_print((char*) _argv);
    serial_println(VER_APP);
}
