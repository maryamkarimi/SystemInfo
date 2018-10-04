//
// Created by Maryam Karimi on 9/24/18.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sys/sysinfo.h>
#include "Processor.h"

using namespace std;
// constructor: opens proc/cpuinfo.txt and reads info from it, and initializes vendor,modelName, and clockSpeed
Processor::Processor(){
    // assuming the orders are the same as the file on my comp
    string line;
    ifstream file;
    file.open("/proc/cpuinfo");
    int numLine = 0;
    while (numLine!=7) {
        getline(file,line);
        numLine++;
        switch(numLine){
            case 2:{
                line.erase(line.begin(),line.begin()+12);
                this->vendor = line;
                break;
            }

            case 5:{
                line.erase(line.begin(),line.begin()+13);
                this->modelName = line;
                break;
            }

            case 7:{
                line.erase(line.begin(),line.begin()+11);
                this->clockSpeed = line;
                break;
            }

        }
    }

    file.close();

    struct sysinfo info[3];
    sysinfo(info);
    this->oneCurrentLoadAvg = info->loads[0];
    this->fiveCurrentLoadAvg = info->loads[1];
    this->fifteenCurrentLoadAvg = info->loads[2];
}

// getter method for Vendor
string Processor::getVendor(){
    return this->vendor;
}

// getter method for model name
string Processor::getModelName(){
    return this->modelName;
}

// getter method for clock speed
string Processor::getClockSpeed(){
    return this->clockSpeed;
}

// getter method for 1-minute load average
long Processor::getOneCurrentLoadAvg(){
    return this->oneCurrentLoadAvg;
}

// getter method for 5-minute load average
long Processor::getFiveCurrentLoadAvg(){
    return this->fiveCurrentLoadAvg;
}

// getter method for 15-minute load average
long Processor::getFifteenCurrentLoadAvg(){
    return this->fifteenCurrentLoadAvg;
}

// prints processor info
void Processor::to_String() {
    cout<<"\n >> Processor info"<<endl;
    cout<<" Vendor:\t\t"<<this->getVendor()<<endl<<" Model Name:\t\t"<<this->getModelName()<<endl<<
    " CPU MHz:\t\t"<<this->getClockSpeed()<<endl<<" 1min Load Avg:\t\t"<<this->getOneCurrentLoadAvg()
    <<endl<<" 5min Load Avg:\t\t"<<this->getFiveCurrentLoadAvg()<<endl<<" 15min Load Avg:\t"<<
    this->getFifteenCurrentLoadAvg()<<endl;
}