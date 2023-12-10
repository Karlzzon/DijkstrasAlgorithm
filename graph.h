#ifndef GRAPH_H
#define GRAPH_H
#include "node.h"
#include "edge.h"
#include <fstream>
#include "dijkstra.h"
#include <memory>

class Graph
{
	public:
		Graph() : nodes() {}
		Graph(std::istream& in);
		void addNode(const std::string& name);
		Node* find(const std::string& name);
		void resetVals();
		std::vector<std::unique_ptr<Node>>::iterator begin() { return nodes.begin(); }
		std::vector<std::unique_ptr<Node>>::iterator end() { return nodes.end(); }
	private:
		std::vector<std::unique_ptr<Node>> nodes;

};

#endif
