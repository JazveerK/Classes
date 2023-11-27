/*
Jazveer Kaler
10/30/2023
Creates a database where you're able to add, search, or delete types of media
Thanks to Tejas, Levi, and Akash for help
 */

#include <iostream>
#include <typeinfo>
#include <vector>
#include "Media.h"
#include <limits>
#include "Videogames.h"
#include "Music.h"
#include "Movies.h"
#include <cstring>

using namespace std;

//Function Prototypes
void searchMedia(vector<Media*> &);
void addMedia(vector<Media*> &);
void deleteMedia(vector<Media*> &);

int main() {
    char input[10];
    char commandInput[10];
    bool running = true;
    vector<Media*> v;
    
    //User input
    while (running == true) {
        cout << "Enter a command for what you want to do." << endl;
        cout << "Enter ADD to add a type of media. Enter SEARCH to search for existing media. Enter DELETE to delete existing media. Enter QUIT to quit the program" << endl;
        cin >> commandInput;
        if (strcmp(commandInput, "ADD") == 0)
            addMedia(v);
        else if (strcmp(commandInput, "SEARCH") == 0)
            searchMedia(v);
        else if (strcmp(commandInput, "DELETE") == 0)
            deleteMedia(v);
        else if (strcmp(commandInput, "QUIT") == 0)
            running = false;
        else
            cout << "Please enter a valid input" << endl;
    }
}

// Search funtion for the database
void searchMedia(vector<Media*> &newv) {
    char command[10];
    char title[10];
    int year;
    
    cout << "Enter TITLE to search by title and YEAR to search by year" << endl;
    cin >> command;
    
    //searching by title
    if (strcmp(command, "TITLE") == 0) {
        cout << "Enter the title of the media that you are searching for" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clears out buffer
        cin.get(title, 11);
        
        //iterates through looking for media with the same title
        for (vector<Media*>::iterator it = newv.begin(); it < newv.end(); ++it) {
            if (strcmp((*it)->getTitle(), title) == 0) {
                (*it)->print();
            }
        }
    }
    
    //Searching by year
    if (strcmp(command, "YEAR") == 0) {
        cout << "Enter the year of the media that you are searching for" << endl;
        cin >> year;
        cin.clear();
        
        //iterates through looking for media with the same title
        for (vector<Media*>::iterator it = newv.begin(); it != newv.end(); ++it) {
            if ((*it)->getYear() == year) {
                (*it)->print();
            }
        }
    }
}

// Delete funtion for the database
// Tejas helped me on this
void deleteMedia(vector<Media*> &newv) {
    char command[100];
    char title[100];
    char confirm[100];
    int year;
    Media* temp;
    
    cout << "Enter TITLE if you wish to find media to delete by title and YEAR if you wish to so by year" << endl;
    cin >> command;
    
    if (strcmp(command, "TITLE") == 0) {
        cout << "Enter the title of the media that you want to delete: " << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get(title, 100);
        
        for (int i = 0; i < newv.size(); i++) {
            if (strcmp(newv[i]->getTitle(), title) == 0) {
                newv[i]->print();
                cout << "Are you sure you want to delete this media? Enter 'Y' to continue.";
                cin >> confirm;
                if (strcmp(confirm, "Y") == 0) {
                    delete newv[i];
                    newv.erase(newv.begin() + i);
                }
                else {
                    cout << "Media was not deleted" << endl;
                }
            }
        }
    }
    
    if (strcmp(command, "YEAR") == 0) {
        cout << "Enter the year of the media that you want to delete: " << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> year;
        
        for (int i = 0; i < newv.size(); i++) {
            if (newv[i]->getYear() == year) {
                newv[i]->print();
                cout << "Are you sure you want to delete this media? Enter 'Y' to continue.";
                cin >> confirm;
                if (strcmp(confirm, "Y") == 0) {
                    delete newv[i];
                    newv.erase(newv.begin() + i);
                }
                else {
                    cout << "Media was not deleted" << endl;
                }
            }
        }
    }
}

// Add funtion for the database
void addMedia(vector<Media*> &newv) {
    char title[100];
    int publishYear;
    char mediaType[100];
    char creator[100];
    int length;
    float rating;
    
    cout << "Please enter the type of media that you are adding to the database. Enter VG for a video game, MC for music, and MV for a movie" << endl;
    cin >> mediaType;
    
    // Adds music to database
    if (strcmp(mediaType, "MC") == 0) {
        Music* newmusic = new Music();
        
        cout << "Enter the title of the music: " << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get(title, 100);
        newmusic->Title(title);
        
        cout << "Enter the creation year of the music: " << endl;
        cin >> publishYear;
        newmusic->Year(publishYear);
        
        cout << "Enter the artist name: " << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get(creator, 100);
        newmusic->addArtistName(creator);
        
        cout << "Enter the length of the music in minutes: " << endl;
        cin >> length;
        newmusic->addDuration(length);
        newv.push_back(newmusic);
    }
    
    //Adds viedo games to the database
    if (strcmp(mediaType, "VG") == 0) {
        VideoGames* newvg = new VideoGames();
        
        cout << "Enter the title of the game: " << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get(title, 100);
        newvg->Title(title);
        
        cout << "Enter the creation year of the game: " << endl;
        cin >> publishYear;
        newvg->Year(publishYear);
        
        cout << "Enter the publisher of the game: " << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get(creator, 100);
        newvg->addPublisherName(creator);
        
        cout << "Enter the rating of the game out of 10: " << endl;
        cin >> rating;
        cin.clear();
        newvg->addRating(rating);
        newv.push_back(newvg);
    }
    
    // Adds movie to the database
    if (strcmp(mediaType, "MV") == 0) {
        Movies* newmovie = new Movies();
        
        cout << "Enter the title of the movie: " << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get(title, 100);
        newmovie->Title(title);
        
        cout << "Enter the year that the movie was created in: " << endl;
        cin >> publishYear;
        newmovie->Year(publishYear);
        
        cout << "Enter the director of the movie: " << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get(creator, 100);
        newmovie->addDirectorName(creator);
        
        cout << "Enter the length of the movie in minutes: " << endl;
        cin >> length;
        newmovie->addDuration(length);
        
        cout << "Enter the rating of the movie out of 10: " << endl;
        cin >> rating;
        cin.clear();
        newmovie->addRating(rating);
        newv.push_back(newmovie);
    }
}
