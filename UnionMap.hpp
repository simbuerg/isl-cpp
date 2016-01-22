#ifndef ISL_CXX_UnionMap_IMPL_H
#define ISL_CXX_UnionMap_IMPL_H

#include "isl/UnionMap.h"

#include "isl/BasicMap.hpp"
#include "isl/Map.hpp"
#include "isl/MultiUnionPwAff.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/UnionPwMultiAff.hpp"
#include "isl/UnionPwQpolynomialFold.hpp"
#include "isl/UnionSet.hpp"
#include "isl/Val.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/map.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_union_map *UnionMap::GetCopy() const {
  return isl_union_map_copy((isl_union_map *)This);
}
inline UnionMap &UnionMap::operator=(const UnionMap &Other) {
  isl_union_map *New = Other.GetCopy();
  isl_union_map_free((isl_union_map *)This);
  This = New;
  return *this;
}
inline UnionMap UnionMap::fromUnionPwMultiAff(const UnionPwMultiAff &upma) {
  const Ctx &_ctx = upma.Context();
  _ctx.lock();
  isl_union_map *That = isl_union_map_from_union_pw_multi_aff((upma).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_map_from_union_pw_multi_aff returned a NULL pointer.");
  }

  return UnionMap(_ctx, That);
}

inline UnionMap UnionMap::fromMultiUnionPwAff(const MultiUnionPwAff &mupa) {
  const Ctx &_ctx = mupa.Context();
  _ctx.lock();
  isl_union_map *That = isl_union_map_from_multi_union_pw_aff((mupa).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_map_from_multi_union_pw_aff returned a NULL pointer.");
  }

  return UnionMap(_ctx, That);
}

inline UnionMap UnionMap::fromBasicMap(const BasicMap &bmap) {
  const Ctx &_ctx = bmap.Context();
  _ctx.lock();
  isl_union_map *That = isl_union_map_from_basic_map((bmap).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_map_from_basic_map returned a NULL pointer.");
  }

  return UnionMap(_ctx, That);
}

inline UnionMap UnionMap::fromMap(const Map &map) {
  const Ctx &_ctx = map.Context();
  _ctx.lock();
  isl_union_map *That = isl_union_map_from_map((map).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_map_from_map returned a NULL pointer.");
  }

  return UnionMap(_ctx, That);
}

inline UnionMap UnionMap::empty(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_union_map *That = isl_union_map_empty((dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_map_empty returned a NULL pointer.");
  }

  return UnionMap(_ctx, That);
}

inline UnionMap UnionMap::universe(const UnionMap &umap) {
  const Ctx &_ctx = umap.Context();
  _ctx.lock();
  isl_union_map *That = isl_union_map_universe((umap).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_map_universe returned a NULL pointer.");
  }

  return UnionMap(_ctx, That);
}

inline UnionMap UnionMap::fromDomain(const UnionSet &uset) {
  const Ctx &_ctx = uset.Context();
  _ctx.lock();
  isl_union_map *That = isl_union_map_from_domain((uset).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_map_from_domain returned a NULL pointer.");
  }

  return UnionMap(_ctx, That);
}

inline UnionMap UnionMap::fromRange(const UnionSet &uset) {
  const Ctx &_ctx = uset.Context();
  _ctx.lock();
  isl_union_map *That = isl_union_map_from_range((uset).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_map_from_range returned a NULL pointer.");
  }

  return UnionMap(_ctx, That);
}

inline UnionMap UnionMap::fromDomainAndRange(const UnionSet &domain, const UnionSet &range) {
  const Ctx &_ctx = range.Context();
  _ctx.lock();
  isl_union_map *That = isl_union_map_from_domain_and_range((domain).GetCopy(), (range).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_map_from_domain_and_range returned a NULL pointer.");
  }

  return UnionMap(_ctx, That);
}

inline UnionMap UnionMap::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_union_map *That = isl_union_map_read_from_str((ctx.Get()), str.c_str());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_map_read_from_str returned a NULL pointer.");
  }

  return UnionMap(_ctx, That);
}
inline UnionMap::~UnionMap() {
  isl_union_map_free((isl_union_map *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_union_map *UnionMap::Give() {
  isl_union_map *res = (isl_union_map *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_union_map *UnionMap::Get() const {  return (isl_union_map *)This;
}


inline UnionMap UnionMap::affineHull() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_affine_hull((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_affine_hull returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::alignParams(const Space &model) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_align_params((*this).GetCopy(), (model).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_align_params returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::applyDomain(const UnionMap &umap2) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_apply_domain((*this).GetCopy(), (umap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_apply_domain returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::applyRange(const UnionMap &umap2) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_apply_range((*this).GetCopy(), (umap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_apply_range returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionPwQpolynomialFold UnionMap::applyUnionPwQpolynomialFold(const UnionPwQpolynomialFold &upwf, int * tight) const {
  ctx.lock();
  isl_union_pw_qpolynomial_fold * res =  isl_union_map_apply_union_pw_qpolynomial_fold((*this).GetCopy(), (upwf).GetCopy(), tight);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_apply_union_pw_qpolynomial_fold returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(ctx, res);
}

inline UnionMap UnionMap::coalesce() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_coalesce((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_coalesce returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::computeDivs() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_compute_divs((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_compute_divs returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline int UnionMap::computeFlow(const UnionMap &must_source, const UnionMap &may_source, const UnionMap &schedule, std::unique_ptr<UnionMap> * must_dep, std::unique_ptr<UnionMap> * may_dep, std::unique_ptr<UnionMap> * must_no_source, std::unique_ptr<UnionMap> * may_no_source) const {
  ctx.lock();
  isl_union_map * _must_dep = nullptr;
  isl_union_map * _may_dep = nullptr;
  isl_union_map * _must_no_source = nullptr;
  isl_union_map * _may_no_source = nullptr;
  int res =  isl_union_map_compute_flow((*this).GetCopy(), (must_source).GetCopy(), (may_source).GetCopy(), (schedule).GetCopy(), (must_dep) ? &_must_dep : nullptr, (may_dep) ? &_may_dep : nullptr, (must_no_source) ? &_must_no_source : nullptr, (may_no_source) ? &_may_no_source : nullptr);
  if(must_dep) {
  if (ctx.hasError()) {
    handleError("must_dep became a NULL pointer.");
  }
    UnionMap _tmp_must_dep = UnionMap(ctx, _must_dep);
    must_dep->reset(new UnionMap(_tmp_must_dep));
  }
  if(may_dep) {
  if (ctx.hasError()) {
    handleError("may_dep became a NULL pointer.");
  }
    UnionMap _tmp_may_dep = UnionMap(ctx, _may_dep);
    may_dep->reset(new UnionMap(_tmp_may_dep));
  }
  if(must_no_source) {
  if (ctx.hasError()) {
    handleError("must_no_source became a NULL pointer.");
  }
    UnionMap _tmp_must_no_source = UnionMap(ctx, _must_no_source);
    must_no_source->reset(new UnionMap(_tmp_must_no_source));
  }
  if(may_no_source) {
  if (ctx.hasError()) {
    handleError("may_no_source became a NULL pointer.");
  }
    UnionMap _tmp_may_no_source = UnionMap(ctx, _may_no_source);
    may_no_source->reset(new UnionMap(_tmp_may_no_source));
  }
  ctx.unlock();
  return res;
}

inline int UnionMap::contains(const Space &dim) const {
  ctx.lock();
  int res =  isl_union_map_contains((*this).Get(), (dim).Get());
  ctx.unlock();
  return res;
}

inline UnionMap UnionMap::curry() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_curry((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_curry returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionSet UnionMap::deltas() const {
  ctx.lock();
  isl_union_set * res =  isl_union_map_deltas((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_deltas returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionMap UnionMap::detectEqualities() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_detect_equalities((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_detect_equalities returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionSet UnionMap::domain() const {
  ctx.lock();
  isl_union_set * res =  isl_union_map_domain((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_domain returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionMap UnionMap::domainFactorDomain() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_domain_factor_domain((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_domain_factor_domain returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::domainFactorRange() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_domain_factor_range((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_domain_factor_range returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::domainMap() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_domain_map((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_domain_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionPwMultiAff UnionMap::domainMapUnionPwMultiAff() const {
  ctx.lock();
  isl_union_pw_multi_aff * res =  isl_union_map_domain_map_union_pw_multi_aff((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_domain_map_union_pw_multi_aff returned a NULL pointer.");
  }
  return UnionPwMultiAff(ctx, res);
}

inline UnionMap UnionMap::domainProduct(const UnionMap &umap2) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_domain_product((*this).GetCopy(), (umap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_domain_product returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline Map UnionMap::extractMap(const Space &dim) const {
  ctx.lock();
  isl_map * res =  isl_union_map_extract_map((*this).Get(), (dim).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_extract_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline UnionMap UnionMap::factorDomain() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_factor_domain((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_factor_domain returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::factorRange() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_factor_range((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_factor_range returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::fixedPowerVal(const Val &exp) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_fixed_power_val((*this).GetCopy(), (exp).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_fixed_power_val returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline Stat UnionMap::foreachMap(const std::function<isl_stat(isl_map *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_union_map_foreach_map((*this).Get(), get_fn_ptr<20>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline Space UnionMap::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_union_map_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline UnionMap UnionMap::gist(const UnionMap &context) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_gist((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_gist returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::gistDomain(const UnionSet &uset) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_gist_domain((*this).GetCopy(), (uset).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_gist_domain returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::gistParams(const Set &set) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_gist_params((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_gist_params returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::gistRange(const UnionSet &uset) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_gist_range((*this).GetCopy(), (uset).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_gist_range returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::intersect(const UnionMap &umap2) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_intersect((*this).GetCopy(), (umap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_intersect returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::intersectDomain(const UnionSet &uset) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_intersect_domain((*this).GetCopy(), (uset).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_intersect_domain returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::intersectParams(const Set &set) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_intersect_params((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_intersect_params returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::intersectRange(const UnionSet &uset) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_intersect_range((*this).GetCopy(), (uset).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_intersect_range returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline Bool UnionMap::isBijective() const {
  ctx.lock();
  isl_bool res =  isl_union_map_is_bijective((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool UnionMap::isEmpty() const {
  ctx.lock();
  isl_bool res =  isl_union_map_is_empty((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool UnionMap::isEqual(const UnionMap &umap2) const {
  ctx.lock();
  isl_bool res =  isl_union_map_is_equal((*this).Get(), (umap2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool UnionMap::isInjective() const {
  ctx.lock();
  isl_bool res =  isl_union_map_is_injective((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool UnionMap::isSingleValued() const {
  ctx.lock();
  isl_bool res =  isl_union_map_is_single_valued((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool UnionMap::isStrictSubset(const UnionMap &umap2) const {
  ctx.lock();
  isl_bool res =  isl_union_map_is_strict_subset((*this).Get(), (umap2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool UnionMap::isSubset(const UnionMap &umap2) const {
  ctx.lock();
  isl_bool res =  isl_union_map_is_subset((*this).Get(), (umap2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline UnionMap UnionMap::lexGeUnionMap(const UnionMap &umap2) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_lex_ge_union_map((*this).GetCopy(), (umap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_lex_ge_union_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::lexGtUnionMap(const UnionMap &umap2) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_lex_gt_union_map((*this).GetCopy(), (umap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_lex_gt_union_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::lexLeUnionMap(const UnionMap &umap2) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_lex_le_union_map((*this).GetCopy(), (umap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_lex_le_union_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::lexLtUnionMap(const UnionMap &umap2) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_lex_lt_union_map((*this).GetCopy(), (umap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_lex_lt_union_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::lexmax() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_lexmax((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_lexmax returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::lexmin() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_lexmin((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_lexmin returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline int UnionMap::nMap() const {
  ctx.lock();
  int res =  isl_union_map_n_map((*this).Get());
  ctx.unlock();
  return res;
}

inline Set UnionMap::params() const {
  ctx.lock();
  isl_set * res =  isl_union_map_params((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_params returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline UnionMap UnionMap::polyhedralHull() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_polyhedral_hull((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_polyhedral_hull returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::power(int * exact) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_power((*this).GetCopy(), exact);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_power returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::product(const UnionMap &umap2) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_product((*this).GetCopy(), (umap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_product returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionSet UnionMap::range() const {
  ctx.lock();
  isl_union_set * res =  isl_union_map_range((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_range returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionMap UnionMap::rangeFactorDomain() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_range_factor_domain((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_range_factor_domain returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::rangeFactorRange() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_range_factor_range((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_range_factor_range returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::rangeMap() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_range_map((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_range_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::rangeProduct(const UnionMap &umap2) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_range_product((*this).GetCopy(), (umap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_range_product returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::reverse() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_reverse((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_reverse returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline BasicMap UnionMap::sample() const {
  ctx.lock();
  isl_basic_map * res =  isl_union_map_sample((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_sample returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline UnionMap UnionMap::subtract(const UnionMap &umap2) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_subtract((*this).GetCopy(), (umap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_subtract returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::subtractDomain(const UnionSet &dom) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_subtract_domain((*this).GetCopy(), (dom).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_subtract_domain returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::subtractRange(const UnionSet &dom) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_subtract_range((*this).GetCopy(), (dom).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_subtract_range returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::transitiveClosure(int * exact) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_transitive_closure((*this).GetCopy(), exact);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_transitive_closure returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::uncurry() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_uncurry((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_uncurry returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::union_(const UnionMap &umap2) const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_union((*this).GetCopy(), (umap2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_union returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionSet UnionMap::wrap() const {
  ctx.lock();
  isl_union_set * res =  isl_union_map_wrap((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_wrap returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionMap UnionMap::zip() const {
  ctx.lock();
  isl_union_map * res =  isl_union_map_zip((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_map_zip returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_UnionMap_IMPL_H
