#include <iostream>
using namespace std;

void substrings(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    int code=ch;
    string ros=s.substr(1);
    substrings(ros,ans);
    substrings(ros,ans+ch);
    substrings(ros,ans + to_string(code));
}
int main(){
    substrings("AB","");
    cout<<endl;
    
    return 0;

}