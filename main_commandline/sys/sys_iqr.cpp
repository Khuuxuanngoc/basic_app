#include "sys_iqr.h"

uint32_t count_millis = 0;

void system_1_ms_iqr(){
    count_millis++;
}

uint32_t system_millis(){
    return count_millis;
}

