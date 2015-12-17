#ifndef ISL_CXX_BasicSetList_IMPL_H
#define ISL_CXX_BasicSetList_IMPL_H

#include "isl/BasicSetList.h"

#include "isl/BasicSet.hpp"
#include "isl/Ctx.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_basic_set_list *BasicSetList::GetCopy() const {
  return isl_basic_set_list_copy((isl_basic_set_list *)This);
}
inline BasicSetList &BasicSetList::operator=(const BasicSetList &Other) {
  isl_basic_set_list *New = Other.GetCopy();
  isl_basic_set_list_free((isl_basic_set_list *)This);
  This = New;
  return *this;
}
inline BasicSetList BasicSetList::alloc(const Ctx &ctx, int n) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_basic_set_list *That = isl_basic_set_list_alloc((ctx.Get()), n);
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_set_list_alloc returned a NULL pointer.");
  }

  return BasicSetList(_ctx, That);
}
inline BasicSetList::~BasicSetList() {
  isl_basic_set_list_free((isl_basic_set_list *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_basic_set_list *BasicSetList::Give() {
  isl_basic_set_list *res = (isl_basic_set_list *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_basic_set_list *BasicSetList::Get() const {  return (isl_basic_set_list *)This;
}

inline BasicSetList BasicSetList::asBasicSetList() const {
  return BasicSetList(ctx, GetCopy());
}

inline BasicSetList BasicSetList::add(const BasicSet &el) const {
  ctx.lock();
  BasicSetList self = asBasicSetList();
  // Prepare arguments
  BasicSet _cast_el = el.asBasicSet();
  // Call isl_basic_set_list_add
  isl_basic_set_list * res =  isl_basic_set_list_add((self).Give(), (_cast_el).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_list_add returned a NULL pointer.");
  }
  return BasicSetList(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_BasicSetList_IMPL_H
