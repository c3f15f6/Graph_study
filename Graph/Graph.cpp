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
		labelid = vector<int>();
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
				unsigned int d;
				assert(s < vn);
				while (iss >> t>>d) {
					e.push_back({s,t,d});
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
	LabelId();
	
}

Graph::~Graph()
{
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
		cout << 'e' << ' ';
		for (j = 0; j < e[i].size(); j++)
			cout << e[i][j] << ' ';
		cout << endl;
	}
}

//计算标签种类
void Graph::LabelId() {
	//确定类型
	for (int i=0; i < vn; i++) {
		if (labelid.size() == 0) labelid.push_back(v[i][0]);
		else {
			int j;
			for (j = 0; j < labelid.size(); j++) {
				if (labelid[j] == v[i][0]) break;
			}
			if (j+1>labelid.size()) labelid.push_back(v[i][0]);
		}
	}
	//确定类型后，初始化个数
	sort(labelid.begin(), labelid.end());//labelid排序
	labelidnum = vector < vector<unsigned>>(vn, vector<unsigned>(labelid.size(),0));
	for (int i = 0; i < en; i++) {
		if (e[i].size() == 0) continue;
		else {
			//e[i][i]相邻顶点
			//i是顶点
			for (int k = 0; k < labelid.size(); k++) {
				if (v[e[i][1]][0] == labelid[k]) {
					labelidnum[e[i][0]][k]++;
				}
				if (v[e[i][0]][0] == labelid[k]) {
					labelidnum[e[i][1]][k]++;
				}
			}
		}
	}
}