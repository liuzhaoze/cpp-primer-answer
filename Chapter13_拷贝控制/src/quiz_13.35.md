如果 Message 使用合成的拷贝控制成员，将会发生什么？

> 答：这会导致 Message 在进行拷贝、赋值、销毁时，相关的 Folder 无法正确地同步 `Message *` 集合中的指针。
