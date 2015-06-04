#define Expected_at_the_begin true

#define getInstruction(expectedParameter, usedLine) getStringUntil(usedLine, ";",  nbreisInThisString(actualLine, expectedParameter, Expected_At_The_Begin) );


#ifndef PARAM_INCLUDED
#define PARAM_INCLUDED

typedef Parameters map<std::string, std::string>;                     /// This "map" store the, first the index, a nickname for the second string


Parameters sortArguments(int argc, char *argv[]);

int isInThisString(const std::string &str, const std::string &searchedWord, bool atTheBegin = false);

///\todo à relire
/// Cette fonction va enregistrer le string \a str dans une nouvelle chaîne de caractères, jusqu'à rencontrer la suite de caractères donnés
string getStringUntil(const string &str, const string &stopWord, int originPos=0);

#endif
