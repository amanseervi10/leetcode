class Solution {
public:

    void solve(vector<vector<int>>& matrix,int start,int size){
        int x=start,y=start;
        
        int a=0,b=size-1;
        int c=size-1,d=0;
        int e=0,f=-1*(size-1);
        int g=-1*(size-1),h=0;

        for(int i=0; i<size-1; i++){
            x=start; y=start;
            int temp=matrix[x][y+i];

            x+=a;y+=b;
            swap(temp,matrix[x][y]);
            a++; b--;

            x+=c; y+=d;
            swap(temp,matrix[x][y]);
            c--; d--;
            break;

            x+=e; y+=f;
            swap(temp,matrix[x][y]);
            e--; f++;

            x+=g; y+=h;
            swap(temp,matrix[x][y]);
            g++; h++;
            break;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int start=0;

        while(n>0){
            solve(matrix,start,n);
            n-=2; start++;
        }
    }
};


//This has a beautiful way of doing. Look into some of the solutions posted by people on leetcode.