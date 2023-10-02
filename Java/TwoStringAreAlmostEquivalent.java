package StringQuestion;

//https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/
public class TwoStringAreAlmostEquivalent {
    public static void main(String[] args) {
        String word1 = "abcdeef";
        String word2 = "abaaacc";
        System.out.println(Equivalent(word1,word2));
    }

    public static boolean Equivalent(String word1, String word2) {
        int n = word1.length();
        int[] fre = new int[26];

        for (int i = 0; i < n; i++){
            fre[word1.charAt(i) - 'a']++;
            fre[word2.charAt(i) - 'a']--;
        }

        for (int i = 0; i < fre.length; i++) {
            if(Math.abs(fre[i]) > 3) return false;
        }

        return true;
    }

//    static boolean Equivalent(String word1, String word2){
//        int length = word1.length();
//        int[] frequency = new int[26];
//
//        for (int i = 0; i < length; i++) {
//            frequency[word1.charAt(i) - 'a']++;
//            frequency[word2.charAt(i) - 'a']--;
//        }
//        for (int i = 0; i < frequency.length; i++) {
//            if(Math.abs(frequency[i]) > 3) return false;
//        }
//        return true;
//    }
}
