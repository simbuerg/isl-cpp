#ifndef ISL_CXX_PwQpolynomial_IMPL_H
#define ISL_CXX_PwQpolynomial_IMPL_H

#include "isl/PwQpolynomial.h"

#include "isl/Point.hpp"
#include "isl/PwAff.hpp"
#include "isl/PwQpolynomialFold.hpp"
#include "isl/Qpolynomial.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/Val.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
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
inline isl_pw_qpolynomial *PwQpolynomial::GetCopy() const {
  return isl_pw_qpolynomial_copy((isl_pw_qpolynomial *)This);
}
inline PwQpolynomial &PwQpolynomial::operator=(const PwQpolynomial &Other) {
  isl_pw_qpolynomial *New = Other.GetCopy();
  isl_pw_qpolynomial_free((isl_pw_qpolynomial *)This);
  This = New;
  return *this;
}
inline PwQpolynomial PwQpolynomial::zero(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_pw_qpolynomial *That = isl_pw_qpolynomial_zero((dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_qpolynomial_zero returned a NULL pointer.");
  }

  return PwQpolynomial(_ctx, That);
}

inline PwQpolynomial PwQpolynomial::alloc(const Set &set, const Qpolynomial &qp) {
  const Ctx &_ctx = qp.Context();
  _ctx.lock();
  isl_pw_qpolynomial *That = isl_pw_qpolynomial_alloc((set).GetCopy(), (qp).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_qpolynomial_alloc returned a NULL pointer.");
  }

  return PwQpolynomial(_ctx, That);
}

inline PwQpolynomial PwQpolynomial::fromQpolynomial(const Qpolynomial &qp) {
  const Ctx &_ctx = qp.Context();
  _ctx.lock();
  isl_pw_qpolynomial *That = isl_pw_qpolynomial_from_qpolynomial((qp).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_qpolynomial_from_qpolynomial returned a NULL pointer.");
  }

  return PwQpolynomial(_ctx, That);
}

inline PwQpolynomial PwQpolynomial::fromPwAff(const PwAff &pwaff) {
  const Ctx &_ctx = pwaff.Context();
  _ctx.lock();
  isl_pw_qpolynomial *That = isl_pw_qpolynomial_from_pw_aff((pwaff).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_qpolynomial_from_pw_aff returned a NULL pointer.");
  }

  return PwQpolynomial(_ctx, That);
}

inline PwQpolynomial PwQpolynomial::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_pw_qpolynomial *That = isl_pw_qpolynomial_read_from_str((ctx.Get()), str.c_str());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_qpolynomial_read_from_str returned a NULL pointer.");
  }

  return PwQpolynomial(_ctx, That);
}
inline PwQpolynomial::~PwQpolynomial() {
  isl_pw_qpolynomial_free((isl_pw_qpolynomial *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_pw_qpolynomial *PwQpolynomial::Give() {
  isl_pw_qpolynomial *res = (isl_pw_qpolynomial *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_pw_qpolynomial *PwQpolynomial::Get() const {  return (isl_pw_qpolynomial *)This;
}


inline PwQpolynomial PwQpolynomial::add(const PwQpolynomial &pwqp2) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_add((*this).GetCopy(), (pwqp2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_add returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline PwQpolynomial PwQpolynomial::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_add_dims((*this).GetCopy(), (enum isl_dim_type)type, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_add_dims returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline PwQpolynomial PwQpolynomial::addDisjoint(const PwQpolynomial &pwqp2) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_add_disjoint((*this).GetCopy(), (pwqp2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_add_disjoint returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline PwQpolynomialFold PwQpolynomial::bound(Fold type, int * tight) const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_bound((*this).GetCopy(), (enum isl_fold)type, tight);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_bound returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline PwQpolynomial PwQpolynomial::coalesce() const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_coalesce((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_coalesce returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline unsigned int PwQpolynomial::dim(DimType type) const {
  ctx.lock();
  unsigned int res =  isl_pw_qpolynomial_dim((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return res;
}

inline Set PwQpolynomial::domain() const {
  ctx.lock();
  isl_set * res =  isl_pw_qpolynomial_domain((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_domain returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline PwQpolynomial PwQpolynomial::dropDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_drop_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_drop_dims returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline Val PwQpolynomial::eval(const Point &pnt) const {
  ctx.lock();
  isl_val * res =  isl_pw_qpolynomial_eval((*this).GetCopy(), (pnt).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_eval returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline PwQpolynomial PwQpolynomial::fixVal(DimType type, unsigned int n, const Val &v) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_fix_val((*this).GetCopy(), (enum isl_dim_type)type, n, (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fix_val returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline Stat PwQpolynomial::foreachLiftedPiece(const std::function<isl_stat(isl_set *, isl_qpolynomial *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_pw_qpolynomial_foreach_lifted_piece((*this).Get(), get_fn_ptr<7>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline Stat PwQpolynomial::foreachPiece(const std::function<isl_stat(isl_set *, isl_qpolynomial *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_pw_qpolynomial_foreach_piece((*this).Get(), get_fn_ptr<8>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline Space PwQpolynomial::getDomainSpace() const {
  ctx.lock();
  isl_space * res =  isl_pw_qpolynomial_get_domain_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_get_domain_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space PwQpolynomial::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_pw_qpolynomial_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline PwQpolynomial PwQpolynomial::gist(const Set &context) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_gist((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_gist returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline PwQpolynomial PwQpolynomial::gistParams(const Set &context) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_gist_params((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_gist_params returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline int PwQpolynomial::hasEqualSpace(const PwQpolynomial &pwqp2) const {
  ctx.lock();
  int res =  isl_pw_qpolynomial_has_equal_space((*this).Get(), (pwqp2).Get());
  ctx.unlock();
  return res;
}

inline PwQpolynomial PwQpolynomial::insertDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_insert_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_insert_dims returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline PwQpolynomial PwQpolynomial::intersectDomain(const Set &set) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_intersect_domain((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_intersect_domain returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline PwQpolynomial PwQpolynomial::intersectParams(const Set &set) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_intersect_params((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_intersect_params returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline Bool PwQpolynomial::involvesDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_bool res =  isl_pw_qpolynomial_involves_dims((*this).Get(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  return (Bool)res;
}

inline Bool PwQpolynomial::isZero() const {
  ctx.lock();
  isl_bool res =  isl_pw_qpolynomial_is_zero((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Val PwQpolynomial::max() const {
  ctx.lock();
  isl_val * res =  isl_pw_qpolynomial_max((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_max returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Val PwQpolynomial::min() const {
  ctx.lock();
  isl_val * res =  isl_pw_qpolynomial_min((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_min returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline PwQpolynomial PwQpolynomial::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_move_dims((*this).GetCopy(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_move_dims returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline PwQpolynomial PwQpolynomial::mul(const PwQpolynomial &pwqp2) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_mul((*this).GetCopy(), (pwqp2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_mul returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline PwQpolynomial PwQpolynomial::neg() const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_neg((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_neg returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline Bool PwQpolynomial::plainIsEqual(const PwQpolynomial &pwqp2) const {
  ctx.lock();
  isl_bool res =  isl_pw_qpolynomial_plain_is_equal((*this).Get(), (pwqp2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline PwQpolynomial PwQpolynomial::pow(unsigned int exponent) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_pow((*this).GetCopy(), exponent);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_pow returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline PwQpolynomial PwQpolynomial::projectDomainOnParams() const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_project_domain_on_params((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_project_domain_on_params returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline PwQpolynomial PwQpolynomial::resetDomainSpace(const Space &dim) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_reset_domain_space((*this).GetCopy(), (dim).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_reset_domain_space returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline PwQpolynomial PwQpolynomial::scaleVal(const Val &v) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_scale_val((*this).GetCopy(), (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_scale_val returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline PwQpolynomial PwQpolynomial::setDimName(DimType type, unsigned int pos, std::string s) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_set_dim_name((*this).GetCopy(), (enum isl_dim_type)type, pos, s.c_str());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_set_dim_name returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline PwQpolynomial PwQpolynomial::splitDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_split_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_split_dims returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline PwQpolynomial PwQpolynomial::splitPeriods(int max_periods) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_split_periods((*this).GetCopy(), max_periods);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_split_periods returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline PwQpolynomial PwQpolynomial::sub(const PwQpolynomial &pwqp2) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_sub((*this).GetCopy(), (pwqp2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_sub returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

inline PwQpolynomial PwQpolynomial::toPolynomial(int sign) const {
  ctx.lock();
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_to_polynomial((*this).GetCopy(), sign);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_to_polynomial returned a NULL pointer.");
  }
  return PwQpolynomial(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_PwQpolynomial_IMPL_H
