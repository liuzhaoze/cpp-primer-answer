比较你的可变参数版本的 errorMsg 和 [6.2.6 节](../../Chapter6_%E5%87%BD%E6%95%B0/note/note_6.2.md)中的 error_msg 函数。
两种方法的优点和缺点各是什么？

> 答：error_msg 函数接受一个初始化列表作为函数实参，这要求列表中的元素类型必须相同（或者可以转换为同一个公共类型）。  
> 而 errorMsg 函数可以接受任意类型的函数实参，它更加灵活。
