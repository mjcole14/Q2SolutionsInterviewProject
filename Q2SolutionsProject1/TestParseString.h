// TestParseString.h :  
//
// Description:  
// Unit Test Suite for ParseString class. 
//
// Author: 	Michael Cole	
// Date:	09/01/2018

#pragma once

#include <iostream>
#include <string>
#include "ParseString.h"

using namespace std;

class TestParseString
{

public:
	TestParseString();

	~TestParseString();

	void runAllTests();

	//Test1 accepts as input a string to be parsed as well as a set of 
	//expected results for the given input string. It then calls ParseString 
	//and verfies the calulated results from the app against the expected 
	//results. Failures are reported to standard output.
	//
	//Attibutes:
	//string str : Input string to parse
	//int aCount : Number of letter A's found in the input string (case insensitive)
	//int cCount : Number of letter C's found in the input string (case insensitive) 
	//int gCount : Number of letter G's found in the input string (case insensitive) 
	//int tCount : Number of letter T's found in the input string (case insensitive) 
	//int otherCharCount :  Number of letters that are not A, C, G or T found in the input string (case insensitive)
	//int largestASequence : Largest string of A's in a row in the input string
	//int largestCSequence : Largest string of C's in a row in the input string
	//int largestGSequence : Largest string of G's in a row in the input string
	//int largestTSequence : Largest string of F's in a row in the input string
	//float percentA : Percentage of A's in the input string.
	//float percentC : Percentage of C's in the input string.
	//float percentG : Percentage of G's in the input string.
	//float percentT : Percentage of T's in the input string.
	//float percentOther : Percentage of letters in the input string that are not A, C, G or T.

	void Test1(
		string str,
		int aCount, 
		int cCount, 
		int gCount, 
		int tCount, 
		int otherCharCount, 
		int largestASequence, 
		int largestCSequence, 
		int largestGSequence, 
		int largestTSequence, 
		float percentA, 
		float percentC, 
		float percentG, 
		float percentT,
		float percentOther);

private:
	string testString;
	int testCase = 0;

};

