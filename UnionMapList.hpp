#ifndef ISL_CXX_UnionMapList_IMPL_H
#define ISL_CXX_UnionMapList_IMPL_H

#include "isl/UnionMapList.h"

#include "isl/UnionMap.hpp"
#include "isl/Ctx.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include <cassert>

namespace isl {

inline isl_union_map_list *UnionMapList::GetCopy() const {
  return isl_union_map_list_copy((isl_union_map_list *)This);
}
inline UnionMapList &UnionMapList::operator=(const UnionMapList &Other) {
  isl_union_map_list *New = Other.GetCopy();
  ctx = Other.Context();
  isl_union_map_list_free((isl_union_map_list *)This);
  This = New;
  return *this;
}
inline UnionMapList UnionMapList::alloc(const Ctx &ctx, int n) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_union_map_list *That = isl_union_map_list_alloc((ctx.Get()), n);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_map_list_alloc returned a NULL pointer.");
  }

  return UnionMapList(_ctx, That);
}
inline UnionMapList::~UnionMapList() {
  isl_union_map_list_free((isl_union_map_list *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_union_map_list *UnionMapList::Give() {
  isl_union_map_list *res = (isl_union_map_list *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_union_map_list *UnionMapList::Get() const {  return (isl_union_map_list *)This;
}

inline UnionMapList UnionMapList::add(const UnionMap &el) const {
  ctx.lock();
  isl_union_map_list * res =  isl_union_map_list_add((*this).GetCopy(), (el).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_list_add returned a NULL pointer.");
  }
  return UnionMapList(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_UnionMapList_IMPL_H
