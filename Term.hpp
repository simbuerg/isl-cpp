#ifndef ISL_CXX_Term_IMPL_H
#define ISL_CXX_Term_IMPL_H

#include "isl/Term.h"

#include "isl/Aff.hpp"
#include "isl/DimType.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_term *Term::GetCopy() const {
  return isl_term_copy((isl_term *)This);
}
inline Term &Term::operator=(const Term &Other) {
  isl_term *New = Other.GetCopy();
  isl_term_free((isl_term *)This);
  This = New;
  return *this;
}inline Term::~Term() {
  isl_term_free((isl_term *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_term *Term::Give() {
  isl_term *res = (isl_term *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_term *Term::Get() const {  return (isl_term *)This;
}


inline unsigned int Term::dim(DimType type) const {
  ctx.lock();
  unsigned int res =  isl_term_dim((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return res;
}

inline Aff Term::getDiv(unsigned int pos) const {
  ctx.lock();
  isl_aff * res =  isl_term_get_div((*this).Get(), pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_term_get_div returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline int Term::getExp(DimType type, unsigned int pos) const {
  ctx.lock();
  int res =  isl_term_get_exp((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  return res;
}

} // namespace isl
#endif //ISL_CXX_Term_IMPL_H
