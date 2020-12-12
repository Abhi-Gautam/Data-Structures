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
int getMinStepToReachEnd(int arr[], int N)
{
    bool visit[N];
    int distance[N];
    vector<int> digit[10];
    memset(visit, false, sizeof(visit));
    for (int i = 1; i < N; i++)
        digit[arr[i]].push_back(i);
    distance[0] = 0;
    visit[0] = true;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int idx = q.front();
        q.pop();
        if (idx == N - 1)
            break;
        int d = arr[idx];
        for (int i = 0; i < digit[d].size(); i++)
        {
            int nextidx = digit[d][i];
            if (!visit[nextidx])
            {
                visit[nextidx] = true;
                q.push(nextidx);
                distance[nextidx] = distance[idx] + 1;
            }
        }
        digit[d].clear();
        if (idx - 1 >= 0 && !visit[idx - 1])
        {
            visit[idx - 1] = true;
            q.push(idx - 1);
            distance[idx - 1] = distance[idx] + 1;
        }
        if (idx + 1 < N && !visit[idx + 1])
        {
            visit[idx + 1] = true;
            q.push(idx + 1);
            distance[idx + 1] = distance[idx] + 1;
        }
    }
    return distance[N - 1];
}
int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 5,
                 4, 3, 6, 0, 1, 2, 3, 4, 5, 7};
    int N = sizeof(arr) / sizeof(int);
    cout << getMinStepToReachEnd(arr, N);
    return 0;
}