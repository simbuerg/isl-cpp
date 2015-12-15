#ifndef ISL_CXX_IslBase_H
#define ISL_CXX_IslBase_H
#include "isl/IslException.h"

#include <memory>
#include <vector>
#include <iostream>

namespace isl {
static inline void handleError(std::string what) {
#ifdef __EXCEPTIONS
  throw IslException(what);
#else
  std::cerr << what << std::endl;
  std::abort();
#endif
}

template <class T, typename... Args>
void map_inplace(T (T::*fn)(Args& ...args) const, std::vector<std::reference_wrapper<T>> &&objs, Args && ...args) {
  for (T &obj : objs)
    obj = (obj.*fn)(std::forward<Args>(args)...);
}
} //namespace isl
#endif //ISL_CXX_Context_H
