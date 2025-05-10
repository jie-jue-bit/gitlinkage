
#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
class Quaternary{
    private:
    string value;
    public:
    Quaternary (string temp){
        value=temp;
    }
    Quaternary operator+(const Quaternary& other){
        string a=value;
        string b=other.value;
        while(a.size()<b.size()){
            a="0"+a;
        }
        while(a.size()>b.size()){
            b="0"+b;
        }
        int carry=0;
        string res="";
        for(int i=a.size()-1;i>=0;i--){
            int digita=a[i]-'0';
            int digitb=b[i]-'0';
            int sum=digita+digitb+carry;
            res+=(sum%4+'0');
            carry=sum/4;
        }
        if(carry){
            res+=carry+'0';
        }
        reverse(res.begin(),res.end());
        return Quaternary(res);
    }
    void display(){
        cout<<value<<endl;
    }
};
int main() {
    int t;
    string num = "0";
    Quaternary sum(num);
    cin >> t;
    while (t--) {
        cin >> num;
        Quaternary number(num);
        sum = sum + number;
    }
    sum.display();
    return 0;
}