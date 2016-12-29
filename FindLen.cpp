#include <iostream>
#include <math.h>

using namespace std;

float calc(int m, float u){
    float t=ct(m);
    return sqrt(t)/sqrt(u);
}

float ct(int a){
    return a*0.0098;
}

int main()
{
    int m;
    float t,u,l;
    cout<<"What is mass on hook?(g)\n";
    cin>>m;
    cout<<"What is linear mass density of wire?(g/m)\n";
    cin>>u;
    u/=1000;
    l = calc(m,u);
    cout<<"Value of l is approximately "<<l<<"cm";
    return 0;
}
