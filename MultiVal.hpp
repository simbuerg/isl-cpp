#ifndef ISL_CXX_MultiVal_IMPL_H
#define ISL_CXX_MultiVal_IMPL_H

#include "isl/MultiVal.h"

#include "isl/Val.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_multi_val *MultiVal::GetCopy() const {
  return isl_multi_val_copy((isl_multi_val *)This);
}
inline MultiVal &MultiVal::operator=(const MultiVal &Other) {
  isl_multi_val *New = Other.GetCopy();
  isl_multi_val_free((isl_multi_val *)This);
  This = New;
  return *this;
}
inline MultiVal MultiVal::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_multi_val *That = isl_multi_val_read_from_str((ctx.Get()), str.c_str());
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_multi_val_read_from_str returned a NULL pointer.");
  }

  return MultiVal(_ctx, That);
}
inline MultiVal::~MultiVal() {
  isl_multi_val_free((isl_multi_val *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_multi_val *MultiVal::Give() {
  isl_multi_val *res = (isl_multi_val *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_multi_val *MultiVal::Get() const {  return (isl_multi_val *)This;
}

inline MultiVal MultiVal::asMultiVal() const {
  return MultiVal(ctx, GetCopy());
}

inline MultiVal MultiVal::addVal(const Val &v) const {
  ctx.lock();
  MultiVal self = asMultiVal();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_multi_val_add_val
  isl_multi_val * res =  isl_multi_val_add_val((self).Give(), (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_val_add_val returned a NULL pointer.");
  }
  return MultiVal(ctx, res);
}

inline MultiVal MultiVal::modVal(const Val &v) const {
  ctx.lock();
  MultiVal self = asMultiVal();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_multi_val_mod_val
  isl_multi_val * res =  isl_multi_val_mod_val((self).Give(), (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_multi_val_mod_val returned a NULL pointer.");
  }
  return MultiVal(ctx, res);
}

inline Bool MultiVal::plainIsEqual(const MultiVal &multi2) const {
  ctx.lock();
  MultiVal self = asMultiVal();
  // Prepare arguments
  MultiVal _cast_multi2 = multi2.asMultiVal();
  // Call isl_multi_val_plain_is_equal
  isl_bool res =  isl_multi_val_plain_is_equal((self).Get(), (_cast_multi2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

} // namespace isl
#endif //ISL_CXX_MultiVal_IMPL_H
