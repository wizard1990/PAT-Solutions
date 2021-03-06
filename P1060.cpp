#include<stdio.h>
#include<string.h>
#define MAX 110
struct result{
    char r[MAX];
    int k;
};

result getResult(char a[MAX], int n) {
    result r;
    
    int index = 0 ;
    int firstPos = -1; //the position of first valueable number in a.
    int pointPos = -1; //the position of point.
    int i;
    for (i = 0; a[i] != 0; ++ i) {
        if (a[i] == '.') { //get position of point
            pointPos = i;
            continue;
        }
        
        if (a[i] == '0' && firstPos == -1) //ignore header 0s.
            continue;
        else {
            if (firstPos == -1 )
                firstPos = i;
            if (index < n)
                r.r[index ++] = a[i];
        }
    }
    r.r[index] = 0;
    
    if (pointPos == -1)
        pointPos = i;
    if (pointPos - firstPos < 0)
        r.k  = pointPos - firstPos + 1;
    else
        r.k = pointPos - firstPos;
    
    if (index == 0) { //zero case.
        int i;
        for (i = 0; i != n; ++ i)
            r.r[i] = '0';
        r.r[i] = 0;
        r.k = 0;
    }
    
    return r;
}

int main()
{
    int n;
    char a[MAX], b[MAX];
    scanf("%d%s%s", &n, a, b);
    result r1 = getResult(a, n);
    result r2 = getResult(b, n);
    
    if (strcmp(r1.r, r2.r) == 0 && r1.k == r2.k)
        printf("YES 0.%s*10^%d\n", r1.r, r1.k);
    else
        printf("NO 0.%s*10^%d 0.%s*10^%d\n", r1.r, r1.k, r2.r, r2.k);
    
}