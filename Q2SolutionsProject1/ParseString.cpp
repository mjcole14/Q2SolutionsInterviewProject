//ParseString.ccp :  
//
//Author: 	Michael Cole	
//Date:	09/01/2018
//
//Description:  
//Accepts as input a string to be parsed and calculates a set of results after parsing the input string.
//
//Input:
//string str : Input string to parse
//
//Calculated attibutes:
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
// 


#include "stdafx.h"
#include "ParseString.h"


ParseString::ParseString(const string &inStr)
	: str(inStr)
{
	parse();
}

ParseString::~ParseString()
{
}

//Parses the input string
void ParseString::parse()
{
	int strLen = str.length();
	int letterCount = 0;

	//Parse only non empty strings
	if (strLen >= 1)
	{

		int aSeqCurCount = 0;
		int cSeqCurCount = 0;
		int gSeqCurCount = 0;
		int tSeqCurCount = 0;

		char current;
		char last = ' ';

		//Examine each character in the string and add to appropriate counts
		for (int i = 0; i < strLen; i++)
		{
			//Get next char and ignore if it is not a valid letter
			current = str.at(i);
			if (current >= 'a' && current <= 'z' || current >= 'A' && current <= 'Z')
			{ 
				//Ignore case of character
				current = tolower(current);

				//Count each type of letter
				letterCount++;
				switch (current) {
				case 'a':
					aCount++;

					//Look for longest sequences
					if (last == current) {
						aSeqCurCount++;
					}
					else {
						aSeqCurCount = 1;
					}

					if (aSeqCurCount > largestASequence) {
						largestASequence = aSeqCurCount;
					}

					break;

				case 'c':
					cCount++;

					//Look for longest sequences
					if (last == current) {
						cSeqCurCount++;
					}
					else {
						cSeqCurCount = 1;
					}

					if (cSeqCurCount > largestCSequence) {
						largestCSequence = cSeqCurCount;
					}

					break;

				case 'g':
					gCount++;

					//Look for longest sequences
					if (last == current) {
						gSeqCurCount++;
					}
					else {
						gSeqCurCount = 1;
					}

					if (gSeqCurCount > largestGSequence) {
						largestGSequence = gSeqCurCount;
					}

					break;

				case 't':
					tCount++;

					//Look for longest sequences
					if (last == current) {
						tSeqCurCount++;
					}
					else {
						tSeqCurCount = 1;
					}

					if (tSeqCurCount > largestTSequence) {
						largestTSequence = tSeqCurCount;
					}

					break;

				default:
					otherCharCount++;
					break;
				}

				//Remember last letter to look for longest sequences
				last = current;
			} 
		}

		//Calculate the percentages of letter type found
		percentA = ((float)aCount / (float)letterCount) * 100;
		percentC = ((float)cCount / (float)letterCount) * 100;
		percentG = ((float)gCount / (float)letterCount) * 100;
		percentT = ((float)tCount / (float)letterCount) * 100;
		percentOther = ((float)otherCharCount / (float)letterCount) * 100;

	}

}
