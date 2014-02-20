#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Node
{
public:
	int number;
	int level;
};

bool compare(const Node& n1, const Node& n2)
{
	if (n1.level != n2.level)
	{
		return n1.level < n2.level;
	}
	else return n1.number < n2.number;
}

int getBottomSub(int num)
{
	int m = 1;
	int k = 0;
	while (m - 1 < num)
	{
		m *= 2;
		k++;
	}
	int bottom = num + 1 - m / 2;
	if (bottom <= m / 4)
	{
		return bottom;
	}
	else
	{
		if (bottom == m / 2)
		{
			return 0;
		}
		else return m / 4 - bottom % (m / 4);
	}
}

void parse(int level, int head, int tail, vector<Node>& list)
{
	if (head == tail)
	{
		list[head].level = level;
		return;
	}
	int number = tail - head + 1;
	int s = getBottomSub(number);
	int root = head + s + (number - s) / 2;
	list[root].level = level;
	if(head <= root - 1) parse(level + 1, head, root - 1, list);
	if(tail >= root + 1) parse(level + 1, root + 1, tail, list);
}

int main()
{
	vector<Node> list;
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		Node p;
		p.level = -1;
		cin>>p.number;
		list.push_back(p);
	}
	sort(list.begin(), list.end(), compare);
	parse(0, 0, n-1, list);
	sort(list.begin(), list.end(), compare);
	for (int i = 0; i < n-1; i++)
	{
		cout<<list[i].number<<" ";
	}
	cout<<list[n-1].number;
}