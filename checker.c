#include <stdio.h>
#include <assert.h>

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int isOk = 1;
    const char *errorMessages[3] = { NULL, NULL, NULL };

    if (temperature < 0 || temperature > 45) {
        errorMessages[0] = "Temperature out of range!\n";
        isOk = 0;
    }
    if (soc < 20 || soc > 80) {
        errorMessages[1] = "State of Charge out of range!\n";
        isOk = 0;
    }
    if (chargeRate > 0.8) {
        errorMessages[2] = "Charge Rate out of range!\n";
        isOk = 0;
    }

    for (int i = 0; i < 3; ++i) {
        if (errorMessages[i] != NULL) {
            printf("%s", errorMessages[i]);
        }
    }

    return isOk;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    return 0;
}
