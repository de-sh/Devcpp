#include <iostream>
#include <math.h>
using namespace std;
float calc(float t,float u,float l){
    return sqrt(t)/(2*l*sqrt(u));
}
float ten(float x){
    return x*0.0098;
}
float com(float x1, float x2){
    return(x1+x2)/200;
}
int main()
{
    int w;
    float n,t,u,l1,l2,l;
    cout<<"Calculate Frequency of AC from lengths on Sonometer!!\n";
    cout<<"What are the lengths?(cm)\nl.1:";cin>>l1;cout<<"l.2:";cin>>l2;
    l=com(l1,l2);
    cout<<"Mean length = "<<l<<" m\nWhat is the value of weights(g)?\n";cin>>w;
    t= ten(w);
    //cout<<"Tension = "<<t<<" Kgm/s\nWhat is the value of linear density of wire U(g/m)?\n";
    u = 0.92/1000;
    n=calc(t,u,l);
    cout<<"\nTherefore frequency of AC is "<<n<<" Hz\n";
    return 0;
}
