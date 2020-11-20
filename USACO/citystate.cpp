//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
int main()
{
    ofstream fout ("citystate.out");
    ifstream fin ("citystate.in");
    map<string,map<string,int>> m;
    in(n);
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        s=s.substr(0,2);
        string state;
        cin>>state;
        m[state][s]+=1;
    }
    ll answer=0;
    for(auto it: m)
    {
        for(auto it1: it.S)
        {
            int a=it1.S;
            int b;
            if(m.count(it1.F)==0)
                b=0;
            else
            {
                b=m[it1.F][it.F];
                if(it1.F == it.F)
                    continue;
                answer+=(a*b);
            }
        }
    }
    answer/=2;
    cout<<answer<<endl;
    return 0;
}
