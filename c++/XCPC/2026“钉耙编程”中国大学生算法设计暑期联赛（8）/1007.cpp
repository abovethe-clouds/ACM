#include<bits/stdc++.h>
using namespace std;

#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;

// ===== FastIO (fread/fwrite) =====
class FastIO
{
private:
    static const int BUFSIZE = 1 << 20;
    char buf[BUFSIZE];
    int idx = 0, sz = 0;
    char obuf[BUFSIZE];
    int oidx = 0;

    inline char getChar()
    {
        if (idx >= sz)
        {
            sz = fread(buf, 1, BUFSIZE, stdin);
            idx = 0;
            if (sz == 0) return EOF;
        }
        return buf[idx++];
    }

    inline void flushOut()
    {
        if (oidx)
            fwrite(obuf, 1, oidx, stdout), oidx = 0;
    }

public:
    template<typename T>
    bool read(T &x)
    {
        char c = getChar();

        while (c != '-' && (c < '0' || c > '9'))
        {
            if (c == EOF) return false;
            c = getChar();
        }

        bool neg = false;

        if (c == '-')
        {
            neg = true;
            c = getChar();
        }

        x = 0;

        while (c >= '0' && c <= '9')
        {
            x = x * 10 + (c - '0');
            c = getChar();
        }

        if (neg) x = -x;

        return true;
    }

    bool readChar(char &c)
    {
        c = getChar();
        if (c == EOF) return false;
        return true;
    }

    bool readString(string &s)
    {
        char c = getChar();

        while (c == ' ' || c == '\n' || c == '\r' || c == '\t')
        {
            if (c == EOF) return false;
            c = getChar();
        }

        s.clear();

        while (c != ' ' && c != '\n' && c != '\r' && c != '\t' && c != EOF)
        {
            s.push_back(c);
            c = getChar();
        }

        return true;
    }

    inline void writeChar(char c)
    {
        if (oidx >= BUFSIZE)
            flushOut();

        obuf[oidx++] = c;
    }

    template<typename T>
    void write(T x)
    {
        if (x < 0)
        {
            writeChar('-');
            x = -x;
        }

        static char tmp[24];
        int len = 0;

        if (x == 0)
            tmp[len++] = '0';

        while (x)
        {
            tmp[len++] = char('0' + x % 10);
            x /= 10;
        }

        while (len--)
            writeChar(tmp[len]);
    }

    ~FastIO()
    {
        flushOut();
    }
} io;

vector<int> mp(500005);
vector<vector<bool>> mpp(205, vector<bool>(205, false));

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void solve()
{
    fill(mp.begin(), mp.end(), 0);
    fill(mpp.begin(), mpp.end(), vector<bool>(205, false));

    int n, m, k, q;
    io.read(n);
    io.read(m);
    io.read(k);
    io.read(q);

    auto id = [&](int x, int y)
    {
        return x * m + y;
    };

    string s;

    for (int i = 0; i < n; i++)
    {
        io.readString(s);

        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#')
                mp[id(i, j)] = -1;
            else
                mp[id(i, j)] = 1;
        }
    }

    auto bfs = [&](int x, int y, int z)
    {
        queue<pii> q;

        q.push({x, y});
        mp[id(x, y)] = z;

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                if (mp[id(nx, ny)] == 1)
                {
                    mp[id(nx, ny)] = z;
                    q.push({nx, ny});
                }
            }
        }
    };

    int cnt = 10;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[id(i, j)] == 1)
            {
                bfs(i, j, cnt);
                cnt++;
            }
        }
    }

    set<int> st;
    map<int, int> mp2;

    int cnt2 = 0;

    while (k--)
    {
        int x, y, z, w;

        io.read(x);
        io.read(y);
        io.read(z);
        io.read(w);

        x--;
        y--;
        z--;
        w--;

        int id1 = mp[id(x, y)];
        int id2 = mp[id(z, w)];
        if (!mp2.count(id1))
            mp2[id1] = cnt2++;
        if (!mp2.count(id2))
            mp2[id2] = cnt2++;
        mpp[mp2[id1]][mp2[id2]] = true;
    }
    for (int k = 0; k < cnt2; k++)
    {
        for (int i = 0; i < cnt2; i++)
        {
            if (mpp[i][k])
            {
                for (int j = 0; j < cnt2; j++)
                {
                    if (mpp[k][j])
                        mpp[i][j] = true;
                }
            }
        }
    }

    while (q--)
    {
        int x, y, z, w;

        io.read(x);
        io.read(y);
        io.read(z);
        io.read(w);

        x--;
        y--;
        z--;
        w--;

        if (mp[id(x, y)] == mp[id(z, w)])
        {
            io.write(1);
            io.writeChar('\n');
        }
        else
        {
            if (mp2.count(mp[id(x, y)]) &&
                mp2.count(mp[id(z, w)]) &&
                mpp[mp2[mp[id(x, y)]]
                   ][mp2[mp[id(z, w)]]])
            {
                io.write(1);
                io.writeChar('\n');
            }
            else
            {
                io.write(0);
                io.writeChar('\n');
            }
        }
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif

    int t = 1;
    io.read(t);

    while (t--)
        solve();

    return 0;
}

// Created by Administrator on 2026/8/13.