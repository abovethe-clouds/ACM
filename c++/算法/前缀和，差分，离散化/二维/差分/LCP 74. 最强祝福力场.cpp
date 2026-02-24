//https://leetcode.cn/problems/xepqZ5/description/
//记得开long long ，不然会爆int
class Solution {
public:

    int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {
        vector<long long> x;
        for (auto &f: forceField)
        {
            x.push_back(f[0]*2ll-f[2]);
            x.push_back(f[0]*2ll+f[2]);
            x.push_back(f[1]*2ll-f[2]);
            x.push_back(f[1]*2ll+f[2]);
        }
        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());
        vector<vector<long long>> diff(x.size()+2, vector<long long>(x.size()+2, 0));
        for (auto &f: forceField)
        {
            long long x1=lower_bound(x.begin(), x.end(), f[0]*2ll-f[2])-x.begin()+1;
            long long x2=lower_bound(x.begin(), x.end(), f[0]*2ll+f[2])-x.begin()+1;
            long long y1=lower_bound(x.begin(), x.end(), f[1]*2ll-f[2])-x.begin()+1;
            long long y2=lower_bound(x.begin(), x.end(), f[1]*2ll+f[2])-x.begin()+1;
            diff[x1][y1]++;
            diff[x1][y2+1]--;
            diff[x2+1][y1]--;
            diff[x2+1][y2+1]++;
        }
        long long maxx=0;
        for (long long i=1; i<=x.size(); i++)
        {
            for (long long j=1; j<=x.size(); j++)
            {
                diff[i][j]+=diff[i-1][j]+diff[i][j-1]-diff[i-1][j-1];
                maxx=max(maxx, diff[i][j]);
            }
        }
        return maxx;
    }
};