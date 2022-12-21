#ifndef CLIENTBASE_H
#define CLIENTBASE_H

#include <iostream>
#include <vector>
#include "client.h"

class clientBase
{
public:
    clientBase();

private:

    std::vector<client> clients;

};

#endif // CLIENTBASE_H
