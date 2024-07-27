# Red black tree
與AVL tree相同，為了避免BST的worst case，因此它會自己平衡樹的高度，但紅黑樹的樹高和其他平衡樹的定義不同(等一下會提)

紅黑樹會滿足以下條件:
1. 每個node不是黑色就是紅色
2. 整棵tree的root一定是黑色
3. null視為黑色
4. 不能有連續的紅色(紅色的child一定得是黑色)，黑色無此規定
5. 從任意節點到tree leaf的path上會經過相同數量的黑node(紅黑樹樹高，black height)

若違反上面的其中一點，就會進行調整

## Color change
在等一下insert node的過程，若遇到一個node其兩個child皆為紅色，則需要進行此步驟

將此node變為紅色，並將其兩個child變成黑色，如下圖
![color_change](color_change.png)

## Rotation
基本上紅黑樹的rotation也是left rotation和right rotation，和AVL tree相同，請參考下網址

[https://github.com/kow3388/DS_and_Algo/tree/main/DS/AVL_tree](https://github.com/kow3388/DS_and_Algo/tree/main/DS/AVL_tree)

## Insert node
在紅黑樹插入一個node步驟如下
1. 先search node該插入的位置
2. 在search的過程中若遇到某個node兩個child為紅色的話，則進行color change
3. 將x插入正確的位置，顏色為紅色
4. 檢查有無連續的紅色，若有則進行rotation
5. Root一律改為黑色

## Delete node
刪除node和BST的方式不會插到太多，找到其位置並要找一個node去替代其位置，但會需要去紀錄其要刪除點的顏色為後面維護紅黑樹的平衡

講起來容易，其實在implement時相當複雜

## Implement
### C++
### Python

###### `tree`
