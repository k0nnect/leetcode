public class Solution {
    public bool RepeatedSubstringPattern(string s) {
        string t = s + s;
        string cut = t.Substring(1, t.Length - 2);
        return cut.Contains(s);
    }
}