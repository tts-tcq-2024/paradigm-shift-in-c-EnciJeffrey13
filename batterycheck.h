#ifndef BATTERY_CHECK_H
#define BATTERY_CHECK_H

typedef enum {
    OK,
    TEMP_WARNING,
    TEMP_OUT_OF_RANGE,
    SOC_WARNING,
    SOC_OUT_OF_RANGE,
    CHARGE_WARNING,
    CHARGE_OUT_OF_RANGE
} BatteryStatus;

const char* getErrorMessage(BatteryStatus status, const char* language);
BatteryStatus checkTemperature(float temperature);
BatteryStatus checkSoc(float soc);
BatteryStatus checkChargeRate(float chargeRate);
int batteryIsOk(float temperature, float soc, float chargeRate);

#endif
