#include "../headers/agentlist.h"

using namespace std;
// Entregable 7

AgentList::AgentList() : header (new AgentNode)
{
    if(header==nullptr)
    {
        throw ListException("Memoria no disponible, inicializando lista");
    }
    header->setPrev(header);
    header->setNext(header);
}

bool AgentList::isEmpty()
{
    return header->getNext()==header;
}

void AgentList::insertData(AgentNode* p,const Agent& e)
{
    if(p != nullptr and !isValidPos(p))
    {
        throw ListException("Posicion invalida, insertData AgentList");
    }
    if(p==nullptr)
    {
        p=header;
    }
    AgentNode* aux(new AgentNode(e));
    if(aux==nullptr)
    {
        throw ListException("Memoria no disponible, insertData");
    }
    aux->setPrev(p);
    aux->setNext(p->getNext());

    p->getNext()->setPrev(aux);
    p->setNext(aux);
}

bool AgentList::isValidPos(AgentNode* p)
{
    AgentNode* aux(header->getNext());
    while(aux != header)
    {
        if(p==aux)
        {
            return true;
        }
        aux=aux->getNext();
    }
    return false;
}

string AgentList::toString(const bool& withAgentList)
{
    AgentNode* aux(header->getNext());
    string result="";
    while(aux!=header)
    {
        result+=aux->getData().toString(withAgentList);
        result+="\n";
        aux=aux->getNext();
    }
    if(result.compare("")==0)
    {
        result=" No hay Agentes aun! \n";
    }
    return result;
}



// Entregable 8

AgentNode* AgentList::getPrevPos(AgentNode* p)
{
    if(p==header->getNext() or !isValidPos(p))
    {
        return nullptr;
    }
    return p->getPrev();
}

AgentNode* AgentList::getNextPos(AgentNode* p)
{
    if(p==header->getPrev() or !isValidPos(p))
    {
        return nullptr;
    }
    return p->getNext();
}

void AgentList::deleteData(AgentNode* p)
{
    if(!isValidPos(p))
    {
        throw ListException("Posicion invalida, deleteData Agentlist");
    }
    p->getPrev()->setNext(p->getNext());
    p->getNext()->setPrev(p->getPrev());
    delete p;
}

AgentNode* AgentList::findData(const Agent& e)
{
    AgentNode* aux(header->getNext());

    while(aux != header)
    {
        if(aux->getData() == e)
        {
            return aux;
        }
        aux=aux->getNext();
    }
    return nullptr;
}

bool AgentList::deleteDataByName(const Agent& e)
{
    AgentNode* aux(header->getNext());
    char op;
    while(aux != header)
    {
        if(aux->getData().getName().compare(e.getName())==0)
        {
            cout << endl << aux->getData().toString(true) ;
            do
            {
                cout << "Este es el Agente que desea eliminar (Y/N) : ";
                fflush(stdin);
                cin >> op;
                cin.ignore();
                op=toupper(op);
            }while(op != 'Y' and op != 'N');
            if(op=='Y')
            {
                deleteData(aux);
                return true;
            }
            cout << endl;

        }
        aux=aux->getNext();

    }
    return false;
}

string AgentList::toStringByName(const Agent& e,const bool& d)
{
    AgentNode* aux(header->getNext());
    string result="";
    while(aux != header)
    {
        if(aux->getData().getName().compare(e.getName())==0)
        {
            result+="\n";
            result+=aux->getData().toString(d);
            result+="\n";
        }
        aux=aux->getNext();
    }
    if(result.compare("")==0)
    {
        result=" No hubo coincidencias! \n";
    }
    return result;
}

string AgentList::toStringByWorkField(const std::string& spec,const bool& d)
{
    AgentNode* aux(header->getNext());
    string result="";
    while(aux != header)
    {
        if(aux->getData().getWorkField().compare(spec)==0)
        {
            result+="\n";
            result+=aux->getData().toString(d);
            result+="\n";
        }
        aux=aux->getNext();
    }
    if(result.compare("")==0)
    {
        result=" No hay Agentes con esa especialidad aun! \n";
    }
    return result;
}


void AgentList::deleteAll()
{
    AgentNode* aux;

    while(header->getNext() != header)
    {
        aux=header->getNext();
        header->setNext(aux->getNext());
        delete aux;
    }
    header->setPrev(header);
}

AgentList::~AgentList()
{
    deleteAll();
    delete header;
}

//Extras

void AgentList::copyAll(const AgentList& l)
{
    AgentNode* aux(l.header->getNext());
    AgentNode* newNode;

    while(aux != l.header)
    {
        newNode= new AgentNode(aux->getData());
        if(newNode == nullptr)
        {
            throw ListException("Memoria no disponible, copyAll");
        }
        newNode->setPrev(header->getPrev());
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux=aux->getNext();
    }
}

AgentList::AgentList(const AgentList& l) : AgentList()
{
    copyAll(l);
}

AgentNode* AgentList::getFirstPos()
{
    if(isEmpty())
    {
        return nullptr;
    }
    return header->getNext();
}

AgentNode* AgentList::getLastPos()
{
    if(isEmpty())
    {
        return nullptr;
    }
    return header->getPrev();
}

Agent AgentList::retrieve(AgentNode* p)
{
    if(!isValidPos(p))
    {
        throw ("Posicion invalida, retrieve");
    }
    return p->getData();
}

AgentList& AgentList::operator=(const AgentList& l)
{
    deleteAll();
    copyAll(l);
    return *this;
}

//Entregable 10

void AgentList::swapPtr(AgentNode* a, AgentNode* b)
{
    if(a!=b)
    {
        Agent* aux(a->getDataPT());
        a->setDataPT(b->getDataPT());
        b->setDataPT(aux);

    }
}

void AgentList::sortByName()
{
    sortX(getFirstPos(),getLastPos(),true);
}

void AgentList::sortByWorkField()
{
    sortX(getFirstPos(),getLastPos(),false);
}

void AgentList::sortX(AgentNode* left,AgentNode* right,bool modo)
{
    if(left==right)
    {
        return;
    }
    string datoL;
    string datoR;
    if(modo)
    {
        datoL=minuscula(left->getData().getName());
        datoR=minuscula(right->getData().getName());
    }
    else
    {
        datoL=left->getData().getWorkField();
        datoR=right->getData().getWorkField();
    }

    if(left->getNext() == right)
    {
        if(datoL > datoR)
        {
            swapPtr(left,right);
        }
        return;
    }

    AgentNode* i(left);
    AgentNode* j(right);


    if(modo)
    {
        while(i!=j)
        {
            while(i != j and minuscula(i->getData().getName()) <= datoR)
            {
                i=i->getNext();
            }
            while( i!= j and minuscula(j->getData().getName()) >= datoR)
            {
                j = j->getPrev();
            }
            swapPtr(i,j);
        }
        swapPtr(i,right);
    }
    else
    {
        while(i!=j)
        {
            while(i != j and i->getData().getWorkField() <= datoR)
            {
                i=i->getNext();
            }
            while( i!= j and j->getData().getWorkField() >= datoR)
            {
                j = j->getPrev();
            }
            swapPtr(i,j);
        }
        swapPtr(i,right);
    }
    //No se implemento strings auxiliares para i ni para j, porque causaba conflicto a la hora de ordenarse

    if(i != left)
    {
        sortX(left,i->getPrev(),modo);
    }
    if(i != right)
    {
        sortX(i->getNext(),right,modo);
    }
}

string AgentList::minuscula(string str)
{
    if(str=="")
    {
        return str;
    }

    locale loc;
    string aux="";
    for (string::size_type i=0; i<str.length(); ++i)
    {
        aux+=tolower(str[i],loc);
    }
    return aux;


}


void AgentList::writeToDisk(const std::string& fileName)
{
    ofstream myFile;
    stringstream a;
    string b;
    myFile.open(fileName, myFile.trunc);

    if(!myFile.is_open())
    {
        string message;
        message= "Error al abrir el archivo: '"+fileName+"' para escritura";
        throw ListException(message);
    }
    AgentNode* aux(header->getNext());


    while(aux != header)
    {
        myFile << aux->getData() << endl;

        try
        {
            a.str("");
            a.clear();
            a<<aux->getData().getEmployeeNumber();
            b=a.str();
            aux->getData().getClientList().writeToDisk(fileName+"-clientes-"+b);
        }
        catch(ListException ex)
        {
            cout << ex.what() << endl;
        }
        aux=aux->getNext();
    }
    myFile.close();
}

void AgentList::readFromDisk(const std::string& fileName)
{
    ifstream myFile;
    myFile.open(fileName);
    stringstream a;
    string b;
    if(!myFile.is_open())
    {
        string message;
        message= "Error al abrir el archivo: '"+fileName+"' para lectura";
        throw ListException(message);
    }

    Agent myAgent;
    AgentNode* aux;

    deleteAll();

    while(myFile >> myAgent)
    {
        try
        {
            a.str("");
            a.clear();
            a<<myAgent.getEmployeeNumber();
            b=a.str();
            myAgent.getClientList().readFromDisk(fileName+"-clientes-"+b);
        }
        catch(ListException ex)
        {
            cout << ex.what() << endl;
        }
        if((aux=new AgentNode(myAgent))==nullptr)
        {
            myFile.close();
            throw ListException("Memoria no disponible");
        }
        aux->setPrev(header->getPrev());
        aux->setNext(header);

        header->getPrev()->setNext(aux);
        header->setPrev(aux);
    }
    myFile.close();

}







