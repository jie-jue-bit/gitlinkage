#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    std::string names[] = {"Alice", "Bob", "Charlie", "David", "Eve"};
    int l = 3;

    // 从 names[0] 到 names[2] 创建一个 std::vector
    vector<string> vec(names, names + l);

    // 输出 vector 中的元素
    for (const auto& name : vec) {
        std::cout << name << " ";
    }

    return 0;
}