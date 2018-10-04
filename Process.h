//
// Created by Maryam Karimi on 9/24/18.
//

#include <string>
#ifndef VMSHARE_PROCESS_H
#define VMSHARE_PROCESS_H

class Process {

public:
    Process(int id);
    int getID();
    int getParentID();
    std::string getName();
    std::string getOwnerUID();
    std::string getState();
    void to_String();

private:
    int id;
    int parentID;
    std::string name;
    std::string ownerUID;
    std::string state;

};


#endif //VMSHARE_PROCESS_H
