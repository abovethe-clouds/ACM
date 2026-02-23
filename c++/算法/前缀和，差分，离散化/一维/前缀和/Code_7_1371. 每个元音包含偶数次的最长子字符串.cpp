//https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/
class Solution {
public:
    int move(char letter)
    {
        switch (letter) {
            case 'a': return 0;
            case 'e': return 1;
            case 'i': return 2;
            case 'o': return 3;
            case 'u': return 4;
            default: return -1;
        }
    }
    int findTheLongestSubstring(string s)
    {
        vector<int> bit(32, -2);
        bit[0]=-1;
        int ans=0;
        int pre_sum=0;
        for (int i=0;i<s.size();i++)
        {
            int move_bit=move(s[i]);
            if(move_bit!=-1)
            {
                pre_sum^=(1<<move_bit);
            }
            if(bit[pre_sum]!=-2)
            {
                ans=max(ans,i-bit[pre_sum]);
            }
            else
            {
                bit[pre_sum]=i;
            }

        }
        return ans;
    }
};