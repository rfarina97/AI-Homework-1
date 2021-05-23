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

	pair<int,int> parent[row][col];
	parent[0][0] = make_pair(0,0);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			parent[i][j] = make_pair(-1,-1);
		}
	}



	//add root to queue
	pair<int,int> root(sX, sY);
	pending.push(root);
	//cout << "Root is " << root.first << " " << root.second << endl;


	pair<int,int> aux;
	pair<int,int> res;
	int checkVal = -1;
	int posUp, posLeft, posRight, posDown;
	bool solved = false;

	//check possible locations to be explored
	while (!pending.empty()){
		//dequeue front and save it as aux
		aux = pending.front();
		pending.pop();
		//cout << "Current position: " << aux.first << " " << aux.second << endl;

		//check if aux is goal
		if (aux.first == eX && aux.second == eY){
			/*cout << "GOAL REACHED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
			cout << "Steps: " << steps << endl;
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					if (parent[i][j].first != -1){
						cout << parent[i][j].first << " " << parent[i][j].second << " | ";
					}
					else{
						cout << "- - | ";
					}
					
				}
				cout << endl;
			}*/
			solved = true;
			break;
			//return steps;
		}

		checkVal = mat[aux.first * col + aux.second]; //current value to be checked
		//cout << "Check values " << checkVal << endl;

		//calculate 4 possible positions 
		posUp = aux.first - checkVal;
		posDown = aux.first + checkVal;
		posLeft = aux.second - checkVal;
		posRight = aux.second + checkVal;/*
		cout << "I: " << aux.first << " " << aux.second << endl;
		cout << "Up: " << posUp << " " << aux.second << endl;
		cout << "Down: " << posDown << " " << aux.second << endl;
		cout << "Left: " << aux.first << " " << posLeft << endl;
		cout << "Right: " << aux.first << " " << posRight << endl;*/



		//check if any of the 4 positions has been discovered
		//and add them to queue if not discovered and accesible
		//this implementation is pretty rubbish but it works
		if ((posUp >= 0) && (posUp < row)){
			if (visited[posUp][aux.second] == false){
				res = make_pair(posUp, aux.second);
				pending.push(res);
				//cerr << "Pushing Up: " << posUp << " " << aux.second << endl;
				visited[aux.first][aux.second] = true;

				//cerr << "Attempting to put pair in " << posUp << " " << aux.second << endl;
				parent[posUp][aux.second] = make_pair(aux.first, aux.second);
			}
		}
		if ((posDown >= 0) && (posDown < row)){
			if (visited[posDown][aux.second] == false){
				res = make_pair(posDown, aux.second);
				pending.push(res);
				//cerr << "Pushing Down: " << posDown << " " << aux.second << endl;
				visited[aux.first][aux.second] = true;

				//cerr << "Attempting to put pair in " << posDown << " " << aux.second << endl;
				parent[posDown][aux.second] = make_pair(aux.first, aux.second);
			}			
		}
		if ((posLeft >= 0) && (posLeft < col)){
			if (visited[aux.first][posLeft] == false){
				res = make_pair(aux.first, posLeft);
				pending.push(res);
				//cerr << "Pushing Left: " << aux.first << " " << posLeft << endl;
				visited[aux.first][aux.second] = true;

				//cerr << "Attempting to put pair in " << aux.first << " " << posLeft << endl;
				parent[aux.first][posLeft] = make_pair(aux.first, aux.second);
			}			
		}
		if ((posRight >= 0) && (posRight < col)){
			if (visited[aux.first][posRight] == false){
				res = make_pair(aux.first, posRight);
				pending.push(res);
				//cerr << "Pushing Right: " << aux.first << " " << posRight << endl;
				visited[aux.first][aux.second] = true;

				//cerr << "Attempting to put pair in " << aux.first << " " << posRight << endl;
				parent[aux.first][posRight] = make_pair(aux.first, aux.second);
			}			
		}

		steps++;
		//cout << "-----------------------\n";

	}

	if (solved == false){
		cout << "No hay solucion\n";
		return -1;
	}

	pair<int,int> temp = make_pair(eX, eY);
	//cout << eX << " " << eY << endl;
	vector<pair<int,int>> road;
	//print path
	while(1){
		road.push_back(temp);
		//cout << "Step " << temp.first << " " << temp.second << endl;
		int newX = parent[temp.first][temp.second].first;
		int newY = parent[temp.first][temp.second].second;
		//cout << newX << " " << newY << endl;
		temp = make_pair(newX, newY);
		if (temp.first == -1){
			break;
		}
	}

	//prints road taken
	int count = 0;
	//cout << "ROAD TAKEN: " << endl;
	for (int i = road.size()-2 ; i >= 0; --i)
	{
		//cout<<road[i].first << " " << road[i].second << endl;
		count++;
	}
	cout << count << endl;
	//mat[5] = 999;
	return -1;
}


int main()
{

	

	while(1){
		//n rows
		//m columns
		//start position
		int m, n;
		int startX, startY;
		int endX, endY;

		//assume start and end are always within the bounds of the matrix
		cin >> n;
		if (n == 0){
			break;
		}
		cin >> m;
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
		/*for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << mat[i*m + j] << " ";
			}
			cout << endl;
		}*/

		BFS(mat, n, m, startX, startY, endX, endY);
	}

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
