class Solution {
public:

    double myPow(double x, int n) {
        if(n==1) return x;
        if(n==2) return x*x;
        else if(n%2==0) return myPow(myPow(x,n/2),2);
        else return myPow(myPow(x,(n-1)/2),2)*x;
    }
};