#ifndef _PLATFORM_SETUP_H_
#define _PLATFORM_SETUP_H_
/**********************************************************
                    Choose platform
**********************************************************/
#define ARDUINO_IDE


/**********************************************************
                    Files is included in platform
**********************************************************/
    #if defined(ARDUINO_IDE)
        #include "arduino.h"
    #else
        #error "please choose platform in platform_setup file"
    #endif

#endif
