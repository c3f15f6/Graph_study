#pragma once

#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_
#include <iostream>
#include <deque>
#include <string.h>
#include <vector>
#include <algorithm>//排序
using namespace std;
class Graph {
protected:
	vector<vector<unsigned>> v;
	vector<vector<unsigned>> e;
	vector<int>labelid;
	vector<vector<unsigned>>labelidnum;
	int en;//边数
	int vn;//顶点数
	vector<unsigned> deg;
	vector<unsigned> indeg;
	deque<unsigned> leaves;
	vector<unsigned> roots;
public:
	Graph(const string& filename);
	~Graph();

	inline int get_vn() const {
		return vn;
	}
	inline vector<vector<unsigned>> get_labelidnum(){
		return labelidnum;
	}
	inline vector<int> get_labelid() {
		return labelid;
	}
	void traverse();
	void LabelId();
};
// TODO: 在此处引用程序需要的其他标头。
#endif




