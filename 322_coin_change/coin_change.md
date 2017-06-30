
# All By Myself 

## Backtrace

最初看到此题,  联想到的是 [Combination Sum](https://leetcode.com/problems/combination-sum/), 
即用没有重复的元素累加到目标数, 每个元素可以使用多次. 

原题使用回溯法求解, 此题因为不需要记录路径, 将保存的路径转换成当前长度, 
每当有一个可行解, 与当前最优解比较进行更新. 结果正确, 但是 **TLE**.

分析 *Combination Sum* 需要记录路径, 关键是当元素重复时, 栈空间会很大 O(amount/min(money)), 
完全可以将相同的元素合并起来, 以不同的个数区分, 则栈空间只有元素的个数 O(|money|). 


* pruning

剪枝对结果的影响非常明显, 而关键是对数据进行排序, 贪婪式地选择大数值的元素,
```
for(size_t i=idx; i < coins.size(); i++) {

  int num = target / coins[i];

  // pruning
  if(cur + num >= len)
    break;

  // num from big to small
  for(int j = num; j >= 1; j--) {
    backtrace(len, cur+j, coins, i+1, target - coins[i]*j);
  }

}
```
当数据是有序的时候, `cur+num>=len`, 则可以退出循环, 因为之后的元素需要的个数一定比 `cur+num` 大,
另外 `j` 从大到小递减, 如果过程中得到一个可行解, 之后剪枝策略则会触发.


对比剪枝与否的函数递归调用次数:

data                                         |   Yes   |   No
---------------------------------------------|---------|---------
[1, 2, 5], 11                                |   4     |   60
[186, 419, 83, 408], 6249                    |   2100  |  33566
[288, 160, 10, 249, 40, 77 314, 429], 9208   |   121   |   inf

9ms

```
class Solution {

public:

  int coinChange(vector<int>& coins, int amount) {

    int rel = amount + 1;

    // sort is necessary for pruning
    sort(coins.rbegin(), coins.rend());

    backtrace(rel, 0, coins, 0, amount);
  
    return rel == amount + 1 ? -1 : rel;
  }

  void backtrace(int& len, int cur, vector<int>& coins, int idx, int target) {

    if(0 == target && cur < len) {
      len = cur;
      return;
    }

    for(size_t i=idx; i < coins.size(); i++) {

      int num = target / coins[i];

      // pruning
      if(cur + num >= len)
        break;

      // num from big to small
      for(int j = num; j >= 1; j--) {
        backtrace(len, cur+j, coins, i+1, target - coins[i]*j);
      }

    }

  }

};
```

## DP

最开始使用上述DFS策略时, Time Limit Exceeded, 开始查找递归子结构,
使用 DP 或 备忘录 算法求解.

首先思考的最优子结构: 

$$
c(n,m)=\min(c(n, m-c[n])+1, c(n-1, m))
$$

$c(n,m)$ 表示用前$n$个元素组合$m$所需要的最少个数,
初始数据 $c(n,0)=0,n\ge{}0$, $c(0,m)=inf,m>1$.

可以求解, 不超时, 但效率不高, 时间和空间复杂度均为O(mn), 220ms.


其实更简单的最优子结构:

$$
c(m)=\min_i(c(m-c[i])+1)
$$

$c(m)$ 表示组合$m$所需要的最少个数, 等于在所有组合中, 减去某一个元素的值,
剩余数值所需要的硬币个数最少的那个(再加1). 计算一个值, 要对多个分支取最小值,
在如下代码中为内循环. 算法的时间复杂度为 O(mn), 空间复杂度为 O(m), 40ms.


```
class Solution {

public:

  int coinChange(vector<int>& coins, int amount) {

    vector<int> marks(amount + 1, amount + 1);

    marks[0] = 0;

    for(int i = 1; i <= amount; i++) {
    
      for(int j = 0; j < coins.size(); j++) {
        if(i >= coins[j])
          marks[i] = min(marks[i], marks[i-coins[j]]+1);
      }

    }

    return marks[amount] == amount + 1 ? -1 : marks[amount];
  }

};

```

