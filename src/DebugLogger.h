#ifndef _DEBUGLOGGER_HH
#define _DEBUGLOGGER_HH

#include "OcsStorage.h"

class DebugLogger
{
public:
    DebugLogger(bool debugLogEnabled, int pcBaudrate);

    void begin();
    void log(String message);
    void printAllTransferedData(int messageId, OcsStorage::message1 message1, OcsStorage::message2 message2, OcsStorage::message3 message3, OcsStorage::message4 message4);
private:
    bool debugLogEnabled = false;
    int pcBaudrate = 9600;
};

#endif /* _DEBUGLOGGER_HH */