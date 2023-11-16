#include <iostream>
#include <cstring>
#include "Media.h"
#include "Music.h"
#include "VideoGames.h"
#include "Movies.h"
using namespace std;

//Functions for Media

void Media::print() {
  cout << year << endl;
  cout << title <<endl;
}

void Media::Title(char* newtitle){
  title = new char[100];
  strcpy(title, newtitle);
}

void Media::Year(int newyear){
  year = newyear;
}

char* Media::getTitle(){
  return title;
}

int Media::getYear(){
  return year;
}

Media::~Media() {
    
} //destructor

