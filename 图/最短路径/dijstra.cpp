#include <bits/stdc++.h>
using namespace std;

typedef struct Edge{
  int a, b, w;
  Edge(int a, int b, int w): a(a), b(b), w(w){}
}Edge;
/**
 * 单源最短路径: Dijkstra。迪杰斯特拉算法 [S集合和T集合，最初S集合只有V0]
 * 初始2个顶点集合S和T，S中存放已找到最短路径的节点。T集合中为没有并入S的节点
 * N为顶点个数
 * 必选:
 * visited:用于区分S和T集合。visited[i] = true，表示i节点加入了S集合
 * dist: 存放从vo到其他节点的最短距离, dist[i] = w， 表示从v0到i的最短距离为w
 * 可选
 * path： path[i] = j 表示到节点i的距离最近的节点为j. 其中path[v0] = -1,作为唯一的根节点。
*/
vector<int> path(7, -1);

vector<int> Dijkstra(int v0, int N, vector<Edge> edges){ //v0为起点
  vector<bool> visited(N, false);
  vector<int> dist(N, 0x3f3f3f3f);
  //可选:记录路径（如果需要记录的话）path[i] = j  表示到节点i的最近节点为j;
  // vector<int> path(N, -1);
  //S集合到其他节点的最短距离
  for(auto edge: edges){
    if(edge.a == v0){
      dist[edge.b] = edge.w;
      path[edge.b] = edge.a;
    }
  }
  dist[v0] = 0;
  path[v0] = -1; //v0是起点（唯一）
  //遍历除v0外的每一个节点
  for(int i = 0; i < N - 1; ++i){
    int minDistance = 0x3f3f3f3f;
    int u;
    //选出一个节点，该节点到S的距离最短
    for(int j = 0; j < N; ++j){
      if(!visited[j] && dist[j] < minDistance){
        minDistance = dist[j];
        u = j; 
      }
    }
    visited[u] = true;
    //以新节点作为中间节点，更新是否到其他节点距离更短
    for(auto edge: edges){
      //到中间节点的距离 + 中间节点到T集合的距离 <= 原先S集合到T的距离
      if(edge.a == u && !visited[edge.b]){
        if(dist[edge.b] > dist[u] + edge.w){
          dist[edge.b] = dist[u] + edge.w;
          path[edge.b] = u;
        }
      }
    }

  }
  return dist;
}
//打印到该节点的路径
vector<int> printPath(vector<int> path, int v0){
  stack<int> sta;
  while(path[v0] != -1){ //
    sta.push(v0);
    v0 = path[v0];
  }
  vector<int> result;
  while(!sta.empty()){
    result.push_back(sta.top());
    sta.pop();
  }
  return result;
}

int main(){
  vector<Edge> edges = {Edge(0, 1, 4), Edge(0, 2, 6), Edge(0, 3, 6), 
  Edge(1, 2, 1), Edge(3, 2, 2), Edge(1, 4, 7), Edge(3, 5, 5), Edge(2, 4, 6), Edge(2, 5, 4),
  Edge(5, 4, 1), Edge(4, 6, 6), Edge(5, 6, 8)
  };
  vector<int> result = Dijkstra(0, 7, edges);
  cout << "path 数组:";
  for(auto p: path){
    cout << p << " ";
  }
  cout << endl;

  int res = 0;
  for(int i = 0; i < 7; ++i){
    vector<int> paths = printPath(path, i);
    cout << 0;
    for(int i = 0; i < paths.size(); ++i){
      cout << " -> " << paths[i];
    }
    cout << " :"<< result[i] << endl;
    res += result[i];
  }
  
  cout << "Dijkstra :" << res << endl;
  return 0;
}