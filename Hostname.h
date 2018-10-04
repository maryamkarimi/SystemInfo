//
// Created by Maryam Karimi on 9/21/18.
//

#ifndef VMSHARE_HOSTNAME_H
#define VMSHARE_HOSTNAME_H

#include <string>

class HostName {

public:
    HostName();
    std::string getHostName();
    void to_string();


private:
    std::string hostName;

};


#endif //VMSHARE_HOSTNAME_H
