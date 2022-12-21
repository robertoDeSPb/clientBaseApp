#include "person.h"

person::person()
{

}

std::string person::get_name()
{
    return name;
}
std::string person::get_surname()
{
    return surname;
}
std::string person::get_patronymic()
{
    return patronymic;
}
int person::get_age()
{
    return age;
}
