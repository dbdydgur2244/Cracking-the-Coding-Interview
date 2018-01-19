# Chapter 4 : Tree and Graphs

## Tree

Tree의 recursive explanation은 다음과 같음.

- 각 tree는 root node를 가지고 있음
- root node는 0 또는 0개 이상의 child nodes를 가지고 있음.
- 각 child node도 마찬가지임.

 Tree는 cycle이 있을 수 없다.



### Binary Tree

node가 최대 2개의 자식을 가지는 tree임.



### Binary Search Tree

all left descendent <= n < all right descendents한 특징을 가지고 있음.

Balanced인 경우에만 insert와 find에 $O(logn)$을 보장함.



### Complete Binary Trees



### Full Binary Trees



### Perfect Binary Trees



### Bidirectional Search

Bidirectional Search는 주로 source와 destination node간의 shortest path를 찾는데 사용함.

source와 destination에서 동시에 BFS를 사용하여 만나면 path로 간주.

최대 neighbor가 k, source : s와 destination: t, s와 t간의 길이가 d라고 할 때, BFS로 찾을 땐 최대 $O(k^d)$, Bidirectional은 $O(k^{d/2})$






​	