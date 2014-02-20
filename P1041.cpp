#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n;
    int s = 0;
    int f[10010];
    memset(f,0,sizeof(f));
    int a[100010];
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        f[a[i]]++;
    }
    bool flag = false;
    for (int i = 0; i < n; i++){
        if(f[a[i]] == 1){
                   flag = true;
                   printf("%d\n",a[i]);
                   break;
        }
    }
    if(!flag) printf("None");
}
