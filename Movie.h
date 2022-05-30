#ifndef AUFGABENBLATT3_MOVIE_H
#define AUFGABENBLATT3_MOVIE_H

#include<iostream>
#include "Person.h"
namespace hfu {
    class Movie {
    private:
        std::string title;
        hfu::Person director;
        int filmLength;
        int*scores;
        int scoreCount;
        static int* arrayCopy(const int array[], int scoreCount);
    public:
        std::string getTitle() const;
        std::string getDirectorFirstname();
        std::string getDirectorLastname();
        //std::string getDirectorFirstname();
        // std::string getDirectorLastname();
        int getFilmLength()const;
        Movie(std::string title, int filmLength, hfu::Person director);  //Konstruktor
        Movie(std::string title, int filmLength, hfu::Person director, int scores[], int scoreCount);
        int getScore(int i);
        int getScoreCount();



    };
}

#endif //AUFGABENBLATT3_MOVIE_