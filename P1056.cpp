#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Mouse
{
public:
	Mouse():
		weight(0),order(0),rank(0)
	{};
	int weight;
	int order;
	int rank;
};
bool compare(const Mouse* m1, const Mouse* m2)
{
	return m1->order < m2->order;
}
bool match(vector<Mouse*>& waitList, vector<Mouse*>& finishList, int gNum)
{
	if (waitList.size() == 1)
	{
		return false;
	}
	int max = -1;
	int group = -1;
	int count = 0;
	for (int i = 0; i <= waitList.size(); i++)
	{
		if (group != i / gNum || i == waitList.size())
		{
			if (group != -1)
			{
				for (int j = gNum*group; j < min((group+1)*gNum, (int)waitList.size()); j++)
				{
					if (waitList[j]->weight != max)
					{
						waitList[j]->rank = 1;
						count++;
					}
				}
			}
			if (i < waitList.size())
			{
				max = waitList[i]->weight;
				group = i / gNum;
			}
		}
		else
		{
			if (waitList[i]->weight > max)
			{
				max = waitList[i]->weight;
			}
		}
	}

	int rankNum = waitList.size() - count + 1;
	for (vector<Mouse*>::iterator iter = waitList.begin(); iter != waitList.end();)
	{
		if ((*iter)->rank == 1)
		{
			(*iter)->rank = rankNum;
			finishList.push_back(*iter);
			iter = waitList.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	return true;
}

int main()
{
	int n, g;
	int orderList[1010];
	vector<Mouse*> list;
	vector<Mouse*> finishedList;
	cin>>n>>g;
	for (int i = 0; i < n; i++)
	{
		cin>>orderList[i];
	}

	for (int i = 0; i < n; i++)
	{
		int order;
		cin>>order;
		Mouse* m = new Mouse();
		m->weight = orderList[order];
		m->order = order;
		list.push_back(m);
	}

	while (match(list, finishedList, g));
	list[0]->rank = 1;
	finishedList.push_back(list[0]);
	list.clear();
	sort(finishedList.begin(), finishedList.end(), compare);

	for (int i = 0; i < n - 1; i++)
	{
		cout<<finishedList[i]->rank<<" ";
	}
	cout<<finishedList[n-1]->rank;

	for (vector<Mouse*>::iterator iter = finishedList.begin(); iter!=finishedList.end();)
	{
		delete *iter;
		iter = finishedList.erase(iter);
	}
}