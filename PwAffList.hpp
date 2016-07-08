#ifndef ISL_CXX_PwAffList_IMPL_H
#define ISL_CXX_PwAffList_IMPL_H

#include "isl/PwAffList.h"

#include "isl/PwAff.hpp"
#include "isl/Ctx.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include <cassert>

namespace isl {

inline isl_pw_aff_list *PwAffList::GetCopy() const {
  return isl_pw_aff_list_copy((isl_pw_aff_list *)This);
}
inline PwAffList &PwAffList::operator=(const PwAffList &Other) {
  isl_pw_aff_list *New = Other.GetCopy();
  ctx = Other.Context();
  isl_pw_aff_list_free((isl_pw_aff_list *)This);
  This = New;
  return *this;
}
inline PwAffList PwAffList::alloc(const Ctx &ctx, int n) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_pw_aff_list *That = isl_pw_aff_list_alloc((ctx.Get()), n);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_aff_list_alloc returned a NULL pointer.");
  }

  return PwAffList(_ctx, That);
}
inline PwAffList::~PwAffList() {
  isl_pw_aff_list_free((isl_pw_aff_list *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_pw_aff_list *PwAffList::Give() {
  isl_pw_aff_list *res = (isl_pw_aff_list *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_pw_aff_list *PwAffList::Get() const {  return (isl_pw_aff_list *)This;
}

inline PwAffList PwAffList::add(const PwAff &el) const {
  ctx.lock();
  isl_pw_aff_list * res =  isl_pw_aff_list_add((*this).GetCopy(), (el).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_list_add returned a NULL pointer.");
  }
  return PwAffList(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_PwAffList_IMPL_H
