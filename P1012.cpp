#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct stuInfo
{
       int stuNum;
       int math;
       int clan;
       int eng;
	   int avg;
};

bool compare(stuInfo s1, stuInfo s2, int cmpType)
{
     switch(cmpType){
		case 0: return s1.math > s2.math;
        break;
        case 1: return s1.clan > s2.clan;
        break;
        case 2: return s1.eng > s2.eng;
		break;
		case 3: return s1.avg > s2.avg;
        break;
        default: return false;
     }
}

void sort(vector<stuInfo> &list, int type)
{
	int len = list.size();
	for (int i = 0; i < len - 1; i++)
		for (int j = i+1; j < len; j++ ){
			if (compare(list[j],list[i],type)){
				stuInfo tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
}

int getRank(int num, vector<stuInfo> list, int type)
{
	int len = list.size();
	int ret;
	bool flag = false;
	for (int i = 0; i < len; i++){
		if(list[i].stuNum == num){
			flag = true;
			ret = i;
			break;
		}
	}
	if (!flag) return -1;
	else {
		switch (type){
			case 0: while (ret - 1 >= 0 && list[ret - 1].math == list[ret].math) ret--;
				break;
			case 1: while (ret - 1 >= 0 && list[ret - 1].clan == list[ret].clan) ret--;
				break;
			case 2: while (ret - 1 >= 0 && list[ret - 1].eng == list[ret].eng) ret--;
				break;
			case 3: while (ret - 1 >= 0 && list[ret - 1].avg == list[ret].avg) ret--;
				break;
		}
		return ret + 1;
	}
}

void output(int rank1, int rank2, int rank3, int rank4)
{
	if (rank1 == -1){
		printf("N/A\n");
	}
	else {
		char ans = 'E';
		int ret = rank4;
		if(rank3 <= ret){
			ret = rank3;
			ans = 'M';
		}
		if(rank2 <= ret){
			ret = rank2;
			ans = 'C';
		}
		if(rank1 <= ret){
			ret = rank1;
			ans = 'A';
		}
		printf("%d %c\n",ret,ans);
	}
}

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    vector<stuInfo> stuList;
    for (int i = 0; i < n; i++){
		stuInfo info;
		scanf("%d%d%d%d",&info.stuNum, &info.clan, &info.math, &info.eng);
		info.avg = (int)((double)(info.clan + info.math + info.eng) / 3 + 0.5);
        stuList.push_back(info);
    }
	vector<stuInfo> mathList(stuList);
	vector<stuInfo> clanList(stuList);
	vector<stuInfo> engList(stuList);
	vector<stuInfo> avgList(stuList);

	sort(mathList, 0);
	sort(clanList, 1);
	sort(engList,2);
	sort(avgList,3);
    for (int i = 0; i < m; i++){
		int queryNum;
        scanf("%d",&queryNum);
		int mathRank = getRank(queryNum, mathList, 0);
		int cRank = getRank(queryNum, clanList, 1);
		int engRank = getRank(queryNum, engList, 2);
		int avgRank = getRank(queryNum, avgList, 3);
		output(avgRank, cRank, mathRank, engRank);
    }
}