//
// Created by Maryam Karimi on 9/21/18.
//

#include "Hostname.h"
#include <unistd.h>
#include <string>
#include <iostream>

using namespace std;

// constructor: gets the host name using gethostname function
HostName::HostName() {
    char hostname[1024];
    gethostname(hostname, 1023);
    this->hostName = hostname;
}

// returns the name of host name
string HostName::getHostName() {
    return hostName;
}

// prints the name of host name
void HostName::to_string() {
    cout<<" Host Name:\t\t"<<this->getHostName()<<endl;
}
