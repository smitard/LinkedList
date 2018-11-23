#include "cList.h"

void except();

int main() {
	
	system("color f0");
	cList list;
	string command;
	cout << "Type help to see available commands\n";
	while (1) {
		cout << "> "; getline(cin, command);
		if (command == "help") {
			list.Help();
			list.PrintList();
		}
		else if (command == "add") {
			cout << "\nWhich element would you like to add?\n\n";
			cout << "> "; list.AddNode(list.getNode());
			list.PrintList();
		}
		else if (command == "addafter") {
			if (list.IsEmpty()) {
				except();
			}
			else {
				cout << "\nAfter which element would you like to add yours?\n\n";
				cout << "> "; getline(cin, command);
				cout << "\nWhat would you like to add?\n\n";
				cout << "> "; list.AddNodeAfter(command, list.getNode());
			}
			list.PrintList();
		}
		else if (command == "addfirst") {
			cout << "\nWhich element would you like to add?\n\n";
			cout << "> "; list.AddNodeAsFirst(list.getNode());
			list.PrintList();
		}
		else if (command == "delete") {
			if (list.IsEmpty()) {
				except();
			}
			else {
				cout << "\nWhich element would you like to delete?\n\n";
				cout << "> "; list.DeleteNode(list.getNode());
			}
			list.PrintList();
		}
		else if (command == "sort") {
			if (list.IsEmpty()) {
				except();
			}
			else {
				list.Sort();
			}
			list.PrintList();
		}
		else if (command == "clear") {
			if (list.IsEmpty()) {
				except();
			}
			else {
			list.Clear();
			}
			list.PrintList();
		}
		else if (command == "quit") {
			return 0;
		}
		else cout << "\nThere is no such command. Try again or use help to see available commands\n\n";
	}
}

void except() {
	cout << "\nThere are no elements yet. At first add something\n";
}