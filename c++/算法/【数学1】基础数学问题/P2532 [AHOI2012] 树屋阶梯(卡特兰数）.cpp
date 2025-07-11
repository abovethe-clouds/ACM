#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;
// compare比较函数：相等返回0，大于返回1，小于返回-1
int compare(string str1, string str2)
{
    if (str1.length() > str2.length())
        return 1;
    else if (str1.length() < str2.length())
        return -1;
    else
        return str1.compare(str2);
}
// 高精度加法
// 只能是两个正数相加
string add(string str1, string str2) // 高精度加法
{
    string str;
    int len1 = str1.length();
    int len2 = str2.length();
    // 前面补0，弄成长度相同
    if (len1 < len2)
    {
        for (int i = 1; i <= len2 - len1; i++)
            str1 = "0" + str1;
    }
    else
    {
        for (int i = 1; i <= len1 - len2; i++)
            str2 = "0" + str2;
    }
    len1 = str1.length();
    int cf = 0;
    int temp;
    for (int i = len1 - 1; i >= 0; i--)
    {
        temp = str1[i] - '0' + str2[i] - '0' + cf;
        cf = temp / 10;
        temp %= 10;
        str = char(temp + '0') + str;
    }
    if (cf != 0)
        str = char(cf + '0') + str;
    return str;
}
string sub(string str1, string str2) // 高精度减法
{
    string str;
    int tmp = str1.length() - str2.length();
    int cf = 0;
    for (int i = str2.length() - 1; i >= 0; i--)
    {
        if (str1[tmp + i] < str2[i] + cf)
        {
            str = char(str1[tmp + i] - str2[i] - cf + '0' + 10) + str;
            cf = 1;
        }
        else
        {
            str = char(str1[tmp + i] - str2[i] - cf + '0') + str;
            cf = 0;
        }
    }
    for (int i = tmp - 1; i >= 0; i--)
    {
        if (str1[i] - cf >= '0')
        {
            str = char(str1[i] - cf) + str;
            cf = 0;
        }
        else
        {
            str = char(str1[i] - cf + 10) + str;
            cf = 1;
        }
    }
    str.erase(0, str.find_first_not_of('0'));
    return str;
}
string mul(string str1, string str2)
{
    string str;
    int len1 = str1.length();
    int len2 = str2.length();
    string tempstr;
    for (int i = len2 - 1; i >= 0; i--)
    {
        tempstr = "";
        int temp = str2[i] - '0';
        int t = 0;
        int cf = 0;
        if (temp != 0)
        {
            for (int j = 1; j <= len2 - 1 - i; j++)
                tempstr += "0";
            for (int j = len1 - 1; j >= 0; j--)
            {
                t = (temp * (str1[j] - '0') + cf) % 10;
                cf = (temp * (str1[j] - '0') + cf) / 10;
                tempstr = char(t + '0') + tempstr;
            }
            if (cf != 0)
                tempstr = char(cf + '0') + tempstr;
        }
        str = add(str, tempstr);
    }
    str.erase(0, str.find_first_not_of('0'));
    return str;
}

void div(string str1, string str2, string &quotient, string &residue)
{
    quotient = residue = ""; // 清空
    if (str2 == "0")         // 判断除数是否为0
    {
        quotient = residue = "ERROR";
        return;
    }
    if (str1 == "0") // 判断被除数是否为0
    {
        quotient = residue = "0";
        return;
    }
    int res = compare(str1, str2);
    if (res < 0)
    {
        quotient = "0";
        residue = str1;
        return;
    }
    else if (res == 0)
    {
        quotient = "1";
        residue = "0";
        return;
    }
    else
    {
        int len1 = str1.length();
        int len2 = str2.length();
        string tempstr;
        tempstr.append(str1, 0, len2 - 1);
        for (int i = len2 - 1; i < len1; i++)
        {
            tempstr = tempstr + str1[i];
            tempstr.erase(0, tempstr.find_first_not_of('0'));
            if (tempstr.empty())
                tempstr = "0";
            for (char ch = '9'; ch >= '0'; ch--) // 试商
            {
                string str, tmp;
                str = str + ch;
                tmp = mul(str2, str);
                if (compare(tmp, tempstr) <= 0) // 试商成功
                {
                    quotient = quotient + ch;
                    tempstr = sub(tempstr, tmp);
                    break;
                }
            }
        }
        residue = tempstr;
    }
    quotient.erase(0, quotient.find_first_not_of('0'));
    if (quotient.empty())
        quotient = "0";
}
string mod(const string &a, const string &b)
{
    string rem = "";
    for (char c : a)
    {
        // 把下一个十进制位拉进 rem
        rem.push_back(c);
        // 去掉前导 0
        rem.erase(0, rem.find_first_not_of('0'));
        if (rem.empty())
            rem = "0";

        // 在 rem 上做“试商” 0～9，但不记录商，只更新 rem
        int low = 0, high = 9, best = 0;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            // 计算 b * mid
            string prod = mul(b, to_string(mid));
            if (prod.size() < rem.size() ||
                (prod.size() == rem.size() && prod <= rem))
            {
                best = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        // rem = rem - b * best
        if (best != 0)
        {
            string prod = mul(b, to_string(best));
            rem = sub(rem, prod);
        }
    }
    // 最终 rem 就是 a % b
    if (rem.empty())
        return "0";
    return rem;
}
int main()
{
    int n;
    cin >> n;
    string s[501];
    s[1] = "1";
    if(n==1)
    {
        cout << 1;
        return 0;
    }
    for (int i = 2; i <= n; i++)
    {
        string o;
        div(mul(s[i - 1], to_string(4 * i - 2)),to_string(i+1), s[i], o);
    }
    cout << s[n];
    return 0;
}