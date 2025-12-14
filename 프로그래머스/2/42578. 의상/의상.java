import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        Map<String, Integer> m = new HashMap<>();
        for (String[] cloth : clothes) {
            String type = cloth[1];
            m.put(type, m.getOrDefault(type, 0) + 1);
        }
        
        int answer = 1;
        for (int count : m.values()) {
            answer *= (count+1);
        }
        return answer - 1;
    }
}