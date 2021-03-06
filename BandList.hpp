#ifndef ISL_CXX_BandList_IMPL_H
#define ISL_CXX_BandList_IMPL_H

#include "isl/BandList.h"

#include "isl/Band.hpp"
#include "isl/Ctx.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/band.h"
#include <string>

#include <cassert>

namespace isl {

inline isl_band_list *BandList::GetCopy() const {
  return isl_band_list_copy((isl_band_list *)This);
}
inline BandList &BandList::operator=(const BandList &Other) {
  isl_band_list *New = Other.GetCopy();
  ctx = Other.Context();
  isl_band_list_free((isl_band_list *)This);
  This = New;
  return *this;
}
inline BandList BandList::alloc(const Ctx &ctx, int n) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_band_list *That = isl_band_list_alloc((ctx.Get()), n);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_band_list_alloc returned a NULL pointer.");
  }

  return BandList(_ctx, That);
}
inline BandList::~BandList() {
  isl_band_list_free((isl_band_list *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_band_list *BandList::Give() {
  isl_band_list *res = (isl_band_list *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_band_list *BandList::Get() const {  return (isl_band_list *)This;
}

inline BandList BandList::add(const Band &el) const {
  ctx.lock();
  isl_band_list * res =  isl_band_list_add((*this).GetCopy(), (el).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_band_list_add returned a NULL pointer.");
  }
  return BandList(ctx, res);
}

inline int BandList::foreachBand(const std::function<int(isl_band *, void *)> && fn, void * user) const {
  ctx.lock();
  int res =  isl_band_list_foreach_band((*this).Get(), get_fn_ptr<0>(fn), user);
  ctx.unlock();
  return res;
}

} // namespace isl
#endif //ISL_CXX_BandList_IMPL_H
