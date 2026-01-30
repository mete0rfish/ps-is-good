class Solution {
    
    private int res = 0;
    
    public int solution(int[] numbers, int target) {
        int answer = 0;
        
        dfs(numbers, target, 0, 0);
        
        return res;
    }
    
    private void dfs(int[] numbers, int target, int idx, int cur) {
        if (idx == numbers.length) {
            if (cur == target) {
                res++;
            }
            return;
        }
        
        dfs(numbers, target, idx+1, cur + numbers[idx]);
        dfs(numbers, target, idx+1, cur - numbers[idx]);
    }
}