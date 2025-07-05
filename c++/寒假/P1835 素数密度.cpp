#include <bits/stdc++.h>
#include <fstream>  // 用于文件处理
using namespace std;

int main() {
    unsigned int n;
    cin >> n;
    
    // 用 vector<bool> 动态分配内存
    vector<bool> wait(n + 1, false);  // 初始化大小为 n + 1 的布尔数组，默认值为 false（表示素数）

    unsigned long long sum = 0;
    
    // 打开文件以写入模式
    ofstream outFile("primes_output.txt");

    // 文件打开失败的错误处理
    if (!outFile) {
        cerr << "文件打开失败。" << endl;
        return 1;
    }
    
    // 埃拉托斯特尼筛法：找到所有小于等于n的素数
    for (unsigned int i = 2; i <= sqrt(n); i++) {
        if (!wait[i]) {  // 如果 i 是素数
            for (unsigned int j = i * i; j <= n; j += i) {
                wait[j] = true;  // 标记合数
            }
        }
    }
    
    wait[1] = true;  // 将1标记为非素数
    bool first = true;  // 用于控制是否添加逗号

    // 输出所有素数到文件
    int sss=0;
    for (unsigned int i = 2; i <= n; i++) {
        if (!wait[i]) {
            sss++;  // 如果是素数
            if (!first) {
                outFile << ",";  // 在每个素数前加逗号，除了第一个
            }
            outFile << i;  // 输出素数到文件
            first = false;  // 第一次输出后，设置逗号标志
        }
    }

    // 写入完毕后关闭文件
    outFile.close();
    cout<<sss;
    return 0;
}
