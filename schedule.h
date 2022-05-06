#ifndef SCHEDULE_H_INCLUDED
#define SCHEDULE_H_INCLUDED

#include <iostream>
#include <string>

#include "time.h"

class Schedule
{
	private:
		bool monday;
		bool tuesday;
		bool wednesday;
		bool thursday;
		bool friday;
		bool saturday;
		Time startTime;
		Time endTime;

		bool isValid(const bool&, const bool&, const bool&,
		const bool&,const bool&,const bool&) const;
    public:

		Schedule();
		Schedule(const Schedule&);
		Schedule(const bool&,const bool&,const bool&
		,const bool&,const bool&, const bool&, const Time&, const Time&);

		bool getMonday () const;
		bool getTuesday () const;
		bool getWednesday () const;
		bool getThursday () const;
		bool getFriday () const;
		bool getSaturday () const;
		Time getStartTime () const;
		Time getEndTime () const;
        std::string toString() const;

		void setMonday (const bool&);
		void setTuesday (const bool&);
		void setWednesday (const bool&) ;
		void setThursday (const bool&);
		void setFriday (const bool&);
		void setSaturday (const bool&);
		void setStartTime (const Time&) ;
		void setEndTime (const Time&);

        friend std::ostream& operator << (std::ostream&, const Schedule&);
		friend std::istream& operator >> (std::istream&, Schedule&);

};
#endif
