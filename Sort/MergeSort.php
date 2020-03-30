<?php
/**
 * Created by PhpStorm.
 * User: mengxianhui
 * Date: 2020/3/30
 * Time: 12:23
 */

class MergeSort
{
    /**
     * 初始化函数
     * MergeSort constructor.
     * @param array $arr
     */
    public function __construct(array $arr)
    {
        // 设置初始数组，左侧下标，及数组总下标大小
        $this->mSort($arr, 0, count($arr) - 1);
        print_r($arr);
    }

    /**
     * 递归拆分数组
     * @param array $arr 原始数组
     * @param int $left 左侧索引下标
     * @param int $right 右侧索引下标
     */
    public function mSort(array &$arr, int $left, int $right)
    {
        if ($left < $right) {
            $center = floor(($left + $right) / 2);
            $this->mSort($arr, $left, $center);
            $this->mSort($arr, $center + 1, $right);
            $this->mergeArray($arr, $left, $right, $center);
        }
    }

    /**
     * 合并数组
     * @param array $arr
     * @param int $left
     * @param int $right
     * @param int $center
     */
    public function mergeArray(array &$arr, int $left, int $right, int $center)
    {
        echo 'sort before:' . $left . ' - ' . $center . ' - ' . $right . ' - ' . implode(',', $arr) . "\n";

        $left_i = $left;
        $right_i = $center + 1;
        $temp = [];
        while ($left_i <= $center && $right_i <= $right) {
            // 当数组A和数组B都没有越界时
            if ($arr[$left_i] < $arr[$right_i]) {
                $temp[] = $arr[$left_i++];
            } else {
                $temp[] = $arr[$right_i++];
            }
        }
        // 判断 数组A内的元素是否都用完了，没有的话将其全部插入到 temp 数组内：
        while ($left_i <= $center) {
            $temp[] = $arr[$left_i++];
        }
        // 判断 数组B内的元素是否都用完了，没有的话将其全部插入到 temp 数组内：
        while ($right_i <= $right) {
            $temp[] = $arr[$right_i++];
        }

        // 将 $arr 内排序好的部分，写入到 $arr 内：
        for ($i = 0, $len = count($temp); $i < $len; $i++) {
            $arr[$left + $i] = $temp[$i];
        }

        echo 'sort after :' . $left . ' - ' . $center . ' - ' . $right . ' - ' . implode(',', $arr) . "\n";
    }
}

$arr = [2, 1, 6, 3, 5, 4];
new MergeSort($arr);

