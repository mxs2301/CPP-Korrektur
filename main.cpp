#include <iostream>
#include "Person.h"
#include "Movie.h"
#include <cassert>


void test_person() {          //1c
//    //hfu::Person person;
//    std::string donald = "Donald";
//   // person.setFirstname(donald);
//    assert(person.getFirstname() == "Donald");
//    donald[0] = 'X';
//    assert(person.getFirstname() == "Donald");
//    std::string duck = "Duck";
//    person.setLastname(duck);
//    assert(person.getLastname() == "Duck");
//    duck[0] = 'X';
//    assert(person.getLastname() == "Duck");
    std::string donald="Donald";
    std::string duck="Duck";
    hfu::Person person(donald, duck);           //Konstruktoraufruf
    assert(person.getFirstname() == "Donald");
    donald[0] = 'X';
    assert(person.getFirstname() == "Donald");
    assert(person.getLastname() == "Duck");
    duck[0] = 'X';
    assert(person.getLastname() == "Duck");
}

void test_movie(){
//    hfu::Movie movie;
//    std::string hdg = "Hdg";
//    movie.setTitle(hdg);
//    assert(movie.getTitle() == "Hdg");
//    hdg[0] = 'X';
//    assert(movie.getTitle() == "Hdg");
//    std::string duck = "Duck";
//    movie.setDirector(duck);
//    assert(movie.getDirector() == "Duck");
//    duck[0] = 'X';
//    assert(movie.getDirector() == "Duck");
    int filmLength=90;
    std::string hdg = "Hdg";
    std::string lastDuck = "Duck";                 //Directorname
    std::string FirstDonald="Donald";
    hfu::Person director(FirstDonald,lastDuck);
    hfu::Movie movie(hdg,filmLength,director);
    assert(movie.getTitle() == "Hdg");
    hdg[0] = 'X';
    assert(movie.getTitle() == "Hdg");
    assert(movie.getDirectorLastname() == "Duck");
    lastDuck[0] = 'X';
    assert(movie.getDirectorLastname() == "Duck");
}

void test_compare(){
    hfu::Person personDaisy("Daisy","Duck");
    hfu::Person personDonald("Donald","Duck");

    assert(personDaisy.compare(personDonald)<0);
    assert(personDonald.compare(personDaisy)>0);
    assert(personDaisy.compare(personDaisy)==0);
}

void test_sort(){
    const int size =15;
    hfu::Person people[size] = {
            hfu::Person("Donald","Duck"),
            hfu::Person("Daisy", "Duck"),
            hfu::Person("Jana","Herder"),
            hfu::Person("Johnny","Depp"),
            hfu::Person("Luna", "Laber"),
            hfu::Person("Max","Mix"),
            hfu::Person("Nils", "Koenig"),
            hfu::Person("Giulia", "Seife"),
            hfu::Person("Katja","Leber"),
            hfu::Person("Nico","Nacht"),
            hfu::Person("Gretel", "Berger"),
            hfu::Person("Gerta","Berg"),
            hfu::Person("Johannes","Hecht"),
            hfu::Person("Mona","Lisa"),
            hfu::Person("Till","Mann")};
    hfu::Person::sort(people, size);
    assert(people[0].getFirstname() == hfu::Person("Daisy", "Duck").getFirstname());
    assert(people[1].getFirstname() == hfu::Person("Donald", "Duck").getFirstname());
    assert(people[2].getFirstname() == hfu::Person("Gerta", "Berg").getFirstname());
    assert(people[3].getFirstname() == hfu::Person("Giulia", "Seife").getFirstname());
}
void test_scores() {
    hfu::Person director("Donald", "Duck");
    int scores[]={4,7,1,1};
    hfu::Movie scored_movie("Modern Times", 90, director, scores,4);
    scores[3]=23;
    assert(scored_movie.getScoreCount()==4);
    assert(scored_movie.getScore(0)==4);
    assert(scored_movie.getScore(1)==7);
    assert(scored_movie.getScore(2)==1);
    assert(scored_movie.getScore(3)==1);
}
void test_7_Person(){                                 //7.1a
    hfu::Person* arrayCopy() {
        hfu::Person* result = new hfu::Person[4];
        result[0]=hfu::Person("Minnie", "Maus");
        result[1]=hfu::Person("Daisy", "Duck");
        result[2]=hfu::Person("Donald", "Duck");
        result[3]=hfu::Person("Micky", "Maus");
        return result;
    }
}
void test_sort7(){
    int size = 4;
    hfu::Person* persons = arrayCopy();
    hfu::sort(persons, size);
    assert((persons[0]).getFirstname() == "Daisy");
    assert((persons[1]).getFirstname() == "Donald");
    assert((persons[2]).getFirstname() == "Micky");
    assert((persons[3]).getFirstname() == "Minnie");
    delete[] persons;

}

int main() {
    std::cout<<"Starting..."<<std::endl;
    test_person();
    test_movie();
    test_compare();
    std::cout<<"Continuing..."<<std::endl;
    test_sort();
    test_scores();
    std::cout<<"Terminating..."<<std::endl;
    return 0;
}