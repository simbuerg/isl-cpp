#ifndef ISL_CXX_QpolynomialFold_IMPL_H
#define ISL_CXX_QpolynomialFold_IMPL_H

#include "isl/QpolynomialFold.h"

#include "isl/Point.hpp"
#include "isl/Qpolynomial.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/Val.hpp"
#include "isl/DimType.h"
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
inline isl_qpolynomial_fold *QpolynomialFold::GetCopy() const {
  return isl_qpolynomial_fold_copy((isl_qpolynomial_fold *)This);
}
inline QpolynomialFold &QpolynomialFold::operator=(const QpolynomialFold &Other) {
  isl_qpolynomial_fold *New = Other.GetCopy();
  isl_qpolynomial_fold_free((isl_qpolynomial_fold *)This);
  This = New;
  return *this;
}
inline QpolynomialFold QpolynomialFold::empty(Fold type, const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_qpolynomial_fold *That = isl_qpolynomial_fold_empty((enum isl_fold)type, (_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_fold_empty returned a NULL pointer.");
  }

  return QpolynomialFold(_ctx, That);
}

inline QpolynomialFold QpolynomialFold::alloc(Fold type, const Qpolynomial &qp) {
  const Ctx &_ctx = qp.Context();
  _ctx.lock();
  Qpolynomial _cast_qp = qp.asQpolynomial();
  isl_qpolynomial_fold *That = isl_qpolynomial_fold_alloc((enum isl_fold)type, (_cast_qp).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_fold_alloc returned a NULL pointer.");
  }

  return QpolynomialFold(_ctx, That);
}
inline QpolynomialFold::~QpolynomialFold() {
  isl_qpolynomial_fold_free((isl_qpolynomial_fold *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_qpolynomial_fold *QpolynomialFold::Give() {
  isl_qpolynomial_fold *res = (isl_qpolynomial_fold *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_qpolynomial_fold *QpolynomialFold::Get() const {  return (isl_qpolynomial_fold *)This;
}

inline QpolynomialFold QpolynomialFold::asQpolynomialFold() const {
  return QpolynomialFold(ctx, GetCopy());
}

inline Val QpolynomialFold::eval(const Point &pnt) const {
  ctx.lock();
  QpolynomialFold self = asQpolynomialFold();
  // Prepare arguments
  Point _cast_pnt = pnt.asPoint();
  // Call isl_qpolynomial_fold_eval
  isl_val * res =  isl_qpolynomial_fold_eval((self).Give(), (_cast_pnt).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_fold_eval returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline QpolynomialFold QpolynomialFold::fold(const QpolynomialFold &fold2) const {
  ctx.lock();
  QpolynomialFold self = asQpolynomialFold();
  // Prepare arguments
  QpolynomialFold _cast_fold2 = fold2.asQpolynomialFold();
  // Call isl_qpolynomial_fold_fold
  isl_qpolynomial_fold * res =  isl_qpolynomial_fold_fold((self).Give(), (_cast_fold2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_fold_fold returned a NULL pointer.");
  }
  return QpolynomialFold(ctx, res);
}

inline Stat QpolynomialFold::foreachQpolynomial(const std::function<isl_stat(isl_qpolynomial *, void *)> && fn, void * user) const {
  ctx.lock();
  QpolynomialFold self = asQpolynomialFold();
  // Prepare arguments
  // Call isl_qpolynomial_fold_foreach_qpolynomial
  isl_stat res =  isl_qpolynomial_fold_foreach_qpolynomial((self).Get(), get_fn_ptr<17>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline Space QpolynomialFold::getSpace() const {
  ctx.lock();
  QpolynomialFold self = asQpolynomialFold();
  // Prepare arguments
  // Call isl_qpolynomial_fold_get_space
  isl_space * res =  isl_qpolynomial_fold_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_fold_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Fold QpolynomialFold::getType() const {
  ctx.lock();
  QpolynomialFold self = asQpolynomialFold();
  // Prepare arguments
  // Call isl_qpolynomial_fold_get_type
  enum isl_fold res =  isl_qpolynomial_fold_get_type((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Fold)res;
}

inline QpolynomialFold QpolynomialFold::gist(const Set &context) const {
  ctx.lock();
  QpolynomialFold self = asQpolynomialFold();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_qpolynomial_fold_gist
  isl_qpolynomial_fold * res =  isl_qpolynomial_fold_gist((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_fold_gist returned a NULL pointer.");
  }
  return QpolynomialFold(ctx, res);
}

inline QpolynomialFold QpolynomialFold::gistParams(const Set &context) const {
  ctx.lock();
  QpolynomialFold self = asQpolynomialFold();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_qpolynomial_fold_gist_params
  isl_qpolynomial_fold * res =  isl_qpolynomial_fold_gist_params((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_fold_gist_params returned a NULL pointer.");
  }
  return QpolynomialFold(ctx, res);
}

inline int QpolynomialFold::isEmpty() const {
  ctx.lock();
  QpolynomialFold self = asQpolynomialFold();
  // Prepare arguments
  // Call isl_qpolynomial_fold_is_empty
  int res =  isl_qpolynomial_fold_is_empty((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline QpolynomialFold QpolynomialFold::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  QpolynomialFold self = asQpolynomialFold();
  // Prepare arguments
  // Call isl_qpolynomial_fold_move_dims
  isl_qpolynomial_fold * res =  isl_qpolynomial_fold_move_dims((self).Give(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_fold_move_dims returned a NULL pointer.");
  }
  return QpolynomialFold(ctx, res);
}

inline int QpolynomialFold::plainIsEqual(const QpolynomialFold &fold2) const {
  ctx.lock();
  QpolynomialFold self = asQpolynomialFold();
  // Prepare arguments
  QpolynomialFold _cast_fold2 = fold2.asQpolynomialFold();
  // Call isl_qpolynomial_fold_plain_is_equal
  int res =  isl_qpolynomial_fold_plain_is_equal((self).Get(), (_cast_fold2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline QpolynomialFold QpolynomialFold::scaleVal(const Val &v) const {
  ctx.lock();
  QpolynomialFold self = asQpolynomialFold();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_qpolynomial_fold_scale_val
  isl_qpolynomial_fold * res =  isl_qpolynomial_fold_scale_val((self).Give(), (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_fold_scale_val returned a NULL pointer.");
  }
  return QpolynomialFold(ctx, res);
}

inline QpolynomialFold QpolynomialFold::substitute(DimType type, unsigned int first, unsigned int n, std::unique_ptr<Qpolynomial> * subs) const {
  ctx.lock();
  QpolynomialFold self = asQpolynomialFold();
  // Prepare arguments
  isl_qpolynomial * _subs = nullptr;
  // Call isl_qpolynomial_fold_substitute
  isl_qpolynomial_fold * res =  isl_qpolynomial_fold_substitute((self).Give(), (enum isl_dim_type)type, first, n, (subs) ? &_subs : nullptr);
  // Handle result argument(s)
  if(subs) {
  if (ctx.hasError()) {
    handleError("subs became a NULL pointer.");
  }
    Qpolynomial _tmp_subs = Qpolynomial(ctx, _subs);
    subs->reset(new Qpolynomial(_tmp_subs));
  }
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_fold_substitute returned a NULL pointer.");
  }
  return QpolynomialFold(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_QpolynomialFold_IMPL_H
