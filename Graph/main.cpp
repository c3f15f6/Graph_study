#include "Graph.h"
#include "SubGraph.h"
int main()
{
	Graph G("dblp.graph");
	SubGraph sG("query_dense_4_1.graph2", G);
//	g.traverse();
	return 1;
}