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

    template<typename T> void sort(T* Arr, const int size){
        for(int i = 0; i<size-1; i++){
            for(int j = 0; j<size-1; j++){
                if(Arr[j]<Arr[j+1]){
                    T temp = Arr[j];
                    Arr[j] = Arr[j+1];
                    Arr[j+1] = temp;
                }
            }
        }
    }


}



#endif //AUFGABENBLATT3_PERSON_H