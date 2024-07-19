//from leetcode
//question link : https://leetcode.com/problems/longest-palindromic-substring/description/?envType=study-plan-v2&envId=dynamic-programming

//below is n^2 solution

//there is also a linear time solution for this
//Manacher's algorithm : https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/

class Solution {
public:
    string longestPalindrome(string s) {
        
        //Expanding windows
        //Think of it as an expanding window at each index. The longest is stored
        //It is a O(n^2) solution

        string ans=""; ans+=s[0];
        int max_length=INT_MIN;

        for(int i=0; i<s.length(); i++){
            //This one is considering that the palindrome is of odd length
            int l=i-1,r=i+1;
            int temp=1;
            while(l>=0 && r<s.length()){
                if(s[l]==s[r]){
                    temp+=2;
                    if(temp>max_length){
                        ans=s.substr(l,temp);
                        max_length=temp;
                    }
                    l--; r++;
                }
                else break;
            }

            //This one is considering that the palindrome is of even length
            l=i; r=i+1;
            temp=0;
            while(l>=0 && r<s.length()){
                if(s[l]==s[r]){
                    temp+=2;
                    if(temp>max_length){
                        ans=s.substr(l,temp);
                        max_length=temp;
                    }
                    l--; r++;
                }
                else break;
            }
        }

        return ans;
    }
};