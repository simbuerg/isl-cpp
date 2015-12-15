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
#include "isl/Printer.hpp"
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
#include <ostream>

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
  Ctx _ctx = pwaff.Context();
  _ctx.lock();
  PwAff _cast_pwaff = pwaff.asPwAff();
  isl_set *That = isl_set_from_pw_aff((_cast_pwaff).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_set_from_pw_aff returned a NULL pointer.");
  }

  return Set(_ctx, That);
}

inline Set Set::readFromStr(const Ctx &ctx, std::string str) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_set *That = isl_set_read_from_str((ctx.Get()), str.c_str());
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_set_read_from_str returned a NULL pointer.");
  }

  return Set(_ctx, That);
}

inline Set Set::fromBasicSet(const BasicSet &bset) {
  Ctx _ctx = bset.Context();
  _ctx.lock();
  BasicSet _cast_bset = bset.asBasicSet();
  isl_set *That = isl_set_from_basic_set((_cast_bset).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_set_from_basic_set returned a NULL pointer.");
  }

  return Set(_ctx, That);
}

inline Set Set::fromPoint(const Point &pnt) {
  Ctx _ctx = pnt.Context();
  _ctx.lock();
  Point _cast_pnt = pnt.asPoint();
  isl_set *That = isl_set_from_point((_cast_pnt).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_set_from_point returned a NULL pointer.");
  }

  return Set(_ctx, That);
}

inline Set Set::boxFromPoints(const Point &pnt1, const Point &pnt2) {
  Ctx _ctx = pnt2.Context();
  _ctx.lock();
  Point _cast_pnt1 = pnt1.asPoint();
  Point _cast_pnt2 = pnt2.asPoint();
  isl_set *That = isl_set_box_from_points((_cast_pnt1).Give(), (_cast_pnt2).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_set_box_from_points returned a NULL pointer.");
  }

  return Set(_ctx, That);
}

inline Set Set::fromUnionSet(const UnionSet &uset) {
  Ctx _ctx = uset.Context();
  _ctx.lock();
  UnionSet _cast_uset = uset.asUnionSet();
  isl_set *That = isl_set_from_union_set((_cast_uset).Give());

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
inline std::string Set::toStr(isl::Format F) const {
  Printer p = Printer::toStr(ctx);
  p = p.setOutputFormat(F);
  p = p.printSet(*this);
  return p.getStr();
}

inline Set Set::asSet() const {
  return Set(GetCopy());
}

inline UnionSet Set::asUnionSet() const {
  return UnionSet(*this);
}

inline Set Set::addConstraint(const Constraint &constraint) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Constraint _cast_constraint = constraint.asConstraint();
  // Call isl_set_add_constraint
  isl_set * res =  isl_set_add_constraint((self).Give(), (_cast_constraint).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_add_constraint returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_add_dims
  isl_set * res =  isl_set_add_dims((self).Give(), (enum isl_dim_type)type, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_add_dims returned a NULL pointer.");
  }
  return Set(res);
}

inline BasicSet Set::affineHull() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_affine_hull
  isl_basic_set * res =  isl_set_affine_hull((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_affine_hull returned a NULL pointer.");
  }
  return BasicSet(res);
}

inline Set Set::alignDivs() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_align_divs
  isl_set * res =  isl_set_align_divs((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_align_divs returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::alignParams(const Space &model) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Space _cast_model = model.asSpace();
  // Call isl_set_align_params
  isl_set * res =  isl_set_align_params((self).Give(), (_cast_model).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_align_params returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::apply(const Map &map) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Map _cast_map = map.asMap();
  // Call isl_set_apply
  isl_set * res =  isl_set_apply((self).Give(), (_cast_map).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_apply returned a NULL pointer.");
  }
  return Set(res);
}

inline PwQpolynomialFold Set::applyPwQpolynomialFold(const PwQpolynomialFold &pwf, int * tight) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  PwQpolynomialFold _cast_pwf = pwf.asPwQpolynomialFold();
  // Call isl_set_apply_pw_qpolynomial_fold
  isl_pw_qpolynomial_fold * res =  isl_set_apply_pw_qpolynomial_fold((self).Give(), (_cast_pwf).Give(), tight);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_apply_pw_qpolynomial_fold returned a NULL pointer.");
  }
  return PwQpolynomialFold(res);
}

inline Set Set::coalesce() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_coalesce
  isl_set * res =  isl_set_coalesce((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_coalesce returned a NULL pointer.");
  }
  return Set(res);
}

inline BasicSet Set::coefficients() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_coefficients
  isl_basic_set * res =  isl_set_coefficients((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_coefficients returned a NULL pointer.");
  }
  return BasicSet(res);
}

inline Set Set::complement() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_complement
  isl_set * res =  isl_set_complement((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_complement returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::computeDivs() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_compute_divs
  isl_set * res =  isl_set_compute_divs((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_compute_divs returned a NULL pointer.");
  }
  return Set(res);
}

inline BasicSet Set::convexHull() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_convex_hull
  isl_basic_set * res =  isl_set_convex_hull((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_convex_hull returned a NULL pointer.");
  }
  return BasicSet(res);
}

inline Val Set::countVal() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_count_val
  isl_val * res =  isl_set_count_val((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_count_val returned a NULL pointer.");
  }
  return Val(res);
}

inline Set Set::detectEqualities() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_detect_equalities
  isl_set * res =  isl_set_detect_equalities((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_detect_equalities returned a NULL pointer.");
  }
  return Set(res);
}

inline unsigned int Set::dim(DimType type) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_dim
  unsigned int res =  isl_set_dim((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Bool Set::dimHasAnyLowerBound(DimType type, unsigned int pos) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_dim_has_any_lower_bound
  isl_bool res =  isl_set_dim_has_any_lower_bound((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Set::dimHasAnyUpperBound(DimType type, unsigned int pos) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_dim_has_any_upper_bound
  isl_bool res =  isl_set_dim_has_any_upper_bound((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Set::dimHasLowerBound(DimType type, unsigned int pos) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_dim_has_lower_bound
  isl_bool res =  isl_set_dim_has_lower_bound((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Set::dimHasUpperBound(DimType type, unsigned int pos) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_dim_has_upper_bound
  isl_bool res =  isl_set_dim_has_upper_bound((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline int Set::dimIsBounded(DimType type, unsigned int pos) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_dim_is_bounded
  int res =  isl_set_dim_is_bounded((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline PwAff Set::dimMax(int pos) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_dim_max
  isl_pw_aff * res =  isl_set_dim_max((self).Give(), pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_dim_max returned a NULL pointer.");
  }
  return PwAff(res);
}

inline PwAff Set::dimMin(int pos) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_dim_min
  isl_pw_aff * res =  isl_set_dim_min((self).Give(), pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_dim_min returned a NULL pointer.");
  }
  return PwAff(res);
}

inline Set Set::dropConstraintsInvolvingDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_drop_constraints_involving_dims
  isl_set * res =  isl_set_drop_constraints_involving_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_drop_constraints_involving_dims returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::flatProduct(const Set &set2) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Set _cast_set2 = set2.asSet();
  // Call isl_set_flat_product
  isl_set * res =  isl_set_flat_product((self).Give(), (_cast_set2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_flat_product returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::flatten() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_flatten
  isl_set * res =  isl_set_flatten((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_flatten returned a NULL pointer.");
  }
  return Set(res);
}

inline Map Set::flattenMap() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_flatten_map
  isl_map * res =  isl_set_flatten_map((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_flatten_map returned a NULL pointer.");
  }
  return Map(res);
}

inline Stat Set::foreachBasicSet(const std::function<isl_stat(isl_basic_set *, void *)> && fn, void * user) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_foreach_basic_set
  isl_stat res =  isl_set_foreach_basic_set((self).Get(), get_fn_ptr<22>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline Stat Set::foreachPoint(const std::function<isl_stat(isl_point *, void *)> && fn, void * user) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_foreach_point
  isl_stat res =  isl_set_foreach_point((self).Get(), get_fn_ptr<23>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline Id Set::getDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_get_dim_id
  isl_id * res =  isl_set_get_dim_id((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_get_dim_id returned a NULL pointer.");
  }
  return Id(res);
}

inline std::string Set::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_get_dim_name
  const char * res =  isl_set_get_dim_name((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_set_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Space Set::getSpace() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_get_space
  isl_space * res =  isl_set_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_get_space returned a NULL pointer.");
  }
  return Space(res);
}

inline Id Set::getTupleId() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_get_tuple_id
  isl_id * res =  isl_set_get_tuple_id((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_get_tuple_id returned a NULL pointer.");
  }
  return Id(res);
}

inline std::string Set::getTupleName() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_get_tuple_name
  const char * res =  isl_set_get_tuple_name((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_set_get_tuple_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Set Set::gist(const Set &context) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_set_gist
  isl_set * res =  isl_set_gist((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_gist returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::gistBasicSet(const BasicSet &context) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  BasicSet _cast_context = context.asBasicSet();
  // Call isl_set_gist_basic_set
  isl_set * res =  isl_set_gist_basic_set((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_gist_basic_set returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::gistParams(const Set &context) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_set_gist_params
  isl_set * res =  isl_set_gist_params((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_gist_params returned a NULL pointer.");
  }
  return Set(res);
}

inline Bool Set::hasDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_has_dim_id
  isl_bool res =  isl_set_has_dim_id((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Set::hasDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_has_dim_name
  isl_bool res =  isl_set_has_dim_name((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline int Set::hasEqualSpace(const Set &set2) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Set _cast_set2 = set2.asSet();
  // Call isl_set_has_equal_space
  int res =  isl_set_has_equal_space((self).Get(), (_cast_set2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Bool Set::hasTupleId() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_has_tuple_id
  isl_bool res =  isl_set_has_tuple_id((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Set::hasTupleName() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_has_tuple_name
  isl_bool res =  isl_set_has_tuple_name((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Map Set::identity() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_identity
  isl_map * res =  isl_set_identity((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_identity returned a NULL pointer.");
  }
  return Map(res);
}

inline PwAff Set::indicatorFunction() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_indicator_function
  isl_pw_aff * res =  isl_set_indicator_function((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_indicator_function returned a NULL pointer.");
  }
  return PwAff(res);
}

inline Set Set::insertDims(DimType type, unsigned int pos, unsigned int n) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_insert_dims
  isl_set * res =  isl_set_insert_dims((self).Give(), (enum isl_dim_type)type, pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_insert_dims returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::intersect(const Set &set2) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Set _cast_set2 = set2.asSet();
  // Call isl_set_intersect
  isl_set * res =  isl_set_intersect((self).Give(), (_cast_set2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_intersect returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::intersectParams(const Set &params) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Set _cast_params = params.asSet();
  // Call isl_set_intersect_params
  isl_set * res =  isl_set_intersect_params((self).Give(), (_cast_params).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_intersect_params returned a NULL pointer.");
  }
  return Set(res);
}

inline Bool Set::involvesDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_involves_dims
  isl_bool res =  isl_set_involves_dims((self).Get(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline int Set::isBounded() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_is_bounded
  int res =  isl_set_is_bounded((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Bool Set::isDisjoint(const Set &set2) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Set _cast_set2 = set2.asSet();
  // Call isl_set_is_disjoint
  isl_bool res =  isl_set_is_disjoint((self).Get(), (_cast_set2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Set::isEmpty() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_is_empty
  isl_bool res =  isl_set_is_empty((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Set::isEqual(const Set &set2) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Set _cast_set2 = set2.asSet();
  // Call isl_set_is_equal
  isl_bool res =  isl_set_is_equal((self).Get(), (_cast_set2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Set::isSingleton() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_is_singleton
  isl_bool res =  isl_set_is_singleton((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Set::isStrictSubset(const Set &set2) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Set _cast_set2 = set2.asSet();
  // Call isl_set_is_strict_subset
  isl_bool res =  isl_set_is_strict_subset((self).Get(), (_cast_set2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Set::isSubset(const Set &set2) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Set _cast_set2 = set2.asSet();
  // Call isl_set_is_subset
  isl_bool res =  isl_set_is_subset((self).Get(), (_cast_set2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool Set::isWrapping() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_is_wrapping
  isl_bool res =  isl_set_is_wrapping((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Map Set::lexGeSet(const Set &set2) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Set _cast_set2 = set2.asSet();
  // Call isl_set_lex_ge_set
  isl_map * res =  isl_set_lex_ge_set((self).Give(), (_cast_set2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_lex_ge_set returned a NULL pointer.");
  }
  return Map(res);
}

inline Map Set::lexGtSet(const Set &set2) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Set _cast_set2 = set2.asSet();
  // Call isl_set_lex_gt_set
  isl_map * res =  isl_set_lex_gt_set((self).Give(), (_cast_set2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_lex_gt_set returned a NULL pointer.");
  }
  return Map(res);
}

inline Map Set::lexLeSet(const Set &set2) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Set _cast_set2 = set2.asSet();
  // Call isl_set_lex_le_set
  isl_map * res =  isl_set_lex_le_set((self).Give(), (_cast_set2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_lex_le_set returned a NULL pointer.");
  }
  return Map(res);
}

inline Map Set::lexLtSet(const Set &set2) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Set _cast_set2 = set2.asSet();
  // Call isl_set_lex_lt_set
  isl_map * res =  isl_set_lex_lt_set((self).Give(), (_cast_set2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_lex_lt_set returned a NULL pointer.");
  }
  return Map(res);
}

inline Set Set::lexmax() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_lexmax
  isl_set * res =  isl_set_lexmax((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_lexmax returned a NULL pointer.");
  }
  return Set(res);
}

inline PwMultiAff Set::lexmaxPwMultiAff() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_lexmax_pw_multi_aff
  isl_pw_multi_aff * res =  isl_set_lexmax_pw_multi_aff((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_lexmax_pw_multi_aff returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline Set Set::lexmin() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_lexmin
  isl_set * res =  isl_set_lexmin((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_lexmin returned a NULL pointer.");
  }
  return Set(res);
}

inline PwMultiAff Set::lexminPwMultiAff() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_lexmin_pw_multi_aff
  isl_pw_multi_aff * res =  isl_set_lexmin_pw_multi_aff((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_lexmin_pw_multi_aff returned a NULL pointer.");
  }
  return PwMultiAff(res);
}

inline Set Set::lift() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_lift
  isl_set * res =  isl_set_lift((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_lift returned a NULL pointer.");
  }
  return Set(res);
}

inline Map Set::lifting() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_lifting
  isl_map * res =  isl_set_lifting((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_lifting returned a NULL pointer.");
  }
  return Map(res);
}

inline Set Set::makeDisjoint() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_make_disjoint
  isl_set * res =  isl_set_make_disjoint((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_make_disjoint returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_move_dims
  isl_set * res =  isl_set_move_dims((self).Give(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_move_dims returned a NULL pointer.");
  }
  return Set(res);
}

inline int Set::nBasicSet() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_n_basic_set
  int res =  isl_set_n_basic_set((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Set Set::neg() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_neg
  isl_set * res =  isl_set_neg((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_neg returned a NULL pointer.");
  }
  return Set(res);
}

inline BasicSet Set::polyhedralHull() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_polyhedral_hull
  isl_basic_set * res =  isl_set_polyhedral_hull((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_polyhedral_hull returned a NULL pointer.");
  }
  return BasicSet(res);
}

inline Set Set::preimageMultiAff(const MultiAff &ma) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  MultiAff _cast_ma = ma.asMultiAff();
  // Call isl_set_preimage_multi_aff
  isl_set * res =  isl_set_preimage_multi_aff((self).Give(), (_cast_ma).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_preimage_multi_aff returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::preimageMultiPwAff(const MultiPwAff &mpa) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  MultiPwAff _cast_mpa = mpa.asMultiPwAff();
  // Call isl_set_preimage_multi_pw_aff
  isl_set * res =  isl_set_preimage_multi_pw_aff((self).Give(), (_cast_mpa).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_preimage_multi_pw_aff returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::preimagePwMultiAff(const PwMultiAff &pma) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  PwMultiAff _cast_pma = pma.asPwMultiAff();
  // Call isl_set_preimage_pw_multi_aff
  isl_set * res =  isl_set_preimage_pw_multi_aff((self).Give(), (_cast_pma).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_preimage_pw_multi_aff returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::product(const Set &set2) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Set _cast_set2 = set2.asSet();
  // Call isl_set_product
  isl_set * res =  isl_set_product((self).Give(), (_cast_set2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_product returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::projectOut(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_project_out
  isl_set * res =  isl_set_project_out((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_project_out returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::recessionCone() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_recession_cone
  isl_set * res =  isl_set_recession_cone((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_recession_cone returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::removeDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_remove_dims
  isl_set * res =  isl_set_remove_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_remove_dims returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::removeDivs() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_remove_divs
  isl_set * res =  isl_set_remove_divs((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_remove_divs returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::removeDivsInvolvingDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_remove_divs_involving_dims
  isl_set * res =  isl_set_remove_divs_involving_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_remove_divs_involving_dims returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::removeUnknownDivs() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_remove_unknown_divs
  isl_set * res =  isl_set_remove_unknown_divs((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_remove_unknown_divs returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::resetTupleId() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_reset_tuple_id
  isl_set * res =  isl_set_reset_tuple_id((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_reset_tuple_id returned a NULL pointer.");
  }
  return Set(res);
}

inline BasicSet Set::sample() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_sample
  isl_basic_set * res =  isl_set_sample((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_sample returned a NULL pointer.");
  }
  return BasicSet(res);
}

inline Point Set::samplePoint() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_sample_point
  isl_point * res =  isl_set_sample_point((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_sample_point returned a NULL pointer.");
  }
  return Point(res);
}

inline Set Set::setDimId(DimType type, unsigned int pos, const Id &id) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_set_set_dim_id
  isl_set * res =  isl_set_set_dim_id((self).Give(), (enum isl_dim_type)type, pos, (_cast_id).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_set_dim_id returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::setTupleId(const Id &id) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_set_set_tuple_id
  isl_set * res =  isl_set_set_tuple_id((self).Give(), (_cast_id).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_set_tuple_id returned a NULL pointer.");
  }
  return Set(res);
}

inline BasicSet Set::simpleHull() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_simple_hull
  isl_basic_set * res =  isl_set_simple_hull((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_simple_hull returned a NULL pointer.");
  }
  return BasicSet(res);
}

inline int Set::size() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_size
  int res =  isl_set_size((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline BasicSet Set::solutions() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_solutions
  isl_basic_set * res =  isl_set_solutions((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_solutions returned a NULL pointer.");
  }
  return BasicSet(res);
}

inline Set Set::splitDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_split_dims
  isl_set * res =  isl_set_split_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_split_dims returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::subtract(const Set &set2) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Set _cast_set2 = set2.asSet();
  // Call isl_set_subtract
  isl_set * res =  isl_set_subtract((self).Give(), (_cast_set2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_subtract returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::sum(const Set &set2) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Set _cast_set2 = set2.asSet();
  // Call isl_set_sum
  isl_set * res =  isl_set_sum((self).Give(), (_cast_set2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_sum returned a NULL pointer.");
  }
  return Set(res);
}

inline Set Set::union_(const Set &set2) const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  Set _cast_set2 = set2.asSet();
  // Call isl_set_union
  isl_set * res =  isl_set_union((self).Give(), (_cast_set2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_union returned a NULL pointer.");
  }
  return Set(res);
}

inline BasicSet Set::unshiftedSimpleHull() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_unshifted_simple_hull
  isl_basic_set * res =  isl_set_unshifted_simple_hull((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_unshifted_simple_hull returned a NULL pointer.");
  }
  return BasicSet(res);
}

inline Map Set::unwrap() const {
  ctx.lock();
  Set self = asSet();
  // Prepare arguments
  // Call isl_set_unwrap
  isl_map * res =  isl_set_unwrap((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_set_unwrap returned a NULL pointer.");
  }
  return Map(res);
}

} // namespace isl
#endif //ISL_CXX_Set_IMPL_H
