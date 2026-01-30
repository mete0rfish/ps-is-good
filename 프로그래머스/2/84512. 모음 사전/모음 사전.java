import java.util.*;

class Solution {
    private char[] ch = {'A', 'E', 'I', 'O', 'U'};
    private List<String> list = new ArrayList<>();

    public int solution(String word) {
        dfs("");
        return list.indexOf(word);
    }

    private void dfs(String cur) {
        list.add(cur);

        if (cur.length() == 5) {
            return;
        }

        for (int i = 0; i < 5; i++) {
            dfs(cur + ch[i]);
        }
    }
}