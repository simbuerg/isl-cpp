#ifndef ISL_CXX_BasicSet_IMPL_H
#define ISL_CXX_BasicSet_IMPL_H

#include "isl/BasicSet.h"

#include "isl/BasicMap.hpp"
#include "isl/Constraint.hpp"
#include "isl/Id.hpp"
#include "isl/Mat.hpp"
#include "isl/Point.hpp"
#include "isl/Space.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/Set.hpp"
#include "isl/Stat.h"
#include "isl/constraint.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_basic_set *BasicSet::GetCopy() const {
  return isl_basic_set_copy((isl_basic_set *)This);
}
inline BasicSet &BasicSet::operator=(const BasicSet &Other) {
  isl_basic_set *New = Other.GetCopy();
  isl_basic_set_free((isl_basic_set *)This);
  This = New;
  return *this;
}
inline BasicSet BasicSet::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_basic_set *That = isl_basic_set_read_from_str((ctx.Get()), str.c_str());
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_set_read_from_str returned a NULL pointer.");
  }

  return BasicSet(_ctx, That);
}

inline BasicSet BasicSet::fromPoint(const Point &pnt) {
  const Ctx &_ctx = pnt.Context();
  _ctx.lock();
  Point _cast_pnt = pnt.asPoint();
  isl_basic_set *That = isl_basic_set_from_point((_cast_pnt).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_set_from_point returned a NULL pointer.");
  }

  return BasicSet(_ctx, That);
}

inline BasicSet BasicSet::boxFromPoints(const Point &pnt1, const Point &pnt2) {
  const Ctx &_ctx = pnt2.Context();
  _ctx.lock();
  Point _cast_pnt1 = pnt1.asPoint();
  Point _cast_pnt2 = pnt2.asPoint();
  isl_basic_set *That = isl_basic_set_box_from_points((_cast_pnt1).Give(), (_cast_pnt2).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_set_box_from_points returned a NULL pointer.");
  }

  return BasicSet(_ctx, That);
}

inline BasicSet BasicSet::fromConstraintMatrices(const Space &dim, const Mat &eq, const Mat &ineq, DimType c1, DimType c2, DimType c3, DimType c4) {
  const Ctx &_ctx = ineq.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  Mat _cast_eq = eq.asMat();
  Mat _cast_ineq = ineq.asMat();
  isl_basic_set *That = isl_basic_set_from_constraint_matrices((_cast_dim).Give(), (_cast_eq).Give(), (_cast_ineq).Give(), (enum isl_dim_type)c1, (enum isl_dim_type)c2, (enum isl_dim_type)c3, (enum isl_dim_type)c4);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_set_from_constraint_matrices returned a NULL pointer.");
  }

  return BasicSet(_ctx, That);
}

inline BasicSet BasicSet::fromConstraint(const Constraint &constraint) {
  const Ctx &_ctx = constraint.Context();
  _ctx.lock();
  Constraint _cast_constraint = constraint.asConstraint();
  isl_basic_set *That = isl_basic_set_from_constraint((_cast_constraint).Get());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_set_from_constraint returned a NULL pointer.");
  }

  return BasicSet(_ctx, That);
}
inline BasicSet::~BasicSet() {
  isl_basic_set_free((isl_basic_set *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_basic_set *BasicSet::Give() {
  isl_basic_set *res = (isl_basic_set *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_basic_set *BasicSet::Get() const {  return (isl_basic_set *)This;
}

inline BasicSet BasicSet::asBasicSet() const {
  return BasicSet(ctx, GetCopy());
}

inline Set BasicSet::asSet() const {
  return Set(*this);
}

inline UnionSet BasicSet::asUnionSet() const {
  return UnionSet(*this);
}

inline BasicSet BasicSet::addConstraint(const Constraint &constraint) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  Constraint _cast_constraint = constraint.asConstraint();
  // Call isl_basic_set_add_constraint
  isl_basic_set * res =  isl_basic_set_add_constraint((self).Give(), (_cast_constraint).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_add_constraint returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_add_dims
  isl_basic_set * res =  isl_basic_set_add_dims((self).Give(), (enum isl_dim_type)type, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_add_dims returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::affineHull() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_affine_hull
  isl_basic_set * res =  isl_basic_set_affine_hull((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_affine_hull returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::alignParams(const Space &model) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  Space _cast_model = model.asSpace();
  // Call isl_basic_set_align_params
  isl_basic_set * res =  isl_basic_set_align_params((self).Give(), (_cast_model).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_align_params returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::apply(const BasicMap &bmap) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  BasicMap _cast_bmap = bmap.asBasicMap();
  // Call isl_basic_set_apply
  isl_basic_set * res =  isl_basic_set_apply((self).Give(), (_cast_bmap).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_apply returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::coefficients() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_coefficients
  isl_basic_set * res =  isl_basic_set_coefficients((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_coefficients returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::detectEqualities() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_detect_equalities
  isl_basic_set * res =  isl_basic_set_detect_equalities((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_detect_equalities returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline unsigned int BasicSet::dim(DimType type) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_dim
  unsigned int res =  isl_basic_set_dim((self).Get(), (enum isl_dim_type)type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline BasicSet BasicSet::dropConstraintsInvolvingDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_drop_constraints_involving_dims
  isl_basic_set * res =  isl_basic_set_drop_constraints_involving_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_drop_constraints_involving_dims returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::dropConstraintsNotInvolvingDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_drop_constraints_not_involving_dims
  isl_basic_set * res =  isl_basic_set_drop_constraints_not_involving_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_drop_constraints_not_involving_dims returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::eliminate(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_eliminate
  isl_basic_set * res =  isl_basic_set_eliminate((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_eliminate returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Mat BasicSet::equalitiesMatrix(DimType c1, DimType c2, DimType c3, DimType c4) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_equalities_matrix
  isl_mat * res =  isl_basic_set_equalities_matrix((self).Get(), (enum isl_dim_type)c1, (enum isl_dim_type)c2, (enum isl_dim_type)c3, (enum isl_dim_type)c4);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_equalities_matrix returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline BasicSet BasicSet::flatProduct(const BasicSet &bset2) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  BasicSet _cast_bset2 = bset2.asBasicSet();
  // Call isl_basic_set_flat_product
  isl_basic_set * res =  isl_basic_set_flat_product((self).Give(), (_cast_bset2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_flat_product returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::flatten() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_flatten
  isl_basic_set * res =  isl_basic_set_flatten((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_flatten returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Stat BasicSet::foreachBoundPair(DimType type, unsigned int pos, const std::function<isl_stat(isl_constraint *, isl_constraint *, isl_basic_set *, void *)> && fn, void * user) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_foreach_bound_pair
  isl_stat res =  isl_basic_set_foreach_bound_pair((self).Get(), (enum isl_dim_type)type, pos, get_fn_ptr<5>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline Stat BasicSet::foreachConstraint(const std::function<isl_stat(isl_constraint *, void *)> && fn, void * user) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_foreach_constraint
  isl_stat res =  isl_basic_set_foreach_constraint((self).Get(), get_fn_ptr<6>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline Id BasicSet::getDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_get_dim_id
  isl_id * res =  isl_basic_set_get_dim_id((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_get_dim_id returned a NULL pointer.");
  }
  return Id(ctx, res);
}

inline std::string BasicSet::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_get_dim_name
  const char * res =  isl_basic_set_get_dim_name((self).Get(), (enum isl_dim_type)type, pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_basic_set_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Space BasicSet::getSpace() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_get_space
  isl_space * res =  isl_basic_set_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline std::string BasicSet::getTupleName() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_get_tuple_name
  const char * res =  isl_basic_set_get_tuple_name((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_basic_set_get_tuple_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline BasicSet BasicSet::gist(const BasicSet &context) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  BasicSet _cast_context = context.asBasicSet();
  // Call isl_basic_set_gist
  isl_basic_set * res =  isl_basic_set_gist((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_gist returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Mat BasicSet::inequalitiesMatrix(DimType c1, DimType c2, DimType c3, DimType c4) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_inequalities_matrix
  isl_mat * res =  isl_basic_set_inequalities_matrix((self).Get(), (enum isl_dim_type)c1, (enum isl_dim_type)c2, (enum isl_dim_type)c3, (enum isl_dim_type)c4);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_inequalities_matrix returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline BasicSet BasicSet::insertDims(DimType type, unsigned int pos, unsigned int n) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_insert_dims
  isl_basic_set * res =  isl_basic_set_insert_dims((self).Give(), (enum isl_dim_type)type, pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_insert_dims returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::intersect(const BasicSet &bset2) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  BasicSet _cast_bset2 = bset2.asBasicSet();
  // Call isl_basic_set_intersect
  isl_basic_set * res =  isl_basic_set_intersect((self).Give(), (_cast_bset2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_intersect returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::intersectParams(const BasicSet &bset2) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  BasicSet _cast_bset2 = bset2.asBasicSet();
  // Call isl_basic_set_intersect_params
  isl_basic_set * res =  isl_basic_set_intersect_params((self).Give(), (_cast_bset2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_intersect_params returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Bool BasicSet::involvesDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_involves_dims
  isl_bool res =  isl_basic_set_involves_dims((self).Get(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool BasicSet::isEmpty() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_is_empty
  isl_bool res =  isl_basic_set_is_empty((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool BasicSet::isEqual(const BasicSet &bset2) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  BasicSet _cast_bset2 = bset2.asBasicSet();
  // Call isl_basic_set_is_equal
  isl_bool res =  isl_basic_set_is_equal((self).Get(), (_cast_bset2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool BasicSet::isSubset(const BasicSet &bset2) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  BasicSet _cast_bset2 = bset2.asBasicSet();
  // Call isl_basic_set_is_subset
  isl_bool res =  isl_basic_set_is_subset((self).Get(), (_cast_bset2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool BasicSet::isWrapping() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_is_wrapping
  isl_bool res =  isl_basic_set_is_wrapping((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Set BasicSet::lexmax() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_lexmax
  isl_set * res =  isl_basic_set_lexmax((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_lexmax returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set BasicSet::lexmin() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_lexmin
  isl_set * res =  isl_basic_set_lexmin((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_lexmin returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline BasicSet BasicSet::lift() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_lift
  isl_basic_set * res =  isl_basic_set_lift((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_lift returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_move_dims
  isl_basic_set * res =  isl_basic_set_move_dims((self).Give(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_move_dims returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline int BasicSet::nConstraint() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_n_constraint
  int res =  isl_basic_set_n_constraint((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline BasicSet BasicSet::neg() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_neg
  isl_basic_set * res =  isl_basic_set_neg((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_neg returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::projectOut(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_project_out
  isl_basic_set * res =  isl_basic_set_project_out((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_project_out returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Mat BasicSet::reducedBasis() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_reduced_basis
  isl_mat * res =  isl_basic_set_reduced_basis((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_reduced_basis returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline BasicSet BasicSet::removeDivs() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_remove_divs
  isl_basic_set * res =  isl_basic_set_remove_divs((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_remove_divs returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::removeDivsInvolvingDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_remove_divs_involving_dims
  isl_basic_set * res =  isl_basic_set_remove_divs_involving_dims((self).Give(), (enum isl_dim_type)type, first, n);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_remove_divs_involving_dims returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::removeUnknownDivs() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_remove_unknown_divs
  isl_basic_set * res =  isl_basic_set_remove_unknown_divs((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_remove_unknown_divs returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::sample() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_sample
  isl_basic_set * res =  isl_basic_set_sample((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_sample returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Point BasicSet::samplePoint() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_sample_point
  isl_point * res =  isl_basic_set_sample_point((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_sample_point returned a NULL pointer.");
  }
  return Point(ctx, res);
}

inline BasicSet BasicSet::setTupleId(const Id &id) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_basic_set_set_tuple_id
  isl_basic_set * res =  isl_basic_set_set_tuple_id((self).Give(), (_cast_id).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_set_tuple_id returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::solutions() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_solutions
  isl_basic_set * res =  isl_basic_set_solutions((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_solutions returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Set BasicSet::union_(const BasicSet &bset2) const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  BasicSet _cast_bset2 = bset2.asBasicSet();
  // Call isl_basic_set_union
  isl_set * res =  isl_basic_set_union((self).Give(), (_cast_bset2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_union returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline BasicMap BasicSet::unwrap() const {
  ctx.lock();
  BasicSet self = asBasicSet();
  // Prepare arguments
  // Call isl_basic_set_unwrap
  isl_basic_map * res =  isl_basic_set_unwrap((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_basic_set_unwrap returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_BasicSet_IMPL_H
