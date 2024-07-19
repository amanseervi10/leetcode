class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans=INT_MIN;
        int curr=0;
        for(int i=0; i<answerKey.length(); i++){
            int temp=k;
            char a=answerKey[i];
            int m=i;
            curr++;
            while(temp>=0){
                i++;    
                if(i>=answerKey.length()) break;
                if(a==answerKey[i]) curr++;
                else{
                    if(temp!=0){
                        curr++;
                    }
                    temp--;
                }
            }
            ans=max(ans,curr);
            curr=0;
            while(answerKey[m]==a) m++;
            i=m-1;
        }
        ans=max(ans,curr);

        curr=0;
        for(int i=answerKey.length()-1; i>=0; i--){
            int temp=k;
            char a=answerKey[i];
            int m=i;
            curr++;
            while(temp>=0){
                i--;    
                if(i<0) break;
                if(a==answerKey[i]) curr++;
                else{
                    if(temp!=0){
                        curr++;
                    }
                    temp--;
                }
            }
            ans=max(ans,curr);
            curr=0;
            int flag=0;
            while(answerKey[m]==a){
                m--; 
                if(m<-1) flag=1; break;
            }
            if(flag==1) break;
            i=m+1;
        }
        ans=max(ans,curr);
        return ans;
    }
};