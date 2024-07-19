class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(node==NULL) return NULL;

        unordered_map<Node*, Node*> st;
        queue<Node*> q;

        Node* root=new Node(node->val);
        q.push(node);
        st[node]=root;

        while(!q.empty()){
            Node* temp=q.front();
            q.pop();

            for(auto i : temp->neighbors){
                if(st.find(i)==st.end()){
                    Node* k=new Node(i->val);
                    st[i]=k;
                    q.push(i);
                }
                st[temp]->neighbors.push_back(st[i]);
            }
        }

        return root;
    }
};