542 01 Matrix
 word search ii
 n queen



## Principle
1.  **`明确用递推`**。dp一般从最底层累加至顶层，recursion一般从顶层开始（比较明显的例子就是`70 Climbing Stairs`,322的up to buttom递归）。这里的顶层是指靠近最后输出的状态。
    从顶层开始的recursion类似于dfs。    
    但是如果状态的范围很大，而且step间隔也很大，那么就适合用recursion（322）   

2.  **`状态的定义`**。这里的状态是指最终所求的东西，可以用什么方程表示？也即求y=f(x)，要确定这个`f()`  
    由于dp问题一般都是放在数组里面求，所以`f()`一般可以表示为一维或者二维数组。比如裴波那切问题，第n天的兔子数就可以表示为`fib[n]`，再如70题可以表示为`step[n]`，而64题就比较明显是个二维数组，最后的path可以表示为`path[m][n]`。但是有些题目的状态并不明显，比如121题，题中给的是一个一维数组，但是状态实际应该定义为`profit[day_index][hold]`（显式，通用），当然后续也可以用变量来简化成一维DP数组。  

    2.1 **`确定维度`**，用多少个维度是要根据具体的情况来定。     

    2.2 **`确定输出状态`**，定义了状态还要确定**最后的输出是什么状态**，比如上述就是`profit[n-1][]`的最大值。 

    2.3 **`初始化边界`**，确定了维度之后dp就是一个n维数组。一般来说不会超过三维，所以这里用xyz来示意。一维数组一般初始化f[0]、f[1]等，二维数组一般初始化f[0][] f[][0]（64，121），但也有些可能只初始化一条边（122），三维数组初始化xy平面和z轴f[][0][0]。

3.  **`最优子结构`**。这里的最优子结构相当于根据题目中的限制条件把许多分支给剪掉，不然直接求出所有分支的话那和递归就没什么区别了。
    比如f[10]=f[9]+f[8]，f[9]和f[8]就是f[10]的最优子结构，其余的f[7]f[6]等都是多余的状态。最优子结构用于确定状态转移方程。

4.  **`状态转移方程`**。包括边界值的确定和按照状态转移方程来计算。

### 1D DP

120 triangle  
70 Climbing Stairs (up2down)  
53 Maximum Subarray  
322 Coin Change  
518 Coin Change2  
300 Longest Increasing Subsequence  
650 2 Keys Keyboard (up2down)  
91 Decode Ways

### 2D DP

64 Minimum Path Sum  
121 Best Time to Buy and Sell Stock  
122 Best Time to Buy and Sell Stock ii  
123 Best Time to Buy and Sell Stock iii  
188 Best Time to Buy and Sell Stock iv  
152 Maximum Product Subarray (output不一定在dp数组的最后)  
198 House Robber  
213 House Robber II  
309	Best Time to Buy and Sell Stock with Cooldown   
300 LIS (output不一定在dp数组的最后)  
221 Maximal Square (output不一定在dp数组的最后)(压缩dp维数和Triangle很像)  

### 3D DP

123 Best Time to Buy and Sell Stock iii  
188 Best Time to Buy and Sell Stock iv  

---
44. Wildcard Matching
10. Regular Expression Matching
72. Edit Distance



647. Palindromic Substrings