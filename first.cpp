#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> adjList[1000]; // Adjacency list to represent the network

void readInput(int &n, int &m)
{
	ifstream inputFile("test_input-7.txt");

	if (!inputFile.is_open())
	{
		cerr << "Error opening file!" << endl;
		exit(1);
	}

	inputFile >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		inputFile >> u >> v;
		adjList[u - 1].push_back(v - 1);
		adjList[v - 1].push_back(u - 1); // Bidirectional connections
	}

	inputFile.close();
}

bool dfs(int u, int target, vector<bool> &visited)
{
	visited[u] = true;

	if (u == target)
	{
		return true;
	}

	for (int v : adjList[u])
	{
		if (!visited[v])
		{
			if (dfs(v, target, visited))
			{
				return true;
			}
		}
	}

	return false;
}

int minConnectionsToSever(int n)
{
	vector<bool> visited(n, false);
	int count = 0;

	// Iterate through all edges and check if removing them breaks connection
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < adjList[i].size(); j++)
		{
			int neighbor = adjList[i][j];
			adjList[i].erase(adjList[i].begin() + j); // Temporarily remove edge

			visited.assign(n, false); // Reset visited for each check

			if (!dfs(0, n - 1, visited))
			{ // Check if path exists after removal
				count++;
			}

			adjList[i].insert(adjList[i].begin() + j, neighbor); // Restore edge
		}
	}

	return count;
}

int main()
{
	int n, m;
	readInput(n, m);

	int minCuts = minConnectionsToSever(n);
	cout << "Minimum number of connections to sever: " << minCuts << endl;

	return 0;
}
