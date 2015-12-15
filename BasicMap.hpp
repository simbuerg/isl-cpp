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
#include "isl/Printer.hpp"
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
#include <ostream>

#include <cassert>

namespace isl {
inline isl_basic_map *BasicMap::GetCopy() const {
  return isl_basic_map_copy((isl_basic_map *)This);
}
inline BasicMap &BasicMap::operator=(const BasicMap &Other) {
  isl_basic_map *New = Other.GetCopy();
  isl_basic_map_free((isl_basic_map *)This);
  This = New;
  return *this;
}
inline BasicMap BasicMap::lessAt(const Space &dim, unsigned int pos) {
  Ctx _ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_basic_map *That = isl_basic_map_less_at((_cast_dim).Give(), pos);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_less_at returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::moreAt(const Space &dim, unsigned int pos) {
  Ctx _ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_basic_map *That = isl_basic_map_more_at((_cast_dim).Give(), pos);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_more_at returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::empty(const Space &dim) {
  Ctx _ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_basic_map *That = isl_basic_map_empty((_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_empty returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::natUniverse(const Space &dim) {
  Ctx _ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_basic_map *That = isl_basic_map_nat_universe((_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_nat_universe returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::fromBasicSet(const BasicSet &bset, const Space &dim) {
  Ctx _ctx = dim.Context();
  _ctx.lock();
  BasicSet _cast_bset = bset.asBasicSet();
  Space _cast_dim = dim.asSpace();
  isl_basic_map *That = isl_basic_map_from_basic_set((_cast_bset).Give(), (_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_from_basic_set returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::readFromStr(const Ctx &ctx, std::string str) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_basic_map *That = isl_basic_map_read_from_str((ctx.Get()), str.c_str());
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_read_from_str returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::fromDomain(const BasicSet &bset) {
  Ctx _ctx = bset.Context();
  _ctx.lock();
  BasicSet _cast_bset = bset.asBasicSet();
  isl_basic_map *That = isl_basic_map_from_domain((_cast_bset).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_from_domain returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::fromRange(const BasicSet &bset) {
  Ctx _ctx = bset.Context();
  _ctx.lock();
  BasicSet _cast_bset = bset.asBasicSet();
  isl_basic_map *That = isl_basic_map_from_range((_cast_bset).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_from_range returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::fromDomainAndRange(const BasicSet &domain, const BasicSet &range) {
  Ctx _ctx = range.Context();
  _ctx.lock();
  BasicSet _cast_domain = domain.asBasicSet();
  BasicSet _cast_range = range.asBasicSet();
  isl_basic_map *That = isl_basic_map_from_domain_and_range((_cast_domain).Give(), (_cast_range).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_from_domain_and_range returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::fromConstraintMatrices(const Space &dim, const Mat &eq, const Mat &ineq, DimType c1, DimType c2, DimType c3, DimType c4, DimType c5) {
  Ctx _ctx = ineq.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  Mat _cast_eq = eq.asMat();
  Mat _cast_ineq = ineq.asMat();
  isl_basic_map *That = isl_basic_map_from_constraint_matrices((_cast_dim).Give(), (_cast_eq).Give(), (_cast_ineq).Give(), (enum isl_dim_type)c1, (enum isl_dim_type)c2, (enum isl_dim_type)c3, (enum isl_dim_type)c4, (enum isl_dim_type)c5);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_from_constraint_matrices returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::fromAff(const Aff &aff) {
  Ctx _ctx = aff.Context();
  _ctx.lock();
  Aff _cast_aff = aff.asAff();
  isl_basic_map *That = isl_basic_map_from_aff((_cast_aff).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_from_aff returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::fromMultiAff(const MultiAff &maff) {
  Ctx _ctx = maff.Context();
  _ctx.lock();
  MultiAff _cast_maff = maff.asMultiAff();
  isl_basic_map *That = isl_basic_map_from_multi_aff((_cast_maff).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_from_multi_aff returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::fromConstraint(const Constraint &constraint) {
  Ctx _ctx = constraint.Context();
  _ctx.lock();
  Constraint _cast_constraint = constraint.asConstraint();
  isl_basic_map *That = isl_basic_map_from_constraint((_cast_constraint).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_map_from_constraint returned a NULL pointer.");
  }

  return BasicMap(_ctx, That);
}

inline BasicMap BasicMap::fromQpolynomial(const Qpolynomial &qp) {
  Ctx _ctx = qp.Context();
  _ctx.lock();
  Qpolynomial _cast_qp = qp.asQpolynomial();
  isl_basic_map *That = isl_basic_map_from_qpolynomial((_cast_qp).Give());

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
inline std::string BasicMap::toStr(isl::Format F) const {
  Printer p = Printer::toStr(ctx);
  p = p.setOutputFormat(F);
  p = p.printBasicMap(*this);
  return p.getStr();
}

inline BasicMap BasicMap::asBasicMap() const {
  return BasicMap(GetCopy());
}

inline Map BasicMap::asMap() const {
  return Map(*this);
}

inline UnionMap BasicMap::asUnionMap() const {
  return UnionMap(*this);
}

inline BasicMap BasicMap::addConstraint(const Constraint &constraint) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  Constraint _cast_constraint = constraint.asConstraint();
  // Call isl_basic_map_add_constraint
  isl_basic_map * res =  isl_basic_map_add_constraint((self).Give(), (_cast_constraint).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_add_constraint returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_add_dims
  isl_basic_map * res =  isl_basic_map_add_dims((self).Give(), (enum isl_dim_type)type, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_add_dims returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::affineHull() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_affine_hull
  isl_basic_map * res =  isl_basic_map_affine_hull((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_affine_hull returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::alignParams(const Space &model) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  Space _cast_model = model.asSpace();
  // Call isl_basic_map_align_params
  isl_basic_map * res =  isl_basic_map_align_params((self).Give(), (_cast_model).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_align_params returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::applyDomain(const BasicMap &bmap2) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  BasicMap _cast_bmap2 = bmap2.asBasicMap();
  // Call isl_basic_map_apply_domain
  isl_basic_map * res =  isl_basic_map_apply_domain((self).Give(), (_cast_bmap2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_apply_domain returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::applyRange(const BasicMap &bmap2) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  BasicMap _cast_bmap2 = bmap2.asBasicMap();
  // Call isl_basic_map_apply_range
  isl_basic_map * res =  isl_basic_map_apply_range((self).Give(), (_cast_bmap2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_apply_range returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline Bool BasicMap::canCurry() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_can_curry
  isl_bool res =  isl_basic_map_can_curry((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool BasicMap::canUncurry() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_can_uncurry
  isl_bool res =  isl_basic_map_can_uncurry((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool BasicMap::canZip() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_can_zip
  isl_bool res =  isl_basic_map_can_zip((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Map BasicMap::computeDivs() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_compute_divs
  isl_map * res =  isl_basic_map_compute_divs((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_compute_divs returned a NULL pointer.");
  }
  return Map(res);
}

inline BasicMap BasicMap::curry() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_curry
  isl_basic_map * res =  isl_basic_map_curry((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_curry returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicSet BasicMap::deltas() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_deltas
  isl_basic_set * res =  isl_basic_map_deltas((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_deltas returned a NULL pointer.");
  }
  return BasicSet(res);
}

inline BasicMap BasicMap::deltasMap() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_deltas_map
  isl_basic_map * res =  isl_basic_map_deltas_map((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_deltas_map returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::detectEqualities() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_detect_equalities
  isl_basic_map * res =  isl_basic_map_detect_equalities((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_detect_equalities returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline unsigned int BasicMap::dim(DimType type) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_dim
  unsigned int res =  isl_basic_map_dim((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline BasicSet BasicMap::domain() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_domain
  isl_basic_set * res =  isl_basic_map_domain((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_domain returned a NULL pointer.");
  }
  return BasicSet(res);
}

inline BasicMap BasicMap::domainMap() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_domain_map
  isl_basic_map * res =  isl_basic_map_domain_map((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_domain_map returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::domainProduct(const BasicMap &bmap2) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  BasicMap _cast_bmap2 = bmap2.asBasicMap();
  // Call isl_basic_map_domain_product
  isl_basic_map * res =  isl_basic_map_domain_product((self).Give(), (_cast_bmap2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_domain_product returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::dropConstraintsInvolvingDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_drop_constraints_involving_dims
  isl_basic_map * res =  isl_basic_map_drop_constraints_involving_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_drop_constraints_involving_dims returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::eliminate(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_eliminate
  isl_basic_map * res =  isl_basic_map_eliminate((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_eliminate returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline Mat BasicMap::equalitiesMatrix(DimType c1, DimType c2, DimType c3, DimType c4, DimType c5) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_equalities_matrix
  isl_mat * res =  isl_basic_map_equalities_matrix((self).Get(), (enum isl_dim_type)c1, (enum isl_dim_type)c2, (enum isl_dim_type)c3, (enum isl_dim_type)c4, (enum isl_dim_type)c5);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_equalities_matrix returned a NULL pointer.");
  }
  return Mat(res);
}

inline BasicMap BasicMap::equate(DimType type1, int pos1, DimType type2, int pos2) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_equate
  isl_basic_map * res =  isl_basic_map_equate((self).Give(), (enum isl_dim_type)type1, pos1, (enum isl_dim_type)type2, pos2);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_equate returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::fixVal(DimType type, unsigned int pos, const Val &v) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_basic_map_fix_val
  isl_basic_map * res =  isl_basic_map_fix_val((self).Give(), (enum isl_dim_type)type, pos, (_cast_v).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_fix_val returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::flatProduct(const BasicMap &bmap2) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  BasicMap _cast_bmap2 = bmap2.asBasicMap();
  // Call isl_basic_map_flat_product
  isl_basic_map * res =  isl_basic_map_flat_product((self).Give(), (_cast_bmap2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_flat_product returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::flatRangeProduct(const BasicMap &bmap2) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  BasicMap _cast_bmap2 = bmap2.asBasicMap();
  // Call isl_basic_map_flat_range_product
  isl_basic_map * res =  isl_basic_map_flat_range_product((self).Give(), (_cast_bmap2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_flat_range_product returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::flatten() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_flatten
  isl_basic_map * res =  isl_basic_map_flatten((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_flatten returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::flattenDomain() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_flatten_domain
  isl_basic_map * res =  isl_basic_map_flatten_domain((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_flatten_domain returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::flattenRange() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_flatten_range
  isl_basic_map * res =  isl_basic_map_flatten_range((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_flatten_range returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline Stat BasicMap::foreachConstraint(const std::function<isl_stat(isl_constraint *, void *)> && fn, void * user) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_foreach_constraint
  isl_stat res =  isl_basic_map_foreach_constraint((self).Get(), get_fn_ptr<4>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline std::string BasicMap::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_get_dim_name
  const char * res =  isl_basic_map_get_dim_name((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_basic_map_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Aff BasicMap::getDiv(int pos) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_get_div
  isl_aff * res =  isl_basic_map_get_div((self).Get(), pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_get_div returned a NULL pointer.");
  }
  return Aff(res);
}

inline LocalSpace BasicMap::getLocalSpace() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_get_local_space
  isl_local_space * res =  isl_basic_map_get_local_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_get_local_space returned a NULL pointer.");
  }
  return LocalSpace(res);
}

inline Space BasicMap::getSpace() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_get_space
  isl_space * res =  isl_basic_map_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_get_space returned a NULL pointer.");
  }
  return Space(res);
}

inline std::string BasicMap::getTupleName(DimType type) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_get_tuple_name
  const char * res =  isl_basic_map_get_tuple_name((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_basic_map_get_tuple_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline BasicMap BasicMap::gist(const BasicMap &context) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  BasicMap _cast_context = context.asBasicMap();
  // Call isl_basic_map_gist
  isl_basic_map * res =  isl_basic_map_gist((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_gist returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline Bool BasicMap::hasDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_has_dim_id
  isl_bool res =  isl_basic_map_has_dim_id((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Mat BasicMap::inequalitiesMatrix(DimType c1, DimType c2, DimType c3, DimType c4, DimType c5) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_inequalities_matrix
  isl_mat * res =  isl_basic_map_inequalities_matrix((self).Get(), (enum isl_dim_type)c1, (enum isl_dim_type)c2, (enum isl_dim_type)c3, (enum isl_dim_type)c4, (enum isl_dim_type)c5);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_inequalities_matrix returned a NULL pointer.");
  }
  return Mat(res);
}

inline BasicMap BasicMap::insertDims(DimType type, unsigned int pos, unsigned int n) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_insert_dims
  isl_basic_map * res =  isl_basic_map_insert_dims((self).Give(), (enum isl_dim_type)type, pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_insert_dims returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::intersect(const BasicMap &bmap2) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  BasicMap _cast_bmap2 = bmap2.asBasicMap();
  // Call isl_basic_map_intersect
  isl_basic_map * res =  isl_basic_map_intersect((self).Give(), (_cast_bmap2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_intersect returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::intersectDomain(const BasicSet &bset) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  BasicSet _cast_bset = bset.asBasicSet();
  // Call isl_basic_map_intersect_domain
  isl_basic_map * res =  isl_basic_map_intersect_domain((self).Give(), (_cast_bset).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_intersect_domain returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::intersectRange(const BasicSet &bset) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  BasicSet _cast_bset = bset.asBasicSet();
  // Call isl_basic_map_intersect_range
  isl_basic_map * res =  isl_basic_map_intersect_range((self).Give(), (_cast_bset).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_intersect_range returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline Bool BasicMap::involvesDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_involves_dims
  isl_bool res =  isl_basic_map_involves_dims((self).Get(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool BasicMap::isDisjoint(const BasicMap &bmap2) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  BasicMap _cast_bmap2 = bmap2.asBasicMap();
  // Call isl_basic_map_is_disjoint
  isl_bool res =  isl_basic_map_is_disjoint((self).Get(), (_cast_bmap2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool BasicMap::isEmpty() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_is_empty
  isl_bool res =  isl_basic_map_is_empty((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool BasicMap::isEqual(const BasicMap &bmap2) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  BasicMap _cast_bmap2 = bmap2.asBasicMap();
  // Call isl_basic_map_is_equal
  isl_bool res =  isl_basic_map_is_equal((self).Get(), (_cast_bmap2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline int BasicMap::isRational() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_is_rational
  int res =  isl_basic_map_is_rational((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Bool BasicMap::isStrictSubset(const BasicMap &bmap2) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  BasicMap _cast_bmap2 = bmap2.asBasicMap();
  // Call isl_basic_map_is_strict_subset
  isl_bool res =  isl_basic_map_is_strict_subset((self).Get(), (_cast_bmap2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool BasicMap::isSubset(const BasicMap &bmap2) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  BasicMap _cast_bmap2 = bmap2.asBasicMap();
  // Call isl_basic_map_is_subset
  isl_bool res =  isl_basic_map_is_subset((self).Get(), (_cast_bmap2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool BasicMap::isUniverse() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_is_universe
  isl_bool res =  isl_basic_map_is_universe((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Map BasicMap::lexmax() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_lexmax
  isl_map * res =  isl_basic_map_lexmax((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_lexmax returned a NULL pointer.");
  }
  return Map(res);
}

inline Map BasicMap::lexmin() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_lexmin
  isl_map * res =  isl_basic_map_lexmin((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_lexmin returned a NULL pointer.");
  }
  return Map(res);
}

inline PwMultiAff BasicMap::lexminPwMultiAff() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_lexmin_pw_multi_aff
  isl_pw_multi_aff * res =  isl_basic_map_lexmin_pw_multi_aff((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_lexmin_pw_multi_aff returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline BasicMap BasicMap::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_move_dims
  isl_basic_map * res =  isl_basic_map_move_dims((self).Give(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_move_dims returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline int BasicMap::nConstraint() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_n_constraint
  int res =  isl_basic_map_n_constraint((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline unsigned int BasicMap::nDiv() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_n_div
  unsigned int res =  isl_basic_map_n_div((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline unsigned int BasicMap::nIn() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_n_in
  unsigned int res =  isl_basic_map_n_in((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline unsigned int BasicMap::nOut() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_n_out
  unsigned int res =  isl_basic_map_n_out((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline unsigned int BasicMap::nParam() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_n_param
  unsigned int res =  isl_basic_map_n_param((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline BasicMap BasicMap::orderGe(DimType type1, int pos1, DimType type2, int pos2) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_order_ge
  isl_basic_map * res =  isl_basic_map_order_ge((self).Give(), (enum isl_dim_type)type1, pos1, (enum isl_dim_type)type2, pos2);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_order_ge returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::orderGt(DimType type1, int pos1, DimType type2, int pos2) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_order_gt
  isl_basic_map * res =  isl_basic_map_order_gt((self).Give(), (enum isl_dim_type)type1, pos1, (enum isl_dim_type)type2, pos2);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_order_gt returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::product(const BasicMap &bmap2) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  BasicMap _cast_bmap2 = bmap2.asBasicMap();
  // Call isl_basic_map_product
  isl_basic_map * res =  isl_basic_map_product((self).Give(), (_cast_bmap2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_product returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::projectOut(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_project_out
  isl_basic_map * res =  isl_basic_map_project_out((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_project_out returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicSet BasicMap::range() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_range
  isl_basic_set * res =  isl_basic_map_range((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_range returned a NULL pointer.");
  }
  return BasicSet(res);
}

inline BasicMap BasicMap::rangeMap() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_range_map
  isl_basic_map * res =  isl_basic_map_range_map((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_range_map returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::rangeProduct(const BasicMap &bmap2) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  BasicMap _cast_bmap2 = bmap2.asBasicMap();
  // Call isl_basic_map_range_product
  isl_basic_map * res =  isl_basic_map_range_product((self).Give(), (_cast_bmap2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_range_product returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::removeDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_remove_dims
  isl_basic_map * res =  isl_basic_map_remove_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_remove_dims returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::removeDivs() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_remove_divs
  isl_basic_map * res =  isl_basic_map_remove_divs((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_remove_divs returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::removeDivsInvolvingDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_remove_divs_involving_dims
  isl_basic_map * res =  isl_basic_map_remove_divs_involving_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_remove_divs_involving_dims returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::reverse() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_reverse
  isl_basic_map * res =  isl_basic_map_reverse((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_reverse returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::sample() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_sample
  isl_basic_map * res =  isl_basic_map_sample((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_sample returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::setDimName(DimType type, unsigned int pos, std::string s) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_set_dim_name
  isl_basic_map * res =  isl_basic_map_set_dim_name((self).Give(), (enum isl_dim_type)type, pos, s.c_str());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_set_dim_name returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::setTupleId(DimType type, const Id &id) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_basic_map_set_tuple_id
  isl_basic_map * res =  isl_basic_map_set_tuple_id((self).Give(), (enum isl_dim_type)type, (_cast_id).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_set_tuple_id returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline BasicMap BasicMap::setTupleName(DimType type, std::string s) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_set_tuple_name
  isl_basic_map * res =  isl_basic_map_set_tuple_name((self).Give(), (enum isl_dim_type)type, s.c_str());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_set_tuple_name returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline unsigned int BasicMap::totalDim() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_total_dim
  unsigned int res =  isl_basic_map_total_dim((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline BasicMap BasicMap::uncurry() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_uncurry
  isl_basic_map * res =  isl_basic_map_uncurry((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_uncurry returned a NULL pointer.");
  }
  return BasicMap(res);
}

inline Map BasicMap::union_(const BasicMap &bmap2) const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  BasicMap _cast_bmap2 = bmap2.asBasicMap();
  // Call isl_basic_map_union
  isl_map * res =  isl_basic_map_union((self).Give(), (_cast_bmap2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_union returned a NULL pointer.");
  }
  return Map(res);
}

inline BasicSet BasicMap::wrap() const {
  ctx.lock();
  BasicMap self = asBasicMap();
  // Prepare arguments
  // Call isl_basic_map_wrap
  isl_basic_set * res =  isl_basic_map_wrap((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_map_wrap returned a NULL pointer.");
  }
  return BasicSet(res);
}

} // namespace isl
#endif //ISL_CXX_BasicMap_IMPL_H
