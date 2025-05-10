#include <iostream>

using namespace std;

string n2c[10] = {"��", "Ҽ", "��", "��", "��",
                 "��", "½", "��", "��", "��"};
string unit[8] = {"", "ʰ", "��", "Ǫ", "", "��", "��"};


void substransNum(string substr,bool& prezero){
    string temp;
    int len=substr.size()-1;
    for(auto c:substr){
        if(c=='0')prezero=true;
        else {
            if(prezero){
                temp+="��";
                prezero=false;
            }
            temp+=n2c[c-'0'];
            temp+=unit[len];
        }
        len--;
    }
    cout<<temp;
}
void transNum(string num){
    int len=num.length();
    string substr;
    bool prezero=false;
    for(int i=0;i<len;i++){
        substr+=num[i];
        if((len-1-i)%4==0){
            if(stoi(substr)){
                substransNum(substr,prezero);
                cout<<unit[(len-i-1)/4+4];
            }
            substr.clear();
        }
    }
    cout<<"Ԫ��";
}
int main() {
    string num;
    cin >> num;
    transNum(num);
    return 0;
}