class Solution {
public:
    /*bool found(string curr){
        vector<string> dict={"abc","acb","bac","bca","cab","cba"};
        for(auto it:dict){
            if(curr.find(it)){
                return true;
            }
        }
        return false;
    }*/
    int numberOfSubstrings(string s) {
        int cnt=0;
        //sliding window of size 3, then 4, then 5 , so on unttil s.size()
        /*if(s.size()<3) return 0;
        for(int i=3;i<=s.size();i++){
            string curr=s.substr(0,i);
            //cout<<curr<<" "<<i<<endl;
            int l=0;
            int r=i;
            while(r<=s.size()){
                if(curr.find("a")!=string::npos && curr.find("b")!=string::npos && curr.find("c")!=string::npos){
                    //cout<<"true"<<endl;
                    cnt++;
                }
                l++;
                r++;
                curr=s.substr(l,i);

            }
        } Givrd TLE*/
        int l=0;
        vector<int> freq(3,0);
        for(int r=0;r<s.size();r++){
            freq[s[r]-'a']++;
            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                cnt+=(s.size()-r);
                freq[s[l]-'a']--;
                l++;
            }
            
        }
        return cnt;
    }
};