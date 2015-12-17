#ifndef ISL_CXX_Map_IMPL_H
#define ISL_CXX_Map_IMPL_H

#include "isl/Map.h"

#include "isl/Aff.hpp"
#include "isl/BasicMap.hpp"
#include "isl/Constraint.hpp"
#include "isl/Id.hpp"
#include "isl/MultiAff.hpp"
#include "isl/MultiPwAff.hpp"
#include "isl/PwAff.hpp"
#include "isl/PwMultiAff.hpp"
#include "isl/PwQpolynomialFold.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/Val.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/UnionMap.hpp"
#include "isl/map.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_map *Map::GetCopy() const {
  return isl_map_copy((isl_map *)This);
}
inline Map &Map::operator=(const Map &Other) {
  isl_map *New = Other.GetCopy();
  isl_map_free((isl_map *)This);
  This = New;
  return *this;
}
inline Map Map::fromPwAff(const PwAff &pwaff) {
  const Ctx &_ctx = pwaff.Context();
  _ctx.lock();
  PwAff _cast_pwaff = pwaff.asPwAff();
  isl_map *That = isl_map_from_pw_aff((_cast_pwaff).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_from_pw_aff returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_map *That = isl_map_read_from_str((ctx.Get()), str.c_str());
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_read_from_str returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::natUniverse(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_map *That = isl_map_nat_universe((_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_nat_universe returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::empty(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_map *That = isl_map_empty((_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_empty returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::lexLeFirst(const Space &dim, unsigned int n) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_map *That = isl_map_lex_le_first((_cast_dim).Give(), n);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_lex_le_first returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::lexLt(const Space &set_dim) {
  const Ctx &_ctx = set_dim.Context();
  _ctx.lock();
  Space _cast_set_dim = set_dim.asSpace();
  isl_map *That = isl_map_lex_lt((_cast_set_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_lex_lt returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::lexLe(const Space &set_dim) {
  const Ctx &_ctx = set_dim.Context();
  _ctx.lock();
  Space _cast_set_dim = set_dim.asSpace();
  isl_map *That = isl_map_lex_le((_cast_set_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_lex_le returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::lexGtFirst(const Space &dim, unsigned int n) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_map *That = isl_map_lex_gt_first((_cast_dim).Give(), n);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_lex_gt_first returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::lexGeFirst(const Space &dim, unsigned int n) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_map *That = isl_map_lex_ge_first((_cast_dim).Give(), n);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_lex_ge_first returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::lexGt(const Space &set_dim) {
  const Ctx &_ctx = set_dim.Context();
  _ctx.lock();
  Space _cast_set_dim = set_dim.asSpace();
  isl_map *That = isl_map_lex_gt((_cast_set_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_lex_gt returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::lexGe(const Space &set_dim) {
  const Ctx &_ctx = set_dim.Context();
  _ctx.lock();
  Space _cast_set_dim = set_dim.asSpace();
  isl_map *That = isl_map_lex_ge((_cast_set_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_lex_ge returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::fromBasicMap(const BasicMap &bmap) {
  const Ctx &_ctx = bmap.Context();
  _ctx.lock();
  BasicMap _cast_bmap = bmap.asBasicMap();
  isl_map *That = isl_map_from_basic_map((_cast_bmap).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_from_basic_map returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::fromDomain(const Set &set) {
  const Ctx &_ctx = set.Context();
  _ctx.lock();
  Set _cast_set = set.asSet();
  isl_map *That = isl_map_from_domain((_cast_set).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_from_domain returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::fromRange(const Set &set) {
  const Ctx &_ctx = set.Context();
  _ctx.lock();
  Set _cast_set = set.asSet();
  isl_map *That = isl_map_from_range((_cast_set).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_from_range returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::fromDomainAndRange(const Set &domain, const Set &range) {
  const Ctx &_ctx = range.Context();
  _ctx.lock();
  Set _cast_domain = domain.asSet();
  Set _cast_range = range.asSet();
  isl_map *That = isl_map_from_domain_and_range((_cast_domain).Give(), (_cast_range).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_from_domain_and_range returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::fromSet(const Set &set, const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Set _cast_set = set.asSet();
  Space _cast_dim = dim.asSpace();
  isl_map *That = isl_map_from_set((_cast_set).Give(), (_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_from_set returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::fromAff(const Aff &aff) {
  const Ctx &_ctx = aff.Context();
  _ctx.lock();
  Aff _cast_aff = aff.asAff();
  isl_map *That = isl_map_from_aff((_cast_aff).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_from_aff returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::fromMultiAff(const MultiAff &maff) {
  const Ctx &_ctx = maff.Context();
  _ctx.lock();
  MultiAff _cast_maff = maff.asMultiAff();
  isl_map *That = isl_map_from_multi_aff((_cast_maff).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_from_multi_aff returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::fromUnionMap(const UnionMap &umap) {
  const Ctx &_ctx = umap.Context();
  _ctx.lock();
  UnionMap _cast_umap = umap.asUnionMap();
  isl_map *That = isl_map_from_union_map((_cast_umap).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_from_union_map returned a NULL pointer.");
  }

  return Map(_ctx, That);
}
inline Map::~Map() {
  isl_map_free((isl_map *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_map *Map::Give() {
  isl_map *res = (isl_map *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_map *Map::Get() const {  return (isl_map *)This;
}

inline Map Map::asMap() const {
  return Map(ctx, GetCopy());
}

inline UnionMap Map::asUnionMap() const {
  return UnionMap(*this);
}

inline Map Map::addConstraint(const Constraint &constraint) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Constraint _cast_constraint = constraint.asConstraint();
  // Call isl_map_add_constraint
  isl_map * res =  isl_map_add_constraint((self).Give(), (_cast_constraint).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_add_constraint returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_add_dims
  isl_map * res =  isl_map_add_dims((self).Give(), (enum isl_dim_type)type, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_add_dims returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline BasicMap Map::affineHull() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_affine_hull
  isl_basic_map * res =  isl_map_affine_hull((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_affine_hull returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline Map Map::alignDivs() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_align_divs
  isl_map * res =  isl_map_align_divs((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_align_divs returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::alignParams(const Space &model) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Space _cast_model = model.asSpace();
  // Call isl_map_align_params
  isl_map * res =  isl_map_align_params((self).Give(), (_cast_model).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_align_params returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::applyDomain(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_apply_domain
  isl_map * res =  isl_map_apply_domain((self).Give(), (_cast_map2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_apply_domain returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline PwQpolynomialFold Map::applyPwQpolynomialFold(const PwQpolynomialFold &pwf, int * tight) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  PwQpolynomialFold _cast_pwf = pwf.asPwQpolynomialFold();
  // Call isl_map_apply_pw_qpolynomial_fold
  isl_pw_qpolynomial_fold * res =  isl_map_apply_pw_qpolynomial_fold((self).Give(), (_cast_pwf).Give(), tight);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_apply_pw_qpolynomial_fold returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline Map Map::applyRange(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_apply_range
  isl_map * res =  isl_map_apply_range((self).Give(), (_cast_map2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_apply_range returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Bool Map::canCurry() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_can_curry
  isl_bool res =  isl_map_can_curry((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Map::canUncurry() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_can_uncurry
  isl_bool res =  isl_map_can_uncurry((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Map::canZip() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_can_zip
  isl_bool res =  isl_map_can_zip((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Map Map::coalesce() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_coalesce
  isl_map * res =  isl_map_coalesce((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_coalesce returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::complement() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_complement
  isl_map * res =  isl_map_complement((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_complement returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::computeDivs() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_compute_divs
  isl_map * res =  isl_map_compute_divs((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_compute_divs returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline BasicMap Map::convexHull() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_convex_hull
  isl_basic_map * res =  isl_map_convex_hull((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_convex_hull returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline Map Map::curry() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_curry
  isl_map * res =  isl_map_curry((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_curry returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Set Map::deltas() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_deltas
  isl_set * res =  isl_map_deltas((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_deltas returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Map Map::deltasMap() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_deltas_map
  isl_map * res =  isl_map_deltas_map((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_deltas_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::detectEqualities() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_detect_equalities
  isl_map * res =  isl_map_detect_equalities((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_detect_equalities returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline unsigned int Map::dim(DimType type) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_dim
  unsigned int res =  isl_map_dim((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline PwAff Map::dimMax(int pos) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_dim_max
  isl_pw_aff * res =  isl_map_dim_max((self).Give(), pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_dim_max returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Set Map::domain() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_domain
  isl_set * res =  isl_map_domain((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_domain returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Map Map::domainMap() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_domain_map
  isl_map * res =  isl_map_domain_map((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_domain_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::domainProduct(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_domain_product
  isl_map * res =  isl_map_domain_product((self).Give(), (_cast_map2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_domain_product returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::dropConstraintsInvolvingDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_drop_constraints_involving_dims
  isl_map * res =  isl_map_drop_constraints_involving_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_drop_constraints_involving_dims returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::eliminate(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_eliminate
  isl_map * res =  isl_map_eliminate((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_eliminate returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::equate(DimType type1, int pos1, DimType type2, int pos2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_equate
  isl_map * res =  isl_map_equate((self).Give(), (enum isl_dim_type)type1, pos1, (enum isl_dim_type)type2, pos2);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_equate returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline int Map::findDimById(DimType type, const Id &id) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_map_find_dim_by_id
  int res =  isl_map_find_dim_by_id((self).Get(), (enum isl_dim_type)type, (_cast_id).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline int Map::findDimByName(DimType type, std::string name) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_find_dim_by_name
  int res =  isl_map_find_dim_by_name((self).Get(), (enum isl_dim_type)type, name.c_str());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Map Map::fixVal(DimType type, unsigned int pos, const Val &v) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_map_fix_val
  isl_map * res =  isl_map_fix_val((self).Give(), (enum isl_dim_type)type, pos, (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_fix_val returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::fixedPowerVal(const Val &exp) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Val _cast_exp = exp.asVal();
  // Call isl_map_fixed_power_val
  isl_map * res =  isl_map_fixed_power_val((self).Give(), (_cast_exp).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_fixed_power_val returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::flatDomainProduct(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_flat_domain_product
  isl_map * res =  isl_map_flat_domain_product((self).Give(), (_cast_map2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_flat_domain_product returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::flatProduct(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_flat_product
  isl_map * res =  isl_map_flat_product((self).Give(), (_cast_map2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_flat_product returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::flatRangeProduct(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_flat_range_product
  isl_map * res =  isl_map_flat_range_product((self).Give(), (_cast_map2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_flat_range_product returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::flatten() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_flatten
  isl_map * res =  isl_map_flatten((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_flatten returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::flattenDomain() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_flatten_domain
  isl_map * res =  isl_map_flatten_domain((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_flatten_domain returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::flattenRange() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_flatten_range
  isl_map * res =  isl_map_flatten_range((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_flatten_range returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::floordivVal(const Val &d) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Val _cast_d = d.asVal();
  // Call isl_map_floordiv_val
  isl_map * res =  isl_map_floordiv_val((self).Give(), (_cast_d).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_floordiv_val returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Stat Map::foreachBasicMap(const std::function<isl_stat(isl_basic_map *, void *)> && fn, void * user) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_foreach_basic_map
  isl_stat res =  isl_map_foreach_basic_map((self).Get(), get_fn_ptr<8>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline Id Map::getDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_get_dim_id
  isl_id * res =  isl_map_get_dim_id((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_get_dim_id returned a NULL pointer.");
  }
  return Id(ctx, res);
}

inline std::string Map::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_get_dim_name
  const char * res =  isl_map_get_dim_name((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_map_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Space Map::getSpace() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_get_space
  isl_space * res =  isl_map_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Id Map::getTupleId(DimType type) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_get_tuple_id
  isl_id * res =  isl_map_get_tuple_id((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_get_tuple_id returned a NULL pointer.");
  }
  return Id(ctx, res);
}

inline std::string Map::getTupleName(DimType type) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_get_tuple_name
  const char * res =  isl_map_get_tuple_name((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_map_get_tuple_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Map Map::gist(const Map &context) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_context = context.asMap();
  // Call isl_map_gist
  isl_map * res =  isl_map_gist((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_gist returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::gistBasicMap(const BasicMap &context) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  BasicMap _cast_context = context.asBasicMap();
  // Call isl_map_gist_basic_map
  isl_map * res =  isl_map_gist_basic_map((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_gist_basic_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::gistDomain(const Set &context) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_map_gist_domain
  isl_map * res =  isl_map_gist_domain((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_gist_domain returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::gistParams(const Set &context) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_map_gist_params
  isl_map * res =  isl_map_gist_params((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_gist_params returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::gistRange(const Set &context) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_map_gist_range
  isl_map * res =  isl_map_gist_range((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_gist_range returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Bool Map::hasDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_has_dim_id
  isl_bool res =  isl_map_has_dim_id((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Map::hasDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_has_dim_name
  isl_bool res =  isl_map_has_dim_name((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline int Map::hasEqualSpace(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_has_equal_space
  int res =  isl_map_has_equal_space((self).Get(), (_cast_map2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Bool Map::hasTupleId(DimType type) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_has_tuple_id
  isl_bool res =  isl_map_has_tuple_id((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Map::hasTupleName(DimType type) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_has_tuple_name
  isl_bool res =  isl_map_has_tuple_name((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Map Map::insertDims(DimType type, unsigned int pos, unsigned int n) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_insert_dims
  isl_map * res =  isl_map_insert_dims((self).Give(), (enum isl_dim_type)type, pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_insert_dims returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::intersect(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_intersect
  isl_map * res =  isl_map_intersect((self).Give(), (_cast_map2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_intersect returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::intersectDomain(const Set &set) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_map_intersect_domain
  isl_map * res =  isl_map_intersect_domain((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_intersect_domain returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::intersectParams(const Set &params) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Set _cast_params = params.asSet();
  // Call isl_map_intersect_params
  isl_map * res =  isl_map_intersect_params((self).Give(), (_cast_params).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_intersect_params returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::intersectRange(const Set &set) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_map_intersect_range
  isl_map * res =  isl_map_intersect_range((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_intersect_range returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Bool Map::involvesDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_involves_dims
  isl_bool res =  isl_map_involves_dims((self).Get(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Map::isBijective() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_is_bijective
  isl_bool res =  isl_map_is_bijective((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Map::isDisjoint(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_is_disjoint
  isl_bool res =  isl_map_is_disjoint((self).Get(), (_cast_map2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Map::isEmpty() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_is_empty
  isl_bool res =  isl_map_is_empty((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Map::isEqual(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_is_equal
  isl_bool res =  isl_map_is_equal((self).Get(), (_cast_map2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Map::isInjective() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_is_injective
  isl_bool res =  isl_map_is_injective((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Map::isSingleValued() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_is_single_valued
  isl_bool res =  isl_map_is_single_valued((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Map::isStrictSubset(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_is_strict_subset
  isl_bool res =  isl_map_is_strict_subset((self).Get(), (_cast_map2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Map::isSubset(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_is_subset
  isl_bool res =  isl_map_is_subset((self).Get(), (_cast_map2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline int Map::isTranslation() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_is_translation
  int res =  isl_map_is_translation((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Map Map::lexGeMap(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_lex_ge_map
  isl_map * res =  isl_map_lex_ge_map((self).Give(), (_cast_map2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_lex_ge_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::lexGtMap(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_lex_gt_map
  isl_map * res =  isl_map_lex_gt_map((self).Give(), (_cast_map2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_lex_gt_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::lexLeMap(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_lex_le_map
  isl_map * res =  isl_map_lex_le_map((self).Give(), (_cast_map2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_lex_le_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::lexLtMap(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_lex_lt_map
  isl_map * res =  isl_map_lex_lt_map((self).Give(), (_cast_map2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_lex_lt_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::lexmax() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_lexmax
  isl_map * res =  isl_map_lexmax((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_lexmax returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::lexmin() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_lexmin
  isl_map * res =  isl_map_lexmin((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_lexmin returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline PwMultiAff Map::lexminPwMultiAff() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_lexmin_pw_multi_aff
  isl_pw_multi_aff * res =  isl_map_lexmin_pw_multi_aff((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_lexmin_pw_multi_aff returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline Map Map::makeDisjoint() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_make_disjoint
  isl_map * res =  isl_map_make_disjoint((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_make_disjoint returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_move_dims
  isl_map * res =  isl_map_move_dims((self).Give(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_move_dims returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline unsigned int Map::nIn() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_n_in
  unsigned int res =  isl_map_n_in((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline unsigned int Map::nOut() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_n_out
  unsigned int res =  isl_map_n_out((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline unsigned int Map::nParam() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_n_param
  unsigned int res =  isl_map_n_param((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Map Map::oppose(DimType type1, int pos1, DimType type2, int pos2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_oppose
  isl_map * res =  isl_map_oppose((self).Give(), (enum isl_dim_type)type1, pos1, (enum isl_dim_type)type2, pos2);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_oppose returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::orderGt(DimType type1, int pos1, DimType type2, int pos2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_order_gt
  isl_map * res =  isl_map_order_gt((self).Give(), (enum isl_dim_type)type1, pos1, (enum isl_dim_type)type2, pos2);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_order_gt returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::orderLt(DimType type1, int pos1, DimType type2, int pos2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_order_lt
  isl_map * res =  isl_map_order_lt((self).Give(), (enum isl_dim_type)type1, pos1, (enum isl_dim_type)type2, pos2);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_order_lt returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Set Map::params() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_params
  isl_set * res =  isl_map_params((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_params returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Bool Map::plainIsEmpty() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_plain_is_empty
  isl_bool res =  isl_map_plain_is_empty((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Map::plainIsEqual(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_plain_is_equal
  isl_bool res =  isl_map_plain_is_equal((self).Get(), (_cast_map2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Map::plainIsInjective() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_plain_is_injective
  isl_bool res =  isl_map_plain_is_injective((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Map::plainIsUniverse() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_plain_is_universe
  isl_bool res =  isl_map_plain_is_universe((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline BasicMap Map::polyhedralHull() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_polyhedral_hull
  isl_basic_map * res =  isl_map_polyhedral_hull((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_polyhedral_hull returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline Map Map::preimageDomainMultiAff(const MultiAff &ma) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  MultiAff _cast_ma = ma.asMultiAff();
  // Call isl_map_preimage_domain_multi_aff
  isl_map * res =  isl_map_preimage_domain_multi_aff((self).Give(), (_cast_ma).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_preimage_domain_multi_aff returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::preimageDomainMultiPwAff(const MultiPwAff &mpa) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  MultiPwAff _cast_mpa = mpa.asMultiPwAff();
  // Call isl_map_preimage_domain_multi_pw_aff
  isl_map * res =  isl_map_preimage_domain_multi_pw_aff((self).Give(), (_cast_mpa).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_preimage_domain_multi_pw_aff returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::preimageDomainPwMultiAff(const PwMultiAff &pma) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  PwMultiAff _cast_pma = pma.asPwMultiAff();
  // Call isl_map_preimage_domain_pw_multi_aff
  isl_map * res =  isl_map_preimage_domain_pw_multi_aff((self).Give(), (_cast_pma).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_preimage_domain_pw_multi_aff returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::preimageRangeMultiAff(const MultiAff &ma) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  MultiAff _cast_ma = ma.asMultiAff();
  // Call isl_map_preimage_range_multi_aff
  isl_map * res =  isl_map_preimage_range_multi_aff((self).Give(), (_cast_ma).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_preimage_range_multi_aff returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::preimageRangePwMultiAff(const PwMultiAff &pma) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  PwMultiAff _cast_pma = pma.asPwMultiAff();
  // Call isl_map_preimage_range_pw_multi_aff
  isl_map * res =  isl_map_preimage_range_pw_multi_aff((self).Give(), (_cast_pma).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_preimage_range_pw_multi_aff returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::product(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_product
  isl_map * res =  isl_map_product((self).Give(), (_cast_map2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_product returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::projectOut(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_project_out
  isl_map * res =  isl_map_project_out((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_project_out returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Set Map::range() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_range
  isl_set * res =  isl_map_range((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_range returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Map Map::rangeMap() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_range_map
  isl_map * res =  isl_map_range_map((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_range_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::rangeProduct(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_range_product
  isl_map * res =  isl_map_range_product((self).Give(), (_cast_map2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_range_product returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::removeDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_remove_dims
  isl_map * res =  isl_map_remove_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_remove_dims returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::removeDivs() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_remove_divs
  isl_map * res =  isl_map_remove_divs((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_remove_divs returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::removeDivsInvolvingDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_remove_divs_involving_dims
  isl_map * res =  isl_map_remove_divs_involving_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_remove_divs_involving_dims returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::removeRedundancies() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_remove_redundancies
  isl_map * res =  isl_map_remove_redundancies((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_remove_redundancies returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::removeUnknownDivs() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_remove_unknown_divs
  isl_map * res =  isl_map_remove_unknown_divs((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_remove_unknown_divs returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::resetTupleId(DimType type) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_reset_tuple_id
  isl_map * res =  isl_map_reset_tuple_id((self).Give(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_reset_tuple_id returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::reverse() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_reverse
  isl_map * res =  isl_map_reverse((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_reverse returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline BasicMap Map::sample() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_sample
  isl_basic_map * res =  isl_map_sample((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_sample returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline Map Map::setDimId(DimType type, unsigned int pos, const Id &id) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_map_set_dim_id
  isl_map * res =  isl_map_set_dim_id((self).Give(), (enum isl_dim_type)type, pos, (_cast_id).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_set_dim_id returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::setDimName(DimType type, unsigned int pos, std::string s) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_set_dim_name
  isl_map * res =  isl_map_set_dim_name((self).Give(), (enum isl_dim_type)type, pos, s.c_str());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_set_dim_name returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::setTupleId(DimType type, const Id &id) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_map_set_tuple_id
  isl_map * res =  isl_map_set_tuple_id((self).Give(), (enum isl_dim_type)type, (_cast_id).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_set_tuple_id returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::setTupleName(DimType type, std::string s) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_set_tuple_name
  isl_map * res =  isl_map_set_tuple_name((self).Give(), (enum isl_dim_type)type, s.c_str());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_set_tuple_name returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline BasicMap Map::simpleHull() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_simple_hull
  isl_basic_map * res =  isl_map_simple_hull((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_simple_hull returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline Map Map::subtract(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_subtract
  isl_map * res =  isl_map_subtract((self).Give(), (_cast_map2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_subtract returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::subtractDomain(const Set &dom) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Set _cast_dom = dom.asSet();
  // Call isl_map_subtract_domain
  isl_map * res =  isl_map_subtract_domain((self).Give(), (_cast_dom).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_subtract_domain returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::subtractRange(const Set &dom) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Set _cast_dom = dom.asSet();
  // Call isl_map_subtract_range
  isl_map * res =  isl_map_subtract_range((self).Give(), (_cast_dom).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_subtract_range returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::transitiveClosure(int * exact) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_transitive_closure
  isl_map * res =  isl_map_transitive_closure((self).Give(), exact);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_transitive_closure returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::uncurry() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_uncurry
  isl_map * res =  isl_map_uncurry((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_uncurry returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::union_(const Map &map2) const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  Map _cast_map2 = map2.asMap();
  // Call isl_map_union
  isl_map * res =  isl_map_union((self).Give(), (_cast_map2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_union returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline BasicMap Map::unshiftedSimpleHull() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_unshifted_simple_hull
  isl_basic_map * res =  isl_map_unshifted_simple_hull((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_unshifted_simple_hull returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline Set Map::wrap() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_wrap
  isl_set * res =  isl_map_wrap((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_wrap returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Map Map::zip() const {
  ctx.lock();
  Map self = asMap();
  // Prepare arguments
  // Call isl_map_zip
  isl_map * res =  isl_map_zip((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_map_zip returned a NULL pointer.");
  }
  return Map(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_Map_IMPL_H
