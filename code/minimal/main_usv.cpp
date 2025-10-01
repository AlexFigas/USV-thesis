#include "USV/USV.h"

GPS_BN880 gps;
IMU_ICM_20948 imu;
Expander expander(0x40);
ThrusterController leftController(14, 1000, 2000, 1500, 50, "left");
ThrusterController rightController(15, 1000, 2000, 1500, 50, "right");
Led yellow(expander, 7);
Led green(expander, 11);
USV usv = USV(expander, leftController, rightController, green, yellow);

void setup()
{
    gps.setup();
    imu.setup();

    usv.begin();
}

void loop()
{
    gps.loop();
    imu.loop();

    usv.getLoRaProto().receive();

    GPSData gpsData = gps.getGPSData();
    IMUData imuData = imu.getIMUData();
    usv.loop(gpsData, imuData);
}
