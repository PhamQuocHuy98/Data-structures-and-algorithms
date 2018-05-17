// Created by Quoc Huy on 17/05/2018.
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
class point {
public:
	int x, y;

	friend bool operator==(const point &lhs, const point &rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}

	friend bool operator!=(const point &lhs, const point &rhs)
	{
		return !(rhs == lhs);
	}
	friend istream& operator>>(istream &is, point &point)
	{
		is >> point.x >> point.y;
		return is;
	}
	friend ostream& operator<<(ostream &os, const point &point)
	{
		return os << '(' << point.x << ", " << point.y << ')';
	}
};
#define MAX 1000
int visited[MAX][MAX];
point path[MAX][MAX];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
#define row 9
#define col 10
void BFS(point start, point end, int matrix[][col])
{
	memset(visited, false, sizeof(visited));
	memset(path, -1, sizeof(path));
	queue<point>Queue;
	Queue.push(start);
	visited[start.x][start.y] = true;
	int x, y;
	while (!Queue.empty())
	{
		point u = Queue.front();
		Queue.pop();
		for (int i = 0; i < 4; i++)
		{
			x = u.x + dx[i];
			y = u.y + dy[i];
			if (x < row && x >= 0 && y < col && y >= 0)
			{
				if (!visited[x][y] && matrix[x][y] != 0)
				{
					visited[x][y] = true;
					path[x][y] = u;
					Queue.push(point{ x, y });
				}
			}
		}
	}
}
void prinPath(point s, point f)
{
	if (s == f)
	{
		cout << f;
	}
	else
	{
		if (path[f.x][f.y] == point{ -1, -1 })
		{
			cout << "No path" << endl; return;
		}
		prinPath(s, path[f.x][f.y]);
		cout <<"->"<< f;
	}
}
int main() {
	int matrix[row][col] =
	{
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
		{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
	};
	const point begin = { 0, 0 };
	const point end = { 8, 9 };

	BFS(begin, end, matrix);
	cout << "path by BFS: "<<endl;
	prinPath(begin, end);
	cout << endl;
	system("pause");
	return 0;
}