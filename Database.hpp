#pragma once
#include "Person.hpp"
#include <vector>

using namespace std;

using allPeople= vector<Person*>;

class Database
{
public:
    void addStudent(Person* person);
    void sortByIndex();
    void removeStudent(int index);
    allPeople findByLastname(const string & lastname);
    Person* findByPesel(const string & pesel);
    void show();
    void sortByPesel();
    void sortByLastname();
    void removeByPesel(const string & pesel);
    void modifyAddressByPesel(const string & pesel, const string & newAddress);

private:
    allPeople allPeople_;
};
