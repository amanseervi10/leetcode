class node
{
    public : 
    char a;
    int freq;
    node *left, *right;

    node(char x, int y)
    {
        this->a = x;
        this->freq = y;
        left = right = NULL;
    }
};

struct Compare {
    bool operator()(node* l, node* r) { return l->freq > r->freq; }
};

class Solution
{
public:
    void traverse(node *root, string s, vector<string> &ans)
    {
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(s);
            return;
        }
        traverse(root->left, s + '0', ans);
        traverse(root->right, s + '1', ans);
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        priority_queue<node *, vector<node *>, Compare> pq;

        for (int i = 0; i < N; i++)
        {
            node *temp = new node(S[i], f[i]);
            pq.push(temp);
        }

        while (pq.size() > 1)
        {
            node *a = pq.top();
            pq.pop();
            node *b = pq.top();
            pq.pop();

            node *root = new node('*', a->freq + b->freq);
            root->left = a;
            root->right = b;
            pq.push(root);
        }

        vector<string> ans;
        traverse(pq.top(), "", ans);
        return ans;
    }
};