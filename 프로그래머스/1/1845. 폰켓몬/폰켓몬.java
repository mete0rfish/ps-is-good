import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        Set<Integer> s = new HashSet<>();
        
        for (int num : nums) {
            s.add(num);
        }
        
        int tmp = nums.length/2;
        return tmp > s.size() ? s.size() : tmp;
    }
}