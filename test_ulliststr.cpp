#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
	ULListStr list;
	std::cout << "Populating List with Push Back . . ." << std::endl;
	list.push_back("CSCI_103");
	std::cout << "Pushed Back: " << list.back() << std::endl;
	list.push_back("CSCI_104");
	std::cout << "Pushed Back: " << list.back() << std::endl;
	list.push_back("CSCI_170");
	std::cout << "Pushed Back: " << list.back() << std::endl;
	list.push_back("CSCI_270");
	std::cout << "Pushed Back: " << list.back() << std::endl;

	std::cout << std::endl << "Frontmost Element: " << list.front() << std::endl;
	std::cout << "Popped Back: " << list.back() << std::endl;
	list.pop_back();
    std::cout << "Back Element after Pop Back: " << list.back() << std::endl;
	std::cout << "Popped Back: " << list.back() << std::endl;
	list.pop_back();
    std::cout << "Back Element after Pop Back: " << list.back() << std::endl;
	std::cout << "Popped Back: " << list.back() << std::endl;
	list.pop_back();
    std::cout << "Back Element after Pop Back: " << list.back() << std::endl;
	std::cout << "Popped Back: " << list.back() << std::endl;
	list.pop_back();

	if (list.empty()) {
		std::cout << "List is empty after popping back all elements" << std::endl;
	} else {
		std::cout << "List is not empty after popping back all elements" << std::endl;
	}

	std::cout << std::endl << "Populating List with Push Front . . ." << std::endl;
	list.push_front("CSCI_103");
	std::cout << "Pushed Front: " << list.front() << std::endl;
	list.push_front("CSCI_104");
	std::cout << "Pushed Front: " << list.front() << std::endl;
	list.push_front("CSCI_170");
	std::cout << "Pushed Front: " << list.front() << std::endl;
	list.push_front("CSCI_270");
	std::cout << "Pushed Front: " << list.front() << std::endl;

	std::cout << std::endl << "Backmost Element: " << list.back() << std::endl;
	std::cout << "Popped Front: " << list.front() << std::endl;
	list.pop_front();
    std::cout << "Front Element after Pop Front: " << list.front() << std::endl;
	std::cout << "Popped Front: " << list.front() << std::endl;
	list.pop_front();
    std::cout << "Front Element after Pop Front: " << list.front() << std::endl;
	std::cout << "Popped Front: " << list.front() << std::endl;
	list.pop_front();
    std::cout << "Front Element after Pop Front: " << list.front() << std::endl;
	std::cout << "Popped Front: " << list.front() << std::endl;
	list.pop_front();

	if (list.empty()) {
		std::cout << "List is empty after popping front all elements" << std::endl;
	} else {
		std::cout << "List is not empty after popping front all elements" << std::endl;
	}
}
