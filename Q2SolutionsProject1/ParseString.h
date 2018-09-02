//ParseString.h :  
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


#pragma once
#include <string>

using namespace std;

class ParseString
{
private:
	//Input
	string str;

	//Calculated values
	int aCount = 0;
	int cCount = 0;
	int gCount = 0;
	int tCount = 0;
	int otherCharCount = 0;
	int largestASequence = 0;
	int largestCSequence = 0;
	int largestGSequence = 0;
	int largestTSequence = 0;
	float percentA = 0.0;
	float percentC = 0.0;
	float percentG = 0.0;
	float percentT = 0.0;
	float percentOther = 0.0;




public:
	ParseString(const string &inStr);
	
	~ParseString();

private:
	void parse();

public:
	//Getters and Setters for attribute values
	string getString()
	{
		return str;
	}

	int getACount()
	{
		return aCount;
	}

	void setACount(int aCnt)
	{
		aCount = aCnt;
	}

	int getCCount()
	{
		return cCount;
	}

	void setCCount(int cCnt)
	{
		cCount = cCnt;
	}

	int getGCount()
	{
		return gCount;
	}

	void setGCount(int gCnt)
	{
		gCount = gCnt;
	}

	int getTCount()
	{
		return tCount;
	}

	void setTCount(int tCnt)
	{
		tCount = tCnt;
	}

	int getOtherCharCount()
	{
		return otherCharCount;
	}

	void setOtherCharCount(int otherCnt)
	{
		otherCharCount = otherCnt;
	}

	int getLargestASequence()
	{
		return largestASequence;
	}

	void setLargestASequence(int largestASeq)
	{
		largestASequence = largestASeq;
	}

	int getLargestCSequence()
	{
		return largestCSequence;
	}

	void setLargestCSequence(int largestCSeq)
	{
		largestCSequence = largestCSeq;
	}

	int getLargestGSequence()
	{
		return largestGSequence;
	}

	void setLargestGSequence(int largestGSeq)
	{
		largestGSequence = largestGSeq;
	}

	int getLargestTSequence()
	{
		return largestTSequence;
	}

	void setLargestTSequence(int largestTSeq)
	{
		largestTSequence = largestTSeq;
	}
	
	float getPercentA()
	{
		return percentA;
	}

	void setPercentA(float pctA)
	{
		percentA = pctA;
	}

	float getPercentC()
	{
		return percentC;
	}

	void setPercentC(float pctC)
	{
		percentC = pctC;
	}

	float getPercentG()
	{
		return percentG;
	}

	void setPercentG(float pctG)
	{
		percentG = pctG;
	}

	float getPercentT()
	{
		return percentT;
	}

	void setPercentT(float pctT)
	{
		percentT = pctT;
	}

	float getPercentOther()
	{
		return percentOther;
	}

	void setPercentOther(float pctOther)
	{
		percentOther = pctOther;
	}


};

