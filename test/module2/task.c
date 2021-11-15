#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <time.h>
#include <signal.h>

#define __USE_GNU
#include <sched.h>
#include <ctype.h>
#include <string.h>
#include <pthread.h>

#include <fastlog.h>
#include <module2.h>

#include "common.h"

void *task_module2(void*param) 
{
    struct task_arg * arg = (struct task_arg *)param;
    
    set_thread_cpu_affinity(arg->cpu);    
   
    unsigned long total_dequeue = 0;

    while(1) {

        total_dequeue += 3;
    
        M2_CRIT("module 2 %ld\n", total_dequeue);
    
        
        sleep(1);
    }
    pthread_exit(arg);
}

