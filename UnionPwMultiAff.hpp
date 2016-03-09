#ifndef ISL_CXX_UnionPwMultiAff_IMPL_H
#define ISL_CXX_UnionPwMultiAff_IMPL_H

#include "isl/UnionPwMultiAff.h"

#include "isl/MultiUnionPwAff.hpp"
#include "isl/PwMultiAff.hpp"
#include "isl/UnionPwAff.hpp"
#include "isl/Ctx.hpp"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include <cassert>

namespace isl {

inline isl_union_pw_multi_aff *UnionPwMultiAff::GetCopy() const {
  return isl_union_pw_multi_aff_copy((isl_union_pw_multi_aff *)This);
}
inline UnionPwMultiAff &UnionPwMultiAff::operator=(const UnionPwMultiAff &Other) {
  isl_union_pw_multi_aff *New = Other.GetCopy();
  isl_union_pw_multi_aff_free((isl_union_pw_multi_aff *)This);
  This = New;
  return *this;
}
inline UnionPwMultiAff UnionPwMultiAff::fromPwMultiAff(const PwMultiAff &pma) {
  const Ctx &_ctx = pma.Context();
  _ctx.lock();
  isl_union_pw_multi_aff *That = isl_union_pw_multi_aff_from_pw_multi_aff((pma).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_pw_multi_aff_from_pw_multi_aff returned a NULL pointer.");
  }

  return UnionPwMultiAff(_ctx, That);
}

inline UnionPwMultiAff UnionPwMultiAff::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_union_pw_multi_aff *That = isl_union_pw_multi_aff_read_from_str((ctx.Get()), str.c_str());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_pw_multi_aff_read_from_str returned a NULL pointer.");
  }

  return UnionPwMultiAff(_ctx, That);
}

inline UnionPwMultiAff UnionPwMultiAff::fromUnionPwAff(const UnionPwAff &upa) {
  const Ctx &_ctx = upa.Context();
  _ctx.lock();
  isl_union_pw_multi_aff *That = isl_union_pw_multi_aff_from_union_pw_aff((upa).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_pw_multi_aff_from_union_pw_aff returned a NULL pointer.");
  }

  return UnionPwMultiAff(_ctx, That);
}

inline UnionPwMultiAff UnionPwMultiAff::fromMultiUnionPwAff(const MultiUnionPwAff &mupa) {
  const Ctx &_ctx = mupa.Context();
  _ctx.lock();
  isl_union_pw_multi_aff *That = isl_union_pw_multi_aff_from_multi_union_pw_aff((mupa).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_pw_multi_aff_from_multi_union_pw_aff returned a NULL pointer.");
  }

  return UnionPwMultiAff(_ctx, That);
}
inline UnionPwMultiAff::~UnionPwMultiAff() {
  isl_union_pw_multi_aff_free((isl_union_pw_multi_aff *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_union_pw_multi_aff *UnionPwMultiAff::Give() {
  isl_union_pw_multi_aff *res = (isl_union_pw_multi_aff *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_union_pw_multi_aff *UnionPwMultiAff::Get() const {  return (isl_union_pw_multi_aff *)This;
}

inline UnionPwMultiAff UnionPwMultiAff::add(const UnionPwMultiAff &upma2) const {
  ctx.lock();
  isl_union_pw_multi_aff * res =  isl_union_pw_multi_aff_add((*this).GetCopy(), (upma2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_multi_aff_add returned a NULL pointer.");
  }
  return UnionPwMultiAff(ctx, res);
}

inline UnionPwMultiAff UnionPwMultiAff::flatRangeProduct(const UnionPwMultiAff &upma2) const {
  ctx.lock();
  isl_union_pw_multi_aff * res =  isl_union_pw_multi_aff_flat_range_product((*this).GetCopy(), (upma2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_multi_aff_flat_range_product returned a NULL pointer.");
  }
  return UnionPwMultiAff(ctx, res);
}

inline UnionPwMultiAff UnionPwMultiAff::pullbackUnionPwMultiAff(const UnionPwMultiAff &upma2) const {
  ctx.lock();
  isl_union_pw_multi_aff * res =  isl_union_pw_multi_aff_pullback_union_pw_multi_aff((*this).GetCopy(), (upma2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_multi_aff_pullback_union_pw_multi_aff returned a NULL pointer.");
  }
  return UnionPwMultiAff(ctx, res);
}

inline UnionPwMultiAff UnionPwMultiAff::unionAdd(const UnionPwMultiAff &upma2) const {
  ctx.lock();
  isl_union_pw_multi_aff * res =  isl_union_pw_multi_aff_union_add((*this).GetCopy(), (upma2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_multi_aff_union_add returned a NULL pointer.");
  }
  return UnionPwMultiAff(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_UnionPwMultiAff_IMPL_H
