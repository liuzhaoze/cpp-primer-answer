#ifndef _EMAIL_HPP_
#define _EMAIL_HPP_

#include <set>
#include <string>

class Folder;
class Message;

class Message
{
  public:
    friend class Folder;
    friend void swap(Message &, Message &);

  private:
    std::string contents;       // 消息文本
    std::set<Folder *> folders; // 包含本 Message 的 Folder

    // 将给定的 Folder 添加到集合中
    void addFldr(Folder *);
    // 将给定的 Folder 从集合中移除
    void remFldr(Folder *);

    // 将本 Message 添加到给定 Message 所在的所有 Folder 中
    void add_to_Folders(const Message &);
    // 将本 Message 从 folders 中的所有 Folder 中移除
    void remove_from_Folders();

    // 使用给定 Message 的 folders 成员更新本 Message 的成员，并将给定 Message 的 folders 设置为析构安全的状态
    void move_Folders(Message *);

  public:
    // 默认构造函数
    explicit Message(const std::string &str = "") : contents(str)
    {
    }
    // 拷贝构造函数
    Message(const Message &);
    // 析构函数
    ~Message();
    // 拷贝赋值运算符
    Message &operator=(const Message &);
    // 移动构造函数
    Message(Message &&);
    // 移动赋值运算符
    Message &operator=(Message &&);

    // 从给定 Folder 中添加本 Message
    void save(Folder &);
    // 从给定 Folder 中删除本 Message
    void remove(Folder &);
};

inline void swap(Message &, Message &);

class Folder
{
  public:
    friend class Message;
    friend void swap(Folder &, Folder &);

  private:
    std::set<Message *> msgs;

    // 将给定的 Messages 添加到集合中
    void addMsg(Message *);
    // 将给定的 Messages 从集合中移除
    void remMsg(Message *);

    // 向给定 Folder 中的所有 Message 中添加本 Folder
    void add_to_Messages(const Folder &);
    // 将本 Folder 从 msgs 中的所有 Message 中移除
    void remove_from_Messages();

  public:
    // 默认构造函数
    Folder() = default;
    // 拷贝构造函数
    Folder(const Folder &);
    // 析构函数
    ~Folder();
    // 拷贝赋值运算符
    Folder &operator=(const Folder &);
};

inline void swap(Folder &, Folder &);

#endif
