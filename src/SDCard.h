#ifndef _SDCARD_HH
#define _SDCARD_HH

#include <Arduino.h>
#include <SD.h>

class SDCard
{
  public:
	  String getFilename();
};

#endif /* _SDCARD_HH */

