<?php
/**
 * Created by PhpStorm.
 * User: mengxianhui
 * Date: 2020/1/14
 * Time: 15:39
 */

class Solution
{
    /**
     * @param String $s
     * @return Integer
     */
    function romanToInt($s)
    {
        $arr = [
            'I' => 1,
            'V' => 5,
            'X' => 10,
            'L' => 50,
            'C' => 100,
            'D' => 500,
            'M' => 1000
        ];
        $sum = 0;
        for ($i = 0; $i < strlen($s); $i++) {
            if (!isset($arr[$s[$i]]) || $arr[$s[$i]] >= $arr[$s[$i + 1]]) {
                $sum += $arr[$s[$i]];
            } else {
                $sum += $arr[$s[$i + 1]] - $arr[$s[$i]];
                $i = $i + 1;
            }
        }
        return $sum;
    }
}

$s = "LVIII";
echo (new Solution)->romanToInt($s);