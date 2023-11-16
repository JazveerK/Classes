#ifndef MEDIAHEADER
#define MEDIAHEADER
#include <iostream>
#include <cstring>
using namespace std;

//Header for Media
class Media {
  public:  
  virtual void Title(char*);
  virtual void Year(int);
  virtual void print();
  virtual char* getTitle();
  virtual int getYear();
  virtual ~Media();
  protected:
  char* title;
  int year;
};
#endif
  
