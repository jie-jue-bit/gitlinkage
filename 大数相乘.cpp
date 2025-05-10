#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    
    int len1 = num1.length();
    int len2 = num2.length();
    int len = len1 + len2;
    vector<int> arr(len, 0); // 初始化为0,这里必须初始化，保证接下来的自增操作

    // 逆序遍历 num1 和 num2
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int digit = (num1[i] - '0') * (num2[j] - '0');
            int sum = arr[i + j + 1] + digit;
            arr[i + j + 1] = sum % 10;  // 存储个位
            arr[i + j] += sum / 10;     // 存储进位
        }
    }

    // 去除前导零
    string result;
    int index = 0;
    while (index < len && arr[index] == 0) {
        index++;
    }

    // 如果整个数组都是 0，返回 "0"
    if (index == len) {
        cout << "0" << endl;
        return 0;
    }

    // 转换为字符串
    for (; index < len; index++) {
        result += (arr[index] + '0');
    }

    cout << result << endl;
    return 0;
}