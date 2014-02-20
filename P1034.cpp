#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
struct SetInfo {
    string root;
    int weight;
};
map<string, SetInfo> dSet;
string getFather(const string &key)
{
    if (key == dSet[key].root) {
        return dSet[key].root;
    }
    dSet[key].root = getFather(dSet[key].root);
    return dSet[key].root;
}

void merge(const string &key1, const string &key2)
{
    string f1 = getFather(key1);
    string f2 = getFather(key2);
    dSet[f2].root = f1;
}

void updateNode(map<string, SetInfo> &s, string key, int w)
{
    if (s.find(key) == s.end()) {
        SetInfo info;
        info.root = key;
        info.weight = w;
        s[key] = info;
    }
    else {
        s[key].weight += w;
    }
}

int main()
{
    int n, k;
    cin>>n>>k;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        int weight;
        cin>>s1>>s2>>weight;
        updateNode(dSet, s1, weight);
        updateNode(dSet, s2, weight);
        merge(s1, s2);
    }
    map<string, string> head;
    map<string, int> weightMap;
    map<string, int> gangNum;
    map<string, int> gangSum;
    for (map<string, SetInfo>::iterator iter = dSet.begin(); iter != dSet.end(); iter++) {
        string node = iter->first;
        string father = getFather(node);
        int weight = iter->second.weight;
        
        weightMap[node] = weight;
        
        if (head.find(father) == head.end()) {
            head[father] = node;
            gangNum[father] = 1;
            gangSum[father] = weight;
        }
        else {
            string best = head[father];
            if (weightMap[best] < weight) {
                head[father] = node;
            }
            gangNum[father]++;
            gangSum[father]+= weight;
        }
    }
    
    map<string, int> results;
    for (map<string, string>::iterator iter = head.begin(); iter!=head.end(); iter++) {
        int count = gangNum[iter->first];
        if (count > 2 && gangSum[iter->first] / 2 > k) {
            results[iter->second] = count;
        }
    }
    
    cout<<results.size()<<endl;
    for (map<string, int>::iterator iter = results.begin(); iter!=results.end(); iter++) {
        cout<<iter->first<<" "<<iter->second<<endl;
    }
}