#pragma once

#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_
#include <iostream>
#include <deque>
#include <string.h>
#include <vector>
#include <algorithm>//����
using namespace std;
class Graph {
protected:
	vector<vector<unsigned>> v;
	vector<vector<unsigned>> e;
	vector<int>labelid;
	vector<vector<unsigned>>labelidnum;
	int en;//����
	int vn;//������
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
// TODO: �ڴ˴����ó�����Ҫ��������ͷ��
#endif




