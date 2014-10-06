#include <winsock2.h> 
#include "net.h"

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
bool win = true; 
bool yourTurnA = true;
bool yourTurnB = false;
int countGoes = 0;
string str1 = "";
string str2 = "";


void playerA(){
	playA = true;
	cout << playA << endl;
	n.setupUDP(portA,ipAddressA);
	cout << "Greetings fellow chum," << endl << " did you see those petty commoners playing rock, paper scissors!!" << endl;
	cout << " huehuehue lol LOL! Today were about to embark on the glorious adventure of" << endl << "QUARTZ!, PARCHMENT! and SHEERS!" << endl;
  
	while(true)
	{
		while(!yourTurnA){

				if(n.receiveData(ans2))
				{
					
					str1 = ans1;
					str2 = ans2;
					if((str1 == "SHEERS" && str2 == "PARCHMENT") || 
						(str1 == "PARCHMENT" && str2 == "QUARTZ") ||
						(str1 == "QUARTZ" && str2 == "SHEERS"))
					{
						//win = true; 
						cout << "You win!" << endl; 
						yourTurnA = true;
					}
					else if((str1 == "SHEERS" && str2 == "SHEERS") || 
						(str1 == "PARCHMENT" && str2 == "PARCHMENT") ||
						(str1 == "QUARTZ" && str2 == "QUARTZ"))
					{
						cout << "Draw!" << endl; 
						yourTurnA = true;
					}
					else if((str2 == "SHEERS" && str1 == "PARCHMENT") || 
						(str2 == "PARCHMENT" && str1 == "QUARTZ") ||
						(str2 == "QUARTZ" && str1 == "SHEERS"))
					{
						cout << "You lose! Huehuehue" << endl; 
						yourTurnA = true;
					}
					else
					{
							yourTurnA = true;
					}
				
				}
		}

		while(yourTurnA){
					
			//if( win == false)
			//{
				//cout << "Guess!" << endl;
				cout << "Please input one of the following: QUARTZ, PARCHMENT or SHEERS" <<endl;
				cin >> ans1;

				cout << " you have choosen: " << ans1 << endl; 

			//	if (ans1 != "QUARTZ" || ans1 != "PARCHMENT" || ans1 != "SHEERS" )
			//	{	
			//			 cout << "Please input one of the following: QUARTZ, PARCHMENT or SHEERS" <<endl;
				//		 cin >> ans1;
				//		 cout << " you have choosen: " << ans1 << endl; 
			//			
				//}
				 
				n.sendData(ipAddressB, portB, ans1);

				yourTurnA = false;


			
				
			//}			
		}
	}
		
	





	
}

void playerB(){
		
	playB = true;
	cout << playB << endl;
	n.setupUDP(portB,ipAddressB);
	cout << "Greetings fellow chum," << endl << " did you see those petty commoners playing rock, paper scissors!!" << endl;
	cout << " huehuehue lol LOL! Today were about to embark on the glorious adventure of" << endl << "QUARTZ!, PARCHMENT! and SHEERS!" << endl;
  
	while(true)
	{
		while(!yourTurnB){

				if(n.receiveData(ans1))
				{
					str1 = ans1;
					str2 = ans2;
					if((str2 == "SHEERS" && str1 == "PARCHMENT") || 
						(str2 == "PARCHMENT" && str1 == "QUARTZ") ||
						(str2 == "QUARTZ" && str1 == "SHEERS"))
					{
						//win = true; 
						cout << "You win!" << endl; 
						yourTurnB = true;
					}
					else if((str1 == "SHEERS" && str2 == "SHEERS") || 
						(str1 == "PARCHMENT" && str2 == "PARCHMENT") ||
						(str1 == "QUARTZ" && str2 == "QUARTZ"))
					{
						cout << "Draw!" << endl; 
						yourTurnB = true;
					}
					else if((str1 == "SHEERS" && str2 == "PARCHMENT") || 
						(str1 == "PARCHMENT" && str2 == "QUARTZ") ||
						(str1 == "QUARTZ" && str2 == "SHEERS"))
					{
						cout << "You lose! Huehuehue" << endl; 
						yourTurnB = true;

					}
					else
					{
						yourTurnB = true;

					}
					
				}
		}

		while(yourTurnB){
					
			//if(	 ans2[0] != '/0' && win == false)
			//{
				//cout << "Guess!" << endl;
				cout << "Please input one of the following: QUARTZ, PARCHMENT or SHEERS" <<endl;
				cin >> ans2;

				cout << " you have choosen: " << ans2; 

				//if(ans2 != "QUARTZ"|| ans2 != "PARCHMENT"|| ans2 != "SHEERS" )
				//{	
					//	 cout << "Please input one of the following: QUARTZ, PARCHMENT or SHEERS" <<endl;
				//		 cin >> ans2;
				//		 cout << " you have choosen: " << ans2 << endl; 
						
			//	}

				n.sendData(ipAddressA, portA, ans2);

			
	
					
						yourTurnB = false;
		
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



