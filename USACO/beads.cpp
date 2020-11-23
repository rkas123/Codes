//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
int main()
{
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    in(n);
    string s;
    cin>>s;
    int answer=0;
    for(int i=0;i<n;i++)
    {
        int r=i;
        int l=i-1;
        l+=n;
        l%=n;
        
        
        int temp=0;
        int j=r;
        do
        {
            if(s[j]=='w'){
                temp++;
            }
            else
                break;
            j++;
            j%=n;
        }while(j!=r);

        char curr=s[j];
        while((s[j]=='w' || s[j]==curr))
        {
            temp++;
            j++;
            j%=n;
            if(j==r)
                break;
        }
        j=l;
        do
        {
            if(s[j]=='w')
            {
                temp++;
            }
            else
                break;
            j--;
            j+=n;
            j%=n;
        }while(j!=l);

        curr=s[j];
        while((s[j]=='w' || s[j]==curr))
        {
            temp++;
            j--;
            j+=n;
            j%=n;
            if(j==l)
                break;
        }
        temp=min(temp,n);
        answer=max(answer,temp);
    }
    cout<<answer<<endl;
    return 0;
}
