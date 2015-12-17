#ifndef ISL_CXX_UnionMap_IMPL_H
#define ISL_CXX_UnionMap_IMPL_H

#include "isl/UnionMap.h"

#include "isl/BasicMap.hpp"
#include "isl/Map.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
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
inline UnionMap UnionMap::fromBasicMap(const BasicMap &bmap) {
  const Ctx &_ctx = bmap.Context();
  _ctx.lock();
  BasicMap _cast_bmap = bmap.asBasicMap();
  isl_union_map *That = isl_union_map_from_basic_map((_cast_bmap).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_map_from_basic_map returned a NULL pointer.");
  }

  return UnionMap(_ctx, That);
}

inline UnionMap UnionMap::fromMap(const Map &map) {
  const Ctx &_ctx = map.Context();
  _ctx.lock();
  Map _cast_map = map.asMap();
  isl_union_map *That = isl_union_map_from_map((_cast_map).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_map_from_map returned a NULL pointer.");
  }

  return UnionMap(_ctx, That);
}

inline UnionMap UnionMap::empty(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_union_map *That = isl_union_map_empty((_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_map_empty returned a NULL pointer.");
  }

  return UnionMap(_ctx, That);
}

inline UnionMap UnionMap::universe(const UnionMap &umap) {
  const Ctx &_ctx = umap.Context();
  _ctx.lock();
  UnionMap _cast_umap = umap.asUnionMap();
  isl_union_map *That = isl_union_map_universe((_cast_umap).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_map_universe returned a NULL pointer.");
  }

  return UnionMap(_ctx, That);
}

inline UnionMap UnionMap::fromDomain(const UnionSet &uset) {
  const Ctx &_ctx = uset.Context();
  _ctx.lock();
  UnionSet _cast_uset = uset.asUnionSet();
  isl_union_map *That = isl_union_map_from_domain((_cast_uset).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_map_from_domain returned a NULL pointer.");
  }

  return UnionMap(_ctx, That);
}

inline UnionMap UnionMap::fromRange(const UnionSet &uset) {
  const Ctx &_ctx = uset.Context();
  _ctx.lock();
  UnionSet _cast_uset = uset.asUnionSet();
  isl_union_map *That = isl_union_map_from_range((_cast_uset).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_map_from_range returned a NULL pointer.");
  }

  return UnionMap(_ctx, That);
}

inline UnionMap UnionMap::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_union_map *That = isl_union_map_read_from_str((ctx.Get()), str.c_str());
  ctx.unlock();

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

inline UnionMap UnionMap::asUnionMap() const {
  return UnionMap(ctx, GetCopy());
}

inline UnionMap UnionMap::affineHull() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_affine_hull
  isl_union_map * res =  isl_union_map_affine_hull((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_affine_hull returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::alignParams(const Space &model) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  Space _cast_model = model.asSpace();
  // Call isl_union_map_align_params
  isl_union_map * res =  isl_union_map_align_params((self).Give(), (_cast_model).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_align_params returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::applyDomain(const UnionMap &umap2) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionMap _cast_umap2 = umap2.asUnionMap();
  // Call isl_union_map_apply_domain
  isl_union_map * res =  isl_union_map_apply_domain((self).Give(), (_cast_umap2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_apply_domain returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::applyRange(const UnionMap &umap2) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionMap _cast_umap2 = umap2.asUnionMap();
  // Call isl_union_map_apply_range
  isl_union_map * res =  isl_union_map_apply_range((self).Give(), (_cast_umap2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_apply_range returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionPwQpolynomialFold UnionMap::applyUnionPwQpolynomialFold(const UnionPwQpolynomialFold &upwf, int * tight) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionPwQpolynomialFold _cast_upwf = upwf.asUnionPwQpolynomialFold();
  // Call isl_union_map_apply_union_pw_qpolynomial_fold
  isl_union_pw_qpolynomial_fold * res =  isl_union_map_apply_union_pw_qpolynomial_fold((self).Give(), (_cast_upwf).Give(), tight);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_apply_union_pw_qpolynomial_fold returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(ctx, res);
}

inline UnionMap UnionMap::coalesce() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_coalesce
  isl_union_map * res =  isl_union_map_coalesce((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_coalesce returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::computeDivs() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_compute_divs
  isl_union_map * res =  isl_union_map_compute_divs((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_compute_divs returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline int UnionMap::computeFlow(const UnionMap &must_source, const UnionMap &may_source, const UnionMap &schedule, std::unique_ptr<UnionMap> * must_dep, std::unique_ptr<UnionMap> * may_dep, std::unique_ptr<UnionMap> * must_no_source, std::unique_ptr<UnionMap> * may_no_source) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionMap _cast_must_source = must_source.asUnionMap();
  UnionMap _cast_may_source = may_source.asUnionMap();
  UnionMap _cast_schedule = schedule.asUnionMap();
  isl_union_map * _must_dep = nullptr;
  isl_union_map * _may_dep = nullptr;
  isl_union_map * _must_no_source = nullptr;
  isl_union_map * _may_no_source = nullptr;
  // Call isl_union_map_compute_flow
  int res =  isl_union_map_compute_flow((self).Give(), (_cast_must_source).Give(), (_cast_may_source).Give(), (_cast_schedule).Give(), (must_dep) ? &_must_dep : nullptr, (may_dep) ? &_may_dep : nullptr, (must_no_source) ? &_must_no_source : nullptr, (may_no_source) ? &_may_no_source : nullptr);
  // Handle result argument(s)
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
  // Handle return
  return res;
}

inline int UnionMap::contains(const Space &dim) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  Space _cast_dim = dim.asSpace();
  // Call isl_union_map_contains
  int res =  isl_union_map_contains((self).Get(), (_cast_dim).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline UnionMap UnionMap::curry() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_curry
  isl_union_map * res =  isl_union_map_curry((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_curry returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionSet UnionMap::deltas() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_deltas
  isl_union_set * res =  isl_union_map_deltas((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_deltas returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionMap UnionMap::detectEqualities() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_detect_equalities
  isl_union_map * res =  isl_union_map_detect_equalities((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_detect_equalities returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionSet UnionMap::domain() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_domain
  isl_union_set * res =  isl_union_map_domain((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_domain returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionMap UnionMap::domainMap() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_domain_map
  isl_union_map * res =  isl_union_map_domain_map((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_domain_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline Map UnionMap::extractMap(const Space &dim) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  Space _cast_dim = dim.asSpace();
  // Call isl_union_map_extract_map
  isl_map * res =  isl_union_map_extract_map((self).Get(), (_cast_dim).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_extract_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline UnionMap UnionMap::fixedPowerVal(const Val &exp) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  Val _cast_exp = exp.asVal();
  // Call isl_union_map_fixed_power_val
  isl_union_map * res =  isl_union_map_fixed_power_val((self).Give(), (_cast_exp).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_fixed_power_val returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline Stat UnionMap::foreachMap(const std::function<isl_stat(isl_map *, void *)> && fn, void * user) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_foreach_map
  isl_stat res =  isl_union_map_foreach_map((self).Get(), get_fn_ptr<24>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline Space UnionMap::getSpace() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_get_space
  isl_space * res =  isl_union_map_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline UnionMap UnionMap::gist(const UnionMap &context) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionMap _cast_context = context.asUnionMap();
  // Call isl_union_map_gist
  isl_union_map * res =  isl_union_map_gist((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_gist returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::gistDomain(const UnionSet &uset) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionSet _cast_uset = uset.asUnionSet();
  // Call isl_union_map_gist_domain
  isl_union_map * res =  isl_union_map_gist_domain((self).Give(), (_cast_uset).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_gist_domain returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::gistParams(const Set &set) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_union_map_gist_params
  isl_union_map * res =  isl_union_map_gist_params((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_gist_params returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::gistRange(const UnionSet &uset) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionSet _cast_uset = uset.asUnionSet();
  // Call isl_union_map_gist_range
  isl_union_map * res =  isl_union_map_gist_range((self).Give(), (_cast_uset).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_gist_range returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::intersect(const UnionMap &umap2) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionMap _cast_umap2 = umap2.asUnionMap();
  // Call isl_union_map_intersect
  isl_union_map * res =  isl_union_map_intersect((self).Give(), (_cast_umap2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_intersect returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::intersectDomain(const UnionSet &uset) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionSet _cast_uset = uset.asUnionSet();
  // Call isl_union_map_intersect_domain
  isl_union_map * res =  isl_union_map_intersect_domain((self).Give(), (_cast_uset).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_intersect_domain returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::intersectParams(const Set &set) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_union_map_intersect_params
  isl_union_map * res =  isl_union_map_intersect_params((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_intersect_params returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::intersectRange(const UnionSet &uset) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionSet _cast_uset = uset.asUnionSet();
  // Call isl_union_map_intersect_range
  isl_union_map * res =  isl_union_map_intersect_range((self).Give(), (_cast_uset).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_intersect_range returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline Bool UnionMap::isBijective() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_is_bijective
  isl_bool res =  isl_union_map_is_bijective((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool UnionMap::isEmpty() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_is_empty
  isl_bool res =  isl_union_map_is_empty((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool UnionMap::isEqual(const UnionMap &umap2) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionMap _cast_umap2 = umap2.asUnionMap();
  // Call isl_union_map_is_equal
  isl_bool res =  isl_union_map_is_equal((self).Get(), (_cast_umap2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool UnionMap::isInjective() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_is_injective
  isl_bool res =  isl_union_map_is_injective((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool UnionMap::isSingleValued() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_is_single_valued
  isl_bool res =  isl_union_map_is_single_valued((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool UnionMap::isStrictSubset(const UnionMap &umap2) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionMap _cast_umap2 = umap2.asUnionMap();
  // Call isl_union_map_is_strict_subset
  isl_bool res =  isl_union_map_is_strict_subset((self).Get(), (_cast_umap2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool UnionMap::isSubset(const UnionMap &umap2) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionMap _cast_umap2 = umap2.asUnionMap();
  // Call isl_union_map_is_subset
  isl_bool res =  isl_union_map_is_subset((self).Get(), (_cast_umap2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline UnionMap UnionMap::lexGeUnionMap(const UnionMap &umap2) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionMap _cast_umap2 = umap2.asUnionMap();
  // Call isl_union_map_lex_ge_union_map
  isl_union_map * res =  isl_union_map_lex_ge_union_map((self).Give(), (_cast_umap2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_lex_ge_union_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::lexGtUnionMap(const UnionMap &umap2) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionMap _cast_umap2 = umap2.asUnionMap();
  // Call isl_union_map_lex_gt_union_map
  isl_union_map * res =  isl_union_map_lex_gt_union_map((self).Give(), (_cast_umap2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_lex_gt_union_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::lexLeUnionMap(const UnionMap &umap2) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionMap _cast_umap2 = umap2.asUnionMap();
  // Call isl_union_map_lex_le_union_map
  isl_union_map * res =  isl_union_map_lex_le_union_map((self).Give(), (_cast_umap2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_lex_le_union_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::lexLtUnionMap(const UnionMap &umap2) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionMap _cast_umap2 = umap2.asUnionMap();
  // Call isl_union_map_lex_lt_union_map
  isl_union_map * res =  isl_union_map_lex_lt_union_map((self).Give(), (_cast_umap2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_lex_lt_union_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::lexmax() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_lexmax
  isl_union_map * res =  isl_union_map_lexmax((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_lexmax returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::lexmin() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_lexmin
  isl_union_map * res =  isl_union_map_lexmin((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_lexmin returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline int UnionMap::nMap() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_n_map
  int res =  isl_union_map_n_map((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Set UnionMap::params() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_params
  isl_set * res =  isl_union_map_params((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_params returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline UnionMap UnionMap::polyhedralHull() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_polyhedral_hull
  isl_union_map * res =  isl_union_map_polyhedral_hull((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_polyhedral_hull returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::power(int * exact) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_power
  isl_union_map * res =  isl_union_map_power((self).Give(), exact);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_power returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionSet UnionMap::range() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_range
  isl_union_set * res =  isl_union_map_range((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_range returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionMap UnionMap::rangeMap() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_range_map
  isl_union_map * res =  isl_union_map_range_map((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_range_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::reverse() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_reverse
  isl_union_map * res =  isl_union_map_reverse((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_reverse returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline BasicMap UnionMap::sample() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_sample
  isl_basic_map * res =  isl_union_map_sample((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_sample returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline UnionMap UnionMap::subtract(const UnionMap &umap2) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionMap _cast_umap2 = umap2.asUnionMap();
  // Call isl_union_map_subtract
  isl_union_map * res =  isl_union_map_subtract((self).Give(), (_cast_umap2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_subtract returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::subtractDomain(const UnionSet &dom) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionSet _cast_dom = dom.asUnionSet();
  // Call isl_union_map_subtract_domain
  isl_union_map * res =  isl_union_map_subtract_domain((self).Give(), (_cast_dom).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_subtract_domain returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::subtractRange(const UnionSet &dom) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionSet _cast_dom = dom.asUnionSet();
  // Call isl_union_map_subtract_range
  isl_union_map * res =  isl_union_map_subtract_range((self).Give(), (_cast_dom).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_subtract_range returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::transitiveClosure(int * exact) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_transitive_closure
  isl_union_map * res =  isl_union_map_transitive_closure((self).Give(), exact);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_transitive_closure returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::uncurry() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_uncurry
  isl_union_map * res =  isl_union_map_uncurry((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_uncurry returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionMap::union_(const UnionMap &umap2) const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  UnionMap _cast_umap2 = umap2.asUnionMap();
  // Call isl_union_map_union
  isl_union_map * res =  isl_union_map_union((self).Give(), (_cast_umap2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_union returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionSet UnionMap::wrap() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_wrap
  isl_union_set * res =  isl_union_map_wrap((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_wrap returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionMap UnionMap::zip() const {
  ctx.lock();
  UnionMap self = asUnionMap();
  // Prepare arguments
  // Call isl_union_map_zip
  isl_union_map * res =  isl_union_map_zip((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_map_zip returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_UnionMap_IMPL_H
