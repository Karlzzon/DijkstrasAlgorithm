#include "graph.h"
#include <iostream>
#include <string>

Graph::Graph(std::istream &in)
{
	if (!in)
	{
		std::cout << "couldnt open file" << std::endl;
	}
	std::string line;
	std::string source;
	std::string distance;
	std::string destination;
	while (std::getline(in, line))
	{
		source = line.substr(0, (line.find_first_of(':')));
		line.erase(0, (line.find_first_of(':') + 2));
		distance = line.substr(0, (line.find_first_of(' ')));
		line.erase(0, (line.find_first_of(' ') + 1));
		destination = line;

		addNode(source);
		addNode(destination);

		find(source)->addEdge(find(destination), std::stoi(distance));
	}
}

Node *Graph::find(const std::string &name)
{
	for (auto &nodePtr : nodes)
	{
		if (nodePtr->getName() == name)
		{
			return nodePtr.get();
		}
	}
	return nullptr;
}

void Graph::addNode(const std::string &name)
{
	if (this->find(name) == nullptr)
	{
		this->nodes.push_back(std::unique_ptr<Node>(new Node(name)));
	}
}

void Graph::resetVals()
{
	for (std::unique_ptr<Node> &nodePtr : nodes)
	{
		nodePtr->setValue(Node::max_value);
	}
}
