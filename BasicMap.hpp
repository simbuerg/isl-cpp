#ifndef ISL_CXX_BasicMap_IMPL_H
#define ISL_CXX_BasicMap_IMPL_H

#include "isl/BasicMap.h"

#include "isl/Aff.hpp"
#include "isl/BasicSet.hpp"
#include "isl/Constraint.hpp"
#include "isl/Id.hpp"
#include "isl/LocalSpace.hpp"
#include "isl/Mat.hpp"
#include "isl/MultiAff.hpp"
#include "isl/PwMultiAff.hpp"
#include "isl/Qpolynomial.hpp"
#include "isl/Space.hpp"
#include "isl/Val.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/Map.hpp"
#include "isl/Stat.h"
#include "isl/constraint.h"
#include <string>

#include <cassert>

namespace isl {

inline isl_basic_map *BasicMap::GetCopy() const {
  return isl_basic_map_copy((isl_basic_map *)This);
}
inline BasicMap &BasicMap::operator=(const BasicMap &Other) {
  isl_basic_map *New = Other.GetCopy();
  ctx = Other.Context();
  isl_basic_map_free((isl_basic_map *)This);
  This = New;
  return *this;
}
inline BasicMap BasicMap::lessAt(const Space &dim, unsigned int pos) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_basic_map *That = isl_basic_map_less_at((dim).GetCopy(), pos);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_less_at returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::moreAt(const Space &dim, unsigned int pos) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_basic_map *That = isl_basic_map_more_at((dim).GetCopy(), pos);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_more_at returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::empty(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_basic_map *That = isl_basic_map_empty((dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_empty returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::natUniverse(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_basic_map *That = isl_basic_map_nat_universe((dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_nat_universe returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::fromBasicSet(const BasicSet &bset, const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_basic_map *That = isl_basic_map_from_basic_set((bset).GetCopy(), (dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_from_basic_set returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_basic_map *That = isl_basic_map_read_from_str((ctx.Get()), str.c_str());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_read_from_str returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::fromDomain(const BasicSet &bset) {
  const Ctx &_ctx = bset.Context();
  _ctx.lock();
  isl_basic_map *That = isl_basic_map_from_domain((bset).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_from_domain returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::fromRange(const BasicSet &bset) {
  const Ctx &_ctx = bset.Context();
  _ctx.lock();
  isl_basic_map *That = isl_basic_map_from_range((bset).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_from_range returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::fromDomainAndRange(const BasicSet &domain, const BasicSet &range) {
  const Ctx &_ctx = range.Context();
  _ctx.lock();
  isl_basic_map *That = isl_basic_map_from_domain_and_range((domain).GetCopy(), (range).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_from_domain_and_range returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::fromConstraintMatrices(const Space &dim, const Mat &eq, const Mat &ineq, DimType c1, DimType c2, DimType c3, DimType c4, DimType c5) {
  const Ctx &_ctx = ineq.Context();
  _ctx.lock();
  isl_basic_map *That = isl_basic_map_from_constraint_matrices((dim).GetCopy(), (eq).GetCopy(), (ineq).GetCopy(), (enum isl_dim_type)c1, (enum isl_dim_type)c2, (enum isl_dim_type)c3, (enum isl_dim_type)c4, (enum isl_dim_type)c5);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_from_constraint_matrices returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::fromAff(const Aff &aff) {
  const Ctx &_ctx = aff.Context();
  _ctx.lock();
  isl_basic_map *That = isl_basic_map_from_aff((aff).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_from_aff returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::fromMultiAff(const MultiAff &maff) {
  const Ctx &_ctx = maff.Context();
  _ctx.lock();
  isl_basic_map *That = isl_basic_map_from_multi_aff((maff).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_from_multi_aff returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::fromConstraint(const Constraint &constraint) {
  const Ctx &_ctx = constraint.Context();
  _ctx.lock();
  isl_basic_map *That = isl_basic_map_from_constraint((constraint).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_from_constraint returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::fromQpolynomial(const Qpolynomial &qp) {
  const Ctx &_ctx = qp.Context();
  _ctx.lock();
  isl_basic_map *That = isl_basic_map_from_qpolynomial((qp).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_from_qpolynomial returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}
inline BasicMap::~BasicMap() {
  isl_basic_map_free((isl_basic_map *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_basic_map *BasicMap::Give() {
  isl_basic_map *res = (isl_basic_map *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_basic_map *BasicMap::Get() const {  return (isl_basic_map *)This;
}

inline BasicMap BasicMap::addConstraint(const Constraint &constraint) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_add_constraint((*this).GetCopy(), (constraint).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_add_constraint returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_add_dims((*this).GetCopy(), (enum isl_dim_type)type, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_add_dims returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::affineHull() const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_affine_hull((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_affine_hull returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::alignParams(const Space &model) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_align_params((*this).GetCopy(), (model).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_align_params returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::applyDomain(const BasicMap &bmap2) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_apply_domain((*this).GetCopy(), (bmap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_apply_domain returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::applyRange(const BasicMap &bmap2) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_apply_range((*this).GetCopy(), (bmap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_apply_range returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline Bool BasicMap::canCurry() const {
  ctx.lock();
  isl_bool res =  isl_basic_map_can_curry((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool BasicMap::canUncurry() const {
  ctx.lock();
  isl_bool res =  isl_basic_map_can_uncurry((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool BasicMap::canZip() const {
  ctx.lock();
  isl_bool res =  isl_basic_map_can_zip((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Map BasicMap::computeDivs() const {
  ctx.lock();
  isl_map * res =  isl_basic_map_compute_divs((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_compute_divs returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline BasicMap BasicMap::curry() const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_curry((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_curry returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicSet BasicMap::deltas() const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_map_deltas((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_deltas returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicMap BasicMap::deltasMap() const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_deltas_map((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_deltas_map returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::detectEqualities() const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_detect_equalities((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_detect_equalities returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline unsigned int BasicMap::dim(DimType type) const {
  ctx.lock();
  unsigned int res =  isl_basic_map_dim((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return res;
}

inline BasicSet BasicMap::domain() const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_map_domain((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_domain returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicMap BasicMap::domainMap() const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_domain_map((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_domain_map returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::domainProduct(const BasicMap &bmap2) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_domain_product((*this).GetCopy(), (bmap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_domain_product returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::dropConstraintsInvolvingDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_drop_constraints_involving_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_drop_constraints_involving_dims returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::eliminate(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_eliminate((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_eliminate returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline Mat BasicMap::equalitiesMatrix(DimType c1, DimType c2, DimType c3, DimType c4, DimType c5) const {
  ctx.lock();
  isl_mat * res =  isl_basic_map_equalities_matrix((*this).Get(), (enum isl_dim_type)c1, (enum isl_dim_type)c2, (enum isl_dim_type)c3, (enum isl_dim_type)c4, (enum isl_dim_type)c5);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_equalities_matrix returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline BasicMap BasicMap::equate(DimType type1, int pos1, DimType type2, int pos2) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_equate((*this).GetCopy(), (enum isl_dim_type)type1, pos1, (enum isl_dim_type)type2, pos2);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_equate returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::fixVal(DimType type, unsigned int pos, const Val &v) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_fix_val((*this).GetCopy(), (enum isl_dim_type)type, pos, (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_fix_val returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::flatProduct(const BasicMap &bmap2) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_flat_product((*this).GetCopy(), (bmap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_flat_product returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::flatRangeProduct(const BasicMap &bmap2) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_flat_range_product((*this).GetCopy(), (bmap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_flat_range_product returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::flatten() const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_flatten((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_flatten returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::flattenDomain() const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_flatten_domain((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_flatten_domain returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::flattenRange() const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_flatten_range((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_flatten_range returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline Stat BasicMap::foreachConstraint(const std::function<isl_stat(isl_constraint *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_basic_map_foreach_constraint((*this).Get(), get_fn_ptr<1>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline std::string BasicMap::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  const char * res =  isl_basic_map_get_dim_name((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_basic_map_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Aff BasicMap::getDiv(int pos) const {
  ctx.lock();
  isl_aff * res =  isl_basic_map_get_div((*this).Get(), pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_get_div returned a NULL pointer.");
  }
  return Aff(ctx, res);
}

inline LocalSpace BasicMap::getLocalSpace() const {
  ctx.lock();
  isl_local_space * res =  isl_basic_map_get_local_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_get_local_space returned a NULL pointer.");
  }
  return LocalSpace(ctx, res);
}

inline Space BasicMap::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_basic_map_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline std::string BasicMap::getTupleName(DimType type) const {
  ctx.lock();
  const char * res =  isl_basic_map_get_tuple_name((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_basic_map_get_tuple_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline BasicMap BasicMap::gist(const BasicMap &context) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_gist((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_gist returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline Bool BasicMap::hasDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_bool res =  isl_basic_map_has_dim_id((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  return (Bool)res;
}

inline Mat BasicMap::inequalitiesMatrix(DimType c1, DimType c2, DimType c3, DimType c4, DimType c5) const {
  ctx.lock();
  isl_mat * res =  isl_basic_map_inequalities_matrix((*this).Get(), (enum isl_dim_type)c1, (enum isl_dim_type)c2, (enum isl_dim_type)c3, (enum isl_dim_type)c4, (enum isl_dim_type)c5);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_inequalities_matrix returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline BasicMap BasicMap::insertDims(DimType type, unsigned int pos, unsigned int n) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_insert_dims((*this).GetCopy(), (enum isl_dim_type)type, pos, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_insert_dims returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::intersect(const BasicMap &bmap2) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_intersect((*this).GetCopy(), (bmap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_intersect returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::intersectDomain(const BasicSet &bset) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_intersect_domain((*this).GetCopy(), (bset).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_intersect_domain returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::intersectRange(const BasicSet &bset) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_intersect_range((*this).GetCopy(), (bset).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_intersect_range returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline Bool BasicMap::involvesDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_bool res =  isl_basic_map_involves_dims((*this).Get(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  return (Bool)res;
}

inline Bool BasicMap::isDisjoint(const BasicMap &bmap2) const {
  ctx.lock();
  isl_bool res =  isl_basic_map_is_disjoint((*this).Get(), (bmap2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool BasicMap::isEmpty() const {
  ctx.lock();
  isl_bool res =  isl_basic_map_is_empty((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool BasicMap::isEqual(const BasicMap &bmap2) const {
  ctx.lock();
  isl_bool res =  isl_basic_map_is_equal((*this).Get(), (bmap2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline int BasicMap::isRational() const {
  ctx.lock();
  int res =  isl_basic_map_is_rational((*this).Get());
  ctx.unlock();
  return res;
}

inline Bool BasicMap::isStrictSubset(const BasicMap &bmap2) const {
  ctx.lock();
  isl_bool res =  isl_basic_map_is_strict_subset((*this).Get(), (bmap2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool BasicMap::isSubset(const BasicMap &bmap2) const {
  ctx.lock();
  isl_bool res =  isl_basic_map_is_subset((*this).Get(), (bmap2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool BasicMap::isUniverse() const {
  ctx.lock();
  isl_bool res =  isl_basic_map_is_universe((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Map BasicMap::lexmax() const {
  ctx.lock();
  isl_map * res =  isl_basic_map_lexmax((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_lexmax returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map BasicMap::lexmin() const {
  ctx.lock();
  isl_map * res =  isl_basic_map_lexmin((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_lexmin returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline PwMultiAff BasicMap::lexminPwMultiAff() const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_basic_map_lexmin_pw_multi_aff((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_lexmin_pw_multi_aff returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline BasicMap BasicMap::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_move_dims((*this).GetCopy(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_move_dims returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline int BasicMap::nConstraint() const {
  ctx.lock();
  int res =  isl_basic_map_n_constraint((*this).Get());
  ctx.unlock();
  return res;
}

inline unsigned int BasicMap::nDiv() const {
  ctx.lock();
  unsigned int res =  isl_basic_map_n_div((*this).Get());
  ctx.unlock();
  return res;
}

inline unsigned int BasicMap::nIn() const {
  ctx.lock();
  unsigned int res =  isl_basic_map_n_in((*this).Get());
  ctx.unlock();
  return res;
}

inline unsigned int BasicMap::nOut() const {
  ctx.lock();
  unsigned int res =  isl_basic_map_n_out((*this).Get());
  ctx.unlock();
  return res;
}

inline unsigned int BasicMap::nParam() const {
  ctx.lock();
  unsigned int res =  isl_basic_map_n_param((*this).Get());
  ctx.unlock();
  return res;
}

inline BasicMap BasicMap::orderGe(DimType type1, int pos1, DimType type2, int pos2) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_order_ge((*this).GetCopy(), (enum isl_dim_type)type1, pos1, (enum isl_dim_type)type2, pos2);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_order_ge returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::orderGt(DimType type1, int pos1, DimType type2, int pos2) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_order_gt((*this).GetCopy(), (enum isl_dim_type)type1, pos1, (enum isl_dim_type)type2, pos2);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_order_gt returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::product(const BasicMap &bmap2) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_product((*this).GetCopy(), (bmap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_product returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::projectOut(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_project_out((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_project_out returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicSet BasicMap::range() const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_map_range((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_range returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicMap BasicMap::rangeMap() const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_range_map((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_range_map returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::rangeProduct(const BasicMap &bmap2) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_range_product((*this).GetCopy(), (bmap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_range_product returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::removeDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_remove_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_remove_dims returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::removeDivs() const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_remove_divs((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_remove_divs returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::removeDivsInvolvingDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_remove_divs_involving_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_remove_divs_involving_dims returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::reverse() const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_reverse((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_reverse returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::sample() const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_sample((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_sample returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::setDimName(DimType type, unsigned int pos, std::string s) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_set_dim_name((*this).GetCopy(), (enum isl_dim_type)type, pos, s.c_str());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_set_dim_name returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::setTupleId(DimType type, const Id &id) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_set_tuple_id((*this).GetCopy(), (enum isl_dim_type)type, (id).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_set_tuple_id returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline BasicMap BasicMap::setTupleName(DimType type, std::string s) const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_set_tuple_name((*this).GetCopy(), (enum isl_dim_type)type, s.c_str());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_set_tuple_name returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline unsigned int BasicMap::totalDim() const {
  ctx.lock();
  unsigned int res =  isl_basic_map_total_dim((*this).Get());
  ctx.unlock();
  return res;
}

inline BasicMap BasicMap::uncurry() const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_map_uncurry((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_uncurry returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline Map BasicMap::union_(const BasicMap &bmap2) const {
  ctx.lock();
  isl_map * res =  isl_basic_map_union((*this).GetCopy(), (bmap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_union returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline BasicSet BasicMap::wrap() const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_map_wrap((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_map_wrap returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_BasicMap_IMPL_H
