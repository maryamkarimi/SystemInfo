//
// Created by Maryam Karimi on 9/24/18.
//

#include "ProcessList.h"
#include "Process.cpp"
#include <iostream>
#include <string>
#include <sys/types.h>
#include <dirent.h>

using namespace std;

/* constructor:
 * gets the names of all the files in /proc ,and creates new process objects with those names
 * pushes the process objects to the list of processes
 * */
ProcessesList::ProcessesList(){
    DIR *directoryEntry;
    struct dirent *info;

    if ((directoryEntry = opendir("/proc"))!= NULL){

        while ((info = readdir(directoryEntry))!=NULL){
            string fileName = info->d_name;
            if (isInteger(fileName)){
                Process newProcess = Process(stoi(fileName));
                processesList.push_back(newProcess);
            }
        }
        closedir(directoryEntry);
    }

    else{
        cout<<"can't open";
    }

}

// this method is used by the constructor of this class, gets a string and checks if it's an integer
bool ProcessesList::isInteger(string str){
    for (int i=0; i<str.length(); i++){
        if (!isdigit(str.at(i))){
            return false;
        }
    }
    return true;
}

// calls to_String on all of the process objects in the list
void ProcessesList::to_String() {
    cout<<" >> Processes Info:"<<endl;
    for (Process p: this->processesList){
        p.to_String();
        cout<<"________________________________________________________"<<endl;
    }
}