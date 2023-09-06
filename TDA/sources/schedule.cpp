#include "../headers/schedule.h"
using namespace std;
bool Schedule::isValid(const bool& m, const bool& t, const bool& w, const bool&th, const bool&f, const bool& s) const
{
    return m or t or w or th or f or s;
}

Schedule::Schedule()
{
    monday=true;
    tuesday=true;
    wednesday=true;
    thursday=true;
    friday=true;
    saturday=false;
}

Schedule::Schedule(const Schedule& s) : monday(s.monday), tuesday(s.tuesday), wednesday(s.wednesday),
thursday(s.thursday), friday(s.friday),saturday(s.saturday), startTime(s.startTime), endTime(s.endTime){}

Schedule::Schedule(const bool& m, const bool& t, const bool& w, const bool& th, const bool& f, const bool& s, const Time& sT, const Time& eT)
{
    if(isValid(m,t,w,th,f,s))
    {
        monday=m;
        tuesday=t;
        wednesday=w;
        thursday=th;
        friday=f;
        saturday=s;
    }


}

bool Schedule::getMonday() const
{
    return monday;
}

bool Schedule::getTuesday() const
{
    return tuesday;
}

bool Schedule::getWednesday() const
{
    return wednesday;
}

bool Schedule::getThursday() const
{
    return thursday;
}

bool Schedule::getFriday() const
{
    return friday;
}

bool Schedule::getSaturday() const
{
    return saturday;
}

Time Schedule::getStartTime() const
{
    return startTime;
}

Time Schedule::getEndTime() const
{
    return endTime;
}

void Schedule::setMonday(const bool& m)
{

    monday=m;
}

void Schedule::setTuesday(const bool& t)
{

    tuesday=t;

}

void Schedule::setWednesday(const bool& w)
{

    wednesday=w;
}

void Schedule::setThursday(const bool& th)
{

    thursday=th;
}

void Schedule::setFriday(const bool& f)
{

    friday=f;
}

void Schedule::setSaturday(const bool& s)
{
    saturday=s;
}

void Schedule::setStartTime(const Time& t)
{
    startTime=t;
}

void Schedule::setEndTime(const Time& t)
{
    endTime=t;
}
string Schedule::toString() const
{
    string result;
    result = "*Trabaja* \n";
    if(monday)
        result += "-Lunes-\n";
    if(tuesday)
        result += "-Martes-\n";
    if(wednesday)
        result += "-Miercoles-\n";
    if(thursday)
        result += "-Jueves-\n";
    if(friday)
        result += "-Viernes-\n";
    if(saturday)
        result += "-Sabado-\n";
    result+="De: " + startTime.toString();
    result+=" A " + endTime.toString();
    return result;
}

ostream& operator << (ostream& os, const Schedule& c)
{
    os << c.monday << endl;
    os << c.tuesday << endl;
    os << c.wednesday << endl;
    os << c.thursday << endl;
    os << c.friday << endl;
    os << c.saturday << endl;
    os << c.startTime << endl;
    os << c.endTime;
    return os;
}

istream& operator  >> (istream& is, Schedule& c)
{
    string myStr;
    getline(is, myStr);
    c.monday=(myStr=="1") ? true:false;
    getline(is, myStr);
    c.tuesday=(myStr=="1") ? true:false;
    getline(is, myStr);
    c.wednesday=(myStr=="1") ? true:false;
    getline(is, myStr);
    c.thursday=(myStr=="1") ? true:false;
    getline(is, myStr);
    c.friday=(myStr=="1") ? true:false;
    getline(is, myStr);
    c.saturday=(myStr=="1") ? true:false;

    is >> c.startTime;
    is >> c.endTime;



    return is;
}


