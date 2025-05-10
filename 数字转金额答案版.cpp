#include<iostream>
#include<string>
#include<vector>
using namespace std;
 vector<string> digit[10]={"��", "Ҽ", "��", "��",
 "��", "��", "½", "��", "��", "��"};
  vector<string> unit[4]={"","ʰ","��","Ǫ"};
 vector<string> uniti[3]={"","��","��"};
string transform(string a){
	bool judg=false;
	string res;
	int len=a.size(),i=0;
	int pos=0;
	while(pos<len){
		if(a[pos]=='0'){
			judg=true;
		}
		else{
			if(judg){
				res+="��";
				judg=false;
			}
			res+=digit[a[pos]-'0'];
			res+=unit[len-1-pos];
		}
		pos++;
	}
	return res;
}
int main(){
	long long num;
	cin>>num;
	string hh=string(num);
	int len=num.size(),pos=0;
	string res;
	int fir=len%4==0?4:len%4;
	string a=hh.substr(0,fir);
	string temp=transform(a);
	bool judg=false;
	if(a.back()=='0')judg=true;
	res+=temp+uniti[(len-1-pos)/4];
	pos+=fir;
	while(pos<len){
		string tem=hh.substr(pos,4);
		if(tem[0]!='0'&&judg){
			res+="��";
			judg=false;
		}
		res+=transform(tem);
		res+=uniti[(len-1-pos)/4];
		pos+=4;
		if(tem.back()=='0')judg=true;
	}
	res+="Ԫ��";
	cout<<res;
	return 0;
} 