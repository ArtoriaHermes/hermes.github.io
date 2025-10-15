// Tonight Gehrman Sparrow joins the hunt
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define Monarch_of_Decay ios_base::sync_with_stdio(false);
#define Son_of_Chaos cin.tie(nullptr);
#define Mother_Goddess_of_Depravity cout.tie(nullptr);
#define Inextinguishable_Ravings freopen("template.inp", "r", stdin);
#define Lord_of_The_Mysteries freopen("template.out", "w", stdout);
#define Circle_of_Inevitability ONLINE_JUDGE
#define Primordial signed
#define God_Almighty main()

int n,q,s;
vector<pair<int,int>> ve[9*100005+100];
int cur;
int tree1[4*100005+100], tree2[4*100005+100];
long long dis[9*100005+100];
const long long oo = 1e18;

void dijkstra(int s)
{
  for (int i=1; i<cur; i++) dis[i]=oo;
  dis[s]=0;
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
  q.push({0, s});
  while (!q.empty())
  {
    pair<long long, int> f = q.top();
    q.pop();
    long long w = f.first;
    int u = f.second;
    if (w > dis[u]) continue;

    for (pair<long long, int> x : ve[u])
    {
      long long k = x.first;
      int v = x.second;
      if (dis[v] > w+k)
      {
        dis[v] = w+k;
        q.push({dis[v], v});
      }
    }
  }
}

void build(int id, int l, int r, int type)
{
  if (l==r)
  {
    if (type==1)
    {
      tree1[id] = cur;
      ve[cur].push_back({0,l});
      cur++;
      return;
    } else {
      tree2[id] = cur;
      ve[l].push_back({0,cur});
      cur++;
      return;
    }
  }
  if (type==1)
  {
    tree1[id] = cur;
  } else tree2[id] = cur;
  cur++;
  int m = (l+r)>>1;
  build(id<<1, l, m, type);
  build(id<<1|1, m+1, r, type);
  if (type==1)
  {
    ve[tree1[id]].push_back({0,tree1[id<<1]});
    ve[tree1[id]].push_back({0,tree1[id<<1|1]});
  } else {
    ve[tree2[id<<1]].push_back({0,tree2[id]});
    ve[tree2[id<<1|1]].push_back({0,tree2[id]});
  }
}

void getval(int id, int l, int r, int u, int v, int type, vector<int> &ans)
{
  if (r<u || l>v) return;
  if (u <= l && r <= v)
  {
    if (type==1) ans.push_back(tree1[id]);
    else ans.push_back(tree2[id]);
    return;
  }
  int m = (l+r)>>1;
  getval(id<<1, l, m, u, v, type, ans);
  getval(id<<1|1, m+1, r, u, v, type, ans);
}

Primordial God_Almighty
{
	Monarch_of_Decay 
  Son_of_Chaos
  Mother_Goddess_of_Depravity
  #ifndef ONLINE_JUDGE
		Inextinguishable_Ravings
    Lord_of_The_Mysteries
  #endif
	cin >> n >> q >> s;
  cur = n+1;
  build(1, 1, n, 1);
  build(1, 1, n, 2);
  int type, u, v, w, l, r;
  for (int i=1; i<=q; i++)
  {
    cin >> type;
    if (type==1) // nối đỉnh -> đỉnh
    {
      cin >> u >> v >> w;
      ve[u].push_back({w,v});
    } else if (type==2) // nối đỉnh -> đoạn
    {
      cin >> u >> l >> r >> w;
      vector<int> vertices;
      getval(1, 1, n, l, r, 1, vertices);
      for (int x : vertices) ve[u].push_back({w, x});
    } else { // nối đoạn -> đỉnh
      cin >> u >> l >> r >> w;
      vector<int> vertices;
      getval(1, 1, n, l, r, 2, vertices);
      for (int x : vertices) ve[x].push_back({w, u});
    }
  }
  dijkstra(s);
  for (int i=1; i<=n; i++)
  {
    if (dis[i] != oo) cout << dis[i] << " ";
    else cout << -1 << " ";
  }
	return 0;
}
