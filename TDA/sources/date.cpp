#include "../headers/date.h"
using namespace std;

bool Date::isValid(const int& d, const int& m, const int& y ) const
{
    switch(m)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return d >= 0 and d <= 31 and y >= 2019;
            break;
        case 4: case 6: case 9: case 11:
            return d >= 0 and d <= 30 and y >= 2019;
            break;
        case 2:
            return d >= 0 and d <= 29 and y >= 2019;
            break;
        default:
            return false;

    }
}

Date::Date()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    int j,i=0;
    char aux[3],aux2[1];
	for(j=5;j<7;j++)
    {
        aux2[i]=buf[j];
        i++;
    }
	sscanf(aux2, "%d", &month);
	i=0;
	for(j=8;j<10;j++)
    {
        aux2[i]=buf[j];
        i++;
    }
    sscanf(aux2, "%d", &day);
     for (j=0;j<4;j++)
    {
    	aux[j]=buf[j];
	}
	sscanf(aux, "%d", &year);

}

Date::Date(const Date& d) : day(d.day), month(d.month) , year(d.year){}

Date::Date(const int& d, const int& m , const int& y) : Date()
{
    if(isValid(d,m,y))
    {
        day=d;
        month=m;
        year=y;
    }
}

string Date::toString() const
{
    stringstream d,m,y;
    string aux,result="";
    d<<day;
    aux=d.str();
    result+=aux+"/";
    m<<month;
    aux=m.str();
    result+=aux+"/";
    y<<year;
    aux=y.str();
    result+=aux;
    return result;
}

int Date::getYear() const
{
    return year;
}

int Date::getMonth() const
{
    return month;
}

int Date::getDay() const
{
    return day;
}

void Date::setYear(const int& y)
{
    if(isValid(day,month,y))
    {
        year=y;
    }
}

void Date::setMonth(const int& m)
{
    if(isValid(day,m,year))
    {
        month=m;
    }
}

void Date::setDay(const int& d)
{
    if(isValid(d,month,year))
    {
        day=d;
    }
}

ostream& operator << (ostream& os, const Date& d)
{
    os << d.toString();
    return os;
}

istream& operator  >> (istream& is, Date& d)
{
    string myStr;
    getline(is, myStr, '/');
    d.day = atoi(myStr.c_str());
    getline(is,myStr, '/');
    d.month= atoi(myStr.c_str());
    getline(is,myStr);
    d.year= atoi(myStr.c_str());
    return is;
}

