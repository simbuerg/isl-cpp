#ifndef ISL_CXX_Schedule_IMPL_H
#define ISL_CXX_Schedule_IMPL_H

#include "isl/Schedule.h"

#include "isl/ScheduleNode.hpp"
#include "isl/UnionMap.hpp"
#include "isl/UnionPwMultiAff.hpp"
#include "isl/Ctx.hpp"
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

inline Schedule Schedule::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_schedule *That = isl_schedule_read_from_str((ctx.Get()), str.c_str());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_schedule_read_from_str returned a NULL pointer.");
  }

  return Schedule(_ctx, That);
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


inline int Schedule::foreachBand(const std::function<int(isl_band *, void *)> && fn, void * user) const {
  ctx.lock();
  int res =  isl_schedule_foreach_band((*this).Get(), get_fn_ptr<14>(fn), user);
  ctx.unlock();
  return res;
}

inline UnionMap Schedule::getMap() const {
  ctx.lock();
  isl_union_map * res =  isl_schedule_get_map((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_get_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline ScheduleNode Schedule::getRoot() const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_get_root((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_get_root returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline Schedule Schedule::pullbackUnionPwMultiAff(const UnionPwMultiAff &upma) const {
  ctx.lock();
  isl_schedule * res =  isl_schedule_pullback_union_pw_multi_aff((*this).Get(), (upma).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_pullback_union_pw_multi_aff returned a NULL pointer.");
  }
  return Schedule(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_Schedule_IMPL_H
