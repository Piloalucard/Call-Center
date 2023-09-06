#include "../headers/time.h"

using namespace std;

bool Time::isValid(const int& h, const int& m) const
{
    return h >= 0 and h < 24 and m >= 0 and m <60;
}

Time::Time()
{
    chrono::system_clock::time_point today = chrono::system_clock::now();
    time_t tt;
    tt = chrono::system_clock::to_time_t (today);
    struct tm* timeinfo;
    timeinfo = localtime(&tt);
    hour = timeinfo->tm_hour;
    minute = timeinfo->tm_min;
}

Time::Time(const Time& t) : hour(t.hour), minute(t.minute){}

Time::Time(const int& h, const int& m) : Time()
{
    if(isValid(h,m))
    {
        hour=h;
        minute=m;
    }
}

int Time::getHour() const
{
    return hour;
}

int Time::getMinute() const
{
    return minute;
}

void Time::setHour(const int& h)
{
    if(isValid(h,minute))
    {
        hour = h;
    }
}

void Time::setMinute(const int& m)
{
    if(isValid(hour,m))
    {
        minute=m;
    }
}

string Time::toString() const
{
    char result[6];
    sprintf(result, "%02i:%02i",hour,minute);
    return result;
}


ostream& operator << (ostream& os, const Time& t)
{
    os << t.toString();
    return os;
}

istream& operator  >> (istream& is, Time& t)
{
    string myStr;
    getline(is, myStr, ':');
    t.hour = atoi(myStr.c_str());
    getline(is,myStr);
    t.minute= atoi(myStr.c_str());

    return is;
}

