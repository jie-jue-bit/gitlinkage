#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string s;
    int row;
    cin>>s>>row;
    int len=s.length();
    vector<vector<char>> arr(len,vector<char>(len,' '));
bool down=false;
int i=0;
int j=0,k=0;
while(i<len){
   if(j==0||j==row-1)down=!down;
   arr[j][k]=s[i];
   if(down)j++;
   else{
    j--;
    k++;
   }
   i++;
}
for(i=0;i<row;i++){
    for(j=0;j<row;j++){
        if(arr[i][j]!=' '&&j>0){
            cout<<' ';
        }
        if(j>0&&(i==0||i==row-1)&&arr[i][j]!=' '){//这个条件写进教科书！！
            for(k=0;k<row-2;k++){
                cout<<' ';
            }
        }
        cout<<arr[i][j];
    }
    cout<<endl;
}
return 0;
}