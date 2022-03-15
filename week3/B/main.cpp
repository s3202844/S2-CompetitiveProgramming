#include<iostream>       
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
const int MAX = 0x3f3f3f3f;
const int MIN = 0xc0c0c0c0;
const int maxn = 1e4 + 5;
struct node
{
    int v, t, pre;
}q[maxn];
int dp[50];
int comp(node x, node y)
{
    if (x.t == y.t) return x.v > y.v;
    return x.t < y.t;
}
int main()
{
    int n, t;
    cin >> n >> t;
    int i, j, k;
    for (i = 0; i < n; i++)
        scanf("%d%d", &q[i].v, &q[i].t);
    sort(q, q+n, comp);
    memset(dp, 0, sizeof(dp));
    int MAXN = MIN;
    for (i = 0; i < n; i++)
    {
        for (j = t; j >= 1; j--)
        {
            if (j - 1 <= q[i].t)
            {
                dp[j] = max(dp[j], dp[j - 1] + q[i].v);  
            }
            if (dp[j] > MAXN)
                MAXN = dp[j];
        }
    }
    cout << MAXN << endl;
}