//
// Created by Maryam Karimi on 9/24/18.
//

#include <iostream>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <string>
#include "OperatingSystem.h"

using namespace std;

// constructor: initializes system Name, release, version, and machine by calling uname
OperatingSystem::OperatingSystem(){
    struct utsname info[1024];
    uname(info);
    this->sysName = info->sysname;
    this->release = info->release;
    this->version = info->version;
    this->machine = info->machine;

    struct sysinfo systemInfo[1024];
    sysinfo(systemInfo);

    calculateUptime(systemInfo->uptime);
}

// getter method for system name
string OperatingSystem::getSysName(){
    return this->sysName;
}

// getter method for release
string OperatingSystem::getRelease(){
    return this->release;
}

// getter method for version
string OperatingSystem::getVersion(){
    return this->version;
}

// getter method for machine
string OperatingSystem::getMachine(){
    return this->machine;
}

// getter method for uptime
string OperatingSystem::getUptime(){
    return this->uptime;
}


// gets a time in seconds and converts it to days:hours:minutes:seconds format - used by constructor
void OperatingSystem::calculateUptime(long seconds){
    long days = seconds/86400;
    seconds-=days*86400;
    long hours = seconds/3600;
    seconds-=hours*3600;
    long minutes = seconds/60;
    seconds-=minutes*60;
    this->uptime = to_string(days)+"days:"+to_string(hours)+"hours:"+to_string(minutes)+"minutes:"+to_string(seconds)+"seconds";
}

// prints the operating system info
void OperatingSystem::to_String() {
    cout<<"\n >> Operating System info"<<endl;
   cout<<" System name:\t\t"<<this->getSysName()<<endl<<" Version:\t\t"<<this->getVersion()<<endl<<
   " Release:\t\t"<<this->getRelease()<<endl<<" Machine:\t\t"<<this->getMachine()<<endl<<" Uptime:\t\t"<<this->getUptime()<<endl;
}
