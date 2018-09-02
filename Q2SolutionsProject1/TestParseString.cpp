// TestParseString.ccp :  
//
// Description:  
// Unit Test Suite for ParseString class.
//
// Author: 	Michael Cole	
// Date:	09/01/2018

#include "stdafx.h"
#include <assert.h>
#include "TestParseString.h"



TestParseString::TestParseString()
{
}

TestParseString::~TestParseString()
{
}

void TestParseString::runAllTests()
{
	//All letters
	testCase = 1;
	Test1("abcdefghijklmnopqrstuvwxyz", 1, 1, 1, 1, 22, 1, 1, 1, 1, 3.84615397, 3.84615397, 3.84615397, 3.84615397, 84.6153870);

	//Multiple special letters lower case
	testCase = 2;
	Test1("abbcegtaabcccdggggetttttf", 3, 4, 5, 6, 7, 2, 3, 4, 5, 12.0, 16.0, 20.0, 24.0, 28.0);

	//Multiple special letters upper case
	testCase = 3;
	Test1("abbcegtAAbCCCdGGGGETTTTTf", 3, 4, 5, 6, 7, 2, 3, 4, 5, 12.0, 16.0, 20.0, 24.0, 28.0);

	//Ignore non-letters
	testCase = 4;
	Test1("a aa b c d,t, t, t", 3, 1, 0, 3, 2, 3, 1, 0, 3, 33.3333, 11.1111, 0.0, 33.3333, 22.2222);

	//Single non-special letter
	testCase = 5;
	Test1("bbbb", 0, 0, 0, 0, 4, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, 100.0);

	//Single special letter mixed case
	testCase = 6;
	Test1("aAaAaa", 6, 0, 0, 0, 0, 6, 0, 0, 0, 100.0, 0.0, 0.0, 0.0, 0.0);

	//Empty string
	testCase = 7;
	Test1("", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0);

}

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
void TestParseString::Test1(
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
	float percentOther)
{

	cout << "Running test suite Test1 on: " << str << endl;

	bool testPassed = true;

	ParseString ps = ParseString(str);

	//Verify all calculated attibutes

	//Verify letter counts
	int attributeCount = 1;
	if (ps.getACount() != aCount) {
		cout << "Test1-" << testCase << "-" << attributeCount << " FAIL: A Count = " << ps.getACount() << " expected " << aCount << endl;
		testPassed = false;
	}

	attributeCount++;
	if (ps.getCCount() != cCount) {
		cout << "Test1-" << testCase << "-" << attributeCount << " FAIL: C Count = " << ps.getCCount() << " expected " << cCount << endl;
		testPassed = false;
	}

	attributeCount++;
	if (ps.getGCount() != gCount) {
		cout << "Test1-" << testCase << "-" << attributeCount << " FAIL: G Count = " << ps.getGCount() << " expected " << gCount << endl;
		testPassed = false;
	}

	attributeCount++;
	if (ps.getTCount() != tCount) {
		cout << "Test1-" << testCase << "-" << attributeCount << " FAIL: T Count = " << ps.getTCount() << " expected " << tCount << endl;
		testPassed = false;
	}

	//Verify largest sequences
	attributeCount++;
	if (ps.getLargestASequence() != largestASequence) {
		cout << "Test1-" << testCase << "-" << attributeCount << " FAIL: largest A Sequence = " << ps.getLargestASequence() << " expected " << largestASequence << endl;
		testPassed = false;
	}

	attributeCount++;
	if (ps.getLargestCSequence() != largestCSequence) {
		cout << "Test1-" << testCase << "-" << attributeCount << " FAIL: largest C Sequence = " << ps.getLargestCSequence() << " expected " << largestCSequence << endl;
		testPassed = false;
	}

	attributeCount++;
	if (ps.getLargestGSequence() != largestGSequence) {
		cout << "Test1-" << testCase << "-" << attributeCount << " FAIL: largest G Sequence = " << ps.getLargestGSequence() << " expected " << largestGSequence << endl;
		testPassed = false;
	}

	attributeCount++;
	if (ps.getLargestTSequence() != largestTSequence) {
		cout << "Test1-" << testCase << "-" << attributeCount << " FAIL: largest T Sequence = " << ps.getLargestTSequence() << " expected " << largestTSequence << endl;
		testPassed = false;
	}

	//Validating float values to 2 decimal places. Calculations may 
	//vary by machine. This value is used to allow for a range of
	//values past the second decimal point.
	float roundingDiff = 0.001;

	//Validating percentage values to 2 decimal places
	attributeCount++;
	if (ps.getPercentA() < percentA - roundingDiff || ps.getPercentA() > percentA + roundingDiff) {
		cout << "Test1-" << testCase << "-" << attributeCount << " FAIL: percentage of A values = " << ps.getPercentA() << " expected " << percentA << endl;
		testPassed = false;
	}

	attributeCount++;
	if (ps.getPercentC() < percentC - roundingDiff || ps.getPercentC() > percentC + roundingDiff) {
		cout << "Test1-" << testCase << "-" << attributeCount << " FAIL: percentage of C values = " << ps.getPercentC() << " expected " << percentC << endl;
		testPassed = false;
	}

	attributeCount++;
	if (ps.getPercentG() < percentG - roundingDiff || ps.getPercentG() > percentG + roundingDiff) {
		cout << "Test1-" << testCase << "-" << attributeCount << " FAIL: percentage of G values = " << ps.getPercentG() << " expected " << percentG << endl;
		testPassed = false;
	}

	attributeCount++;
	if (ps.getPercentT() < percentT - roundingDiff || ps.getPercentT() > percentT + roundingDiff) {
		cout << "Test1-" << testCase << "-" << attributeCount << " FAIL: percentage of T values = " << ps.getPercentT() << " expected " << percentT << endl;
		testPassed = false;
	}

	attributeCount++;
	if (ps.getPercentOther() < percentOther - roundingDiff || ps.getPercentOther() > percentOther + roundingDiff) {
		cout << "Test1-" << testCase << "-" << attributeCount << " FAIL: percentage of Other values = " << ps.getPercentOther() << " expected " << percentOther << endl;
		testPassed = false;
	}

	if (testPassed) {
		cout << "PASSED" << endl;
	}
	cout << endl;
}
