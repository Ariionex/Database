#pragma once
#include <string>

using namespace std;

enum class Gender : char {male='m', female='f'};

class Person
{
public:
    Person(const string & name,
           const string & lastname,
           const string & address,
           const string & pesel,
           const Gender gender);
        string getLastname() const;
        string getPesel() const;
        string show() const;
        virtual int getIndex() const;
        virtual int getSalary() const;

private:
    string name_;
    string lastname_;
    string address_;
    string pesel_;
    Gender gender_;
};

