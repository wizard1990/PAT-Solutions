#include<iostream>
using namespace std;

long long sum(long long n)
{
	long long iCount = 0;
	long long iFactor = 1;
	long long iLowerNum = 0;
	long long iCurrNum = 0;
	long long iHigherNum = 0;

	while(n / iFactor != 0) {
		iLowerNum = n - (n / iFactor) * iFactor;
		iCurrNum = (n / iFactor) % 10;
		iHigherNum = n / (iFactor * 10);

		switch (iCurrNum)
		{
		case 0:
			iCount += iHigherNum * iFactor;
			break;
		case 1:
			iCount += iHigherNum * iFactor + iLowerNum + 1;
			break;
		default:
			iCount += (iHigherNum + 1) * iFactor;
			break;
		}
		iFactor *= 10;
	}
	return iCount;
}
int main()
{
	long long n;
	cin>>n;
	long long ans = sum(n);
	cout<<ans;
}