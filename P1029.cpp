#include<cstdio>
#include<queue>
using namespace std;
void inputQueue(int count, queue<int> &q)
{
	for (int i = 0; i < count; i++)
	{
		int num;
		scanf("%d",&num);
		q.push(num);
	}
}
int popQueue(queue<int> &q)
{
	int tmp = q.front();
	q.pop();
	return tmp;
}
int main()
{
	queue<int> q1,q2;
	int n1,n2;
	scanf("%d",&n1);
	inputQueue(n1,q1);
	scanf("%d",&n2);
	inputQueue(n2,q2);
	if (q1.back() < q2.back())
	{
		swap(q1,q2);
	}

	int ct = (n1 + n2) & 1 ? (n1+n2) / 2 + 1 : (n1+n2) / 2;
	for (int i = 0; i < ct - 1; i++)
	{
		if (q2.empty())
		{
			q1.pop();
		}
		else
		{
			q1.front() < q2.front() ? q1.pop() : q2.pop();
		}
	}

	int ans = 0;
	if (q2.empty())
	{
		ans = popQueue(q1);
	}
	else
	{
		q1.front() < q2.front() ? ans = popQueue(q1) : ans = popQueue(q2);
	}
	printf("%d\n",ans);
}