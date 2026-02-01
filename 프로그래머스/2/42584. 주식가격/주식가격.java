import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int n = prices.length;
        int[] answer = new int[n];
        
        Stack<Integer> stk = new Stack<>();
        
        for (int i=0;i<n;i++) {
            while (!stk.isEmpty() && prices[stk.peek()] > prices[i]) {
                int popped = stk.pop();
                answer[popped] = i - popped;
            }
            stk.push(i);
        }
        
        while (!stk.isEmpty()) {
            int popped = stk.pop();
            answer[popped] = n - 1 - popped;
        }
        
        return answer;
    }
}