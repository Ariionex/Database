#pragma once
#include "Person.hpp"
#include <string>

using namespace std;

class Student : public Person
{
public:
    Student(const string & name,
            const string & lastname,
            const string & address,
            const string & pesel,
            Gender gender,
            int index);
        int getIndex () const;

private:
    int index_;
};
