#include "Job.h"
void JOB::delay(unsigned long __dl_) {
  Delay = __dl_;
}

void JOB::lasttime(unsigned long __lasttime_) {
  curtime = __lasttime_;
  nextloop++;
}

bool JOB::Ready() {
  if((millis() - curtime) >= Delay){
      Delay=0;
      return true;
  }else; return false;
}

void JOB::run(){
	if(Enable){
		if(Ready()){
			lasttime(millis());
                        if(UserF != NULL)
                            UserF();
                        else if(UserF2 != NULL)
                            UserF2(p_data);
                        else;
		}else;
	}else;
}

void JOB::disable(){
	nextloop = 0;
	Enable = false;
}

void JOB::enable(){
	if(Enable == false){
		nextloop = 0;
		Enable = true;
	}
}

void JOB::enable(uint8_t _nextSch_){
	if(Enable == false){
		nextloop = _nextSch_;
		Enable = true;
	}
}

void JOB::begin(pf_UserFunct _UserF_){
	UserF = _UserF_;
	enable();
	isPause = false;
}
void JOB::begin(pf_UserFunct2 _UserF_){
        UserF2 = _UserF_;
        enable();
        isPause = false;
}

void JOB::setloop(uint8_t _nextloop_){
	lastloop = nextloop;
	nextloop = _nextloop_ - 1;
}

void JOB::pause(){
	if(isPause == false){
		Enable = false;
		isPause = true;
	}
}

void JOB::play(){
	if(isPause == true){
		Enable = true;
		isPause = false;
	}
	Enable = true;
}
