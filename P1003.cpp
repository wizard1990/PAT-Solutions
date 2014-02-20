#include<cstdio>
#include<cstring>
using namespace std;
struct pathNode
{
	int distance;
	int pathNum;
	bool checked;
	int teams;
};
int n,m,c1,c2;
int teams[510];
int g[510][510];
pathNode dist[510];

void dijkstra(int start)
{
	for (int i = 0; i < n - 1; i++){
		int minLen = 99999999;
		int minIndex;
		for(int j = 0; j < n; j++){
			if(dist[j].checked == false && dist[j].distance < minLen){
				minLen = dist[j].distance;
				minIndex = j;
			}
		}
		dist[minIndex].checked = true;
		for (int j = 0; j < n; j++){
			if(dist[j].checked == false && (dist[minIndex].distance + g[minIndex][j] < dist[j].distance)){
				dist[j].distance = dist[minIndex].distance + g[minIndex][j];
				dist[j].pathNum = dist[minIndex].pathNum;
				dist[j].teams = dist[minIndex].teams + teams[j];
			}
			else if (dist[j].checked == false && (dist[minIndex].distance + g[minIndex][j] == dist[j].distance)){
				dist[j].pathNum += dist[minIndex].pathNum;
				if (dist[j].teams < dist[minIndex].teams + teams[j]) dist[j].teams = dist[minIndex].teams + teams[j];
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 510; i++){
		dist[i].checked = false;
		for (int j = 0; j < 510; j++){
			if(i == j) g[i][j] = 0;
			else g[i][j] = 99999999;
		}
	}
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	for (int i = 0; i < n; i++){
		scanf("%d",&teams[i]);
	}
	for (int i = 0; i < m; i++){
		int from, to, dis;
		scanf("%d%d%d",&from, &to, &dis);
		g[from][to] = g[to][from] = dis;
	}

	dist[c1].checked = true;
	dist[c1].distance = 0;
	dist[c1].pathNum = 1;
	dist[c1].teams = teams[c1];
	for (int i = 0; i < n; i++){
		if(i != c1){
			dist[i].checked = false;
			dist[i].distance = g[c1][i];
			if (dist[i].distance < 99999999){
				dist[i].pathNum = 1;
				dist[i].teams = dist[c1].teams + teams[i];
			}
			else {
				dist[i].pathNum = 0;
				dist[i].teams = 0;
			}
		}
	}

	dijkstra(c1);
	printf("%d %d",dist[c2].pathNum, dist[c2].teams);
}