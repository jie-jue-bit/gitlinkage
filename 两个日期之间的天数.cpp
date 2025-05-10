#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;
vector<int> arr={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isleapyear(int year){
    return (year%4==0&&year%100!=0||year%400==0);
}
class data{
    public:
    int year,month,day;
    data(string& s){
        int pos1=s.find('-');
        int pos2=s.find('-',pos1+1);
        year=stoi(s.substr(0,pos1));
        month=stoi(s.substr(pos1+1,pos2-pos1-1));
        day=stoi(s.substr(pos2+1));
    }
    int days(){
        int res=0;
        for(int i=1;i<month;i++){
            res+=arr[i];
        }
        res+=day;
        if(month>2&&isleapyear(year))res+=1;
        return res;
    }
    int alldays(){
        if(isleapyear(year))return 366;
        else return 365;
    }
};


int intervaldays(string& s1,string& s2){
    data data1(s1);
    data data2(s2);
    int res=0;
    if(data1.year!=data2.year){
        res+=data1.alldays()-data1.days();
        for(int i=data1.year+1;i<data2.year;i++){
            res+=isleapyear(i)?366:365;
        }
        res+=data2.days();
    }
    else{
        res= data2.days()-data1.days();
    }
    return res;
}
int main(){
    cout<<"刘乾";
    string s1,s2;
    cin>>s1>>s2;
    int res=intervaldays(s1,s2);
    cout<<res<<endl;
    return 0;
}