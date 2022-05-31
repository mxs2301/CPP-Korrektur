#include "Wordsequence.h"
#include<iostream>
//hfu::Wordsequence::Wordsequence(std::string *words, int size){}      //6.1a
hfu::Wordsequence::Wordsequence(std::string *words, int size) : words(arrayCopy(words, size)), size(size) {}      //6.1a,c(arrayCopy(words, size))
hfu::Wordsequence::Wordsequence(): Wordsequence({},0){}   //6.1b
hfu::Wordsequence::Wordsequence(const Wordsequence& assignation): words(assignation.words), size(assignation.size) {}
int hfu::Wordsequence::getSize() const{                                   //6.1d
    return this-> size;
}
/*
std::string *hfu::Wordsequence::getWords() const {
    return words;
}*/
std::string hfu::Wordsequence::word(int position){//6.1e
    if(position>=size||position<0){
        throw std::invalid_argument("position wrong");
    }
    else{
        return words[position];
    }
}

hfu::Wordsequence::~Wordsequence() {
    delete[] this->words;
}

std::string *hfu::Wordsequence::arrayCopy(std::string original[], int size) {              //6.1c
    std::string *copy;
    copy = new std::string[size];
    for(int i=0; i<size; i++){
        copy[i] = original[i];
    }
    return copy;
}

void hfu::Wordsequence::word(int position,const std::string &word){                                                 //6.2a
    if (words == nullptr) {
        return;
    }
    if (position < 0 || position >= size) {
        return;
    }
    words[position] = word;
}

hfu::Wordsequence& hfu::Wordsequence::operator=(const hfu::Wordsequence &assignation) {
    if(this == &assignation)
        return *this;
    delete[] words;
    words = arrayCopy(words,size);
    return *this;
}

/*
std::ostream& hfu::operator<<(std::ostream& out, const Wordsequence& w) {
    for (int i = 0; i < copy.size; i++) {
        if (i == copy.size - 1) {
            out << copy.words[i] << std::endl;
        }
        else {
            out << copy.words[i] << ", ";
        }
    }
    return out;
}
 */
std::ostream& hfu::operator<<(std::ostream& out, hfu::Wordsequence& sequence) {
    for(int i = 0; i<sequence.getSize(); i++){
        out << sequence[i];                         //out (cout)
        if(i!=sequence.getSize()-1){                //Solange kleiner size ,
            out <<",";
        }
        else {
            out << " ";
        }
    }
    return out;
}

std::string& hfu::Wordsequence::operator[](int position) {             //veränderbar

    if(position< 0 || position >= size){
        throw new std::string("Operator wrong");
    }else{
        return words[position];
    }

}

std::string& hfu::Wordsequence::operator[](int position)const {     //const nicht veränderbar

    if(this->words == nullptr){
        throw std::invalid_argument("Error");
    }else {
        return this->words[position];
    }
}