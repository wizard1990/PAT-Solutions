#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int compareSub(string s1, string s2)
{
	int l1 = s1.length();
	int l2 = s2.length();
	
	for (int i = 0; i < min(l1,l2); i++)
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] < s2[i])
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
	}
	if (l1 == l2)
	{
		return 0;
	}
	if (l1 < l2)
	{
		return compareSub(s1, s2.substr(l1, l2-l1));
	}
	else
	{
		return compareSub(s1.substr(l2, l1-l2), s2);
	}
}
bool compare(string num1, string num2)
{
	int ans = compareSub(num1, num2);
	if (ans > 0)
	{
		return true;
	}
	return false;
}
int main()
{
	int n;
	char str[9];
	vector<string> list;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s",str);
		string num;
		num.assign(str);
		list.push_back(num);
	}
	sort(list.begin(), list.end(), compare);
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (flag)
		{
			printf("%s",list[i].c_str());
		}
		else
		{
			for (int j = 0; j < list[i].length(); j++)
			{
				if (flag)
				{
					putchar(list[i][j]);
				}
				else
				{
					if (list[i][j] == '0') continue;
					else
					{
						putchar(list[i][j]);
						flag = true;
					}
				}
			}
		}
	}
	if (!flag)
	{
		printf("0");
	}
}
