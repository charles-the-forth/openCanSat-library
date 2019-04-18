#include "SDCard.h"

String SDCard::getFilename()
{
    String filename = "000.csv";
    File root = SD.open("/");
    while (true) {
        File entry = root.openNextFile();
        String newEntryName = entry.name();
        if (!entry || newEntryName.equals("SYSTEM~1")) {
            break;
        }
        filename = newEntryName;
        entry.close();
    }

    filename.replace(".csv", "");
  
    int fileNumber = filename.toInt();
    fileNumber++;
    if (fileNumber < 10) {
        filename = "00" + String(fileNumber) + ".csv";
    } else if (fileNumber < 100) {
        filename = "0" + String(fileNumber) + ".csv";
    } else {
        filename = String(fileNumber) + ".csv";
    }
    return filename;
}
