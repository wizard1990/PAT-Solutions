#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

string decToRadix(int x, int radix)
{
	string ans;
	while (x > 0){
		char ch = x % radix + '0';
		ans.insert(0,1,ch);
		x /= radix;
	}
	return ans;
}

int digitToDec(string num, int radix)
{
	int l = num.length();
	int ans = 0;
	int m = 1;
	for (int i = l - 1; i >= 0; i--){
		int digit = num[i] - '0';
		ans += m * digit;
		m *= radix;
	}
	return ans;
}

bool isPrime(int x)
{
	if(x < 2) return false;

	int most = x / 2;
	for (int i = 2; i <= most; i++){
		if(x % i == 0) return false;
	}
	return true;
}
int main()
{
	while(1){
		int n, d;
		scanf("%d",&n);
		if (n < 0) break;
		scanf("%d",&d);
		string s = decToRadix(n,d);
		string rs;
		rs.assign(s.rbegin(),s.rend());
		if(isPrime(digitToDec(s, d)) && isPrime(digitToDec(rs, d))) printf("Yes\n");
		else printf("No\n");
	}
}
