<?php
/**
 * Created by PhpStorm.
 * User: mengxianhui
 * Date: 2020/1/6
 * Time: 11:50
 */
// https://leetcode-cn.com/problems/reverse-integer/
class Solution {
    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        // 判断数值是否为整数
        if (!is_int($x)) return 0;
        // 设置暂存器
        $res = 0;
        // 设置最大值及最小值范围 pow函数 次幂
        $max = pow(2, 31) - 1;
        $min = pow(-2, 31);
        // 数字反转操作
        while ($x != 0) {
            $remainder = $x % 10;
            $x = ($x - $remainder) / 10;
            $res = $res * 10 + $remainder;
        }
        // 判断结果是否越界
        if ($res > $max) return 0;
        if ($res < $min) return 0;
        return $res;
    }
}

echo (new Solution)->reverse(-123);