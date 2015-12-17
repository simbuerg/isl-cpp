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
#include <ostream>

#include <cassert>

namespace isl {
inline isl_pw_qpolynomial_fold *PwQpolynomialFold::GetCopy() const {
  return isl_pw_qpolynomial_fold_copy((isl_pw_qpolynomial_fold *)This);
}
inline PwQpolynomialFold &PwQpolynomialFold::operator=(const PwQpolynomialFold &Other) {
  isl_pw_qpolynomial_fold *New = Other.GetCopy();
  isl_pw_qpolynomial_fold_free((isl_pw_qpolynomial_fold *)This);
  This = New;
  return *this;
}
inline PwQpolynomialFold PwQpolynomialFold::zero(const Space &dim, Fold type) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_pw_qpolynomial_fold *That = isl_pw_qpolynomial_fold_zero((_cast_dim).Give(), (enum isl_fold)type);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_zero returned a NULL pointer.");
  }

  return PwQpolynomialFold(_ctx, That);
}

inline PwQpolynomialFold PwQpolynomialFold::fromPwQpolynomial(Fold type, const PwQpolynomial &pwqp) {
  const Ctx &_ctx = pwqp.Context();
  _ctx.lock();
  PwQpolynomial _cast_pwqp = pwqp.asPwQpolynomial();
  isl_pw_qpolynomial_fold *That = isl_pw_qpolynomial_fold_from_pw_qpolynomial((enum isl_fold)type, (_cast_pwqp).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_from_pw_qpolynomial returned a NULL pointer.");
  }

  return PwQpolynomialFold(_ctx, That);
}

inline PwQpolynomialFold PwQpolynomialFold::alloc(Fold type, const Set &set, const QpolynomialFold &fold) {
  const Ctx &_ctx = fold.Context();
  _ctx.lock();
  Set _cast_set = set.asSet();
  QpolynomialFold _cast_fold = fold.asQpolynomialFold();
  isl_pw_qpolynomial_fold *That = isl_pw_qpolynomial_fold_alloc((enum isl_fold)type, (_cast_set).Give(), (_cast_fold).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_alloc returned a NULL pointer.");
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

inline PwQpolynomialFold PwQpolynomialFold::asPwQpolynomialFold() const {
  return PwQpolynomialFold(ctx, GetCopy());
}

inline PwQpolynomialFold PwQpolynomialFold::add(const PwQpolynomialFold &pwf2) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  PwQpolynomialFold _cast_pwf2 = pwf2.asPwQpolynomialFold();
  // Call isl_pw_qpolynomial_fold_add
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_add((self).Give(), (_cast_pwf2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_add returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::addDisjoint(const PwQpolynomialFold &pwf2) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  PwQpolynomialFold _cast_pwf2 = pwf2.asPwQpolynomialFold();
  // Call isl_pw_qpolynomial_fold_add_disjoint
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_add_disjoint((self).Give(), (_cast_pwf2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_add_disjoint returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::bound(int * tight) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  // Call isl_pw_qpolynomial_fold_bound
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_bound((self).Give(), tight);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_bound returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::coalesce() const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  // Call isl_pw_qpolynomial_fold_coalesce
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_coalesce((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_coalesce returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline unsigned int PwQpolynomialFold::dim(DimType type) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  // Call isl_pw_qpolynomial_fold_dim
  unsigned int res =  isl_pw_qpolynomial_fold_dim((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Set PwQpolynomialFold::domain() const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  // Call isl_pw_qpolynomial_fold_domain
  isl_set * res =  isl_pw_qpolynomial_fold_domain((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_domain returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::dropDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  // Call isl_pw_qpolynomial_fold_drop_dims
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_drop_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_drop_dims returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline Val PwQpolynomialFold::eval(const Point &pnt) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  Point _cast_pnt = pnt.asPoint();
  // Call isl_pw_qpolynomial_fold_eval
  isl_val * res =  isl_pw_qpolynomial_fold_eval((self).Give(), (_cast_pnt).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_eval returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::fold(const PwQpolynomialFold &pwf2) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  PwQpolynomialFold _cast_pwf2 = pwf2.asPwQpolynomialFold();
  // Call isl_pw_qpolynomial_fold_fold
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_fold((self).Give(), (_cast_pwf2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_fold returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline Stat PwQpolynomialFold::foreachLiftedPiece(const std::function<isl_stat(isl_set *, isl_qpolynomial_fold *, void *)> && fn, void * user) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  // Call isl_pw_qpolynomial_fold_foreach_lifted_piece
  isl_stat res =  isl_pw_qpolynomial_fold_foreach_lifted_piece((self).Get(), get_fn_ptr<13>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline Stat PwQpolynomialFold::foreachPiece(const std::function<isl_stat(isl_set *, isl_qpolynomial_fold *, void *)> && fn, void * user) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  // Call isl_pw_qpolynomial_fold_foreach_piece
  isl_stat res =  isl_pw_qpolynomial_fold_foreach_piece((self).Get(), get_fn_ptr<14>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline Space PwQpolynomialFold::getDomainSpace() const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  // Call isl_pw_qpolynomial_fold_get_domain_space
  isl_space * res =  isl_pw_qpolynomial_fold_get_domain_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_get_domain_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space PwQpolynomialFold::getSpace() const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  // Call isl_pw_qpolynomial_fold_get_space
  isl_space * res =  isl_pw_qpolynomial_fold_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::gist(const Set &context) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_pw_qpolynomial_fold_gist
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_gist((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_gist returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::gistParams(const Set &context) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_pw_qpolynomial_fold_gist_params
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_gist_params((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_gist_params returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline int PwQpolynomialFold::hasEqualSpace(const PwQpolynomialFold &pwf2) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  PwQpolynomialFold _cast_pwf2 = pwf2.asPwQpolynomialFold();
  // Call isl_pw_qpolynomial_fold_has_equal_space
  int res =  isl_pw_qpolynomial_fold_has_equal_space((self).Get(), (_cast_pwf2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline PwQpolynomialFold PwQpolynomialFold::intersectDomain(const Set &set) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_pw_qpolynomial_fold_intersect_domain
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_intersect_domain((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_intersect_domain returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::intersectParams(const Set &set) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_pw_qpolynomial_fold_intersect_params
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_intersect_params((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_intersect_params returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline Bool PwQpolynomialFold::isZero() const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  // Call isl_pw_qpolynomial_fold_is_zero
  isl_bool res =  isl_pw_qpolynomial_fold_is_zero((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Val PwQpolynomialFold::max() const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  // Call isl_pw_qpolynomial_fold_max
  isl_val * res =  isl_pw_qpolynomial_fold_max((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_max returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Val PwQpolynomialFold::min() const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  // Call isl_pw_qpolynomial_fold_min
  isl_val * res =  isl_pw_qpolynomial_fold_min((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_min returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  // Call isl_pw_qpolynomial_fold_move_dims
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_move_dims((self).Give(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_move_dims returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline Bool PwQpolynomialFold::plainIsEqual(const PwQpolynomialFold &pwf2) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  PwQpolynomialFold _cast_pwf2 = pwf2.asPwQpolynomialFold();
  // Call isl_pw_qpolynomial_fold_plain_is_equal
  isl_bool res =  isl_pw_qpolynomial_fold_plain_is_equal((self).Get(), (_cast_pwf2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline PwQpolynomialFold PwQpolynomialFold::projectDomainOnParams() const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  // Call isl_pw_qpolynomial_fold_project_domain_on_params
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_project_domain_on_params((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_project_domain_on_params returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::resetSpace(const Space &dim) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  Space _cast_dim = dim.asSpace();
  // Call isl_pw_qpolynomial_fold_reset_space
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_reset_space((self).Give(), (_cast_dim).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_reset_space returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::scaleVal(const Val &v) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_pw_qpolynomial_fold_scale_val
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_scale_val((self).Give(), (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_scale_val returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline PwQpolynomialFold PwQpolynomialFold::setDimName(DimType type, unsigned int pos, std::string s) const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  // Call isl_pw_qpolynomial_fold_set_dim_name
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_fold_set_dim_name((self).Give(), (enum isl_dim_type)type, pos, s.c_str());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fold_set_dim_name returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline size_t PwQpolynomialFold::size() const {
  ctx.lock();
  PwQpolynomialFold self = asPwQpolynomialFold();
  // Prepare arguments
  // Call isl_pw_qpolynomial_fold_size
  size_t res =  isl_pw_qpolynomial_fold_size((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

} // namespace isl
#endif //ISL_CXX_PwQpolynomialFold_IMPL_H
