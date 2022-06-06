#include<iostream>
#include<vector>

using namespace std;

bool is_pangram(string& str);

int main(){
    string str;

    cout<<"Enter a  sentance: ";
    getline(cin,str);
   
    bool prangram = is_pangram(str);

    if(prangram == true){
        cout<<"YES, Given sentence is a Pangram.";
    }else{
        cout<<"NO, Given sentence is not a Pangram.";
    }
}


//================
//    DEFINATION
//================
bool is_pangram(string& str){
    vector<int> v(26,false);
    int index;

    for(int i=0;i<str.length();i++){
        if(str[i]>='A' && str[i]<='Z'){
            index = str[i]-'A';
        }
        else if(str[i]>='a' && str[i]<='z'){
            index = str[i]-'a';
        }else{
            continue;
        }

        v[index] = true;
    }

    for(int i=0;i<26;i++){
        if(v[i]== false){
            return false;
        }
    }

    return true;
}