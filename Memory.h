//
// Created by Maryam Karimi on 9/24/18.
//

#ifndef VMSHARE_MEMORY_H
#define VMSHARE_MEMORY_H


class Memory {

public:
    Memory();
    long getTotalRam();
    long getFreeRam();
    long getSharedRam();
    long getBufferRam();
    void to_String();

private:
    long totalRam;
    long freeRam;
    long sharedRam;
    long bufferRam;

};


#endif //VMSHARE_MEMORY_H
