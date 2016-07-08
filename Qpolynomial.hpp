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

#include <cassert>

namespace isl {

inline isl_qpolynomial *Qpolynomial::GetCopy() const {
  return isl_qpolynomial_copy((isl_qpolynomial *)This);
}
inline Qpolynomial &Qpolynomial::operator=(const Qpolynomial &Other) {
  isl_qpolynomial *New = Other.GetCopy();
  ctx = Other.Context();
  isl_qpolynomial_free((isl_qpolynomial *)This);
  This = New;
  return *this;
}
inline Qpolynomial Qpolynomial::zeroOnDomain(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_qpolynomial *That = isl_qpolynomial_zero_on_domain((dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_zero_on_domain returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}

inline Qpolynomial Qpolynomial::oneOnDomain(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_qpolynomial *That = isl_qpolynomial_one_on_domain((dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_one_on_domain returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}

inline Qpolynomial Qpolynomial::inftyOnDomain(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_qpolynomial *That = isl_qpolynomial_infty_on_domain((dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_infty_on_domain returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}

inline Qpolynomial Qpolynomial::neginftyOnDomain(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_qpolynomial *That = isl_qpolynomial_neginfty_on_domain((dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_neginfty_on_domain returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}

inline Qpolynomial Qpolynomial::nanOnDomain(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_qpolynomial *That = isl_qpolynomial_nan_on_domain((dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_nan_on_domain returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}

inline Qpolynomial Qpolynomial::valOnDomain(const Space &space, const Val &val) {
  const Ctx &_ctx = val.Context();
  _ctx.lock();
  isl_qpolynomial *That = isl_qpolynomial_val_on_domain((space).GetCopy(), (val).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_val_on_domain returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}

inline Qpolynomial Qpolynomial::varOnDomain(const Space &dim, DimType type, unsigned int pos) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_qpolynomial *That = isl_qpolynomial_var_on_domain((dim).GetCopy(), (enum isl_dim_type)type, pos);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_var_on_domain returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}

inline Qpolynomial Qpolynomial::fromConstraint(const Constraint &c, DimType type, unsigned int pos) {
  const Ctx &_ctx = c.Context();
  _ctx.lock();
  isl_qpolynomial *That = isl_qpolynomial_from_constraint((c).GetCopy(), (enum isl_dim_type)type, pos);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_from_constraint returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}

inline Qpolynomial Qpolynomial::fromTerm(const Term &term) {
  const Ctx &_ctx = term.Context();
  _ctx.lock();
  isl_qpolynomial *That = isl_qpolynomial_from_term((term).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_qpolynomial_from_term returned a NULL pointer.");
  }

  return Qpolynomial(_ctx, That);
}

inline Qpolynomial Qpolynomial::fromAff(const Aff &aff) {
  const Ctx &_ctx = aff.Context();
  _ctx.lock();
  isl_qpolynomial *That = isl_qpolynomial_from_aff((aff).GetCopy());

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

inline Qpolynomial Qpolynomial::add(const Qpolynomial &qp2) const {
  ctx.lock();
  isl_qpolynomial * res =  isl_qpolynomial_add((*this).GetCopy(), (qp2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_add returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  isl_qpolynomial * res =  isl_qpolynomial_add_dims((*this).GetCopy(), (enum isl_dim_type)type, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_add_dims returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::alignParams(const Space &model) const {
  ctx.lock();
  isl_qpolynomial * res =  isl_qpolynomial_align_params((*this).GetCopy(), (model).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_align_params returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline int Qpolynomial::asPolynomialOnDomain(const BasicSet &bset, const std::function<int(isl_basic_set *, isl_qpolynomial *, void *)> && fn, void * user) const {
  ctx.lock();
  int res =  isl_qpolynomial_as_polynomial_on_domain((*this).Get(), (bset).Get(), get_fn_ptr<11>(fn), user);
  ctx.unlock();
  return res;
}

inline unsigned int Qpolynomial::dim(DimType type) const {
  ctx.lock();
  unsigned int res =  isl_qpolynomial_dim((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return res;
}

inline Qpolynomial Qpolynomial::dropDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_qpolynomial * res =  isl_qpolynomial_drop_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_drop_dims returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Val Qpolynomial::eval(const Point &pnt) const {
  ctx.lock();
  isl_val * res =  isl_qpolynomial_eval((*this).GetCopy(), (pnt).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_eval returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Stat Qpolynomial::foreachTerm(const std::function<isl_stat(isl_term *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_qpolynomial_foreach_term((*this).Get(), get_fn_ptr<12>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline Val Qpolynomial::getConstantVal() const {
  ctx.lock();
  isl_val * res =  isl_qpolynomial_get_constant_val((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_get_constant_val returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Space Qpolynomial::getDomainSpace() const {
  ctx.lock();
  isl_space * res =  isl_qpolynomial_get_domain_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_get_domain_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space Qpolynomial::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_qpolynomial_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Qpolynomial Qpolynomial::gist(const Set &context) const {
  ctx.lock();
  isl_qpolynomial * res =  isl_qpolynomial_gist((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_gist returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::gistParams(const Set &context) const {
  ctx.lock();
  isl_qpolynomial * res =  isl_qpolynomial_gist_params((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_gist_params returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::homogenize() const {
  ctx.lock();
  isl_qpolynomial * res =  isl_qpolynomial_homogenize((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_homogenize returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::insertDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_qpolynomial * res =  isl_qpolynomial_insert_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_insert_dims returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Bool Qpolynomial::involvesDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_bool res =  isl_qpolynomial_involves_dims((*this).Get(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  return (Bool)res;
}

inline Bool Qpolynomial::isInfty() const {
  ctx.lock();
  isl_bool res =  isl_qpolynomial_is_infty((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Qpolynomial::isNan() const {
  ctx.lock();
  isl_bool res =  isl_qpolynomial_is_nan((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Qpolynomial::isNeginfty() const {
  ctx.lock();
  isl_bool res =  isl_qpolynomial_is_neginfty((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Qpolynomial::isZero() const {
  ctx.lock();
  isl_bool res =  isl_qpolynomial_is_zero((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Qpolynomial Qpolynomial::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  isl_qpolynomial * res =  isl_qpolynomial_move_dims((*this).GetCopy(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_move_dims returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::mul(const Qpolynomial &qp2) const {
  ctx.lock();
  isl_qpolynomial * res =  isl_qpolynomial_mul((*this).GetCopy(), (qp2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_mul returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::neg() const {
  ctx.lock();
  isl_qpolynomial * res =  isl_qpolynomial_neg((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_neg returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Bool Qpolynomial::plainIsEqual(const Qpolynomial &qp2) const {
  ctx.lock();
  isl_bool res =  isl_qpolynomial_plain_is_equal((*this).Get(), (qp2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Qpolynomial Qpolynomial::pow(unsigned int power) const {
  ctx.lock();
  isl_qpolynomial * res =  isl_qpolynomial_pow((*this).GetCopy(), power);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_pow returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::projectDomainOnParams() const {
  ctx.lock();
  isl_qpolynomial * res =  isl_qpolynomial_project_domain_on_params((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_project_domain_on_params returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::scaleVal(const Val &v) const {
  ctx.lock();
  isl_qpolynomial * res =  isl_qpolynomial_scale_val((*this).GetCopy(), (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_scale_val returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::setDimName(DimType type, unsigned int pos, std::string s) const {
  ctx.lock();
  isl_qpolynomial * res =  isl_qpolynomial_set_dim_name((*this).GetCopy(), (enum isl_dim_type)type, pos, s.c_str());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_set_dim_name returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline int Qpolynomial::sgn() const {
  ctx.lock();
  int res =  isl_qpolynomial_sgn((*this).Get());
  ctx.unlock();
  return res;
}

inline Qpolynomial Qpolynomial::sub(const Qpolynomial &qp2) const {
  ctx.lock();
  isl_qpolynomial * res =  isl_qpolynomial_sub((*this).GetCopy(), (qp2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_sub returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

inline Qpolynomial Qpolynomial::substitute(DimType type, unsigned int first, unsigned int n, std::unique_ptr<Qpolynomial> * subs) const {
  ctx.lock();
  isl_qpolynomial * _subs = nullptr;
  isl_qpolynomial * res =  isl_qpolynomial_substitute((*this).GetCopy(), (enum isl_dim_type)type, first, n, (subs) ? &_subs : nullptr);
  if(subs) {
  if (ctx.hasError()) {
    handleError("subs became a NULL pointer.");
  }
    Qpolynomial _tmp_subs = Qpolynomial(ctx, _subs);
    subs->reset(new Qpolynomial(_tmp_subs));
  }
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_qpolynomial_substitute returned a NULL pointer.");
  }
  return Qpolynomial(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_Qpolynomial_IMPL_H
