#include<cstdio>
#include<vector>
using namespace std;
int main()
{
	int n;
	vector<int> list;
	list.push_back(0);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		int tmp;
		scanf("%d",&tmp);
		list.push_back(list[i-1] + tmp);
	}
	int m;
	scanf("%d",&m);
	for (int i = 0; i < m; i++)
	{
		int s, t;
		scanf("%d%d",&s, &t);
		if (s > t)
		{
			swap(s, t);
		}
		int dis = list[t-1] - list[s-1];
		printf("%d\n",min(dis, list[n] - dis));
	}
}