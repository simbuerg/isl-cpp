#ifndef ISL_CXX_SetList_IMPL_H
#define ISL_CXX_SetList_IMPL_H

#include "isl/SetList.h"

#include "isl/Set.hpp"
#include "isl/Ctx.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include <cassert>

namespace isl {

inline isl_set_list *SetList::GetCopy() const {
  return isl_set_list_copy((isl_set_list *)This);
}
inline SetList &SetList::operator=(const SetList &Other) {
  isl_set_list *New = Other.GetCopy();
  ctx = Other.Context();
  isl_set_list_free((isl_set_list *)This);
  This = New;
  return *this;
}
inline SetList SetList::alloc(const Ctx &ctx, int n) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_set_list *That = isl_set_list_alloc((ctx.Get()), n);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_set_list_alloc returned a NULL pointer.");
  }

  return SetList(_ctx, That);
}
inline SetList::~SetList() {
  isl_set_list_free((isl_set_list *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_set_list *SetList::Give() {
  isl_set_list *res = (isl_set_list *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_set_list *SetList::Get() const {  return (isl_set_list *)This;
}

inline SetList SetList::add(const Set &el) const {
  ctx.lock();
  isl_set_list * res =  isl_set_list_add((*this).GetCopy(), (el).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_list_add returned a NULL pointer.");
  }
  return SetList(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_SetList_IMPL_H
