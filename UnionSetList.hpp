#ifndef ISL_CXX_UnionSetList_IMPL_H
#define ISL_CXX_UnionSetList_IMPL_H

#include "isl/UnionSetList.h"

#include "isl/UnionSet.hpp"
#include "isl/Ctx.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_union_set_list *UnionSetList::GetCopy() const {
  return isl_union_set_list_copy((isl_union_set_list *)This);
}
inline UnionSetList &UnionSetList::operator=(const UnionSetList &Other) {
  isl_union_set_list *New = Other.GetCopy();
  isl_union_set_list_free((isl_union_set_list *)This);
  This = New;
  return *this;
}
inline UnionSetList UnionSetList::alloc(const Ctx &ctx, int n) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_union_set_list *That = isl_union_set_list_alloc((ctx.Get()), n);
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_set_list_alloc returned a NULL pointer.");
  }

  return UnionSetList(_ctx, That);
}
inline UnionSetList::~UnionSetList() {
  isl_union_set_list_free((isl_union_set_list *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_union_set_list *UnionSetList::Give() {
  isl_union_set_list *res = (isl_union_set_list *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_union_set_list *UnionSetList::Get() const {  return (isl_union_set_list *)This;
}

inline UnionSetList UnionSetList::asUnionSetList() const {
  return UnionSetList(GetCopy());
}

inline UnionSetList UnionSetList::add(const UnionSet &el) const {
  ctx.lock();
  UnionSetList self = asUnionSetList();
  // Prepare arguments
  UnionSet _cast_el = el.asUnionSet();
  // Call isl_union_set_list_add
  isl_union_set_list * res =  isl_union_set_list_add((self).Give(), (_cast_el).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_list_add returned a NULL pointer.");
  }
  return UnionSetList(res);
}

} // namespace isl
#endif //ISL_CXX_UnionSetList_IMPL_H
