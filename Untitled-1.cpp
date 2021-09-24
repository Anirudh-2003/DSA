#include <iostream>
using namespace std;

int main{

    float n=6000000;
    for(int i=1;i<35;i++){
        n+=n*0.1;
    }
    cout<<n<<endl
}