//
// Created by Maryam Karimi on 9/30/18.
//

#include <string>
#include "Memory.h"

using namespace std;

// constructor: creates an object of memory and calls to_String on it to print info about memory

int main(){
    Memory memory = Memory();
    memory.to_String();
}