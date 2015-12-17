#ifndef ISL_CXX_MultiPwAff_IMPL_H
#define ISL_CXX_MultiPwAff_IMPL_H

#include "isl/MultiPwAff.h"

#include "isl/Bool.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_multi_pw_aff *MultiPwAff::GetCopy() const {
  return isl_multi_pw_aff_copy((isl_multi_pw_aff *)This);
}
inline MultiPwAff &MultiPwAff::operator=(const MultiPwAff &Other) {
  isl_multi_pw_aff *New = Other.GetCopy();
  isl_multi_pw_aff_free((isl_multi_pw_aff *)This);
  This = New;
  return *this;
}inline MultiPwAff::~MultiPwAff() {
  isl_multi_pw_aff_free((isl_multi_pw_aff *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_multi_pw_aff *MultiPwAff::Give() {
  isl_multi_pw_aff *res = (isl_multi_pw_aff *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_multi_pw_aff *MultiPwAff::Get() const {  return (isl_multi_pw_aff *)This;
}

inline MultiPwAff MultiPwAff::asMultiPwAff() const {
  return MultiPwAff(ctx, GetCopy());
}

inline Bool MultiPwAff::plainIsEqual(const MultiPwAff &multi2) const {
  ctx.lock();
  MultiPwAff self = asMultiPwAff();
  // Prepare arguments
  MultiPwAff _cast_multi2 = multi2.asMultiPwAff();
  // Call isl_multi_pw_aff_plain_is_equal
  isl_bool res =  isl_multi_pw_aff_plain_is_equal((self).Get(), (_cast_multi2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

} // namespace isl
#endif //ISL_CXX_MultiPwAff_IMPL_H
