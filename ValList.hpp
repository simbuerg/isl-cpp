#ifndef ISL_CXX_ValList_IMPL_H
#define ISL_CXX_ValList_IMPL_H

#include "isl/ValList.h"

#include "isl/Val.hpp"
#include "isl/Ctx.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_val_list *ValList::GetCopy() const {
  return isl_val_list_copy((isl_val_list *)This);
}
inline ValList &ValList::operator=(const ValList &Other) {
  isl_val_list *New = Other.GetCopy();
  isl_val_list_free((isl_val_list *)This);
  This = New;
  return *this;
}
inline ValList ValList::alloc(const Ctx &ctx, int n) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_val_list *That = isl_val_list_alloc((ctx.Get()), n);
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_val_list_alloc returned a NULL pointer.");
  }

  return ValList(_ctx, That);
}
inline ValList::~ValList() {
  isl_val_list_free((isl_val_list *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_val_list *ValList::Give() {
  isl_val_list *res = (isl_val_list *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_val_list *ValList::Get() const {  return (isl_val_list *)This;
}

inline ValList ValList::asValList() const {
  return ValList(GetCopy());
}

inline ValList ValList::add(const Val &el) const {
  ctx.lock();
  ValList self = asValList();
  // Prepare arguments
  Val _cast_el = el.asVal();
  // Call isl_val_list_add
  isl_val_list * res =  isl_val_list_add((self).Give(), (_cast_el).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_val_list_add returned a NULL pointer.");
  }
  return ValList(res);
}

} // namespace isl
#endif //ISL_CXX_ValList_IMPL_H
