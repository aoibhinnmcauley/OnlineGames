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
char * ipAddressB = "149.153.102.62";
char* msg = "Lets Play";
int waiting = 0; 
Net n;
bool initialise = false;
 char message[200]="";
string strA = "";
string strB = "";
string answer = "";
char guess[200] = ""; 
char guess2[200] = ""; 
char ans1[200] = ""; 
char ans2[200] = ""; 
char reset[200]= "";
bool wrong = true; 


void playerA(){
	playA = true;
	cout << playA << endl;
	n.setupUDP(portA,ipAddressA);
	n.sendData(ipAddressB, portB, msg);
    cout << "Put in a name for your friend to guess!" <<endl;
    cin >> ans1; 
	while(true){
			n.receiveData(message);
 
		if(	 message[0] != '\0')
		{
			//cout << message << endl;
			n.sendData(ipAddressB, portB, ans1);
			n.receiveData(guess2);
			cout <<"Your Friend Guessed " <<guess2 << endl;
		if(	 guess[0] != '/0' && wrong == true)
		{
			//cout << "Guess!" << endl;
			cin >> guess;
			n.sendData(ipAddressB, portB, guess);

			if(guess == ans2)
			{
				wrong = false; 
				cout << "You win!" << endl; 
			}
			else 
		     
			 cout << "Guess again" << endl; 
			 
		}			

			//system("Pause");
		}			
	}
	
}

void playerB(){
		
	playB = true;
	cout << playB << endl;
	n.setupUDP(portB,ipAddressB);
	n.sendData(ipAddressA, portA, msg);
  
			cout << "Put in a name for your friend to guess!" <<endl;
			cin >> ans2;
	while(true){
			
			n.receiveData(guess);
			cout <<"Your Friend Guessed " <<guess << endl;
		if(	 guess[0] != '/0' && wrong == true)
		{
			//cout << "Guess?" <<endl;	
			cin >> guess2;
			n.sendData(ipAddressA, portA, guess2);

			if(guess2 == ans1)
			{
				wrong = false; 
				cout << "You win!" << endl; 
			}
			else 
		     
			 cout << "Guess again" << endl; 
			 
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



