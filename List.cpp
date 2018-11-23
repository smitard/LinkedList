#include "cList.h"

cList::cList() {
	head = NULL;
	curr = NULL;
	temp = NULL;
}

// Function that gets a node from console
string cList::getNode() {
	string addData;
	getline(cin, addData);
	int i = addData.length() - 1;
/*  In this loop we are getting rid of unnecessary spaces*/
	while (addData[i] == ' ') {
		addData.pop_back();
		i--;
	}
	while (addData[0] == ' ') {
		addData.erase(0, 1);
	}
	return addData;
}

// Function that adds a node to the end of list
void cList::AddNode(string addData) {
	
	nodePtr n = new node;				// Creating a new node 
	n->next = NULL;						// Which will take it's place at the end of list
	n->data = addData;					// Adding data to the node

/* If the list isn't empty then make "current" pointer
   point to the last element of the list
   Once it's done we set the "next" member of our new element as NULL
   and the "prev" as the pointer to the "current"
   Otherwise "head" pointer will point to the new element
   and new element will point nowhere */
	if (head != NULL) {					
		curr = head;					
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = n;
		n->prev = curr;
	}
	else {
		head = n;
		n->prev = NULL;
	}
}

// Function that adds a node to the begining of the list
void cList::AddNodeAsFirst(string addData) {
	nodePtr n = new node;
	n->data = addData;
	n->prev = NULL;
/*  If the list isn't empty then make our new element's "next" member to point to the first element of the list
	the first element's "prev" to point to our new element
	and head to point to our new element
	Otherwise just add a new element as we did before*/
	if (head != NULL) {
		n->next = head;
		head->prev = n;
		head = n;
	}
	else
	{
		head = n;
		n->next = NULL;
	}
}

// Function that adds a node after a desirable one
void cList::AddNodeAfter(string afterData, string addData) {
	
	nodePtr n = new node;								// Creating a new node
	n->data = addData;									// Filling its data member
	curr = head;										// Setting "current" to point to head of the list
/*	Searching through the list for the element after which we are going to add a new one */
	while (curr != NULL && curr->data != afterData){
		curr = curr->next;
	}
/*  Exception if the list doesn't contain desired element */
	if (curr == NULL) {
		cout << "\nElement \"" << afterData << "\" wasn't found in the list\n";
		delete n;
	}
/*	Adding new element */	
	else {
		// Exceptrion if you are adding element to the end of list
		if (curr->next == NULL) {
			curr->next = n;
			n->prev = curr;
			n->next = NULL;
		}
		else {
			temp = curr->next;
			n->prev = curr;
			n->next = temp;
			curr->next = n;
			temp->prev = n;
		}
	}
	}

// Function that deletes the node from the list
void cList::DeleteNode(string delData) {
	
	nodePtr delPtr = NULL;					// Deletion pointer	
	temp = head;							// Setting both pointers to point at the head of the list
	curr = head;	

/*  Searching through the list for the element that is going to be deleted
	Step by step advancing "current" element and leaving "temporary" pointer
	one node behind 
	While we haven't reached the end of the list or found
	the element we were searching for */
	while (curr != NULL && curr->data != delData) {
		temp = curr;
		curr = curr->next;
	}
/*	If we have reached the end of the list and we didn't find desired node
	than we are leaving a statement and cleaning memory
	Otherwise we delete desired node by making the previous one to point to
	the node after the deleting one and then cleaning memory
	           _
	1-2-3 -> 1/2\3 -> 1-3 */
	if (curr == NULL) {
		cout << "\nElement \"" << delData << "\" wasn't found in the list\n";
		delete delPtr;
	}
	else {
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		/* Condition for the case in which the first element was choosen as an element to delete */
		if (delPtr == head) {
			head = head->next;
			temp = NULL;
		}
		delete delPtr;
		cout << "\nThe element \"" << delData << "\" was deleted\n";
	}
}

// Function that deletes all the elements from the list
void cList::Clear() {
/*  Going through the list from the begining to the end deleting one by one each elemet */
	while (head != NULL) {
		curr = head;
		head = head->next;
		delete curr;
	}
	cout << "\nThe list was completely cleared\n";
}

// Function to selection sort a linked list
void cList::Sort() {
	nodePtr i, j;
	string * temporary = new string;
	for(i = head; i->next != NULL; i = i->next)
		for(j = i->next; j!=NULL; j = j->next)
			if (i->data > j->data){
				*temporary = i->data;
				i->data = j->data;
				j->data = *temporary;
			}
	delete temporary;
}


// Function that prints the list
void cList::PrintList() {
	temp = head;
	cout << endl;
	cout << "List: \t";
	cout << "[ ";
/*  Going through the list printing each element */
	while (temp != NULL) {
		cout << '\'' << temp->data << "' ";
		temp = temp->next;
	}
	cout << "]\n\n";
}


bool cList::IsEmpty() {
	return (head == NULL) ? 1 : 0;
}

// Function that shows availible commands
void cList::Help() {
	cout << endl;
	cout << "This is the app that provides you doubly-linked list experience\n";
	cout << "Use these commands to add, delete and sort your list in any way you wish\n\n";
	cout << "add           adds new element to the end of current list\n";
	cout << "addafter      adds new element after any chosen one\n";
	cout << "addfirst      adds new element to the begining of the list\n";
	cout << "delete        deletes any chosen element\n";
	cout << "sort          sorts your list in alphabetic order (yet only works with words)\n";
	cout << "clear         deletes all the elements from the list\n";
	cout << "quit          ends the program\n";
	cout << endl;
	if (head == NULL) cout << "Currently your list is empty. Stop wasting time start using list!\n";
	else cout << "You already have few elements in your list. Don't stop there.\nDream big Achieve bigger\n";
}