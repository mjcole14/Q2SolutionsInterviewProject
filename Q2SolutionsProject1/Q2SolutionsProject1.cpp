// Q2SolutionsProject1.cpp : 
//
// Description: 
// Defines the entry point for the console application. 
// This project satifies the coding portion of the employment application test for Q2 Solutions. 
// It includes an application to parse an input string as well as unit testing for this applicaton.
//
// Author:	Michael Cole	
// Date:	09/01/2018


#include "stdafx.h"
#include "TestParseString.h"


int main()
{
	// Create test class for ParseString
	TestParseString tps;
	cout << "Running all test cases: Start" << endl << endl;

	//Run all ParseString unit test cases 
	tps.runAllTests();

	cout << "Running all test cases: Complete" << endl;

    return 0;
}

