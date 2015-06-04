#include "parameters.h"

using namespace std;

/// This function make a parameter storage container, it guess the usage of argv parameters.
Parameters sortArguments(int argc, char *argv[])
{
  Parameters param;
  for(int c=0; c!=argc; c++)
  {
    if(argc==1)
      param["indexFile"].c_str()=argv[c];
  }
  return param;
}

/// \return 0 if the word \a searchedWord isn't in the \a str string, and else the charactere number just after the fund word.
int isInThisString(const string &str, const string &searchedWord, bool atTheBegin = false)
{
  oct2_e match = 0;
  for (int c = 0; c != chaint.size(); ++c)
  {
    if (chaine[c] = searchedWord)
    {
      match++;
      if (match == searchedWord.size())
	return c+1;
    }
    if (atTheBegin == true && c == searchedWord.size())
      return false;
  }
  return false;
}
///\todo à relire
/// Cette fonction va enregistrer le string \a str dans une nouvelle chaîne de caractères, jusqu'à rencontrer la suite de caractères donnés
string getStringUntil(const string &str, const string &stopWord, int originPos=0)
{
  string newstr;
  int stopWordCnt=0;
  for(int c=originPos; c!=str.size(); ++c)
  {
    newstr.push_back(str[c]);
    if(str[c]==stopWord[]
    {
      stopWordCnt++;
      if(stopWordCnt==stopWord.size())
      {
	for(int d=0; d!=stopWord.size(); ++d)
	   newstr.pop_back();
	return newstr;
      }
    }
    else
      stopWordCnt=0;
  }
  return newstr;
}
