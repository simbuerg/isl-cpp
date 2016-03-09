#ifndef ISL_CXX_Set_IMPL_H
#define ISL_CXX_Set_IMPL_H

#include "isl/Set.h"

#include "isl/BasicSet.hpp"
#include "isl/Constraint.hpp"
#include "isl/Id.hpp"
#include "isl/Map.hpp"
#include "isl/MultiAff.hpp"
#include "isl/MultiPwAff.hpp"
#include "isl/Point.hpp"
#include "isl/PwAff.hpp"
#include "isl/PwMultiAff.hpp"
#include "isl/PwQpolynomialFold.hpp"
#include "isl/Space.hpp"
#include "isl/Val.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/UnionSet.hpp"
#include "isl/point.h"
#include "isl/set.h"
#include <string>

#include <cassert>

namespace isl {

inline isl_set *Set::GetCopy() const {
  return isl_set_copy((isl_set *)This);
}
inline Set &Set::operator=(const Set &Other) {
  isl_set *New = Other.GetCopy();
  isl_set_free((isl_set *)This);
  This = New;
  return *this;
}
inline Set Set::fromPwAff(const PwAff &pwaff) {
  const Ctx &_ctx = pwaff.Context();
  _ctx.lock();
  isl_set *That = isl_set_from_pw_aff((pwaff).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_set_from_pw_aff returned a NULL pointer.");
  }

  return Set(_ctx, That);
}

inline Set Set::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_set *That = isl_set_read_from_str((ctx.Get()), str.c_str());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_set_read_from_str returned a NULL pointer.");
  }

  return Set(_ctx, That);
}

inline Set Set::fromBasicSet(const BasicSet &bset) {
  const Ctx &_ctx = bset.Context();
  _ctx.lock();
  isl_set *That = isl_set_from_basic_set((bset).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_set_from_basic_set returned a NULL pointer.");
  }

  return Set(_ctx, That);
}

inline Set Set::fromPoint(const Point &pnt) {
  const Ctx &_ctx = pnt.Context();
  _ctx.lock();
  isl_set *That = isl_set_from_point((pnt).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_set_from_point returned a NULL pointer.");
  }

  return Set(_ctx, That);
}

inline Set Set::boxFromPoints(const Point &pnt1, const Point &pnt2) {
  const Ctx &_ctx = pnt2.Context();
  _ctx.lock();
  isl_set *That = isl_set_box_from_points((pnt1).GetCopy(), (pnt2).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_set_box_from_points returned a NULL pointer.");
  }

  return Set(_ctx, That);
}

inline Set Set::fromUnionSet(const UnionSet &uset) {
  const Ctx &_ctx = uset.Context();
  _ctx.lock();
  isl_set *That = isl_set_from_union_set((uset).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_set_from_union_set returned a NULL pointer.");
  }

  return Set(_ctx, That);
}
inline Set::~Set() {
  isl_set_free((isl_set *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_set *Set::Give() {
  isl_set *res = (isl_set *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_set *Set::Get() const {  return (isl_set *)This;
}

inline Set Set::addConstraint(const Constraint &constraint) const {
  ctx.lock();
  isl_set * res =  isl_set_add_constraint((*this).GetCopy(), (constraint).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_add_constraint returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  isl_set * res =  isl_set_add_dims((*this).GetCopy(), (enum isl_dim_type)type, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_add_dims returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline BasicSet Set::affineHull() const {
  ctx.lock();
  isl_basic_set * res =  isl_set_affine_hull((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_affine_hull returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Set Set::alignDivs() const {
  ctx.lock();
  isl_set * res =  isl_set_align_divs((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_align_divs returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::alignParams(const Space &model) const {
  ctx.lock();
  isl_set * res =  isl_set_align_params((*this).GetCopy(), (model).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_align_params returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::apply(const Map &map) const {
  ctx.lock();
  isl_set * res =  isl_set_apply((*this).GetCopy(), (map).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_apply returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline PwQpolynomialFold Set::applyPwQpolynomialFold(const PwQpolynomialFold &pwf, int * tight) const {
  ctx.lock();
  isl_pw_qpolynomial_fold * res =  isl_set_apply_pw_qpolynomial_fold((*this).GetCopy(), (pwf).GetCopy(), tight);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_apply_pw_qpolynomial_fold returned a NULL pointer.");
  }
  return PwQpolynomialFold(ctx, res);
}

inline Set Set::coalesce() const {
  ctx.lock();
  isl_set * res =  isl_set_coalesce((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_coalesce returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline BasicSet Set::coefficients() const {
  ctx.lock();
  isl_basic_set * res =  isl_set_coefficients((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_coefficients returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Set Set::complement() const {
  ctx.lock();
  isl_set * res =  isl_set_complement((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_complement returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::computeDivs() const {
  ctx.lock();
  isl_set * res =  isl_set_compute_divs((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_compute_divs returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline BasicSet Set::convexHull() const {
  ctx.lock();
  isl_basic_set * res =  isl_set_convex_hull((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_convex_hull returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Val Set::countVal() const {
  ctx.lock();
  isl_val * res =  isl_set_count_val((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_count_val returned a NULL pointer.");
  }
  return Val(ctx, res);
}

inline Set Set::detectEqualities() const {
  ctx.lock();
  isl_set * res =  isl_set_detect_equalities((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_detect_equalities returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline unsigned int Set::dim(DimType type) const {
  ctx.lock();
  unsigned int res =  isl_set_dim((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return res;
}

inline Bool Set::dimHasAnyLowerBound(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_bool res =  isl_set_dim_has_any_lower_bound((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  return (Bool)res;
}

inline Bool Set::dimHasAnyUpperBound(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_bool res =  isl_set_dim_has_any_upper_bound((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  return (Bool)res;
}

inline Bool Set::dimHasLowerBound(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_bool res =  isl_set_dim_has_lower_bound((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  return (Bool)res;
}

inline Bool Set::dimHasUpperBound(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_bool res =  isl_set_dim_has_upper_bound((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  return (Bool)res;
}

inline int Set::dimIsBounded(DimType type, unsigned int pos) const {
  ctx.lock();
  int res =  isl_set_dim_is_bounded((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  return res;
}

inline PwAff Set::dimMax(int pos) const {
  ctx.lock();
  isl_pw_aff * res =  isl_set_dim_max((*this).GetCopy(), pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_dim_max returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline PwAff Set::dimMin(int pos) const {
  ctx.lock();
  isl_pw_aff * res =  isl_set_dim_min((*this).GetCopy(), pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_dim_min returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Set Set::dropConstraintsInvolvingDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_set * res =  isl_set_drop_constraints_involving_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_drop_constraints_involving_dims returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline void Set::dump() const {
  ctx.lock();
   isl_set_dump((*this).Get());
  ctx.unlock();
}

inline Set Set::flatProduct(const Set &set2) const {
  ctx.lock();
  isl_set * res =  isl_set_flat_product((*this).GetCopy(), (set2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_flat_product returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::flatten() const {
  ctx.lock();
  isl_set * res =  isl_set_flatten((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_flatten returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Map Set::flattenMap() const {
  ctx.lock();
  isl_map * res =  isl_set_flatten_map((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_flatten_map returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Stat Set::foreachBasicSet(const std::function<isl_stat(isl_basic_set *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_set_foreach_basic_set((*this).Get(), get_fn_ptr<18>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline Stat Set::foreachPoint(const std::function<isl_stat(isl_point *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_set_foreach_point((*this).Get(), get_fn_ptr<19>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline Id Set::getDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_id * res =  isl_set_get_dim_id((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_get_dim_id returned a NULL pointer.");
  }
  return Id(ctx, res);
}

inline std::string Set::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  const char * res =  isl_set_get_dim_name((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_set_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Space Set::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_set_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline Id Set::getTupleId() const {
  ctx.lock();
  isl_id * res =  isl_set_get_tuple_id((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_get_tuple_id returned a NULL pointer.");
  }
  return Id(ctx, res);
}

inline std::string Set::getTupleName() const {
  ctx.lock();
  const char * res =  isl_set_get_tuple_name((*this).Get());
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_set_get_tuple_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Set Set::gist(const Set &context) const {
  ctx.lock();
  isl_set * res =  isl_set_gist((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_gist returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::gistBasicSet(const BasicSet &context) const {
  ctx.lock();
  isl_set * res =  isl_set_gist_basic_set((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_gist_basic_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::gistParams(const Set &context) const {
  ctx.lock();
  isl_set * res =  isl_set_gist_params((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_gist_params returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Bool Set::hasDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_bool res =  isl_set_has_dim_id((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  return (Bool)res;
}

inline Bool Set::hasDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_bool res =  isl_set_has_dim_name((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  return (Bool)res;
}

inline int Set::hasEqualSpace(const Set &set2) const {
  ctx.lock();
  int res =  isl_set_has_equal_space((*this).Get(), (set2).Get());
  ctx.unlock();
  return res;
}

inline Bool Set::hasTupleId() const {
  ctx.lock();
  isl_bool res =  isl_set_has_tuple_id((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Set::hasTupleName() const {
  ctx.lock();
  isl_bool res =  isl_set_has_tuple_name((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Map Set::identity() const {
  ctx.lock();
  isl_map * res =  isl_set_identity((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_identity returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline PwAff Set::indicatorFunction() const {
  ctx.lock();
  isl_pw_aff * res =  isl_set_indicator_function((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_indicator_function returned a NULL pointer.");
  }
  return PwAff(ctx, res);
}

inline Set Set::insertDims(DimType type, unsigned int pos, unsigned int n) const {
  ctx.lock();
  isl_set * res =  isl_set_insert_dims((*this).GetCopy(), (enum isl_dim_type)type, pos, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_insert_dims returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::intersect(const Set &set2) const {
  ctx.lock();
  isl_set * res =  isl_set_intersect((*this).GetCopy(), (set2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_intersect returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::intersectParams(const Set &params) const {
  ctx.lock();
  isl_set * res =  isl_set_intersect_params((*this).GetCopy(), (params).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_intersect_params returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Bool Set::involvesDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_bool res =  isl_set_involves_dims((*this).Get(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  return (Bool)res;
}

inline int Set::isBounded() const {
  ctx.lock();
  int res =  isl_set_is_bounded((*this).Get());
  ctx.unlock();
  return res;
}

inline Bool Set::isDisjoint(const Set &set2) const {
  ctx.lock();
  isl_bool res =  isl_set_is_disjoint((*this).Get(), (set2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Set::isEmpty() const {
  ctx.lock();
  isl_bool res =  isl_set_is_empty((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Set::isEqual(const Set &set2) const {
  ctx.lock();
  isl_bool res =  isl_set_is_equal((*this).Get(), (set2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Set::isSingleton() const {
  ctx.lock();
  isl_bool res =  isl_set_is_singleton((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Set::isStrictSubset(const Set &set2) const {
  ctx.lock();
  isl_bool res =  isl_set_is_strict_subset((*this).Get(), (set2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Set::isSubset(const Set &set2) const {
  ctx.lock();
  isl_bool res =  isl_set_is_subset((*this).Get(), (set2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool Set::isWrapping() const {
  ctx.lock();
  isl_bool res =  isl_set_is_wrapping((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Map Set::lexGeSet(const Set &set2) const {
  ctx.lock();
  isl_map * res =  isl_set_lex_ge_set((*this).GetCopy(), (set2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_lex_ge_set returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Set::lexGtSet(const Set &set2) const {
  ctx.lock();
  isl_map * res =  isl_set_lex_gt_set((*this).GetCopy(), (set2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_lex_gt_set returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Set::lexLeSet(const Set &set2) const {
  ctx.lock();
  isl_map * res =  isl_set_lex_le_set((*this).GetCopy(), (set2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_lex_le_set returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Map Set::lexLtSet(const Set &set2) const {
  ctx.lock();
  isl_map * res =  isl_set_lex_lt_set((*this).GetCopy(), (set2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_lex_lt_set returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Set Set::lexmax() const {
  ctx.lock();
  isl_set * res =  isl_set_lexmax((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_lexmax returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline PwMultiAff Set::lexmaxPwMultiAff() const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_set_lexmax_pw_multi_aff((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_lexmax_pw_multi_aff returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline Set Set::lexmin() const {
  ctx.lock();
  isl_set * res =  isl_set_lexmin((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_lexmin returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline PwMultiAff Set::lexminPwMultiAff() const {
  ctx.lock();
  isl_pw_multi_aff * res =  isl_set_lexmin_pw_multi_aff((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_lexmin_pw_multi_aff returned a NULL pointer.");
  }
  return PwMultiAff(ctx, res);
}

inline Set Set::lift() const {
  ctx.lock();
  isl_set * res =  isl_set_lift((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_lift returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Map Set::lifting() const {
  ctx.lock();
  isl_map * res =  isl_set_lifting((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_lifting returned a NULL pointer.");
  }
  return Map(ctx, res);
}

inline Set Set::makeDisjoint() const {
  ctx.lock();
  isl_set * res =  isl_set_make_disjoint((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_make_disjoint returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  isl_set * res =  isl_set_move_dims((*this).GetCopy(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_move_dims returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline int Set::nBasicSet() const {
  ctx.lock();
  int res =  isl_set_n_basic_set((*this).Get());
  ctx.unlock();
  return res;
}

inline Set Set::neg() const {
  ctx.lock();
  isl_set * res =  isl_set_neg((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_neg returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline BasicSet Set::polyhedralHull() const {
  ctx.lock();
  isl_basic_set * res =  isl_set_polyhedral_hull((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_polyhedral_hull returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Set Set::preimageMultiAff(const MultiAff &ma) const {
  ctx.lock();
  isl_set * res =  isl_set_preimage_multi_aff((*this).GetCopy(), (ma).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_preimage_multi_aff returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::preimageMultiPwAff(const MultiPwAff &mpa) const {
  ctx.lock();
  isl_set * res =  isl_set_preimage_multi_pw_aff((*this).GetCopy(), (mpa).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_preimage_multi_pw_aff returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::preimagePwMultiAff(const PwMultiAff &pma) const {
  ctx.lock();
  isl_set * res =  isl_set_preimage_pw_multi_aff((*this).GetCopy(), (pma).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_preimage_pw_multi_aff returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::product(const Set &set2) const {
  ctx.lock();
  isl_set * res =  isl_set_product((*this).GetCopy(), (set2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_product returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::projectOut(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_set * res =  isl_set_project_out((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_project_out returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::recessionCone() const {
  ctx.lock();
  isl_set * res =  isl_set_recession_cone((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_recession_cone returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::removeDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_set * res =  isl_set_remove_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_remove_dims returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::removeDivs() const {
  ctx.lock();
  isl_set * res =  isl_set_remove_divs((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_remove_divs returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::removeDivsInvolvingDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_set * res =  isl_set_remove_divs_involving_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_remove_divs_involving_dims returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::removeUnknownDivs() const {
  ctx.lock();
  isl_set * res =  isl_set_remove_unknown_divs((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_remove_unknown_divs returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::resetTupleId() const {
  ctx.lock();
  isl_set * res =  isl_set_reset_tuple_id((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_reset_tuple_id returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline BasicSet Set::sample() const {
  ctx.lock();
  isl_basic_set * res =  isl_set_sample((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_sample returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Point Set::samplePoint() const {
  ctx.lock();
  isl_point * res =  isl_set_sample_point((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_sample_point returned a NULL pointer.");
  }
  return Point(ctx, res);
}

inline Set Set::setDimId(DimType type, unsigned int pos, const Id &id) const {
  ctx.lock();
  isl_set * res =  isl_set_set_dim_id((*this).GetCopy(), (enum isl_dim_type)type, pos, (id).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_set_dim_id returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::setTupleId(const Id &id) const {
  ctx.lock();
  isl_set * res =  isl_set_set_tuple_id((*this).GetCopy(), (id).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_set_tuple_id returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline BasicSet Set::simpleHull() const {
  ctx.lock();
  isl_basic_set * res =  isl_set_simple_hull((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_simple_hull returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline int Set::size() const {
  ctx.lock();
  int res =  isl_set_size((*this).Get());
  ctx.unlock();
  return res;
}

inline BasicSet Set::solutions() const {
  ctx.lock();
  isl_basic_set * res =  isl_set_solutions((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_solutions returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Set Set::splitDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_set * res =  isl_set_split_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_split_dims returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::subtract(const Set &set2) const {
  ctx.lock();
  isl_set * res =  isl_set_subtract((*this).GetCopy(), (set2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_subtract returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set Set::sum(const Set &set2) const {
  ctx.lock();
  isl_set * res =  isl_set_sum((*this).GetCopy(), (set2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_sum returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline std::string Set::toStr() const {
  ctx.lock();
  char * res =  isl_set_to_str((*this).Get());
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_set_to_str returned a NULL pointer.");
  }
  res_ = res;
  free((void *)res);
  return res_;
}

inline Set Set::union_(const Set &set2) const {
  ctx.lock();
  isl_set * res =  isl_set_union((*this).GetCopy(), (set2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_union returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline BasicSet Set::unshiftedSimpleHull() const {
  ctx.lock();
  isl_basic_set * res =  isl_set_unshifted_simple_hull((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_unshifted_simple_hull returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Map Set::unwrap() const {
  ctx.lock();
  isl_map * res =  isl_set_unwrap((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_set_unwrap returned a NULL pointer.");
  }
  return Map(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_Set_IMPL_H
