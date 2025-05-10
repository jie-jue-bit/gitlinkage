#include<iostream>
#include<string>
#include<vector>
using namespace std;
string process(string a){
    string res="#";
    for(char c:a){
        res+=c;
        res+="#";
    }
    return res;
}
string maxhw( string b){
    if(b.empty())return "";
    string a=process(b);
    int len=a.size();
    int maxlen=0;
    int c=0,r=0;
    int index=0;
    vector<int> p(len,0);
    for(int i=0;i<len;i++){
        int mirror=2*c-i;
        if(i<r)p[i]=min(r-i,p[mirror]);
while(i+p[i]+1<len&&i-p[i]-1>=0&&a[i+p[i]+1]==a[i-p[i]-1]){
    p[i]++;
}
if(p[i]+i>r){
    r=p[i]+i;
    c=i;
}
if(p[i]>maxlen){
    maxlen=p[i];
    index=i;
}
    }
    string res=b.substr((index-maxlen)/2,maxlen);
    return res;
}
int main(){
    string a;
    cin>>a;
    string res=maxhw(a);
cout<<res<<endl;
return 0;
}