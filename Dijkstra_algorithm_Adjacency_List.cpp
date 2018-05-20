/*
	created by Quoc Huy on 20/05/2018
*/
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<pair<int, int>>>Graph;
#define MAX 100
const int INF = 1000000000;
vector<int>dist(MAX, INF);
int path[MAX];
void Dijkstra(int s,vector<vector<pair<int,int>>>&Graph)
{
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > Queue;
	Queue.push(pair<int,int>(0, s));
	dist[s] = 0;
	while (!Queue.empty())
	{
		pair<int, int> top = Queue.top();
		Queue.pop();
		int node = top.second; // đỉnh
		int d = top.first; // chi phí
		for (int i = 0; i < Graph[node].size(); i++)
		{
			pair<int, int>neighbor = Graph[node][i]; 
			if (neighbor.second + d < dist[neighbor.first])
			{
				dist[neighbor.first] = neighbor.second + d;
				Queue.push(pair<int,int>(dist[neighbor.first], neighbor.first));
				path[neighbor.first] = node; // lưu lại đỉnh cha
			}
		}
	}
}
void printPath(int s, int e)
{
	if (s == e)
		cout << e;
	else
	{
		if (path[e] == -1)
		{
			cout << "No path "; return;
		}
		else
		{
			printPath(s, path[e]);
			cout << "->"<<e;
		}
	}
}
int main()
{
	/*
	6 10
	0 1 1
	1 2 5
	1 3 2
	1 5 7
	2 5 1
	3 0 2
	3 2 1
	3 4 4
	4 3 3
	5 4 1 
	*/
	int V=6, E=10;
	dist = vector<int>(MAX, INF); 
	Graph = vector<vector<pair<int, int>>>(MAX + 5, vector<pair<int, int>>());
	memset(path, -1, sizeof(path));
	for (int i = 0; i < E; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		Graph[u].push_back(pair<int,int>(v, d));
	}
	const int begin = 0;
	const int end = 4;
	Dijkstra(begin,Graph);
	cout << "Path by DijKstra: "<<endl;
	printPath(begin, end);
	
	system("pause");
	return 0;
}
