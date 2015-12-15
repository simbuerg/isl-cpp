#ifndef ISL_CXX_Ctx_IMPL_H
#define ISL_CXX_Ctx_IMPL_H

#include "isl/Ctx.h"

#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include <mutex>
#include <string>
#include <ostream>

#include <cassert>

namespace isl {

inline Ctx Ctx::alloc() {
  return Ctx(isl_ctx_alloc());
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_ctx *Ctx::Give() {
  isl_ctx *res = This.get()->p;
  This.get()->p = nullptr;
  This.reset();
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_ctx *Ctx::Get() const {  return (isl_ctx *)This.get()->p;
}

inline Ctx Ctx::asCtx() const {
  return *const_cast<Ctx *>(this);
}

inline int Ctx::getTileScaleTileLoops() const {
  (*this).lock();
  Ctx self = asCtx();
  // Prepare arguments
  // Call isl_options_get_tile_scale_tile_loops
  int res =  isl_options_get_tile_scale_tile_loops((self).Get());
  // Handle result argument(s)
  (*this).unlock();
  // Handle return
  return res;
}

inline int Ctx::getTileShiftPointLoops() const {
  (*this).lock();
  Ctx self = asCtx();
  // Prepare arguments
  // Call isl_options_get_tile_shift_point_loops
  int res =  isl_options_get_tile_shift_point_loops((self).Get());
  // Handle result argument(s)
  (*this).unlock();
  // Handle return
  return res;
}

inline Stat Ctx::setTileScaleTileLoops(int val) const {
  (*this).lock();
  Ctx self = asCtx();
  // Prepare arguments
  // Call isl_options_set_tile_scale_tile_loops
  isl_stat res =  isl_options_set_tile_scale_tile_loops((self).Get(), val);
  // Handle result argument(s)
  (*this).unlock();
  // Handle return
  return (Stat)res;
}

inline Stat Ctx::setTileShiftPointLoops(int val) const {
  (*this).lock();
  Ctx self = asCtx();
  // Prepare arguments
  // Call isl_options_set_tile_shift_point_loops
  isl_stat res =  isl_options_set_tile_shift_point_loops((self).Get(), val);
  // Handle result argument(s)
  (*this).unlock();
  // Handle return
  return (Stat)res;
}

} // namespace isl
#endif //ISL_CXX_Ctx_IMPL_H
