#include <iostream>
#include <fstream>
#include "graph.h"
#include <cassert>
#include "dijkstra.h"
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

Node* find_and_test(const std::string& s, Graph& g)
{
    Node * n = g.find(s);
    assert(n != nullptr);
    assert(n->getName() == s);
    assert(n->getValue() == Node::max_value);
    return n;
}

void test_graph(Graph& g)
{
    auto n_lund = find_and_test("Lund", g);
    find_and_test("Dalby", g);
    find_and_test("Sodra Sandby", g);
    find_and_test("Veberod", g);
    find_and_test("Torna Hallestad", g);
    auto n_flyinge = find_and_test("Flyinge", g);

    n_lund->setValue(17);
    auto n2 = g.find("Lund");
    assert(n2->getValue()==17);

    auto n3 = g.find("Flyinge");
    n_flyinge->setValue(42);
    assert(n3->getValue()==42);

    g.resetVals();
    for(auto it = g.begin(); it != g.end(); ++it){
        assert((*it)->getValue() == Node::max_value);
    }

	cout<<"==============Test Graph Passed================"<< endl;
}
void test_dijkstraPrint(Graph& g)
{
	Node* target = g.find("Veberod");
	vector<Node*> path;

	while(target != nullptr)
	{	
		path.push_back(target);
		target = target->getParent();
		
	}
	int cost = path.front()->getValue();
	string pathstr;
	while(!path.empty())
	{
		pathstr += path.back()->getName();
		pathstr += " ";
		path.pop_back();
	};
	cout<< "vägen från Lund till Veberod : "<< pathstr<< " "<< cost << endl;

}


//Kostnadsfunktion för att mäta vägavstånd
struct DistanceCost{
	int operator()(const Node& source, const Edge& edge) const{
		return edge.getLength();
	}
};
//Kostnadsfunktion för att mäta antal passerade orter
struct PassCountCost{
	int operator()(const Node& source, const Edge& edge) const{
		return 1;
	}
};
int main()
{
	cout<<"================Test Started=================="<< endl;
	std::ifstream in("./graph.txt");
	Graph g(in);
	test_graph(g);
	dijkstra(g.find("Lund"));
	test_dijkstraPrint(g);

	cout<<"=========Test for generalized started=========="<<endl;
	DistanceCost d;
	dijkstraGeneralized(g.find("Lund"), d);
	test_dijkstraPrint(g);

	PassCountCost p;
	dijkstraGeneralized(g.find("Lund"), p);
	test_dijkstraPrint(g);
	cout<<"=============All Testing Complete=============="<<endl;

}
