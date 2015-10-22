#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
//#include <array>
#include <fstream>

using namespace std;

//Génère un pitit nbre aléatoire
#define RAND(min, max) ( (rand() % (max-min+1))+min )
//versions:

/*array<float, 200> versions
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
};*/
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
    cout << "Cryptator version "/*<<RAND(0, (int)versions[1])*/<< endl;

	string password;
	string fileName;
	string contenuFichier;
	bool coder;

	for(;;)
	{
		cout<<endl<<endl;
		cout << "Voulez vous:" << endl;
		cout << "	1) Coder" << endl;
		cout << "	2) Décoder" << endl;
		cout << "	3) Quitter (défaut)" << endl << "~: ";
		getline(cin, fileName);
		if(fileName == "2")
			coder=false;
		else if(fileName == "1")
			coder=true;
		else
			break;

		ifstream file;
		string nomOutFile;
		for(;;)
		{
			cout << "Entrez le nom de votre fichier d'entré: ";
			getline(cin, fileName);
			file.open(fileName.c_str());
			if(!file)
				cout << "Erreur, impossible d'ouvrir le fichier." << endl;
			else
				break;
		}

		string nomOut;
		if(coder)
			nomOut=".code";
		else if(!coder)
			nomOut=".decode";
		cout << "Entrez le nom de votre fichier de sortie (par défaut on rajoute " << nomOut << " à la fin): " << endl;
		getline(cin, nomOutFile);

		if("" == nomOutFile)
			nomOutFile = fileName+nomOut;

		for(;;)
		{
			cout << "Entrez le mot de passe fichier: ";
			getline(cin, password);
			system("clear");
			if(password.size() < 3){
				cout << "Votre mot de passe doit faire au moins 3 charactères (appuyez sur entré)" << endl;
				getline(cin, password);
			}
			else
				break;
		}

		string output;
		while(file)
		{
			contenuFichier += file.get();
		}
		for(char c=0; c != password[1]; ++c)
			contenuFichier = decaler(contenuFichier, password, coder);

		file.close();
		ofstream outFile(nomOutFile.c_str());
		outFile<<contenuFichier;

		cout << contenuFichier << endl << endl;
		cout << "	Fichier transformé avec succès en " << nomOutFile << endl;
	}

	cout << "Merci d'avoir utilisé ce petit utilitaire, veuillez l'utiliser (naturellement) à bon escient" << endl << endl << endl;

/*	for(unsigned int c=0; c!=versions.size() && versions[c]!=0; c++)
		cout <<c<<": "<<versions[c];*/
    return 0;
}
