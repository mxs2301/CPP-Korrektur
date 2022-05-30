#ifndef AUFGABENBLATT3_PERSON_H
#define AUFGABENBLATT3_PERSON_H
#include <iostream>

namespace hfu {
    class Person {
    private:
        //1a

        std::string firstname;
        std::string lastname;
    public:
        std::string getFirstname() const;
        std::string getLastname() const;
        //Aufgabe 3
        int compare(const Person& other);
        bool operator ==(const Person& other);
        bool operator<(const Person& other);
        bool operator >(const Person& other);

        Person(std::string firstname, std::string lastname);  //AB4A1
        Person();                                             //Somit geht Person newValue;

        static void sort(Person *p, int size);
    };
}

#endif //AUFGABENBLATT3_PERSON_H