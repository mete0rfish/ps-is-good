class Solution {

    private boolean[] vst = new boolean[201];
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        for (int i=0;i<n;i++) {
            if (vst[i]) continue;
            
            answer++;
            dfs(n, computers, i);
        }
        
        return answer;
    }
    
    private void dfs(int n, int[][] computers, int cur) {
        
        vst[cur] = true;
        
        for (int next = 0; next< n;next++) {
            if (next == cur) continue;
            if (vst[next]) continue;
            if (computers[cur][next] == 0) continue;
            
            dfs(n, computers, next);
        }
    }
}