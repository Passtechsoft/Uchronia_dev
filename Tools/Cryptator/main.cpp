#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <array>

using namespace std;

//Génère un pitit nbre aléatoire
#define RAND(min, max) ( (rand() % (max-min+1))+min )
//versions:

array<float, 200> versions
{
	1,
	3,
	4,
	7,
	13,
	23,
	42,
	666,
	1024
};
//3
//4
//7
//13
//23
//42
//666
//1024

string decaler(string fichier, string password, bool sup=true)
{
	string outString;
	unsigned int roller=0;
	for(unsigned int c=0; c != fichier.size(); c++)
	{
		if(sup)
			outString.push_back(fichier.at(c)+(password.at(roller)*password.at(roller)));
		else
			outString.push_back(fichier.at(c)-(password.at(roller)*password.at(roller)));

		if(roller == password.size())
			roller=0;
	}

	return outString;
}

int main()
{srand(time(0));
	cout << "Cryptator version "<<RAND(0, (int)versions[1])<< endl;

	string input;
	string motACoder;
	string message;
	cout << "password: ";
	getline(cin, input);

	while(motACoder != "exit")
	{
		cout<<"Voulez vous: 1:Coder 2:Décoder 3:Quitter?"<<endl;
		cin<<message;
		if(
		{
			cout << "Mot à coder: ";
			getline(cin, motACoder);
			string motCode=decaler(motACoder, input);
			for(int c=0; c != motCode.size(); c++)
				cout << (int)motCode.at(c) << ":";
			cout<<endl;
			cout << motCode << endl;
			cout << decaler(motCode, input, false) << endl;
		}
	}

	for(unsigned int c=0; c!=versions.size() && versions[c]!=0; c++)
		cout <<c<<": "<<versions[c];
    return 0;
}
