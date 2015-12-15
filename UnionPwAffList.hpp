#ifndef ISL_CXX_UnionPwAffList_IMPL_H
#define ISL_CXX_UnionPwAffList_IMPL_H

#include "isl/UnionPwAffList.h"

#include "isl/UnionPwAff.hpp"
#include "isl/Ctx.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_union_pw_aff_list *UnionPwAffList::GetCopy() const {
  return isl_union_pw_aff_list_copy((isl_union_pw_aff_list *)This);
}
inline UnionPwAffList &UnionPwAffList::operator=(const UnionPwAffList &Other) {
  isl_union_pw_aff_list *New = Other.GetCopy();
  isl_union_pw_aff_list_free((isl_union_pw_aff_list *)This);
  This = New;
  return *this;
}
inline UnionPwAffList UnionPwAffList::alloc(const Ctx &ctx, int n) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_union_pw_aff_list *That = isl_union_pw_aff_list_alloc((ctx.Get()), n);
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_pw_aff_list_alloc returned a NULL pointer.");
  }

  return UnionPwAffList(_ctx, That);
}
inline UnionPwAffList::~UnionPwAffList() {
  isl_union_pw_aff_list_free((isl_union_pw_aff_list *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_union_pw_aff_list *UnionPwAffList::Give() {
  isl_union_pw_aff_list *res = (isl_union_pw_aff_list *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_union_pw_aff_list *UnionPwAffList::Get() const {  return (isl_union_pw_aff_list *)This;
}

inline UnionPwAffList UnionPwAffList::asUnionPwAffList() const {
  return UnionPwAffList(GetCopy());
}

inline UnionPwAffList UnionPwAffList::add(const UnionPwAff &el) const {
  ctx.lock();
  UnionPwAffList self = asUnionPwAffList();
  // Prepare arguments
  UnionPwAff _cast_el = el.asUnionPwAff();
  // Call isl_union_pw_aff_list_add
  isl_union_pw_aff_list * res =  isl_union_pw_aff_list_add((self).Give(), (_cast_el).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_aff_list_add returned a NULL pointer.");
  }
  return UnionPwAffList(res);
}

} // namespace isl
#endif //ISL_CXX_UnionPwAffList_IMPL_H
