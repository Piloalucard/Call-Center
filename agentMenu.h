#ifndef AGENTMENU_H_INCLUDED
#define AGENTMENU_H_INCLUDED

#include "agent.h"
#include "agentlist.h"
#include "clientlist.h"
#include "clientMenu.h"
#include "time.h"
#include <ctype.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#define SEG 1000

class agentMenu
{
private:
    AgentList* agentListRef;

    void mainMenu();
    void header();
    void pantalla();
    void pause();
    void addAgent();
    void modifyAgent();
    void deleteAgent();
    void deleteAll();
    void showAgent();
    void showAll();

    void showByWorkField();
    void sortAgent();

    void readFromDisk();
    void writeToDisk();

public:
    agentMenu(AgentList*);
};


#endif // AGENTMENU_H_INCLUDED
