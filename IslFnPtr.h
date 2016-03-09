#ifndef ISL_CXX_FN_PTR_H
#define ISL_CXX_FN_PTR_H

#include <unistd.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <functional>
#include <cmath>

template <const size_t _UniqueId, typename _Res, typename... _ArgTypes>
struct fun_ptr_helper
{
public:
  typedef std::function<_Res(_ArgTypes...)> function_type;

  static void bind(function_type&& f)
  { instance().fn_.swap(f); }

  static void bind(const function_type& f)
  { instance().fn_=f; }

  static _Res invoke(_ArgTypes... args)
  { return instance().fn_(args...); }

  typedef decltype(&fun_ptr_helper::invoke) pointer_type;
  static pointer_type ptr()
  { return &invoke; }

private:
  static fun_ptr_helper& instance()
  {
    static fun_ptr_helper inst_;
    return inst_;
  }

  fun_ptr_helper() {}
  function_type fn_;
};

template <const size_t _UniqueId, typename _Res, typename... _ArgTypes>
typename fun_ptr_helper<_UniqueId, _Res, _ArgTypes...>::pointer_type
get_fn_ptr(const std::function<_Res(_ArgTypes...)>& f)
{
  fun_ptr_helper<_UniqueId, _Res, _ArgTypes...>::bind(f);
  return fun_ptr_helper<_UniqueId, _Res, _ArgTypes...>::ptr();
}
#endif //ISL_CXX_FN_PTR_H
