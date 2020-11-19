/*
ID: rkrupes1
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>
#define cin fin
#define cout fout
using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int n;
    cin>>n;
    vector<string> v;
    map<string,int> m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
        m[s]=0;
    }
    for(int i=0;i<n;i++)
    {
        string curr;
        cin>>curr;
        int cost,people;
        cin>>cost>>people;
        if(people == 0)
            continue;
        m[curr]-=cost;
        int share=cost/people;
        m[curr]+=(cost%people);
        for(int j=0;j<people;j++){
            string temp;
            cin>>temp;
            m[temp]+=share;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" "<<m[v[i]]<<endl;
    }

    return 0;
}

