#ifndef VIDEOGAMEHEADER
#define VIDEOGAMEHEADER
#include <iostream>
#include "Media.h"
using namespace std;

//Header for VideoGames
class VideoGames : public Media {
public:
  virtual void print();
  virtual void addRating(float);
  ~VideoGames();
private:
  char * publisherName;
  float rating;
};
#endif
