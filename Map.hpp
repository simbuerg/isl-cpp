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

#include <cassert>

namespace isl {

inline isl_map *Map::GetCopy() const {
  return isl_map_copy((isl_map *)This);
}
inline Map &Map::operator=(const Map &Other) {
  isl_map *New = Other.GetCopy();
  ctx = Other.Context();
  isl_map_free((isl_map *)This);
  This = New;
  return *this;
}
inline Map Map::fromPwAff(const PwAff &pwaff) {
  const Ctx &_ctx = pwaff.Context();
  _ctx.lock();
  isl_map *That = isl_map_from_pw_aff((pwaff).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_from_pw_aff returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::natUniverse(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_map *That = isl_map_nat_universe((dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_nat_universe returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::empty(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_map *That = isl_map_empty((dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_empty returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::lexLeFirst(const Space &dim, unsigned int n) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_map *That = isl_map_lex_le_first((dim).GetCopy(), n);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_lex_le_first returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::lexLt(const Space &set_dim) {
  const Ctx &_ctx = set_dim.Context();
  _ctx.lock();
  isl_map *That = isl_map_lex_lt((set_dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_lex_lt returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::lexLe(const Space &set_dim) {
  const Ctx &_ctx = set_dim.Context();
  _ctx.lock();
  isl_map *That = isl_map_lex_le((set_dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_lex_le returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::lexGtFirst(const Space &dim, unsigned int n) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_map *That = isl_map_lex_gt_first((dim).GetCopy(), n);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_lex_gt_first returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::lexGeFirst(const Space &dim, unsigned int n) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_map *That = isl_map_lex_ge_first((dim).GetCopy(), n);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_lex_ge_first returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::lexGt(const Space &set_dim) {
  const Ctx &_ctx = set_dim.Context();
  _ctx.lock();
  isl_map *That = isl_map_lex_gt((set_dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_lex_gt returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::lexGe(const Space &set_dim) {
  const Ctx &_ctx = set_dim.Context();
  _ctx.lock();
  isl_map *That = isl_map_lex_ge((set_dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_lex_ge returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_map *That = isl_map_read_from_str((ctx.Get()), str.c_str());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_read_from_str returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::fromBasicMap(const BasicMap &bmap) {
  const Ctx &_ctx = bmap.Context();
  _ctx.lock();
  isl_map *That = isl_map_from_basic_map((bmap).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_from_basic_map returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::fromDomain(const Set &set) {
  const Ctx &_ctx = set.Context();
  _ctx.lock();
  isl_map *That = isl_map_from_domain((set).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_from_domain returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::fromRange(const Set &set) {
  const Ctx &_ctx = set.Context();
  _ctx.lock();
  isl_map *That = isl_map_from_range((set).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_from_range returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::fromDomainAndRange(const Set &domain, const Set &range) {
  const Ctx &_ctx = range.Context();
  _ctx.lock();
  isl_map *That = isl_map_from_domain_and_range((domain).GetCopy(), (range).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_from_domain_and_range returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::fromSet(const Set &set, const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_map *That = isl_map_from_set((set).GetCopy(), (dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_from_set returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::fromAff(const Aff &aff) {
  const Ctx &_ctx = aff.Context();
  _ctx.lock();
  isl_map *That = isl_map_from_aff((aff).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_from_aff returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::fromMultiAff(const MultiAff &maff) {
  const Ctx &_ctx = maff.Context();
  _ctx.lock();
  isl_map *That = isl_map_from_multi_aff((maff).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_map_from_multi_aff returned a NULL pointer.");
  }

  return Map(_ctx, That);
}

inline Map Map::fromUnionMap(const UnionMap &umap) {
  const Ctx &_ctx = umap.Context();
  _ctx.lock();
  isl_map *That = isl_map_from_union_map((umap).GetCopy());

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

inline Map Map::addConstraint(const Constraint &constraint) const {
  ctx.lock();
  isl_map * res =  isl_map_add_constraint((*this).GetCopy(), (constraint).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_add_constraint returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  isl_map * res =  isl_map_add_dims((*this).GetCopy(), (enum isl_dim_type)type, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_add_dims returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline BasicMap Map::affineHull() const {
  ctx.lock();
  isl_basic_map * res =  isl_map_affine_hull((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_affine_hull returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline Map Map::alignDivs() const {
  ctx.lock();
  isl_map * res =  isl_map_align_divs((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_align_divs returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::alignParams(const Space &model) const {
  ctx.lock();
  isl_map * res =  isl_map_align_params((*this).GetCopy(), (model).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_align_params returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::applyDomain(const Map &map2) const {
  ctx.lock();
  isl_map * res =  isl_map_apply_domain((*this).GetCopy(), (map2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_apply_domain returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline PwQpolynomialFold Map::applyPwQpolynomialFold(const PwQpolynomialFold &pwf, int * tight) const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_map_apply_pw_qpolynomial_fold((*this).GetCopy(), (pwf).GetCopy(), tight);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_apply_pw_qpolynomial_fold returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline Map Map::applyRange(const Map &map2) const {
  ctx.lock();
  isl_map * res =  isl_map_apply_range((*this).GetCopy(), (map2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_apply_range returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Bool Map::canCurry() const {
  ctx.lock();
  isl_bool res =  isl_map_can_curry((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Map::canUncurry() const {
  ctx.lock();
  isl_bool res =  isl_map_can_uncurry((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Map::canZip() const {
  ctx.lock();
  isl_bool res =  isl_map_can_zip((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Map Map::coalesce() const {
  ctx.lock();
  isl_map * res =  isl_map_coalesce((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_coalesce returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::complement() const {
  ctx.lock();
  isl_map * res =  isl_map_complement((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_complement returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::computeDivs() const {
  ctx.lock();
  isl_map * res =  isl_map_compute_divs((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_compute_divs returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline BasicMap Map::convexHull() const {
  ctx.lock();
  isl_basic_map * res =  isl_map_convex_hull((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_convex_hull returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline Map Map::curry() const {
  ctx.lock();
  isl_map * res =  isl_map_curry((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_curry returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Set Map::deltas() const {
  ctx.lock();
  isl_set * res =  isl_map_deltas((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_deltas returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Map Map::deltasMap() const {
  ctx.lock();
  isl_map * res =  isl_map_deltas_map((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_deltas_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::detectEqualities() const {
  ctx.lock();
  isl_map * res =  isl_map_detect_equalities((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_detect_equalities returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline unsigned int Map::dim(DimType type) const {
  ctx.lock();
  unsigned int res =  isl_map_dim((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return res;
}

inline PwAff Map::dimMax(int pos) const {
  ctx.lock();
  isl_pw_aff * res =  isl_map_dim_max((*this).GetCopy(), pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_dim_max returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Set Map::domain() const {
  ctx.lock();
  isl_set * res =  isl_map_domain((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_domain returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Map Map::domainMap() const {
  ctx.lock();
  isl_map * res =  isl_map_domain_map((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_domain_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::domainProduct(const Map &map2) const {
  ctx.lock();
  isl_map * res =  isl_map_domain_product((*this).GetCopy(), (map2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_domain_product returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::dropConstraintsInvolvingDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_map * res =  isl_map_drop_constraints_involving_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_drop_constraints_involving_dims returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::eliminate(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_map * res =  isl_map_eliminate((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_eliminate returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::equate(DimType type1, int pos1, DimType type2, int pos2) const {
  ctx.lock();
  isl_map * res =  isl_map_equate((*this).GetCopy(), (enum isl_dim_type)type1, pos1, (enum isl_dim_type)type2, pos2);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_equate returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline int Map::findDimById(DimType type, const Id &id) const {
  ctx.lock();
  int res =  isl_map_find_dim_by_id((*this).Get(), (enum isl_dim_type)type, (id).Get());
  ctx.unlock();
  return res;
}

inline int Map::findDimByName(DimType type, std::string name) const {
  ctx.lock();
  int res =  isl_map_find_dim_by_name((*this).Get(), (enum isl_dim_type)type, name.c_str());
  ctx.unlock();
  return res;
}

inline Map Map::fixVal(DimType type, unsigned int pos, const Val &v) const {
  ctx.lock();
  isl_map * res =  isl_map_fix_val((*this).GetCopy(), (enum isl_dim_type)type, pos, (v).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_fix_val returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::fixedPowerVal(const Val &exp) const {
  ctx.lock();
  isl_map * res =  isl_map_fixed_power_val((*this).GetCopy(), (exp).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_fixed_power_val returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::flatDomainProduct(const Map &map2) const {
  ctx.lock();
  isl_map * res =  isl_map_flat_domain_product((*this).GetCopy(), (map2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_flat_domain_product returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::flatProduct(const Map &map2) const {
  ctx.lock();
  isl_map * res =  isl_map_flat_product((*this).GetCopy(), (map2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_flat_product returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::flatRangeProduct(const Map &map2) const {
  ctx.lock();
  isl_map * res =  isl_map_flat_range_product((*this).GetCopy(), (map2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_flat_range_product returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::flatten() const {
  ctx.lock();
  isl_map * res =  isl_map_flatten((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_flatten returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::flattenDomain() const {
  ctx.lock();
  isl_map * res =  isl_map_flatten_domain((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_flatten_domain returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::flattenRange() const {
  ctx.lock();
  isl_map * res =  isl_map_flatten_range((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_flatten_range returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::floordivVal(const Val &d) const {
  ctx.lock();
  isl_map * res =  isl_map_floordiv_val((*this).GetCopy(), (d).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_floordiv_val returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Stat Map::foreachBasicMap(const std::function<isl_stat(isl_basic_map *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_map_foreach_basic_map((*this).Get(), get_fn_ptr<4>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline Id Map::getDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_id * res =  isl_map_get_dim_id((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_get_dim_id returned a NULL pointer.");
  }
  return Id(ctx, res);
}

inline std::string Map::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  const char * res =  isl_map_get_dim_name((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_map_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Space Map::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_map_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Id Map::getTupleId(DimType type) const {
  ctx.lock();
  isl_id * res =  isl_map_get_tuple_id((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_get_tuple_id returned a NULL pointer.");
  }
  return Id(ctx, res);
}

inline std::string Map::getTupleName(DimType type) const {
  ctx.lock();
  const char * res =  isl_map_get_tuple_name((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_map_get_tuple_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Map Map::gist(const Map &context) const {
  ctx.lock();
  isl_map * res =  isl_map_gist((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_gist returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::gistBasicMap(const BasicMap &context) const {
  ctx.lock();
  isl_map * res =  isl_map_gist_basic_map((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_gist_basic_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::gistDomain(const Set &context) const {
  ctx.lock();
  isl_map * res =  isl_map_gist_domain((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_gist_domain returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::gistParams(const Set &context) const {
  ctx.lock();
  isl_map * res =  isl_map_gist_params((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_gist_params returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::gistRange(const Set &context) const {
  ctx.lock();
  isl_map * res =  isl_map_gist_range((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_gist_range returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Bool Map::hasDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_bool res =  isl_map_has_dim_id((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  return (Bool)res;
}

inline Bool Map::hasDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_bool res =  isl_map_has_dim_name((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  return (Bool)res;
}

inline int Map::hasEqualSpace(const Map &map2) const {
  ctx.lock();
  int res =  isl_map_has_equal_space((*this).Get(), (map2).Get());
  ctx.unlock();
  return res;
}

inline Bool Map::hasTupleId(DimType type) const {
  ctx.lock();
  isl_bool res =  isl_map_has_tuple_id((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return (Bool)res;
}

inline Bool Map::hasTupleName(DimType type) const {
  ctx.lock();
  isl_bool res =  isl_map_has_tuple_name((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return (Bool)res;
}

inline Map Map::insertDims(DimType type, unsigned int pos, unsigned int n) const {
  ctx.lock();
  isl_map * res =  isl_map_insert_dims((*this).GetCopy(), (enum isl_dim_type)type, pos, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_insert_dims returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::intersect(const Map &map2) const {
  ctx.lock();
  isl_map * res =  isl_map_intersect((*this).GetCopy(), (map2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_intersect returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::intersectDomain(const Set &set) const {
  ctx.lock();
  isl_map * res =  isl_map_intersect_domain((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_intersect_domain returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::intersectParams(const Set &params) const {
  ctx.lock();
  isl_map * res =  isl_map_intersect_params((*this).GetCopy(), (params).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_intersect_params returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::intersectRange(const Set &set) const {
  ctx.lock();
  isl_map * res =  isl_map_intersect_range((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_intersect_range returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Bool Map::involvesDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_bool res =  isl_map_involves_dims((*this).Get(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  return (Bool)res;
}

inline Bool Map::isBijective() const {
  ctx.lock();
  isl_bool res =  isl_map_is_bijective((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Map::isDisjoint(const Map &map2) const {
  ctx.lock();
  isl_bool res =  isl_map_is_disjoint((*this).Get(), (map2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Map::isEmpty() const {
  ctx.lock();
  isl_bool res =  isl_map_is_empty((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Map::isEqual(const Map &map2) const {
  ctx.lock();
  isl_bool res =  isl_map_is_equal((*this).Get(), (map2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Map::isInjective() const {
  ctx.lock();
  isl_bool res =  isl_map_is_injective((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Map::isSingleValued() const {
  ctx.lock();
  isl_bool res =  isl_map_is_single_valued((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Map::isStrictSubset(const Map &map2) const {
  ctx.lock();
  isl_bool res =  isl_map_is_strict_subset((*this).Get(), (map2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Map::isSubset(const Map &map2) const {
  ctx.lock();
  isl_bool res =  isl_map_is_subset((*this).Get(), (map2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline int Map::isTranslation() const {
  ctx.lock();
  int res =  isl_map_is_translation((*this).Get());
  ctx.unlock();
  return res;
}

inline Map Map::lexGeMap(const Map &map2) const {
  ctx.lock();
  isl_map * res =  isl_map_lex_ge_map((*this).GetCopy(), (map2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_lex_ge_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::lexGtMap(const Map &map2) const {
  ctx.lock();
  isl_map * res =  isl_map_lex_gt_map((*this).GetCopy(), (map2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_lex_gt_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::lexLeMap(const Map &map2) const {
  ctx.lock();
  isl_map * res =  isl_map_lex_le_map((*this).GetCopy(), (map2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_lex_le_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::lexLtMap(const Map &map2) const {
  ctx.lock();
  isl_map * res =  isl_map_lex_lt_map((*this).GetCopy(), (map2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_lex_lt_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::lexmax() const {
  ctx.lock();
  isl_map * res =  isl_map_lexmax((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_lexmax returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::lexmin() const {
  ctx.lock();
  isl_map * res =  isl_map_lexmin((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_lexmin returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline PwMultiAff Map::lexminPwMultiAff() const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_map_lexmin_pw_multi_aff((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_lexmin_pw_multi_aff returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline Map Map::makeDisjoint() const {
  ctx.lock();
  isl_map * res =  isl_map_make_disjoint((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_make_disjoint returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  isl_map * res =  isl_map_move_dims((*this).GetCopy(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_move_dims returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline unsigned int Map::nIn() const {
  ctx.lock();
  unsigned int res =  isl_map_n_in((*this).Get());
  ctx.unlock();
  return res;
}

inline unsigned int Map::nOut() const {
  ctx.lock();
  unsigned int res =  isl_map_n_out((*this).Get());
  ctx.unlock();
  return res;
}

inline unsigned int Map::nParam() const {
  ctx.lock();
  unsigned int res =  isl_map_n_param((*this).Get());
  ctx.unlock();
  return res;
}

inline Map Map::oppose(DimType type1, int pos1, DimType type2, int pos2) const {
  ctx.lock();
  isl_map * res =  isl_map_oppose((*this).GetCopy(), (enum isl_dim_type)type1, pos1, (enum isl_dim_type)type2, pos2);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_oppose returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::orderGt(DimType type1, int pos1, DimType type2, int pos2) const {
  ctx.lock();
  isl_map * res =  isl_map_order_gt((*this).GetCopy(), (enum isl_dim_type)type1, pos1, (enum isl_dim_type)type2, pos2);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_order_gt returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::orderLt(DimType type1, int pos1, DimType type2, int pos2) const {
  ctx.lock();
  isl_map * res =  isl_map_order_lt((*this).GetCopy(), (enum isl_dim_type)type1, pos1, (enum isl_dim_type)type2, pos2);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_order_lt returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Set Map::params() const {
  ctx.lock();
  isl_set * res =  isl_map_params((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_params returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Bool Map::plainIsEmpty() const {
  ctx.lock();
  isl_bool res =  isl_map_plain_is_empty((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Map::plainIsEqual(const Map &map2) const {
  ctx.lock();
  isl_bool res =  isl_map_plain_is_equal((*this).Get(), (map2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Map::plainIsInjective() const {
  ctx.lock();
  isl_bool res =  isl_map_plain_is_injective((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Map::plainIsUniverse() const {
  ctx.lock();
  isl_bool res =  isl_map_plain_is_universe((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline BasicMap Map::polyhedralHull() const {
  ctx.lock();
  isl_basic_map * res =  isl_map_polyhedral_hull((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_polyhedral_hull returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline Map Map::preimageDomainMultiAff(const MultiAff &ma) const {
  ctx.lock();
  isl_map * res =  isl_map_preimage_domain_multi_aff((*this).GetCopy(), (ma).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_preimage_domain_multi_aff returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::preimageDomainMultiPwAff(const MultiPwAff &mpa) const {
  ctx.lock();
  isl_map * res =  isl_map_preimage_domain_multi_pw_aff((*this).GetCopy(), (mpa).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_preimage_domain_multi_pw_aff returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::preimageDomainPwMultiAff(const PwMultiAff &pma) const {
  ctx.lock();
  isl_map * res =  isl_map_preimage_domain_pw_multi_aff((*this).GetCopy(), (pma).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_preimage_domain_pw_multi_aff returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::preimageRangeMultiAff(const MultiAff &ma) const {
  ctx.lock();
  isl_map * res =  isl_map_preimage_range_multi_aff((*this).GetCopy(), (ma).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_preimage_range_multi_aff returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::preimageRangePwMultiAff(const PwMultiAff &pma) const {
  ctx.lock();
  isl_map * res =  isl_map_preimage_range_pw_multi_aff((*this).GetCopy(), (pma).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_preimage_range_pw_multi_aff returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::product(const Map &map2) const {
  ctx.lock();
  isl_map * res =  isl_map_product((*this).GetCopy(), (map2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_product returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::projectOut(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_map * res =  isl_map_project_out((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_project_out returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Set Map::range() const {
  ctx.lock();
  isl_set * res =  isl_map_range((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_range returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Map Map::rangeMap() const {
  ctx.lock();
  isl_map * res =  isl_map_range_map((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_range_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::rangeProduct(const Map &map2) const {
  ctx.lock();
  isl_map * res =  isl_map_range_product((*this).GetCopy(), (map2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_range_product returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::removeDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_map * res =  isl_map_remove_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_remove_dims returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::removeDivs() const {
  ctx.lock();
  isl_map * res =  isl_map_remove_divs((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_remove_divs returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::removeDivsInvolvingDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_map * res =  isl_map_remove_divs_involving_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_remove_divs_involving_dims returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::removeRedundancies() const {
  ctx.lock();
  isl_map * res =  isl_map_remove_redundancies((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_remove_redundancies returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::removeUnknownDivs() const {
  ctx.lock();
  isl_map * res =  isl_map_remove_unknown_divs((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_remove_unknown_divs returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::resetTupleId(DimType type) const {
  ctx.lock();
  isl_map * res =  isl_map_reset_tuple_id((*this).GetCopy(), (enum isl_dim_type)type);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_reset_tuple_id returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::reverse() const {
  ctx.lock();
  isl_map * res =  isl_map_reverse((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_reverse returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline BasicMap Map::sample() const {
  ctx.lock();
  isl_basic_map * res =  isl_map_sample((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_sample returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline Map Map::setDimId(DimType type, unsigned int pos, const Id &id) const {
  ctx.lock();
  isl_map * res =  isl_map_set_dim_id((*this).GetCopy(), (enum isl_dim_type)type, pos, (id).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_set_dim_id returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::setDimName(DimType type, unsigned int pos, std::string s) const {
  ctx.lock();
  isl_map * res =  isl_map_set_dim_name((*this).GetCopy(), (enum isl_dim_type)type, pos, s.c_str());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_set_dim_name returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::setTupleId(DimType type, const Id &id) const {
  ctx.lock();
  isl_map * res =  isl_map_set_tuple_id((*this).GetCopy(), (enum isl_dim_type)type, (id).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_set_tuple_id returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::setTupleName(DimType type, std::string s) const {
  ctx.lock();
  isl_map * res =  isl_map_set_tuple_name((*this).GetCopy(), (enum isl_dim_type)type, s.c_str());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_set_tuple_name returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline BasicMap Map::simpleHull() const {
  ctx.lock();
  isl_basic_map * res =  isl_map_simple_hull((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_simple_hull returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline Map Map::subtract(const Map &map2) const {
  ctx.lock();
  isl_map * res =  isl_map_subtract((*this).GetCopy(), (map2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_subtract returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::subtractDomain(const Set &dom) const {
  ctx.lock();
  isl_map * res =  isl_map_subtract_domain((*this).GetCopy(), (dom).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_subtract_domain returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::subtractRange(const Set &dom) const {
  ctx.lock();
  isl_map * res =  isl_map_subtract_range((*this).GetCopy(), (dom).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_subtract_range returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline std::string Map::toStr() const {
  ctx.lock();
  char * res =  isl_map_to_str((*this).Get());
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_map_to_str returned a NULL pointer.");
  }
  res_ = res;
  free((void *)res);
  return res_;
}

inline Map Map::transitiveClosure(int * exact) const {
  ctx.lock();
  isl_map * res =  isl_map_transitive_closure((*this).GetCopy(), exact);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_transitive_closure returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::uncurry() const {
  ctx.lock();
  isl_map * res =  isl_map_uncurry((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_uncurry returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Map::union_(const Map &map2) const {
  ctx.lock();
  isl_map * res =  isl_map_union((*this).GetCopy(), (map2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_union returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline BasicMap Map::unshiftedSimpleHull() const {
  ctx.lock();
  isl_basic_map * res =  isl_map_unshifted_simple_hull((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_unshifted_simple_hull returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

inline Set Map::wrap() const {
  ctx.lock();
  isl_set * res =  isl_map_wrap((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_wrap returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Map Map::zip() const {
  ctx.lock();
  isl_map * res =  isl_map_zip((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_map_zip returned a NULL pointer.");
  }
  return Map(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_Map_IMPL_H
