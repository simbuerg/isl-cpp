#ifndef ISL_CXX_Point_IMPL_H
#define ISL_CXX_Point_IMPL_H

#include "isl/Point.h"

#include "isl/Space.hpp"
#include "isl/Val.hpp"
#include "isl/BasicSet.hpp"
#include "isl/Bool.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include <string>

#include <cassert>

namespace isl {

inline isl_point *Point::GetCopy() const {
  return isl_point_copy((isl_point *)This);
}
inline Point &Point::operator=(const Point &Other) {
  isl_point *New = Other.GetCopy();
  isl_point_free((isl_point *)This);
  This = New;
  return *this;
}
inline Point Point::void_(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_point *That = isl_point_void((dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_point_void returned a NULL pointer.");
  }

  return Point(_ctx, That);
}

inline Point Point::zero(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_point *That = isl_point_zero((dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_point_zero returned a NULL pointer.");
  }

  return Point(_ctx, That);
}
inline Point::~Point() {
  isl_point_free((isl_point *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_point *Point::Give() {
  isl_point *res = (isl_point *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_point *Point::Get() const {  return (isl_point *)This;
}

inline Point Point::addUi(DimType type, int pos, unsigned int val) const {
  ctx.lock();
  isl_point * res =  isl_point_add_ui((*this).GetCopy(), (enum isl_dim_type)type, pos, val);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_point_add_ui returned a NULL pointer.");
  }
  return Point(ctx, res);
}

inline void Point::dump() const {
  ctx.lock();
   isl_point_dump((*this).Get());
  ctx.unlock();
}

inline Val Point::getCoordinateVal(DimType type, int pos) const {
  ctx.lock();
  isl_val * res =  isl_point_get_coordinate_val((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_point_get_coordinate_val returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Space Point::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_point_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_point_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Bool Point::isVoid() const {
  ctx.lock();
  isl_bool res =  isl_point_is_void((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Point Point::setCoordinateVal(DimType type, int pos, const Val &v) const {
  ctx.lock();
  isl_point * res =  isl_point_set_coordinate_val((*this).GetCopy(), (enum isl_dim_type)type, pos, (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_point_set_coordinate_val returned a NULL pointer.");
  }
  return Point(ctx, res);
}

inline Point Point::subUi(DimType type, int pos, unsigned int val) const {
  ctx.lock();
  isl_point * res =  isl_point_sub_ui((*this).GetCopy(), (enum isl_dim_type)type, pos, val);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_point_sub_ui returned a NULL pointer.");
  }
  return Point(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_Point_IMPL_H
