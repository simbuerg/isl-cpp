#ifndef ISL_CXX_Band_IMPL_H
#define ISL_CXX_Band_IMPL_H

#include "isl/Band.h"

#include "isl/Printer.hpp"
#include "isl/UnionMap.hpp"
#include "isl/Vec.hpp"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_band *Band::GetCopy() const {
  return isl_band_copy((isl_band *)This);
}
inline Band &Band::operator=(const Band &Other) {
  isl_band *New = Other.GetCopy();
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
inline std::string Band::toStr(isl::Format F) const {
  Printer p = Printer::toStr(ctx);
  p = p.setOutputFormat(F);
  p = p.printBand(*this);
  return p.getStr();
}

inline Band Band::asBand() const {
  return Band(GetCopy());
}

inline UnionMap Band::getPartialSchedule() const {
  ctx.lock();
  Band self = asBand();
  // Prepare arguments
  // Call isl_band_get_partial_schedule
  isl_union_map * res =  isl_band_get_partial_schedule((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_band_get_partial_schedule returned a NULL pointer.");
  }
  return UnionMap(res);
}

inline UnionMap Band::getPrefixSchedule() const {
  ctx.lock();
  Band self = asBand();
  // Prepare arguments
  // Call isl_band_get_prefix_schedule
  isl_union_map * res =  isl_band_get_prefix_schedule((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_band_get_prefix_schedule returned a NULL pointer.");
  }
  return UnionMap(res);
}

inline UnionMap Band::getSuffixSchedule() const {
  ctx.lock();
  Band self = asBand();
  // Prepare arguments
  // Call isl_band_get_suffix_schedule
  isl_union_map * res =  isl_band_get_suffix_schedule((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_band_get_suffix_schedule returned a NULL pointer.");
  }
  return UnionMap(res);
}

inline int Band::split(int pos) const {
  ctx.lock();
  Band self = asBand();
  // Prepare arguments
  // Call isl_band_split
  int res =  isl_band_split((self).Get(), pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline int Band::tile(const Vec &sizes) const {
  ctx.lock();
  Band self = asBand();
  // Prepare arguments
  Vec _cast_sizes = sizes.asVec();
  // Call isl_band_tile
  int res =  isl_band_tile((self).Get(), (_cast_sizes).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

} // namespace isl
#endif //ISL_CXX_Band_IMPL_H
