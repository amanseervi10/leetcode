
int pass1(vector<vector<int>> &A){

    int a[]={0,1,0,-1};
    int b[]={1,0,-1,0};

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(A[i][j]==0){
                for(int k=0; k<4; k++){
                    int newx=i+a[k];
                    int newy=j+b[k];
                    
                    if(newx>=0 && newx<3 && newy>=0 && newy<3){
                        if(A[newx][newy]>1){
                            A[newx][newy]--;
                            A[i][j]++;
                            break;
                        }
                    }
                }
            }
        }
    }
}

int pass2(vector<vector<int>> &A){

    

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(A[i][j]==0){

            }
        }
    }
}

int solution(vector<vector<int>> &A){

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<A[i][j]<<" ";
        }
    }
}