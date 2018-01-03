# Chapter 4 : Tree and Graphs

1. Graph and find route problem

   단순히 dfs or bfs를 사용하여  O(n + m)를  n번하여 모두 탐색 가능

   따라서 총 시간 복잡도는 $O(n^2 + nm)$

   비슷한 문제로 모든 vertex에서 최단 거리를 찾는 방법이 있겠다.

   https://en.wikipedia.org/wiki/Johnson%27s_algorithm 참고

   ​

2. binary search tree의 특징을 이용한다. complete tree로 만드는 경우, 그냥 balanced tree로 만드는 경우가 있다.

   > 소스 코드 참고

3. recursive한 함수를 사용하여서 구현하면 됨. 간단. pass.
   ​

4. depth를 파라미터를 가진 재귀함수 작성. leat node인 경우 depth를 따로 저장하여 정렬하여서 가장 작은 값과 큰 값의 차이가 1 이상 안나면 balance


5. inorder가 정렬되어있는지 확인


6. ?? 무슨 말인지 모르겟음 솔루션 확인


7. graph 문제이다. directed graph를 구성하여서 cycle이 있는지 확인하면 됨. cycle이 있으면 종속성을 만족할 수 가 없으므로 false, 있으면 그냥 위상 정렬 사용해서 출력하면 됨. 


8. LCS  알고리즘 사용하여 탐색하면 된다.


9. 무슨 말인지 모르겠음. 솔루션 참고


10. binary tree인 경우 inorder와 preorder 순회 결과를 알고 있으면 unique한 tree 구성 가능. 따라서 그 결과를 string화 해서 T1의 결과와 KMP 사용하여 substring인 경우 true 아니면 false.

   > N개의 subtree를 가지는 경우 아호코라식을 사용하면 됨.


11. 무슨 말일까…? 이해를 못하겠음


12. ​
