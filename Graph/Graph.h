#pragma once

#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_
#include <iostream>
#include <deque>
#include <string.h>
#include <vector>
using namespace std;
class Graph {
private:
	vector<vector<unsigned>> v;
	vector<vector<unsigned>> e;
	vector<int>type;
	vector<vector<unsigned>>typenum;
	int en;//����
	int vn;//������
	vector<unsigned> deg;
	vector<unsigned> indeg;
	deque<unsigned> leaves;
	vector<unsigned> roots;
public:

	Graph(const string& filename);
	void traverse();
	void Type();
};
// TODO: �ڴ˴����ó�����Ҫ��������ͷ��
#endif




