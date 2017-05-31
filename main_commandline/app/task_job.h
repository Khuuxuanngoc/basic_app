/***********************************************************
Author: Ngoc Xuan Khuu
Date: 30/05/2017
***********************************************************/
#ifndef _task_job_h_
#define _task_job_h_

#include "../platform_setup.h"
#include "../common/Job.h"

typedef uint8_t	task_pri_t_job;
typedef uint8_t	task_id_t_job;
typedef void	(*pf_task_job)(void*);
typedef JOB*    p_job;

typedef struct {
        task_id_t_job           id;
        task_pri_t_job          pri;
        pf_task_job		task;
        p_job                   job;
} task_job;


#endif
