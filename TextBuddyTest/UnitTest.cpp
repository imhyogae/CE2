//Since other functions has been tested, I only use TDD to write sort and search function.

#include "stdafx.h"
#include "CppUnitTest.h"
#include <assert.h>
#include "TextBuddy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

std::string fileName = "mytestfile.txt";

const std::string wordtobeFound = "debug";

namespace TextBuddyTest
{
	TEST_CLASS(sortText)
	{
	public:
		
		TEST_METHOD(isSorted){
			TextBuddy testing(fileName);
			std::string expecteOutput[7] = {    "CE2 is so hard.",
												"Hello World!",
												"Hey you sister.",
												"How to do unit testing?",	
												"I can't debug my program.",
												"I do not like debugging.",
												"I have a dream.",
			};

			testing.sortText();
			testing.getText();
			
			for(int i = 0; i<6; i++){
				Assert::AreEqual(expecteOutput[i],testing.textInFile[i]);
			}
		}
	};

	TEST_CLASS(searchWord){
	
	public:
		TEST_METHOD(searchTheWord){
			TextBuddy testing(fileName);
			string expected[2] = {	"I can't debug my program.",
									"I do not like debugging."	,				
			};
			vector<string> searchResult;
			searchResult = testing.searchText(wordtobeFound);
			unsigned int i=0;
			while(i < searchResult.size()){
				Assert::AreEqual(expected[i],searchResult[i]);
				i++; 
				}	
		}
	};

}