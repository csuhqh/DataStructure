/**
 * 图的存储: 邻接表与邻接矩阵
 * 邻接矩阵: 用一个N * N大小的矩阵去存储图的N条边，matrix[i][j] 表示节点i -> j 的距离
 * 邻接表: 用一个长度为N的节点数组，每个节点数组含有其边链表的头结点。
 * 
 * 总结:
 * 邻接矩阵: 空间复杂度高。但是查询出入边容易
 * 邻接表: 空间复杂度低，查询出边很容易，但是查询入边需要遍历所有边
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * 邻接表: 用一个长度为N的节点数组，每个节点数组含有其边链表的头结点。
*/
typedef struct Edge{
  int dst; //边的另一端
  int w; //边的权值
  Edge* next;
  Edge(int dst, int w):dst(dst), w(w), next(nullptr){} 
}Edge;
typedef struct Node{
  Edge* next;
}Node;


int main(){
  vector<vector<int>> nums = {{0, 1, 4}, {0, 2, 6}, {0, 3, 6}, {1, 4, 7}, {1, 2, 1}, {3, 2, 3},
  {3, 5, 5}, {2, 4, 6}, {2, 5, 4}, {5, 4, 1}, {4, 6, 6}, {5, 6, 8}};
  int N = 7; //一共7个节点
  //构建(邻接表)
  vector<vector<int>> graph(N, vector<int>(N, 0x3f3f3f3f)); //默认不可达为无穷大
  for(int i = 0; i < nums.size(); ++i){
    vector<int> edge = nums[i];
    graph[edge[0]][edge[1]] = edge[2];
  }
  //使用邻接矩阵
  vector<Node> graph2(N);
  for(int i = 0; i < nums.size(); ++i){
    int start = nums[i][0];
    int end = nums[i][1];
    int w = nums[i][2];
    if(graph2[start].next == nullptr){
      graph2[start].next = new Edge(end, w);
    }else{
      Edge* cur = graph2[start].next;
      while(cur->next){
        cur = cur->next;
      }
      cur->next = new Edge(end, w);
    }
    
  }
  //测试出边
  cout << "测试节点2有哪些出边:" << endl;
  cout << "邻接矩阵(简单):" << endl;;
  for(int i = 0; i < graph[2].size(); ++i){
    if(graph[2][i] != 0x3f3f3f3f){
      cout << 2 << " -> " << i << ": " << graph[2][i] << endl;;
    }
  }
  cout << "邻接表(简单):" << endl;
  Edge* edge = graph2[2].next;
  while(edge){
    cout << 2 << " -> " << edge->dst << ": " << edge->w << endl;
    edge = edge->next;
  }
  //测试入边
  cout << "测试节点2有哪些入边:" << endl;
  cout << "邻接矩阵(简单):" << endl;;
  for(int i = 0; i < graph.size(); ++i){
    if(graph[i][2] != 0x3f3f3f3f){
      cout << 2 << " <- " << i << ": " << graph[i][2] << endl;;
    }
  }
  cout << "邻接表(麻烦):" << endl;
  for(int i = 0; i < graph2.size(); ++i){
    Edge* edge2 = graph2[i].next;
    while(edge2){
      if(edge2->dst == 2){
        cout << 2 << " <- " << i << ": " << edge2->w << endl;
      }
      edge2 = edge2->next;
    }
  }


  return 0;
}