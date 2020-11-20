#define cin fin
#define cout fout


//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

using namespace std;
int main()
{
    ofstream fout ("whereami.out");
    ifstream fin ("whereami.in");
    in(n);
    string s;
    cin>>s;
    map<string,bool> m;
    int i=1;
    for(;i<=n;i++)
    {
        int st=0;
        bool flag=true;
        while(st<=(n-i))
        {
            string curr=s.substr(st,i);
            if(m.count(curr)!=0)
            {
                flag=false;
                break;
            }
            else
            {
                m[curr]=true;
            }
            st++;
        }
        if(flag)
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
