#pragma once
#include "Graph.h"
#include <map>
class SubGraph :public Graph
{
private:
	vector < vector<unsigned >> condidacy;//��ѡ���㼯
public:
	SubGraph(const string& filename,Graph G);
	void CountCon(Graph G);//�����ѡ��
};

