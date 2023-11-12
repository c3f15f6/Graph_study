#include "Graph.h"
#include <fstream>
#include <sstream>
#include <cassert>
//​#define NDEBUG 报错信息打印
using namespace std;
Graph::Graph(const string& filename) :vn(0), en(0) {
	string line;
	char kind;
	ifstream stream(filename.c_str());//string->char*
	if (!stream.eof()) {
		//顶点集初始化
		getline(stream, line);
		istringstream iss(line, istringstream::in);
		iss >> kind >> vn >> en;
		v = vector<vector<unsigned>>(vn);
		e = vector<vector<unsigned>>(en);
		deg = vector<unsigned>(vn, 0);
		indeg = vector<unsigned>(vn, 0);
		leaves = deque<unsigned>();

		//顶点集创建
		unsigned s, t;
		vector<bool>is_root(vn, true);

		while (stream.good()) {
			iss.clear();
			getline(stream, line);
			iss.str(line);
			iss >> kind;
			if (kind == 'v') {
				iss >> s;
				assert(s < vn);//输入错误
				while (iss >> t) {
					v[s].push_back(t);
					++deg[s];

				}
			}//加入顶点集
			else if (kind == 'e') {
				iss >> s;
				assert(s < en);
				while (iss >> t) {
					e[s].push_back(t);
					++deg[s];
				}
			}//加入边集

		}
		for (unsigned i = 0; i < vn; i++) {
			if (deg[i] == 0) {
				leaves.push_back(i);
			}
		}
	}
}

void Graph::traverse() {
	int i = 0;
	int j = 0;
	for (i = 0; i < vn; i++) {
		cout << 'v' << ' '<<i<<' ';
		for (j = 0; j < v[i].size(); j++)
			cout << v[i][j] << ' ';
		cout << endl;
	}
	for (i = 0; i < en; i++) {
		cout << 'e' << ' '<<i<<' ';
		for (j = 0; j < e[i].size(); j++)
			cout << e[i][j] << ' ';
		cout << endl;
	}
}