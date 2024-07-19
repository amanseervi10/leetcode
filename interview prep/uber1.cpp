//User function Template for C++

class Solution{
  public:
    int Anagrams(vector<string> &string_list)
{
   map<string,vector<string>> mp;

   for(int i=0; i<string_list.size(); i++){
        string s=string_list[i];

        sort(s.begin(),s.end());

        mp[s].push_back(string_list[i]);
    }

    return mp.size();

    return ans;
}
};