#include <iostream>
using namespace std;

class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // 输出运算符重载
    friend ostream& operator<<(ostream& os, const MyClass& obj);
    
    // 输入运算符重载
    friend istream& operator>>(istream& is, MyClass& obj);
};

// 输出运算符重载定义
ostream& operator<<(ostream& os, const MyClass& obj) {
    os << "Value: " << obj.value;
    return os;
}

// 输入运算符重载定义
istream& operator>>(istream& is, MyClass& obj) {
    is >> obj.value;
    return is;
}
int main(){
    MyClass obj;
    cin>>obj;
    cout<<obj;
}