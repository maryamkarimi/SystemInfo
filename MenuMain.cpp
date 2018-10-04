#include <iostream>
#include <string>

#include "Hostname.h"
#include "OperatingSystem.h"
#include "Memory.h"
#include "Processor.h"
#include "ProcessList.h"
#include "NetworkInterfaceList.h"

#include "Hostname.cpp"
#include "OperatingSystem.cpp"
#include "Memory.cpp"
#include "Processor.cpp"
#include "ProcessList.cpp"
#include "NetworkInterfaceList.cpp"



using namespace std;

// used in main(), prints a menu and asks user to enter a number
void printMenu(){
    cout << "-----------------------------------------------------------------" << endl;
    cout << "- 1. Host Name\t\t\t2. Operating System Info\t-\n- 3. Processor Info\t\t4. Memory Info\t\t\t-\n- 5. Processes Info\t\t"
            "6. Network Interfaces Info\t-" << endl << "- 7. Exit\t\t\t\t\t\t\t-" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << " Enter a number: ";
}

int main() {

    string input = "";

    while (input!="7") {

        printMenu();
        cin >> input;

        if (input.length() == 1 && isdigit(input.at(0))) {
            if (stoi(input) > 0 && stoi(input) < 8) {
                switch (stoi(input)) {
                    case 1: {
                        HostName hostName = HostName();
                        hostName.to_string();
                        break;
                    }

                    case 2: {
                        OperatingSystem opSystem = OperatingSystem();
                        opSystem.to_String();
                        break;
                    }

                    case 3: {
                        Processor processor = Processor();
                        processor.to_String();
                        break;
                    }

                    case 4: {
                        Memory memory = Memory();
                        memory.to_String();
                        break;
                    }

                    case 5: {
                        ProcessesList processes = ProcessesList();
                        processes.to_String();
                        break;
                    }

                    case 6: {
                        NetworkInterfacesList interfaces = NetworkInterfacesList();
                        interfaces.to_String();
                        break;
                    }
                }
            } else {
                cout << " Not between 1 and 7 - Try again." << endl;
            }
        } else {
            cout << " Not a digit - Try again." << endl;
        }
    }

    return 0;
}