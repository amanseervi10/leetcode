// See boyer-moore algorithm for this

int majorityElement(int a[], int size)
{
    int votes=0, candidate=-1;

    for(int i=0; i<size; i++){
        if(votes==0){
            candidate=a[i];
            votes=1;
        }
        else if(a[i]!=candidate){
            votes--;
        }
        else{
            votes++;
        }
    }

    int count=0;
    for(int i=0; i<size; i++){
        if(a[i]==candidate) count++;
    }

    if(count>size/2) return candidate;
    return -1;
}