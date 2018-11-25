#include "cList.h"

void except();
void clearspaces(string& command);

int main() {
	int index;
	cList list;
	string command;
	cout << "\n\nLinkedList application welcomes you\n";
	cout << "Type help to see available commands\n";
	while (1) {
		cout << "> "; getline(cin, command);
		clearspaces(command);
		if (command == "help") {
			list.Help();
			list.PrintList("");
		}
		else if (command == "add") {
			cout << "\nType new element you'd like to add\n\n";
			cout << "> "; list.AddNode(list.getNode());
			list.PrintList("");
		}
		else if (command == "addafter") {
			if (list.IsEmpty()) {
				except();
			}
			else {
				cout << "\nAfter which element would you like to add yours?\n\n";
				cout << "> "; getline(cin, command);
				cout << "\nType new element you'd like to add\n\n";
				cout << "> "; list.AddNodeAfter(command, list.getNode());
			}
			list.PrintList("");
		}
		else if (command == "addfirst") {
			cout << "\nType new element you'd like to add\n\n";
			cout << "> "; list.AddNodeAsFirst(list.getNode());
			list.PrintList("");
		}
		else if (command == "delbydata") {
			if (list.IsEmpty()) {
				except();
			}
			else {
				cout << "\nWhich element would you like to delete?\n\n";
				cout << "> "; list.DeleteNodeByData(list.getNode());
			}
			list.PrintList("");
		}
		else if (command == "delbyind") {
			if (list.IsEmpty()) {
				except();
			}
			else {
				list.PrintList("ind");
				cout << "\n\nType index\n";
				cout << "> "; cin >> index;
				list.DeleteNodeByIndex(index);
				cin.clear(); cin.ignore(INT_MAX, '\n');
			}
			list.PrintList("");
		}
		else if (command == "pop") {
			if (list.IsEmpty()) {
				except();
			}
			else {
				list.Pop();
			}
			list.PrintList("");
		}
		else if (command == "sort") {
			if (list.IsEmpty()) {
				except();
			}
			else {
				list.Sort();
				cout << "\nThe list has been sorted\n\n";
			}
			list.PrintList("");
		}
		else if (command == "clear") {
			if (list.IsEmpty()) {
				except();
			}
			else {
			list.Clear();
			cout << "\nThe list was completely cleared\n\n";
			}
			list.PrintList("");
		}
		else if (command == "quit") {
			return 0;
		}
		else {
			cout << "\nThere is no such command. Try again or use help to see available commands\n\n";
		}
	}
}

/*  Function that displays exception message */
void except() {
	cout << "\nThere are no elements yet in the List. At first add something\n";
}

/*  Functions that checks input for unnecessary spaces and cleares them
	if input is empty transforms it into string with space
	Parameter -> string from input */
void clearspaces(string& command) {
	int* i = new int;
	if (command != "") {
		*i = command.length() - 1;
		while (command[*i] == ' ' && *i > 0) {
			command.pop_back();
			*i = *i - 1;
		}
		while (command[0] == ' ') {
			command.erase(0, 1);
		}
	}
	else command = " ";
	delete i;
}