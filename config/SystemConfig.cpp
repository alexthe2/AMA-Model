#include "SystemConfig.h"

#include <fstream>
#include <iostream>
#include <sstream>

static SystemConfig* instance = nullptr;

SystemConfig::SystemConfig() {
    configMap = std::map<std::string, double>();

    // load .env config
    loadDotEnvConfig(".env");
}

SystemConfig* SystemConfig::getInstance() {
    if (instance == nullptr) {
        instance = new SystemConfig();
    }
    return instance;
}

double SystemConfig::getENV(std::string envName) {
    // check whetehr the environment variable exists in configMap
    if (configMap.find(envName) != configMap.end()) {
        return configMap[envName];
    }

    // read from environment variable
    char *r = std::getenv(envName.c_str());
    if (r == nullptr) {
        return 0.0;
    }

    double value = std::stod(r);
    configMap[envName] = value;
    return value;
}

double SystemConfig::getENVorDefault(std::string envName, double defaultValue) {
    // check whetehr the environment variable exists in configMap
    if (configMap.find(envName) != configMap.end()) {
        return configMap[envName];
    }

    // read from environment variable
    char *r = std::getenv(envName.c_str());
    if (r == nullptr) {
        return defaultValue;
    }

    double value = std::stod(r);
    configMap[envName] = value;
    return value;
}

void SystemConfig::loadDotEnvConfig(std::string configPath) {
    std::ifstream file(configPath);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << configPath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        double value;
        if (std::getline(iss, key, '=') && iss >> value) {
            configMap[key] = value;
        }
    }

    file.close();
}
