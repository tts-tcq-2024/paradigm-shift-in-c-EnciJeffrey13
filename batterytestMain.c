#include "batteryCheck.h"
#include <assert.h>
#include <stdio.h>

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));

    // Testing warnings
    assert(batteryIsOk(44, 70, 0.7));
    assert(batteryIsOk(25, 76, 0.7));
    assert(batteryIsOk(25, 70, 0.75));

    // Test with German language messages
    printf("%s", getErrorMessage(checkBattery(50, 85, 0), "DE"));
    printf("%s", getErrorMessage(checkBattery(44, 70, 0.7), "DE"));

    return 0;
}
