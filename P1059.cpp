#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> list;

void findPrimeFactor(int num)
{
	if (num < 2)
	{
		return;
	}

	int factor = -1;
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			factor = i;
			break;
		}
	}
	if (factor > 0)
	{
		findPrimeFactor(num / factor);
		findPrimeFactor(factor);
	}
	else
	{
		list.push_back(num);
	}
}

int main()
{
	int n;
	cin>>n;
	findPrimeFactor(n);
	sort(list.begin(),list.end());

	int count = 1;
	if (list.empty())
	{
		cout<<n<<"="<<n<<endl;
	}
	else
	{
		cout<<n<<"=";
		for (int i = 0; i < list.size(); i++)
		{
			if (i == 0)
			{
				cout<<list[i];
			}
			else
			{
				if (list[i] == list[i-1])
				{
					count++;
					continue;
				}
				else
				{
					if (count == 1)
					{
						cout<<"*"<<list[i];
					}
					else
					{
						cout<<"^"<<count<<"*"<<list[i];
						count = 1;
					}
				}
			}
		}
	}
	if (count > 1)
	{
		cout<<"^"<<count<<endl;
	}
	else
	{
		cout<<endl;
	}
}