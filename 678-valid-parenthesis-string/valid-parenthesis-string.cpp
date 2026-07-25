class Solution {
public:
    bool checkValidString(string s) {
        int minopen=0;
        int maxopen=0;
        for(char &ch:s){
            if(ch=='('){
                minopen++;
                maxopen++;
            }
            else if(ch==')'){
                minopen--;
                maxopen--;
            }
            else{
                minopen--;
                maxopen++;
            }
            if(maxopen<0) return 0;
            minopen=max(minopen,0);
        }
        return minopen==0;
    }
};