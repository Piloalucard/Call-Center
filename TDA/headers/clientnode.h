#ifndef CLIENTNODE_H_INCLUDED
#define CLIENTNODE_H_INCLUDED

#include <iostream>
#include "client.h"

class ClientNode
{
	private:
		Client data;
		ClientNode* next;

	public:
		ClientNode();
		ClientNode(const Client&);

		Client getData();
		ClientNode* getNext();

		void setData(const Client&);
        void setNext(ClientNode*);


};
#endif
