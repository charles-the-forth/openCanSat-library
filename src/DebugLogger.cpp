#include <DebugLogger.h>

void DebugLogger::printAllTransferedData(int messageId, OcsStorage::message1 message1, OcsStorage::message2 message2, OcsStorage::message3 message3, OcsStorage::message4 message4)
{
    SerialUSB.println("Message id: " + String(messageId));

    SerialUSB.println("Light intensity: " + String(message1.lightIntensity));

    SerialUSB.println("UV sensor: " + String(message2.uvIndex));

    SerialUSB.println("Temperature CanSat: " + String(message1.temperatureCanSat));
    SerialUSB.println("Temperature MPU: " + String(message2.temperatureMPU));
    SerialUSB.println("Temperature External: " + String(message1.temperatureExternal));
    SerialUSB.println("Temperature SCD30: " + String(message2.temperatureSCD30));
    SerialUSB.println("Ambient temperature: " + String(message1.ambientTemp));
    SerialUSB.println("Object temperature: " + String(message1.objectTemp));

    SerialUSB.println("Pressure CanSat: " + String(message1.pressureCanSat));
    SerialUSB.println("Pressure External: " + String(message1.pressureExternal));

    SerialUSB.println("Humidity CanSat: " + String(message1.humidityCanSat));
    SerialUSB.println("Humidity External: " + String(message1.humidityExternal));
    SerialUSB.println("Humidity SCD30: " + String(message2.humiditySCD30));

    SerialUSB.println("Altitude CanSat: " + String(message1.altitudeCanSat));
    SerialUSB.println("Altitude External: " + String(message1.altitudeExternal));

    SerialUSB.println("O2: " + String(message2.o2Concentration) + " %");
    SerialUSB.println("Acceleration X: " + String(message3.accelerationX));
    SerialUSB.println("Acceleration Y: " + String(message3.accelerationY));
    SerialUSB.println("Acceleration Z: " + String(message3.accelerationZ));

    SerialUSB.println("Rotation X: " + String(message3.rotationX));
    SerialUSB.println("Rotation Y: " + String(message3.rotationY));
    SerialUSB.println("Rotation Z: " + String(message3.rotationZ));

    SerialUSB.println("Magnetometer X: " + String(message3.magnetometerX));
    SerialUSB.println("Magnetometer Y: " + String(message3.magnetometerY));
    SerialUSB.println("Magnetometer Z: " + String(message3.magnetometerZ));

    SerialUSB.println("CO2 SCD30: " + String(message1.co2SCD30) + " ppm");
    SerialUSB.println("CO2 CCS811: " + String(message1.co2CCS811) + " ppm");
    SerialUSB.println("TVOC CCS811: " + String(message2.tvoc) + " ppb");

    SerialUSB.println("A: " + String(message4.a));
    SerialUSB.println("B: " + String(message4.b));
    SerialUSB.println("C: " + String(message4.c));
    SerialUSB.println("D: " + String(message4.d));
    SerialUSB.println("E: " + String(message4.e));
    SerialUSB.println("F: " + String(message4.f));
    SerialUSB.println("G: " + String(message4.g));
    SerialUSB.println("H: " + String(message4.h));
    SerialUSB.println("I: " + String(message4.i));
    SerialUSB.println("J: " + String(message4.j));
    SerialUSB.println("R: " + String(message4.r));
    SerialUSB.println("S: " + String(message4.s));
    SerialUSB.println("T: " + String(message4.t));
}