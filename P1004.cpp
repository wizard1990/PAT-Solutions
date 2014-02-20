#include<cstdio>
#include<cstring>
using namespace std;
int getLevel(int x);
struct Node
{
       int id;
       int father;
       int level;
	   int sonNum;
};
int maxL = 0;
Node a[110];
int main()
{
    int n, m;
    for (int i = 0; i < 110; i++){
        a[i].id = a[i].level = a[i].father = -1;
		a[i].sonNum = 0;
    }
    int f[110];
    
    a[1].father = 1;
    memset(f,0,sizeof(f));
    scanf("%d%d",&n,&m);
	if (m == 0) f[0] = 1;
    
    for (int i = 0; i < m; i++) {
        int k;
		int id;
        scanf("%d",&id);
        scanf("%d",&k);
        a[id].sonNum = k;
		a[id].id = id;
		if(id == 1) a[id].father = 1;

        for (int j = 0; j < k; j++){
            int son;
            scanf("%d",&son);
			a[son].id = son;
			a[son].father = id;
        }
    }
    for (int i = 0; i <= n; i++){
		if (a[i].id != -1 && a[i].level == -1){
			int lv = getLevel(i);
		}
		if (a[i].id != -1 && a[i].sonNum == 0){
			f[a[i].level]++;
		}
	}
		
    for (int i = 0; i < maxL; i++) {
        printf("%d ",f[i]);
    }
	printf("%d",f[maxL]);
}

int getLevel(int x)
{
    if(a[x].father == x) return 0;
    int lv = getLevel(a[x].father);
    a[x].level = lv+1;
	if(a[x].level > maxL) maxL = a[x].level;
    return a[x].level;
}
