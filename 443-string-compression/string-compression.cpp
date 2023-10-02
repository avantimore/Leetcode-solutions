class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        for(int j=1,count=1;j<=n;j++,count++){
            if(j==n || chars[j]!=chars[j-1]){
                chars[i++] = chars[j-1];
                if(count>=2){
                    for(char dig:to_string(count)){
                        chars[i++] = dig;
                    }
                }
                count=0;
            }
        }
        return i;
    }
};