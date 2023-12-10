#include "nodeset.h"
#include <algorithm>
#include <iostream>
Node *NodeSet::removeMin()
{
	if (n.empty())
	{
		return nullptr;
	}
	auto minIter = std::min_element(n.begin(), n.end(), [](Node *a, Node *b)
									{ return a->getValue() < b->getValue(); });
	Node *minNode = *minIter;
	n.erase(minIter);
	return minNode;
}

bool NodeSet::isEmpty()
{
	return n.empty();
}
void NodeSet::add(Node *node)
{
	auto it = std::find_if(n.begin(), n.end(), [node](const Node *exists)
						   { return node->getName() == exists->getName(); });
	if (it == n.end())
	{
		n.push_back(node);
	}
}
