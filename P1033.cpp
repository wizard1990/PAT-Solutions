#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int c,d,dn;
	int n;
	double price[505];
	int dist[505];
	double currentGas = 0;
	scanf("%d%d%d%d",&c, &d, &dn, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf%d",&price[i], &dist[i]);
	}
	dist[n] = d;
	price[n] = -1;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (dist[i] > dist[j])
			{
				double tmp = dist[i];
				dist[i] = dist[j];
				dist[j] = tmp;
				tmp = price[i];
				price[i] = price[j];
				price[j] = tmp;
			}
			else
			{
				if (dist[i] == dist[j])
				{
					if (price[i] < price[j])
					{
						double tmp = dist[i];
						dist[i] = dist[j];
						dist[j] = tmp;
						tmp = price[i];
						price[i] = price[j];
						price[j] = tmp;
					}
				}
			}
		}
	}
	int index = 0;
	if (dist[0] != 0)
	{
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	double cost = 0;
	int dis = c * dn;
	while (index < n) {
		int j = index + 1;
		if (dis + dist[index] < dist[j])
		{
			printf("The maximum travel distance = %.2lf",(double)dis + dist[index]);
			return 0;
		}
		int min = price[j];
		int minIndex = j;
		while (price[j] > price[index] && dist[j] <= dist[index] + dis)
		{
			if (price[j] <= min)
			{
				min = price[j];
				minIndex = j;
			}
			j++;
		}

		if (dist[j] > dis + dist[index])
		{
			//move to minIndex
			cost += price[index] * (c - currentGas);
			currentGas = c - (dist[minIndex] - dist[index]) / (double)dn;
			index = minIndex;
		}
		else
		{
			//move to j
			cost += price[index] * ((dist[j] - dist[index]) / (double)dn - currentGas);
			currentGas = 0;
			index = j;
		}
	}
	printf("%.2lf",cost);
}