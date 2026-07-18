#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int long long
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;

struct time
{
    int year, month, day;
    int hour, minute, second;
    int month_day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    time(int y, int m, int d, int h, int min, int s)
    {
        year = y;
        month = m;
        day = d;
        hour = h;
        minute = min;
        second = s;
        if (isLeapYear(year))
            month_day[2] = 29;
    }

    static bool isLeapYear(int year)
    {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            return true;
        return false;
    }

    time operator+(int seconds)
    {
        time result = *this;
        result.second += seconds;
        while (result.second >= 60)
        {
            result.minute += result.second / 60;
            result.second %= 60;
        }
        while (result.minute >= 60)
        {
            result.hour += result.minute / 60;
            result.minute %= 60;
        }
        while (result.hour >= 24)
        {
            result.day += result.hour / 24;
            result.hour %= 24;
        }
        while (result.day > month_day[result.month])
        {
            result.day -= month_day[result.month];
            result.month++;
            if (result.month > 12)
            {
                result.month = 1;
                result.year++;
                if (isLeapYear(result.year))
                    month_day[2] = 29;
                else
                    month_day[2] = 28;
            }
        }
        return result;
    }

    bool operator!=(const time& b) const
    {
        if (year != b.year || month != b.month || day != b.day || hour != b.hour || minute != b.minute || second != b.
            second)
            return true;
        return false;
    }

    int operator-(time t)
    {
        int ans = 0;
        time a = *this;
        while (a != t)
        {
            ans += 1;
            a = a + 60;
        }
        return ans;
    }

    time operator-(int seconds)
    {
        time ans = *this;
        ans.second -= seconds;
        while (ans.second < 0)
        {
            ans.second += 60;
            ans.minute--;
        }
        while (ans.minute < 0)
        {
            ans.minute += 60;
            ans.hour--;
        }
        while (ans.hour < 0)
        {
            ans.hour += 24;
            ans.day--;
        }
        while (ans.day <= 0)
        {
            ans.month--;
            if (ans.month <= 0)
            {
                ans.month = 12;
                ans.year--;
                if (isLeapYear(ans.year))
                    month_day[2] = 29;
                else
                    month_day[2] = 28;
            }
            ans.day += month_day[ans.month];
        }
        return ans;
    }
};

void solve()
{
    struct time t1(1970, 1, 1, 0, 0, 0);
    int y,m,d,h,mm,s,x;
    scanf("%lld-%lld-%lld %lld:%lld:%lld %lld", &y, &m, &d, &h, &mm, &s,&x);
    struct time t2(y, m, d, h, mm, 0);
    int between = t1 - t2;
    t2=t2-between%x*60;
    printf("%04lld-%02lld-%02lld %02lld:%02lld:%02lld\n", t2.year, t2.month, t2.day, t2.hour, t2.minute, t2.second);


}

signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

//
// Created by Administrator on 2026/4/30.
//
