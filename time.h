#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <chrono>
#include <cstdlib>

class Time
{
	private:
		int hour;
		int minute;

		bool isValid(const int&, const int&) const;

	public:
		Time();
		Time(const Time&);
		Time(const int&,const int&);

		std::string toString() const;
		int getHour() const;
		int getMinute() const;

		void setHour(const int&);
		void setMinute(const int&);

		friend std::ostream& operator << (std::ostream&, const Time&);
		friend std::istream& operator >> (std::istream&, Time&);


};

#endif
