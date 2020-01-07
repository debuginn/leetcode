<?php
/**
 * Created by PhpStorm.
 * User: mengxianhui
 * Date: 2020/1/1
 * Time: 10:14
 */
class Solution {
    /**
     * @param Integer $x
     * @return Boolean
     */
    public function isPalindrome($x) {
        // 排除特殊值
        if($x < 0) return false;
        if($x >= 0 && $x < 10) return true;
        if($x == 10) return false;
        // 定义数值长度标识符
        $div = 1;
        // 判断当前数值长度并赋值
        while( $x / $div >= 10){
            $div *= 10;
        }
        // 判断左右数字是否相等若相同判断左右第二位数字是否相同
        while($x > 1){
            $left = (int)($x / $div);
            $right = $x % 10;
            if($left != $right) return false;
            $x = ($x % $div) / 10;
            $div /= 100;
        }
        return true;
    }
}
echo (new Solution)->isPalindrome(1234321);