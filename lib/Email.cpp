#include "Email.hpp"
#include <map>
#include <utility>

void Message::addFldr(Folder *f)
{
    folders.insert(f);
}

void Message::remFldr(Folder *f)
{
    folders.erase(f);
}

void Message::save(Folder &f)
{
    addFldr(&f);    // 将给定 Folder 添加到本 Message 的 Folder 集合中
    f.addMsg(this); // 将本 Message 添加到给定 Folder 的 Message 集合中
}

void Message::remove(Folder &f)
{
    remFldr(&f);    // 将给定 Folder 从本 Message 的 Folder 集合中移除
    f.remMsg(this); // 将本 Message 从给定 Folder 的 Message 集合中移除
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders) // 对消息 m 所在的每一个 Folder
    {
        f->addMsg(this); // 将本 Message 添加到每一个 Folder 中
    }
}

void Message::remove_from_Folders()
{
    for (auto f : folders) // 对本消息所在的每一个 Folder
    {
        f->remMsg(this); // 将本消息从每一个 Folder 中移除
    }
}

void Message::move_Folders(Message *m)
{
    folders = std::move(m->folders); // 将给定 Massage 的 folders 成员的内存交给本 Message 接管

    for (auto f : folders)
    {
        f->remMsg(m);    // 删除旧 Message
        f->addMsg(this); // 添加本 Message（新）
    }

    m->folders.clear(); // 设置为析构安全的状态
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m); // 将本 Message 添加到 m 所在的所有 Folder 中
}

Message::Message(Message &&m) : contents(std::move(m.contents)) // 移动 contents
{
    move_Folders(&m); // 移动 folders
}

Message::~Message()
{
    remove_from_Folders();
}

Message &Message::operator=(const Message &rhs)
{
    remove_from_Folders(); // 先删除再插入可以解决自赋值的问题
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);

    return *this;
}

Message &Message::operator=(Message &&rhs)
{
    if (this != &rhs)
    {
        remove_from_Folders();              // 将本 Message 从所有 Folder 中删除
        contents = std::move(rhs.contents); // 移动 contents
        move_Folders(&rhs);                 // 移动 folders
    }

    return *this;
}

inline void swap(Message &lhs, Message &rhs)
{
    using std::swap;

    // 将消息从其所在的 Folder 中移除
    lhs.remove_from_Folders();
    rhs.remove_from_Folders();

    // 交换成员
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);

    // 将交换后的消息添加到新 Folder 中
    lhs.add_to_Folders(lhs);
    rhs.add_to_Folders(rhs);
}

void Folder::addMsg(Message *m)
{
    msgs.insert(m);
}

void Folder::remMsg(Message *m)
{
    msgs.erase(m);
}

void Folder::add_to_Messages(const Folder &f)
{
    for (auto m : f.msgs)
    {
        m->addFldr(this);
    }
}

void Folder::remove_from_Messages()
{
    for (auto m : msgs)
    {
        m->remFldr(this);
    }
}

Folder::Folder(const Folder &f) : msgs(f.msgs)
{
    add_to_Messages(f);
}

Folder::~Folder()
{
    remove_from_Messages();
}

Folder &Folder::operator=(const Folder &rhs)
{
    remove_from_Messages();
    msgs = rhs.msgs;
    add_to_Messages(rhs);

    return *this;
}

inline void swap(Folder &lhs, Folder &rhs)
{
    using std::swap;

    lhs.remove_from_Messages();
    rhs.remove_from_Messages();

    swap(lhs.msgs, rhs.msgs);

    lhs.add_to_Messages(lhs);
    rhs.add_to_Messages(rhs);
}
