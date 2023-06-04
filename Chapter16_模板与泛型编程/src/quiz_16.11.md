下面 List 的定义是错误的。应该如何修正它？

```cpp
template <typename elemType> class ListItem;
template <typename elemType> class List
{
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType> &operator=(const List<elemType> &);
    ~List();

    void insert(ListItem *ptr, elemType value);

private:
    ListItem *front, *end;
};
```

> 答：模板不能作为类型，应该给 `ListItem` 指明模板实参：`ListItem<elemType>` （共 2 处）
