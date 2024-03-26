#pragma once
#include <queue>
#include <string>
#include <unordered_map>
#include "Node.h"
#include "Graph.h"


class City;

template <class T>
class SearchData
{
public:
    std::string departure;
    std::string destination;
    std::unordered_map<Node<T>*, bool> visited;
    std::unordered_map<Node<T>*, std::pair<Node<City>*, int>> parents;

    SearchData(const std::string& departure, const std::string& destination)
    : departure(departure), destination(destination) { }

    virtual void SetValueDefault() = 0;
    
};


template <class T>
class BFSData : public SearchData<T>
{
public:
    std::queue<std::pair<Node<T>*, int>> queue;

    BFSData() : SearchData<T>() { }
    BFSData(Graph<T> graph, const std::string& departure, const std::string& destination)
     : SearchData<T>(departure, destination)
    {
        for (const auto& node : graph.Nodes())
        {
            if(node->data->Name() == departure)
            {
                queue.emplace(node, 0);
                SearchData<T>::visited[node] = false;
            }
        }
    }

    virtual void SetValueDefault() override
    {
        while (!queue.empty())
        {
            queue.pop();
        }
        for (auto& element : SearchData<T>::visited)
        {
            element.second = false;
        }
    }
    
};

template <class T>
class DFSData : public SearchData<T>
{
public:
    Node<City>* init_node;
    DFSData() : SearchData<T>(), init_node(nullptr) { }
    DFSData(Graph<T> graph, const std::string& departure, const std::string& destination)
     : SearchData<T>(departure, destination)
    {
        for (const auto& node : graph.Nodes())
        {
            if(node->data->Name() == departure)
            {
                init_node = node;
            }
            SearchData<T>::visited[node] = false;
        }
    }
    
    ~DFSData() { delete init_node; }
    
    virtual void SetValueDefault() override
    {
        for (auto& element : SearchData<T>::visited)
        {
            element.second = false;
        }

        SearchData<T>::parents.clear();
    }
};