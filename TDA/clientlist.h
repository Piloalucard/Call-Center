#ifndef CLIENTLIST_H_INCLUDED
#define CLIENTLIST_H_INCLUDED

#include <iostream>
#include <fstream>

#include "clientnode.h"
#include "client.h"
#include "listexception.h"

class ClientList{
	private:
		ClientNode* anchor;
        bool isValidPos(ClientNode*);
        void copyAll(const ClientList&);

	public:
		ClientList();
		ClientList(const ClientList&);
		~ClientList();

		bool isEmpty();
		void insertOrdered(const Client&);
		void insertData(ClientNode*, const Client&);

        std::string toString() const;
		void deleteData(ClientNode*);
		void deleteAll();
		void writeToDisk(const std::string&);
		void readFromDisk(const std::string&);

		ClientNode* getFirstPos();
		ClientNode* getLastPos();
		ClientNode* getPrevPos(ClientNode*);
		ClientNode* getNextPos(ClientNode*);
		ClientNode* findData(const Client&);
		Client retrieve(ClientNode*);
		ClientList& operator = (const ClientList&);


};
#endif
