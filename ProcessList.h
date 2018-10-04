//
// Created by Maryam Karimi on 9/24/18.
//

#ifndef VMSHARE_PROCESSESLIST_H
#define VMSHARE_PROCESSESLIST_H
#include <string>
#include <list>
#include "process.h"


class ProcessesList {

public:
    ProcessesList();
    void to_String();
    bool isInteger(std::string str);

private:
    std::list<Process> processesList;

};


#endif //VMSHARE_PROCESSESLIST_H