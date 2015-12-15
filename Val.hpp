#ifndef ISL_CXX_Val_IMPL_H
#define ISL_CXX_Val_IMPL_H

#include "isl/Val.h"

#include "isl/Printer.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/MultiVal.hpp"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_val *Val::GetCopy() const {
  return isl_val_copy((isl_val *)This);
}
inline Val &Val::operator=(const Val &Other) {
  isl_val *New = Other.GetCopy();
  isl_val_free((isl_val *)This);
  This = New;
  return *this;
}
inline Val Val::zero(const Ctx &ctx) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_val *That = isl_val_zero((ctx.Get()));
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_val_zero returned a NULL pointer.");
  }

  return Val(_ctx, That);
}

inline Val Val::one(const Ctx &ctx) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_val *That = isl_val_one((ctx.Get()));
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_val_one returned a NULL pointer.");
  }

  return Val(_ctx, That);
}

inline Val Val::negone(const Ctx &ctx) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_val *That = isl_val_negone((ctx.Get()));
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_val_negone returned a NULL pointer.");
  }

  return Val(_ctx, That);
}

inline Val Val::nan(const Ctx &ctx) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_val *That = isl_val_nan((ctx.Get()));
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_val_nan returned a NULL pointer.");
  }

  return Val(_ctx, That);
}

inline Val Val::infty(const Ctx &ctx) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_val *That = isl_val_infty((ctx.Get()));
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_val_infty returned a NULL pointer.");
  }

  return Val(_ctx, That);
}

inline Val Val::neginfty(const Ctx &ctx) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_val *That = isl_val_neginfty((ctx.Get()));
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_val_neginfty returned a NULL pointer.");
  }

  return Val(_ctx, That);
}

inline Val Val::readFromStr(const Ctx &ctx, std::string str) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_val *That = isl_val_read_from_str((ctx.Get()), str.c_str());
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_val_read_from_str returned a NULL pointer.");
  }

  return Val(_ctx, That);
}
inline Val::~Val() {
  isl_val_free((isl_val *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_val *Val::Give() {
  isl_val *res = (isl_val *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_val *Val::Get() const {  return (isl_val *)This;
}
inline std::string Val::toStr(isl::Format F) const {
  Printer p = Printer::toStr(ctx);
  p = p.setOutputFormat(F);
  p = p.printVal(*this);
  return p.getStr();
}

inline Val Val::asVal() const {
  return Val(GetCopy());
}

inline MultiVal Val::asMultiVal() const {
  return MultiVal(*this);
}

inline Val Val::abs() const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_abs
  isl_val * res =  isl_val_abs((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_val_abs returned a NULL pointer.");
  }
  return Val(res);
}

inline Bool Val::absEq(const Val &v2) const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  Val _cast_v2 = v2.asVal();
  // Call isl_val_abs_eq
  isl_bool res =  isl_val_abs_eq((self).Get(), (_cast_v2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Val Val::add(const Val &v2) const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  Val _cast_v2 = v2.asVal();
  // Call isl_val_add
  isl_val * res =  isl_val_add((self).Give(), (_cast_v2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_val_add returned a NULL pointer.");
  }
  return Val(res);
}

inline Val Val::ceil() const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_ceil
  isl_val * res =  isl_val_ceil((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_val_ceil returned a NULL pointer.");
  }
  return Val(res);
}

inline Val Val::div(const Val &v2) const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  Val _cast_v2 = v2.asVal();
  // Call isl_val_div
  isl_val * res =  isl_val_div((self).Give(), (_cast_v2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_val_div returned a NULL pointer.");
  }
  return Val(res);
}

inline Bool Val::eq(const Val &v2) const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  Val _cast_v2 = v2.asVal();
  // Call isl_val_eq
  isl_bool res =  isl_val_eq((self).Get(), (_cast_v2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Val Val::floor() const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_floor
  isl_val * res =  isl_val_floor((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_val_floor returned a NULL pointer.");
  }
  return Val(res);
}

inline Val Val::gcd(const Val &v2) const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  Val _cast_v2 = v2.asVal();
  // Call isl_val_gcd
  isl_val * res =  isl_val_gcd((self).Give(), (_cast_v2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_val_gcd returned a NULL pointer.");
  }
  return Val(res);
}

inline Bool Val::ge(const Val &v2) const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  Val _cast_v2 = v2.asVal();
  // Call isl_val_ge
  isl_bool res =  isl_val_ge((self).Get(), (_cast_v2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Val::gt(const Val &v2) const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  Val _cast_v2 = v2.asVal();
  // Call isl_val_gt
  isl_bool res =  isl_val_gt((self).Get(), (_cast_v2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Val::isDivisibleBy(const Val &v2) const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  Val _cast_v2 = v2.asVal();
  // Call isl_val_is_divisible_by
  isl_bool res =  isl_val_is_divisible_by((self).Get(), (_cast_v2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline int Val::isInfty() const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_is_infty
  int res =  isl_val_is_infty((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline int Val::isInt() const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_is_int
  int res =  isl_val_is_int((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline int Val::isNan() const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_is_nan
  int res =  isl_val_is_nan((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline int Val::isNeg() const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_is_neg
  int res =  isl_val_is_neg((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline int Val::isNeginfty() const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_is_neginfty
  int res =  isl_val_is_neginfty((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline int Val::isNegone() const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_is_negone
  int res =  isl_val_is_negone((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline int Val::isNonneg() const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_is_nonneg
  int res =  isl_val_is_nonneg((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline int Val::isNonpos() const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_is_nonpos
  int res =  isl_val_is_nonpos((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline int Val::isOne() const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_is_one
  int res =  isl_val_is_one((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline int Val::isPos() const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_is_pos
  int res =  isl_val_is_pos((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline int Val::isRat() const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_is_rat
  int res =  isl_val_is_rat((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline int Val::isZero() const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_is_zero
  int res =  isl_val_is_zero((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Bool Val::le(const Val &v2) const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  Val _cast_v2 = v2.asVal();
  // Call isl_val_le
  isl_bool res =  isl_val_le((self).Get(), (_cast_v2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Val::lt(const Val &v2) const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  Val _cast_v2 = v2.asVal();
  // Call isl_val_lt
  isl_bool res =  isl_val_lt((self).Get(), (_cast_v2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Val Val::max(const Val &v2) const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  Val _cast_v2 = v2.asVal();
  // Call isl_val_max
  isl_val * res =  isl_val_max((self).Give(), (_cast_v2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_val_max returned a NULL pointer.");
  }
  return Val(res);
}

inline Val Val::min(const Val &v2) const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  Val _cast_v2 = v2.asVal();
  // Call isl_val_min
  isl_val * res =  isl_val_min((self).Give(), (_cast_v2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_val_min returned a NULL pointer.");
  }
  return Val(res);
}

inline Val Val::mod(const Val &v2) const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  Val _cast_v2 = v2.asVal();
  // Call isl_val_mod
  isl_val * res =  isl_val_mod((self).Give(), (_cast_v2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_val_mod returned a NULL pointer.");
  }
  return Val(res);
}

inline Val Val::mul(const Val &v2) const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  Val _cast_v2 = v2.asVal();
  // Call isl_val_mul
  isl_val * res =  isl_val_mul((self).Give(), (_cast_v2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_val_mul returned a NULL pointer.");
  }
  return Val(res);
}

inline Val Val::mulUi(unsigned long v2) const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_mul_ui
  isl_val * res =  isl_val_mul_ui((self).Give(), v2);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_val_mul_ui returned a NULL pointer.");
  }
  return Val(res);
}

inline Bool Val::ne(const Val &v2) const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  Val _cast_v2 = v2.asVal();
  // Call isl_val_ne
  isl_bool res =  isl_val_ne((self).Get(), (_cast_v2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Val Val::neg() const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_neg
  isl_val * res =  isl_val_neg((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_val_neg returned a NULL pointer.");
  }
  return Val(res);
}

inline int Val::sgn() const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_sgn
  int res =  isl_val_sgn((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Val Val::sub(const Val &v2) const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  Val _cast_v2 = v2.asVal();
  // Call isl_val_sub
  isl_val * res =  isl_val_sub((self).Give(), (_cast_v2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_val_sub returned a NULL pointer.");
  }
  return Val(res);
}

inline Val Val::trunc() const {
  ctx.lock();
  Val self = asVal();
  // Prepare arguments
  // Call isl_val_trunc
  isl_val * res =  isl_val_trunc((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_val_trunc returned a NULL pointer.");
  }
  return Val(res);
}

} // namespace isl
#endif //ISL_CXX_Val_IMPL_H
