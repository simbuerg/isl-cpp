#ifndef ISL_CXX_UnionFlow_IMPL_H
#define ISL_CXX_UnionFlow_IMPL_H

#include "isl/UnionFlow.h"

#include "isl/UnionMap.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include <cassert>

namespace isl {

inline isl_union_flow *UnionFlow::GetCopy() const {
  return isl_union_flow_copy((isl_union_flow *)This);
}
inline UnionFlow &UnionFlow::operator=(const UnionFlow &Other) {
  isl_union_flow *New = Other.GetCopy();
  isl_union_flow_free((isl_union_flow *)This);
  This = New;
  return *this;
}inline UnionFlow::~UnionFlow() {
  isl_union_flow_free((isl_union_flow *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_union_flow *UnionFlow::Give() {
  isl_union_flow *res = (isl_union_flow *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_union_flow *UnionFlow::Get() const {  return (isl_union_flow *)This;
}

inline UnionMap UnionFlow::getFullMayDependence() const {
  ctx.lock();
  isl_union_map * res =  isl_union_flow_get_full_may_dependence((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_flow_get_full_may_dependence returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionFlow::getFullMustDependence() const {
  ctx.lock();
  isl_union_map * res =  isl_union_flow_get_full_must_dependence((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_flow_get_full_must_dependence returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionFlow::getMayDependence() const {
  ctx.lock();
  isl_union_map * res =  isl_union_flow_get_may_dependence((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_flow_get_may_dependence returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionFlow::getMayNoSource() const {
  ctx.lock();
  isl_union_map * res =  isl_union_flow_get_may_no_source((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_flow_get_may_no_source returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionFlow::getMustDependence() const {
  ctx.lock();
  isl_union_map * res =  isl_union_flow_get_must_dependence((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_flow_get_must_dependence returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionFlow::getMustNoSource() const {
  ctx.lock();
  isl_union_map * res =  isl_union_flow_get_must_no_source((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_flow_get_must_no_source returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_UnionFlow_IMPL_H
