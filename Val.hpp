#ifndef ISL_CXX_Val_IMPL_H
#define ISL_CXX_Val_IMPL_H

#include "isl/Val.h"

#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/MultiVal.hpp"
#include <string>

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
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_val *That = isl_val_zero((ctx.Get()));

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_val_zero returned a NULL pointer.");
  }

  return Val(_ctx, That);
}

inline Val Val::one(const Ctx &ctx) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_val *That = isl_val_one((ctx.Get()));

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_val_one returned a NULL pointer.");
  }

  return Val(_ctx, That);
}

inline Val Val::negone(const Ctx &ctx) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_val *That = isl_val_negone((ctx.Get()));

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_val_negone returned a NULL pointer.");
  }

  return Val(_ctx, That);
}

inline Val Val::nan(const Ctx &ctx) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_val *That = isl_val_nan((ctx.Get()));

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_val_nan returned a NULL pointer.");
  }

  return Val(_ctx, That);
}

inline Val Val::infty(const Ctx &ctx) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_val *That = isl_val_infty((ctx.Get()));

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_val_infty returned a NULL pointer.");
  }

  return Val(_ctx, That);
}

inline Val Val::neginfty(const Ctx &ctx) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_val *That = isl_val_neginfty((ctx.Get()));

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_val_neginfty returned a NULL pointer.");
  }

  return Val(_ctx, That);
}

inline Val Val::intFromSi(const Ctx &ctx, long i) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_val *That = isl_val_int_from_si((ctx.Get()), i);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_val_int_from_si returned a NULL pointer.");
  }

  return Val(_ctx, That);
}

inline Val Val::intFromUi(const Ctx &ctx, unsigned long u) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_val *That = isl_val_int_from_ui((ctx.Get()), u);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_val_int_from_ui returned a NULL pointer.");
  }

  return Val(_ctx, That);
}

inline Val Val::intFromChunks(const Ctx &ctx, size_t n, size_t size, const void * chunks) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_val *That = isl_val_int_from_chunks((ctx.Get()), n, size, chunks);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_val_int_from_chunks returned a NULL pointer.");
  }

  return Val(_ctx, That);
}

inline Val Val::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_val *That = isl_val_read_from_str((ctx.Get()), str.c_str());

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

inline Val Val::abs() const {
  ctx.lock();
  isl_val * res =  isl_val_abs((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_val_abs returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Bool Val::absEq(const Val &v2) const {
  ctx.lock();
  isl_bool res =  isl_val_abs_eq((*this).Get(), (v2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Val Val::add(const Val &v2) const {
  ctx.lock();
  isl_val * res =  isl_val_add((*this).GetCopy(), (v2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_val_add returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Val Val::ceil() const {
  ctx.lock();
  isl_val * res =  isl_val_ceil((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_val_ceil returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Val Val::div(const Val &v2) const {
  ctx.lock();
  isl_val * res =  isl_val_div((*this).GetCopy(), (v2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_val_div returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Bool Val::eq(const Val &v2) const {
  ctx.lock();
  isl_bool res =  isl_val_eq((*this).Get(), (v2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Val Val::floor() const {
  ctx.lock();
  isl_val * res =  isl_val_floor((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_val_floor returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Val Val::gcd(const Val &v2) const {
  ctx.lock();
  isl_val * res =  isl_val_gcd((*this).GetCopy(), (v2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_val_gcd returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Bool Val::ge(const Val &v2) const {
  ctx.lock();
  isl_bool res =  isl_val_ge((*this).Get(), (v2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Val::gt(const Val &v2) const {
  ctx.lock();
  isl_bool res =  isl_val_gt((*this).Get(), (v2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Val::isDivisibleBy(const Val &v2) const {
  ctx.lock();
  isl_bool res =  isl_val_is_divisible_by((*this).Get(), (v2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline int Val::isInfty() const {
  ctx.lock();
  int res =  isl_val_is_infty((*this).Get());
  ctx.unlock();
  return res;
}

inline int Val::isInt() const {
  ctx.lock();
  int res =  isl_val_is_int((*this).Get());
  ctx.unlock();
  return res;
}

inline int Val::isNan() const {
  ctx.lock();
  int res =  isl_val_is_nan((*this).Get());
  ctx.unlock();
  return res;
}

inline int Val::isNeg() const {
  ctx.lock();
  int res =  isl_val_is_neg((*this).Get());
  ctx.unlock();
  return res;
}

inline int Val::isNeginfty() const {
  ctx.lock();
  int res =  isl_val_is_neginfty((*this).Get());
  ctx.unlock();
  return res;
}

inline int Val::isNegone() const {
  ctx.lock();
  int res =  isl_val_is_negone((*this).Get());
  ctx.unlock();
  return res;
}

inline int Val::isNonneg() const {
  ctx.lock();
  int res =  isl_val_is_nonneg((*this).Get());
  ctx.unlock();
  return res;
}

inline int Val::isNonpos() const {
  ctx.lock();
  int res =  isl_val_is_nonpos((*this).Get());
  ctx.unlock();
  return res;
}

inline int Val::isOne() const {
  ctx.lock();
  int res =  isl_val_is_one((*this).Get());
  ctx.unlock();
  return res;
}

inline int Val::isPos() const {
  ctx.lock();
  int res =  isl_val_is_pos((*this).Get());
  ctx.unlock();
  return res;
}

inline int Val::isRat() const {
  ctx.lock();
  int res =  isl_val_is_rat((*this).Get());
  ctx.unlock();
  return res;
}

inline int Val::isZero() const {
  ctx.lock();
  int res =  isl_val_is_zero((*this).Get());
  ctx.unlock();
  return res;
}

inline Bool Val::le(const Val &v2) const {
  ctx.lock();
  isl_bool res =  isl_val_le((*this).Get(), (v2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Val::lt(const Val &v2) const {
  ctx.lock();
  isl_bool res =  isl_val_lt((*this).Get(), (v2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Val Val::max(const Val &v2) const {
  ctx.lock();
  isl_val * res =  isl_val_max((*this).GetCopy(), (v2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_val_max returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Val Val::min(const Val &v2) const {
  ctx.lock();
  isl_val * res =  isl_val_min((*this).GetCopy(), (v2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_val_min returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Val Val::mod(const Val &v2) const {
  ctx.lock();
  isl_val * res =  isl_val_mod((*this).GetCopy(), (v2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_val_mod returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Val Val::mul(const Val &v2) const {
  ctx.lock();
  isl_val * res =  isl_val_mul((*this).GetCopy(), (v2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_val_mul returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Val Val::mulUi(unsigned long v2) const {
  ctx.lock();
  isl_val * res =  isl_val_mul_ui((*this).GetCopy(), v2);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_val_mul_ui returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Bool Val::ne(const Val &v2) const {
  ctx.lock();
  isl_bool res =  isl_val_ne((*this).Get(), (v2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Val Val::neg() const {
  ctx.lock();
  isl_val * res =  isl_val_neg((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_val_neg returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline int Val::sgn() const {
  ctx.lock();
  int res =  isl_val_sgn((*this).Get());
  ctx.unlock();
  return res;
}

inline Val Val::sub(const Val &v2) const {
  ctx.lock();
  isl_val * res =  isl_val_sub((*this).GetCopy(), (v2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_val_sub returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Val Val::trunc() const {
  ctx.lock();
  isl_val * res =  isl_val_trunc((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_val_trunc returned a NULL pointer.");
  }
  return Val(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_Val_IMPL_H
