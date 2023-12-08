#include "dijkstra.h"

void dijkstra(Node* start){
	start->setValue(0);
	NodeSet s;
	s.add(start);

	Node* n;
	int l;
	Node* d;
	int a;
	while(!s.isEmpty())
	{
		n = s.removeMin();
		for(Edge e : n->getEdges())
		{
			l = e.getLength();
			d = e.getDest();
			a = n->getValue() + l;
			if(a < d->getValue())
			{
				d->setValue(a);
				s.add(d);
			}
		}
	}
}
