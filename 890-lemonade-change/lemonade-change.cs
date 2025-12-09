public class Solution {
    public bool LemonadeChange(int[] bills) {
        int five = 0, ten = 0;

        foreach (var b in bills) {
            if (b == 5) {
                five++;
            } else if (b == 10) {
                if (five == 0) return false;
                five--; ten++;
            } else {
                if (ten > 0 && five > 0) {
                    ten--; five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
}