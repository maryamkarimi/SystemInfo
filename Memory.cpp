//
// Created by Maryam Karimi on 9/24/18.
//

#include "Memory.h"
#include <iostream>
#include <string>

#include <sys/sysinfo.h>

using namespace std;

//constructor: initializes the attributes by calling sysinfo
Memory::Memory() {
    struct sysinfo info[1024];
    sysinfo(info);
    this->totalRam = info-> totalram;
    this->bufferRam = info->bufferram;
    this->sharedRam = info->sharedram;
    this->freeRam = info-> freeram;
}

// returns total ram
long Memory::getTotalRam(){
    return this->totalRam;
}

// returns free ram
long Memory::getFreeRam(){
    return this->freeRam;
}

// returns shared ram
long Memory::getSharedRam(){
    return this->sharedRam;
}

// returns buffer ram
long Memory::getBufferRam(){
    return this->bufferRam;
}

// prints info about memory
void Memory::to_String(){
    cout<<"\n >> Memory info"<<endl;
    cout<<" Total Ram:\t\t"<<this->getTotalRam()<<"B"<<endl<<" Free Ram:\t\t"<<this->getFreeRam()<<"B"<<endl<<" Shared Ram:\t\t"<<this->getSharedRam()<<"B"<<endl<<
        " Buffer Ram:\t\t"<<this->getBufferRam()<<"B"<<endl;
}