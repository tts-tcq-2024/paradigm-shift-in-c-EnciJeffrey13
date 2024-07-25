#include "batterycheck.h"
#include <stdio.h>

static const float TEMP_UPPER_LIMIT = 45.0;
static const float TEMP_LOWER_LIMIT = 0.0;
static const float SOC_UPPER_LIMIT = 80.0;
static const float SOC_LOWER_LIMIT = 20.0;
static const float CHARGE_RATE_UPPER_LIMIT = 0.8;

static const float TEMP_WARNING_DELTA = TEMP_UPPER_LIMIT * 0.05;
static const float SOC_WARNING_DELTA = SOC_UPPER_LIMIT * 0.05;
static const float CHARGE_RATE_WARNING_DELTA = CHARGE_RATE_UPPER_LIMIT * 0.05;

const char* getErrorMessage(BatteryStatus status, const char* language) {
    if (strcmp(language, "DE") == 0) {
        switch (status) {
            case TEMP_OUT_OF_RANGE:
                return "Temperatur außerhalb des Bereichs!\n";
            case SOC_OUT_OF_RANGE:
                return "Ladezustand außerhalb des Bereichs!\n";
            case CHARGE_OUT_OF_RANGE:
                return "Laderate außerhalb des Bereichs!\n";
            case TEMP_WARNING:
                return "Warnung: Annäherung an Temperaturgrenze!\n";
            case SOC_WARNING:
                return "Warnung: Annäherung an Ladezustandsgrenze!\n";
            case CHARGE_WARNING:
                return "Warnung: Annäherung an Laderategrenze!\n";
            default:
                return "";
        }
    } else {
        switch (status) {
            case TEMP_OUT_OF_RANGE:
                return "Temperature out of range!\n";
            case SOC_OUT_OF_RANGE:
                return "State of Charge out of range!\n";
            case CHARGE_OUT_OF_RANGE:
                return "Charge Rate out of range!\n";
            case TEMP_WARNING:
                return "Warning: Approaching temperature limit!\n";
            case SOC_WARNING:
                return "Warning: Approaching state of charge limit!\n";
            case CHARGE_WARNING:
                return "Warning: Approaching charge rate limit!\n";
            default:
                return "";
        }
    }
}

BatteryStatus checkBattery(float temperature, float soc, float chargeRate) {
    if (temperature < TEMP_LOWER_LIMIT || temperature > TEMP_UPPER_LIMIT) {
        return TEMP_OUT_OF_RANGE;
    } else if (temperature > TEMP_UPPER_LIMIT - TEMP_WARNING_DELTA || temperature < TEMP_LOWER_LIMIT + TEMP_WARNING_DELTA) {
        return TEMP_WARNING;
    }

    if (soc < SOC_LOWER_LIMIT || soc > SOC_UPPER_LIMIT) {
        return SOC_OUT_OF_RANGE;
    } else if (soc > SOC_UPPER_LIMIT - SOC_WARNING_DELTA || soc < SOC_LOWER_LIMIT + SOC_WARNING_DELTA) {
        return SOC_WARNING;
    }

    if (chargeRate > CHARGE_RATE_UPPER_LIMIT) {
        return CHARGE_OUT_OF_RANGE;
    } else if (chargeRate > CHARGE_RATE_UPPER_LIMIT - CHARGE_RATE_WARNING_DELTA) {
        return CHARGE_WARNING;
    }

    return TEMP_OK;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    BatteryStatus status = checkBattery(temperature, soc, chargeRate);
    if (status != TEMP_OK) {
        printf("%s", getErrorMessage(status, "EN"));
        return 0;
    }
    return 1;
}
