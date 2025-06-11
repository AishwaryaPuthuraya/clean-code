#include <iostream>

class TemperatureMonitor {
private:
    float temperature;

public:
    void updateTemperature(float valueCelsius) {
        temperature = valueCelsius;
        std::cout << "Temperature updated to " << temperature << " °C" << std::endl;
    }
};

class DimensionVariationMonitor {
private:
    float dimensionVariation;

public:
    void updateDimensionVariation(float variationMM) {
        dimensionVariation = variationMM;
        std::cout << "Dimension variation updated to " << dimensionVariation << " mm" << std::endl;
    }
};

class SelfTestMonitor {
private:
    int selfTestCode;

public:
    void checkSelfTestCode(int code) {
        selfTestCode = code;
        std::cout << "Self-test code set to " << selfTestCode << std::endl;
    }
};

class ContinuousOperationMonitor {
private:
    float continuousOperationMinutes;

public:
    void updateContinuousOperation(int minutes) {
        continuousOperationMinutes = minutes;
        std::cout << "Continuous operation updated to " << continuousOperationMinutes << " minutes" << std::endl;
    }
};

class CNCMachineMonitor {
private:
    TemperatureMonitor tempMonitor;
    DimensionVariationMonitor dvMonitor;
    SelfTestMonitor stMonitor;
    ContinuousOperationMonitor coMonitor;

public:
    void monitor() {
        std::cout << "Monitoring CNC machine..." << std::endl;
        tempMonitor.updateTemperature(75.0f);
        dvMonitor.updateDimensionVariation(0.02f);
        stMonitor.checkSelfTestCode(101);
        coMonitor.updateContinuousOperation(120);
    }
};

// Example usage
int main() {
    CNCMachineMonitor machine;
    machine.monitor();

    return 0;
}
