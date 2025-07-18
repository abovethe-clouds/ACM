#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        int n;
        cin >> n;
        vector<int> l(n);
        for (int i = 0; i < n; i++)
        {
            cin >> l[i];
        }

        vector<int> ll(n, 1);
        deque<pair<int, int>> li;
        li.push_back({l[0], 1});

        int maxx = l[n - 1];
        vector<int> ld(n, 1);
        for (int i = n - 2; i >= 0; i--)
        {
            ld[i] = maxx;
            if (l[i] > maxx)
            {
                maxx = l[i];
            }
        }

        maxx = 2;
        for (int i = 1; i < n - 1; i++)
        {
            while (!li.empty() && li.front().first > ld[i])
            {
                li.pop_front();
            }

            deque<pair<int, int>> lx;
            while (!li.empty() && li.back().first > l[i])
            {
                li.back().second += 1;
                maxx = max(maxx, li.back().second + 1);
                lx.push_front(li.back());
                li.pop_back();
            }

            li.push_back({l[i], 1});
            while (!lx.empty())
            {
                li.push_back(lx.front());
                lx.pop_front();
            }
        }

        cout << maxx << endl;
    }
    return 0;
}