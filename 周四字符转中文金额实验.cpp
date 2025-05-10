#include<iostream>
#include<string>
#include<vector>
using namespace std;
string digit[10]= {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
string convertFullGroup(const string &s){
    string res;
    string unit[4]={"仟", "佰", "拾", ""};
    bool zero=false;
    for(i=0;i<4;i++){
if(s[i]!='0')zeroflag=false;
int num=s[i]-'0';
if(num!=0){
    if(zero){
        res+="零";
        zero=false;
    }
    res+=digit[i]+unit[i];
}
else {
    zero=true;
}
    }
    return res;
}
string convertPartialGroup(const string &s){
    string res;
    int len=s.size();
    vector<string> units;
    bool zeroflag=false;
    if(len==1){
        units.push_back("");
    }
    else if(len==2){
        units.push_back("拾","");
    }
    else if(len==3){
        units.push_back("佰","拾","");
    }
    for(int i=0;i<len;i++){
        int d=s[i]-'0';
        if(s[i]!='0'){
            if(zero){
                res+="零";
                zeroflag=false;
            }
            res+=digit[d]+units[i];
        }
        else if(s[i]=='0')zeroflag=true;
    }
    return res;
}
int main(){
    unsigned long long num;
    cin>>num;
    if(num==0){
        cout<<"零元整"<<endl;
        return 0;
    }
    string s=to_string(num);
    int len=s.length();
    vector<string> groupConv;      // 存放每组转换后的结果
    vector<bool> groupOrigZero;    // 存放该组原串是否全为'0'
    vector<bool> groupEndWithZero; 
    int first=len%4==0?4:len%4;
    int pos=0;
    string grp=s.substr(pos,first);
    pos+=first;
    string conv;
    if(firstGroupLen < 4)
        conv = convertPartialGroup(grp);
    else
        conv = convertFullGroup(grp);
    groupConv.push_back(conv);
    bool allzero=true;
    for(char ch: grp){
        if(ch!='0'){
            allzero=false;
            break;
        }
    }
    groupOrigZero.push_back(allZero);
    groupEndWithZero.push_back(grp.back() == '0');
    while(pos < len){
        grp = s.substr(pos, 4);
        pos += 4;
        conv = convertFullGroup(grp);
        groupConv.push_back(conv);
        allZero = true;
        for (char ch : grp) {
            if(ch != '0') { allZero = false; break; }
        }
        groupOrigZero.push_back(allZero);
        groupEndWithZero.push_back(grp.back() == '0');
    }
    vector<string> groupunit={"","万","亿"};
    int totalGroups = groupConv.size();
    for (int i = 0; i < totalGroups; i++) {
        // 当前组对应的组单位：从右边数，0->无单位，1->"万"，2->"亿"
        int idxFromRight = totalGroups - 1 - i;
        string unit = (idxFromRight < groupUnit.size() ? groupUnit[idxFromRight] : "");
        if(groupOrigZero[i]) { // 此组全为0
            pendingZero = true;
            // 特殊情况：如果当前组对应“亿”位，即使为0也要输出“亿”
            if(idxFromRight == 2 && !result.empty()) {
                result += "亿";
            }
        } else {
            // 判断上组是否因全0或末尾0需要补“零”
            if(pendingZero && (result.size() < 3 || result.substr(result.size()-3) != "零")) {
                 if(conv.substr(0, 3) != "零")
                    result += "零";
            }
            result += groupConv[i] + unit;
            pendingZero = groupEndWithZero[i];
        }
    }
    
    result += "元整";
    cout << result << endl;
    return 0;
}