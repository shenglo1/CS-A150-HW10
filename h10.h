/**
    @file h10.h
    @author Stephen Gilbert
    @version Declarations for CS 150 Homework
*/
#ifndef H10_H_
#define H10_H_

/**
    Reads C++ (or Java or JavaScript) code and removes the comments.
    Reads from standard input and writes to standard output.
*/
void strip();


/////////// SOME STUFF TO TEST YOUR CODE -- IGNORE PLEASE ////////////////////////
#define CHECK(M, S, E) {\
        ostringstream sout; \
        istringstream sin(S); \
        streambuf* oldIn = cin.rdbuf(); \
        cin.rdbuf(sin.rdbuf()); \
        streambuf* oldOut = cout.rdbuf(); \
        cout.rdbuf(sout.rdbuf()); \
        try { strip(); \
        assertEqualsMsg(M, E, sout.str()); \
        } catch (...) { failMsg("CRASH: " M); } \
        cout.rdbuf(oldOut); \
        cin.rdbuf(oldIn);   \
        }
#endif
