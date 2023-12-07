# Topological Sort
- Need to be DAG(Directed Acyclic Graph)
- There may be more than one result
- Time complexity : O(V+E) (V: vertex, E: edge)
- Space complexity : O(V)
- vertex(x) need to appear before vertex(y)
  EX: vertex(4) need to appear vertex(0)
  ![DAG](https://hackmd.io/_uploads/BkSt4tv4a.jpg)

    | vertex |   |   |
    | ------ | - | - |
    | 0      |   |   |
    | 1      |   |   |
    | 2      | 3 |   |
    | 3      | 1 |   |
    | 4      | 0 | 1 |
    | 5      | 0 | 2 |
    
    This two topological sort result in this case is acceptable:
    5, 4, 2, 3, 1, 0
    4, 5, 2, 3, 1, 0

## DFS
以DFS的方式去訪問node，將node設為visited，如果還能往下走先往下走，如果不行則push進stack中，最後將stack pop得到最後的結果

### DFS Example
以上圖為例

1. 訪問node 0，將node 0設為visited，無法往下走，push進stack中
   stack : [0] 
   
2. 訪問node 1，將node 1設為visited，無法往下走，push進stack中
   stack : [0, 1] 

3. 訪問node 2，將node 2設為visited，往下走
   stack : [0, 1]

4. 訪問node 3，將node 3設為visited，無法往下走，push進stack中，回node 2
   stack : [0, 1, 3]
   
5. node 2無法往下走，push進stack中
   stack : [0, 1, 3, 2]

6. 訪問node 4，將node 4設為visited，其他點已visited，push進stack中
   stack : [0, 1, 3, 2, 4]

7. 訪問node 5，將node 5設為visited，其他點已visited，push進stack中
   stack : [0, 1, 3, 2, 4, 5]

8. 得Res : [5, 4, 2, 3, 1, 0]

### Implement DFS
#### C++
```cpp=
class topological_sort
{
    public:
        vector<vector<int>> graph;
        vector<bool> visited;
        stack<int> stk;
    
        topological_sort(vector<vector<int>> g)
        {
            this.graph.insert(this.graph.end(), g.begin(), g.end());
            this.visited.resize(g.size(), false);
        }
    
        void _sort(int point)
        {
            if(!visited[point])
            {
                visited[point] = True;
                
                for(int p : graph[point])
                    if(!visited[p])
                        _sort(p);
            }
            
            stk.push(point);
        }
        
        void print_res()
        {
            for(int i : graph)
                if(!visited[i])
                    _sort(i);
            
            while(!stk.empty())
            {
                cout << stk.top() << " ";
                stk.pop();
            }
            cout << endl;
        }
};
```

#### Python
```python=
class topological_sort:
    def __init__(self, graph: List[List[int]]):
        self.graph = graph
        self.visited = [False]*len(self.graph)
        self.stk = []
    
    def _sort(self, point: int):
        if not self.visited[point]:
            self.visited[point] = True
            for p in self.graph[point]:
                if not self.visited[p]:
                    self._sort(p)
                    
        self.stk.append(point)
    
    def print_res(self):
        for i in range(len(self.graph)):
            if not self.visited[i]:
                self._sort(i)
        
        print(reversed(self.stk))
```

## Kahn Algo (BFS)
計算每個node的in degree，每次將in degree為0的node push進queue中，並把此node有指向別人的edge去除，並將被指向的node in degree - 1，重複上述動作，直到所有node皆被push進queue中，此queue即為最終結果

### Kahn Example
一樣以上圖為例

1. 計算所有的in degree得
   node 0 : 2
   node 1 : 2
   node 2 : 1
   node 3 : 1
   node 4 : 0
   node 5 : 0

2. 將in degree = 0的push進queue中
   queue : [4, 5] 

3. 將node 4和node 5有指向的node in degree - 1
   node 0 : 0
   node 1 : 1
   node 2 : 0
   node 3 : 1

4. 將in degree = 0的push進queue中
   queue : [4, 5, 0, 2] 

5. 將node 0和node 2有指向的node in degree - 1
   node 1 : 1
   node 3 : 0

6. 將in degree = 0的push進queue中
   queue : [4, 5, 0, 2, 3] 

7. 將node 0和node 2有指向的node in degree - 1
   node 1 : 0

8. 將in degree = 0的push進queue中
   queue : [4, 5, 0, 2, 3, 1]

9. 得Res : [4, 5, 0, 2, 3, 1]

### Implement Kahn
#### C++
```cpp=
class topological_sort_kahn
{
	public:
		vector<vector<int>> graph;
		vector<int> degree;
		vector<int> target;
		queue<int> q;

		topological_sort_kahn(vector<vector<int>> g)
		{
			graph = g;

			degree.resize(g.size(), 0);
			for(int i = 0; i < graph.size(); i++)
				for(int n : graph[i])
					degree[n]++;

			for(int i = 0; i < degree.size(); i++)
				if(degree[i] == 0)
					q.push(i);
		}

		void print_res()
		{
			while(!q.empty())
			{
				int node = q.front();
				q.pop();
				target.emplace_back(node);

				for(int i : graph[node])
				{
					degree[i]--;
					if(degree[i] == 0)
						q.push(i);
				}
			}

			for(int node : target)
				cout << node << " ";
			cout << endl;
		}
};
```

#### Python
```python=
class topological_kahn:
    def __init__(self, g: list[list[int]]):
        self.graph = g
        self.target = []

        self.degree = [0]*len(g)
        for node in g:
            for n in node:
                self.degree[n] += 1
        
        self.q = queue.Queue()
        for i in range(len(g)):
            if self.degree[i] == 0:
                self.q.put(i)

    def print_res(self):
        while not self.q.empty():
            node = self.q.get()
            self.target.append(node)

            for n in self.graph[node]:
                self.degree[n] -= 1
                if self.degree[n] == 0:
                    self.q.put(n)

        print(self.target)
```
###### tag : `Graph` `DFS` `BFS`