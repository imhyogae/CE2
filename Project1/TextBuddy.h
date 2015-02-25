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
	string fileName;
	char buffer[1000];
	static const std::string MESSAGE_WELCOME;
	static const std::string MESSAGE_ADDED;
	static const std::string MESSAGE_DELETED;
	static const std::string MESSAGE_CLEARED;
	static const std::string MESSAGE_EMPTY;
	static const std::string MESSAGE_SORTED;
	enum COMMAND_TYPE { ADD, DISPLAY, DELETE, CLEAR, SORT, INVALID, EXIT, SEARCH};

	COMMAND_TYPE findCommandType(string currentCommand);
public:	
	TextBuddy();
	TextBuddy(string);
	~TextBuddy();
	string textInFile[1000];
	void displayText(void);
	void displayMessage(string message);
	void writeFile(string message);
	void addText(void);
	void deleteText(void);
	void clearText(void);
	void sortText(void);
	vector<string> searchText(string word);
	void displayWelcome(void);
	void getText(void);
	void executeCommand(string userCommand);
};

#endif
