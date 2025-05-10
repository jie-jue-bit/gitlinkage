#include<iostream>
#include<string>
#include<vector>
using namespace std;
 vector<string> digit[10]={"Áã", "Ò¼", "·¡", "Èþ",
 "ËÁ", "Îé", "Â½", "Æâ", "°Æ", "¾Á"};
  vector<string> unit[4]={"","Ê°","°Û","Çª"};
 vector<string> uniti[3]={"","Íò","ÒÚ"};
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
				res+="Áã";
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
			res+="Áã";
			judg=false;
		}
		res+=transform(tem);
		res+=uniti[(len-1-pos)/4];
		pos+=4;
		if(tem.back()=='0')judg=true;
	}
	res+="ÔªÕû";
	cout<<res;
	return 0;
} 