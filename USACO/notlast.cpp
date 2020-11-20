#define cin fin
#define cout fout

using namespace std;
int main()
{
    ofstream fout ("notlast.out");
    ifstream fin ("notlast.in");
    map<string,int> m;
    m["Bessie"]=0;
    m["Maggie"]=0;
    m["Elsie"]=0;
    m["Henrietta"]=0;
    m["Gertie"]=0;
    m["Daisy"]=0;
    m["Annabelle"]=0;
    in(n);
    while(n--)
    {
        string s;
        cin>>s;
        in(t);
        m[s]+=t;
    }
    int least=MAX;
    for(auto it: m)
    {
        least=min(least,it.S);
    }
    int answer=MAX;
    string ans;
    int count=0;
    for(auto it: m)
    {
        if(it.S > least && it.S == answer)
        {
            count++;
        }
        if(it.S > least && it.S < answer)
        {
            answer=it.S;
            ans=it.F;
            count=1;
        }
            }
    if(answer==MAX || count > 1)
    {
        cout<<"Tie"<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    return 0;
}
