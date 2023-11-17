#include "ConfigReader.h"

void ConfigReader::InputSettingsReader(const std::string &inputConfig) {
    configFile.open(inputConfig);

    if (configFile.is_open()) {
        char inputKey;

        std::string command;
        std::string line;
        while (std::getline(configFile, line)) {
            if (!(configFile >> inputKey >> command)) {
                std::cout<<"Error while reading input config file. \n";
                break;
            }

            int count = keyMap.count(inputKey);
            int countCommands = 0;
            auto it = keyMap.begin();
            while(it != keyMap.end()){
                if(it->second == command)
                    ++countCommands;
                ++it;
            }
            if (count == 0 && countCommands < 2) {
                if (isupper(inputKey)) {
                    keyMap.insert(std::pair<int, std::string>(inputKey, command));
                    inputKey = tolower(inputKey);
                    keyMap.insert(std::pair<int, std::string>(inputKey, command));
                }
                else {
                    keyMap.insert(std::pair<int, std::string>(inputKey, command));
                    inputKey = toupper(inputKey);
                    keyMap.insert(std::pair<int, std::string>(inputKey, command));
                }
            }
        }
        keyMap.insert(std::pair<int, std::string>(27, "menu"));
    }
    else
        std::cout<<"Input config file was not found. \n";
}


ConfigReader::~ConfigReader() {
    if (configFile.is_open())
    configFile.close();
}

std::map<int, std::string>* ConfigReader::getKeyList() {
    return &keyMap;
}
