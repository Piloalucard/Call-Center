#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <iostream>

#include "time.h"
#include "date.h"

class Client{
	private:
		std::string name;
		Date date;
		Time time;
		Time duration;
	public:
		Client();
		Client(const Client&);

		std::string getName() const;
		Date getDate() const;
		Time getTime() const;
		Time getDuration() const;
        std::string toString() const;

		void setName(const std::string&);
		void setDate(const Date&);
		void setTime(const Time&);
		void setDuration(const Time&);

        bool operator != (const Client&) const;
        bool operator > (const Client&) const;

		friend std::ostream& operator << (std::ostream&, const Client&);
		friend std::istream& operator >> (std::istream&, Client&);

};

 #endif
