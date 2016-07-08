#ifndef ISL_CXX_Band_IMPL_H
#define ISL_CXX_Band_IMPL_H

#include "isl/Band.h"

#include "isl/UnionMap.hpp"
#include "isl/Vec.hpp"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include <cassert>

namespace isl {

inline isl_band *Band::GetCopy() const {
  return isl_band_copy((isl_band *)This);
}
inline Band &Band::operator=(const Band &Other) {
  isl_band *New = Other.GetCopy();
  ctx = Other.Context();
  isl_band_free((isl_band *)This);
  This = New;
  return *this;
}/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_band *Band::Give() {
  isl_band *res = (isl_band *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_band *Band::Get() const {  return (isl_band *)This;
}

inline UnionMap Band::getPartialSchedule() const {
  ctx.lock();
  isl_union_map * res =  isl_band_get_partial_schedule((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_band_get_partial_schedule returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap Band::getPrefixSchedule() const {
  ctx.lock();
  isl_union_map * res =  isl_band_get_prefix_schedule((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_band_get_prefix_schedule returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap Band::getSuffixSchedule() const {
  ctx.lock();
  isl_union_map * res =  isl_band_get_suffix_schedule((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_band_get_suffix_schedule returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline int Band::split(int pos) const {
  ctx.lock();
  int res =  isl_band_split((*this).Get(), pos);
  ctx.unlock();
  return res;
}

inline int Band::tile(const Vec &sizes) const {
  ctx.lock();
  int res =  isl_band_tile((*this).Get(), (sizes).GetCopy());
  ctx.unlock();
  return res;
}

} // namespace isl
#endif //ISL_CXX_Band_IMPL_H
