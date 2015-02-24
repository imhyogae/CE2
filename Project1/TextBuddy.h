#ifndef TEXTBUDDY_H_
#define TEXTBUDDY_H_

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class TextBuddy {
private:
	char buffer[1000];
	static const std::string MESSAGE_WELCOME;
	static const std::string MESSAGE_ADDED;
	static const std::string MESSAGE_DELETED;
	static const std::string MESSAGE_CLEARED;
	static const std::string MESSAGE_EMPTY;
	static const std::string MESSAGE_SORTED;
	enum COMMAND_TYPE { ADD, DISPLAY, DELETE, CLEAR, SORT, INVALID, EXIT};

	COMMAND_TYPE findCommandType(string currentCommand);
	
	void displayText(string fileName);
	void displayMessage(string message);
	void writeFile(string message, string fileName);
	void addText(string fileName);
	void deleteText(string fileName);
	void clearText(string fileName);
	void sortText(string fileName);

public:
	TextBuddy();
	~TextBuddy();
	void displayWelcome(string fileName);
	void executeCommand(string userCommand, string fileName);
};

#endif
