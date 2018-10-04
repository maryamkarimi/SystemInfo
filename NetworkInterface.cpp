//
// Created by Maryam Karimi on 9/25/18.
//

#include <iostream>
#include <fstream>
#include <string>
#include "NetworkInterface.h"

using namespace std;

// constructor: initializes name and MAC Address by opening the corresponding file
NetworkInterface::NetworkInterface(string name) {
    string line;
    ifstream file;
    string a = "/sys/class/net/"+name+"/address";
    file.open(a);
    getline(file,line);

    this->MACAddress = line;
    this->name = name;
}

// getter method for MAC Address
string NetworkInterface::getMACAddress() {
    return this->MACAddress;
}

// getter method for name
string NetworkInterface::getName() {
    return this->name;
}

// prints the name and MAC Address of this networkInterface
void NetworkInterface::to_String() {
    cout<<" Name:\t\t\t"<<this->getName()<<"\n MAC Address:\t\t"<<this->getMACAddress()<<endl;
}