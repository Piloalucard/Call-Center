#include "../headers/agent.h"

using namespace std;

Agent::Agent()
{
}

Agent::Agent(const Agent& a): name(a.name), employeeNumber(a.employeeNumber), schedule(a.schedule), workField(a.workField)
,extension(a.extension),extraHours(a.extraHours), clientList(a.clientList){}

string Agent::getName() const
{
    return name;
}

int Agent::getEmployeeNumber() const
{
    return employeeNumber;
}

Schedule Agent::getSchedule() const
{
    return schedule;
}

string Agent::getWorkField() const
{
    return workField;
}

int Agent::getExtension() const
{
    return extension;
}

int Agent::getExtraHours()
{
    return extraHours;
}


ClientList& Agent::getClientList()
{
    return clientList;
}

void Agent::setName(const std::string& n)
{
    name=n;
}

void Agent::setEmployeeNumber(const int& en)
{
    employeeNumber=en;
}

void Agent::setSchedule(const Schedule& s)
{
    schedule=s;
}

void Agent::setWorkField(const std::string& wf)
{
    workField=wf;
}

void Agent::setExtension(const int& ex)
{
    extension=ex;
}

void Agent::setExtraHours(const int& eh)
{
    extraHours=eh;
}

void Agent::setClientList(const ClientList& c)
{
    clientList=c;
}

string Agent::toString(const bool& subList=false)const
{
    string result="",aux;
    stringstream a;
    result+="----------------------------------------------------------------------\n";
    result+= name+ " : Especialidad de " + workField +"\n";
    result+="----------------------------------------------------------------------\n";
    a<<employeeNumber;
    aux=a.str();
    result+= "No. Empleado: " + aux +"\n";

    a.str("");
    a.clear();
    a<<extension;
    aux=a.str();
    result+= "No. Ext: " + aux + "\n";
    a.str("");
    a.clear();
    a<<extraHours;
    aux=a.str();
    result+= "Horas extras que trabaja: " + aux + "\n";
    result+= schedule.toString() + "\n";
    if(subList)
    {
        result+="\n";
        result+="-------------------------------------------------------------\n";
        result+="\t|     Lista de clientes de " + name + "    |\n";
        result+=clientList.toString();
        result+="-------------------------------------------------------------\n";
        result+="\n";

    }


    return result;
}

bool Agent::operator==(const Agent& a) const
{
    return employeeNumber == a.employeeNumber;
}
Agent& Agent::operator=(const Agent& a)
{
    name=a.name;
    employeeNumber=a.employeeNumber;
    extension=a.extension;
    workField=a.workField;
    extraHours=a.extraHours;
    schedule=a.schedule;
    clientList=a.clientList;
    return *this;
}


ostream& operator << (ostream& os, const Agent& a)
{
    os << a.name << endl;
    os << a.employeeNumber << endl;
    os << a.workField << endl;
    os << a.extension << endl;
    os << a.extraHours << endl;
    os << a.schedule;
    return os;
}

istream& operator >> (istream& is, Agent& a)
{
    string aux;
    getline(is,a.name);
    getline(is,aux);
    a.employeeNumber = atoi(aux.c_str());
    getline(is,a.workField);
    getline(is,aux);
    a.extension = atoi(aux.c_str());
    getline(is,aux);
    a.extraHours = atoi(aux.c_str());
    is >> a.schedule;
    return is;
}


