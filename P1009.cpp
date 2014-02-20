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
    //ԭ����һ��test caseһֱ�����˵�ԭ������Ϊ���ȵ����⡣
    for (it = product.begin(); it != product.end();) {
		if (fabs(it->second) <= 1e-10) //��ʱ������Ϊ��0
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