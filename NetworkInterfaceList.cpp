//
// Created by Maryam Karimi on 9/25/18.
//

#include <string>
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include "NetworkInterfaceList.h"
#include "NetworkInterface.h"
#include "NetworkInterface.cpp"

using namespace std;

/* constructor:
 * opens the sys/class/net directory and goes through all of the files
 * gets the file's name and creates an object of it by passing its name
 * adds the current networkInterface object to the list
 *
 * */
NetworkInterfacesList::NetworkInterfacesList(){
    DIR *directoryEntry;
    struct dirent *info;
    if ((directoryEntry = opendir("/sys/class/net"))!=NULL){
        while((info = readdir(directoryEntry))!=NULL){
            string fileName = info->d_name;
            if (fileName.compare(".")!=0 && fileName.compare("..")!=0) {
                NetworkInterface newNetworkInterface = NetworkInterface(fileName);
                this->networkList.push_back(newNetworkInterface);
            }
        }
        closedir(directoryEntry);
    }

}

// prints all of the network interfaces by calling to_String on all of the networkInterface objects in the list
void NetworkInterfacesList::to_String(){
    cout<<"\n >> Network Interfaces:"<<endl;
    for (NetworkInterface networkInterface: this->networkList){
        networkInterface.to_String();
    }
}
