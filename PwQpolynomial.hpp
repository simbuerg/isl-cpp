#ifndef ISL_CXX_PwQpolynomial_IMPL_H
#define ISL_CXX_PwQpolynomial_IMPL_H

#include "isl/PwQpolynomial.h"

#include "isl/Point.hpp"
#include "isl/Printer.hpp"
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
  Ctx _ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_pw_qpolynomial *That = isl_pw_qpolynomial_zero((_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_qpolynomial_zero returned a NULL pointer.");
  }

  return PwQpolynomial(_ctx, That);
}

inline PwQpolynomial PwQpolynomial::alloc(const Set &set, const Qpolynomial &qp) {
  Ctx _ctx = qp.Context();
  _ctx.lock();
  Set _cast_set = set.asSet();
  Qpolynomial _cast_qp = qp.asQpolynomial();
  isl_pw_qpolynomial *That = isl_pw_qpolynomial_alloc((_cast_set).Give(), (_cast_qp).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_qpolynomial_alloc returned a NULL pointer.");
  }

  return PwQpolynomial(_ctx, That);
}

inline PwQpolynomial PwQpolynomial::fromQpolynomial(const Qpolynomial &qp) {
  Ctx _ctx = qp.Context();
  _ctx.lock();
  Qpolynomial _cast_qp = qp.asQpolynomial();
  isl_pw_qpolynomial *That = isl_pw_qpolynomial_from_qpolynomial((_cast_qp).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_qpolynomial_from_qpolynomial returned a NULL pointer.");
  }

  return PwQpolynomial(_ctx, That);
}

inline PwQpolynomial PwQpolynomial::fromPwAff(const PwAff &pwaff) {
  Ctx _ctx = pwaff.Context();
  _ctx.lock();
  PwAff _cast_pwaff = pwaff.asPwAff();
  isl_pw_qpolynomial *That = isl_pw_qpolynomial_from_pw_aff((_cast_pwaff).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_qpolynomial_from_pw_aff returned a NULL pointer.");
  }

  return PwQpolynomial(_ctx, That);
}

inline PwQpolynomial PwQpolynomial::readFromStr(const Ctx &ctx, std::string str) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_pw_qpolynomial *That = isl_pw_qpolynomial_read_from_str((ctx.Get()), str.c_str());
  ctx.unlock();

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
inline std::string PwQpolynomial::toStr(isl::Format F) const {
  Printer p = Printer::toStr(ctx);
  p = p.setOutputFormat(F);
  p = p.printPwQpolynomial(*this);
  return p.getStr();
}

inline PwQpolynomial PwQpolynomial::asPwQpolynomial() const {
  return PwQpolynomial(GetCopy());
}

inline PwQpolynomial PwQpolynomial::add(const PwQpolynomial &pwqp2) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  PwQpolynomial _cast_pwqp2 = pwqp2.asPwQpolynomial();
  // Call isl_pw_qpolynomial_add
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_add((self).Give(), (_cast_pwqp2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_add returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline PwQpolynomial PwQpolynomial::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_add_dims
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_add_dims((self).Give(), (enum isl_dim_type)type, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_add_dims returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline PwQpolynomial PwQpolynomial::addDisjoint(const PwQpolynomial &pwqp2) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  PwQpolynomial _cast_pwqp2 = pwqp2.asPwQpolynomial();
  // Call isl_pw_qpolynomial_add_disjoint
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_add_disjoint((self).Give(), (_cast_pwqp2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_add_disjoint returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline PwQpolynomialFold PwQpolynomial::bound(Fold type, int * tight) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_bound
  isl_pw_qpolynomial_fold * res =  isl_pw_qpolynomial_bound((self).Give(), (enum isl_fold)type, tight);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_bound returned a NULL pointer.");
  }
  return PwQpolynomialFold(res);
}

inline PwQpolynomial PwQpolynomial::coalesce() const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_coalesce
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_coalesce((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_coalesce returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline unsigned int PwQpolynomial::dim(DimType type) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_dim
  unsigned int res =  isl_pw_qpolynomial_dim((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Set PwQpolynomial::domain() const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_domain
  isl_set * res =  isl_pw_qpolynomial_domain((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_domain returned a NULL pointer.");
  }
  return Set(res);
}

inline PwQpolynomial PwQpolynomial::dropDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_drop_dims
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_drop_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_drop_dims returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline Val PwQpolynomial::eval(const Point &pnt) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  Point _cast_pnt = pnt.asPoint();
  // Call isl_pw_qpolynomial_eval
  isl_val * res =  isl_pw_qpolynomial_eval((self).Give(), (_cast_pnt).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_eval returned a NULL pointer.");
  }
  return Val(res);
}

inline PwQpolynomial PwQpolynomial::fixVal(DimType type, unsigned int n, const Val &v) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_pw_qpolynomial_fix_val
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_fix_val((self).Give(), (enum isl_dim_type)type, n, (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_fix_val returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline Stat PwQpolynomial::foreachLiftedPiece(const std::function<isl_stat(isl_set *, isl_qpolynomial *, void *)> && fn, void * user) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_foreach_lifted_piece
  isl_stat res =  isl_pw_qpolynomial_foreach_lifted_piece((self).Get(), get_fn_ptr<11>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline Stat PwQpolynomial::foreachPiece(const std::function<isl_stat(isl_set *, isl_qpolynomial *, void *)> && fn, void * user) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_foreach_piece
  isl_stat res =  isl_pw_qpolynomial_foreach_piece((self).Get(), get_fn_ptr<12>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline Space PwQpolynomial::getDomainSpace() const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_get_domain_space
  isl_space * res =  isl_pw_qpolynomial_get_domain_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_get_domain_space returned a NULL pointer.");
  }
  return Space(res);
}

inline Space PwQpolynomial::getSpace() const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_get_space
  isl_space * res =  isl_pw_qpolynomial_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_get_space returned a NULL pointer.");
  }
  return Space(res);
}

inline PwQpolynomial PwQpolynomial::gist(const Set &context) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_pw_qpolynomial_gist
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_gist((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_gist returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline PwQpolynomial PwQpolynomial::gistParams(const Set &context) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_pw_qpolynomial_gist_params
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_gist_params((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_gist_params returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline int PwQpolynomial::hasEqualSpace(const PwQpolynomial &pwqp2) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  PwQpolynomial _cast_pwqp2 = pwqp2.asPwQpolynomial();
  // Call isl_pw_qpolynomial_has_equal_space
  int res =  isl_pw_qpolynomial_has_equal_space((self).Get(), (_cast_pwqp2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline PwQpolynomial PwQpolynomial::insertDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_insert_dims
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_insert_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_insert_dims returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline PwQpolynomial PwQpolynomial::intersectDomain(const Set &set) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_pw_qpolynomial_intersect_domain
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_intersect_domain((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_intersect_domain returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline PwQpolynomial PwQpolynomial::intersectParams(const Set &set) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_pw_qpolynomial_intersect_params
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_intersect_params((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_intersect_params returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline Bool PwQpolynomial::involvesDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_involves_dims
  isl_bool res =  isl_pw_qpolynomial_involves_dims((self).Get(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool PwQpolynomial::isZero() const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_is_zero
  isl_bool res =  isl_pw_qpolynomial_is_zero((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Val PwQpolynomial::max() const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_max
  isl_val * res =  isl_pw_qpolynomial_max((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_max returned a NULL pointer.");
  }
  return Val(res);
}

inline Val PwQpolynomial::min() const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_min
  isl_val * res =  isl_pw_qpolynomial_min((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_min returned a NULL pointer.");
  }
  return Val(res);
}

inline PwQpolynomial PwQpolynomial::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_move_dims
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_move_dims((self).Give(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_move_dims returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline PwQpolynomial PwQpolynomial::mul(const PwQpolynomial &pwqp2) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  PwQpolynomial _cast_pwqp2 = pwqp2.asPwQpolynomial();
  // Call isl_pw_qpolynomial_mul
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_mul((self).Give(), (_cast_pwqp2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_mul returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline PwQpolynomial PwQpolynomial::neg() const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_neg
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_neg((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_neg returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline Bool PwQpolynomial::plainIsEqual(const PwQpolynomial &pwqp2) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  PwQpolynomial _cast_pwqp2 = pwqp2.asPwQpolynomial();
  // Call isl_pw_qpolynomial_plain_is_equal
  isl_bool res =  isl_pw_qpolynomial_plain_is_equal((self).Get(), (_cast_pwqp2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline PwQpolynomial PwQpolynomial::pow(unsigned int exponent) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_pow
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_pow((self).Give(), exponent);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_pow returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline PwQpolynomial PwQpolynomial::projectDomainOnParams() const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_project_domain_on_params
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_project_domain_on_params((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_project_domain_on_params returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline PwQpolynomial PwQpolynomial::resetDomainSpace(const Space &dim) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  Space _cast_dim = dim.asSpace();
  // Call isl_pw_qpolynomial_reset_domain_space
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_reset_domain_space((self).Give(), (_cast_dim).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_reset_domain_space returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline PwQpolynomial PwQpolynomial::scaleVal(const Val &v) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_pw_qpolynomial_scale_val
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_scale_val((self).Give(), (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_scale_val returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline PwQpolynomial PwQpolynomial::setDimName(DimType type, unsigned int pos, std::string s) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_set_dim_name
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_set_dim_name((self).Give(), (enum isl_dim_type)type, pos, s.c_str());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_set_dim_name returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline PwQpolynomial PwQpolynomial::splitDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_split_dims
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_split_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_split_dims returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline PwQpolynomial PwQpolynomial::splitPeriods(int max_periods) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_split_periods
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_split_periods((self).Give(), max_periods);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_split_periods returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline PwQpolynomial PwQpolynomial::sub(const PwQpolynomial &pwqp2) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  PwQpolynomial _cast_pwqp2 = pwqp2.asPwQpolynomial();
  // Call isl_pw_qpolynomial_sub
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_sub((self).Give(), (_cast_pwqp2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_sub returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

inline PwQpolynomial PwQpolynomial::toPolynomial(int sign) const {
  ctx.lock();
  PwQpolynomial self = asPwQpolynomial();
  // Prepare arguments
  // Call isl_pw_qpolynomial_to_polynomial
  isl_pw_qpolynomial * res =  isl_pw_qpolynomial_to_polynomial((self).Give(), sign);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_pw_qpolynomial_to_polynomial returned a NULL pointer.");
  }
  return PwQpolynomial(res);
}

} // namespace isl
#endif //ISL_CXX_PwQpolynomial_IMPL_H
