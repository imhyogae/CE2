//By Ren Xiaokai A0116455
//The following solution allows user to define a file to store the text to be added
//Each text is added immediately after a user action that make modification to the file

#include "TextBuddy.h"

	const string TextBuddy::MESSAGE_WELCOME = "Welcome to TextBuddy. %s is ready for use";
	const string TextBuddy::MESSAGE_ADDED = "added to %s: \"%s\"";
	const string TextBuddy::MESSAGE_DELETED = "deleted from %s: \"%s\"";
	const string TextBuddy::MESSAGE_CLEARED = "all content deleted from %s";
	const string TextBuddy::MESSAGE_EMPTY = "%s is empty";
	const string TextBuddy::MESSAGE_SORTED = "%s has been sorted";

TextBuddy::TextBuddy(string inputFileName){
	fileName=inputFileName;
}
TextBuddy::TextBuddy(void) {
}
TextBuddy::~TextBuddy(void) {
}

void TextBuddy::executeCommand(string userCommand){
	COMMAND_TYPE command=findCommandType(userCommand);

	switch (command) {
	case ADD:
			return addText();
	case DISPLAY:
			return displayText();
	case DELETE:
			return deleteText();
	case CLEAR:
			return clearText();
	case SORT:
			return sortText();
	case SEARCH:
			{	string word;
				cin >> word;
				vector<string> linesFound = searchText(word);
				return;
			}
	case INVALID:
			cout << "invalid command" << endl;
			return;
	case EXIT:
			return; 
	}
}
TextBuddy::COMMAND_TYPE TextBuddy::findCommandType(string currentCommand){

		if (currentCommand == "add"){
			return ADD;
		}
		else if (currentCommand == "display"){
			return DISPLAY;
		}
		else if (currentCommand == "delete"){
			return DELETE;
		} 
		else if (currentCommand == "clear"){
			return CLEAR;
		}
		else if (currentCommand == "sort"){
			return SORT;
		}
		else if (currentCommand == "search"){
			return SEARCH;
		}
		else if (currentCommand != "exit"){
			return INVALID;
		}
		else return EXIT;
}

void TextBuddy::addText(void){
	string firstWord;
	string remainingWords;
	string wholePhrase;
	cin >> firstWord;
	getline(cin, remainingWords);
	wholePhrase = firstWord + remainingWords;
	sprintf_s(buffer, MESSAGE_ADDED.c_str(), fileName.c_str(), wholePhrase.c_str());
	displayMessage(buffer);
	writeFile(wholePhrase);

}

void TextBuddy::clearText(void){
	ofstream outputFile;
	outputFile.open(fileName);
	outputFile.close();

	sprintf_s(buffer, MESSAGE_CLEARED.c_str(), fileName.c_str());
	displayMessage(buffer);

}
vector<string> TextBuddy::searchText(string word)
{
	ifstream ifsFile;
	string currentLine;
	vector<string> textFound;
	ifsFile.open(fileName);
	while (getline(ifsFile, currentLine)){
		if (string::npos != currentLine.find(word))
			textFound.push_back(currentLine);
	}
	ifsFile.close();

	return textFound;
}

void TextBuddy::deleteText(void){
	int index;
	cin >> index;
	vector<string> textInFile;
	string currentLine;
	string deletedLine;
	ifstream ifsFile;
	ofstream outputFile;

	ifsFile.open(fileName);
	while (getline(ifsFile, currentLine)){
		textInFile.push_back(currentLine);
	}

	ifsFile.close();
	outputFile.open(fileName);

	for (unsigned int i = 0; i < textInFile.size(); i++){
		if (i == index - 1){
			deletedLine = textInFile[i];
		}
		else {
			outputFile << textInFile[i] << endl;
		}
	}
	outputFile.close();

	sprintf_s(buffer, MESSAGE_DELETED.c_str(), fileName.c_str(), deletedLine.c_str());
	displayMessage(buffer);

}

void TextBuddy::displayText(void){
	ifstream textFile;
	string currentLine;

	textFile.open(fileName);
	int i;
	for (i = 1; getline(textFile, currentLine); i++){
		cout << i << "." <<currentLine <<endl;
	}

	if (i == 1 ){
		sprintf_s(buffer, MESSAGE_EMPTY.c_str(), fileName.c_str());
		displayMessage(buffer);
		return;
	}
	textFile.close();

}

void TextBuddy::displayWelcome(void){
	sprintf_s(buffer, MESSAGE_WELCOME.c_str(), fileName.c_str());
	displayMessage(buffer);
	}
void TextBuddy::displayMessage(string message) {
	cout << message << endl;
		
}

void TextBuddy::writeFile(string message){
	ofstream destination;

	destination.open(fileName, ofstream::app);
	destination << message << endl;
	destination.close();

}
void TextBuddy::getText(void){
	ifstream textFile;
	string currentLine;
	textFile.open(fileName);
	int i=0;
	while(getline(textFile,currentLine)){
		textInFile[i] = currentLine;
		i++;
	}
	textFile.close();
}

void TextBuddy::sortText(void){
	ifstream textFile;
	ofstream outputFile;
	string currentLine;
	vector<string> tempVector;

	textFile.open(fileName);
	
	while(getline(textFile,currentLine)){
		tempVector.push_back(currentLine);
	}
	sort(tempVector.begin(), tempVector.end());

	outputFile.open(fileName);

	for (unsigned int i = 0; i < tempVector.size(); i++){
			outputFile << tempVector[i] << endl;
		}
	outputFile.close();

	sprintf_s(buffer, MESSAGE_SORTED.c_str(), fileName.c_str());
	displayMessage(buffer);
	}

	



