#ifndef ISL_CXX_UnionPwAff_IMPL_H
#define ISL_CXX_UnionPwAff_IMPL_H

#include "isl/UnionPwAff.h"

#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_union_pw_aff *UnionPwAff::GetCopy() const {
  return isl_union_pw_aff_copy((isl_union_pw_aff *)This);
}
inline UnionPwAff &UnionPwAff::operator=(const UnionPwAff &Other) {
  isl_union_pw_aff *New = Other.GetCopy();
  isl_union_pw_aff_free((isl_union_pw_aff *)This);
  This = New;
  return *this;
}inline UnionPwAff::~UnionPwAff() {
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

inline UnionPwAff UnionPwAff::asUnionPwAff() const {
  return UnionPwAff(GetCopy());
}

} // namespace isl
#endif //ISL_CXX_UnionPwAff_IMPL_H
