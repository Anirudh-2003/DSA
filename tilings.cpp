#include<iostream>
using namespace std;

int friendspairing(int n){
    if(n==1){
        return 1;
    }
    if(n==0){
        return 0;
    }
    return friendspairing(n-1) + friendspairing(n-2);
}
int main(){

    cout << friendspairing(4) << endl;
    return 0;
}