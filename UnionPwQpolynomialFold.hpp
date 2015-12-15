#ifndef ISL_CXX_UnionPwQpolynomialFold_IMPL_H
#define ISL_CXX_UnionPwQpolynomialFold_IMPL_H

#include "isl/UnionPwQpolynomialFold.h"

#include "isl/Point.hpp"
#include "isl/Printer.hpp"
#include "isl/PwQpolynomialFold.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/UnionPwQpolynomial.hpp"
#include "isl/UnionSet.hpp"
#include "isl/Val.hpp"
#include "isl/Bool.h"
#include "isl/Fold.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/polynomial.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_union_pw_qpolynomial_fold *UnionPwQpolynomialFold::GetCopy() const {
  return isl_union_pw_qpolynomial_fold_copy((isl_union_pw_qpolynomial_fold *)This);
}
inline UnionPwQpolynomialFold &UnionPwQpolynomialFold::operator=(const UnionPwQpolynomialFold &Other) {
  isl_union_pw_qpolynomial_fold *New = Other.GetCopy();
  isl_union_pw_qpolynomial_fold_free((isl_union_pw_qpolynomial_fold *)This);
  This = New;
  return *this;
}
inline UnionPwQpolynomialFold UnionPwQpolynomialFold::fromPwQpolynomialFold(const PwQpolynomialFold &pwf) {
  Ctx _ctx = pwf.Context();
  _ctx.lock();
  PwQpolynomialFold _cast_pwf = pwf.asPwQpolynomialFold();
  isl_union_pw_qpolynomial_fold *That = isl_union_pw_qpolynomial_fold_from_pw_qpolynomial_fold((_cast_pwf).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_from_pw_qpolynomial_fold returned a NULL pointer.");
  }

  return UnionPwQpolynomialFold(_ctx, That);
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::zero(const Space &dim, Fold type) {
  Ctx _ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_union_pw_qpolynomial_fold *That = isl_union_pw_qpolynomial_fold_zero((_cast_dim).Give(), (enum isl_fold)type);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_zero returned a NULL pointer.");
  }

  return UnionPwQpolynomialFold(_ctx, That);
}
inline UnionPwQpolynomialFold::~UnionPwQpolynomialFold() {
  isl_union_pw_qpolynomial_fold_free((isl_union_pw_qpolynomial_fold *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_union_pw_qpolynomial_fold *UnionPwQpolynomialFold::Give() {
  isl_union_pw_qpolynomial_fold *res = (isl_union_pw_qpolynomial_fold *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_union_pw_qpolynomial_fold *UnionPwQpolynomialFold::Get() const {  return (isl_union_pw_qpolynomial_fold *)This;
}
inline std::string UnionPwQpolynomialFold::toStr(isl::Format F) const {
  Printer p = Printer::toStr(ctx);
  p = p.setOutputFormat(F);
  p = p.printUnionPwQpolynomialFold(*this);
  return p.getStr();
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::asUnionPwQpolynomialFold() const {
  return UnionPwQpolynomialFold(GetCopy());
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::addUnionPwQpolynomial(const UnionPwQpolynomial &upwqp) const {
  ctx.lock();
  UnionPwQpolynomialFold self = asUnionPwQpolynomialFold();
  // Prepare arguments
  UnionPwQpolynomial _cast_upwqp = upwqp.asUnionPwQpolynomial();
  // Call isl_union_pw_qpolynomial_fold_add_union_pw_qpolynomial
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_add_union_pw_qpolynomial((self).Give(), (_cast_upwqp).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_add_union_pw_qpolynomial returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(res);
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::alignParams(const Space &model) const {
  ctx.lock();
  UnionPwQpolynomialFold self = asUnionPwQpolynomialFold();
  // Prepare arguments
  Space _cast_model = model.asSpace();
  // Call isl_union_pw_qpolynomial_fold_align_params
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_align_params((self).Give(), (_cast_model).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_align_params returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(res);
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::coalesce() const {
  ctx.lock();
  UnionPwQpolynomialFold self = asUnionPwQpolynomialFold();
  // Prepare arguments
  // Call isl_union_pw_qpolynomial_fold_coalesce
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_coalesce((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_coalesce returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(res);
}

inline UnionSet UnionPwQpolynomialFold::domain() const {
  ctx.lock();
  UnionPwQpolynomialFold self = asUnionPwQpolynomialFold();
  // Prepare arguments
  // Call isl_union_pw_qpolynomial_fold_domain
  isl_union_set * res =  isl_union_pw_qpolynomial_fold_domain((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_domain returned a NULL pointer.");
  }
  return UnionSet(res);
}

inline Val UnionPwQpolynomialFold::eval(const Point &pnt) const {
  ctx.lock();
  UnionPwQpolynomialFold self = asUnionPwQpolynomialFold();
  // Prepare arguments
  Point _cast_pnt = pnt.asPoint();
  // Call isl_union_pw_qpolynomial_fold_eval
  isl_val * res =  isl_union_pw_qpolynomial_fold_eval((self).Give(), (_cast_pnt).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_eval returned a NULL pointer.");
  }
  return Val(res);
}

inline PwQpolynomialFold UnionPwQpolynomialFold::extractPwQpolynomialFold(const Space &dim) const {
  ctx.lock();
  UnionPwQpolynomialFold self = asUnionPwQpolynomialFold();
  // Prepare arguments
  Space _cast_dim = dim.asSpace();
  // Call isl_union_pw_qpolynomial_fold_extract_pw_qpolynomial_fold
  isl_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_extract_pw_qpolynomial_fold((self).Get(), (_cast_dim).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_extract_pw_qpolynomial_fold returned a NULL pointer.");
  }
  return PwQpolynomialFold(res);
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::fold(const UnionPwQpolynomialFold &upwf2) const {
  ctx.lock();
  UnionPwQpolynomialFold self = asUnionPwQpolynomialFold();
  // Prepare arguments
  UnionPwQpolynomialFold _cast_upwf2 = upwf2.asUnionPwQpolynomialFold();
  // Call isl_union_pw_qpolynomial_fold_fold
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_fold((self).Give(), (_cast_upwf2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_fold returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(res);
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::foldPwQpolynomialFold(const PwQpolynomialFold &pwqp) const {
  ctx.lock();
  UnionPwQpolynomialFold self = asUnionPwQpolynomialFold();
  // Prepare arguments
  PwQpolynomialFold _cast_pwqp = pwqp.asPwQpolynomialFold();
  // Call isl_union_pw_qpolynomial_fold_fold_pw_qpolynomial_fold
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_fold_pw_qpolynomial_fold((self).Give(), (_cast_pwqp).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_fold_pw_qpolynomial_fold returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(res);
}

inline Stat UnionPwQpolynomialFold::foreachPwQpolynomialFold(const std::function<isl_stat(isl_pw_qpolynomial_fold *, void *)> && fn, void * user) const {
  ctx.lock();
  UnionPwQpolynomialFold self = asUnionPwQpolynomialFold();
  // Prepare arguments
  // Call isl_union_pw_qpolynomial_fold_foreach_pw_qpolynomial_fold
  isl_stat res =  isl_union_pw_qpolynomial_fold_foreach_pw_qpolynomial_fold((self).Get(), get_fn_ptr<26>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline Space UnionPwQpolynomialFold::getSpace() const {
  ctx.lock();
  UnionPwQpolynomialFold self = asUnionPwQpolynomialFold();
  // Prepare arguments
  // Call isl_union_pw_qpolynomial_fold_get_space
  isl_space * res =  isl_union_pw_qpolynomial_fold_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_get_space returned a NULL pointer.");
  }
  return Space(res);
}

inline Fold UnionPwQpolynomialFold::getType() const {
  ctx.lock();
  UnionPwQpolynomialFold self = asUnionPwQpolynomialFold();
  // Prepare arguments
  // Call isl_union_pw_qpolynomial_fold_get_type
  enum isl_fold res =  isl_union_pw_qpolynomial_fold_get_type((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Fold)res;
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::gist(const UnionSet &context) const {
  ctx.lock();
  UnionPwQpolynomialFold self = asUnionPwQpolynomialFold();
  // Prepare arguments
  UnionSet _cast_context = context.asUnionSet();
  // Call isl_union_pw_qpolynomial_fold_gist
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_gist((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_gist returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(res);
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::gistParams(const Set &context) const {
  ctx.lock();
  UnionPwQpolynomialFold self = asUnionPwQpolynomialFold();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_union_pw_qpolynomial_fold_gist_params
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_gist_params((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_gist_params returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(res);
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::intersectDomain(const UnionSet &uset) const {
  ctx.lock();
  UnionPwQpolynomialFold self = asUnionPwQpolynomialFold();
  // Prepare arguments
  UnionSet _cast_uset = uset.asUnionSet();
  // Call isl_union_pw_qpolynomial_fold_intersect_domain
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_intersect_domain((self).Give(), (_cast_uset).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_intersect_domain returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(res);
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::intersectParams(const Set &set) const {
  ctx.lock();
  UnionPwQpolynomialFold self = asUnionPwQpolynomialFold();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_union_pw_qpolynomial_fold_intersect_params
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_intersect_params((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_intersect_params returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(res);
}

inline Bool UnionPwQpolynomialFold::plainIsEqual(const UnionPwQpolynomialFold &upwf2) const {
  ctx.lock();
  UnionPwQpolynomialFold self = asUnionPwQpolynomialFold();
  // Prepare arguments
  UnionPwQpolynomialFold _cast_upwf2 = upwf2.asUnionPwQpolynomialFold();
  // Call isl_union_pw_qpolynomial_fold_plain_is_equal
  isl_bool res =  isl_union_pw_qpolynomial_fold_plain_is_equal((self).Get(), (_cast_upwf2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::scaleVal(const Val &v) const {
  ctx.lock();
  UnionPwQpolynomialFold self = asUnionPwQpolynomialFold();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_union_pw_qpolynomial_fold_scale_val
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_scale_val((self).Give(), (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_scale_val returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(res);
}

} // namespace isl
#endif //ISL_CXX_UnionPwQpolynomialFold_IMPL_H
