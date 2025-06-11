#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Handles alerts (can be replaced with logger/file etc.)
class AlertMonitor {
public:
    void alert(const string& message) const {
        cout << "ALERT: " << message << endl;
    }

    void info(const string& message) const {
        cout << message << endl;
    }
};

// Logic for each check

class TemperatureMonitor {
public:
    void check(float temp, const AlertMonitor& alertMtr) const {
        if (temp > 35.0f) {
            alertMtr.alert("High temperature detected (Environment)");
        }
    }
};

class DimensionMonitor {
public:
    void check(float variation, const AlertMonitor& alertMtr) const {
        if (variation > 0.05f) {
            alertMtr.alert("Part-dimension variation too high (Machine)");
        }
    }
};

class OperationMonitor {
public:
    void check(int minutes, const AlertMonitor& alertMtr) const {
        if (minutes > 360) {
            alertMtr.alert("Continuous operation exceeded 6 hours (Machine)");
        }
    }
};

class SelfTestMonitor {
public:
    void interpret(int code, const AlertMonitor& alertMtr) const {
        switch (code) {
            case 0xFF:
                alertMtr.info("Self-test OK");
                break;
            case 0x00:
                alertMtr.alert("No data from machine (Environment)");
                break;
            case 0x01:
                alertMtr.alert("Controller board failure (Machine)");
                break;
            case 0x02:
                alertMtr.alert("Configuration data corrupted (Machine)");
                break;
            default:
                alertMtr.alert("Unknown self-test code (Machine)");
        }
    }
};

// Central coordinator (no alert logic here)
class CNCMachineMonitor {
private:
    TemperatureMonitor tempMtr;
    DimensionMonitor DimensionMtr;
    OperationMonitor opMtr;
    SelfTestMonitor testMtr;
    AlertMonitor alertMtr;

public:
    void monitor(float temp, float variation, int minutes, int selfTestCode) {
        tempMtr.check(temp, alertMtr);
        DimensionMtr.check(variation, alertMtr);
        opMtr.check(minutes, alertMtr);
        testMtr.interpret(selfTestCode, alertMtr);
    }
};

int main() {
    CNCMachineMonitor monitor;
    ifstream infile("cnc_data.txt");

    if (!infile) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    float temp, variation;
    int minutes, selfTest;

    while (infile >> temp >> variation >> minutes >> hex >> selfTest) {
        monitor.monitor(temp, variation, minutes, selfTest);
        cout << "---" << endl;
    }

    infile.close();
    return 0;
}
