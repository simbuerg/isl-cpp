#ifndef ISL_CXX_Qpolynomial_IMPL_H
#define ISL_CXX_Qpolynomial_IMPL_H

#include "isl/Qpolynomial.h"

#include "isl/Aff.hpp"
#include "isl/BasicSet.hpp"
#include "isl/Constraint.hpp"
#include "isl/Point.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/Term.hpp"
#include "isl/Val.hpp"
#include "isl/Bool.h"
#include "isl/DimType.h"
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
inline isl_qpolynomial *Qpolynomial::GetCopy() const {
  return isl_qpolynomial_copy((isl_qpolynomial *)This);
}
inline Qpolynomial &Qpolynomial::operator=(const Qpolynomial &Other) {
  isl_qpolynomial *New = Other.GetCopy();
  isl_qpolynomial_free((isl_qpolynomial *)This);
  This = New;
  return *this;
}
inline Qpolynomial Qpolynomial::zeroOnDomain(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_qpolynomial *That = isl_qpolynomial_zero_on_domain((_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_zero_on_domain returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}

inline Qpolynomial Qpolynomial::oneOnDomain(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_qpolynomial *That = isl_qpolynomial_one_on_domain((_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_one_on_domain returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}

inline Qpolynomial Qpolynomial::inftyOnDomain(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_qpolynomial *That = isl_qpolynomial_infty_on_domain((_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_infty_on_domain returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}

inline Qpolynomial Qpolynomial::neginftyOnDomain(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_qpolynomial *That = isl_qpolynomial_neginfty_on_domain((_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_neginfty_on_domain returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}

inline Qpolynomial Qpolynomial::nanOnDomain(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_qpolynomial *That = isl_qpolynomial_nan_on_domain((_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_nan_on_domain returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}

inline Qpolynomial Qpolynomial::valOnDomain(const Space &space, const Val &val) {
  const Ctx &_ctx = val.Context();
  _ctx.lock();
  Space _cast_space = space.asSpace();
  Val _cast_val = val.asVal();
  isl_qpolynomial *That = isl_qpolynomial_val_on_domain((_cast_space).Give(), (_cast_val).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_val_on_domain returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}

inline Qpolynomial Qpolynomial::varOnDomain(const Space &dim, DimType type, unsigned int pos) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_qpolynomial *That = isl_qpolynomial_var_on_domain((_cast_dim).Give(), (enum isl_dim_type)type, pos);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_var_on_domain returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}

inline Qpolynomial Qpolynomial::fromConstraint(const Constraint &c, DimType type, unsigned int pos) {
  const Ctx &_ctx = c.Context();
  _ctx.lock();
  Constraint _cast_c = c.asConstraint();
  isl_qpolynomial *That = isl_qpolynomial_from_constraint((_cast_c).Give(), (enum isl_dim_type)type, pos);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_from_constraint returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}

inline Qpolynomial Qpolynomial::fromTerm(const Term &term) {
  const Ctx &_ctx = term.Context();
  _ctx.lock();
  Term _cast_term = term.asTerm();
  isl_qpolynomial *That = isl_qpolynomial_from_term((_cast_term).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_from_term returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}

inline Qpolynomial Qpolynomial::fromAff(const Aff &aff) {
  const Ctx &_ctx = aff.Context();
  _ctx.lock();
  Aff _cast_aff = aff.asAff();
  isl_qpolynomial *That = isl_qpolynomial_from_aff((_cast_aff).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_from_aff returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}
inline Qpolynomial::~Qpolynomial() {
  isl_qpolynomial_free((isl_qpolynomial *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_qpolynomial *Qpolynomial::Give() {
  isl_qpolynomial *res = (isl_qpolynomial *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_qpolynomial *Qpolynomial::Get() const {  return (isl_qpolynomial *)This;
}

inline Qpolynomial Qpolynomial::asQpolynomial() const {
  return Qpolynomial(ctx, GetCopy());
}

inline Qpolynomial Qpolynomial::add(const Qpolynomial &qp2) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  Qpolynomial _cast_qp2 = qp2.asQpolynomial();
  // Call isl_qpolynomial_add
  isl_qpolynomial * res =  isl_qpolynomial_add((self).Give(), (_cast_qp2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_add returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_add_dims
  isl_qpolynomial * res =  isl_qpolynomial_add_dims((self).Give(), (enum isl_dim_type)type, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_add_dims returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::alignParams(const Space &model) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  Space _cast_model = model.asSpace();
  // Call isl_qpolynomial_align_params
  isl_qpolynomial * res =  isl_qpolynomial_align_params((self).Give(), (_cast_model).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_align_params returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline int Qpolynomial::asPolynomialOnDomain(const BasicSet &bset, const std::function<int(isl_basic_set *, isl_qpolynomial *, void *)> && fn, void * user) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  BasicSet _cast_bset = bset.asBasicSet();
  // Call isl_qpolynomial_as_polynomial_on_domain
  int res =  isl_qpolynomial_as_polynomial_on_domain((self).Get(), (_cast_bset).Get(), get_fn_ptr<15>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline unsigned int Qpolynomial::dim(DimType type) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_dim
  unsigned int res =  isl_qpolynomial_dim((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Qpolynomial Qpolynomial::dropDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_drop_dims
  isl_qpolynomial * res =  isl_qpolynomial_drop_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_drop_dims returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Val Qpolynomial::eval(const Point &pnt) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  Point _cast_pnt = pnt.asPoint();
  // Call isl_qpolynomial_eval
  isl_val * res =  isl_qpolynomial_eval((self).Give(), (_cast_pnt).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_eval returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Stat Qpolynomial::foreachTerm(const std::function<isl_stat(isl_term *, void *)> && fn, void * user) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_foreach_term
  isl_stat res =  isl_qpolynomial_foreach_term((self).Get(), get_fn_ptr<16>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline Val Qpolynomial::getConstantVal() const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_get_constant_val
  isl_val * res =  isl_qpolynomial_get_constant_val((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_get_constant_val returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Space Qpolynomial::getDomainSpace() const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_get_domain_space
  isl_space * res =  isl_qpolynomial_get_domain_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_get_domain_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Qpolynomial::getSpace() const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_get_space
  isl_space * res =  isl_qpolynomial_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Qpolynomial Qpolynomial::gist(const Set &context) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_qpolynomial_gist
  isl_qpolynomial * res =  isl_qpolynomial_gist((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_gist returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::gistParams(const Set &context) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_qpolynomial_gist_params
  isl_qpolynomial * res =  isl_qpolynomial_gist_params((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_gist_params returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::homogenize() const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_homogenize
  isl_qpolynomial * res =  isl_qpolynomial_homogenize((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_homogenize returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::insertDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_insert_dims
  isl_qpolynomial * res =  isl_qpolynomial_insert_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_insert_dims returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Bool Qpolynomial::involvesDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_involves_dims
  isl_bool res =  isl_qpolynomial_involves_dims((self).Get(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Qpolynomial::isInfty() const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_is_infty
  isl_bool res =  isl_qpolynomial_is_infty((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Qpolynomial::isNan() const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_is_nan
  isl_bool res =  isl_qpolynomial_is_nan((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Qpolynomial::isNeginfty() const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_is_neginfty
  isl_bool res =  isl_qpolynomial_is_neginfty((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Qpolynomial::isZero() const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_is_zero
  isl_bool res =  isl_qpolynomial_is_zero((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Qpolynomial Qpolynomial::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_move_dims
  isl_qpolynomial * res =  isl_qpolynomial_move_dims((self).Give(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_move_dims returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::mul(const Qpolynomial &qp2) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  Qpolynomial _cast_qp2 = qp2.asQpolynomial();
  // Call isl_qpolynomial_mul
  isl_qpolynomial * res =  isl_qpolynomial_mul((self).Give(), (_cast_qp2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_mul returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::neg() const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_neg
  isl_qpolynomial * res =  isl_qpolynomial_neg((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_neg returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Bool Qpolynomial::plainIsEqual(const Qpolynomial &qp2) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  Qpolynomial _cast_qp2 = qp2.asQpolynomial();
  // Call isl_qpolynomial_plain_is_equal
  isl_bool res =  isl_qpolynomial_plain_is_equal((self).Get(), (_cast_qp2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Qpolynomial Qpolynomial::pow(unsigned int power) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_pow
  isl_qpolynomial * res =  isl_qpolynomial_pow((self).Give(), power);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_pow returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::projectDomainOnParams() const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_project_domain_on_params
  isl_qpolynomial * res =  isl_qpolynomial_project_domain_on_params((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_project_domain_on_params returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::scaleVal(const Val &v) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_qpolynomial_scale_val
  isl_qpolynomial * res =  isl_qpolynomial_scale_val((self).Give(), (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_scale_val returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::setDimName(DimType type, unsigned int pos, std::string s) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_set_dim_name
  isl_qpolynomial * res =  isl_qpolynomial_set_dim_name((self).Give(), (enum isl_dim_type)type, pos, s.c_str());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_set_dim_name returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline int Qpolynomial::sgn() const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  // Call isl_qpolynomial_sgn
  int res =  isl_qpolynomial_sgn((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Qpolynomial Qpolynomial::sub(const Qpolynomial &qp2) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  Qpolynomial _cast_qp2 = qp2.asQpolynomial();
  // Call isl_qpolynomial_sub
  isl_qpolynomial * res =  isl_qpolynomial_sub((self).Give(), (_cast_qp2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_sub returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::substitute(DimType type, unsigned int first, unsigned int n, std::unique_ptr<Qpolynomial> * subs) const {
  ctx.lock();
  Qpolynomial self = asQpolynomial();
  // Prepare arguments
  isl_qpolynomial * _subs = nullptr;
  // Call isl_qpolynomial_substitute
  isl_qpolynomial * res =  isl_qpolynomial_substitute((self).Give(), (enum isl_dim_type)type, first, n, (subs) ? &_subs : nullptr);
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
    handleError("isl_qpolynomial_substitute returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_Qpolynomial_IMPL_H
