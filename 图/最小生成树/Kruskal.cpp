#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 10

typedef struct Road {
    int a, b, w;
    Road(int a, int b, int w) : a(a), b(b), w(w){};
} Road;
int v[MAXSIZE];  // 定义并查集

int getRoot(int a) {
    while (a != v[a]) a = v[a];
    return a;
}

/**
 * 每次选出最小边
 */
void Kruskal(int& sum, Road road[], int N, int E) {  // N为节点个数, E为边的个数
    // 初始化并查集数组
    for (int i = 0; i < N; ++i) {
        v[i] = i;
    }
    
    // 对边进行排序
    //  auto mycomp = [](const Road& a, const Road& b){
    //    return a.w < b.w;
    //  };

    //  sort(road, road + E, mycomp);
    //    for(int i = 0; i < E; ++i){
    //    int a = getRoot(road[i].a);
    //    int b = getRoot(road[i].b);
    //    if(a != b){
    //      v[a] = b;
    //      sum += road[i].w;
    //    }
    //  }

    // 构建小顶堆，每次选出最小
    struct CompareRoad {
        bool operator()(const Road& r1, const Road& r2) {
            // 自定义比较函数，按照 w 升序排列
            return r1.w > r2.w;
        }
    };
    priority_queue<Road, vector<Road>, CompareRoad> minHeap;
    for (int i = 0; i < E; ++i) {
        minHeap.push(road[i]);
    }
    //
    while (!minHeap.empty()) {
        Road road = minHeap.top();
        minHeap.pop();
        int a = getRoot(road.a);
        int b = getRoot(road.b);
        if (a != b) {
            v[a] = b;
            sum += road.w;
        }
    }
}

int main() {
    Road roads[] = {Road(0, 1, 5), Road(0, 2, 1), Road(0, 3, 2),
                    Road(1, 4, 4), Road(2, 4, 2), Road(3, 4, 3), Road(1, 2, 3), Road(2, 3, 6)};
    int sum = 0;
    Kruskal(sum, roads, 5, 8);
    cout << "Kruskal 最小生成树:" << sum << endl;
    return 0;
}