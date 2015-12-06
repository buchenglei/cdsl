# HELP #

### 说明 ###
每一个排序例程都保存在一个单独的.c文件中，并从main.c中统一调用，<br>
判断排序结果是否正确，并输出每一个排序函数的执行时间。

### 编译 ###

```shell
gcc *.c -D TEST_DATA_LEN=10000

```
-D TEST_DATA_LEN 指定测试数据的个数，并用随机函数生成指定长度的用于存储随机数的数组<br>
如果不指定，则使用默认值100