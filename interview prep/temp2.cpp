#include<bits/stdc++.h>
using namespace std;

long long get_bitonic_sum(int n){

    if(n==2) return 2;

    long long k=n/2;

    long long sum=((k)*(k+1))/2;

    sum+=(k+1);
    return sum;
}

int solve(int arr[],int n){

    int prefix[n];
    prefix[0]=arr[0];

    for(int i=1; i<n; i++){
        prefix[i]=prefix[i-1]+arr[i];
    }

    int ans=INT_MAX;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int temp=get_bitonic_sum(j-i+1);

            int a=(i==0)?0:prefix[i-1];
            int b=(j==n-1)?0:(prefix[n-1]-prefix[j]);
            
            int count=(prefix[j]-a)-temp;
            count+=(a+b);

            if(count>0){
                ans=min(ans,count);
            }          
        }
    }

    return ans;
}

int main(){
    
    return 0;
}