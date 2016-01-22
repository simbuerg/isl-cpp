#ifndef ISL_CXX_Constraint_IMPL_H
#define ISL_CXX_Constraint_IMPL_H

#include "isl/Constraint.h"

#include "isl/Aff.hpp"
#include "isl/LocalSpace.hpp"
#include "isl/Space.hpp"
#include "isl/Val.hpp"
#include "isl/Bool.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_constraint *Constraint::GetCopy() const {
  return isl_constraint_copy((isl_constraint *)This);
}
inline Constraint &Constraint::operator=(const Constraint &Other) {
  isl_constraint *New = Other.GetCopy();
  isl_constraint_free((isl_constraint *)This);
  This = New;
  return *this;
}
inline Constraint Constraint::allocEquality(const LocalSpace &ls) {
  const Ctx &_ctx = ls.Context();
  _ctx.lock();
  isl_constraint *That = isl_constraint_alloc_equality((ls).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_constraint_alloc_equality returned a NULL pointer.");
  }

  return Constraint(_ctx, That);
}

inline Constraint Constraint::allocInequality(const LocalSpace &ls) {
  const Ctx &_ctx = ls.Context();
  _ctx.lock();
  isl_constraint *That = isl_constraint_alloc_inequality((ls).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_constraint_alloc_inequality returned a NULL pointer.");
  }

  return Constraint(_ctx, That);
}
inline Constraint::~Constraint() {
  isl_constraint_free((isl_constraint *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_constraint *Constraint::Give() {
  isl_constraint *res = (isl_constraint *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_constraint *Constraint::Get() const {  return (isl_constraint *)This;
}


inline int Constraint::dim(DimType type) const {
  ctx.lock();
  int res =  isl_constraint_dim((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return res;
}

inline Aff Constraint::getAff() const {
  ctx.lock();
  isl_aff * res =  isl_constraint_get_aff((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_constraint_get_aff returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Constraint::getBound(DimType type, int pos) const {
  ctx.lock();
  isl_aff * res =  isl_constraint_get_bound((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_constraint_get_bound returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Val Constraint::getCoefficientVal(DimType type, int pos) const {
  ctx.lock();
  isl_val * res =  isl_constraint_get_coefficient_val((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_constraint_get_coefficient_val returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Val Constraint::getConstantVal() const {
  ctx.lock();
  isl_val * res =  isl_constraint_get_constant_val((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_constraint_get_constant_val returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline std::string Constraint::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  const char * res =  isl_constraint_get_dim_name((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_constraint_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Aff Constraint::getDiv(int pos) const {
  ctx.lock();
  isl_aff * res =  isl_constraint_get_div((*this).Get(), pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_constraint_get_div returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline LocalSpace Constraint::getLocalSpace() const {
  ctx.lock();
  isl_local_space * res =  isl_constraint_get_local_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_constraint_get_local_space returned a NULL pointer.");
  }
  return LocalSpace(ctx, res);
}

inline Space Constraint::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_constraint_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_constraint_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Bool Constraint::involvesDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_bool res =  isl_constraint_involves_dims((*this).Get(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  return (Bool)res;
}

inline int Constraint::isDivConstraint() const {
  ctx.lock();
  int res =  isl_constraint_is_div_constraint((*this).Get());
  ctx.unlock();
  return res;
}

inline Bool Constraint::isEquality() const {
  ctx.lock();
  isl_bool res =  isl_constraint_is_equality((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Constraint::isLowerBound(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_bool res =  isl_constraint_is_lower_bound((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  return (Bool)res;
}

inline Bool Constraint::isUpperBound(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_bool res =  isl_constraint_is_upper_bound((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  return (Bool)res;
}

inline Constraint Constraint::negate() const {
  ctx.lock();
  struct isl_constraint * res =  isl_constraint_negate((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_constraint_negate returned a NULL pointer.");
  }
  return Constraint(ctx, res);
}

inline Constraint Constraint::setCoefficientSi(DimType type, int pos, int v) const {
  ctx.lock();
  isl_constraint * res =  isl_constraint_set_coefficient_si((*this).GetCopy(), (enum isl_dim_type)type, pos, v);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_constraint_set_coefficient_si returned a NULL pointer.");
  }
  return Constraint(ctx, res);
}

inline Constraint Constraint::setCoefficientVal(DimType type, int pos, const Val &v) const {
  ctx.lock();
  isl_constraint * res =  isl_constraint_set_coefficient_val((*this).GetCopy(), (enum isl_dim_type)type, pos, (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_constraint_set_coefficient_val returned a NULL pointer.");
  }
  return Constraint(ctx, res);
}

inline Constraint Constraint::setConstantVal(const Val &v) const {
  ctx.lock();
  isl_constraint * res =  isl_constraint_set_constant_val((*this).GetCopy(), (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_constraint_set_constant_val returned a NULL pointer.");
  }
  return Constraint(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_Constraint_IMPL_H
