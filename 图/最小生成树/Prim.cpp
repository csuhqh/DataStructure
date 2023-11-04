#include <bits/stdc++.h>
using namespace std;

/**
 * 选择任何一个节点作为S集合，每次从T集合中选择到S集合最短的边。
 * visited: 用以区分S集合和T集合. visited[i] = true，表示i节点在S集合。
*/

void Prim(vector<vector<int>> graph, int N, int v0){
  vector<int> lowcost(N); //T集合个节点到S集合最小花费
  vector<bool> visited(N, 0); 
  for(int i = 0; i < N; ++i){
    lowcost[i] = graph[v0][i]; //其中，自身到自身的代价为无穷大
  }
  visited[v0] = true; //S集合，初始只有一个元素
  int sum = 0;
  for(int i = 0; i < N - 1; ++i){
    int min = 0x3f3f3f3f;
    int selectNode;
    //选择T集合到S集合中，代价最小的节点，即从lowcost数组中找出最小值
    for(int j = 0;j < N; ++j){
      if(!visited[j] && lowcost[j] < min){
        min = lowcost[j];
        selectNode = j;
      }
    }
    //将选择的节点归并到S集合，并更新lowcost数组
    visited[selectNode] = 1; 
    sum += min;
    for(int j = 0; j < N; ++j){
      if(!visited[j] && graph[selectNode][j] < lowcost[j]){ 
        lowcost[j] = graph[selectNode][j];
      }
    }
  }
}


int main(){
  vector<vector<int>> edges = {{0,1, 5}, {0, 2, 1}, {0, 3, 2}, 
  {1, 4, 4},{2, 1, 3}, {2, 3, 6}, {2, 4, 2}, {3, 4, 4}};
  int N = 5; //图的节点个数
  // 小于号，说明每次选出最小者，最终排序为升序
  //采用邻接矩阵来表示图
  vector<vector<int>> graph(5, vector<int>(5, 0x3f3f3f3f));
  for(auto edge: edges){
    graph[edge[0]][edge[1]] = edge[2];
  }
  Prim(graph, N, 0);

}