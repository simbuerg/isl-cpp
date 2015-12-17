#ifndef ISL_CXX_Schedule_IMPL_H
#define ISL_CXX_Schedule_IMPL_H

#include "isl/Schedule.h"

#include "isl/UnionMap.hpp"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/band.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline std::shared_ptr<isl::Schedule::ptr> Schedule::GetCopy() const {
  return Schedule::This;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_schedule *Schedule::Give() {
  isl_schedule *res = This.get()->p;
  This.get()->p = nullptr;
  This.reset();
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_schedule *Schedule::Get() const {  return (isl_schedule *)This.get()->p;
}

inline Schedule Schedule::asSchedule() const {
  return *this;
}

inline int Schedule::foreachBand(const std::function<int(isl_band *, void *)> && fn, void * user) const {
  ctx.lock();
  Schedule self = asSchedule();
  // Prepare arguments
  // Call isl_schedule_foreach_band
  int res =  isl_schedule_foreach_band((self).Get(), get_fn_ptr<18>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline UnionMap Schedule::getMap() const {
  ctx.lock();
  Schedule self = asSchedule();
  // Prepare arguments
  // Call isl_schedule_get_map
  isl_union_map * res =  isl_schedule_get_map((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_get_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_Schedule_IMPL_H
