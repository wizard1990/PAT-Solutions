#include<iostream>
#include<string>
using namespace std;
class Money
{
private:
	int galleon;
	int sickle;
	int knut;
public:
	Money(int g=0, int s = 0, int k = 0)
		:galleon(g), sickle(s), knut(k)
	{}

	void print()
	{
		cout<<galleon<<"."<<sickle<<"."<<knut<<endl;
	}

	friend Money operator + (Money m1, Money m2)
	{
		int k = (m1.knut + m2.knut);
		int s = (m1.sickle + m2.sickle) + k / 29;
		int g = m1.galleon + m2.galleon + s / 17;
		k %= 29;
		s %= 17;
		return Money(g, s, k);
	}
};
Money getMoney()
{
	int g, s ,k;
	cin>>g;
	getchar();
	cin>>s;
	getchar();
	cin>>k;
	return Money(g, s, k);
}

int main()
{
	Money m1 = getMoney();
	Money m2 = getMoney();
	Money m = m1 + m2;
	m.print();
}