#include <stdio.h>
#include <assert.h>

typedef enum {
    TEMP_OK,
    SOC_OK,
    CHARGE_OK,
    TEMP_OUT_OF_RANGE,
    SOC_OUT_OF_RANGE,
    CHARGE_OUT_OF_RANGE
} BatteryStatus;

const char* getErrorMessage(BatteryStatus status) {
    switch (status) {
        case TEMP_OUT_OF_RANGE:
            return "Temperature out of range!\n";
        case SOC_OUT_OF_RANGE:
            return "State of Charge out of range!\n";
        case CHARGE_OUT_OF_RANGE:
            return "Charge Rate out of range!\n";
        default:
            return "";
    }
}

BatteryStatus checkBattery(float temperature, float soc, float chargeRate) {
    if (temperature < 0 || temperature > 45) {
        return TEMP_OUT_OF_RANGE;
    }
    if (soc < 20 || soc > 80) {
        return SOC_OUT_OF_RANGE;
    }
    if (chargeRate > 0.8) {
        return CHARGE_OUT_OF_RANGE;
    }
    return TEMP_OK;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    BatteryStatus status = checkBattery(temperature, soc, chargeRate);
    if (status != TEMP_OK) {
        printf("%s", getErrorMessage(status));
        return 0;
    }
    return 1;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    return 0;
}
