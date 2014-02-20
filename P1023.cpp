#include<string>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int f[10];
	memset(f,0,sizeof(f));
	string s,ds;
	cin>>s;
	string::iterator it;
	for(it = s.begin(); it != s.end(); it++){
		int digit = *it - '0';
		char ch = '0' + digit*2; 
		ds += ch;
		f[digit]++;
	}
	for(int i = ds.length() - 1; i > 0; i--){
		if(ds[i] > '9'){
			ds[i - 1]++;
			ds[i] = '0' + (ds[i] - '0')%10;
		}
	}
	int carry = (ds[0] - '0') / 10;
	ds[0] = '0' + (ds[0] - '0')%10;

	for(int i = 0; i < ds.length(); i++){
		int digit = ds[i] - '0';
		f[digit]--;
	}
	bool flag = true;
	for(int i = 0; i < 10; i++){
		if(f[i] != 0){
			flag = false;
			break;
		}
	}
	if(flag){
		cout<<"Yes"<<endl;
	}
	else cout<<"No"<<endl;

	if(carry) cout<<carry;
	cout<<ds<<endl;
}