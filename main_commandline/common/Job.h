#ifndef __JOB_H__
#define __JOB_H__

#include "../platform_setup.h"
#include "../sys/sys_iqr.h"

typedef void (*pf_UserFunct)(void);
typedef void (*pf_UserFunct2)(void*);

class JOB {
    private:
        unsigned long curtime;
        unsigned long Delay;
        bool Enable;
        pf_UserFunct UserF;
        pf_UserFunct2 UserF2;


        bool Ready();//={return((millis()-curtime)>=Delay)?true:false;};
        void lasttime(unsigned long __lasttime_);
    public:

        unsigned char nextloop;
        unsigned char lastloop;
        uint8_t* p_data;

        bool isPause;

        void delay(unsigned long __dl_);
    
	void run();
	void disable();
	void enable();
	void enable(uint8_t _nextloop_);
        void begin(pf_UserFunct);
        void begin(pf_UserFunct2);

	void setloop(uint8_t _nextloop_);
	void pause();
	void play();
};
#endif //__JOB_H__
