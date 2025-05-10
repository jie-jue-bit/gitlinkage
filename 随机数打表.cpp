
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
    srand(static_cast<unsigned int> (time(0)));
    int randnumber=rand()%10;
    cout<<randnumber<<endl;
    return 0;
}
