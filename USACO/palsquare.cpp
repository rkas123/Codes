//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
int base;
vector<int> baseChange(int n)
{
    vector<int> answer;
    while(n>0)
    {
        answer.pb(n%base);
        n/=base;
    }
    return answer;
}

int main()
{
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    vector<pii> answer;
    cin>>base;
    for(int i=1;i<=300;i++)
    {
        vector<int> number=baseChange(i);
        vector<int> square=baseChange(i*i);
        int s=0;
        int e=square.size()-1;
        bool flag=true;
        while(s<e)
        {
            if(square[s]!=square[e])
            {
                flag=false;
                break;
            }
            s++;e--;
        }
        if(flag)
        {
            for(int i=number.size()-1;i>=0;i--)
            {
                if(number[i] > 9)
                {
                    int excess=number[i]-10;
                    cout<<char('A'+excess);
                }
                else
                    cout<<number[i];
            }
            cout<<" ";
            for(int i=square.size()-1;i>=0;i--)
            {
                if(square[i] > 9)
                {
                    int excess=square[i]-10;
                    cout<<char('A'+excess);
                }
                else
                    cout<<square[i];
            }
            cout<<endl;
        }
    }

    return 0;
}
