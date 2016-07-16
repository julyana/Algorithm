// Given s = "hello", return "olleh".

public class Solution {
    public String reverseString(String s) {
        char[] str = s.toCharArray();
        int length = s.length(), halfLength = length / 2;
        char tmp;
        for (int i = 0; i < halfLength; i ++) {
            tmp = str[i];
            str[i] = str[length - 1 - i]; // cannot use halfLength * 2
            str[length - 1 - i] = tmp;
        }
        return new String(str);
    }
}
