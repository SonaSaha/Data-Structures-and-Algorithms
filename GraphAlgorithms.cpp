#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

typedef std::vector<std::vector<int>> adjacent_list;
typedef std::vector<std::vector<bool>> adjacent_matrix;

adjacent_list ReadGraphAsAdjasentList(bool directed = true)
{
	int n, m;
	std::cin >> n >> m;
	adjacent_list list(n);
	for (int i = 0; i < m; ++i)
	{
		int a1, a2;
		std::cin >> a1 >> a2;
		list[a1].push_back(a2);
		if (!directed)
		{
			list[a2].push_back(a1);
		}
	}
	return list;
}
void DFSRecursive(adjacent_list& graph, int v, std::vector<bool>& visited)
{
	visited[v] = true;
	for (int vertex : graph[v])
	{
		if (!visited[vertex])
		{
			DFSRecursive(graph, vertex, visited);
		}
	}
}
void DFSIterative(adjacent_list& graph, int v, std::vector<bool>& visited)
{
	std::stack<int> NodeStack;
	NodeStack.push(v);
	while (!NodeStack.empty())
	{
		int elem = NodeStack.top();
		NodeStack.pop();
		if (!visited[elem])
		{
			std::cout << elem << " ";
			visited[elem] = true;
		}
		for (int i : graph[elem])
		{
			if (!visited[i])
			{
				NodeStack.push(i);
			}
		}
	}
}
void BFSRecursive(adjacent_list& graph, std::queue<int>& q, std::vector<bool>& visited)
{
	if (q.empty())
		return;
	int v = q.front();
	q.pop();
	std::cout << v << " ";
	for (int u : graph[v])
	{
		if (!visited[u])
		{
			visited[u] = true;
			q.push(u);
		}
	}
	BFSRecursive(graph, q, visited);
}
void BFSIterative(adjacent_list& graph, int v, std::vector<bool>& visited)
{
	std::queue<int> q;
	q.push(v);
	visited[v] = true;
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		std::cout << v << " ";
		for (int u : graph[v])
		{
			if (!visited[u])
			{
				q.push(u);
				visited[u] = true;
			}
		}

	}
}
enum class color
{
	not_set,
	red,
	blue
};
color get_opposite(color c)
{
	return c == color::red ? color::blue : color::red;
}

bool is_Bipartite_bfs(adjacent_list& graph, int start_v, std::vector<color>& colors)
{
	std::queue<int> q;
	q.push(start_v);
	colors[start_v] = color::blue;
	while (!q.empty())
	{
		int cur_vertex = q.front();
		q.pop();
		for (int neighbour : graph[cur_vertex])
		{
			if (colors[neighbour] == color::not_set)
			{
				q.push(neighbour);
				colors[neighbour] == get_opposite(colors[cur_vertex]);
			}
			else if (colors[neighbour] == colors[cur_vertex])
			{
				return false;
			}
		}

	}
	return true;
}

std::vector<int> compareTriplets(std::vector<int> a, std::vector<int> b)
{
	std::vector<int> out(2, 0);
	for (int i = 0; i < a.size(); ++i)
	{
		if (a[i] != b[i])
		{
			if (a[i] < b[i])
				++out[1];
			else ++out[0];
		}
		return out;
	}
}
int main()
{
	/*adjacent_list graph = ReadGraphAsAdjasentList(false);
	std::vector<bool> visited(graph.size(),false);
	//DFSIterative(graph, 3, visited);
	std::queue<int> q;
	q.push(0);
	//BFSRecursive(graph, q, visited);
	//BFSIterative(graph, 1, visited);
	std::vector<color> colors(graph.size(), color::not_set);
	for (int i = 0; i < graph.size(); ++i)
	{
		if (colors[i] == color::not_set)
		{
			if (!is_Bipartite_bfs(graph, i, colors))
			{
				std::cout << "Not bicolorable";
				return false;
			}
		}
	}

	std::cout << "bicolorable";
	*/
	std::vector<int> v1({ 1,2,3 });
	std::vector<int> v2({ 3,2,1 });
	std::vector<int> out = compareTriplets(v1, v2);
	std::cout << out[0] << " " << out[1];
}