#include <winsock2.h> 
#include "net.h"
#include <string>

#include <iostream>

using namespace std;

bool playA = false;
bool playB = false;

int portA = 28000;
int portB = 28001;
char * ipAddressA = "149.153.102.62";
char * ipAddressB = "149.153.102.61";
char* msg = "Hello";
int waiting = 0; 
Net n;
bool initialise = false;
 char message[200]="";
string strA = "";
string strB = "";

void playerA(){
	playA = true;
	cout << playA << endl;
	n.setupUDP(portA,ipAddressA);
	n.sendData(ipAddressB, portB, msg);
  
	while(true){
			n.receiveData(message);
		if(	 message[0] != '\0')
		{
			cout << message << endl;
		}			
	}
	
}

void playerB(){
		
	playB = true;
	cout << playB << endl;
	n.setupUDP(portB,ipAddressB);
	n.sendData(ipAddressA, portA, msg);
  

	while(true){
			n.receiveData(message);
		if(	 message[0] != '\0')
		{
			cout << message << endl;
		}			
	}

	

}


int main(){
	
	n.initialise();
	
	cin >> strA;

	if(strA	== "a")
	{
		playerA();
		
	}
	else if(strA == "b")
	{
		playerB();
	}

	
	

	

	
	//system("PAUSE");
	
	

}



