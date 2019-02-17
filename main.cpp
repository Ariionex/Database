#include <iostream>
#include "Student.hpp"
#include "Database.hpp"

using namespace std;

int main()
{
    Database db;
    Person* jan = new Student("Jan","Kowalski","Fiolkowa 5","1234567890",Gender::male,166666);
    db.addStudent(jan);
    Person* adam = new Student("Adam","Adamski","Dziwna 10","0987654321",Gender::male,222222);
    db.addStudent(adam);
    db.sortByIndex();
    db.removeStudent(111111);
    db.removeStudent(222222);
    return 0;
}
