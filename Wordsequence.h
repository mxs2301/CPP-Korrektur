#ifndef AUFGABENBLATT6_WORDSEQUENCE_H
#define AUFGABENBLATT6_WORDSEQUENCE_H

#include <iostream>
#include "Person.h"

namespace hfu {
    template<typename T>
    class Wordsequence {
    private:
        int size;
        T *words;
    public:
        //std::string *getWords() const;



        Wordsequence(T *words, int size):
        words(arrayCopy(words, size)),
        size(size)
        {}

        Wordsequence():
        words(nullptr),
        size(0)
        {}

        Wordsequence(const Wordsequence &assignation):
        words(assignation.words),
        size(assignation.size)
        {}

        int getSize() const{
            return size;
        }//6.1d

        T word(int position){
            if(position>=size || position<0){
                throw std::invalid_argument("Position wrong");
            }else{
                return words[position];
            }
        }

        T* arrayCopy(T original[], int size){
            T* copy;
            copy = new T[size];
            for(int i = 0; i<size; i++){
                copy[i] = original[i];
            }
            return copy;
        }

        void word(int position, const T &word){
            if(words == nullptr){
                return;
            }
            if(position < 0 || position >= size){
                return;
            }

            words[position] = word;
        }          //6.2a


        friend std::ostream &operator<<(std::ostream &out, Wordsequence &sequence){
            for(int i = 0; i<sequence.getSize(); i++){
                out << sequence[i];
                if(i!=sequence.getSize()-1){
                    out<<",";
                }
                else{
                    out << " ";
                }
                return out;
            }
        } //6.2b
        T &operator[](int position){
            if(position<0 || position >= size){
                throw new std::string("Operator Wrong");
            }else{
                return words[position];
            }
        }                                   //6.3
        T &operator[](int position) const{

            if(words == nullptr){
                throw std::invalid_argument("Error");
            }else{
                return words[position];
            }
        }

        Wordsequence& operator=(const Wordsequence &assignation){
            if(this == &assignation){
                return *this;
            }
            delete[] words;
            size = assignation.size;
            words = arrayCopy(assignation.words, assignation.size);
            return *this;
        }

        ~Wordsequence(){
            if(words != nullptr)
                delete[] words;
        }
    };
    typedef Wordsequence<Person> SimpleVector;
}

#endif