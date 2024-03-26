#pragma once
#include <iostream>
#include <list>
#include <ostream>

class City;

struct Solution
{
    bool solved = false;
    bool cutoff = false;
    int distance;
    std::list<City*> path;

    Solution(){}
    
    Solution(bool solved)
    : solved(solved) { }

    Solution(bool solved, bool cutoff)
    : solved(solved), cutoff(cutoff) { }
    
    Solution(bool solved, const std::list<City*>& path, int distance)
    : solved(solved), distance(distance), path(path) { }
    
};

inline std::ostream& operator<<(std::ostream& os, Solution solution)
{
    if(!solution.solved)
    {
        if(solution.cutoff)
            std::cout << "Failed to solve the problem, for a cutoff occured" << std::endl;
        else
            std::cout << "Failed to solve the problem" << std::endl;
    }
    std::cout << "Path : ";
    for (auto city : solution.path)
    {
        if(city->Name() == solution.path.back()->Name())
        {
            std::cout << city << std::endl;
            break;
        }
        std::cout << city << " -> ";

    }
    if(solution.solved)
        std::cout << "Distance : " << solution.distance;

    return os;
}