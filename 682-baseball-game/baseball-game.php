class Solution {

    /**
     * @param String[] $operations
     * @return Integer
     */
    function calPoints($operations) {
        $stack = [];

        foreach ($operations as $op) {
            if ($op === "C") {
                array_pop($stack);
            } elseif ($op === "D") {
                $stack[] = end($stack) * 2;
            } elseif ($op === "+") {
                $n = count($stack);
                $stack[] = $stack[$n - 1] + $stack[$n - 2];
            } else {
                // integer value
                $stack[] = intval($op);
            }
        }

        return array_sum($stack);
    }
}