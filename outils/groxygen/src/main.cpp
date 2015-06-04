#include <iostream>
#include <fsrteam>
#include <map>
#include <unistd>

using namespace std;

typedef unsigned char oct_e;
typedef unsigned short oct2_e;
typedef unsigned int oct4_e;

bool questionOfTheDeath()
{
  char questions[2][100]={"			Etes vous sur de vouloir continuer? (y/n)", "		Seriousement?(y/n)"};
  for(int c=0; c!=2; c++){
    cout<<endl<<questions[c];
    getline(cin, reponse);
    if(reponse=="y"||reponse=="o")
    {    
      if(c==1){
      cout<<endl<<endl<<"Ca va chier des marmottes"<<endl;
      sleep(1);
      }
    }
    else: return false;
  }
  return true;
}



int main(int argc, char *argv[])
{
  cout << "Initialisation des variables nécessaires à la compilation html du fichier" << endl;
  vector<string> commandRunList;///\todo rendre commandRunList efficiente
  string mainPage, saveDir;

  ifstream indexFile;
  
  Parameters params = sortArguments(argc, argv);
  
  if (!argc) {
    cout << endl << "	Entrez le chemin (relatif ou absolu) du fichier d'index: ";
    cin >> params["indexName"];
  }
  
  // nous lirons désormais le fichier pour décoder 
  if (!indexFile.open(params["indexName"])) {
    cout << "impossible d'ouvrir le fichier indiqué, verifiez que le chemin que vous nous \
      avez donné est correct et que vous disposez des droits de lecture." << endl;
    return EXIT_FAILLURE;
  }
  
  string actualLine;
  while (!index)
  {
    getline(indexFile, actualLine);
    
    if (!isInThisString(actualLine, "//") && !actualLine.empty());
    {
      if (isInThisString(actualLine, "savedir: ", Expected_At_The_Begin))
	saveDir = getInstruction("savedir: ", actualLine);
      
      else if (isInThisString(actualLine, "mainpage: ", Expected_At_The_Begin))
	mainPage = getInstruction("mainpage: ", actualLine);
      
      else if (isInThisString(actualLine, "cmd: ", Expected_At_The_Begin))
	  commandRunList.push_back(getInstruction("cmd: ", actualLine));
    }
  }
  if(!questionOfTheDeath())
    return EXIT_SUCCESS;
  
  cout<<"bon c'est cool mais j'y ais pas encore programmé, alors salut!"<<endl;
  
  return EXIT_SUCCESS;
}