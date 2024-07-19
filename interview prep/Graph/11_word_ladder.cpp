class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(),wordList.end());
        unordered_set<string> vis;

        queue<string> q;

        q.push(beginWord);
        vis.insert(beginWord);

        int count=1;
        int flag=0;

        while(!flag && !q.empty()){
            count++;
            int l=q.size();
            for(int b=0; b<l; b++){
                string temp=q.front();
                q.pop();

                for(int i=0; i<temp.length(); i++){
                    for(int j=0; j<26; j++){
                        string k=temp;
                        k[i]='a'+j;
                        if(st.count(k) && !vis.count(k)){
                            q.push(k);
                            vis.insert(k);
                            if(k==endWord){
                                return count;
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};