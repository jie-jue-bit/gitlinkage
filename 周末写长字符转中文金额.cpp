#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;
vector<string> unit={"","拾","百","仟"};
string digit[10] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
string uniti[3]={"","万","亿"};
string transform(string a){
    int pos=a.length();
string res;
bool judge=false;
int i=0;
for(char ch:a){
    if(ch=='0')judge=true;
    else{
        if(judge){
            res+="零";
            judge=false;
        }
        res+=digit[ch-'0']+unit[pos-1-i];
    }
    i++;
}
return res;
}
string transformfool(string a){
    string res;
    bool judge=false;
    int i=0;
    for(char ch:a){
        if(ch=='0')judge=true;
       else {
        if(judge){
            res+="零";
            judge=false;
        }
        res+=digit[ch-'0']+unit[3-i];
       }
       i++;
    }
    return res;
}
int main(){
    string res;
    bool judge=false;
    long long num;
    cin>>num;
    string str=to_string(num);
int fir=str.length()%4==0?4:str.length()%4;
int len=str.length();
string a=str.substr(0,fir);
string temp=transform(a);
int pos=str.length()/4;
int i=0;
res+=temp+uniti[pos-i];
if(a.back()=='0')judge=true;
int posi=fir;
while(posi<len){
    i++;
    string tem=str.substr(posi,4);
    string r=transformfool(tem);
    posi+=4;
if(tem[0]!='0'&&judge){
    res+="零";
    judge=false;
}
res+=r+uniti[pos-i];
if(tem.back()=='0')judge=true;
}
cout<<res<<endl;
return 0;
}