#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

double mergeSet(vector<int> v1, vector<int> v2)
{
    vector<int> list;
    int n1 = (int)v1.size();
    int n2 = (int)v2.size();
    if (v1[n1-1] < v2[n2-1]) {
        v1.swap(v2);
        int tmp = n1;
        n1 = n2;
        n2 = tmp;
    }
    int p1 = 0;
    int p2 = 0;
    while (p2 < n2) {
        if (v1[p1] >= v2[p2]) {
            list.push_back(v2[p2]);
            p2++;
        }
        else {
            list.push_back(v1[p1]);
            p1++;
        }
    }
    while (p1 < n1) {
        list.push_back(v1[p1]);
        p1++;
    }
    int nc = 0;
    int nt = 0;
    for (int i = 0; i < list.size(); i++) {
        if (i == 0) {
            nt++;
        }
        else {
            if (list[i] == list[i-1]) {
                nc++;
            }
            else {
                nt++;
            }
        }
    }
    return (double)nc / (double)nt;
}

int main(int argc, const char * argv[])
{
    int n, k;
    vector<int> numSet[50];
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d",&m);
        for (int j = 0; j < m; j++) {
            int num;
            scanf("%d",&num);
            numSet[i].push_back(num);
        }
        sort(numSet[i].begin(), numSet[i].end());
        for (vector<int>::iterator iter = numSet[i].begin(); iter != numSet[i].end();) {
            if (iter != numSet[i].begin() && *iter == *(iter - 1)) {
                iter = numSet[i].erase(iter);
            }
            else iter++;
        }
    }
    scanf("%d",&k);
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d%d",&a, &b);
        printf("%.1lf%%\n",100*mergeSet(numSet[a-1], numSet[b-1]));
    }
    return 0;
}