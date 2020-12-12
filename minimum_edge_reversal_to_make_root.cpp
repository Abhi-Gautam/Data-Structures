#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <climits>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define in1(n) cin>>n;
#define in2(n, k) cin>>n>>k;
#define in3(n, k, s) cin>>n>>k>>s;
#define scn(t) scanf("%d", &t)
#define scnld(t) scanf("%ld", &t)
#define scnlld(t) scanf("%lld", &t)
#define scnc(t) scanf("%c", &t)
#define scns(t) scanf("%s", t)
#define scnf(t) scanf("%f", &t)
#define scnlf(t) scanf("%lf", &t)
#define mem(a, b) memset(a, (b), sizeof(a))
#define nloop(i, j, k, in) for (int i = j; i < k; i += in)
#define rloop(i, j, k, in) for (int i = j; i >= k; i -= in)
#define rep(i, j) nloop(i, 0, j, 1)
#define rrep(i, j) rloop(i, j, 0, 1)
#define inar(n, a) \
    rep(i, n)\
        cin>>a[i];
#define in(n) \
    int n;\
        cin>>n;
#define inl(n) \
    long long int n;\
        cin>>n;
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)
#define MP make_pair
#define PB push_back
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)\
{\
return (a.second < b.second);\
}
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define fast  \
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
const double pi = acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

int dfs(vector<pair<int, int>> g[], pair<int, int> disRev[], bool visited[], int u)
{
    visited[u] = true;
    int totalRev = 0;

    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i].first;
        if(!visited[v])
        {
            disRev[v].first = disRev[u].first + 1;
            disRev[v].second = disRev[u].second;
            if(g[u][i].second)
            {
                disRev[v].second = disRev[u].second+1;
                totalRev++;
            }
            totalRev += dfs(g, disRev, visited, v);
        }
    }
    return totalRev;
}


void printMinEdgeReverseForRootNode(int edges[][2], int e)
{
    int V = e + 1;
    vector<pair<int, int>> g[V];
    pair<int, int> disRev[V];

    bool visited[V];

    int u, v;
    rep(i, e)
    {
        u = edges[i][0];
        v = edges[i][1];

        g[u].PB(MP(v, 0));
        g[v].PB(MP(u, 1));
    }

    rep(i, V)
    {
        visited[i] = false;
        disRev[i].first = disRev[i].second = 0;
    }

    int root = 0;
    int totalRev = dfs(g, disRev, visited, root);

    int res = INT_MAX;

    rep(i, V)
    {
        cout<<i<<" "<<disRev[i].first<<" "<<disRev[i].second<<'\n';
    }
    rep(i, V)
    {
        int edgestoRev = totalRev - disRev[i].second + disRev[i].first - disRev[i].second;
        if(edgestoRev < res)
        {
            res = edgestoRev;
            root = i;
        }
    }
    cout<<root<<" "<<res<<endl;
}

int main()
{
    fast
    int edges[][2] = 
    { 
        {0, 1}, 
        {2, 1}, 
        {3, 2}, 
        {3, 4}, 
        {5, 4}, 
        {5, 6}, 
        {7, 6} 
    }; 
    int e = sizeof(edges) / sizeof(edges[0]); 
  
    printMinEdgeReverseForRootNode(edges, e); 
    return 0;
}