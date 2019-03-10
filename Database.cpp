#include "Database.hpp"
#include "Student.hpp"
#include <algorithm>
#include <iostream>
using namespace std;

void Database::addStudent(Person* person)
{
    allPeople_.emplace_back(person);
}
void Database::sortByIndex()
{
    sort(begin(allPeople_),end(allPeople_),[](const auto & lhs, const auto & rhs){
            return lhs->getIndex() < rhs->getIndex();
         });
}
void Database::removeStudent(int index)
{
    auto iter = find_if(begin(allPeople_),end(allPeople_),[index](const auto & person){
        return person->getIndex() == index;
    });
    if (iter != end(allPeople_))
    {
        allPeople_.erase(iter);
    }
}
allPeople Database::findByLastname(const string & lastname)
{
    vector<Person*>founded;
    copy_if(allPeople_.begin(),allPeople_.end(),back_inserter(founded),[lastname](const auto & iter){
        return iter->getLastname() == lastname;
            });
    return founded;
}
Person* Database::findByPesel(const string & pesel)
{
    auto it = find_if(allPeople_.begin(),allPeople_.end(),
                      [pesel](const auto & i)
    {
         return i->getPesel() == pesel;
    });
}
void Database::show()
{
    for_each(allPeople_.begin(),allPeople_.end(),[](auto i){cout << i->show() << endl;});
}

void Database::sortByPesel()
{
    sort(allPeople_.begin(),allPeople_.end(),[](Person *a, Person *b){return a->getPesel() < b->getPesel();});
}

void Database::sortByLastname()
{
    sort(allPeople_.begin(),allPeople_.end(),[](Person *a, Person *b){return a->getLastname() < b->getLastname();});
}

void Database::removeByPesel(const string & pesel)//???????????????????
{
    auto human = remove_if(allPeople_.begin(), allPeople_.end(),[pesel](const auto & i)
    {
        return i->getPesel() == pesel;
    });
    allPeople_.erase(human);
}
void Database::modifyAddressByPesel(const string & pesel, const string & newAddress)
{
    auto i = findByPesel(pesel);
    i->setAddress(newAddress);
}
void Database::save(string fileName) const
{
    ofstream ofile(fileName);

    for (auto element : allPeople_)
    {

        ofile << element->getName() << endl;
        ofile << element->getLastname() << endl;
        ofile << element->getPesel() << endl;
        ofile << static_cast<char>(element->getGender()) << endl;
        ofile << element->getAddress() << endl;
        ofile << element->getIndex() << endl;
    }
}
void Database::load(string fileName)
{
    ifstream ifile(fileName);

    if (ifile.good()==false)
    {
        cout<<"Nie mozna otworzyc pliku"<<endl;
        exit(0);
    }

    string line;
    int line_no=1;

    while (getline(ifile,line))
    {
        string temp_name = "NULL";
        string temp_surname = "NULL";
        string temp_PESEL = "NULL";
        string temp_sex = "NULL";
        string temp_address = "NULL";
        string temp_no_of_grade_book = "NULL";

        switch(line_no)
        {
            case 1: temp_name=line;
            case 2: temp_surname=line;
            case 3: temp_PESEL=line;
            case 4: temp_sex=line;
            case 5: temp_address=line;
            case 6: temp_no_of_grade_book=line;
        }
        if(line_no==7)
            line_no=1;
        else
            line_no++;
    }
}
