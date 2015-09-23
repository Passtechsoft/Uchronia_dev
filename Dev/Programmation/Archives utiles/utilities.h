#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

//Mettez cette ligne en commentaire si vous ne voulez pas voir affichés les messages de debug
#define DEBUGMOD


#include <unistd.h>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <sys/time.h>

#include <iostream>
#include <string>
#include <fstream>
#include <ostream>

#include <array>
#include <vector>
#include <map>
#include <queue>
#include <list>


#define PR_WHITE 30 //#seriouslybro
#define PR_RED 31
#define PR_GREEN 32
#define PR_YELLOW 33
#define PR_BLUE 34
#define PR_PURPLE 35
#define PR_LIGHTBLUE 36
#define PR_GREY 37

#define COLORED_PRINT(param1, param) std::cout<<"\033["<<param<<"m"<<param1<<"\033[30m"<<std::endl

#define PIMP(txt) COLORED_PRINT("/!\\PIMP SPOTTED/!\\: "<<txt, PR_LIGHTBLUE)
#define DEBUG(txt) COLORED_PRINT("DEBUG: "<<txt, PR_BLUE)
#define INFO(txt) COLORED_PRINT("INFO: "<<txt, PR_GREY)
#define WARNING(txt) COLORED_PRINT("WARNING: "<<txt, PR_YELLOW)
#define ERROR(txt) COLORED_PRINT("ERROR: "<<txt, PR_RED)
#define CRITIC_ERROR(txt) COLORED_PRINT("/!\\CRITIC ERROR/!\\: "<<txt, PR_PURPLE);std::cout<<1/0<<std::endl

#ifdef DEBUGMOD
#define affInDebug(message, entree) entree(message)
#else
#define affDebug(message, entree) ;
#endif // DEBUGMOD

//Génère un pitit nbre aléatoire
#define RAND(min, max) ( (rand() % (max-min+1))+min )

//Une simple fonction ²
#define CARRE(var) (var*var)

//Retourne true si le chiffre est entier
#define ISINTEGRER(result) (result==(int)result)

#define ISPOSITIVE(number) (number>=0)

///Cette fonction ne garde qu'un certain nombre de chiffres de la partie entière
#define cutDiz(nombre_, nbIntegrers_) (nombre_/(10*(long)((nombre_/10)*pow(10, nbIntegrers_)))

#define DIVISIBLE_PAR(nbre, diviseur) (nbre/((float)diviseur)==(short)nbre/diviseur)
//Utile dans les cas de tests ou on aimerait obtenir un int tel que jamais un utilisateur n'oserais le taper
#define INT_IMPROBABLE 4294967295


typedef std::map<std::string, std::map<void*, int> > CompteurClasseType;
typedef unsigned char oct_e;//Rest In Pieces :_{
typedef unsigned char uchar;
typedef unsigned short ushort;

std::map<void *, int> *getCptClass(std::string &nom);

#define ptrFlagInc(nomclasse, ptrClasse) compteurClasses[nomclasse].at(ptrClasse) += 1
#define ptrFlagDec(nomclasse, ptrClasse) compteurClasses[nomclasse].at(ptrClasse) -= 1
void affPtrFlag();


///Permet de tester une certaine probabilité
bool probability(int prob, int sur);
///Renvoie le nombre en positif
float positif(int a);
///Donne le mot n°\a word_num dans la chaine chaine, à noter que word_num commence par 0;
std::string getWord(ushort word_num, std::string &chaine);
///\return true si \a subWord est dans \a word
bool isInWord(std::string word, std::string subWord);

///Lis dans le fichier donné une liste de mots suivant ces conditions: si le premier mot de la chaîne \n
///se termine par ":", on l'ignore (il est alors considéré comme une sorte de commentaire) et si le mot \n
///est ";", on s'arrête de rajouter des mots dans le vector. Enfin, on ne retourne qu'une nombre de mots égale\n
///à \a nbreMotsAttendus.
std::vector<std::string> getFileWithSthx(std::ifstream &flux, unsigned int nbreMotsAttendus=INT_IMPROBABLE);

///Uchronia noise namespace
namespace Unoise
{
    typedef std::array<unsigned short, 256> PermTable;
    typedef std::vector<std::vector<float>> ChunkPoints;

    ///Stock a PermTable "Diamond"
    struct DiamondPermTable
    {
        PermTable permTable;
        PermTable permPermTable;
    };

    ///Pas obligatoire, cette fonction permet de changer lambdaPermTable
    void setPermTable(PermTable* perm);

    void setSeed(int);

    ///On génère la table de permutation à partir d'un seed
    void genPermTable(PermTable*, int);

    ///Fonction du bruit de perlin (float x, float z, float resolution, table de permutation):
    float perlinNoise(float x, float z, float res, PermTable* perm=nullptr);

    ///Midpoint displacement noise, ou Diamond square noise (nom latin: carrus diamus)
    ChunkPoints diamondSquareNoise(float x, float y, int amplitude, float res, unsigned short subDivisions, int nseed=-1, std::array<float, 4>* pointsPrincipaux=nullptr, std::array<std::vector<float>, 4>* pointsEnvironnants=nullptr);
}

#endif // UTILITIES_H_INCLUDED


