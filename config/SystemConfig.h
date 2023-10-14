#pragma once

#include <string>
#include <memory>
#include <map>

class SystemConfig {
    private:
        SystemConfig();
        std::map<std::string, double> configMap;

    public:
        static SystemConfig* getInstance();
        double getENV(std::string envName);
        double getENVorDefault(std::string envName, double defaultValue);

        void loadDotEnvConfig(std::string configPath);
};
