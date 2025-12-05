class Solution {

    /**
     * @param String $columnTitle
     * @return Integer
     */
    function titleToNumber($columnTitle) {
        $result = 0;
        $length = strlen($columnTitle);
        for ($i = 0; $i < $length; $i++) {
            $charValue = ord($columnTitle[$i]) - ord('A') + 1;
            $result = $result * 26 + $charValue;
        }
        return $result;
    }
}