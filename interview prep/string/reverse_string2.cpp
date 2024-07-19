class Solution {
public:

    void reverse(string &s,int start, int end){
        while(end>start){
            swap(s[start],s[end]);
            start++; end--;
        }
    }

    string reverseStr(string s, int k) {
        int curr=0;
        while(curr<s.length()-1){
            int next=curr+(k-1);
            // next=min(s.length()-1,next);
            if(s.length-1<next) next=s.length()-1;
            reverse(s,curr,next);
            curr=curr+(2*k-1);
        }
        return s;
    }
};