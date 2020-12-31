#include <DebugLogger.h>

DebugLogger::DebugLogger(bool debugLogEnabled, int pcBaudrate)
{
    this->debugLogEnabled = debugLogEnabled;
    this->pcBaudrate = pcBaudrate;
}

void DebugLogger::begin()
{
    SerialUSB.begin(this->pcBaudrate);
}

void DebugLogger::log(String message)
{
    if (this->debugLogEnabled)
    {
        SerialUSB.println(message);
    }
}

void DebugLogger::printAllTransferedData(int messageId, OcsStorage::message1 message1, OcsStorage::message2 message2, OcsStorage::message3 message3, OcsStorage::message4 message4)
{
    log("Message id: " + String(messageId));

    log("Light intensity: " + String(message1.lightIntensity));

    log("UV sensor: " + String(message2.uvIndex));

    log("Temperature CanSat: " + String(message1.temperatureCanSat));
    log("Temperature MPU: " + String(message2.temperatureMPU));
    log("Temperature External: " + String(message1.temperatureExternal));
    log("Temperature SCD30: " + String(message2.temperatureSCD30));
    log("Ambient temperature: " + String(message1.ambientTemp));
    log("Object temperature: " + String(message1.objectTemp));

    log("Pressure CanSat: " + String(message1.pressureCanSat));
    log("Pressure External: " + String(message1.pressureExternal));

    log("Humidity CanSat: " + String(message1.humidityCanSat));
    log("Humidity External: " + String(message1.humidityExternal));
    log("Humidity SCD30: " + String(message2.humiditySCD30));

    log("Altitude CanSat: " + String(message1.altitudeCanSat));
    log("Altitude External: " + String(message1.altitudeExternal));

    log("O2: " + String(message2.o2Concentration) + " %");
    log("Acceleration X: " + String(message3.accelerationX));
    log("Acceleration Y: " + String(message3.accelerationY));
    log("Acceleration Z: " + String(message3.accelerationZ));

    log("Rotation X: " + String(message3.rotationX));
    log("Rotation Y: " + String(message3.rotationY));
    log("Rotation Z: " + String(message3.rotationZ));

    log("Magnetometer X: " + String(message3.magnetometerX));
    log("Magnetometer Y: " + String(message3.magnetometerY));
    log("Magnetometer Z: " + String(message3.magnetometerZ));

    log("CO2 SCD30: " + String(message1.co2SCD30) + " ppm");
    log("CO2 CCS811: " + String(message1.co2CCS811) + " ppm");
    log("TVOC CCS811: " + String(message2.tvoc) + " ppb");

    log("A: " + String(message4.a));
    log("B: " + String(message4.b));
    log("C: " + String(message4.c));
    log("D: " + String(message4.d));
    log("E: " + String(message4.e));
    log("F: " + String(message4.f));
    log("G: " + String(message4.g));
    log("H: " + String(message4.h));
    log("I: " + String(message4.i));
    log("J: " + String(message4.j));
    log("R: " + String(message4.r));
    log("S: " + String(message4.s));
    log("T: " + String(message4.t));
}