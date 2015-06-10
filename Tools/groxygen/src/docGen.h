#ifndef DOCGEN_H
#define DOCGEN_H

/// Stocke une page, la transforme, contient les paramètres inhérents à sa transformation.
class HtmlDoc
{
public:
  HtmlDoc();
  HtmlDoc(std::string toxyFile);
  bool ReadFile();
  
private:
  vector<string> OriginalText;
  vector<string> HtmlText;
};

#endif
