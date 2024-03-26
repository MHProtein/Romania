#pragma once
#include <list>
#include <vector>

template <class T>
struct Node
{
    T* data;
    std::list<std::pair<Node*, int>> next;
    
    Node(T* data) : data(data) {}
    Node() : data(nullptr){}
    ~Node()
    {
        delete data;
        data = nullptr;
    }
    void AddNext(Node* node, int weight)
    {
        next.push_back({node, weight});
    }
    void AddNext(const std::vector<std::pair<Node*, int>>& nexts)
    {
        for (auto next : nexts)
        {
            this->next.push_back(next);
        }
    }
};
