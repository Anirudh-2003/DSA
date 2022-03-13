#include<iostream>
using namespace std;

int knapsnap(int value[],int wt[],int n,int w){
    if(n==0 || w<=0){
        return 0;
    }
    if(wt[n-1]>w){
        return knapsnap(value,wt,n-1,w);
    }
    return max(knapsnap(value,wt,n-1,wt[n-1])+value[n-1],knapsnap(value,wt,n-1,w));
}
int main(){
    int value[]={100,50,150};
    int wt[]={10,20,30};
    int w=50;
    cout << knapsnap(value,wt,3,w) << endl;
    return 0;
}