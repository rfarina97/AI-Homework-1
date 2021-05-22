#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 1  procedure BFS(G, root) is
 2      let Q be a queue
 3      label root as discovered
 4      Q.enqueue(root)
 5      while Q is not empty do
 6          v := Q.dequeue()
 7          if v is the goal then
 8              return v
 9          for all edges from v to w in G.adjacentEdges(v) do
10              if w is not labeled as discovered then
11                  label w as discovered
12                  Q.enqueue(w)
*/

void initVisited(vector<bool> visited, int n, int m){
	//n rows
	//m columns
	//visited is contiguous vector of size n*m
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			visited[i*n + j] = false;
			cout << visited[i*n + j] << " ";
		}
		cout << endl;
	}

}

int main()
{

	//n rows
	//m columns
	//start position
	int m, n;
	int startX, startY;
	int endX, endY;

	//assume start and end are always within the bounds of the matrix
	cin >> n >> m;
	cin >> startX >> startY;
	cin >> endX >> endY;

	//matrix
	int mat[n][m];

	//visited nodes
	vector<bool> visited(n*m);
	initVisited(visited, n, m);

	//read matrix input
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> mat[i][j];
		}
	}

	//print matrix for debug
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}




    return 0;
}


