public class Solution {
    public int LengthOfLastWord(string s) {
        int i = s.Length - 1;

        while (i >= 0 && s[i] == ' ')
            i--;

        int length = 0;
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
}
