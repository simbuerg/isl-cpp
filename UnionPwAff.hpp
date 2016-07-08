#ifndef ISL_CXX_UnionPwAff_IMPL_H
#define ISL_CXX_UnionPwAff_IMPL_H

#include "isl/UnionPwAff.h"

#include "isl/PwAff.hpp"
#include "isl/Ctx.hpp"
#include "isl/IslException.h"
#include "isl/UnionPwMultiAff.hpp"
#include <string>

#include <cassert>

namespace isl {

inline isl_union_pw_aff *UnionPwAff::GetCopy() const {
  return isl_union_pw_aff_copy((isl_union_pw_aff *)This);
}
inline UnionPwAff &UnionPwAff::operator=(const UnionPwAff &Other) {
  isl_union_pw_aff *New = Other.GetCopy();
  ctx = Other.Context();
  isl_union_pw_aff_free((isl_union_pw_aff *)This);
  This = New;
  return *this;
}
inline UnionPwAff UnionPwAff::fromPwAff(const PwAff &pa) {
  const Ctx &_ctx = pa.Context();
  _ctx.lock();
  isl_union_pw_aff *That = isl_union_pw_aff_from_pw_aff((pa).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_pw_aff_from_pw_aff returned a NULL pointer.");
  }

  return UnionPwAff(_ctx, That);
}

inline UnionPwAff UnionPwAff::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_union_pw_aff *That = isl_union_pw_aff_read_from_str((ctx.Get()), str.c_str());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_pw_aff_read_from_str returned a NULL pointer.");
  }

  return UnionPwAff(_ctx, That);
}
inline UnionPwAff::~UnionPwAff() {
  isl_union_pw_aff_free((isl_union_pw_aff *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_union_pw_aff *UnionPwAff::Give() {
  isl_union_pw_aff *res = (isl_union_pw_aff *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_union_pw_aff *UnionPwAff::Get() const {  return (isl_union_pw_aff *)This;
}

inline UnionPwAff UnionPwAff::add(const UnionPwAff &upa2) const {
  ctx.lock();
  isl_union_pw_aff * res =  isl_union_pw_aff_add((*this).GetCopy(), (upa2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_aff_add returned a NULL pointer.");
  }
  return UnionPwAff(ctx, res);
}

inline UnionPwAff UnionPwAff::pullbackUnionPwMultiAff(const UnionPwMultiAff &upma) const {
  ctx.lock();
  isl_union_pw_aff * res =  isl_union_pw_aff_pullback_union_pw_multi_aff((*this).GetCopy(), (upma).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_aff_pullback_union_pw_multi_aff returned a NULL pointer.");
  }
  return UnionPwAff(ctx, res);
}

inline std::string UnionPwAff::toStr() const {
  ctx.lock();
  char * res =  isl_union_pw_aff_to_str((*this).Get());
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_union_pw_aff_to_str returned a NULL pointer.");
  }
  res_ = res;
  free((void *)res);
  return res_;
}

inline UnionPwAff UnionPwAff::unionAdd(const UnionPwAff &upa2) const {
  ctx.lock();
  isl_union_pw_aff * res =  isl_union_pw_aff_union_add((*this).GetCopy(), (upa2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_aff_union_add returned a NULL pointer.");
  }
  return UnionPwAff(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_UnionPwAff_IMPL_H
