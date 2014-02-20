#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
struct Item
{
	int compo;
	double coe;
};
int main()
{
	vector<Item> numA;
	vector<Item> numB;
	int kA,kB;
	scanf("%d", &kA);
	for (int i = 0; i < kA; i++){
		Item tmp;
		scanf("%d %lf", &tmp.compo, &tmp.coe);
		numA.push_back(tmp);
	}
	scanf("%d", &kB);
	for (int i = 0; i < kB; i++){
		Item tmp;
		scanf("%d %lf", &tmp.compo, &tmp.coe);
		numB.push_back(tmp);
	}
	
	map<int,double> product;
	for (int i = 0; i < kA; i++){
		for (int j = 0; j < kB; j++){
			double coefficient = numB[j].coe * numA[i].coe;
			int component = numA[i].compo + numB[j].compo;
			if (product.count(component)){
				product[component] += coefficient;
			}
			else product[component] = coefficient;
		}
	}
	map<int,double>::iterator it;
    //原来第一个test case一直过不了的原因是因为精度的问题。
    for (it = product.begin(); it != product.end();) {
		if (fabs(it->second) <= 1e-10) //此时可以认为是0
        {
            it = product.erase(it);
        }
        else
            it++;
    }

	printf("%d",product.size());
	if(product.size() > 0){
		map<int,double>::iterator i = product.end();
		i--;
		for (;i != product.begin(); i--){
			printf(" %d %.1lf",i->first,i->second);
		}
		i = product.begin();
		printf(" %d %.1lf",i->first,i->second);
	}
}