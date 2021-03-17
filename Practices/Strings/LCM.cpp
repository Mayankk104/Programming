// codeforces problem "B. String LCM"
#include<iostream>
#include<string>
using namespace std;

int lcm(int a,int b);
int hcf(int a,int b);
string* stringLcm(string& str1,string& str2);

int main(){
    string S,T;
    string* lcm_str;

    cout<<"Enter first string: ";
    getline(cin,S);
    cout<<"Enter second string: ";
    getline(cin,T);

    lcm_str = stringLcm(S,T);
    cout<<*lcm_str;
}

int hcf(int a,int b){
    if(b==0)
        return a;
    else
        return hcf(b,a%b);
}

int lcm(int a, int b){
    return (a*b)/hcf(a,b);
}

string* stringLcm(string& str1,string& str2){
    int n = str1.size();
    int m = str2.size();
    int lng_of_lcm_str = lcm(n,m);
    string* lcm_str = new string;
    for(int i=0;i<lng_of_lcm_str/n;i++)
        *lcm_str += str1;
    
    for(int i=0; i<lng_of_lcm_str;i++){
        if( str1[i%n] != str2[i%m]){
            *lcm_str = "-1";
            break;
        }
    }
    return lcm_str;
}