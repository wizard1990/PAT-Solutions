#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int pos;
	int ch;
	for (int i = 0; i < min(s1.length(), s2.length()); i++)
	{
		if (s1[i] == s2[i] && s1[i] - 'A' >=0 && s1[i] - 'A' < 7 )
		{
			pos = i;
			ch = s1[i];
			break;
		}
	}
	switch (ch)
	{
	case 'A': cout<<"MON "; break;
	case 'B': cout<<"TUE "; break;
	case 'C': cout<<"WED "; break;
	case 'D': cout<<"THU "; break;
	case 'E': cout<<"FRI "; break;
	case 'F': cout<<"SAT "; break;
	case 'G': cout<<"SUN "; break;
	default:
		break;
	}
	for (int i = pos + 1; i < min(s1.length(), s2.length()); i++)
	{
		if (s1[i] == s2[i] && (isdigit(s1[i]) || (s1[i] - 'A' >= 0 && s1[i] - 'N' <= 0 )))
		{
			if (isdigit(s1[i]))
			{
				cout<<'0'<<s1[i]<<":";
			}
			else
			{
				cout<<10+(s1[i] - 'A')<<":";
			}
			break;
		}
	}
	for (int i = 0; i < min(s3.length(), s4.length()); i++)
	{
		if (s3[i] == s4[i] && isalpha(s3[i]))
		{
			if (i < 10)
			{
				cout<<"0"<<i;
			}
			else
			{
				cout<<i;
			}
			break;
		}
	}
}