#pragma once
#include "Person.hpp"
#include <string>

using namespace std;

class Employee : public Person
{
public:
    Employee(const string & name,
             const string & lastname,
             const string & address,
             const string & pesel,
             Gender gender,
             int salary);
        int getSalary() const;
private:
    int salary_;
};
