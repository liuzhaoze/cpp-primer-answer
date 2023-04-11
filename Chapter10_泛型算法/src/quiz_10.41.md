仅根据算法和参数的名字，描述下面每个标准库算法执行什么操作：

(a) `replace(beg, end, old_val, new_val);`  
(b) `replace_if(beg, end, pred, new_val);`  
(c) `replace_copy(beg, end, dest, old_val, new_val);`  
(d) `replace_copy_if(beg, end, dest, pred, new_val);`

> 答：  
> (a) 将输入范围内 old_val 的值替换为 new_val ；  
> (b) 将输入范围内使 pred 为真的值替换为 new_val ；  
> (c) 输入范围内的元素不变，将 (a) 的替换结果拷贝到 dest 所指位置；  
> (d) 输入范围内的元素不变，将 (b) 的替换结果拷贝到 dest 所指位置。
