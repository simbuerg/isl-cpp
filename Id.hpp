#ifndef ISL_CXX_Id_IMPL_H
#define ISL_CXX_Id_IMPL_H

#include "isl/Id.h"

#include "isl/Ctx.hpp"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_id *Id::GetCopy() const {
  return isl_id_copy((isl_id *)This);
}
inline Id &Id::operator=(const Id &Other) {
  isl_id *New = Other.GetCopy();
  isl_id_free((isl_id *)This);
  This = New;
  return *this;
}
inline Id Id::alloc(const Ctx &ctx, std::string name, void * user) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_id *That = isl_id_alloc((ctx.Get()), name.c_str(), user);
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_id_alloc returned a NULL pointer.");
  }

  return Id(_ctx, That);
}
inline Id::~Id() {
  isl_id_free((isl_id *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_id *Id::Give() {
  isl_id *res = (isl_id *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_id *Id::Get() const {  return (isl_id *)This;
}

inline Id Id::asId() const {
  return Id(ctx, GetCopy());
}

inline std::string Id::getName() const {
  ctx.lock();
  Id self = asId();
  // Prepare arguments
  // Call isl_id_get_name
  const char * res =  isl_id_get_name((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_id_get_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

} // namespace isl
#endif //ISL_CXX_Id_IMPL_H
