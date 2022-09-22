//Dijkstra_PriorityQueue.cpp
#include <iostream>
#include <queue>
#include <vector>
#define INF INT_MAX
using namespace std;

int V = 4; //총 노드의 갯수
Vector<pair<int, int>> adj[V]; // 인접 배열 행렬 [V index]에서 pair.first까지 cost는 pair.second

//src부터 모든 노드로의 최단거리를 저장한 vector를 return 타입으로 함
vector<int> dijkstra(int src)
{
    vector<int> dist(V, INF); // src를 초기노드로하여 모든노드까지의 최단거리 배열
    dist[src] = 0; // 자기 자신까지의 거리는 0이다.
    priority_queue<pair<int, int>> pq; // 인접 노드를 집어넣을 priority queue pair.first는 cost이고 pair.second가 정점번호이다.
    pq.push(make_pair(0, src)); // 최초 자기자신까지의 간선 push
    while (!pq.empty())
    {
        /*
        priority queue는 그 특성상 가장 큰 값이 front에 온다.
        그렇기 때문에 간선의 비용이 적은 정점 데이터가 front에 오게하기위해 간선의 비용에 - 를 붙여 음수로 만들어준다.
        */
        int cost = -pq.top().first;  // 경유하는 정점까지의 비용
        int here = pq.top().second; // 경유하는 정점의 번호

        // 이미 경유하는 정점까지의 최소비용을 알고 있다면 skip
        if (dist[here] < cost) continue;

        /*
        인접 행렬을 adj 를 생성할 때 vector<pair<int, int>> adj[]로 만든 강점이 여기서 나온다.
        우리는 굳이 경유노드로부터 모든 노드를 조사하지 않고 간선이 있는 노드만 조사할 수 있다.
        그래서 i는 adj[here].size() 만큼만 탐색.
        */
        for (int i = 0; i < adj[here].size(); i++)
        {
            int there = adj[here][i].first; // 경유노드에서 갈 수 있는 인접노드의 번호
            int nextDist = cost + adj[here][i].second; // here를 경유했을 때 src ~ there까지의 비용

            if (dist[there] > nextDist)
            {
                dist[there] = nextDist; // 최단경로 업데이트
                pq.push(make_pair(-nextDist, there)); // there 노드 조사. 다시 한 번 -nextDist 강조!
            }
        }
    }

    return dist;
}