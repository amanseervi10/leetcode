class Solution {
public:
    string countAndSay(int n) {
        string ans="1";

        for(int i=0; i<n-1; i++){
            string temp="";
            char curr=ans[0];
            int count=1;
            for(int j=1; j<ans.length(); j++){
                if(ans[j]==curr) count++;
                else{
                    temp+=char(count+'0');
                    temp+=curr;
                    curr=ans[j]; 
                    count=1;
                }
            }
            temp+=char(count+'0');
            temp+=curr;
            ans=temp;
        }

        return ans;
    }
};