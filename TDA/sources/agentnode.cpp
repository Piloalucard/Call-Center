#include "../headers/agentnode.h"

using namespace std;
AgentNode::AgentNode() : dataPT(nullptr), prev(nullptr), next(nullptr)
{
}

AgentNode::AgentNode(const Agent& e) : dataPT(new Agent(e)) , prev(nullptr), next(nullptr)
{
    if(dataPT==nullptr)
    {
        throw AgentNodeException("Memoria no disponible, creando AgentNode");
    }
}

AgentNode::~AgentNode()
{
    delete dataPT;
}

Agent AgentNode::getData()
{
    if(dataPT==nullptr)
    {
        throw AgentNodeException ("Error, el dato no existe, getData , AgentNode");
    }
    return *dataPT;
}

Agent* AgentNode::getDataPT()
{
    return dataPT;
}

AgentNode* AgentNode::getPrev()
{
    return prev;
}

AgentNode* AgentNode::getNext()
{
    return next;
}

void AgentNode::setDataPT(Agent* p)
{
    dataPT=p;
}

void AgentNode::setData(const Agent& e)
{
    delete dataPT;
    dataPT= new Agent(e);

    if(dataPT==nullptr)
    {
        throw AgentNodeException("Memoria no disponible, setData");
    }
}

void AgentNode::setPrev(AgentNode* p)
{
    prev=p;
}

void AgentNode::setNext(AgentNode* p)
{
    next=p;
}
