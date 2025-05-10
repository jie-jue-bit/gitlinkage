#include<iostream>
#include<vector>
#include<string>
using namespace std;

    vector<string> digitToLetters = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void backtrack(string& digits,int index,string& cur,vector<string>& result){
        if(index==digits.size()){
            result.push_back(cur);
            return;
        }
        int digit=digits[index]-'0';
        string letters= digitToLetters[digit];
        for(const char a:letters){
            cur.push_back(a);
            backtrack(digits,index+1,cur,result);
            cur.pop_back();
        }
    }
    vector<string> process(string digits){
        vector<string> result;
        if(digits.size()==0)return result;
        string cur;
        backtrack(digits,0,cur,result);
        return result;
    }

int main(){
    string test="234";
    vector<string> res=process(test);
    for(const string& c:res){
        cout<<c<<" "<<endl;
    }
    return 0;
}