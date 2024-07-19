static bool comparator(Item &a, Item &b){
    return (float(a.value*1.0/a.weight)<float(b.value*1.0/b.weight));
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr,arr+n,comparator);

    double value=0;

    for(int i=0; i<n; i++){
        if(W==0) break;

        if(W>=arr[i].weight){
            value+=arr[i].value;
            W-=arr[i].weight;
        }
        else{
            value+=((W*1.0)/arr[i].weight)*arr[i].value*1.0;
            W=0;
        }
    }

    return value;
}