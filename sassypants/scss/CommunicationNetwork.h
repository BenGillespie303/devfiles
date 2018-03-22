#ifndef CommunicationNetwork_h
#define Communication_h

#include <stdio.h>
#include <iostream>

using namespace std;

struct City {
	string cityName;
	string message;
	City *next;
	City *previous;

	City();
	City (string initName, City *initNext, City *initPrevious, string initMessage) {
		cityName=initName;
		next=initNext;
		previous=initPrevious;
		message=initMessage;
	}
};

class CommunicationNetwork {
	public:
		CommunicationNetwork();
		~CommunicationNetwork();
		void addCity (string, string);
		void buildNetwork();
		void transmitMsg(char *);
		void printNetwork();
		void deleteCity(string);
		void deleteNetwork();
	private:
		City *head;
		City *tail;
};

#endif /* CommunicationNetwork_h */
