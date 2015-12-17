#ifndef ISL_CXX_UnionPwMultiAff_IMPL_H
#define ISL_CXX_UnionPwMultiAff_IMPL_H

#include "isl/UnionPwMultiAff.h"

#include "isl/MultiUnionPwAff.hpp"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

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
inline UnionPwMultiAff UnionPwMultiAff::fromMultiUnionPwAff(const MultiUnionPwAff &mupa) {
  const Ctx &_ctx = mupa.Context();
  _ctx.lock();
  MultiUnionPwAff _cast_mupa = mupa.asMultiUnionPwAff();
  isl_union_pw_multi_aff *That = isl_union_pw_multi_aff_from_multi_union_pw_aff((_cast_mupa).Give());

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

inline UnionPwMultiAff UnionPwMultiAff::asUnionPwMultiAff() const {
  return UnionPwMultiAff(ctx, GetCopy());
}

} // namespace isl
#endif //ISL_CXX_UnionPwMultiAff_IMPL_H
