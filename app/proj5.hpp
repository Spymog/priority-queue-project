#ifndef __PROJECT5_HPP
#define __PROJECT5_HPP

#include <vector>
#include <unordered_set>

void loadWordsIntoTable(std::unordered_set<std::string> & words, std::istream & in);

bool isAdjacent(const std::string& s1, const std::string& s2);

unsigned int optimisticEstimate(const std::string& s1, const std::string& s2);

std::vector< std::string > convert(const std::string & s1, const std::string & s2, const std::unordered_set<std::string> & words);



#endif 
