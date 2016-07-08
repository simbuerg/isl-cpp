#ifndef ISL_CXX_PwQpolynomialFold_IMPL_H
#define ISL_CXX_PwQpolynomialFold_IMPL_H

#include "isl/PwQpolynomialFold.h"

#include "isl/Point.hpp"
#include "isl/PwQpolynomial.hpp"
#include "isl/QpolynomialFold.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/Val.hpp"
#include "isl/Bool.h"
#include "isl/DimType.h"
#include "isl/Fold.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/polynomial.h"
#include "isl/set.h"
#include <string>

#include <cassert>

namespace isl {

inline isl_pw_qpolynomial_fold *PwQpolynomialFold::GetCopy() const {
  return isl_pw_qpolynomial_fold_copy((isl_pw_qpolynomial_fold *)This);
}
inline PwQpolynomialFold &PwQpolynomialFold::operator=(const PwQpolynomialFold &Other) {
  isl_pw_qpolynomial_fold *New = Other.GetCopy();
  ctx = Other.Context();
  isl_pw_qpolynomial_fold_free((isl_pw_qpolynomial_fold *)This);
  This = New;
  return *this;
}
inline PwQpolynomialFold PwQpolynomialFold::fromPwQpolynomial(Fold type, const PwQpolynomial &pwqp) {
  const Ctx &_ctx = pwqp.Context();
  _ctx.lock();
  isl_pw_qpolynomial_fold *That = isl_pw_qpolynomial_fold_from_pw_qpolynomial((enum isl_fold)type, (pwqp).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_from_pw_qpolynomial returned a NULL pointer.");
  }

  return PwQpolynomialFold(_ctx, That);
}

inline PwQpolynomialFold PwQpolynomialFold::alloc(Fold type, const Set &set, const QpolynomialFold &fold) {
  const Ctx &_ctx = fold.Context();
  _ctx.lock();
  isl_pw_qpolynomial_fold *That = isl_pw_qpolynomial_fold_alloc((enum isl_fold)type, (set).GetCopy(), (fold).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_alloc returned a NULL pointer.");
  }

  return PwQpolynomialFold(_ctx, That);
}

inline PwQpolynomialFold PwQpolynomialFold::zero(const Space &dim, Fold type) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_pw_qpolynomial_fold *That = isl_pw_qpolynomial_fold_zero((dim).GetCopy(), (enum isl_fold)type);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_zero returned a NULL pointer.");
  }

  return PwQpolynomialFold(_ctx, That);
}
inline PwQpolynomialFold::~PwQpolynomialFold() {
  isl_pw_qpolynomial_fold_free((isl_pw_qpolynomial_fold *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_pw_qpolynomial_fold *PwQpolynomialFold::Give() {
  isl_pw_qpolynomial_fold *res = (isl_pw_qpolynomial_fold *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_pw_qpolynomial_fold *PwQpolynomialFold::Get() const {  return (isl_pw_qpolynomial_fold *)This;
}

inline PwQpolynomialFold PwQpolynomialFold::add(const PwQpolynomialFold &pwf2) const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_add((*this).GetCopy(), (pwf2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_add returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::addDisjoint(const PwQpolynomialFold &pwf2) const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_add_disjoint((*this).GetCopy(), (pwf2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_add_disjoint returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::bound(int * tight) const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_bound((*this).GetCopy(), tight);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_bound returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::coalesce() const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_coalesce((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_coalesce returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline unsigned int PwQpolynomialFold::dim(DimType type) const {
  ctx.lock();
  unsigned int res =  isl_pw_qpolynomial_fold_dim((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return res;
}

inline Set PwQpolynomialFold::domain() const {
  ctx.lock();
  isl_set * res =  isl_pw_qpolynomial_fold_domain((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_domain returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::dropDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_drop_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_drop_dims returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline Val PwQpolynomialFold::eval(const Point &pnt) const {
  ctx.lock();
  isl_val * res =  isl_pw_qpolynomial_fold_eval((*this).GetCopy(), (pnt).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_eval returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::fold(const PwQpolynomialFold &pwf2) const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_fold((*this).GetCopy(), (pwf2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_fold returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline Stat PwQpolynomialFold::foreachLiftedPiece(const std::function<isl_stat(isl_set *, isl_qpolynomial_fold *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_pw_qpolynomial_fold_foreach_lifted_piece((*this).Get(), get_fn_ptr<9>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline Stat PwQpolynomialFold::foreachPiece(const std::function<isl_stat(isl_set *, isl_qpolynomial_fold *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_pw_qpolynomial_fold_foreach_piece((*this).Get(), get_fn_ptr<10>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline Space PwQpolynomialFold::getDomainSpace() const {
  ctx.lock();
  isl_space * res =  isl_pw_qpolynomial_fold_get_domain_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_get_domain_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space PwQpolynomialFold::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_pw_qpolynomial_fold_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::gist(const Set &context) const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_gist((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_gist returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::gistParams(const Set &context) const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_gist_params((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_gist_params returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline int PwQpolynomialFold::hasEqualSpace(const PwQpolynomialFold &pwf2) const {
  ctx.lock();
  int res =  isl_pw_qpolynomial_fold_has_equal_space((*this).Get(), (pwf2).Get());
  ctx.unlock();
  return res;
}

inline PwQpolynomialFold PwQpolynomialFold::intersectDomain(const Set &set) const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_intersect_domain((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_intersect_domain returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::intersectParams(const Set &set) const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_intersect_params((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_intersect_params returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline Bool PwQpolynomialFold::isZero() const {
  ctx.lock();
  isl_bool res =  isl_pw_qpolynomial_fold_is_zero((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Val PwQpolynomialFold::max() const {
  ctx.lock();
  isl_val * res =  isl_pw_qpolynomial_fold_max((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_max returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Val PwQpolynomialFold::min() const {
  ctx.lock();
  isl_val * res =  isl_pw_qpolynomial_fold_min((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_min returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_move_dims((*this).GetCopy(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_move_dims returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline Bool PwQpolynomialFold::plainIsEqual(const PwQpolynomialFold &pwf2) const {
  ctx.lock();
  isl_bool res =  isl_pw_qpolynomial_fold_plain_is_equal((*this).Get(), (pwf2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline PwQpolynomialFold PwQpolynomialFold::projectDomainOnParams() const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_project_domain_on_params((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_project_domain_on_params returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::resetSpace(const Space &dim) const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_reset_space((*this).GetCopy(), (dim).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_reset_space returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::scaleVal(const Val &v) const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_scale_val((*this).GetCopy(), (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_scale_val returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::setDimName(DimType type, unsigned int pos, std::string s) const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_set_dim_name((*this).GetCopy(), (enum isl_dim_type)type, pos, s.c_str());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_set_dim_name returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline size_t PwQpolynomialFold::size() const {
  ctx.lock();
  size_t res =  isl_pw_qpolynomial_fold_size((*this).Get());
  ctx.unlock();
  return res;
}

} // namespace isl
#endif //ISL_CXX_PwQpolynomialFold_IMPL_H
