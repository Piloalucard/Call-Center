#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <sstream>
class Date
{
	private:
		int year;
		int month;
		int day;

		bool isValid(const int&, const int&, const int&) const;

	public:
		Date();
		Date(const Date&);
		Date(const int&,const int&,const int&);

		std::string toString() const;
		int getYear() const;
		int getMonth() const;
		int getDay() const;

		void setYear(const int&);
		void setMonth(const int&);
		void setDay(const int&);

		friend std::ostream& operator << (std::ostream&, const Date&);
		friend std::istream& operator >> (std::istream&, Date&);

};
#endif
