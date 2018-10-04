//
// Created by Maryam Karimi on 9/24/18.
//

#include <string>
#include <iostream>

#ifndef VMSHARE_OPERATINGSYSTEM_H
#define VMSHARE_OPERATINGSYSTEM_H

class OperatingSystem {

public:
    OperatingSystem();
    std::string getSysName();
    std::string getRelease();
    std::string getVersion();
    std::string getMachine();
    std::string getUptime();
    void to_String();

private:
    std::string sysName;
    std::string release;
    std::string version;
    std::string machine;
    std::string uptime;
    void calculateUptime(long seconds);

};


#endif //VMSHARE_OPERATINGSYSTEM_H
