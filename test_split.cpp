/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
using namespace std;

#include "split.h"
#include <iostream>

int main(int argc, char* argv[])
{
	Node* linkedlist = new Node(1, nullptr);
	Node* curr = linkedlist;

  	for (int i = 2 ; i <= 10; i++) {
		curr->next = new Node(i, nullptr);
		curr = curr->next;
  	}

	Node* evenlist = nullptr;
	Node* oddlist = nullptr;

	curr = linkedlist;
	cout << "Original List: ";
	while(curr != nullptr) {
		cout << curr->value << ", ";
		curr = curr->next;
	}
	cout << endl;

	split(linkedlist, oddlist, evenlist);

	curr = evenlist;
	cout << "Even List: ";
	while(curr != nullptr) {
		cout << curr->value << ", ";
		curr = curr->next;
	}
	cout << endl;

	curr = oddlist;
	cout << "Odd List: ";
	while(curr != nullptr) {
		cout << curr->value << ", ";
		curr = curr->next;
	}
	cout << endl;

	while(oddlist != nullptr) {
		Node* temp = oddlist;
		oddlist = oddlist->next;
		delete temp;
	}
	while(evenlist != nullptr) {
		Node* temp = evenlist;
		evenlist = evenlist->next;
		delete temp;
	}


	Node* emptyList = nullptr;
	Node* oddResult = nullptr;
	Node* evenResult = nullptr;

	split(emptyList, oddResult, evenResult);
	cout << "Testing empty input list: " << emptyList << endl << "Odd List: " << oddResult << endl << "Even List: " << evenResult << endl;
}
