#include<cstdio>
using namespace std;
int main()
{
	int m, n, currentColor, count = 0;
	scanf("%d%d",&m, &n);
	for (int i = 0; i < m*n; i++)
	{
		int color;
		scanf("%d", &color);
		if (!count)
		{
			currentColor = color;
			count = 1;
		}
		else
		{
			currentColor == color ? count++ : count--;
		}
	}
	printf("%d",currentColor);
}