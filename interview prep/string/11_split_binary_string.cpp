    int maxSubStr(string s)
{
    int count=0;        //this gonna keep the count of the substrings
    
    //the idea is that imma start from the left ans a variable temp will be increase everytime
    //a 0 is encountered and decreased everytime 1 is encountered
    //so if temp becomes 0 then we know that this subsrtring is balanced
    int temp=0;

    for(int i=0; i<s.length(); i++){
        if(s[i]=='0')  temp++;
        else temp--;
        if(temp==0){
            count++;
        }
    }

    if(temp!=0) return -1;
    return count;

}