#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> node[105];
int weight[105];
vector<vector<int>> pathList;
int s;

bool compare(const vector<int> &path1, const vector<int> &path2)
{
	for (int i = 0; i < min(path1.size(), path2.size()); i++)
	{
		if (path1[i] != path2[i])
		{
			return path1[i] > path2[i];
		}
	}
	return *(path1.end()-1) > *(path2.end()-1); 
}

bool isLeaf(int id)
{
	return node[id].size() == 0;
}

void dfs(int parent, int sum, vector<int> path)
{
	sum += weight[parent];
	path.push_back(weight[parent]);
	if (!isLeaf(parent) && sum >= s)
	{
		return;
	}

	if (isLeaf(parent))
	{
		if (sum != s)
		{
			return;
		}
		else
		{
			pathList.push_back(path);
			return;
		}
	}

	for (int i = 0; i < node[parent].size(); i++)
	{
		dfs(node[parent][i], sum, path);
	}
}

int main()
{
	int n, m;
	cin>>n>>m>>s;
	for (int i = 0; i < n; i++)
	{
		cin>>weight[i];
	}
	for (int i = 0; i < m; i++)
	{
		int parent, k;
		cin>>parent>>k;
		for (int j = 0; j < k; j++)
		{
			int child;
			cin>>child;
			node[parent].push_back(child);
		}
	}
	vector<int> path;
	dfs(0, 0, path);
	sort(pathList.begin(), pathList.end(), compare);
	for (int i = 0; i < pathList.size(); i++)
	{
		for (int j = 0; j < pathList[i].size() - 1; j++)
		{
			cout<<pathList[i][j]<<" ";
		}
		cout<<pathList[i][pathList[i].size()-1]<<endl;
	}
}