#include <iostream>
#include <cstring>
#include <iomanip>
#include "VideoGames.h"

using namespace std;

//Functions
void VideoGames::print() {
  cout << "Game title: " << title << endl;
  cout << "Creation year: " << year << endl;
  cout << "Publisher Name: " << publisherName << endl;
  cout << "Game rating: " << std::fixed << setprecision (2) << rating << endl;
}
void VideoGames::addPublisherName(char* newpublisherName) {
  publisherName = new char[100];
  strcpy(publisherName, newpublisherName);
}

void VideoGames::addRating(float newrating) {
  rating = newrating;
}

VideoGames::~VideoGames() {} //destructor
