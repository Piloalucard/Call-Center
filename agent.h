#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED

#include <iostream>
#include <sstream>
#include <string>
#include "clientlist.h"
#include "schedule.h"

class Agent{
	private:
		std::string name;
		int employeeNumber;
		Schedule schedule;
		std::string workField;
		int extension;
		int extraHours;
		ClientList clientList;
	public:
		Agent();
		Agent(const Agent&);

		std::string getName() const;
		int getEmployeeNumber() const;
		Schedule getSchedule() const;
		std::string getWorkField() const;
		int getExtension() const;
		int getExtraHours();
		ClientList& getClientList();
		std::string toString(const bool&) const;

		void setName(const std::string&);
		void setEmployeeNumber(const int&);
		void setSchedule(const Schedule&);
		void setWorkField(const std::string&);
		void setExtension(const int&);
		void setExtraHours(const int&);
		void setClientList(const ClientList&);

        bool operator == (const Agent&) const;
        Agent& operator = (const Agent&);
        friend std::ostream& operator << (std::ostream&, const Agent&);
		friend std::istream& operator >> (std::istream&, Agent&);

};
#endif
