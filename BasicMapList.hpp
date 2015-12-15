#ifndef ISL_CXX_BasicMapList_IMPL_H
#define ISL_CXX_BasicMapList_IMPL_H

#include "isl/BasicMapList.h"

#include "isl/BasicMap.hpp"
#include "isl/Ctx.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_basic_map_list *BasicMapList::GetCopy() const {
  return isl_basic_map_list_copy((isl_basic_map_list *)This);
}
inline BasicMapList &BasicMapList::operator=(const BasicMapList &Other) {
  isl_basic_map_list *New = Other.GetCopy();
  isl_basic_map_list_free((isl_basic_map_list *)This);
  This = New;
  return *this;
}
inline BasicMapList BasicMapList::alloc(const Ctx &ctx, int n) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_basic_map_list *That = isl_basic_map_list_alloc((ctx.Get()), n);
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_list_alloc returned a NULL pointer.");
  }

  return BasicMapList(_ctx, That);
}
inline BasicMapList::~BasicMapList() {
  isl_basic_map_list_free((isl_basic_map_list *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_basic_map_list *BasicMapList::Give() {
  isl_basic_map_list *res = (isl_basic_map_list *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_basic_map_list *BasicMapList::Get() const {  return (isl_basic_map_list *)This;
}

inline BasicMapList BasicMapList::asBasicMapList() const {
  return BasicMapList(GetCopy());
}

inline BasicMapList BasicMapList::add(const BasicMap &el) const {
  ctx.lock();
  BasicMapList self = asBasicMapList();
  // Prepare arguments
  BasicMap _cast_el = el.asBasicMap();
  // Call isl_basic_map_list_add
  isl_basic_map_list * res =  isl_basic_map_list_add((self).Give(), (_cast_el).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_list_add returned a NULL pointer.");
  }
  return BasicMapList(res);
}

} // namespace isl
#endif //ISL_CXX_BasicMapList_IMPL_H
