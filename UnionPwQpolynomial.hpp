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

#include <cassert>

namespace isl {

inline isl_union_pw_qpolynomial *UnionPwQpolynomial::GetCopy() const {
  return isl_union_pw_qpolynomial_copy((isl_union_pw_qpolynomial *)This);
}
inline UnionPwQpolynomial &UnionPwQpolynomial::operator=(const UnionPwQpolynomial &Other) {
  isl_union_pw_qpolynomial *New = Other.GetCopy();
  ctx = Other.Context();
  isl_union_pw_qpolynomial_free((isl_union_pw_qpolynomial *)This);
  This = New;
  return *this;
}
inline UnionPwQpolynomial UnionPwQpolynomial::fromPwQpolynomial(const PwQpolynomial &pwqp) {
  const Ctx &_ctx = pwqp.Context();
  _ctx.lock();
  isl_union_pw_qpolynomial *That = isl_union_pw_qpolynomial_from_pw_qpolynomial((pwqp).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_from_pw_qpolynomial returned a NULL pointer.");
  }

  return UnionPwQpolynomial(_ctx, That);
}

inline UnionPwQpolynomial UnionPwQpolynomial::zero(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_union_pw_qpolynomial *That = isl_union_pw_qpolynomial_zero((dim).GetCopy());

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

inline UnionPwQpolynomial UnionPwQpolynomial::add(const UnionPwQpolynomial &upwqp2) const {
  ctx.lock();
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_add((*this).GetCopy(), (upwqp2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_add returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::addPwQpolynomial(const PwQpolynomial &pwqp) const {
  ctx.lock();
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_add_pw_qpolynomial((*this).GetCopy(), (pwqp).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_add_pw_qpolynomial returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::alignParams(const Space &model) const {
  ctx.lock();
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_align_params((*this).GetCopy(), (model).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_align_params returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionPwQpolynomialFold UnionPwQpolynomial::bound(Fold type, int * tight) const {
  ctx.lock();
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_bound((*this).GetCopy(), (enum isl_fold)type, tight);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_bound returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::coalesce() const {
  ctx.lock();
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_coalesce((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_coalesce returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionSet UnionPwQpolynomial::domain() const {
  ctx.lock();
  isl_union_set * res =  isl_union_pw_qpolynomial_domain((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_domain returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline Val UnionPwQpolynomial::eval(const Point &pnt) const {
  ctx.lock();
  isl_val * res =  isl_union_pw_qpolynomial_eval((*this).GetCopy(), (pnt).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_eval returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline PwQpolynomial UnionPwQpolynomial::extractPwQpolynomial(const Space &dim) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_union_pw_qpolynomial_extract_pw_qpolynomial((*this).Get(), (dim).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_extract_pw_qpolynomial returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline Stat UnionPwQpolynomial::foreachPwQpolynomial(const std::function<isl_stat(isl_pw_qpolynomial *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_union_pw_qpolynomial_foreach_pw_qpolynomial((*this).Get(), get_fn_ptr<21>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline Space UnionPwQpolynomial::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_union_pw_qpolynomial_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::gist(const UnionSet &context) const {
  ctx.lock();
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_gist((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_gist returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::gistParams(const Set &context) const {
  ctx.lock();
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_gist_params((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_gist_params returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::intersectDomain(const UnionSet &uset) const {
  ctx.lock();
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_intersect_domain((*this).GetCopy(), (uset).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_intersect_domain returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::intersectParams(const Set &set) const {
  ctx.lock();
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_intersect_params((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_intersect_params returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::mul(const UnionPwQpolynomial &upwqp2) const {
  ctx.lock();
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_mul((*this).GetCopy(), (upwqp2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_mul returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline Bool UnionPwQpolynomial::plainIsEqual(const UnionPwQpolynomial &upwqp2) const {
  ctx.lock();
  isl_bool res =  isl_union_pw_qpolynomial_plain_is_equal((*this).Get(), (upwqp2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline UnionPwQpolynomial UnionPwQpolynomial::scaleVal(const Val &v) const {
  ctx.lock();
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_scale_val((*this).GetCopy(), (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_scale_val returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::sub(const UnionPwQpolynomial &upwqp2) const {
  ctx.lock();
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_sub((*this).GetCopy(), (upwqp2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_sub returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

inline UnionPwQpolynomial UnionPwQpolynomial::toPolynomial(int sign) const {
  ctx.lock();
  isl_union_pw_qpolynomial * res =  isl_union_pw_qpolynomial_to_polynomial((*this).GetCopy(), sign);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_to_polynomial returned a NULL pointer.");
  }
  return UnionPwQpolynomial(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_UnionPwQpolynomial_IMPL_H
