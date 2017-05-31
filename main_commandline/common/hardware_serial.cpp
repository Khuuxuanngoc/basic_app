#include "hardware_serial.h"
#include "cmd_line.h"

//struct shell_t {
//        uint8_t index;
//        uint8_t data[SHELL_BUFFER_LENGHT];
//} shell;

shell_test shell;
shell_test shell__test;

void serial_iqr(){
#if defined(ARDUINO_IDE)
    if(serial_available()){
#endif
        uint8_t _readchar = serial_read();
        shell.data[shell.index]= _readchar;
        shell.data[shell.index + 1] = 0;
        shell.index++;

        if(_readchar == '\n'){
            cmd_line_parser(lgn_cmd_table, (uint8_t*)shell.data);
            shell.index = 0;
        }else;
#if defined(ARDUINO_IDE)
    }else;
#endif
}

void serial_iqr(void* _serial_data_){
    if(_serial_data_ != NULL){
        serial_pare_data* temp_data = (serial_pare_data*) _serial_data_;

        temp_data->shell->data[temp_data->shell->index]= temp_data->c_char;
        temp_data->shell->data[temp_data->shell->index + 1] = 0;
        temp_data->shell->index++;

        if(temp_data->c_char == '\n'){
            cmd_line_parser(lgn_cmd_table, (uint8_t*)temp_data->shell->data);
            temp_data->shell->index = 0;
        }else;
    }
}

void Read_Serial_F(void*){
    if(Serial.available()){
        serial_pare_data tem_data;
        tem_data.c_char = Serial.read();
        tem_data.table = lgn_cmd_table;
        tem_data.shell = &shell__test;
        serial_iqr(&tem_data);
    }
}
