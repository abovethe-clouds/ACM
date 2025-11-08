#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// 设置控制台编码
void setConsoleEncoding() {
#ifdef _WIN32
    // Windows: 设置控制台为UTF-8
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    // Linux/Mac 通常默认使用UTF-8，不需要特殊设置
}

int main() {
    setConsoleEncoding();

    // 读取txt文件
    ifstream inputFile("words.txt", ios::binary);

    if (!inputFile.is_open()) {
        cerr << "无法打开文件！请检查文件是否存在。" << endl;
        return 1;
    }

    vector<pair<string, string>> wordPairs; // 存储英文-中文对
    string english, chinese;

    // 读取文件内容
    string content((istreambuf_iterator<char>(inputFile)),
                   istreambuf_iterator<char>());
    inputFile.close();

    // 处理BOM头（如果有）
    if (content.size() >= 3 &&
        static_cast<unsigned char>(content[0]) == 0xEF &&
        static_cast<unsigned char>(content[1]) == 0xBB &&
        static_cast<unsigned char>(content[2]) == 0xBF) {
        content = content.substr(3);
    }

    // 分割成行并配对
    vector<string> lines;
    size_t pos = 0;
    while (pos < content.size()) {
        size_t end = content.find('\n', pos);
        if (end == string::npos) end = content.size();

        string line = content.substr(pos, end - pos);
        // 去除回车符（如果有）
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }

        if (!line.empty()) {
            lines.push_back(line);
        }

        pos = end + 1;
    }

    // 将英文和中文配对
    for (size_t i = 0; i < lines.size(); i += 2) {
        if (i + 1 < lines.size()) {
            wordPairs.push_back(make_pair(lines[i], lines[i + 1]));
        } else {
            // 如果最后一行没有对应的中文，只添加英文
            wordPairs.push_back(make_pair(lines[i], ""));
        }
    }

    if (wordPairs.empty()) {
        cerr << "文件中没有找到单词！" << endl;
        return 1;
    }

    cout << "共读取到 " << wordPairs.size() << " 个单词对" << endl;
    cout << "按回车键显示下一个单词，按Ctrl+C退出" << endl;
    cout << "==================" << endl;
    random_device rd;
    shuffle(wordPairs.begin(), wordPairs.end(), mt19937(rd()));
    for (const auto& pair : wordPairs) {
        cout << "英文: " << pair.first << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "中文: " << pair.second << endl;
        cout << "==================" << endl;


    cout << "所有单词已显示完毕！" << endl;
    return 0;
}