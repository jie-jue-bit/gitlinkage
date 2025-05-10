#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
class cset{
    private:
    vector<int> arr;
    public:
    cset(){
        int a;
        cin>>a;
        int k=0;
        while(a){
            int temp;
            cin>>temp;
           arr.push_back(temp);
            a--;
        }
    }
    cset(vector<int> arr){
        this->arr=arr;
    }
    cset operator+(const cset& other){
        vector<int> temp=arr;
        temp.insert(temp.end(),other.arr.begin(),other.arr.end());
        sort(temp.begin(),temp.end());
        vector<int> res;
        for(int i=0;i<temp.size();i++){
            if(i==0||temp[i]!=temp[i-1]){
                res.push_back(temp[i]);
            }
        }
        return cset(res);
    }
    void print(){
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<endl;
        }
    }
};
int main(){
    cset A;
    cset B;
    cset C=A+B;
    C.print();
    return 0;
}
