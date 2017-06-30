class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        for(int i = 0; i<n/2; i++) {
            
            for(int j = i; j<n-1-i; j++) {
            
                int v = matrix[i][j];
                
                int s_pre = i;
                int t_pre = j;
                
                int s;
                int t;
                
                for(int k = 0; k<3; k++) {
                    s = (n-1 - t_pre);
                    t = s_pre;
                    matrix[s_pre][t_pre] = matrix[s][t];
                    s_pre = s;
                    t_pre = t;
                }
                
                matrix[s_pre][t_pre] = v;
                
            }
            
        }
        
        
    }
};
