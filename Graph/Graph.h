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
	int en;//边数
	int vn;//顶点数
	vector<unsigned> deg;
	vector<unsigned> indeg;
	deque<unsigned> leaves;
	vector<unsigned> roots;
public:
	Graph();
	Graph(const string& filename);
	void traverse();
};
// TODO: 在此处引用程序需要的其他标头。
#endif




