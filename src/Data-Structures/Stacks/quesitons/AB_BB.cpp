//Codeforce problem 1428C
#include<iostream>
#include<stack>
using namespace std;

int remove_AB_BB(string& str){
    stack<char> str_stack;

    for(int i=0;i<str.length();i++){
        if(str[i] == 'B' && str_stack.size()>0){
            str_stack.pop();
        }else{
            str_stack.push(str[i]);
        }
    }
    
    return str_stack.size();
}

int main(){
    int numOfTestcases,final_size;
    string str;
    
    cin>>numOfTestcases;
    cin.ignore();
    
    for(int i=0;i<numOfTestcases; i++){
        getline(cin,str);
        final_size = remove_AB_BB(str);  
        cout<<final_size<<"\n";
    }
}