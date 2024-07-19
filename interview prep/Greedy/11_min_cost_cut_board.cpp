//basic logic is that after every horizontal cut you will have extra vertical piece
//and vice versa

int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N)
{
    int h=1; //associated with cutting of vertical pieces
    int v=1; //associated with cutting of horizontal pieces

    //we first sort both X and Y
    sort(X.begin(),X.end(),greater<int>());
    sort(Y.begin(),Y.end(),greater<int>());

    int i=0,j=0;    //i for X and j for Y
    int cost=0;

    while(i<M-1 && j<N-1){
        if(X[i]>Y[j] || (X[i]==Y[j] && h>=v)){
            cost+=X[i]*h;
            v++;
            i++;
        }
        else{
            cost+=Y[j]*v;
            h++;
            j++;
        }
    }
    
    while(i<M-1){
        cost+=X[i]*h;
        v++;
        i++;
    }
        
    while(j<N-1){
        cost+=Y[j]*v;
        h++;
        j++;
    }
    
    return cost;
}