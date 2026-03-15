class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence[0]!=sentence[sentence.length()-1])return 0;
        char key=' ';
        for(int i=1;i<sentence.length();i++){
            if(sentence[i]==' ')
           {
             key=sentence[i-1];
            if(key!=sentence[i+1])return 0;
            }
        }
        if(key==' '){
            if(sentence[0]!=sentence[sentence.length()-1])return 0;
            else return 1;
        }
        return 1;
    }
};