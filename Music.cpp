#include <iostream>
#include <cstring>
#include "Music.h"
using namespace std;

//Header for music 
void Music::addArtistName(char* newartistName) {
  artistName = new char[100];
  strcpy(artistName, newartistName);
}
void Music::addDuration(int newduration) {
  duration = newduration;
}
void Music::print(){
  cout << "Title: " << title << endl;
  cout << "Creation year: " << year << endl;
  cout << "Artist Name: " << artistName << endl;
  cout << "Length: " << duration << endl;
}

Music::~Music() {
    
} //destructor
