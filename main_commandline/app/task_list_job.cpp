#include "task_list_job.h"

/*******************************************************************
                Declare Job
*******************************************************************/
JOB test1j;
JOB test2j;
JOB Read_Serial;

/*******************************************************************
                Define Job table
*******************************************************************/
task_job tb_job[] = {
    {ID_START_OF_JOB  ,   1  ,     (pf_task_job)0  ,(p_job)0},

    /*******************************************************************
                    Add your job here
    *******************************************************************/
//    {ID_BLINK_1_JOB ,   2  ,     testvoid1b  ,   &test1j},
//    {ID_BLINK_2_JOB ,   2  ,     testvoid2b  ,   &test2j},
    {ID_READ_SERIAL ,   2  ,     Read_Serial_F  ,   &Read_Serial},


    /*******************************************************************
                    Not modify!
    *******************************************************************/
  {ID_END_OF_JOB  ,   1  ,     (pf_task_job)0  ,(p_job)0},
};



void Job_table_Create(task_job* _tb_job_, uint8_t _size_tb_){
    for(uint8_t cf = 1; cf < _size_tb_; cf++){
        _tb_job_[cf].job->begin(_tb_job_[cf].task);
    }
}

void Job_Run(task_job* _tb_job_, uint8_t _size_tb_){
    for(uint8_t cf = 1; cf < _size_tb_; cf++){
        _tb_job_[cf].job->run();
    }
}
