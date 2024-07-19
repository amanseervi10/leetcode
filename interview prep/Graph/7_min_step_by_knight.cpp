//We should use BFS for this one
//How do we know?

//Well we are asked to find minimum steps and for minimum BFS is always suited
//and is more efficient

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    queue<pair<int,int>> q;
    q.push({KnightPos[0],KnightPos[1]});
    int count=0;

    int a[]={2,2,-2,-2,1,1,-1,-1};
    int b[]={1,-1,1,-1,2,-2,2,-2};

    while(!flag){
        
        int k=q.size();
        for(int i=0; i<k; i++){
            auto temp=q.front();
            q.pop();

            if(temp.first=TargetPos[0] && temp.second==targetPos[1]){
                flag=1; break;
            }
            for(int j=0; j<8; j++){
                int x=temp.first+a[j],y=temp.second+b[j];
                if(x>=1 && x<=N && y>=1 && y<=N){
                    q.push({x,y});
                }
            }
        }
        count++;
    }
    return count;
}