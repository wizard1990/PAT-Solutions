#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int nc;
	int np;
	vector<int>listC;
	vector<int>listP;
	scanf("%d",&nc);
	for(int i = 0; i < nc; i++){
		int coupon;
		scanf("%d",&coupon);
		listC.push_back(coupon);
	}
	scanf("%d",&np);
	for (int i = 0; i < np; i++){
		int product;
		scanf("%d",&product);
		listP.push_back(product);
	}
	sort(listC.begin(),listC.end());
	sort(listP.begin(),listP.end());
	int lc = listC.size();
	int lp = listP.size();
	
	int sum = 0;
	int j = 0;
	for (int i = 0; i < lc; i++){
		if(j > lp - 1 || listP[j] >= 0 || listC[i]>= 0) break;
		sum += listC[i] * listP[j];
		j++;
	}
	j = lp - 1;
	for (int i = lc - 1; i >= 0; i--){
		if (j < 0 || listP[j] <= 0 || listC[i] <= 0) break;
		sum += listC[i] * listP[j];
		j--;
	}
	printf("%d",sum);
}