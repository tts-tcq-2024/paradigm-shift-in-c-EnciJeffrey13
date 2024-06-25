#include <stdio.h>
#include <assert.h>

int isWithinRange(float value, float min, float max, const char* parameterName) {
  if (value < min || value > max) {
    printf("%s out of range!\n", parameterName);
    return 0;
  }
  return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
  return isWithinRange(temperature, 0, 45, "Temperature") &&
         isWithinRange(soc, 20, 80, "State of Charge") &&
         isWithinRange(chargeRate, 0, 0.8, "Charge Rate");
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  printf("All tests passed.\n");
  return 0;
}
