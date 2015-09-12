#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//G�n�re un pitit nbre al�atoire
#define RAND(min, max) ( (rand() % (max-min+1))+min )
///Pour compiler: gcc -o nom main.cpp
/**
	Ce programme sert � r�soudre un probl�me de taille dans toutes les grandes productions:
		L'ordre de placementdes noms. L� ou probl�mes d'ego et fausse modesties se font l�gions,
		mon programme propose de mettre enfin de l'ordre dans cela en g�n�rant tout seul une vertion randomis�e
		de votre fichier d'input! (pour l'instant il n'est pas tr�s �volu� je compatit mais des supers options de
		configurations ne tarderons pas!!!)
*/
int main(int argc, char *argv[])
{
	ifstream fichierIn;
	ofstream fichierOut;
	string inputFile, outputFile;
	int datDate;
    cout << "Bienvenue dans le g�n�rateur de listes de noms" << endl;

    if(argc==1)
    {
    	cout<<"Excusez moi: au fait, on est le combien d�j�?"<<endl;
    	cin>>datDate;
    	cout<<"Donnez nous le nom du fichier d'input, puis de celui d'output:"<<endl;
    	cin>>inputFile;
    	cin>>outputFile;
    }
    fichierIn.open(inputFile.c_str());
    fichierOut.open(outputFile.c_str());
    if(!fichierOut||!fichierIn)
			cout<<"Probl�me avec les fichiers que vous nous avez donn�s..."<<endl;
    int seed=datDate*time(0);
    srand(seed);
	cout<<endl<<"		C'est le seed "<<seed<<" qui sera utilis� pour traiter cette liste"<<endl<<endl;

	vector<string> strFichierInput;
	for(int c=0; fichierIn; c++)
	{
		strFichierInput.push_back("");
		getline(fichierIn, strFichierInput[c]);
		cout<<strFichierInput[c]<<endl;
	}
	cout<<"Empaquetage dans le fichier des lignes choisies"<<endl;
	vector<int> numerosGagnants;
	bool nouveau=true;
	for(unsigned int c=0; c!=strFichierInput.size(); c++)
	{
		int nbrerandom=RAND(0, strFichierInput.size()-1);
		for(unsigned int y=0; y!=numerosGagnants.size(); y++){
			if(numerosGagnants[y]==nbrerandom){
				nouveau=false;
				c--;
				break;
			}
		}
		if(nouveau)
		{
			numerosGagnants.push_back(nbrerandom);
			cout<<strFichierInput[nbrerandom]<<endl;
			fichierOut<<strFichierInput[nbrerandom]<<endl;
		}
		nouveau=true;
	}

    return EXIT_SUCCESS;
}
