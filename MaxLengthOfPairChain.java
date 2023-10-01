class Solution {
    public int findLongestChain(int[][] pairs) {

        int currChain = 1;

        int n = pairs.length;

        Arrays.sort(pairs, (a, b) -> {
            
                return a[1] - b[1];
            
        });

        int currPairEnd = pairs[0][1];


            for(int i=1; i<n; i++){

                if(pairs[i][0] > currPairEnd){
                    currChain++;
                    currPairEnd = pairs[i][1];
                }
            }
        return currChain;
    }
}
