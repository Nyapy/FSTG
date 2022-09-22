//Dijkstra_PriorityQueue.cpp
#include <iostream>
#include <queue>
#include <vector>
#define INF INT_MAX
using namespace std;

int V = 4; //�� ����� ����
Vector<pair<int, int>> adj[V]; // ���� �迭 ��� [V index]���� pair.first���� cost�� pair.second

//src���� ��� ������ �ִܰŸ��� ������ vector�� return Ÿ������ ��
vector<int> dijkstra(int src)
{
    vector<int> dist(V, INF); // src�� �ʱ�����Ͽ� ���������� �ִܰŸ� �迭
    dist[src] = 0; // �ڱ� �ڽű����� �Ÿ��� 0�̴�.
    priority_queue<pair<int, int>> pq; // ���� ��带 ������� priority queue pair.first�� cost�̰� pair.second�� ������ȣ�̴�.
    pq.push(make_pair(0, src)); // ���� �ڱ��ڽű����� ���� push
    while (!pq.empty())
    {
        /*
        priority queue�� �� Ư���� ���� ū ���� front�� �´�.
        �׷��� ������ ������ ����� ���� ���� �����Ͱ� front�� �����ϱ����� ������ ��뿡 - �� �ٿ� ������ ������ش�.
        */
        int cost = -pq.top().first;  // �����ϴ� ���������� ���
        int here = pq.top().second; // �����ϴ� ������ ��ȣ

        // �̹� �����ϴ� ���������� �ּҺ���� �˰� �ִٸ� skip
        if (dist[here] < cost) continue;

        /*
        ���� ����� adj �� ������ �� vector<pair<int, int>> adj[]�� ���� ������ ���⼭ ���´�.
        �츮�� ���� �������κ��� ��� ��带 �������� �ʰ� ������ �ִ� ��常 ������ �� �ִ�.
        �׷��� i�� adj[here].size() ��ŭ�� Ž��.
        */
        for (int i = 0; i < adj[here].size(); i++)
        {
            int there = adj[here][i].first; // ������忡�� �� �� �ִ� ��������� ��ȣ
            int nextDist = cost + adj[here][i].second; // here�� �������� �� src ~ there������ ���

            if (dist[there] > nextDist)
            {
                dist[there] = nextDist; // �ִܰ�� ������Ʈ
                pq.push(make_pair(-nextDist, there)); // there ��� ����. �ٽ� �� �� -nextDist ����!
            }
        }
    }

    return dist;
}