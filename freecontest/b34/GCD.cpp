//nnd
using namespace std;
#include<bits/stdc++.h>

const int MAXN = 5e6+19;
const int maxN = 1e6+19;

int spf[MAXN];
 


int a[maxN];
int n;

void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
 
    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int minimumRemovals(int a[], int n)
{
    int g = 0;
    for (int i = 0; i < n; i++)
        g = __gcd(a[i], g);
 
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
        a[i] = a[i] / g;
    for (int i = 0; i < n; i++) {
        vector<int> p = getFactorization(a[i]);
        set<int> s;
        for (int j = 0; j < p.size(); j++) {
            s.insert(p[j]);
        }
        for (auto it = s.begin(); it != s.end(); it++) {
            int el = *it;
            mpp[el] += 1;
        }
    }
 
    int mini = INT_MAX;
    int mini1 = INT_MAX;
    for (auto it = mpp.begin(); it != mpp.end(); it++) {
        int fir = it->first;
        int sec = it->second;
        if ((n - sec) <= mini) {
            mini = n - sec;
        }
    }
    if (mini != INT_MAX)
        return mini;
    else
        return -1;
}
 

int main()
{
    cin >> n;
    for (int i=0; i<n; ++i) cin >> a[i];
    sieve();
    cout << minimumRemovals(a, n);
    return 0;
}