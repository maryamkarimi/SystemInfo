//
// Created by Maryam Karimi on 9/25/18.
//

#include <list>
#include "NetworkInterface.h"

#ifndef VMSHARE_NETWORKINTERFACESLIST_H
#define VMSHARE_NETWORKINTERFACESLIST_H

class NetworkInterfacesList {

public:
    NetworkInterfacesList();
    void to_String();

private:
    std::list<NetworkInterface> networkList;
};


#endif //VMSHARE_NETWORKINTERFACESLIST_H
