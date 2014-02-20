#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int hash[10000];
	memset(hash, 0, sizeof(hash));
	char s1[10001];
	char s2[10001];
	gets(s1);
	gets(s2);
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	for (int i = 0; i < l2; i++)
	{
		hash[s2[i]] = 1;
	}
	for (int i = 0; i < l1; i++)
	{
		if (hash[s1[i]])
		{
			continue;
		}
		else
		{
			printf("%c",s1[i]);
		}
	}
}