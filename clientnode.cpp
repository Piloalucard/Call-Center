#include "clientnode.h"

using namespace std;

ClientNode::ClientNode() : next(nullptr){}

ClientNode::ClientNode(const Client& cn) : data(cn), next(nullptr){}


Client ClientNode::getData()
{
    return data;
}

ClientNode* ClientNode::getNext()
{
    return next;
}

void ClientNode::setData(const Client& cn)
{
    data=cn;
}

void ClientNode::setNext(ClientNode* p)
{
    next=p;
}
