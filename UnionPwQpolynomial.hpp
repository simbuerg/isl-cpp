#ifndef ISL_CXX_UnionPwQpolynomial_IMPL_H
#define ISL_CXX_UnionPwQpolynomial_IMPL_H

#include "isl/UnionPwQpolynomial.h"

#include "isl/Point.hpp"
#include "isl/PwQpolynomial.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/UnionPwQpolynomialFold.hpp"
#include "isl/UnionSet.hpp"
#include "isl/Val.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
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
inline isl_union_pw_qpolynomial *UnionPwQpolynomial::GetCopy() const {
  return isl_union_pw_qpolynomial_copy((isl_union_pw_qpolynomial *)This);
}
inline UnionPwQpolynomial &UnionPwQpolynomial::operator=(const UnionPwQpolynomial &Other) {
  isl_union_pw_qpolynomial *New = Other.GetCopy();
  isl_union_pw_qpolynomial_free((isl_union_pw_qpolynomial *)This);
  This = New;
  return *this;
}
inline UnionPwQpolynomial UnionPwQpolynomial::fromPwQpolynomial(const PwQpolynomial &pwqp) {
  const Ctx &_ctx = pwqp.Context();
  _ctx.lock();
  PwQpolynomial _cast_pwqp = pwqp.asPwQpolynomial();
  isl_union_pw_qpolynomial *That = isl_union_pw_qpolynomial_from_pw_qpolynomial((_cast_pwqp).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_from_pw_qpolynomial returned a NULL pointer.");
  }

  return UnionPwQpolynomial(_ctx, That);
}

inline UnionPwQpolynomial UnionPwQpolynomial::zero(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_union_pw_qpolynomial *That = isl_union_pw_qpolynomial_zero((_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_zero returned a NULL pointer.");
  }

  return UnionPwQpolynomial(_ctx, That);
}

inline UnionPwQpolynomial UnionPwQpolynomial::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_union_pw_qpolynomial *That = isl_union_pw_qpolynomial_read_from_str((ctx.Get()), str.c_str());
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_read_from_str returned a NULL pointer.");
  }

  return UnionPwQpolynomial(_ctx, That);
}
inline UnionPwQpolynomial::~UnionPwQpolynomial() {
  isl_union_pw_qpolynomial_free((isl_union_pw_qpolynomial *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_union_pw_qpolynomial *UnionPwQpolynomial::Give() {
  isl_union_pw_qpolynomial *res = (isl_union_pw_qpolynomial *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_union_pw_qpolynomial *UnionPwQpolynomial::Get() const {  return (isl_union_pw_qpolynomial *)This;
}

inline UnionPwQpolynomial UnionPwQpolynomial::asUnionPwQpolynomial() const {
  return UnionPwQpolynomial(ctx, GetCopy());
}

inline UnionPwQpolynomial UnionPwQpolynomial::add(const UnionPwQpolynomial &upwqp2) const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  UnionPwQpolynomial _cast_upwqp2 = upwqp2.asUnionPwQpolynomial();
  // Call isl_union_pw_qpolynomial_add
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_add((self).Give(), (_cast_upwqp2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_add returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::addPwQpolynomial(const PwQpolynomial &pwqp) const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  PwQpolynomial _cast_pwqp = pwqp.asPwQpolynomial();
  // Call isl_union_pw_qpolynomial_add_pw_qpolynomial
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_add_pw_qpolynomial((self).Give(), (_cast_pwqp).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_add_pw_qpolynomial returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::alignParams(const Space &model) const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  Space _cast_model = model.asSpace();
  // Call isl_union_pw_qpolynomial_align_params
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_align_params((self).Give(), (_cast_model).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_align_params returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionPwQpolynomialFold UnionPwQpolynomial::bound(Fold type, int * tight) const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  // Call isl_union_pw_qpolynomial_bound
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_bound((self).Give(), (enum isl_fold)type, tight);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_bound returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::coalesce() const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  // Call isl_union_pw_qpolynomial_coalesce
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_coalesce((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_coalesce returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionSet UnionPwQpolynomial::domain() const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  // Call isl_union_pw_qpolynomial_domain
  isl_union_set * res =  isl_union_pw_qpolynomial_domain((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_domain returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline Val UnionPwQpolynomial::eval(const Point &pnt) const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  Point _cast_pnt = pnt.asPoint();
  // Call isl_union_pw_qpolynomial_eval
  isl_val * res =  isl_union_pw_qpolynomial_eval((self).Give(), (_cast_pnt).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_eval returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline PwQpolynomial UnionPwQpolynomial::extractPwQpolynomial(const Space &dim) const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  Space _cast_dim = dim.asSpace();
  // Call isl_union_pw_qpolynomial_extract_pw_qpolynomial
  isl_pw_qpolynomial * res =  isl_union_pw_qpolynomial_extract_pw_qpolynomial((self).Get(), (_cast_dim).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_extract_pw_qpolynomial returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline Stat UnionPwQpolynomial::foreachPwQpolynomial(const std::function<isl_stat(isl_pw_qpolynomial *, void *)> && fn, void * user) const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  // Call isl_union_pw_qpolynomial_foreach_pw_qpolynomial
  isl_stat res =  isl_union_pw_qpolynomial_foreach_pw_qpolynomial((self).Get(), get_fn_ptr<25>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline Space UnionPwQpolynomial::getSpace() const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  // Call isl_union_pw_qpolynomial_get_space
  isl_space * res =  isl_union_pw_qpolynomial_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::gist(const UnionSet &context) const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  UnionSet _cast_context = context.asUnionSet();
  // Call isl_union_pw_qpolynomial_gist
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_gist((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_gist returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::gistParams(const Set &context) const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_union_pw_qpolynomial_gist_params
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_gist_params((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_gist_params returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::intersectDomain(const UnionSet &uset) const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  UnionSet _cast_uset = uset.asUnionSet();
  // Call isl_union_pw_qpolynomial_intersect_domain
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_intersect_domain((self).Give(), (_cast_uset).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_intersect_domain returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::intersectParams(const Set &set) const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_union_pw_qpolynomial_intersect_params
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_intersect_params((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_intersect_params returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::mul(const UnionPwQpolynomial &upwqp2) const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  UnionPwQpolynomial _cast_upwqp2 = upwqp2.asUnionPwQpolynomial();
  // Call isl_union_pw_qpolynomial_mul
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_mul((self).Give(), (_cast_upwqp2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_mul returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline Bool UnionPwQpolynomial::plainIsEqual(const UnionPwQpolynomial &upwqp2) const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  UnionPwQpolynomial _cast_upwqp2 = upwqp2.asUnionPwQpolynomial();
  // Call isl_union_pw_qpolynomial_plain_is_equal
  isl_bool res =  isl_union_pw_qpolynomial_plain_is_equal((self).Get(), (_cast_upwqp2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline UnionPwQpolynomial UnionPwQpolynomial::scaleVal(const Val &v) const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_union_pw_qpolynomial_scale_val
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_scale_val((self).Give(), (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_scale_val returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::sub(const UnionPwQpolynomial &upwqp2) const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  UnionPwQpolynomial _cast_upwqp2 = upwqp2.asUnionPwQpolynomial();
  // Call isl_union_pw_qpolynomial_sub
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_sub((self).Give(), (_cast_upwqp2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_sub returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::toPolynomial(int sign) const {
  ctx.lock();
  UnionPwQpolynomial self = asUnionPwQpolynomial();
  // Prepare arguments
  // Call isl_union_pw_qpolynomial_to_polynomial
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_to_polynomial((self).Give(), sign);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_to_polynomial returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_UnionPwQpolynomial_IMPL_H
