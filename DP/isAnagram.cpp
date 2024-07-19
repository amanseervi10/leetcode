bool isAnagram(string a, string b)
{
    int arr1[26]={0},arr2={0};
    for(int i=0; i<a.length(); i++) arr1[a[i]-'a']++;
    for(int i=0; i<b.length(); i++) arr2[b[i]-'a']++;

    for(int i=0; i<26; i++){
        if(arr1[i]!=arr2[i]) return false;
    }
    return true;
}