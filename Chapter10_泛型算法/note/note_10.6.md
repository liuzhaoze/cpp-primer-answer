# 10.6 特定容器算法

链表类型 list 和 forward_list 定义了独有的 sort 、merge 、remove 、reverse 和 unique 算法。  
因为链表移动元素只需要改变指针，所以独有的算法效率更高。

*对于 list 和 forward_list ，应该优先使用成员函数版本的算法，而不是通用版本的算法。*

list 和 forward_list 成员函数版本的算法：

* `lst.merge(lst2)` ：将来自 lst2 的元素合并入 lst ，两者都必须是有序的
* `lst.merge(lst2, comp)` ：将元素从 lst2 中删除，合并之后 lst2 为空。第一个版本使用 < 运算符；第二个版本使用给定的比较操作
* `lst.remove(val)` ：调用 erase 删除与 val 相等的每个元素（使用 == 运算符）
* `lst.remove_if(pred)` ：调用 erase 删除所有使一元谓词 pred 为真的元素
* `lst.reverse()` ：反转 lst 中元素的顺序
* `lst.sort()` ：使用 < 运算符排序元素
* `lst.sort(comp)` ：使用给定的比较操作排序元素
* `lst.unique()` ：调用 erase 删除同一个值的连续拷贝，使用 == 运算符
* `lst.unique(pred)` ：调用 erase 删除同一个值的连续拷贝，前后两个元素使二元谓词 pred 为真时删除

*以上操作都返回 void 。*

链表类型的 splice 算法  
`lst.splice(args)` 和 `flst.splice_after(args)` 的参数：

* `(p, lst2)` ：p 是一个指向 lst 中元素的迭代器，或指向 flst 首前位置的迭代器。函数将 lst2 的所有元素移动到 lst 中 p 之前的位置或是 flst 中 p 之后的位置。并将所有元素从 lst2 中删除。两个容器的类型必须相同，且不能是同一个链表
* `(p, lst2, p2)` ：p2 是一个指向 lst2 中位置的有效迭代器。将 p2 指向的元素移动到 lst 中，或将 p2 之后的所有元素移动到 flst 中。lst2 可以是与 lst 或 flst 相同的链表
* `(p, lst2, b, e)` ：b 和 e 必须表示 lst2 中的合法范围。将给定范围中的元素从 lst2 移动到 lst 或 flst 。两者可以是相同的链表，但 p 不能指向给定范围中的元素

*注意：链表独有的操作会改变容器。链表版本的 merge 会将一个容器中的元素移动到另一个容器中。普通版本的 merge 则是拷贝元素，两个输入序列不变。*

## 练习

* [练习 10.42](../src/quiz_10.42.cpp)
