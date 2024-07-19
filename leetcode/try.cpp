#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    arr[0]=5;
    int curr_power=2,curr_run=1;
    int index=1;
    while(index<=n-1){
        int k=pow(5,curr_power);
        curr_power++;
        arr[index]=k;
        index++;
        for(int i=0; i<curr_run; i++){
            if(index==n) break;
            arr[index]=k+arr[i];
            index++;
        }
        curr_run=index;
    }
    cout<<arr[n-1]<<endl;
    return 0;
}