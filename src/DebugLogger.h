#ifndef _DEBUGLOGGER_HH
#define _DEBUGLOGGER_HH

#include "OcsStorage.h"

class DebugLogger
{
public:
    void printAllTransferedData(int messageId, OcsStorage::message1 message1, OcsStorage::message2 message2, OcsStorage::message3 message3, OcsStorage::message4 message4);
};

#endif /* _DEBUGLOGGER_HH */