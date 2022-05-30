#include "Person.h"
//#include <iostream>

//Konstruktor
hfu::Person::Person(std::string firstname, std::string lastname):firstname(firstname), lastname(lastname){}//1a


hfu::Person::Person(){}


//getter
std::string hfu::Person::getLastname() const {
    return this->lastname;
}

std::string hfu::Person::getFirstname() const {
    return this->firstname;
}

//Aufgabe 3

bool hfu::Person::operator<(const Person &other) {
    if (this->compare(other) > 0) {
        return true;                                    //true other Person ist kleiner
    } else {
        return false;
    }
}

bool hfu::Person::operator>(const Person &other) {
    if (this->compare(other) < 0) {                     //Typo
        return true;                                    //true other Person ist größer
    } else {
        return false;
    }
}

bool hfu::Person::operator==(const Person &other) {
    if (this->compare(other) == 0) {                        //other Person und Person sind gleich
        return true;
    } else {
        return false;
    }
}


int hfu::Person::compare(const Person &other) {

    int compareLastname=this->firstname.compare(other.firstname);
    if (compareLastname == 0) {
        return this->firstname.compare(other.firstname);
    }
    return compareLastname;
}

//2
void hfu::Person::sort(Person *p, int size)                  //4.2
{
    Person newValue("Daisy", "Duck");
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (p[j].compare(p[i])<0)                          //ohne Pointer kein ZUgriff auf Index
            {
                newValue = p[j];                             // Zwischenspeicher
                p[j] = p[i];
                p[i] = newValue;
            }
        }
    }
}

/*
hfu::Person& hfu::Person::operator=(const hfu::Person &assignation) {    //7.1b
    if(this == &assignation)
        return *this;
    delete firstname;
    firstname = new std::string;
    return *this;
} */

