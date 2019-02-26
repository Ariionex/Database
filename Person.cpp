#include "Person.hpp"

using namespace std;

Person::Person(const string & name,
               const string & lastname,
               const string & address,
               const string & pesel,
               Gender gender)
    : name_(name)
    , lastname_(lastname)
    , address_(address)
    , pesel_(pesel)
    , gender_(gender)
{}

string Person::getLastname() const
{
    return lastname_;
}

string Person::getPesel() const
{
    return pesel_;
}
string Person::show() const
{
    return name_ + " " + lastname_ + ", PESEL: " + pesel_ + ", adres: " + address_;
}
int Person::getIndex() const{}
int Person::getSalary() const{}
