
- [ ] 数独解法如何优化？
- [x] word search II如何用trie优化

- [x]  一个字符串变到另一个字符串，到底是用bfs还是dfs？ word search 还有genetic mutation
- [x] 貌似genetic mutation适合用bfs
- [x] 433 怎么解？和BFS有什么关系？（求变换的最短路径，如果是求满足一定条件的路径，就像dfs那样了）
- [x] 第四节课那个课件里那个count the path问题，用bfs也是不好做（虽然像水波纹一样从右下角扩散到左上角，但是用bfs不好记录状态），用dfs和dp好做，类似于word search和树的path sum，和22 generate parentness也类似，如果要输出所有路径，dfs合适；如果只要输出次数，那么dp也可以
- [x] dfs的问题如果要用dp来解，那么就要满足那4个条件，（比如起点值可以比较容易求得，因为dp自下而上，起点就是f（0），比如生成括号，string最后一个值就是f（0），但对于word search就不好求了），还要有比较明显的状态转移方程


- [x] 50 pow(x,n) solution 3总是错误

- [ ] 4 median of two sorted arrays 
查看第四题的kth element解法
https://discuss.leetcode.com/topic/26926/another-simple-and-neat-solution-binary-search-non-recursion-3-rows-of-core-code-o-log-min-m-n/2
https://discuss.leetcode.com/topic/9898/share-my-simple-o-log-m-n-c-solution
- [x] solution 5是否可行
- [x] log(min(m,n))怎么实现
- [ ] kth smallest element有什么关系？(kth element就是数据结构的 选取与中位数 一章)
- [ ] 215. Kth Largest Element in an Array
- [ ] solution 3的c如何实现？ 看295的solution 4

- [ ] 347. Top K Frequent Elements
- [ ] 692. Top K Frequent Words
也算priority queue的题目

-----

- [ ] algorithm.md里面 kth element和median 完成
- [ ] graph.md里面的图的结构转换
- [ ] algorithm.md里面 kmp 完成
- [ ] avl tree
- [ ] splay tree
- [ ] b- b+ b* tree
- [ ] skip list
- [ ] hash map（包括高并发）
- [ ] graph.md里面的todo
- [ ] dp
- [ ] 所有cpp添加test
- [ ] high frequency problems list

- [ ] redis
- [ ] go 构建微服务技术栈
- [ ] 分布式session
--------------------------------------------------------
根据那几个问题和其他问题，具体看dfs和bfs在什么场景下适合？


dfs
word search 、word search ii需要有当前和之前的状态和target比较，用bfs的话记录会比较麻烦，因为状态不能连续记录。
path sum 同上
n皇后和数独、word search类似
124. Binary Tree Maximum Path Sum 


bfs
01 matrix，感觉count the path那个问题也可以用bfs
433 minimum genetic mutation 求最短的变换路径，用bfs求得的第一个变换路径一定是最短的
127 word ladder 和433一模一样



200 number of islands 中blood fill就是用bfs和dfs都可以
