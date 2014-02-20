#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
using namespace std;

int f[10010];
int d[10010];
vector<int> g[10010];

int getFather(int x)
{
	if (f[x] == x)
	{
		return x;
	}
	f[x] = getFather(f[x]);
	return f[x];
}
void merge(int x, int y)
{
	int father = getFather(x);
	f[y] = father;
}

bool judge(int x, int y)
{
	int fx = getFather(x);
	int fy = getFather(y);
	return fx == fy;
}

int bfs(int head)
{
	memset(d,-1,sizeof(d));
	d[head] = 0;
	queue<int> q;
	q.push(head);
	int dmax = 0;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < g[now].size(); i++)
		{
			int p = g[now][i];
			if (d[p] == -1)
			{
				d[p] = d[now]+1;
				q.push(p);
				if (d[p] > dmax)
				{
					dmax = d[p];
				}
			}
		}
	}
	return dmax;
}

int main()
{
	int n;
	set<int> pSet;
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < n-1; i++)
	{
		int n1, n2;
		cin>>n1>>n2;
		merge(n1, n2);
		g[n1].push_back(n2);
		g[n2].push_back(n1);
	}

	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (f[i] == i)
		{
			count++;
		}
	}

	if (count > 1)
	{
		cout<<"Error: "<<count<<" components"<<endl;
	}
	else
	{
		int maxLen = bfs(1);
		for (int i = 1; i <= n; i++)
		{
			if (d[i] == maxLen)
			{
				pSet.insert(i);
			}
		}
		maxLen = bfs(*pSet.begin());
		for (int i = 1; i <= n; i++)
		{
			if (d[i] == maxLen)
			{
				pSet.insert(i);
			}
		}
		for (set<int>::iterator iter = pSet.begin();iter != pSet.end(); iter++)
		{
			cout<<*iter<<endl;
		}
	}
}