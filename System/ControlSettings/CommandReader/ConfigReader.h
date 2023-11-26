
#ifndef LAB1_CONFIGREADER_H
#define LAB1_CONFIGREADER_H

#include "ICommandReader.h"

class ConfigReader : public ICommandReader{
public:
    ConfigReader() = default;
    void InputSettingsReader(const std::string &inputConfig) override;
    std::map<int, std::string>* getKeyList();

    ~ConfigReader() override;

private:
    std::ifstream configFile;
    std::map<int, std::string> keyMap;
};


#endif //LAB1_CONFIGREADER_H
