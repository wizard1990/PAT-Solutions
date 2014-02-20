#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

bool check(const string &s);
string plusDigit(const string &s1, const string &s2);
string &revert(string &s);

int main()
{
    string s;
    int k;
    cin>>s>>k;
    s = revert(s);
    int step = 0;
    for (int i = 0; i < k; i++){
        if(check(s)) break;
        string rs;
        rs.assign(s.rbegin(),s.rend());
        s = plusDigit(s, rs);
        step++;
    }
    s = revert(s);
    cout<<s<<endl<<step;
}

bool check(const string &s)
{
     string rs;
     rs.assign(s.rbegin(),s.rend());
     return (s==rs);     
}

string plusDigit(const string &s1, const string &s2)
{
        string ret;
        int l = min(s1.length(), s2.length());
        for (int i = 0; i < l; i++){
            int d1 = s1[i] - '0';
            int d2 = s2[i] - '0';
      char ch = '0'+d1+d2;
            ret = ret + ch;
        }
    for (int i = 0; i < l - 1; i++){
      if(ret[i] > '9'){
        ret[i+1] = ret[i+1] + 1;
        ret[i] = '0' + (ret[i] - '0')%10;
      }
    }
    if(ret[l-1] > '9'){
      ret[l-1] = '0' + (ret[l-1] - '0')%10;
      ret = ret + '1';
    }
    return ret;
}

string& revert(string &s)
{
  int l = s.length();
  for (int i = 0; i < l / 2; i++) {
    char tmp = s[i];
    s[i] = s[l - i - 1];
    s[l - i - 1] = tmp; 
  }
  return s;
}
