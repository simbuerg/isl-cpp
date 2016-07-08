#ifndef ISL_CXX_IdList_IMPL_H
#define ISL_CXX_IdList_IMPL_H

#include "isl/IdList.h"

#include "isl/Id.hpp"
#include "isl/Ctx.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include <cassert>

namespace isl {

inline isl_id_list *IdList::GetCopy() const {
  return isl_id_list_copy((isl_id_list *)This);
}
inline IdList &IdList::operator=(const IdList &Other) {
  isl_id_list *New = Other.GetCopy();
  ctx = Other.Context();
  isl_id_list_free((isl_id_list *)This);
  This = New;
  return *this;
}
inline IdList IdList::alloc(const Ctx &ctx, int n) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_id_list *That = isl_id_list_alloc((ctx.Get()), n);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_id_list_alloc returned a NULL pointer.");
  }

  return IdList(_ctx, That);
}
inline IdList::~IdList() {
  isl_id_list_free((isl_id_list *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_id_list *IdList::Give() {
  isl_id_list *res = (isl_id_list *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_id_list *IdList::Get() const {  return (isl_id_list *)This;
}

inline IdList IdList::add(const Id &el) const {
  ctx.lock();
  isl_id_list * res =  isl_id_list_add((*this).GetCopy(), (el).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_id_list_add returned a NULL pointer.");
  }
  return IdList(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_IdList_IMPL_H
