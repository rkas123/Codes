/*
ID: rkrupes1
TASK: cowland
LANG: C++
*/
#include<bits/stdc++.h>

#define int long long
#define pll pair<long long,long long>
#define vvi vector<vector<int>>

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

struct Data {
	int num;
	Data()
	{
		num = 0;
	}
	Data(int n)
	{
		num = n;
	}
};


struct Segment_Tree {
	vector<Data> segtree;
	vector<int> lazy;
	Segment_Tree(int n) {
		segtree = vector<Data>(4 * n);
	}
	Segment_Tree(vector<int> &a) {
		int n = a.size();
		segtree = vector<Data>(4 * n);
		lazy = vector<int>(4 * n, 0);
		build(a, 0, n - 1, 1);
	}


	void propagate(int root, int s, int e)
	{
		if (lazy[root] != 0)
		{
			//make updates on the current node

			if (s != e)
			{
				lazy[2 * root] += lazy[root];
				lazy[2 * root + 1] += lazy[root];
			}
			lazy[root] = 0;
		}
	}

	Data f(Data a, Data b) {
		//Just change this for a different segment tree
		return Data(a.num ^ b.num);
	}

	void build(vector<int> &a, int s, int e, int root) {
		// base case
		if (s == e) {
			segtree[root] = Data(a[s]);
			return;
		}

		int mid = (s + e) / 2;
		build(a, s, mid, 2 * root);
		build(a, mid + 1, e, 2 * root + 1);

		// self work
		segtree[root] = f(segtree[2 * root], segtree[2 * root + 1]);
	}

	void point_update(int s, int e, int root, int idx, int val) {
		// base case
		if (s == e) {
			segtree[root] = Data(val);
			return;
		}

		int mid = (s + e) / 2;
		if (mid >= idx) {
			point_update(s, mid, 2 * root, idx, val);
		}
		else {
			point_update(mid + 1, e, 2 * root + 1, idx, val);
		}

		// self work
		segtree[root] = f(segtree[2 * root], segtree[2 * root + 1]);
	}

	Data query(int s, int e, int root, int l, int r) {  //query with root index set to 1
		// completely out of range
		// propagate(root, s, e);
		if (s > r || e < l) {
			return 0;
		}
		// completely in range
		if (s >= l && e <= r) {
			return segtree[root];
		}
		// partial overlap
		int mid = (s + e) / 2;
		Data x = query(s, mid, 2 * root, l, r);
		Data y = query(mid + 1, e, 2 * root + 1, l, r);
		return f(x, y);
	}
};

int dfs(int src, int par, vvi&adjlist, vector<int>&parent, vector<int>&bigchild, vector<int>&depth)
{
	if (par == -1)
		depth[src] = 0;
	else
		depth[src] = depth[par] + 1;

	parent[src] = par;
	int big = -1, cnt = 1;

	for (auto it : adjlist[src])
	{
		if (it != par)
		{
			int sz = dfs(it, src, adjlist, parent, bigchild, depth);
			if (sz > big)
			{
				big = sz;
				bigchild[src] = it;
			}
			cnt += sz;
		}
	}
	return cnt;
}

void dfs1(int src, int par, vvi&adjlist, vector<int> &top, vector<int>&bigchild, vector<int>&v, int t)
{
	v.pb(src);
	top[src] = t;
	if (bigchild[src] != -1)
		dfs1(bigchild[src], src, adjlist, top, bigchild, v, t);

	for (auto it : adjlist[src])
	{
		if (it != par && it != bigchild[src])
		{
			dfs1(it, src, adjlist, top, bigchild, v, it);
		}
	}
}

int walk(int src, int k, vector<vector<int>>&up)  //walk function to jump k nodes up
{
	int curr = src;
	int i = 0;
	while (k > 0)
	{
		if (k & 1)
			curr = up[curr][i];
		k >>= 1; i++;
		if (curr == -1)break;
	}
	return curr;
}

int lca(int a, int b, vvi &up, vector<int> &height)
{
	int ha = height[a];
	int hb = height[b];
	int diff = abs(ha - hb);

	if (ha > hb) a = walk(a, diff, up);
	else b = walk(b, diff, up);

	if (a == b) return a;

	for (int i = 19; i >= 0; i--)   //fix this value  or update this value
	{
		int pa = walk(a, (1 << i), up);
		int pb = walk(b, (1 << i), up);
		if (pa != pb)
		{
			a = pa; b = pb;
		}
	}
	return up[a][0];
}

int32_t main()
{

	ofstream fout ("cowland.out");
	ifstream fin ("cowland.in");

	in(n); in(q);
	vector<int> val(n + 1);

	for (int i = 1; i <= n ; i++) cin >> val[i];

	vvi adjlist(n + 1);
	for (int i = 0; i < n - 1; i++) {
		in(a); in(b);
		adjlist[a].pb(b);
		adjlist[b].pb(a);
	}

	vector<int> depth(n + 1), parent(n + 1, -1), bigchild(n + 1, -1), top(n + 1);

	dfs(1, -1, adjlist, parent, bigchild, depth);
	vector<int> v;
	dfs1(1, -1, adjlist, top, bigchild, v, 1);

	vector<int> pos(n + 1);
	for (int i = 0; i < n; i++) {
		pos[v[i]] = i;
		v[i] = val[v[i]];
	}

	vvi up(n + 1, vector<int>(20, -1));

	for (int i = 1; i <= n; i++)
		up[i][0] = parent[i];

	for (int l = 1; l < 20; l++)       //after setting up[i][0] as the parent of the node
	{
		for (int i = 1; i <= n; i++)
		{
			if (up[i][l - 1] != -1)
			{
				up[i][l] = up[up[i][l - 1]][l - 1];
			}
		}
	}

	Segment_Tree segtree(v);

	while (q--)
	{
		in(t); in(u); in(v);
		if (t == 1)
		{
			segtree.point_update(0, n - 1, 1, pos[u], v);
		}
		else
		{
			int ans = 0;
			int LCA = lca(u, v, up, depth);
			while (1)
			{
				int pu = top[u];
				int pv = top[v];
				if (pu == pv)
				{
					ans ^= segtree.query(0, n - 1, 1, min(pos[u], pos[v]), max(pos[u], pos[v])).num;
					break;
				}
				if (depth[pu] > depth[pv])
				{
					ans ^= segtree.query(0, n - 1, 1, pos[pu], pos[u]).num;
					u = parent[pu];
				}
				else
				{
					ans ^= segtree.query(0, n - 1, 1, pos[pv], pos[v]).num;
					v = parent[pv];
				}
			}
			cout << ans << endl;
		}
	}

	return 0;
}
