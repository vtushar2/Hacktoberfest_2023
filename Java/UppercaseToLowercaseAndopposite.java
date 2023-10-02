package StringQuestion;

import java.util.ArrayList;

public class UppercaseToLowercaseAndopposite {
    public static void main(String[] args) {
        String saik = "SaikAT";
        coversion(saik);
    }

    static void coversion(String S1){
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < S1.length(); i++) {
            if(Character.isUpperCase(S1.charAt(i))){
                s.append(Character.toLowerCase(S1.charAt(i)));
            }else s.append(Character.toUpperCase(S1.charAt(i)));
        }
        System.out.println(s);
    }
}
