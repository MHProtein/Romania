#include "RomaniaProblem.h"

#include <iostream>
#include <map>

#include "City.h"
#include "Graph.h"
#include "SearchData.h"
#include "Solution.h"


Solution RomaniaProblem::BFS(const std::string& departure, const std::string& destination)
{
    BFSData<City>* data = new BFSData<City>(Map(), departure, destination);
    
    if(data->queue.empty())
        throw std::exception("No such city exists");

    while(!data->queue.empty())
    {
        auto node = data->queue.front();
        data->visited[node.first] = true;
        std::map<int, int> x;

        auto xx = data->visited[node.first];
        data->queue.pop();
        for (auto city: node.first->next)
        {
            if(data->visited[city.first])
                continue;
            data->parents[city.first] = node;
            data->queue.push(city);
            if(city.first->data->Name() == destination)
            {
                return GetSolution(node, data);
            }
        }
    }
    return {false};
}


Solution RomaniaProblem::DFS(const std::string& departure, const std::string& destination)
{
    DFSData<City>* data = new DFSData<City>(Map(), departure, destination);

    return DFS_Recursion({data->init_node, 0}, data, std::numeric_limits<uint64_t>::max());
}


Solution RomaniaProblem::DLS(const std::string& departure, const std::string& destination, uint64_t depth)
{
    DFSData<City>* data = new DFSData<City>(Map(), departure, destination);

    return DFS_Recursion({data->init_node, 0}, data, depth);
}

Solution RomaniaProblem::IDS(const std::string& departure, const std::string& destination, uint64_t depth)
{
    DFSData<City>* data = new DFSData<City>(Map(), departure, destination);
 
    for(uint64_t i = 0; i < depth; ++i)
    {
        auto solution = DFS_Recursion({data->init_node, 0}, data, i);
  
        if(solution.cutoff)
        {
            data->SetValueDefault();
            continue;
        }

        if(solution.solved)
            return solution;
    }

    return {false, true};
}

Solution RomaniaProblem::DFS_Recursion(const std::pair<Node<City>*, int>& node,
                                       DFSData<City>* data, uint64_t depth)
{
    data->visited[node.first] = true;

    if(depth == 0)
    {
        return {false, true};
    }
   
    if(node.first->data->Name() == data->destination)
    {
        return GetSolution(node, data);
    }

    for (const auto& city : node.first->next)
    {
        if(!data->visited[city.first])
        {
            data->parents[city.first] = node;
            auto solution = DFS_Recursion(city, data, depth - 1);
            if(solution.solved || solution.cutoff)
                return solution;
        }
    }
    return {false};
}

Solution RomaniaProblem::GetSolution(const std::pair<Node<City>*, int>& dest_node, SearchData<City>* data)
{
    std::cout << data->destination << " reached" << std::endl;
    std::list<City*> path;
    Node<City>* node = dest_node.first;
    path.push_front(node->data);
    int distance = dest_node.second;
    while(node->data->Name() != data->departure)
    {
        distance += data->parents[node].second;
        node = data->parents[node].first;
        path.push_front(node->data);
    }
    return {true, path, distance};
}

