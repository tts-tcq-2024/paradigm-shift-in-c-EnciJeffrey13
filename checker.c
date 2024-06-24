#include <stdio.h>
#include <assert.h>

// Function to check if a value is within a specified range
int isValueInRange(float value, float min, float max, const char* message) {
  if(value < min || value > max) {
    printf("%s out of range!\n", message);
    return 0;
  }
  return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
  return isValueInRange(temperature, 0, 45, "Temperature") &&
         isValueInRange(soc, 20, 80, "State of Charge") &&
         isValueInRange(chargeRate, 0, 0.8, "Charge Rate");
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  printf("All tests passed.\n");
  return 0;
}
