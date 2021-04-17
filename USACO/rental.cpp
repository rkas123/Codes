/*
ID: rkrupes1
TASK:rental
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
bool cmp(int a, int b)
{
	return a > b;
}
bool cmp1(pll a, pll b)
{
	return a.F > b.F;
}
int32_t main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ofstream fout ("rental.out");
	ifstream fin ("rental.in");
	in(n); in(m); in(r);
	int totalmilk = 0;
	int cows[n], renters[r];
	pll retailers[m];
	for (int i = 0; i < n; i++) {
		cin >> cows[i];
		totalmilk += cows[i];
	}
	for (int j = 0; j < m; j++)
	{
		in(a); in(b);
		retailers[j] = {b, a}; //rate,quantity
	}
	for (int i = 0; i < r; i++)
	{
		cin >> renters[i];
	}
	sort(cows, cows + n);
	sort(renters, renters + r, cmp);
	sort(retailers, retailers + m, cmp1);

	for (int i = 1; i < n; i++)
		cows[i] += cows[i - 1];
	for (int i = 1; i < r; i++)
		renters[i] += renters[i - 1];
	vector<int> cumcost(m), cumvol(m);
	for (int i = 0; i < m; i++)
	{
		cumcost[i] = retailers[i].F * retailers[i].S;
		cumvol[i] = retailers[i].S;
	}
	for (int i = 1; i < m; i++)
	{
		cumcost[i] += cumcost[i - 1];
		cumvol[i] += cumvol[i - 1];
	}

	int answer = 0;
	int left = totalmilk;
	int index = upper_bound(cumvol.begin(), cumvol.end(), left) - cumvol.begin();
	if (index == 0)
	{
		answer += (left * retailers[index].F);
	}
	else
	{
		index -- ;
		answer += cumcost[index];
		left -= cumvol[index];
		index++;
		if (index < m)
		{
			answer += (left * retailers[index].F);
		}
	}
	for (int i = 0; i < r && i < n; i++)
	{
		int temp = renters[i];
		int left = totalmilk - cows[i];
		int index = upper_bound(cumvol.begin(), cumvol.end(), left) - cumvol.begin();
		if (index == 0)
		{
			temp += (left * retailers[index].F);
		}
		else
		{
			index -- ;
			temp += cumcost[index];
			left -= cumvol[index];
			index++;
			if (index < m)
			{
				temp += (left * retailers[index].F);
			}
		}
		answer = max(answer, temp);
	}
	cout << answer << endl;;
	return 0;
}
