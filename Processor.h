//
// Created by Maryam Karimi on 9/24/18.
//

#ifndef VMSHARE_PROCESSOR_H
#define VMSHARE_PROCESSOR_H
#include <string>

class Processor {

public:
    Processor();
    std::string getVendor();
    std::string getModelName();
    std::string getClockSpeed();
    long getOneCurrentLoadAvg();
    long getFiveCurrentLoadAvg();
    long getFifteenCurrentLoadAvg();
    void to_String();

private:
    std::string vendor;
    std::string modelName;
    std::string clockSpeed;
    long oneCurrentLoadAvg;
    long fiveCurrentLoadAvg;
    long fifteenCurrentLoadAvg;
};


#endif //VMSHARE_PROCESSOR_H
