#ifndef ISL_CXX_UnionAccessInfo_IMPL_H
#define ISL_CXX_UnionAccessInfo_IMPL_H

#include "isl/UnionAccessInfo.h"

#include "isl/Schedule.hpp"
#include "isl/UnionFlow.hpp"
#include "isl/UnionMap.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include <cassert>

namespace isl {

inline isl_union_access_info *UnionAccessInfo::GetCopy() const {
  return isl_union_access_info_copy((isl_union_access_info *)This);
}
inline UnionAccessInfo &UnionAccessInfo::operator=(const UnionAccessInfo &Other) {
  isl_union_access_info *New = Other.GetCopy();
  isl_union_access_info_free((isl_union_access_info *)This);
  This = New;
  return *this;
}
inline UnionAccessInfo UnionAccessInfo::fromSink(const UnionMap &sink) {
  const Ctx &_ctx = sink.Context();
  _ctx.lock();
  isl_union_access_info *That = isl_union_access_info_from_sink((sink).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_access_info_from_sink returned a NULL pointer.");
  }

  return UnionAccessInfo(_ctx, That);
}
inline UnionAccessInfo::~UnionAccessInfo() {
  isl_union_access_info_free((isl_union_access_info *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_union_access_info *UnionAccessInfo::Give() {
  isl_union_access_info *res = (isl_union_access_info *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_union_access_info *UnionAccessInfo::Get() const {  return (isl_union_access_info *)This;
}

inline UnionFlow UnionAccessInfo::computeFlow() const {
  ctx.lock();
  isl_union_flow * res =  isl_union_access_info_compute_flow((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_access_info_compute_flow returned a NULL pointer.");
  }
  return UnionFlow(ctx, res);
}

inline UnionAccessInfo UnionAccessInfo::setMaySource(const UnionMap &may_source) const {
  ctx.lock();
  isl_union_access_info * res =  isl_union_access_info_set_may_source((*this).GetCopy(), (may_source).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_access_info_set_may_source returned a NULL pointer.");
  }
  return UnionAccessInfo(ctx, res);
}

inline UnionAccessInfo UnionAccessInfo::setMustSource(const UnionMap &must_source) const {
  ctx.lock();
  isl_union_access_info * res =  isl_union_access_info_set_must_source((*this).GetCopy(), (must_source).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_access_info_set_must_source returned a NULL pointer.");
  }
  return UnionAccessInfo(ctx, res);
}

inline UnionAccessInfo UnionAccessInfo::setSchedule(const Schedule &schedule) const {
  ctx.lock();
  isl_union_access_info * res =  isl_union_access_info_set_schedule((*this).GetCopy(), (schedule).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_access_info_set_schedule returned a NULL pointer.");
  }
  return UnionAccessInfo(ctx, res);
}

inline UnionAccessInfo UnionAccessInfo::setScheduleMap(const UnionMap &schedule_map) const {
  ctx.lock();
  isl_union_access_info * res =  isl_union_access_info_set_schedule_map((*this).GetCopy(), (schedule_map).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_access_info_set_schedule_map returned a NULL pointer.");
  }
  return UnionAccessInfo(ctx, res);
}

inline std::string UnionAccessInfo::toStr() const {
  ctx.lock();
  char * res =  isl_union_access_info_to_str((*this).Get());
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_union_access_info_to_str returned a NULL pointer.");
  }
  res_ = res;
  free((void *)res);
  return res_;
}

} // namespace isl
#endif //ISL_CXX_UnionAccessInfo_IMPL_H
