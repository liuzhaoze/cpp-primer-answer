/**
 * 给定下面的两个类，为它们实现一个默认构造函数和必要的拷贝控制成员。
 */

#ifndef _QUIZ_13_28_HPP_
#define _QUIZ_13_28_HPP_

#include <string>

/**
 * @brief 行为像指针的 TreeNode 类
 *
 */
class TreeNode
{
  private:
    std::string value;
    int *count;
    TreeNode *left, *right;

  public:
    // 默认构造函数
    TreeNode() : value(std::string()), count(new int(1)), left(nullptr), right(nullptr)
    {
    }

    // 拷贝控制成员：拷贝构造函数、拷贝赋值运算符、析构函数
    TreeNode(const TreeNode &tn) : value(tn.value), count(tn.count), left(tn.left), right(tn.right)
    {
        ++(*count);
    }

    TreeNode &operator=(const TreeNode &rhs)
    {
        ++(*(rhs.count));

        if (--(*count) == 0)
        {
            delete count;
            delete left;
            delete right;
        }

        value = rhs.value;
        count = rhs.count;
        left = rhs.left;
        right = rhs.right;

        return *this;
    }

    ~TreeNode()
    {
        if (--(*count) == 0)
        {
            delete count;
            delete left;
            delete right;
        }
    }
};

/**
 * @brief 行为像值的 BinStrTree 类
 *
 */
class BinStrTree
{
  private:
    TreeNode *root;

  public:
    // 默认构造函数
    BinStrTree() : root(new TreeNode())
    {
    }

    // 拷贝控制成员：拷贝构造函数、拷贝赋值运算符、析构函数
    BinStrTree(const BinStrTree &bst) : root(new TreeNode(*(bst.root)))
    {
    }

    BinStrTree &operator=(const BinStrTree &rhs)
    {
        TreeNode *new_root = new TreeNode(*(rhs.root));
        delete root;

        root = new_root;

        return *this;
    }

    ~BinStrTree()
    {
        delete root;
    }
};

#endif
