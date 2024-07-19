class Solution {
public:

    bool rotateString(string s, string goal) {
        string temp=s+s;
        for(int i=0; i<s.length(); i++){
            int flag=0;
            for(int j=0; j<s.length(); j++){
                if(temp[i+j]!=goal[j]){
                    flag=1; break;
                }
            }
            if(!flag) return true;
        }
        return false;
    }
};