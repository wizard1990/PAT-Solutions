#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int flag;
class Person
{
public:
	string id;
	string name;
	int score;
};
bool compare(const Person& p1, const Person& p2)
{
	switch (flag)
	{
	case 1:
		return p1.id < p2.id;
	case 2:
		if (p1.name == p2.name)
		{
			return p1.id < p2.id;
		}
		return p1.name < p2.name;
	case 3:
		if (p1.score == p2.score)
		{
			return p1.id < p2.id;
		}
		return p1.score < p2.score;
	default:
		return false;
		break;
	}
}
int main()
{
	char pid[10];
	char pname[10];
	vector<Person> list;
	int n;
	cin>>n>>flag;
	for (int i = 0; i < n; i++)
	{
		Person p;
		scanf("%s%s%d",pid,pname,&p.score);
		p.id.assign(pid);
		p.name.assign(pname);
		list.push_back(p);
	}
	sort(list.begin(), list.end(), compare);
	for (int i = 0; i < n; i++)
	{
		Person *p = &list[i];
		strcpy(pid, p->id.c_str());
		strcpy(pname,p->name.c_str());
		printf("%s %s %d\n",pid, pname, p->score);
	}
}