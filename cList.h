#pragma once

#include <iostream>
#include <string>

using namespace std;

class cList {

private:

	struct node {
		string data;				// Member to store data
		node* next;					// Member to store a pointer to the next List element
		node* prev;					// Member to store a pointer to the previous List element
	};

	typedef struct node* nodePtr;

	nodePtr head;					// Pointer to the head of the list
	nodePtr curr;					// Pointer to the current element
	nodePtr temp;					// Temporary pointer

public:

	cList();
	// Function that gets a node from input
	string getNode();
	// Function that adds a node to the end of the list
	void AddNode(string addData);
	// Function that adds a node to the begining of the list
	void AddNodeAsFirst(string addData);
	// Function that adds a node after a desirable one
	void AddNodeAfter(string after, string addData);
	// Function that deletes the node from the list
	void DeleteNode(string delData);
	// Function that deletes all the elements from the list
	void Clear();
	// Function to selection sort a linked list in alphabetical orded
	void Sort();
	// Function that prints the list
	void PrintList();
	bool IsEmpty();
	// Function that shows avalible commands
	void Help();
};