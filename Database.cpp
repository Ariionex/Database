#include "Database.hpp"
#include "Student.hpp"
#include <algorithm>

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
