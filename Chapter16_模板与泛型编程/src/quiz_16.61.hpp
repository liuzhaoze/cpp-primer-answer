/**
 * 定义你自己版本的 make_shared 。
 */

#ifndef _QUIZ_16_61_HPP_
#define _QUIZ_16_61_HPP_

#include <memory>

namespace quiz
{
template <typename T, typename... Args> auto make_shared(Args &&...args) -> std::shared_ptr<T>
{
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}
} // namespace quiz

#endif
