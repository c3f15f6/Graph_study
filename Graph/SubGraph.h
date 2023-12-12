#pragma once
#include "Graph.h"
#include <map>
class SubGraph :public Graph
{
private:
	vector < vector<unsigned >> condidacy;//候选顶点集
public:
	SubGraph(const string& filename,Graph G);
	void CountCon(Graph G);//计算候选集
};

