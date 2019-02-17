#include "Student.hpp"

using namespace std;

Student::Student(const string & name,
                 const string & lastname,
                 const string & address,
                 const string & pesel,
                 Gender gender,
                 int index)
    : Person(name, lastname, address, pesel, gender)
    , index_(index)
{}

int Student::getIndex() const
{
    return index_;
}

