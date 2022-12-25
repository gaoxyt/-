class Solution {
public:
    int numSquares(int n) {
        int result[n+1];
        memset(result,10000,sizeof(result));
        result[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sqrt(i);j++){
                if(result[i-j*j]+1<result[i])result[i]=result[i-j*j]+1;
            }
        }
        return result[n];
    }
};
