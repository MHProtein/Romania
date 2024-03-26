#pragma once
#include <ostream>
#include <vector>
#include <string>
#include <queue>
#include "Node.h"

struct City;

template <class T>
class Graph
{
    friend class RomaniaProblem;
    friend std::ostream& operator<<(std::ostream& os, const Graph<City>& graph);
public:
    Graph() { }

    auto Nodes() const { return nodes; }
    void AddNode(Node<T>* node) { nodes.push_back(node); }
    void AddNode(const std::vector<Node<T>*>& new_nodes)
    {
        nodes.insert(nodes.cbegin(),
            new_nodes.cbegin(), new_nodes.cend());
    }
    
private:
    std::vector<Node<T>*> nodes;
};

inline std::ostream& operator<<(std::ostream& os, const Graph<City>& graph)
{
    for (auto node : graph.nodes)
    {
        os << node->data << " -> ";
        for (auto next : node->next)
        {
            os << next.first->data << " " << next.second << " ";
        }
        os << std::endl;
    }
    return os;
}
