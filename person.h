#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class person
{
public:
    person();


private:
    std::string name;
    std::string surname;
    std::string patronymic;
    int age;

public:
    std::string get_name();
    std::string get_surname();
    std::string get_patronymic();
    int get_age();
};

#endif // PERSON_H
