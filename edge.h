#ifndef EDGE_H
#define EDGE_H

#include "Node.h"
class Node;

class Edge
{
public:
	Edge(Node *destination, int length) : length(length), destination(destination) {}
	Node *getDest() const { return destination; }
	int getLength() const { return length; }

private:
	int length;
	Node *destination;
};

#endif
