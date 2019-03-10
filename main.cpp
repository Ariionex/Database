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
    Person* krzysztof = new Student("Krzysztof","Jarzyna","Szczecinska 11","1987654320",Gender::male,333222);
    db.addStudent(krzysztof);
    Person* lucyfer = new Student("Lucyfer","Podolski","Szczesliwej 666","8887654320",Gender::male,333444);
    db.addStudent(lucyfer);
    Person* baltazar = new Student("Baltazar","Smith","Kowalowa 77","2987654320",Gender::male,336722);
    db.addStudent(baltazar);
    db.sortByIndex();
    
    db.show();
    cout<<endl;
    db.removeByPesel("8887654320");
    db.sortByLastname();
    db.save("Baza_danych.txt");
    db.load("Baza_danych.txt");
    db.show();
    return 0;
}
