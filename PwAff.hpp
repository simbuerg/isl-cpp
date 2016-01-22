#ifndef ISL_CXX_PwAff_IMPL_H
#define ISL_CXX_PwAff_IMPL_H

#include "isl/PwAff.h"

#include "isl/Aff.hpp"
#include "isl/Id.hpp"
#include "isl/LocalSpace.hpp"
#include "isl/MultiAff.hpp"
#include "isl/MultiPwAff.hpp"
#include "isl/PwMultiAff.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/Val.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/UnionPwAff.hpp"
#include "isl/aff.h"
#include "isl/set.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_pw_aff *PwAff::GetCopy() const {
  return isl_pw_aff_copy((isl_pw_aff *)This);
}
inline PwAff &PwAff::operator=(const PwAff &Other) {
  isl_pw_aff *New = Other.GetCopy();
  isl_pw_aff_free((isl_pw_aff *)This);
  This = New;
  return *this;
}
inline PwAff PwAff::fromAff(const Aff &aff) {
  const Ctx &_ctx = aff.Context();
  _ctx.lock();
  isl_pw_aff *That = isl_pw_aff_from_aff((aff).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_aff_from_aff returned a NULL pointer.");
  }

  return PwAff(_ctx, That);
}

inline PwAff PwAff::empty(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_pw_aff *That = isl_pw_aff_empty((dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_aff_empty returned a NULL pointer.");
  }

  return PwAff(_ctx, That);
}

inline PwAff PwAff::alloc(const Set &set, const Aff &aff) {
  const Ctx &_ctx = aff.Context();
  _ctx.lock();
  isl_pw_aff *That = isl_pw_aff_alloc((set).GetCopy(), (aff).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_aff_alloc returned a NULL pointer.");
  }

  return PwAff(_ctx, That);
}

inline PwAff PwAff::zeroOnDomain(const LocalSpace &ls) {
  const Ctx &_ctx = ls.Context();
  _ctx.lock();
  isl_pw_aff *That = isl_pw_aff_zero_on_domain((ls).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_aff_zero_on_domain returned a NULL pointer.");
  }

  return PwAff(_ctx, That);
}

inline PwAff PwAff::varOnDomain(const LocalSpace &ls, DimType type, unsigned int pos) {
  const Ctx &_ctx = ls.Context();
  _ctx.lock();
  isl_pw_aff *That = isl_pw_aff_var_on_domain((ls).GetCopy(), (enum isl_dim_type)type, pos);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_aff_var_on_domain returned a NULL pointer.");
  }

  return PwAff(_ctx, That);
}

inline PwAff PwAff::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_pw_aff *That = isl_pw_aff_read_from_str((ctx.Get()), str.c_str());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_pw_aff_read_from_str returned a NULL pointer.");
  }

  return PwAff(_ctx, That);
}
inline PwAff::~PwAff() {
  isl_pw_aff_free((isl_pw_aff *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_pw_aff *PwAff::Give() {
  isl_pw_aff *res = (isl_pw_aff *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_pw_aff *PwAff::Get() const {  return (isl_pw_aff *)This;
}




inline PwAff PwAff::add(const PwAff &pwaff2) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_add((*this).GetCopy(), (pwaff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_add returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_add_dims((*this).GetCopy(), (enum isl_dim_type)type, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_add_dims returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::alignParams(const Space &model) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_align_params((*this).GetCopy(), (model).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_align_params returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::ceil() const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_ceil((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_ceil returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::coalesce() const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_coalesce((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_coalesce returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::cond(const PwAff &pwaff_true, const PwAff &pwaff_false) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_cond((*this).GetCopy(), (pwaff_true).GetCopy(), (pwaff_false).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_cond returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline unsigned int PwAff::dim(DimType type) const {
  ctx.lock();
  unsigned int res =  isl_pw_aff_dim((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return res;
}

inline PwAff PwAff::div(const PwAff &pa2) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_div((*this).GetCopy(), (pa2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_div returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Set PwAff::domain() const {
  ctx.lock();
  isl_set * res =  isl_pw_aff_domain((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_domain returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline PwAff PwAff::dropDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_drop_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_drop_dims returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Set PwAff::eqSet(const PwAff &pwaff2) const {
  ctx.lock();
  isl_set * res =  isl_pw_aff_eq_set((*this).GetCopy(), (pwaff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_eq_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline PwAff PwAff::floor() const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_floor((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_floor returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Stat PwAff::foreachPiece(const std::function<isl_stat(isl_set *, isl_aff *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_pw_aff_foreach_piece((*this).Get(), get_fn_ptr<5>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline PwAff PwAff::fromRange() const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_from_range((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_from_range returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Set PwAff::geSet(const PwAff &pwaff2) const {
  ctx.lock();
  isl_set * res =  isl_pw_aff_ge_set((*this).GetCopy(), (pwaff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_ge_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Id PwAff::getDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_id * res =  isl_pw_aff_get_dim_id((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_get_dim_id returned a NULL pointer.");
  }
  return Id(ctx, res);
}

inline std::string PwAff::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  const char * res =  isl_pw_aff_get_dim_name((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_pw_aff_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Space PwAff::getDomainSpace() const {
  ctx.lock();
  isl_space * res =  isl_pw_aff_get_domain_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_get_domain_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Space PwAff::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_pw_aff_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline PwAff PwAff::gist(const Set &context) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_gist((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_gist returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::gistParams(const Set &context) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_gist_params((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_gist_params returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Set PwAff::gtSet(const PwAff &pwaff2) const {
  ctx.lock();
  isl_set * res =  isl_pw_aff_gt_set((*this).GetCopy(), (pwaff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_gt_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Bool PwAff::hasDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_bool res =  isl_pw_aff_has_dim_id((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  return (Bool)res;
}

inline Bool PwAff::hasTupleId(DimType type) const {
  ctx.lock();
  isl_bool res =  isl_pw_aff_has_tuple_id((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return (Bool)res;
}

inline PwAff PwAff::insertDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_insert_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_insert_dims returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::intersectDomain(const Set &set) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_intersect_domain((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_intersect_domain returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::intersectParams(const Set &set) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_intersect_params((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_intersect_params returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Bool PwAff::involvesDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_bool res =  isl_pw_aff_involves_dims((*this).Get(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  return (Bool)res;
}

inline Bool PwAff::isCst() const {
  ctx.lock();
  isl_bool res =  isl_pw_aff_is_cst((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool PwAff::isEmpty() const {
  ctx.lock();
  isl_bool res =  isl_pw_aff_is_empty((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline int PwAff::isEqual(const PwAff &pa2) const {
  ctx.lock();
  int res =  isl_pw_aff_is_equal((*this).Get(), (pa2).Get());
  ctx.unlock();
  return res;
}

inline Set PwAff::leSet(const PwAff &pwaff2) const {
  ctx.lock();
  isl_set * res =  isl_pw_aff_le_set((*this).GetCopy(), (pwaff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_le_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set PwAff::ltSet(const PwAff &pwaff2) const {
  ctx.lock();
  isl_set * res =  isl_pw_aff_lt_set((*this).GetCopy(), (pwaff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_lt_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline PwAff PwAff::max(const PwAff &pwaff2) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_max((*this).GetCopy(), (pwaff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_max returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::min(const PwAff &pwaff2) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_min((*this).GetCopy(), (pwaff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_min returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::modVal(const Val &mod) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_mod_val((*this).GetCopy(), (mod).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_mod_val returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_move_dims((*this).GetCopy(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_move_dims returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::mul(const PwAff &pwaff2) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_mul((*this).GetCopy(), (pwaff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_mul returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline int PwAff::nPiece() const {
  ctx.lock();
  int res =  isl_pw_aff_n_piece((*this).Get());
  ctx.unlock();
  return res;
}

inline Set PwAff::neSet(const PwAff &pwaff2) const {
  ctx.lock();
  isl_set * res =  isl_pw_aff_ne_set((*this).GetCopy(), (pwaff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_ne_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline PwAff PwAff::neg() const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_neg((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_neg returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Set PwAff::nonZeroSet() const {
  ctx.lock();
  isl_set * res =  isl_pw_aff_non_zero_set((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_non_zero_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set PwAff::nonnegSet() const {
  ctx.lock();
  isl_set * res =  isl_pw_aff_nonneg_set((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_nonneg_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set PwAff::params() const {
  ctx.lock();
  isl_set * res =  isl_pw_aff_params((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_params returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline PwAff PwAff::pullbackMultiAff(const MultiAff &ma) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_pullback_multi_aff((*this).GetCopy(), (ma).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_pullback_multi_aff returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::pullbackMultiPwAff(const MultiPwAff &mpa) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_pullback_multi_pw_aff((*this).GetCopy(), (mpa).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_pullback_multi_pw_aff returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::pullbackPwMultiAff(const PwMultiAff &pma) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_pullback_pw_multi_aff((*this).GetCopy(), (pma).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_pullback_pw_multi_aff returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::scaleDownVal(const Val &f) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_scale_down_val((*this).GetCopy(), (f).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_scale_down_val returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::scaleVal(const Val &v) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_scale_val((*this).GetCopy(), (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_scale_val returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::setDimId(DimType type, unsigned int pos, const Id &id) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_set_dim_id((*this).GetCopy(), (enum isl_dim_type)type, pos, (id).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_set_dim_id returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::setTupleId(DimType type, const Id &id) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_set_tuple_id((*this).GetCopy(), (enum isl_dim_type)type, (id).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_set_tuple_id returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::sub(const PwAff &pwaff2) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_sub((*this).GetCopy(), (pwaff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_sub returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::tdivQ(const PwAff &pa2) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_tdiv_q((*this).GetCopy(), (pa2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_tdiv_q returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::tdivR(const PwAff &pa2) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_tdiv_r((*this).GetCopy(), (pa2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_tdiv_r returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::unionAdd(const PwAff &pwaff2) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_union_add((*this).GetCopy(), (pwaff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_union_add returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::unionMax(const PwAff &pwaff2) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_union_max((*this).GetCopy(), (pwaff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_union_max returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff PwAff::unionMin(const PwAff &pwaff2) const {
  ctx.lock();
  isl_pw_aff * res =  isl_pw_aff_union_min((*this).GetCopy(), (pwaff2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_union_min returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Set PwAff::zeroSet() const {
  ctx.lock();
  isl_set * res =  isl_pw_aff_zero_set((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_pw_aff_zero_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_PwAff_IMPL_H
