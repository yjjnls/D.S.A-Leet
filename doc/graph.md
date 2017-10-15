
## DFS
一根筋走到底
需要用hash表或者stack来保存已经访问过的结点
[演示过程](http://www.cs.usfca.edu/~galles/visualization/DFS.html)

<!-- ![dfs](./img/Graph/dfs.png) -->
![dfs_gif](./img/Graph/dfs.gif)
### 模版
```python
def DFS(graph, start):
    # 1.terminator
    if start is None:
        return []
    # 2.init container
    visited = []
    stack = [(start)]

    while stack:
        # 3.pop one node from container
        node  = stack.pop()
        visited.add(node)
        # 4.process current node
        process(node)
        # 5.push releated nodes to container
        nodes = generate_related_nodes(node)
        stack.push(nodes)

    #other processing work
    ...
```
* DFS可以用递归，如果不用递归，则用stack来维护

* 时间复杂度为O(N)，每个结点只访问一次

递归做法
* 200 Number of Islands
* 79 Word Search
* 102 Binary Tree Level Order Traversal
## BFS
[display](http://www.cs.usfca.edu/~galles/visualization/BFS.html)
<!-- ![dfs](./img/Graph/bfs.png) -->
![dfs_gif](./img/Graph/bfs.gif)

### 模板
```python
def BFS(graph, start):
    # 1.terminator
    if start is None:
        return []
    # 2.init container
    visited = []
    queue.append([start])

    while queue:
        # 3.pop one node from container
        node = queue.pop()
        visited.add(node)
        # 4.process current node
        process(node)
        # 5.push releated nodes to container
        nodes = generate_related_nodes(node)
        queue.push(nodes)

    # other processing work
    ...
```

* BFS不能用递归，因为递归是往下深入一层，与BFS的语义就违背了。所以BFS只能用队列来维护。
* time:O(N)

* 对于树的BFS和DFS，不需要判重，因为树没有环。

* 102 Binary Tree Level Order Traversal

## extension
DFS用stack
BFS用queue
如果用priority_queue,就是A*算法，启发式搜索