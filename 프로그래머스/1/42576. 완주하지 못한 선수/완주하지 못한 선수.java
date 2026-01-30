import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        Map<String, Integer> m = new HashMap<>();
        
        for (String p : participant) {
            m.merge(p, 1, Integer::sum);
        }
        
        for (String p : completion) {
            m.merge(p, -1, Integer::sum);
            if (m.get(p) == 0) m.remove(p);
        }
        
        
        return m.keySet().stream().findFirst().get();
    }
}