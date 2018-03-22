//Author: Ben Gillespie
//Assignment 4
//CSCI2270-102 Bhimami



#include <fstream>
#include "CommunicationNetwork.h"
using namespace std;

//communication network constructer
//implimenting the head and the tail as null objects

CommunicationNetwork::CommunicationNetwork(){
    head=NULL;
    tail=NULL;
}

//this is the communication network destructor
//

CommunicationNetwork::~CommunicationNetwork() {
    deleteNetwork();
    head=NULL;
    tail=NULL;
}

//this function adds cities to the linked list

void CommunicationNetwork::addCity(string newCityName, string previousCityName) {
    City *curr, *temp, *next;
    if (head==NULL) {
        head=new City;
        head->next=NULL;
        head->cityName=newCityName;
        head->previous=nullptr;
        head->message="";
        tail=head;
    }

    else {
        if (previousCityName=="First") {
            temp=new City;
            temp->cityName=newCityName;
            temp->message="";
            temp->next=head;
            head->previous=tmp;
            temp->previous=NULL;
            head=tmep;
        }
        else if (previousCityName==""||tail->cityName==previousCityName) {
            temp=new City;
            temp->cityName=newCityName;
            temp->message="";
            temp->next=NULL;
            temp->previous=tail;
            tail->next=tmp;
            tail=temp;
            tail->next=NULL;
        }
        else {
            curr=head;
            while (curr!=NULL) {
                if (curr->cityName==previousCityName) {
                    break;
                }
                current=current->next;
            }
            temp=new City;
            temp->cityName=newCityName;
            temp->message="";
            next=curr->next;
            curr->next=temp;
            temp->previous=curr;
            temp->next=next;
            next->previous=temp;
            
        }
    }
}

//this function builds the network with the specified cities

void CommunicationNetwork::buildNetwork() {
    City *temp,*curr;
    head=new City;
    string array[10]= {"Los Angeles", "Phoenix", "Denver", "Dallas","St. Louis","Chicago","Atlanta", "Washington, D.C.", "New York", "Boston"};
    head->cityName=array[0];
    head->next=nullptr;
    head->previous=nullptr;
    head->message="";
    curr=head;
    int i=0;
    while (i<9) {
        tmep=new City;
        temp->cityName=array[i];
        temp->message="";
        temp->previous=curr;
        temp->next=nullptr;
        curr->next=temp;
        curr=temp;
        i++;
    }
    tail=curr;
}

//this function transmits the message between the cities
//it utilizes the linked list and uses the class to transmit the message

void CommunicationNetwork::transmitMsg(char *file) {
    if (head==nullptr) {
        cout << "Empty list" << endl;
    }
    else {
        ifstream myFile;
        string string1;
        City *current;
        myFile.open(file);
        if (!readFile.fail()) {
            while (getline(readFile,string1,' ')) {
                if (string1[string1.length()-1]=='\n') {
                    string1=string1.substr(0,string1.length()-1);
                }
                current=head;
                while(current!=nullptr) {
                    current->message=newstr;
                    cout<<current->cityName<<" received "<< current->message<<endl;
                    current=current->next;
                }
                current=tail->previous;
                while (current!=nullptr) {
                    current->message=newstr;
                    cout << current->cityName << " received " << current->message <<endl;
                    current=current->previous;
                }
            }
        }
        else {
            cout <<"The file " << *file << " could not be opened" << endl;
        }
    }
}

//this function prints the message to the console. It is a variation of the algorithm given in recitation.

void CommunicationNetwork::printNetwork() {
    City *curr;
    curr=head;
    cout << "===CURRENT PATH===" << endl;
    cout << "NULL <- ";
    while (curr!=nullptr) {
        if (curr==tail) {
            cout <<curr->cityName;
        }
        else {
            cout << curr->cityName << " <-> ";
        }
        curr=curr->next;
    }
    cout << " -> NULL" <<endl;
    cout <<"==================" << endl;
}

//this function deletes a city from a linked list

void CommunicationNetwork::deleteCity(string name) {
    City *curr,*previous,*next,*prev;
    curr=head;
    bool found=false;
    while(curr!=nullptr) {
        if (curr->cityName==name) {
            found=true;
            break;
        }
        curr=curr->next;
    }
    if (head->cityName==name) {
        next=head->next;
        next->previous=nullptr;
        delete head;
        head=next;
    }
    else if (tail->cityName==name) {
        next=tail->previous;
        next->next=nullptr;
        delete tail;
        tail=next;
    }
    else if (found==true) {
        previous=current->previous;
        next=curr->next;
        previous->next=next;
        next->previous=previous;
        delete curr;
    }
    else if (found==false) {
        cout << name << " not found" << endl;
    }
}

//this function deletes the network from the linked list

void CommunicationNetwork::deleteNetwork() {
    City *curr=head;
    City *temp;
    while (curr!=nullptr) {
        temp=curr->next;
        cout << "deleting " <<current->cityName << endl;
        delete curr;
        curr=temp;
    }
    head=NULL;
    
}


