# 13.4 拷贝控制示例

## Message 类

* 使用一个 set 记录其所在的所有 Folder
* save 操作：将 Message 放入指定的 Folder 中
* remove 操作：将 Message 从指定的 Folder 中移除
* 拷贝 Message ：副本和原本是不同的 Message 对象，但存入相同的 Folder
* 销毁 Message ：从包含此消息的所有 Folder 中移除此消息的指针
* 赋值：右侧的 Message 覆盖左侧的 Message ，将左侧的 Message 从所有 Folder 中移除，并且添加到所有右侧的 Message 所在的 Folder 中

## Folder 类

* 使用一个 set 记录其包含的所有 Message
* addMsg 操作：将一条 Message 的指针放入 set 中
* remMsg 操作：将一条 Message 的指针从 set 中移除

## 练习

* [练习 13.33](../src/quiz_13.33.md)
* [练习 13.34](../src/quiz_13.34.md)
* [练习 13.35](../src/quiz_13.35.md)
* [练习 13.36](../src/quiz_13.36.md)
* [练习 13.37](../src/quiz_13.37.md)
* [练习 13.38](../src/quiz_13.38.md)
