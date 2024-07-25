#ifndef BATTERY_CHECK_H
#define BATTERY_CHECK_H

typedef enum {
    TEMP_OK,
    SOC_OK,
    CHARGE_OK,
    TEMP_OUT_OF_RANGE,
    SOC_OUT_OF_RANGE,
    CHARGE_OUT_OF_RANGE
} BatteryStatus;

const char* getErrorMessage(BatteryStatus status);
BatteryStatus checkBattery(float temperature, float soc, float chargeRate);
int batteryIsOk(float temperature, float soc, float chargeRate);

#endif
