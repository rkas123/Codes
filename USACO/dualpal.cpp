//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
bool changeBase(int base,int number)
{
    vector<int> answer;
    while(number>0)
    {
        answer.pb(number%base);
        number/=base;
    }
    int s=0,e=answer.size()-1;
    bool flag=true;
    while(s<e)
    {
        if(answer[s]!=answer[e])
        {
            flag=false;
            break;
        }
        s++;e--;
    }
    return flag;
}
int main()
{
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    in(n);in(s);
    int count=0;
    s++;
    while(count<n)
    {
        int c=0;
        for(int i=2;i<=10;i++)
        {
            if(changeBase(i,s))
            {
                c++;
            }
            if(c>=2)
                break;
        }
        if(c>=2)
        {
            cout<<s<<endl;
            count++;
        }
        s++;
    }
    return 0;
}
