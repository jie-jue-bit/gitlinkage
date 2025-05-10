#include <iostream>
#include <string>
#include <vector>
using namespace std;

string digit[10] = {"��", "Ҽ", "��", "��", "��", "��", "½", "��", "��", "��"};

// ����4λ�������ת����������ַ���s���ȹ̶�Ϊ4��������ǰ��0��
string convertFullGroup(const string &s) {
    string res;
    bool zeroFlag = false; // ���������
    // ��Ӧλ�ĵ�λ��Ǫ, ��, ʰ, (��λ��)
    string units[4] = {"Ǫ", "��", "ʰ", ""};
    for (int i = 0; i < 4; i++) {
        int d = s[i] - '0';
        if(d != 0) {
            if(zeroFlag) {
                res += "��";
                zeroFlag = false;
            }
            res += digit[d] + units[i];
        } else {
            zeroFlag = true;
        }
    }
    return res;
}

// ���ڲ���4λ�������ת��
string convertPartialGroup(const string &s) {
    string res;
    bool zeroFlag = false;
    int L = s.size();
    vector<string> units;
    if(L == 1) {
        units.push_back("");
    } else if(L == 2) {
        units.push_back("ʰ");
        units.push_back("");
    } else if(L == 3) {
        units.push_back("��");
        units.push_back("ʰ");
        units.push_back("");
    }
    for (int i = 0; i < L; i++){
        int d = s[i] - '0';
        if(d != 0) {
            if(zeroFlag) {
                res += "��";
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
    // ����0
    if(num == 0){
        cout << "��Ԫ��" << endl;
        return 0;
    }
    string s = to_string(num);
    int len = s.size();
    vector<string> groupConv;      // ���ÿ��ת����Ľ��
    vector<bool> groupOrigZero;    // ��Ÿ���ԭ���Ƿ�ȫΪ'0'
    vector<bool> groupEndWithZero; // ��¼����ԭ�����һλ�Ƿ�Ϊ'0'
    
    // ���飺����߿�ʼ����һ�鳤�ȿ��ܲ���4
    int firstGroupLen = (len % 4 == 0 ? 4 : len % 4);
    int pos = 0;
    string grp = s.substr(pos, firstGroupLen);
    pos += firstGroupLen;
    string conv;
    // �������鲻��4λ������convertPartialGroup����ǡ��4λ�����convertFullGroup
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
    
    // ����ÿ���Ϊ4λ
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
    
    // ���鼶����϶�Ӧ���鵥λ���鵥λ���ӵ�λ��ʼ��Ϊ��""��"��"��"��"
    vector<string> groupUnit = {"", "��", "��"};
    int totalGroups = groupConv.size();
    string result;
    bool pendingZero = false; // ���ǰ���п��������ĩβΪ0����Ҫ�����㡱
    for (int i = 0; i < totalGroups; i++) {
        // ��ǰ���Ӧ���鵥λ�����ұ�����0->�޵�λ��1->"��"��2->"��"
        int idxFromRight = totalGroups - 1 - i;
        string unit = (idxFromRight < groupUnit.size() ? groupUnit[idxFromRight] : "");
        if(groupOrigZero[i]) { // ����ȫΪ0
            pendingZero = true;
            // ��������������ǰ���Ӧ���ڡ�λ����ʹΪ0ҲҪ������ڡ�
            if(idxFromRight == 2 && !result.empty()) {
                result += "��";
            }
        } else {
            // �ж������Ƿ���ȫ0��ĩβ0��Ҫ�����㡱
            if(pendingZero && (result.size() < 3 || result.substr(result.size()-3) != "��")) {
                 if(conv.substr(0, 3) != "��")
                    result += "��";
            }
            result += groupConv[i] + unit;
            pendingZero = groupEndWithZero[i];
        }
    }
    
    result += "Ԫ��";
    cout << result << endl;
    return 0;
}