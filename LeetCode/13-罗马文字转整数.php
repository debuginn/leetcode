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
            // 判断该数组中是否存在字符串中的字符并且字符串当前位在数组中的值大于后一位
            if (!isset($arr[$s[$i]]) || $arr[$s[$i]] >= $arr[$s[$i + 1]]) {
                $sum += $arr[$s[$i]];
            } else {
                // 不符合代表着满足小于罗马文字大的值减去小的值表达的方式
                $sum += $arr[$s[$i + 1]] - $arr[$s[$i]];
                // 跳过两个值进行下一字节对应值运算
                $i = $i + 1;
            }
        }
        return $sum;
    }
}

$s = "LVIII";
echo (new Solution)->romanToInt($s);