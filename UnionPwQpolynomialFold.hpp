#ifndef ISL_CXX_UnionPwQpolynomialFold_IMPL_H
#define ISL_CXX_UnionPwQpolynomialFold_IMPL_H

#include "isl/UnionPwQpolynomialFold.h"

#include "isl/Point.hpp"
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
  const Ctx &_ctx = pwf.Context();
  _ctx.lock();
  isl_union_pw_qpolynomial_fold *That = isl_union_pw_qpolynomial_fold_from_pw_qpolynomial_fold((pwf).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_from_pw_qpolynomial_fold returned a NULL pointer.");
  }

  return UnionPwQpolynomialFold(_ctx, That);
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::zero(const Space &dim, Fold type) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_union_pw_qpolynomial_fold *That = isl_union_pw_qpolynomial_fold_zero((dim).GetCopy(), (enum isl_fold)type);

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


inline UnionPwQpolynomialFold UnionPwQpolynomialFold::addUnionPwQpolynomial(const UnionPwQpolynomial &upwqp) const {
  ctx.lock();
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_add_union_pw_qpolynomial((*this).GetCopy(), (upwqp).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_add_union_pw_qpolynomial returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(ctx, res);
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::alignParams(const Space &model) const {
  ctx.lock();
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_align_params((*this).GetCopy(), (model).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_align_params returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(ctx, res);
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::coalesce() const {
  ctx.lock();
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_coalesce((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_coalesce returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(ctx, res);
}

inline UnionSet UnionPwQpolynomialFold::domain() const {
  ctx.lock();
  isl_union_set * res =  isl_union_pw_qpolynomial_fold_domain((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_domain returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline Val UnionPwQpolynomialFold::eval(const Point &pnt) const {
  ctx.lock();
  isl_val * res =  isl_union_pw_qpolynomial_fold_eval((*this).GetCopy(), (pnt).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_eval returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline PwQpolynomialFold UnionPwQpolynomialFold::extractPwQpolynomialFold(const Space &dim) const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_extract_pw_qpolynomial_fold((*this).Get(), (dim).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_extract_pw_qpolynomial_fold returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::fold(const UnionPwQpolynomialFold &upwf2) const {
  ctx.lock();
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_fold((*this).GetCopy(), (upwf2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_fold returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(ctx, res);
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::foldPwQpolynomialFold(const PwQpolynomialFold &pwqp) const {
  ctx.lock();
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_fold_pw_qpolynomial_fold((*this).GetCopy(), (pwqp).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_fold_pw_qpolynomial_fold returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(ctx, res);
}

inline Stat UnionPwQpolynomialFold::foreachPwQpolynomialFold(const std::function<isl_stat(isl_pw_qpolynomial_fold *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_union_pw_qpolynomial_fold_foreach_pw_qpolynomial_fold((*this).Get(), get_fn_ptr<22>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline Space UnionPwQpolynomialFold::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_union_pw_qpolynomial_fold_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Fold UnionPwQpolynomialFold::getType() const {
  ctx.lock();
  enum isl_fold res =  isl_union_pw_qpolynomial_fold_get_type((*this).Get());
  ctx.unlock();
  return (Fold)res;
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::gist(const UnionSet &context) const {
  ctx.lock();
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_gist((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_gist returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(ctx, res);
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::gistParams(const Set &context) const {
  ctx.lock();
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_gist_params((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_gist_params returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(ctx, res);
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::intersectDomain(const UnionSet &uset) const {
  ctx.lock();
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_intersect_domain((*this).GetCopy(), (uset).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_intersect_domain returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(ctx, res);
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::intersectParams(const Set &set) const {
  ctx.lock();
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_intersect_params((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_intersect_params returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(ctx, res);
}

inline Bool UnionPwQpolynomialFold::plainIsEqual(const UnionPwQpolynomialFold &upwf2) const {
  ctx.lock();
  isl_bool res =  isl_union_pw_qpolynomial_fold_plain_is_equal((*this).Get(), (upwf2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline UnionPwQpolynomialFold UnionPwQpolynomialFold::scaleVal(const Val &v) const {
  ctx.lock();
  isl_union_pw_qpolynomial_fold * res =  isl_union_pw_qpolynomial_fold_scale_val((*this).GetCopy(), (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_pw_qpolynomial_fold_scale_val returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_UnionPwQpolynomialFold_IMPL_H
