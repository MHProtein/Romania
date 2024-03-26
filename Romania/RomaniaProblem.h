#pragma once
#include <string>
#include <unordered_map>

#include "SearchData.h"

template <class T>
class Graph;
class City;
class Solution;

class RomaniaProblem
{
public:
    RomaniaProblem(Graph<City> map) : map(map) {}
    Solution BFS(const std::string& departure, const std::string& destination);
    Solution DFS(const std::string& departure, const std::string& destination);
    Solution DLS(const std::string& departure, const std::string& destination, uint64_t depth);
    Solution IDS(const std::string& departure, const std::string& destination, uint64_t depth);
    Graph<City> Map() const { return map; }
    
private:

    Solution GetSolution(const std::pair<Node<City>*, int>& dest_node, SearchData<City>* data);
    
    Solution DFS_Recursion(const std::pair<Node<City>*, int>& node,
                                       DFSData<City>* data, uint64_t depth);
    
    Graph<City> map;
};
