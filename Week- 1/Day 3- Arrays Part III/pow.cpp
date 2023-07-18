#include<bits/stdc++.h>
using namespace std;

double power(double x, int n) {
    double ans=1.0;
    long long num= n;
    if(num<0)
        num *= -1;

    while(num) {
        if(num % 2) {
            ans *= x;
            num -= 1;
        }
        else {
            x *= x;
            num /= 2;
        }
    }
    if(n<0)
        ans= (double)(1.0) / (double)(ans);
    
    return ans;
}

int main() {
    int ans= power(6, 5);

    cout<< ans;
    return 0;
}