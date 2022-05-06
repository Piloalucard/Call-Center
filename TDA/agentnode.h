#ifndef AGENTNODE_H_INCLUDED
#define AGENTNODE_H_INCLUDED

#include <iostream>
#include "agent.h"

class AgentNodeException : public std::exception
{
private:
    std::string msg;

public:
    explicit AgentNodeException(const char* message): msg(message) {}
    explicit AgentNodeException(const std::string& message) : msg(message) {}
    virtual ~AgentNodeException() throw () {}

    virtual const char* what() const throw ()
    {
        return msg.c_str();
    }
};


class AgentNode
{
	private:
		Agent* dataPT;
		AgentNode* prev;
		AgentNode* next;

	public:
		AgentNode();
		AgentNode(const Agent&);

		~AgentNode();

		Agent getData();
		Agent* getDataPT();
		AgentNode* getPrev();
		AgentNode* getNext();

		void setDataPT(Agent*);
		void setData(const Agent&);
		void setPrev(AgentNode*);
		void setNext(AgentNode*);


};

#endif // AGENTNODE_H_INCLUDED
