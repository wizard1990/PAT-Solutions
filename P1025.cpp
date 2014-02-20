#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Player
{
public:
	string pid;
	int score;
	int locNum;
	int rank;
	int locRank;
	Player(string &id, int sc, int location)
	{
		pid = id;
		score = sc;
		locNum = location;
	}
};
bool compare(const Player &p1, const Player &p2)
{
	if (p1.score > p2.score)
	{
		return true;
	}
	else if (p1.score == p2.score)
	{
		return p1.pid < p2.pid;
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	vector<vector<Player>> list;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin>>m;
		vector<Player> gList;
		list.push_back(gList);
		for (int j = 0; j < m; j++)
		{
			string s;
			int sc;
			cin>>s>>sc;
			list[i].push_back(Player(s, sc, i+1));
		}
		sort(list[i].begin(),list[i].end(),compare);
		int leap = 1;
		for (int j = 0; j < list[i].size(); j++)
		{
			if (j == 0)
			{
				list[i][j].locRank = 1;
			}
			else
			{
				if (list[i][j].score == list[i][j-1].score)
				{
					list[i][j].locRank = list[i][j-1].locRank;
					leap++;
				}
				else
				{
					list[i][j].locRank = list[i][j-1].locRank + leap;
					leap = 1;
				}
			}
		}
	}
	vector<Player> totalList;
	for (int i = 0; i < n; i++)
	{
		totalList.insert(totalList.end(), list[i].begin(), list[i].end());
	}
	sort(totalList.begin(),totalList.end(),compare);

	cout<<totalList.size()<<endl;
	int leap = 1;
	for (int j = 0; j < totalList.size(); j++)
	{
		if (j == 0) {
			totalList[j].rank = 1;
		}
		else
		{
			if (totalList[j].score == totalList[j-1].score)
			{
				totalList[j].rank = totalList[j-1].rank;					
				leap++;
			}
			else
			{
				totalList[j].rank = totalList[j-1].rank + leap;
				leap = 1;
			}
		}
		cout<<totalList[j].pid<<" "<<totalList[j].rank<<" "<<totalList[j].locNum<<" "<<totalList[j].locRank<<endl;
	}
}