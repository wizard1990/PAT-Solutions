#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

inline int min(int x, int y)
{
    return x < y ? x : y;
}

class TimeStamp {
    int hour;
    int minute;
    int second;
public:
    TimeStamp():
    hour(0),minute(0),second(0){};
    TimeStamp(const int& h, const int& m, const int& s):
    hour(h),minute(m),second(s){};
    TimeStamp(const TimeStamp &t):
    hour(t.hour),minute(t.minute),second(t.second){};
    
    TimeStamp(const string &s);
    TimeStamp(const int &t);
    
    bool operator < (const TimeStamp& t);
    bool operator == (const TimeStamp& t);
    void operator += (const TimeStamp& t);
    friend TimeStamp operator + (const TimeStamp& t1, const TimeStamp& t2);
    friend TimeStamp operator - (const TimeStamp& t1, const TimeStamp& t2);
    
    string printTime();
    double toMinute();
};

struct Customer {
    TimeStamp arriveTime;
    int waitMinute;
};

TimeStamp::TimeStamp(const string &s)
{
    if (s.length() != 8) {
        *this = TimeStamp();
    }
    else{
        hour = (s[0] - '0')*10 + (s[1] - '0');
        minute = (s[3] - '0')*10 + (s[4] - '0');
        second = (s[6] - '0')*10 + (s[7] - '0');
    }
}
TimeStamp::TimeStamp(const int& t)
{
    hour = t / 3600;
    minute = (t - hour*3600) / 60;
    second = t % 60;
}

bool TimeStamp::operator<(const TimeStamp& t)
{
    if (hour < t.hour) {
        return true;
    }
    else if (hour == t.hour) {
        if (minute < t.minute) {
            return true;
        }
        else if (minute == t.minute) {
            if (second < t.second) {
                return true;
            }
        }
    }
    return false;
}

bool TimeStamp::operator==(const TimeStamp& t)
{
    return hour==t.hour && minute==t.minute && second==t.second;
}

void TimeStamp::operator += (const TimeStamp& t)
{
    int s = second + t.second;
    int h = hour + t.hour;
    int m = minute + t.minute;
    if (s >= 60) {
        s %= 60;
        m++;
    }
    if (m >= 60) {
        m %= 60;
        h++;
    }
    hour = h;
    minute = m;
    second = s;
}

string TimeStamp::printTime()
{
    string sh(""), sm(""), ss("");
    
    sh += '0' + hour / 10;
    sh += '0' + hour % 10;
    
    sm += '0' + minute / 10;
    sm += '0' + minute % 10;
    
    ss += '0' + second / 10;
    ss += '0' + second % 10;
    
    return sh+':'+sm+':'+ss;
}

double TimeStamp::toMinute()
{
    return hour * 60 + minute + second / 60.0;
}

TimeStamp operator - (const TimeStamp& t1, const TimeStamp& t2)
{
    int s = t1.second - t2.second;
    int h = t1.hour - t2.hour;
    int m = t1.minute - t2.minute;
    if (m < 0) {
        m += 60;
        h--;
    }
    if (s < 0) {
        s += 60;
        m--;
    }
    return TimeStamp(h, m, s);
}
TimeStamp operator + (const TimeStamp& t1, const TimeStamp& t2)
{
    TimeStamp t(t1);
    t += t2;
    return t;
}

bool compare(Customer c1, Customer c2)
{
    return c1.arriveTime < c2.arriveTime;
}

int main()
{
    int n, k;
    TimeStamp due("17:00:01");
    TimeStamp start("08:00:00");
    vector<Customer> list;
    scanf("%d%d",&n,&k);
    int totalCount = n;
    for (int i = 0; i < n; i++) {
        string s;
        int m;
        cin>>s>>m;
        Customer c;
        c.arriveTime = TimeStamp(s);
        c.waitMinute = m;
        if (c.arriveTime < due) {
            list.push_back(c);
        }
        else totalCount--;
    }
    n = totalCount;
    sort(list.begin(), list.end(), compare);
    int pos = min(k, (int)list.size());
    TimeStamp total = 0;
    for (int i = 0; i < pos; i++) {
        if (list[i].arriveTime < start) {
            total += start - list[i].arriveTime;
            list[i].arriveTime = start;
        }
    }
    
    while (pos < totalCount) {
        TimeStamp minLeave = list[0].arriveTime + list[0].waitMinute * 60;
        int minIndex = 0;
        for (int i = 1; i < k; i++) {
            TimeStamp leaveTime = list[i].arriveTime + list[i].waitMinute * 60;
            if (leaveTime < minLeave) {
                minLeave = leaveTime;
                minIndex = i;
            }
        }
        if (list[pos].arriveTime < minLeave) {
            total += minLeave - list[pos].arriveTime;
            list[pos].arriveTime = minLeave;
        }
        totalCount--;
        vector<Customer>::iterator iter = list.begin() + minIndex;
        list.erase(iter);
    }
    if(n == 0){
        printf("0.0");
    }
    else printf("%.1lf",total.toMinute() / n);
}