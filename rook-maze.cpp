#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <climits>

using namespace std;


int BFS(int* mat, int row, int col, int sX, int sY, int eX, int eY){
	/*
		mat matrix uses a contiguous vector to speed-up memory
		row
		col
		s determines start
		e determines goal
	*/

	//number of steps taken to finish
	int steps = 0;

	//queue contains the coordinates of the pending positions in matrix
	queue<pair<int, int>> pending;

	//init visited matrix as false
	bool visited[row][col];
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			visited[i][j] = false;
		}
	}

	//label root as discovered
	visited[sX][sY] = true;

	int cost[row][col];
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cost[i][j] = INT_MAX;
		}
	}

	//add root to queue
	pair<int,int> root(sX, sY);
	pending.push(root);
	cout << "Root is " << root.first << " " << root.second << endl;


	pair<int,int> aux;
	pair<int,int> res;
	int checkVal = -1;
	int posUp, posLeft, posRight, posDown;

	//check possible locations to be explored
	while (!pending.empty()){
		//dequeue front and save it as aux
		aux = pending.front();
		pending.pop();
		cout << "Current position: " << aux.first << " " << aux.second << endl;

		//check if aux is goal
		if (aux.first == eX && aux.second == eY){
			cout << "GOAL REACHED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
			cout << steps << endl;
			return steps;
		}

		checkVal = mat[aux.first * col + aux.second]; //current value to be checked
		cout << "Check values " << checkVal << endl;

		//calculate 4 possible positions 
		posUp = aux.first - checkVal;
		posDown = aux.first + checkVal;
		posLeft = aux.second - checkVal;
		posRight = aux.second + checkVal;
		cout << "Up: " << posUp << " " << aux.second << endl;
		cout << "Down: " << posDown << " " << aux.second << endl;
		cout << "Left: " << aux.first << " " << posLeft << endl;
		cout << "Right: " << aux.first << " " << posRight << endl;



		//check if any of the 4 positions has been discovered
		//and add them to queue if not discovered and accesible
		//this implementation is pretty rubbish but it works
		if (posUp >= 0 && posUp < row){
			if (visited[posUp][aux.second] == false){
				res = make_pair(posUp, aux.second);
				pending.push(res);
				cout << "Pushing Up: " << posUp << " " << aux.second << endl;
				visited[posUp][aux.second] = true;
			}
		}
		if (posDown >= 0 && posDown < row){
			if (visited[posDown][aux.second] == false){
				res = make_pair(posDown, aux.second);
				pending.push(res);
				cout << "Pushing Down: " << posDown << " " << aux.second << endl;
				visited[posDown][aux.second] == true;
			}			
		}
		if (posLeft >= 0 && posLeft < col){
			if (visited[aux.first][posLeft] == false){
				res = make_pair(aux.first, posLeft);
				pending.push(res);
				cout << "Pushing Left: " << aux.first << " " << posLeft << endl;
				visited[aux.first][posLeft] == true;
			}			
		}
		if (posRight >= 0 && posRight < col){
			if (visited[aux.first][posRight] == false){
				res = make_pair(aux.first, posRight);
				pending.push(res);
				cout << "Pushing Right: " << aux.first << " " << posRight << endl;
				visited[aux.first][posRight] == true;
			}			
		}
		
		cout << "-----------------------\n";

	}

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

	//mat[5] = 999;
	return -1;
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
	int mat[n*m];

	//read matrix input
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> mat[i*m + j];
		}
	}

	//print matrix for debug
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << mat[i*m + j] << " ";
		}
		cout << endl;
	}

	BFS(mat, n, m, startX, startY, endX, endY);

	/*for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << mat[i*m + j] << " ";
		}
		cout << endl;
	}*/
    return 0;
}




/*
DEPRECATED CODE BELOW

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

*/