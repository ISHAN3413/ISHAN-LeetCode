class Solution {
public:
    int countPoints(string rings) {
        int a[10][3]={0};
        int k=0;
       for(int i=0;i<rings.length();i+=2){
        if(rings[i]=='B'){
            a[rings[i+1]-'0'][0]++;
        }
        else if(rings[i]=='G'){
            a[rings[i+1]-'0'][1]++;
        }
        else{
            a[rings[i+1]-'0'][2]++;
        }
       }
       for(int i=0;i<=9;i++){
        if(a[i][0] != 0 && a[i][1]!= 0 && a[i][2]!=0)k++;
       }
       return k;
        
    }
};