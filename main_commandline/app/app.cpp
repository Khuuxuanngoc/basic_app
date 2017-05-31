#include "app.h"
#include "shell.h"
#include "../common/hardware_serial.h"
#include "task_list_job.h"
#include "../sys/sys_debug.h"

int8_t main_app(){

    serial_begin(9600);
    app_db("Entry main_app!\r\n");

    Job_table_Create(tb_job, ID_END_OF_JOB);

    while(1){
        Job_Run(tb_job, ID_END_OF_JOB);
    }

    return 0;
}
