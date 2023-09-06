#include "../headers/client.h"
using namespace std;

Client::Client(){}

Client::Client(const Client& c) : name(c.name),date(c.date), time(c.time), duration(c.duration){ }

string Client::getName() const
{
    return name;
}

Date Client::getDate() const
{
    return date;
}

Time Client::getTime() const
{
    return time;
}

Time Client::getDuration() const
{
    return duration;
}

void Client::setName(const std::string& n)
{
    name=n;
}

void Client::setDate(const Date& d)
{
    date= d;
}

void Client::setTime(const Time& t)
{
    time=t;
}

void Client::setDuration(const Time& t)
{
    duration=t;
}

string Client::toString() const
{
    string result;
    result = "\n\n\t/*" + name + "*/\n";
    result += "\t/*Fecha(DD/MM/YYYY): ";
    result+= date.toString();
    result += "*/\n";
    result += "\t/*Fue realizado a las: ";
    result+= time.toString();
    result += "*/\n";
    result += "\t/*Con duracion de: ";
    result+= duration.toString();
    result+="*/";

    return result;
}
ostream& operator << (ostream& os, const Client& c)
{
    os << c.name << endl;
    os << c.date << endl;
    os << c.time << endl;
    os << c.duration;
    return os;
}

istream& operator  >> (istream& is, Client& c)
{
    getline(is, c.name);
    is >> c.date;
    is >> c.time;
    is>> c.duration;

    return is;
}

bool Client::operator!=(const Client& s)const
{
    return name.compare(s.name);
}

bool Client::operator>(const Client& s)const
{
    if(time.getHour()>=s.time.getHour())
    {
        if(time.getHour()==s.time.getHour())
        {
            return time.getMinute() > s.time.getMinute();
        }
        else
        {
            return true;
        }
    }
    return false;
}
