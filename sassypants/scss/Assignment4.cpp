//Author: Ben Gillespie
//Data Structures
////CSCI2270-102 Bhimami

#include <iostream>
#include "CommunicationNetwork.hpp"
using namespace std;
struct city {
    string cityName;
     string message;
    city *next;
    city() {};
    city(string initName, city *initNext,  string initMessage) {
        cityName=initName;
        message=initMessage;
        next=initNext;
    }
};

void printMenu() {
    cout << "======Main Menu======" << endl;
    cout << "1. Build Network" << endl;
    cout << "2. Print Network Path" <<  endl;
    cout << "3. Transmit Message Coast-To-Coast-To-Coast" <<  endl;
    cout << "4. Add City" << endl;
    cout << "5. Delete City" << endl;
    cout << "6. Clear Network" <<endl;
    cout << "7. Quit" << endl;
    
}

int main(int argc, char *argv[]) {
    int value;
    CommunicationNetwork communication;
    printMenu();
    cin >> value;
    while(input!=7) {
        if (value==1) {
            communication.buildNetwork();
            communication.printNetwork();
        }
        else if (value==2) {
            communication.printNetwork();
        }
        
        else if (value==3) {
            communication.transmitMsg(argv[1]);
        }
        else if (value==4) {
            string cityNew;
            string cityPrevious;
            cout << "Enter a City name: " << endl;
            cin>> cityNew;
            cout << "Enter a previous City name: " << endl;
            cin>> cityPrevious;
            communication.addCity(cityNew, cityPrevious);
        }
        else if (value==5) {
            string str1;
            cout << "Enter a city name: " << endl;
            cin>> str1;
            communication.deleteCity(str1);
        }
        else if (value==6) {
            communication.deleteNetwork();
        }
        printMenu();
        cin >> value;
    }
    cout << "Goodbye!" << endl;
}