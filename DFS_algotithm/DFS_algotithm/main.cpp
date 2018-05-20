/*
	Created by Pham Quoc Huy on 19/05/2018
*/
#include <iostream>
using namespace std;
class point
{
public:
	int x, y;
	friend bool operator==(const point lhs, const point rhs)
	{
		return lhs.x == rhs.y&& lhs.y == rhs.x;
	}
	friend bool operator!=(const point lhs, const point rhs)
	{
		return !(lhs == rhs);
	}
	friend istream& operator>>(istream &is, point &P)
	{
		is >> P.x >> P.y;
		return is;
	}
	friend ostream& operator<<(ostream &os, const point P)
	{
		return os << "(" << P.x << ", " << P.y << " )";

	}
};
#define MAX 100
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
#define row 9
#define col 10
bool visited[MAX][MAX];
point path[MAX][MAX];
void DFS(point begin,int matrix[row][col])
{
	visited[begin.x][begin.y] = true;
	for (int i = 0; i < 4; i++)
	{
		int x = begin.x + dx[i];
		int y = begin.y + dy[i];
		if (x >= 0 && x < row && y >= 0 && y < col)
		{
			if (!visited[x][y] && make[x][y]!=0)
			{
				visited[x][y] = true; 
				path[x][y] = begin; 
				DFS(point{ x, y },matrix);
			}
		}
	}
}
void printPath(point start ,point end)
{
	if (start == end)
	{
		cout << end;
	}
	else
	{
		if (path[end.x][end.y] == point{ -1, -1 })
		{
			cout << "No path"; return;
		}
		else
		{
			printPath(start, path[end.x][end.y]);
			cout <<"->"<< end;
		}
	}
}
auto main()->int
{
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
	memset(visited, false, sizeof(visited));
	memset(path, -1, sizeof(path));
	const point begin = point{ 0, 0 };
	const point end = point{ 8, 9 };
	DFS(begin, matrix);
	cout << "Path by DFS " << endl;
	printPath(begin, end);
	cout << endl;
	system("pause");
	return 0;
}
