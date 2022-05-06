#include "clientlist.h"
using namespace std;
//Entregable 4
bool ClientList::isValidPos(ClientNode* p)
{
    ClientNode* aux(anchor);

    while(aux != nullptr)
    {
        if(aux == p)
        {
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

ClientList::ClientList() : anchor(nullptr){ }


bool ClientList::isEmpty()
{
    return anchor == nullptr;
}
string ClientList::toString() const
{
    ClientNode* aux(anchor);
    string result;
    while(aux!=nullptr)
    {
        result+= aux->getData().toString();
        result += "\n";
        aux= aux->getNext();
    }
    return result;
}

void ClientList::insertOrdered(const Client& cn)
{
    ClientNode* aux(anchor);
    ClientNode* p(nullptr);
    ClientNode* ant(nullptr);
    int cont=0;
    while(aux != nullptr)
    {
        p=aux;
        if(cn > p->getData())
        {
            ant=aux;
            aux= aux->getNext();

        }
        else
        {
            aux=nullptr;
        }
        cont++;

    }
    if(cont!=0 and !(cn > p->getData()))
    {
        p=ant;
    }

    insertData(p,cn);
}

void ClientList::insertData(ClientNode* p, const Client& cn)
{
    if(p!= nullptr and !isValidPos(p))
    {
        throw ListException("Posicion invalida");
    }
    ClientNode* aux(new ClientNode(cn));

    if(aux==nullptr)
    {
        throw ListException("Memoria no disponible");
    }
    if(p == nullptr)
    {
        aux->setNext(anchor);
        anchor = aux;
    }
    else
    {
        aux->setNext(p->getNext());
        p->setNext(aux);
    }
}

//Entregable 5
ClientNode* ClientList::getFirstPos()
{
    return anchor;
}

ClientNode* ClientList::getLastPos()
{
    if(isEmpty())
    {
        return nullptr;
    }
    ClientNode* aux(anchor);

    while(aux->getNext() != nullptr)
    {
        aux = aux->getNext();
    }
    return aux;
}

ClientNode* ClientList::getNextPos(ClientNode* p)
{
    if(!isValidPos(p))
    {
        return nullptr;
    }
    return p->getNext();
}

ClientNode* ClientList::getPrevPos(ClientNode* p)
{
    if(p == anchor or !isValidPos(p))
    {
        return nullptr;
    }

    ClientNode* aux(anchor);

    while(aux->getNext() != p)
    {
        aux = aux ->getNext();
    }
    return aux;
}

void ClientList::deleteData(ClientNode* p)
{
    if(!isValidPos(p))
    {
        throw ListException("Posicion invalida, deleteData");
    }
    if(p==anchor)
    {
        anchor = p->getNext();
    }
    else
    {
        getPrevPos(p)->setNext(p->getNext());
    }
    delete p;
}

ClientNode* ClientList::findData(const Client& e)
{
    ClientNode* aux(anchor);
    while(aux != nullptr and aux->getData() != e)
    {
        aux= aux->getNext();
    }
    return aux;

}

void ClientList::deleteAll()
{
    ClientNode* aux(anchor);

    while(aux != nullptr){
        deleteData(aux);
        aux = aux->getNext();
    }
}

ClientList::~ClientList()
{
    deleteAll();
}


void ClientList::copyAll(const ClientList& l)
{
    ClientNode* aux(l.anchor);
    ClientNode* last(nullptr);
    ClientNode* newNode;

    while(aux != nullptr)
    {
        newNode= new ClientNode(aux->getData());
        if(newNode==nullptr)
        {
            throw ListException("Memoria no disponible, copyAll");
        }
        if(last==nullptr)
        {
            anchor=newNode;
        }
        else
        {
            last->setNext(newNode);
        }
        last = newNode;
        aux= aux->getNext();
    }
}

ClientList::ClientList(const ClientList& l) : ClientList()
{
    copyAll(l);
}

Client ClientList::retrieve(ClientNode* p)
{
    if(!isValidPos(p))
    {
        throw ListException("Posicion invalida, retrieve");

    }
    return p->getData();
}

ClientList& ClientList::operator=(const ClientList& l)
{
    deleteAll();
    copyAll(l);
    return *this;
}

void ClientList::writeToDisk(const string& fileName)
{
    ofstream myFile;
    myFile.open(fileName, myFile.trunc);

    if(!myFile.is_open())
    {
        string message;
        message= "Error al abrir el archivo: '"+fileName+"' para escritura";
        throw ListException(message);
    }

    ClientNode* aux(anchor);
    while(aux!=nullptr)
    {
        myFile << aux->getData() << endl;
        aux=aux->getNext();
    }
    myFile.close();

}

void ClientList::readFromDisk(const std::string& fileName)
{
    ifstream myFile;
    myFile.open(fileName);

    if(!myFile.is_open())
    {
        string message;
        message= "Error al abrir el archivo: '"+fileName+"' para lectura";
        throw ListException(message);
    }
    deleteAll();

    Client myClient;
    ClientNode* last(nullptr);
    ClientNode* newNode;

    while(myFile>>myClient)
    {
        if((newNode=new ClientNode(myClient))==nullptr)
        {
            myFile.close();
            throw ListException("Memoria no disponible");
        }
        if(last==nullptr)
        {
            anchor=newNode;
        }
        else
        {
            last->setNext(newNode);
        }
        last=newNode;
    }
    myFile.close();
}


