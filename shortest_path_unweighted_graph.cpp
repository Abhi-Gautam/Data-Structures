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



bool BFS(VI adj[], int source, int destination, int v, int pred[], int dist[])
{
    queue<int> q;
    bool vis[v];
    rep(i, v) dist[i] = -INT_MAX, pred[i] = -1, vis[i] = false; 

    vis[source] = true;
    dist[source] = 0;
    q.push(source);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); ++i)
        {
            if(vis[adj[u][i]] == false)
            {
                vis[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                q.push(adj[u][i]);

                if(adj[u][i] == destination) return true;
            }
        }
    }
    return false;
}

void printShortestPath(VI adj[], int source, int destination, int v)
{
    int pred[v], dist[v];
    if(BFS(adj, source, destination, v, pred, dist) == false)
    {
        cout<<"Not Connected"<<endl;
        return;
    } 
    
    VI path;

    int crawl = destination;

    path.PB(crawl);
    while(crawl != -1)
    {
        crawl = pred[crawl];
        path.PB(crawl);
    }

    // distance from source is in distance array
    cout << "Shortest path length is : "
         << dist[destination];

    // printing path from source to destination
    cout << "\nPath is::\n";
    for (int i = path.size() - 2; i >= 0; i--)
        cout << path[i] << " ";
}


int main()
{
    fast
    int v, edges;
    in2(v, edges);
    VI adj[v];
    while(edges--)
    {
        int x, y;
        in2(x, y);
        adj[x].PB(y);
        adj[y].PB(x);
    }

    int source, destination;
    in2(source, destination);

    printShortestPath(adj, source, destination, v);
    return 0;
}