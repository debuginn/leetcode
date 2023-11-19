<?php
/**
 * Created by PhpStorm.
 * User: mengxianhui
 * Date: 2020/2/27
 * Time: 19:21
 */

class Solution {
    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        $s = str_replace(['()', '[]', '{}'], '', $s, $count);
        if($count == 0){
           return strlen($s)==0;
        }else{
            return $this->isValid($s);
        }
    }
}

$str = '()[]}';
echo(new Solution())->isValid($str);