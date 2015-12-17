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
  LocalSpace _cast_ls = ls.asLocalSpace();
  isl_constraint *That = isl_constraint_alloc_equality((_cast_ls).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_constraint_alloc_equality returned a NULL pointer.");
  }

  return Constraint(_ctx, That);
}

inline Constraint Constraint::allocInequality(const LocalSpace &ls) {
  const Ctx &_ctx = ls.Context();
  _ctx.lock();
  LocalSpace _cast_ls = ls.asLocalSpace();
  isl_constraint *That = isl_constraint_alloc_inequality((_cast_ls).Give());

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

inline Constraint Constraint::asConstraint() const {
  return Constraint(ctx, GetCopy());
}

inline int Constraint::dim(DimType type) const {
  ctx.lock();
  Constraint self = asConstraint();
  // Prepare arguments
  // Call isl_constraint_dim
  int res =  isl_constraint_dim((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Aff Constraint::getAff() const {
  ctx.lock();
  Constraint self = asConstraint();
  // Prepare arguments
  // Call isl_constraint_get_aff
  isl_aff * res =  isl_constraint_get_aff((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_constraint_get_aff returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Aff Constraint::getBound(DimType type, int pos) const {
  ctx.lock();
  Constraint self = asConstraint();
  // Prepare arguments
  // Call isl_constraint_get_bound
  isl_aff * res =  isl_constraint_get_bound((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_constraint_get_bound returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline Val Constraint::getCoefficientVal(DimType type, int pos) const {
  ctx.lock();
  Constraint self = asConstraint();
  // Prepare arguments
  // Call isl_constraint_get_coefficient_val
  isl_val * res =  isl_constraint_get_coefficient_val((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_constraint_get_coefficient_val returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Val Constraint::getConstantVal() const {
  ctx.lock();
  Constraint self = asConstraint();
  // Prepare arguments
  // Call isl_constraint_get_constant_val
  isl_val * res =  isl_constraint_get_constant_val((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_constraint_get_constant_val returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline std::string Constraint::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  Constraint self = asConstraint();
  // Prepare arguments
  // Call isl_constraint_get_dim_name
  const char * res =  isl_constraint_get_dim_name((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_constraint_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Aff Constraint::getDiv(int pos) const {
  ctx.lock();
  Constraint self = asConstraint();
  // Prepare arguments
  // Call isl_constraint_get_div
  isl_aff * res =  isl_constraint_get_div((self).Get(), pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_constraint_get_div returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline LocalSpace Constraint::getLocalSpace() const {
  ctx.lock();
  Constraint self = asConstraint();
  // Prepare arguments
  // Call isl_constraint_get_local_space
  isl_local_space * res =  isl_constraint_get_local_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_constraint_get_local_space returned a NULL pointer.");
  }
  return LocalSpace(ctx, res);
}

inline Space Constraint::getSpace() const {
  ctx.lock();
  Constraint self = asConstraint();
  // Prepare arguments
  // Call isl_constraint_get_space
  isl_space * res =  isl_constraint_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_constraint_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Bool Constraint::involvesDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Constraint self = asConstraint();
  // Prepare arguments
  // Call isl_constraint_involves_dims
  isl_bool res =  isl_constraint_involves_dims((self).Get(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline int Constraint::isDivConstraint() const {
  ctx.lock();
  Constraint self = asConstraint();
  // Prepare arguments
  // Call isl_constraint_is_div_constraint
  int res =  isl_constraint_is_div_constraint((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Bool Constraint::isEquality() const {
  ctx.lock();
  Constraint self = asConstraint();
  // Prepare arguments
  // Call isl_constraint_is_equality
  isl_bool res =  isl_constraint_is_equality((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Constraint::isLowerBound(DimType type, unsigned int pos) const {
  ctx.lock();
  Constraint self = asConstraint();
  // Prepare arguments
  // Call isl_constraint_is_lower_bound
  isl_bool res =  isl_constraint_is_lower_bound((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Constraint::isUpperBound(DimType type, unsigned int pos) const {
  ctx.lock();
  Constraint self = asConstraint();
  // Prepare arguments
  // Call isl_constraint_is_upper_bound
  isl_bool res =  isl_constraint_is_upper_bound((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Constraint Constraint::negate() const {
  ctx.lock();
  Constraint self = asConstraint();
  // Prepare arguments
  // Call isl_constraint_negate
  struct isl_constraint * res =  isl_constraint_negate((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_constraint_negate returned a NULL pointer.");
  }
  return Constraint(ctx, res);
}

inline Constraint Constraint::setCoefficientSi(DimType type, int pos, int v) const {
  ctx.lock();
  Constraint self = asConstraint();
  // Prepare arguments
  // Call isl_constraint_set_coefficient_si
  isl_constraint * res =  isl_constraint_set_coefficient_si((self).Give(), (enum isl_dim_type)type, pos, v);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_constraint_set_coefficient_si returned a NULL pointer.");
  }
  return Constraint(ctx, res);
}

inline Constraint Constraint::setCoefficientVal(DimType type, int pos, const Val &v) const {
  ctx.lock();
  Constraint self = asConstraint();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_constraint_set_coefficient_val
  isl_constraint * res =  isl_constraint_set_coefficient_val((self).Give(), (enum isl_dim_type)type, pos, (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_constraint_set_coefficient_val returned a NULL pointer.");
  }
  return Constraint(ctx, res);
}

inline Constraint Constraint::setConstantVal(const Val &v) const {
  ctx.lock();
  Constraint self = asConstraint();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_constraint_set_constant_val
  isl_constraint * res =  isl_constraint_set_constant_val((self).Give(), (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_constraint_set_constant_val returned a NULL pointer.");
  }
  return Constraint(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_Constraint_IMPL_H
