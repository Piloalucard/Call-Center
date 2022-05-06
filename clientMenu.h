#ifndef CLIENTMENU_H_INCLUDED
#define CLIENTMENU_H_INCLUDED

#include <iostream>
#include "clientlist.h"
#include <string>
#include <ctype.h>
class ClientMenu
{
private:
    ClientList* clientListRef;

    void mainMenu();
    void pause();
    void addClient();
    void deleteClient();
    void modifyClient();
    void showClient();
    void header();

public:
    ClientMenu(ClientList*);

};

#endif // CLIENTMENU_H_INCLUDED
