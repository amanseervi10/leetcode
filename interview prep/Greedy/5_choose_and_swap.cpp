string chooseandswap(string a)
{
    int arr[26]={0};

    for(int i=0; i<a.length(); i++){
        arr[a[i]-'a']=1;
    }

    int pointer=0;
    char temp;
    for(int i=0; i<a.length(); i++){
        if(arr[pointer]==0){
            pointer++; i--;
        }
        else if(a[i]-'a'==pointer){
            pointer++;
        }
        else if(a[i]-'a'<pointer) continue;
        else{
            temp=a[i]; break;
        }
    }
    
    for(int i=0; i<a.length(); i++){
        if(a[i]==temp) a[i]=pointer+'a';
        
        else if(a[i]==pointer+'a') a[i]=temp;
    }

    return a;
}