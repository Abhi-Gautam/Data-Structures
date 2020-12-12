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

const int MAX_VERTICES = 101;

int arr[MAX_VERTICES];
int siz[MAX_VERTICES];

void initialize(int n)
{
    rep(i, n+1)
    {
        arr[i] = i;
        siz[i] = 1;
    }
}

int find(int i)
{
    // while we reach a node whose parent is
    // equal to itself
    while (arr[i] != i)
    {
        arr[i] = arr[arr[i]]; // Skip one level
        i = arr[i];           // Move to the new level
    }
    return i;
}

void _union(int xr, int yr)
{
    if(siz[xr] < siz[yr]) arr[xr] = arr[yr], siz[yr] += siz[xr];
    else arr[yr] = arr[xr], siz[xr] += siz[yr];
}

int isCycle(vector<int> adj[], int V)
{
    rep(i, V)
    {
        rep(j, adj[i].size())
        {
            int x = find(i);
            int y = find(adj[i][j]);
            if(x == y) return 1;
            _union(x,y);
        }
    }
    return 0;
}   

int main()
{
    fast
    int n;
    cin>>n;
    initialize(n);
    vector<int> adj[n];
    int que = n;
    while(que--)
    {
        int x, y;
        in2(x, y);
        adj[x].PB(y);
    }
    if (isCycle(adj, n))
        cout << "Gxrph contains Cycle.\n";
    else
        cout << "Gxrph does not contain Cycle.\n";
    return 0;
}