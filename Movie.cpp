#include "Movie.h"
hfu::Movie::Movie(std::string title, int filmLength, hfu::Person director) : Movie(title,filmLength,director, {},0) {}
hfu::Movie::Movie(std::string title, int filmLength, hfu::Person director, int *scores, int scoreCount ) : title(title), filmLength(filmLength), director(director), scores(
        arrayCopy(scores, scoreCount)),scoreCount(scoreCount){}

std::string hfu::Movie::getTitle() const {
    return this->title;
}
std::string hfu::Movie::getDirectorFirstname(){
    return this->director.getFirstname();
}

std::string hfu::Movie::getDirectorLastname(){
    return this->director.getLastname();
}

int hfu::Movie::getFilmLength() const{
    return filmLength;
}

//Score

int hfu::Movie::getScoreCount(){
    return scoreCount;
}

int hfu::Movie::getScore(int i){
    return scores[i];
}

int* hfu::Movie::arrayCopy(const int* array, int scoreCount) {
    int* resultCopy = new int[scoreCount];
    for(int i = 0; i < scoreCount; i++){
        resultCopy[i] = array[i];
    }
    return resultCopy;
}