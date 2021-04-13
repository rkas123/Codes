/*
ID: rkrupes1
TASK: cowjog
LANG: C++
*/
#include<bits/stdc++.h>

#define int long long
#define pll pair<long long,long long>

#define in(x) long long x;cin>>x
#define pb push_back
#define F first
#define S second
#define endl "\n"

#define test() int t;cin>>t;while(t--)
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
#define deb(x) cout<<#x<<" "<<x<<endl;

const long long mod = 1e9 + 7;
const int MAX = INT_MAX;
const long long inf = 1e18 + 5;
const double pi = 3.14159265358979323846;

int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};
#define cin fin
#define cout fout
using namespace std;
int32_t main()
{
	ofstream fout ("cowjog.out");
	ifstream fin ("cowjog.in");
	in(n); in(t);
	multiset<int> s;
	for (int i = 0; i < n; i++)
	{
		in(x); in(v);
		int final = x + v * t;
		auto it = s.lower_bound(final);
		if (it == s.begin())
		{
			s.insert(final);
		}
		else
		{
			it = prev(it);
			s.erase(it);
			s.insert(final);
		}
	}
	cout << s.size() << endl;
	return 0;
}
