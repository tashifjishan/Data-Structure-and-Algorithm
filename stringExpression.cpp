#include<iostream>
#include<sstream>
using namespace std;

int main(){
    string expression = "2 + 3 - 2";
    stringstream ss(expression);
    string token;
    while(ss>>token){
        cout<<token<<endl;
    }
    return 0;
}