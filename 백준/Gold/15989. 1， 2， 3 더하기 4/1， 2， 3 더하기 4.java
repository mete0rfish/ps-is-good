import java.util.*;
import java.lang.*;
import java.io.*;

// 1: 1
// 2: 2
// 3: 3
// 4: 1+1+1+1 2+1+1 2+2 3+1
// dp[4] = dp[3]+ dp[2] + dp[1] - (dp[])

// The main method must be in a class named "Main".
class Main {
    static long[] dp = new long[10001];
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader
            (new InputStreamReader(System.in));

        String line1 = br.readLine();
        if (line1 == null) return;
        int T = Integer.parseInt(line1.trim());

        init();

        StringBuilder sb = new StringBuilder();
        for (int t=0;t<T;t++) {
            String line = br.readLine();
            if (line == null) break;

            StringTokenizer st = new StringTokenizer(line);
            while (st.hasMoreTokens()) {
                int n = Integer.parseInt(st.nextToken());
                sb.append(dp[n]).append("\n");
            }
        }
        
        
        System.out.println(sb.toString());
    }

    private static void init() {
        dp[0] = 1;
        for (int i=1;i<=10000;i++) {
            dp[i] += dp[i-1];
        }
        for (int i=2;i<=10000;i++) {
            dp[i] += dp[i-2];
        }
        for (int i=3;i<=10000;i++) {
            dp[i] += dp[i-3];
        }
    }
}