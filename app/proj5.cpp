#include "proj5.hpp"
#include <string>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <utility>
#include "MyPriorityQueue.hpp"
#include <iostream>
#include <fstream>

// You should not need to change this function.
void loadWordsIntoTable(std::unordered_set<std::string> & words, std::istream & in)
{
	std::string line, word;
	std::stringstream ss;

	while(	getline(in, line) )
	{
		ss.clear();
		ss << line;
		while( ss >> word )
		{
			words.insert( word );
		}
	}

}

bool isAdjacent(const std::string& s1, const std::string& s2)
{
    unsigned int l1 = s1.length(), l2 = s2.length();
    
    if (l1 - l2 != 0)
    {
        return false;
    }   
    
    unsigned int changes = 0;
    
    for (int i = 0; i < l1; i++)
    {
        if (s1[i] != s2[i])
        {
            changes++;
            if (changes > 1)
            {
                return false;
            }
        }
    }
    
    return true;    
}

unsigned int optimisticEstimate(const std::string& s1, const std::string& s2)
{
	unsigned int diff = 0;

	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i])
		{
			diff++;
		}
	}

	return diff;
}

std::vector< std::string > convert(const std::string & s1, const std::string & s2, const std::unordered_set<std::string> & words)
{
	std::vector<std::string> conversionPath;

	unsigned int l1 = s1.length(), l2 = s2.length();

	if (l1 != l2 || words.find(s1) == words.end() || words.find(s2) == words.end())
	{
		return conversionPath;
	}

	MyPriorityQueue<std::pair<int, std::string>> mpq;

	std::unordered_map<std::string, std::pair<int, std::string>> wordPaths;

	std::pair<int, std::string> newNode{0, s1};
	// std::cout << "***QUEUING*" << s1 << "*WITH*PRIORITY*" << newNode.first << "***" << std::endl;

	mpq.insert(newNode);

	wordPaths[s1] = std::pair<int, std::string>();

	// std::ofstream out = std::ofstream("file.txt");

	// out.width(5);

	while (!mpq.isEmpty())
	{
		std::pair<int, std::string> currentNode = mpq.min();
		mpq.extractMin();

		// out << "\nGOING THROUGH THE WORDS WITH " << currentNode.second << std::endl;

		for (auto i = words.begin(); i != words.end(); i++)
		{
			if (isAdjacent(currentNode.second, *i))
			{

				int currentLCDist = currentNode.first - optimisticEstimate(currentNode.second, s2);

				if (currentLCDist <= 0)
				{
					currentLCDist = 0;
				}

				std::pair<int, std::string> newNode{currentLCDist + 1 + optimisticEstimate(*i, s2), *i};				


				if (wordPaths.find(*i) == wordPaths.end())
				{
					// out << "***QUEUING*" << *i << "*WITH*PRIORITY*" << newNode.first << "***" << std::endl;
					mpq.insert(newNode);

					// out << "*****Adding*" << newNode.second << "*TO*PATH*****" << std::endl; 

					wordPaths[newNode.second] = std::make_pair(currentLCDist, currentNode.second);
				}
				else if (wordPaths[newNode.second].first > currentLCDist)
				{
					// out << "***QUEUING*" << *i << "*WITH*PRIORITY*" << newNode.first << "***ALREADY ADDED" << std::endl;
					mpq.insert(newNode);

					// out << "*****Adding*" << newNode.second << "*TO*PATH*****ALREADY ADDED" << std::endl; 
					wordPaths[newNode.second] = std::make_pair(currentLCDist, currentNode.second);
				}
			}
		}
	}

	if (wordPaths.find(s2) != wordPaths.end())
	{
		std::string traceBack = s2;
		while (traceBack != "")
		{
			conversionPath.insert(conversionPath.begin(), traceBack);
			traceBack = wordPaths[traceBack].second;
		}
	}

	return conversionPath;
}

