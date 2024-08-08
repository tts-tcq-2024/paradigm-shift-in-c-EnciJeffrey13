#include <stdio.h>
#include <stdbool.h>
#include "battery_status.h"

typedef struct {
    float min;
    float max;
    float warning_tolerance;
    bool enable_warning;  
} ParameterConfig;   

ParameterConfig SoC = {20, 80, 0.05, true};
ParameterConfig Temperature = {0, 45, 0.05, true};
ParameterConfig Charge_rate = {0, 0.8, 0.05, true};

enum {
    NORMAL = 0,
    WARNING_LOW,
    WARNING_HIGH,
    ERROR_LOW,
    ERROR_HIGH
};

const char* messages[2][5] = {
    {"Normal", "Warning: Approaching discharge", "Warning: Approaching charge-peak", "Error: Too low", "Error: Too high"},
    // Add messages for other languages if needed
};

int check_value(float value, ParameterConfig config) {
    if (value < config.min) return ERROR_LOW;
    if (value > config.max) return ERROR_HIGH;

    float warning_range = config.max * config.warning_tolerance;
    if (config.enable_warning) {
        if (value < config.min + warning_range) return WARNING_LOW;
        if (value > config.max - warning_range) return WARNING_HIGH;
    }

    return NORMAL;
}

void check_parameter(const char* param_name, float value, ParameterConfig config) {
    int message_index = check_value(value, config);
    printf("%s: %s\n", param_name, messages[0][message_index]);
}

int main() {
    // Example current values for parameters
    float current_SoC = 86;
    float current_Temperature = 43;
    float current_Charge_rate = 0.7;

    // Check each parameter
    printf("Checking parameters with current values:\n");

    check_parameter("SoC", current_SoC, SoC);
    check_parameter("Temperature", current_Temperature, Temperature);
    check_parameter("Charge_rate", current_Charge_rate, Charge_rate);

    return 0;
}
