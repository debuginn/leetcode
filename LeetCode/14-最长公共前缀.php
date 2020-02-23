<?php
/**
 * Created by PhpStorm.
 * User: mengxianhui
 * Date: 2020/1/15
 * Time: 14:45
 */

class Solution {
    /**
     * @param String[] $strs
     * @return String
     */
    function longestCommonPrefix($strs) {
        if (empty($strs)) {
            return "";
        }
        $ans = $strs[0];
        $count = count($strs);
        for ($i = 1; $i < $count; $i++) {
            $j = 0;
            for (; $j < strlen($ans) && $j < strlen($strs[$i]); $j++) {
                if (substr($ans, $j, 1) != substr($strs[$i], $j, 1)) {
                    break;
                }
            }
            $ans = substr($ans, 0, $j);
            if ($ans == "") {
                return "";
            }
        }
        return $ans;
    }
}

$arr = ["flower", "flow", "flight"];
print_r((new Solution())->longestCommonPrefix($arr));
