#ifndef NODESET_H
#define NODESET_H
#include "node.h"
#include <vector>

class NodeSet
{

public:
	NodeSet() {}
	void add(Node *node);
	bool isEmpty();
	Node *removeMin();

private:
	std::vector<Node *> n;
};

#endif
