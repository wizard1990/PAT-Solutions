#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
using namespace std;
int n, m;
int finish[1010];
int wtime[1010];
int totalTime;

struct Customer
{
	int num;
	int waitTime;
};

string minuteToTime(int minute)
{
	stringstream ss;
	int h = (minute + 480) / 60;
	int m = (minute + 480) % 60;
	if(h < 10){
		ss<<'0';
	}
	ss<<h;
	ss<<':';
	if(m < 10){
		ss<<'0';
	}
	ss<<m;
	return ss.str();
}

bool isFull(Customer lines[][100])
{
	for (int i = 0; i < n; i++){
		if(lines[i][0].num < m) return false;
	}
	return true;
}

bool isEmpty(Customer lines[][100])
{
	for (int i = 0; i < n; i++){
		if(lines[i][0].num > 0) return false;
	}
	return true;
}

bool addCustomer(Customer& customer, Customer lines[][100])
{
	int shortest = m;
	int shortestLine = -1;
	for (int i = 0; i < n; i++){
		if(lines[i][0].num < shortest) {
			shortest = lines[i][0].num;
			shortestLine = i;
		}
	}
	if (shortestLine == -1)
	{
		return false;
	}
	else
	{
		int pos = ++lines[shortestLine][0].num;
		lines[shortestLine][pos] = customer;
		return true;
	}
}

void processCustomer(Customer lines[][100])
{
	int minCus = 999999;
	for (int i = 0; i < n; i++){
		if(lines[i][0].num > 0 && lines[i][1].waitTime < minCus) {
			minCus = lines[i][1].waitTime;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (lines[i][0].num > 0 && lines[i][1].waitTime == minCus)
		{
			finish[lines[i][1].num] = totalTime + minCus;
			for (int j = 2; j <= lines[i][0].num; j++)
			{
				lines[i][j-1] = lines[i][j];
			}
			lines[i][0].num--;
		}
		else if (lines[i][0].num > 0)
		{
			lines[i][1].waitTime -= minCus;
		}
	}
	if(minCus < 999999) totalTime+=minCus;
}

int main()
{
	int k,q;
	Customer lines[20][100];
	memset(lines,0,sizeof(lines));
	for(int i = 0; i < 1010; i++)
		finish[i] = -1;
	cin>>n>>m>>k>>q;
	for (int i = 0; i < k; i++){
		Customer cus;
		cus.num = i;
		cin>>cus.waitTime;
		wtime[i] = cus.waitTime;
		bool ret = addCustomer(cus, lines);
		if(!ret){
			processCustomer(lines);
			addCustomer(cus, lines);
		}
	}
	while(!isEmpty(lines)) {
		processCustomer(lines);
	}
		
	for (int i = 0; i < q; i++){
		int cnum;
		cin>>cnum;
		(finish[cnum-1]>=0 && finish[cnum-1] - wtime[cnum-1]<540) ? cout<<minuteToTime(finish[cnum-1])<<endl : cout<<"Sorry"<<endl;
	}
}