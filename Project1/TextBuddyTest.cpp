#include "TextBuddyTest.h"


TextBuddyTest::TextBuddyTest(void)
{
}


TextBuddyTest::~TextBuddyTest(void)
{
}

void testExecuteUserCommand(){
	assertEquals("add little brown fox","added to mytestfile.txt: 'little brown fox'",TextBuddy.main());
}