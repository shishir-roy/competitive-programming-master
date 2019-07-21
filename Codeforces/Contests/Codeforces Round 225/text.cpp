#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MAX_VALUE = 1LL * 100;

void precalc(const vector<ll> &in, vector<ll> &out, ll cur = 1, int k = 0, ll bound = MAX_VALUE)
{
    if (k >= in.size())
    {
        out.push_back(cur);
        return;
    }
    while (bound > 0)
    {
        precalc(in, out, cur, k + 1, bound);
        cur *= in[k];
        bound /= in[k];
    }
}

vector<ll> xs, ys;

ll count_le(ll t)
{
    ll res = 0;
    int yidx = 0;
    cout << "******" << endl<< endl;
    for (ll x : xs)
    {
        while (yidx < ys.size() && ys[yidx] <= t / x)
        {
            yidx++;
        }
//        cout << x << " er jonno " << yidx << endl;
        res += yidx;
    }
    return res;
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> a[2];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i % 2].push_back(x);
    }

    ll k;
    cin >> k;

    precalc(a[0], xs);
    precalc(a[1], ys);
    sort(xs.rbegin(), xs.rend());
    sort(ys.begin(), ys.end());

    for(int x : xs)
    {
        cout << x << " ";
    }
    cout << endl;
    for(int x : ys)
    {
        cout << x << " ";
    }
    cout << endl << endl;
    ll l = 0, r = MAX_VALUE + 1;
    while (l != r)
    {
        ll m = (l + r) / 2;
        if (count_le(m) < k)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }

    if (l != MAX_VALUE + 1)
    {
        cout << l << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
