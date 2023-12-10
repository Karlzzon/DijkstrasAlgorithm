#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include "Edge.h"
#include <climits>

class Node
{
public:
	Node(const std::string &name) : name(name), value(max_value), parent(nullptr) {}
	std::string getName() const { return name; }
	void setValue(int v) { value = v; }
	int getValue() const { return value; }
	const std::vector<Edge> &getEdges() const { return edges; }
	void addEdge(Node *destination, int length) { edges.emplace_back(Edge(destination, length)); }
	static constexpr int max_value = INT_MAX;
	void setParent(Node *p) { parent = p; }
	Node *getParent() const { return parent; }

private:
	std::string name;
	int value;
	std::vector<Edge> edges;
	Node *parent;
};

#endif
