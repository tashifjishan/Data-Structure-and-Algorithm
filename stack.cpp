#include<iostream>
#include<sstream>
using namespace std;


void push(string arr[], int length, int& pos, string ch){
    if(pos==length){
        cout<<"Stack is full!"<<endl;
        return;
    }

    if(ch=="+"){
      
        int second =stoi(arr[--pos]);
        int first = stoi(arr[--pos]);
        arr[pos++]=to_string(first+second);
    }else if(ch=="/"){
        int second =stoi(arr[--pos]);
        int first = stoi(arr[--pos]);
        arr[pos++]=to_string(first/second);
    }else if(ch=="*"){
        int second =stoi(arr[--pos]);
        int first = stoi(arr[--pos]);
        arr[pos++]=to_string(first*second);
    }else if(ch=="-"){
        int second =stoi(arr[--pos]);
        int first = stoi(arr[--pos]);
        arr[pos++]=to_string(first-second);
    }else{
        arr[pos++] = ch;
    }
}



int main(){
    string expression = "10 5 + 2 * 3 /";
    string arr[100];
    int pos = 0;
    int length = 100;
    stringstream ss(expression);
    string token;
    while(ss>>token){
        cout<<"Pushing: "<<token<<endl;
        push(arr, length, pos, token);
    }

    if(pos==1){
        cout<<"Result: "<<arr[0]<<endl;
    }else{
        cout<<"Invalid Expression"<<endl;
    }
    return 0;
}