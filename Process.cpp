//
// Created by Maryam Karimi on 9/24/18.
//

#include "Process.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sys/sysinfo.h>

using namespace std;

// constructor: initializes id, name, state, parentID, owner UID by opeining the corresponding txt file and reading info
Process::Process(int id){

    this->id = id;

    // assuming the orders are the same as the file on my comp
    string line;
    ifstream file;

    file.open("/proc/"+to_string(id)+"/status");

    int numLine = 0;
    while (numLine!=9) {
        getline(file,line);
        numLine++;

        switch(numLine){
            case 1:{
                line.erase(line.begin(),line.begin()+6);
                this->name = line;
                break;
            }

            case 3:{
                line.erase(line.begin(),line.begin()+7);
                this->state = line;
                break;
            }

            case 7:{

                string number = "";
                for (int i=0; i<line.size();i++){
                    if (isdigit(line.at(i))){
                        number+=line.at(i);
                    }
                }
                this->parentID = stoi(number);
                break;
            }

            case 9:{
                line.erase(line.begin(), line.begin()+4);
                this->ownerUID = line;
                break;
            }
        }
    }

    file.close();
}

// getter method for ID
int Process::getID(){
    return this->id;
}

// getter method for parentID
int Process::getParentID(){
    return this->parentID;
}

// getter method for name
string Process::getName(){
    return this->name;
}

// getter method for ownerUID
string Process::getOwnerUID(){
    return this->ownerUID;
}

// getter method for state
string Process::getState(){
    return this->state;
}

// prints info about this process
void Process::to_String(){
    cout<<" Process ID: \t\t"<<this->getID()<<"\n Parent ID:\t\t"<<this->getParentID()<<"\n Process Name\t\t"<<this->getName()
    <<"\n Owner UID:\t"<<this->getOwnerUID()<<"\n State:\t\t\t"<<this->getState()<<endl;
}