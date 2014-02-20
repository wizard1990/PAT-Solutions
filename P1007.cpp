#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n;
    int a[10010];
    scanf("%d",&n);
    int max = -1;
    int sum = 0;
    int tst = 0;
    int st, ed = 0;
    
    bool flag = false;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] >= 0) flag = true;
    }
    if (!flag) {
       printf("0 %d %d\n",a[0],a[n-1]);
    }
    else {
         tst = a[0];
         for (int i = 0; i < n; i++) {
             sum += a[i];
             if (sum > max) {
                     max = sum;
                     ed = a[i];
                     st = tst;
             }
             else if (sum < 0) {
                  sum = 0;
                  tst = a[i + 1];
             }
         }
         printf("%d %d %d\n",max,st,ed);
    }
    return 0;
}
