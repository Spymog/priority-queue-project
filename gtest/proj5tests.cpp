#include <vector>
#include <gtest/gtest.h>
#include <fstream>
#include "proj5.hpp"
#include "../include/ver.hpp"
#include "MyPriorityQueue.hpp"
#include <string>
namespace{

// As always, this is a STARTING POINT of test cases
	// and is not an exhaustive set of test cases.
	// You should be sure to test EVERY function of 
	// your priority queue as well as the Lewis Carroll puzzle.



TEST(SampleTests, SimplePQ)
{
	MyPriorityQueue<int> mpq;
	mpq.insert(3);
	EXPECT_EQ(mpq.min(), 3);
}


TEST(SampleTests, SimplePQ2)
{
	MyPriorityQueue<int> mpq;
	mpq.insert(8);
	mpq.insert(5);
	mpq.insert(3);
	mpq.insert(6);
	mpq.insert(2);
	EXPECT_EQ(mpq.min(), 2);
	mpq.extractMin();
	EXPECT_EQ(mpq.min(), 3);
	mpq.extractMin();
	EXPECT_EQ(mpq.min(), 5);
	mpq.extractMin();	
	EXPECT_EQ(mpq.min(), 6);
	mpq.extractMin();	
	EXPECT_EQ(mpq.min(), 8);
}

TEST(SampleTests, proj5HelperFunc1)
{
	std::string a = "ant";
	std::string b = "act";

	EXPECT_TRUE(isAdjacent(a, b));
	EXPECT_EQ(optimisticEstimate(a, b), 1);
}



TEST(SampleTests, AntToEat)
{
	std::string WORD_ONE = "ant";
	std::string WORD_TWO = "eat";
	auto CORRECT_LENGTH = 5;


	std::unordered_set<std::string> words;
	std::ifstream in("words.txt");
	loadWordsIntoTable(words, in);


 	std::vector< std::string > r = convert(WORD_ONE, WORD_TWO, words);

	std::ifstream in2("words.txt");

 	EXPECT_EQ(r.size(), CORRECT_LENGTH);
 	EXPECT_TRUE(  validConversion(r, WORD_ONE, WORD_TWO, in2) );
}


TEST(SampleTests, PuttersToHampers)
{
	std::string WORD_ONE = "putters";
	std::string WORD_TWO = "hampers";
	auto CORRECT_LENGTH = 14;


	std::unordered_set<std::string> words;
	std::ifstream in("words.txt");
	loadWordsIntoTable(words, in);


 	std::vector< std::string > r = convert(WORD_ONE, WORD_TWO, words);
	
	std::string a;

	for (auto i = r.begin(); i != r.end(); i++)
	{
		a += " " + *i;
	}

	std::cout << a << std::endl;
	
	std::ifstream in2("words.txt");

 	EXPECT_EQ(r.size(), CORRECT_LENGTH);
 	EXPECT_TRUE(  validConversion(r, WORD_ONE, WORD_TWO, in2) );
}


/*
TEST(SampleTests, BankingToBrewing)
{
	std::string WORD_ONE = "banking";
	std::string WORD_TWO = "brewing";
	auto CORRECT_LENGTH = 15;


	std::unordered_set<std::string> words;
	std::ifstream in("words.txt");
	loadWordsIntoTable(words, in);


 	std::vector< std::string > r = convert(WORD_ONE, WORD_TWO, words);

	std::ifstream in2("words.txt");

 	EXPECT_EQ(r.size(), CORRECT_LENGTH);
 	EXPECT_TRUE(  validConversion(r, WORD_ONE, WORD_TWO, in2) );
}






TEST(SampleTests, ChangesToGlasses)
{
	std::string WORD_ONE = "changes";
	std::string WORD_TWO = "glasses";
	auto CORRECT_LENGTH = 48;


	std::unordered_set<std::string> words;
	std::ifstream in("words.txt");
	loadWordsIntoTable(words, in);


 	std::vector< std::string > r = convert(WORD_ONE, WORD_TWO, words);

	std::ifstream in2("words.txt");

 	EXPECT_EQ(r.size(), CORRECT_LENGTH);
 	EXPECT_TRUE(  validConversion(r, WORD_ONE, WORD_TWO, in2) );
}




TEST(SampleTests, ChangesToSmashed)
{
	std::string WORD_ONE = "changes";
	std::string WORD_TWO = "smashed";
	auto CORRECT_LENGTH = 48;


	std::unordered_set<std::string> words;
	std::ifstream in("words.txt");
	loadWordsIntoTable(words, in);


 	std::vector< std::string > r = convert(WORD_ONE, WORD_TWO, words);

	std::ifstream in2("words.txt");

 	EXPECT_EQ(r.size(), CORRECT_LENGTH);
 	EXPECT_TRUE(  validConversion(r, WORD_ONE, WORD_TWO, in2) );
}


TEST(SampleTests, BoostedToClasses)
{
	std::string WORD_ONE = "boosted";
	std::string WORD_TWO = "classes";
	auto CORRECT_LENGTH = 44;


	std::unordered_set<std::string> words;
	std::ifstream in("words.txt");
	loadWordsIntoTable(words, in);


 	std::vector< std::string > r = convert(WORD_ONE, WORD_TWO, words);

	std::ifstream in2("words.txt");

 	EXPECT_EQ(r.size(), CORRECT_LENGTH);
 	EXPECT_TRUE(  validConversion(r, WORD_ONE, WORD_TWO, in2) );
}
*/







}