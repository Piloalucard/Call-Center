#ifndef AGENTLIST_H_INCLUDED
#define AGENTLIST_H_INCLUDED

#include <iostream>
#include <fstream>
#include <locale>
#include <string>

#include "agentnode.h"
#include "agent.h"

class AgentList{
	private:
		AgentNode* header;

		bool isValidPos(AgentNode*);
		void copyAll(const AgentList&);
		void swapPtr(AgentNode*,AgentNode*);

		void sortX(AgentNode*,AgentNode*,bool);
		std::string minuscula(std::string);
	public:
		AgentList();
		AgentList(const AgentList&);
		~AgentList();

		void insertData(AgentNode*, const Agent&);
		void deleteData(AgentNode*);
		void deleteAll();
		bool isEmpty();

		void findData(AgentNode*);


		AgentNode* getFirstPos();
		AgentNode* getLastPos();
		AgentNode* getPrevPos(AgentNode*);
		AgentNode* getNextPos(AgentNode*);

		AgentNode* findData(const Agent&);
		bool deleteDataByName(const Agent&);
		std::string toStringByName(const Agent&,const bool&);

		Agent retrieve(AgentNode*);

		void sortByName();
		void sortByWorkField();
		std::string toString(const bool&);
		std::string toStringByWorkField(const std::string&,const bool&);

		void writeToDisk(const std::string&);
		void readFromDisk(const std::string&);

		AgentList& operator=(const AgentList&);


};

#endif // AGENTLIST_H_INCLUDED
