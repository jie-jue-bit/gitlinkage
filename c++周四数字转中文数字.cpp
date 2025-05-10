#include <iostream>
#include <string>
#include <vector>
using namespace std;

string digit[10] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};

// 对于4位完整组的转换，传入的字符串s长度固定为4（可能有前导0）
string convertFullGroup(const string &s) {
    string res;
    bool zeroFlag = false; // 标记连续零
    // 对应位的单位：仟, 佰, 拾, (个位空)
    string units[4] = {"仟", "佰", "拾", ""};
    for (int i = 0; i < 4; i++) {
        int d = s[i] - '0';
        if(d != 0) {
            if(zeroFlag) {
                res += "零";
                zeroFlag = false;
            }
            res += digit[d] + units[i];
        } else {
            zeroFlag = true;
        }
    }
    return res;
}

// 对于不足4位的最高组转换
string convertPartialGroup(const string &s) {
    string res;
    bool zeroFlag = false;
    int L = s.size();
    vector<string> units;
    if(L == 1) {
        units.push_back("");
    } else if(L == 2) {
        units.push_back("拾");
        units.push_back("");
    } else if(L == 3) {
        units.push_back("佰");
        units.push_back("拾");
        units.push_back("");
    }
    for (int i = 0; i < L; i++){
        int d = s[i] - '0';
        if(d != 0) {
            if(zeroFlag) {
                res += "零";
                zeroFlag = false;
            }
            res += digit[d] + units[i];
        } else {
            zeroFlag = true;
        }
    }
    return res;
}

int main(){
    unsigned long long num;
    cin >> num;
    // 特判0
    if(num == 0){
        cout << "零元整" << endl;
        return 0;
    }
    string s = to_string(num);
    int len = s.size();
    vector<string> groupConv;      // 存放每组转换后的结果
    vector<bool> groupOrigZero;    // 存放该组原串是否全为'0'
    vector<bool> groupEndWithZero; // 记录该组原串最后一位是否为'0'
    
    // 分组：从左边开始，第一组长度可能不足4
    int firstGroupLen = (len % 4 == 0 ? 4 : len % 4);
    int pos = 0;
    string grp = s.substr(pos, firstGroupLen);
    pos += firstGroupLen;
    string conv;
    // 如果最高组不足4位，调用convertPartialGroup；若恰好4位则调用convertFullGroup
    if(firstGroupLen < 4)
        conv = convertPartialGroup(grp);
    else
        conv = convertFullGroup(grp);
    groupConv.push_back(conv);
    
    bool allZero = true;
    for (char ch : grp) {
        if(ch != '0') { allZero = false; break; }
    }
    groupOrigZero.push_back(allZero);
    groupEndWithZero.push_back(grp.back() == '0');
    
    // 后续每组均为4位
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
    
    // 按组级别加上对应的组单位：组单位（从低位开始）为：""，"万"，"亿"
    vector<string> groupUnit = {"", "万", "亿"};
    int totalGroups = groupConv.size();
    string result;
    bool pendingZero = false; // 标记前面有空组或上组末尾为0，需要补“零”
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