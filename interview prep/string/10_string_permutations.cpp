class Solution
{
	public:
        set<string> store;
        void solve(int index,string S){
            if(index==S.length()){
                store.insert(S);
            }

            for(int i=index; i<S.length(); i++){
                swap(S[i],S[index]);
                solve(index+1,S);
                swap(S[i],S[index]);
            }
        }

		vector<string>find_permutation(string S)
		{
            solve(0,S);
            vector<string> ans;
            for(auto i : store) ans.push_back(i);
            return ans;
		}
};