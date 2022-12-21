#ifndef CLIENT_H
#define CLIENT_H

#include "person.h"

class client : public person
{
public:
    client();

private:
    std::string membership;

public:
    std::string get_membership();

};

#endif // CLIENT_H
