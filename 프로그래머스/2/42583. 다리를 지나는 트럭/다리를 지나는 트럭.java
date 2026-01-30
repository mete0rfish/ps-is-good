import java.util.*;

class Solution {
    
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        Queue<Integer> q = new LinkedList<>();
        for (int i=0;i<bridge_length;i++) {
            q.add(0);
        }
        
        int times = 0;
        int cnt = 0;
        
        int cur_idx = 0;
        int cur_weight = 0;
        
        int n = truck_weights.length;
        
        while (cnt < n) {
            times++;
            
            // 건너기
            int removed = q.poll();
            if (removed != 0) {
                cur_weight -= removed;
                cnt++;
            }
            
            // 건널 수 있으면
            if (cur_idx < n) {
                if (truck_weights[cur_idx] + cur_weight <= weight) {
                    q.add(truck_weights[cur_idx]);
                    cur_weight += truck_weights[cur_idx];
                    cur_idx++;
                } else {
                    q.add(0);
                }
            } else {
                if (cnt < n) q.add(0);
            }
        }
        
        return times;
    }
}