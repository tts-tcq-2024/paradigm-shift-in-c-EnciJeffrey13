#include <stdio.h>
 #include <assert.h> 
int batteryIsOk(float temperature, float soc, float chargeRate) 
{ 
const char* error = (temperature < 0 || temperature > 45) ? "Temperature out of range!\n" : 
(soc < 20 || soc > 80) ? "State of Charge out of range!\n" : 
(chargeRate > 0.8) ? "Charge Rate out of range!\n" : NULL; 
if (error) { printf("%s", error);
 return 0; 
} 
return 1;
 } 

int main() 
{ 
assert(batteryIsOk(25, 70, 0.7)); 
assert(!batteryIsOk(50, 85, 0)); 
return 0; 
}
