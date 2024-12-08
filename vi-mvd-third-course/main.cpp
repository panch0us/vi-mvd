using namespace std;

#include <iostream>
#include "person.h"



int main(int argc, char **argv)
{
    string surname = "Савкин";
    string name = "Павел";
    string middle_name = "Владимирович";
    string sex = "М";

    PersonMissing pm;
    pm.setSurname(surname);
    pm.setName(name);
    pm.setMiddleName(middle_name);
    pm.setSex(sex);
    pm.setBirthYear(1990);

    cout << pm.getSurname() << std::endl;
    cout << pm.getName() << std::endl;
    
    return 0;
}
