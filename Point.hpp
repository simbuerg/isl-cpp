#ifndef ISL_CXX_Point_IMPL_H
#define ISL_CXX_Point_IMPL_H

#include "isl/Point.h"

#include "isl/Printer.hpp"
#include "isl/Space.hpp"
#include "isl/Val.hpp"
#include "isl/Bool.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

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
inline Point Point::zero(const Space &dim) {
  Ctx _ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_point *That = isl_point_zero((_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_point_zero returned a NULL pointer.");
  }

  return Point(_ctx, That);
}

inline Point Point::void_(const Space &dim) {
  Ctx _ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_point *That = isl_point_void((_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_point_void returned a NULL pointer.");
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
inline std::string Point::toStr(isl::Format F) const {
  Printer p = Printer::toStr(ctx);
  p = p.setOutputFormat(F);
  p = p.printPoint(*this);
  return p.getStr();
}

inline Point Point::asPoint() const {
  return Point(GetCopy());
}

inline Val Point::getCoordinateVal(DimType type, int pos) const {
  ctx.lock();
  Point self = asPoint();
  // Prepare arguments
  // Call isl_point_get_coordinate_val
  isl_val * res =  isl_point_get_coordinate_val((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_point_get_coordinate_val returned a NULL pointer.");
  }
  return Val(res);
}

inline Space Point::getSpace() const {
  ctx.lock();
  Point self = asPoint();
  // Prepare arguments
  // Call isl_point_get_space
  isl_space * res =  isl_point_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_point_get_space returned a NULL pointer.");
  }
  return Space(res);
}

inline Bool Point::isVoid() const {
  ctx.lock();
  Point self = asPoint();
  // Prepare arguments
  // Call isl_point_is_void
  isl_bool res =  isl_point_is_void((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Point Point::setCoordinateVal(DimType type, int pos, const Val &v) const {
  ctx.lock();
  Point self = asPoint();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_point_set_coordinate_val
  isl_point * res =  isl_point_set_coordinate_val((self).Give(), (enum isl_dim_type)type, pos, (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_point_set_coordinate_val returned a NULL pointer.");
  }
  return Point(res);
}

} // namespace isl
#endif //ISL_CXX_Point_IMPL_H
