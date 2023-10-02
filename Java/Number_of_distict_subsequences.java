// GFG problem
// Link: https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1

//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String s = read.readLine();
            Solution ob = new Solution();
            System.out.println(ob.distinctSubsequences(s));
        }
    }
}
// } Driver Code Ends

class Solution {
    int distinctSubsequences(String s) {
        // code here
        int mod = 1000000007;
        // code here
        int n = s.length();
        int[]dp = new int[n+1];
        
        dp[0]=1;
        
        HashMap<Character,Integer> hm  = new HashMap<>();
        
        for(int i=1; i<=n; i++){
            dp[i] = (2 * dp[i-1])%mod;
            
            char ch = s.charAt(i-1);
            if(hm.containsKey(ch)){
                int j = hm.get(ch);
                dp[i] = (dp[i] - dp[j-1])%mod;
            }
            
            if(dp[i]<0){
                dp[i] += mod;
            }
            
            hm.put(ch, i);
        }
        return dp[n];
    }
}
