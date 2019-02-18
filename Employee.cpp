#include "Employee.hpp"

using namespace std;

Employee::Employee(const string & name,
                   const string & lastname,
                   const string & address,
                   const string & pesel,
                   Gender gender,
                   int salary)
    :Person(name, lastname, address, pesel, gender)
    ,salary_(salary)
{}

int Employee::getSalary() const
{
    return salary_;
}

