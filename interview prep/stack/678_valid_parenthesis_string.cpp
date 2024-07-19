//question number 678 of leetcode
//good question

//really good solution
//https://leetcode.com/problems/valid-parenthesis-string/solutions/107572/java-using-2-stacks-o-n-space-and-time-complexity/


class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left,star;

        for(int i=0; i<s.length(); i++){
            if(s[i]=='(') left.push(i);
            else if(s[i]=='*') star.push(i);

            else{
                if(!left.empty()) left.pop();
                else if(left.empty() && !star.empty()) star.pop();
                else return false;
            }
        }

        while(!left.empty() && !star.empty()){
            if(left.top()>star.top()) return false;
            left.pop(); star.pop();
        }

        if(left.empty()) return true;
        return false;
    }
};