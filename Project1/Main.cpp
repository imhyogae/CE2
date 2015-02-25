#include <iostream>
#include "TextBuddy.h"


int main(void)
{
	string userCommand;
	string fileName="mytestfile.txt";
	TextBuddy textBuddy(fileName);

	textBuddy.displayWelcome();

	
	do {
		cout << "command: " <<endl;
		cin >> userCommand;
		textBuddy.executeCommand(userCommand);
	}
	while (userCommand != "exit");
	
	return 0;	
}