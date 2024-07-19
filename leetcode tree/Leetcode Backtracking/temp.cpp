#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,p; cin>>n>>p;
    if(p==1) cout<<n<<endl;
    else {
        int ans=0;
        int i=0;
        int a=(i*(p-1))+p;
        int temp=(n-a+1);
        while(temp>0){
            ans+=temp;
            i++;
            a=(i*(p-1))+p;
            temp=(n-a+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}