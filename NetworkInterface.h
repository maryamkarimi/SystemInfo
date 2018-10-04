//
// Created by Maryam Karimi on 9/25/18.
//

#ifndef VMSHARE_NETWORKINTERFACE_H
#define VMSHARE_NETWORKINTERFACE_H
#include <string>

class NetworkInterface {

public:
    NetworkInterface(std::string name);
    std::string getName();
    std::string getMACAddress();
    void to_String();

private:
    std::string name;
    std::string MACAddress;
};


#endif //VMSHARE_NETWORKINTERFACE_H
