#include <iostream>
#include <cstring>
#include <iomanip>
#include "Movies.h"
using namespace std;

//Movie Functions
void Movies::print() {
  cout << "Movie Title: " << title << endl;
  cout << "Creation Year: " << year << endl;
  cout << "Movie Creation: " << directorName << endl;
  cout << "Movie Length: " << duration << " minutes" << endl;
  cout << "Movie Rating: " << std::fixed << setprecision(2) << rating << endl;
}

void Movies::addDirectorName(char* newdirectorName) {
  directorName = new char[100];
  strcpy(directorName, newdirectorName);
}
void Movies::addDuration(int newduration) {
  duration = newduration;
}
void Movies::addRating(float newrating) {
  rating = newrating; 
}

Movies::~Movies() {
    
} //destructor
