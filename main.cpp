/**
 *  @author Stephen Gilbert
 *  @version CS 150 homework testing
 *  @file main.cpp
 */

#include <iostream>
#include <string>
using namespace std;

#include "cs150check.h"
#include "h10.h"

/**
 * Run your program's tests
 */
void runTests()
{
    ///////////// Begin a set of tests
    beginTests(); // test heading

    /////// Tests for //////////////////////
    beginFunctionTest("Checking the strip function.");

    CHECK(  "Check single-line comment",
            "#include <iostream> // standard streams\n#include <string> // standard string class\n",
            "#include <iostream> /#include <string> /");

    // Test 2 - don't delete a comment embedded in a string
    CHECK(  "Check string-embedded comment.",
            "    cout << \"/* this is ok \" << endl;",
            "    cout << \"/* this is ok \" << endl;");

    // Test 3 - Ignore strings in comments; keep newlines at end of single-line comment.
    CHECK(  "Check single, multi-line comments.",
            "// Single line comment should be deleted\n"
            "/* Multi-line comment should be deleted\n"
            "// Not really a comment\n  "
            "\"Not really a string\"    *****/\n"
            "#include <iostream>  // Single line comment should be deleted\n",
            "//#include <iostream>  /");

    // Test 4 - don't delete a comment embedded in a string
    CHECK(  "Check string-embedded comment II.",
            "char * s = \"Some text /* with an embedded */ // comment \";",
            "char * s = \"Some text /* with an embedded */ // comment \";");

    // Test 5 - comment embedded in code
    CHECK(  "Check single-line embedded comment.",
            "int main(int argc /* argument count */, argv[] /* strings */)",
            "int main(int argc / argv[] /");

    // Test 6 - comment embedded in code
    CHECK(  "String, then multi, then string.",
            "string s = \"\\\"hello\\\"\"; /* cmt1 */ string s2 = \"bye\"; /* cmt2 */",
            "string s = \"\\\"hello\\\"\"; /string s2 = \"bye\"; /");

    // Test 7 - escaped quotes in a string
    CHECK(  "Some escaped quotes in a string.",
            "string s = \"\\\"/",
            "string s = \"\\\"/");

    endFunctionTest(); // end

    endTests();
}

