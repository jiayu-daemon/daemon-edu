/*
FloodFill

通常译作“洪水灌溉法”，
算法通过给图中的顶点染色，最终使得同一个连通分量的顶点颜色相同，不同连通分量的顶点颜色不同。
首先了解一些概念：
子图（subgraph）：若一个图的顶点集和边集分别是另一图的顶点集的子集和边集的子集，则称该图为另一图的子图。
连通：在无向图中，如果有从顶点 vv 到顶点 ww 的路径存在，则称 vv 和 ww 是连通的。若图 GG 中任意两个顶点都
是连通的，则称图 GG 为连通图，否则成为非连通图。

连通分量：若图G的子图Gs是连通的，我们就称子图Gs是图G的连通子图。如果对于图G的一个连通子图Gs，不存在图G的
其他连通子图 Gmax​​​ 满足：Gs是 Gmax的子图。则子图 Gs​​是图 G 的极大连通子图，也就是图 G 的连通分量。
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Graph{
private:
	int n;
	int *color;
	vector<int> *edges;
public:
	Graph(int input_n){
		n = input_n;
		edges = new vector<int>[n];
		color = new int[n];
		memset(color, 0, n*sizeof(int));
	}
	~Graph(){
		delete[] edges;
		delete[] color;
	}

	void insert(int x, int y){
		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	void floodfill(){
		//表示当前的染色的值
		int color_cnt = 0, i = 0;
		for (i = 0; i < n; i++) {
			//color等于0，说明没被染色
			if (color[i] == 0) {
				color_cnt++;
				color[i] = color_cnt;
				queue<int> q;
				q.push(i);
				while (!q.empty()) {
					int vertex = q.front();
					for (vector<int>::iterator it = edges[vertex].begin(); it != edges[vertex].end(); it++ ) {
						//未染色
						if (color[*it] == 0) {
							color[*it] = color_cnt;
							q.push(*it);
						}
					}
					q.pop();		
				}
			}
		}
		//输出 编号 及 颜色值
		for (i = 0; i < n; i++) {
			cout << i << " " <<color[i] << endl;
		}
	}
};

int main(){
	int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g.insert(x, y);
    }
    g.floodfill();
    return 0;
}
