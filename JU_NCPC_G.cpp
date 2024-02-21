#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define f first
#define s second
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};
#define inf 9223372036854775807
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int n;
        cin >> n;
        vector<ll> a(n + 3), b(n + 3);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int low = 0;
        int high = n;
        int mid;
        int ans = n;
        while (high >= low)
        {
            mid = (high + low) / 2;
            bool flag = false;
            for (int i = 0; i + mid - 1 < n; i++)
            {
                int k = 0, c = 0, j;
                for (j = 0; j < i && k < n;)
                {
                    if (a[k] == b[j])
                    {
                        j++;
                    }
                    k++;
                }
                if (j != i)
                {
                    flag = false;
                    continue;
                }
                for (j = i + mid; j < n && k < n;)
                {
                    if (a[k] == b[j])
                    {
                        j++;
                    }
                    k++;
                }
                if (j == n)
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                }
                if (flag)
                {
                    ans = min(ans, mid);
                    high = mid - 1;
                    break;
                }
            }
            if (!flag)
            {
                low = mid + 1;
            }
        }
        cout << "Case " << tt << ":"
             << " " << ans << endl;
    }
    return 0;
}