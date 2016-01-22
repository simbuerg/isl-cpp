#ifndef ISL_CXX_AffList_IMPL_H
#define ISL_CXX_AffList_IMPL_H

#include "isl/AffList.h"

#include "isl/Aff.hpp"
#include "isl/Ctx.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_aff_list *AffList::GetCopy() const {
  return isl_aff_list_copy((isl_aff_list *)This);
}
inline AffList &AffList::operator=(const AffList &Other) {
  isl_aff_list *New = Other.GetCopy();
  isl_aff_list_free((isl_aff_list *)This);
  This = New;
  return *this;
}
inline AffList AffList::alloc(const Ctx &ctx, int n) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_aff_list *That = isl_aff_list_alloc((ctx.Get()), n);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_aff_list_alloc returned a NULL pointer.");
  }

  return AffList(_ctx, That);
}
inline AffList::~AffList() {
  isl_aff_list_free((isl_aff_list *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_aff_list *AffList::Give() {
  isl_aff_list *res = (isl_aff_list *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_aff_list *AffList::Get() const {  return (isl_aff_list *)This;
}


inline AffList AffList::add(const Aff &el) const {
  ctx.lock();
  isl_aff_list * res =  isl_aff_list_add((*this).GetCopy(), (el).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_aff_list_add returned a NULL pointer.");
  }
  return AffList(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_AffList_IMPL_H
