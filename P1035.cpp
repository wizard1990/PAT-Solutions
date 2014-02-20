#include<iostream>
#include<vector>
#include<string>
using namespace std;
class User
{
public:
	string userName;
	string password;
};
bool replaceChar(string& s)
{
	bool flag = false;
	int l = s.length();
	for (int i = 0; i < l; i++)
	{
		if (s[i] == '1')
		{
			s[i] = '@';
			flag = true;
		}
		if (s[i] == '0')
		{
			s[i] = '%';
			flag = true;
		}
		if (s[i] == 'l')
		{
			s[i] = 'L';
			flag = true;
		}
		if (s[i] == 'O')
		{
			s[i] = 'o';
			flag = true;
		}
	}
	return flag;
}
void noCorrectionHint(int num)
{
	if(num == 1) 
	{
		cout<<"There is 1 account and no account is modified"<<endl;
	}
	else
	{
		cout<<"There are "<<num<<" accounts and no account is modified"<<endl;
	}
}
int main()
{
	int n;
	cin>>n;
	vector<User> list;
	for (int i = 0; i < n; i++)
	{
		User p;
		cin>>p.userName>>p.password;
		if (replaceChar(p.password))
		{
			list.push_back(p);
		}
	}
	if (list.empty())
	{
		noCorrectionHint(n);
	}
	else
	{
		cout<<list.size()<<endl;
		for (int i = 0; i < list.size(); i++)
		{
			cout<<list[i].userName<<" "<<list[i].password<<endl;
		}
	}
}
