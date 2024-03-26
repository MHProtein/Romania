#include <iostream>

#include "City.h"
#include "Graph.h"
#include "Node.h"
#include "RomaniaProblem.h"
#include "Solution.h"

auto Initialization()
{
    Graph<City> romania;
    Node<City>* Oradea = new Node<City>(new City("Oradea"));
    Node<City>* Zerind = new Node<City>(new City("Zerind"));
    Node<City>* Arad = new Node<City>(new City("Arad"));
    Node<City>* Timisoara = new Node<City>(new City("Timisoara"));
    Node<City>* Lugoj = new Node<City>(new City("Lugoj"));
    Node<City>* Mehadia = new Node<City>(new City("Mehadia"));
    Node<City>* Dobreta = new Node<City>(new City("Dobreta"));
    Node<City>* Craiova = new Node<City>(new City("Craiova"));
    Node<City>* RimnicuVilcea = new Node<City>(new City("RimnicuVilcea"));
    Node<City>* Sibiu = new Node<City>(new City("Sibiu"));
    Node<City>* Fagaras = new Node<City>(new City("Fagaras"));
    Node<City>* Pitesti = new Node<City>(new City("Pitesti"));
    Node<City>* Bucharest = new Node<City>(new City("Bucharest"));
    Node<City>* Giurgiu = new Node<City>(new City("Giurgiu"));
    Node<City>* Urziceni = new Node<City>(new City("Urziceni"));
    Node<City>* Hirsova = new Node<City>(new City("Hirsova"));
    Node<City>* Eforie = new Node<City>(new City("Eforie"));
    Node<City>* Vaslui = new Node<City>(new City("Vaslui"));
    Node<City>* Iasi = new Node<City>(new City("Iasi"));
    Node<City>* Neamt = new Node<City>(new City("Neamt"));

    romania.AddNode({Oradea, Zerind, Arad, Timisoara,
        Lugoj, Mehadia, Dobreta, Craiova, RimnicuVilcea, Sibiu,
        Fagaras, Pitesti, Bucharest, Giurgiu, Urziceni, Hirsova,
        Eforie, Vaslui, Iasi, Neamt});
    
    Oradea->AddNext({ {Zerind, 71},
                    {Sibiu, 151}});
    
    Zerind->AddNext({ {Oradea, 71},
                    {Arad, 75}});

    Arad->AddNext({ {Sibiu, 140},
                {Zerind, 75},
                {Timisoara, 118}});

    Timisoara->AddNext({{Lugoj, 111},
                {Arad, 118}});

    Lugoj->AddNext({{Timisoara, 111},
                {Mehadia, 70}});

    Mehadia->AddNext({{Dobreta, 75},
            {Lugoj, 70}});

    Dobreta->AddNext({{Mehadia, 75},
                {Craiova, 120}});

    Craiova->AddNext({{Dobreta, 120},
                {RimnicuVilcea, 146},
                {Pitesti, 138}});

    RimnicuVilcea->AddNext({{Sibiu, 80},
                    {Pitesti, 97},
                    {Craiova, 146}});

    Sibiu->AddNext({{Oradea, 151},
                {Arad, 140},
                {RimnicuVilcea, 80},
                {Fagaras, 99}});

    Fagaras->AddNext({{Sibiu, 99}, 
                {Bucharest, 211}});

    Pitesti->AddNext({{RimnicuVilcea, 97},
                {Craiova, 138},
                {Bucharest, 101}});

    Bucharest->AddNext({{Fagaras, 211},
                {Pitesti, 101},
                {Giurgiu, 90},
                {Urziceni, 85}});

    Giurgiu->AddNext({{Bucharest, 90}});

    Urziceni->AddNext({{Bucharest, 85},
                {Hirsova, 98},
                {Vaslui, 142}});

    Hirsova->AddNext({{Urziceni, 98},
                {Eforie, 86}});

    Eforie->AddNext({{Hirsova, 86}});

    Vaslui->AddNext({{Urziceni, 142},
                {Iasi, 92}});

    Iasi->AddNext({{Vaslui, 92}, 
                {Neamt, 87}});

    Neamt->AddNext({{Iasi, 87}});

    return romania;
}

int main()
{
    auto romania = Initialization();

    RomaniaProblem* problem = new RomaniaProblem(romania);
    auto solution = problem->BFS("Arad", "Bucharest");
    std::cout << solution << std::endl;
}
