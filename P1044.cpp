#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> minList;

int main()
{
    int n, s;
    
    scanf("%d%d",&n, &s);
    vector<int> list(n+1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d",&list[i]);
    }
    int h, t;
    h = t = 0;
    int min = -1;
    int sum = list[0];
    while (h < n && t < n) {
        if (sum >= s) {
            if (sum <= min || min < 0) {
                if (sum < min) {
                    minList.clear();
                }
                min = sum;
                minList.push_back(make_pair(h, t));
            }
        }
        
        if (sum == s) {
            sum -= list[h];
            h++;
            t++;
            sum += list[t];
            continue;
        }
        
        if (sum > s) {
            sum -= list[h];
            h++;
            continue;
        }
        
        if (sum < s) {
            t++;
            sum += list[t];
        }
    }
    
    for (vector<pair<int, int>>::iterator iter = minList.begin(); iter != minList.end(); iter++) {
        printf("%d-%d\n",iter->first + 1, iter->second + 1);
    }
}