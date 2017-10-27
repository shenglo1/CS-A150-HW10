/**
    @file h10.cpp
    @author your name here
    @version what day and meeting time
*/
#include <string>
#include <iostream>

// Add additional headers here
using namespace std;

string STUDENT = "ilo";     // Add your name Blackboard/occ-email ID

#include "h10.h"

// Write your function here
void strip()
{
    bool inString = false;
    bool inSingleCmt = false;
    bool inMultiCmt = false;
    
    char ch;
    while (cin.get(ch))
    {
        if (cin && !inSingleCmt && !inMultiCmt)
            cout.put(ch);
        else if (inString && ch == '\\' && cin.peek() == '"')
        {
            cout.put(ch);
            cin.get(ch);
        }
        
        if (inSingleCmt && ch == '\n') inSingleCmt = false;
        
        else if (inString && ch == '"') inString = false;
        else if (inMultiCmt && ch == '*' && cin.peek() == '/')
        {
            cin.get(ch);
            cin.get(ch);
            inMultiCmt = false; // turn off multiline comment mode
        }
        else if (!inString && !inSingleCmt && !inMultiCmt)
        {
            if (ch == '/' && cin.peek() == '*')
                inMultiCmt = true;
            else if (ch == '/' && cin.peek() == '/')
                inSingleCmt = true;
            else if (ch == '"')
                inString = true;
        }
    }
}

