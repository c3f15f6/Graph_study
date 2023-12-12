#include "SubGraph.h"

SubGraph::SubGraph(const string& filename, Graph G):Graph(filename)
{
	condidacy = vector<vector<unsigned>>(vn);//vn个顶点的候选集合
	CountCon(G);
}

void SubGraph::CountCon(Graph G) {
	int i = 0, j = 0,k=0,m=0;
	int G_vn = G.get_vn();
	vector<int>G_labelid = G.get_labelid();
	vector<vector<unsigned>>G_labelidnum = G.get_labelidnum();
	for (i = 0; i < vn; i++) {
		bool is_con = true;
		for (j = 0; j < G_vn; j++) {
			is_con = true;
			int begin=0;
			for (k = 0; k < labelid.size(); k++) {
				
				for (m = begin; m < G_labelid.size(); m++) {
					if (labelid[k] == G_labelid[m]) {
						if (labelidnum[i][k] <= G_labelidnum[j][m]) {
							begin = m;
							break;
						}
						else {
							is_con = false;
							begin = m;
							break;
						}
					}
					begin = m;
				}
				if (!is_con) break;
			}
			if (is_con) condidacy[i].push_back(j);
		}
		
	}
}