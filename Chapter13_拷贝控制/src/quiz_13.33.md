为什么 Message 的成员 save 和 remove 的参数是一个 `Folder &` ？
为什么我们不能将参数定义为 `Folder` 或是 `const Folder &` ？

> 答：
>  
> save 和 remove 操作需要向 `Folder` 中的 `Message *` 集合中添加/删除元素，这会改变 `Folder` 的成员，所以不能使用 `const Folder &` ；
>  
> save 和 remove 操作也需要将给定 Folder 从自己的 `Folder *` 集合中添加或删除，使用 `Folder` 则会将给定 Folder 的拷贝的指针（也就是形参的地址）添加到集合中，而这个拷贝在函数返回时就被销毁了。我们真正想添加的是实参的指针，而非形参的指针。所以不能使用 `Folder` 。
