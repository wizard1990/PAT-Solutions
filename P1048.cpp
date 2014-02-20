#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n, m;
	int hash[501];
	memset(hash, 0, sizeof(hash));
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; i++)
	{
		int face;
		scanf("%d",&face);
		hash[face]++;
	}
	int maxf = min(m-1,500);
	bool flag = false;
	for (int i = 1; i <= maxf; i++)
	{
		if (hash[i])
		{
			hash[i]--;
			int other = m - i;
			if (other > 500)
			{
				continue;
			}
			if (hash[other])
			{
				printf("%d %d", i, other);
				flag = true;
				break;
			}
			hash[i]++;
		}
	}
	if (!flag)
	{
		printf("No Solution");
	}
}