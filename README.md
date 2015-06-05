

 Algorithm
===============

  ###建樹:Binary Tree, Heap (AVL Tree, Segment Tree)
  ###建圖:Adjacency matrix, Adjacency list, (Spanning Tree)
  ###搜索:DFS, BFS
  ###最短路徑:Kruskal, (Prim, Sollin)
  ###其他:DP(Dynamic Programming), Fast Pow
  ###字串:Hashing, KMP(用於比較字串), (AC automation)

+ Binary Tree:大部份是要加速搜索到O(log n)，也可以用來做排序，可以搭配搜索跟最短路徑演算法。
+ Heap:這是priority_queue的底層，可以隨時在O(log n)的時間內得到陣列的最大值(平常是O(n))，也可以進行sort
+ AVL Tree:測資不好的時二元樹會很偏某一邊，效率大幅降低，AVL Tree可以旋轉節點進行平衡而且不破壞原本的樹
+ Segment Tree:平常取得陣列中某個區間個最大值需要O(n)，用Segmet Tree可以降到O(log n)
+ Adjacency Matrix:建一個圖描述點與點之間的關係，用二維陣列存，快但是耗空間
+ Adjacency List:一樣是建圖，但是是用vector陣列存，略慢但是省很多空間
+ Spanning Tree:用DFS搭配圖建出來的一棵樹，可以在最短路徑內走遍整張圖(郵差送信問題)
+ DFS, BFS:這應該不用說了
+ Kruskal, Prim, Sollin:在一張圖上用最短路徑走到某個點
+ DP:讓遞迴不重複算已經算過的東西，像費氏數列F(x)=F(x-1)+F(x-2)，用遞回式F(50)的話很多東西會重複算，拖慢超超超多
+ Fast Pow:中文叫快速冪，平常算a^n要O(n)，用快速冪就只要O(log n)，之前應該給你看過速度上的差別
+ Hashing:把字串當成算成一個整數，這樣比較字串的時候就不用一個一個字元比
+ KMP:在一個大字串中快速找出比配字串(一對一)，譬如說要在"abcddec"中找出裡面有沒有"cdde"這個字串
+ AC automation:快速找出匹配字串(一對多)，譬如說要在"abcddec"，找"abc", "cdd", "abb", "dde" 哪些出現過

Websites
========
- [C++ Reference](http://www.cplusplus.com/reference/)
- [Algorithm Note](http://www.csie.ntnu.edu.tw/~u91029/)
- [GitHub](https://github.com/)
- [BitBucket](https://bitbucket.org/)
- [CodeData](http://www.codedata.com.tw/)
- [Data Structure Visual](http://www.cs.usfca.edu/~galles/visualization/Algorithms.html)
- [edx](https://www.edx.org/)

Online Judge
============
- [ZeroJudge Senior](http://zerojudge.tw/)
- [ZeroJudge College](http://judge.nccucs.org/Problems)
- [TCGS](http://www.tcgs.tc.edu.tw:1218/)
- [TIOJ](http://tioj.ck.tp.edu.tw/problems)
- [CodeForce](http://codeforces.com/)

Course
======

### 大數

- BigNum
- 補充 - 小數 (看狀況)
- 補充 - 負數 (看狀況)
- 大數優化 - 壓位數 (概念)

### STL

- \<utility\> - pair()
- STL : vector
- STL : queue FIFO
- STL : stack FILO
- STL : map (看狀況)
- STL : set (看狀況)
- STL : list (看狀況)
- \<algorithm\>


### 串流

- ostream & istream
- 多載 << & >>
- stringstream
- fstream(看狀況)
