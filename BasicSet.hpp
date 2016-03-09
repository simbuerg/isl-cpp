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

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_set_read_from_str returned a NULL pointer.");
  }

  return BasicSet(_ctx, That);
}

inline BasicSet BasicSet::fromPoint(const Point &pnt) {
  const Ctx &_ctx = pnt.Context();
  _ctx.lock();
  isl_basic_set *That = isl_basic_set_from_point((pnt).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_set_from_point returned a NULL pointer.");
  }

  return BasicSet(_ctx, That);
}

inline BasicSet BasicSet::boxFromPoints(const Point &pnt1, const Point &pnt2) {
  const Ctx &_ctx = pnt2.Context();
  _ctx.lock();
  isl_basic_set *That = isl_basic_set_box_from_points((pnt1).GetCopy(), (pnt2).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_set_box_from_points returned a NULL pointer.");
  }

  return BasicSet(_ctx, That);
}

inline BasicSet BasicSet::fromConstraintMatrices(const Space &dim, const Mat &eq, const Mat &ineq, DimType c1, DimType c2, DimType c3, DimType c4) {
  const Ctx &_ctx = ineq.Context();
  _ctx.lock();
  isl_basic_set *That = isl_basic_set_from_constraint_matrices((dim).GetCopy(), (eq).GetCopy(), (ineq).GetCopy(), (enum isl_dim_type)c1, (enum isl_dim_type)c2, (enum isl_dim_type)c3, (enum isl_dim_type)c4);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_basic_set_from_constraint_matrices returned a NULL pointer.");
  }

  return BasicSet(_ctx, That);
}

inline BasicSet BasicSet::fromConstraint(const Constraint &constraint) {
  const Ctx &_ctx = constraint.Context();
  _ctx.lock();
  isl_basic_set *That = isl_basic_set_from_constraint((constraint).Get());

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

inline BasicSet BasicSet::addConstraint(const Constraint &constraint) const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_add_constraint((*this).GetCopy(), (constraint).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_add_constraint returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::addDims(DimType type, unsigned int n) const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_add_dims((*this).GetCopy(), (enum isl_dim_type)type, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_add_dims returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::affineHull() const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_affine_hull((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_affine_hull returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::alignParams(const Space &model) const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_align_params((*this).GetCopy(), (model).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_align_params returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::apply(const BasicMap &bmap) const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_apply((*this).GetCopy(), (bmap).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_apply returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::coefficients() const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_coefficients((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_coefficients returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Set BasicSet::computeDivs() const {
  ctx.lock();
  struct isl_set * res =  isl_basic_set_compute_divs((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_compute_divs returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline BasicSet BasicSet::detectEqualities() const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_detect_equalities((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_detect_equalities returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline unsigned int BasicSet::dim(DimType type) const {
  ctx.lock();
  unsigned int res =  isl_basic_set_dim((*this).Get(), (enum isl_dim_type)type);
  ctx.unlock();
  return res;
}

inline BasicSet BasicSet::dropConstraintsInvolvingDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_drop_constraints_involving_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_drop_constraints_involving_dims returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::dropConstraintsNotInvolvingDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_drop_constraints_not_involving_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_drop_constraints_not_involving_dims returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::eliminate(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_eliminate((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_eliminate returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Mat BasicSet::equalitiesMatrix(DimType c1, DimType c2, DimType c3, DimType c4) const {
  ctx.lock();
  isl_mat * res =  isl_basic_set_equalities_matrix((*this).Get(), (enum isl_dim_type)c1, (enum isl_dim_type)c2, (enum isl_dim_type)c3, (enum isl_dim_type)c4);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_equalities_matrix returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline BasicSet BasicSet::flatProduct(const BasicSet &bset2) const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_flat_product((*this).GetCopy(), (bset2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_flat_product returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::flatten() const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_flatten((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_flatten returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Stat BasicSet::foreachBoundPair(DimType type, unsigned int pos, const std::function<isl_stat(isl_constraint *, isl_constraint *, isl_basic_set *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_basic_set_foreach_bound_pair((*this).Get(), (enum isl_dim_type)type, pos, get_fn_ptr<2>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline Stat BasicSet::foreachConstraint(const std::function<isl_stat(isl_constraint *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_basic_set_foreach_constraint((*this).Get(), get_fn_ptr<3>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline Id BasicSet::getDimId(DimType type, unsigned int pos) const {
  ctx.lock();
  isl_id * res =  isl_basic_set_get_dim_id((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_get_dim_id returned a NULL pointer.");
  }
  return Id(ctx, res);
}

inline std::string BasicSet::getDimName(DimType type, unsigned int pos) const {
  ctx.lock();
  const char * res =  isl_basic_set_get_dim_name((*this).Get(), (enum isl_dim_type)type, pos);
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_basic_set_get_dim_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline Space BasicSet::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_basic_set_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline std::string BasicSet::getTupleName() const {
  ctx.lock();
  const char * res =  isl_basic_set_get_tuple_name((*this).Get());
  ctx.unlock();
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_basic_set_get_tuple_name returned a NULL pointer.");
  }
  res_ = res;
  return res_;
}

inline BasicSet BasicSet::gist(const BasicSet &context) const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_gist((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_gist returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Mat BasicSet::inequalitiesMatrix(DimType c1, DimType c2, DimType c3, DimType c4) const {
  ctx.lock();
  isl_mat * res =  isl_basic_set_inequalities_matrix((*this).Get(), (enum isl_dim_type)c1, (enum isl_dim_type)c2, (enum isl_dim_type)c3, (enum isl_dim_type)c4);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_inequalities_matrix returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline BasicSet BasicSet::insertDims(DimType type, unsigned int pos, unsigned int n) const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_insert_dims((*this).GetCopy(), (enum isl_dim_type)type, pos, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_insert_dims returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::intersect(const BasicSet &bset2) const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_intersect((*this).GetCopy(), (bset2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_intersect returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::intersectParams(const BasicSet &bset2) const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_intersect_params((*this).GetCopy(), (bset2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_intersect_params returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Bool BasicSet::involvesDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_bool res =  isl_basic_set_involves_dims((*this).Get(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  return (Bool)res;
}

inline Bool BasicSet::isEmpty() const {
  ctx.lock();
  isl_bool res =  isl_basic_set_is_empty((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool BasicSet::isEqual(const BasicSet &bset2) const {
  ctx.lock();
  isl_bool res =  isl_basic_set_is_equal((*this).Get(), (bset2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool BasicSet::isSubset(const BasicSet &bset2) const {
  ctx.lock();
  isl_bool res =  isl_basic_set_is_subset((*this).Get(), (bset2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool BasicSet::isWrapping() const {
  ctx.lock();
  isl_bool res =  isl_basic_set_is_wrapping((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Set BasicSet::lexmax() const {
  ctx.lock();
  isl_set * res =  isl_basic_set_lexmax((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_lexmax returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Set BasicSet::lexmin() const {
  ctx.lock();
  isl_set * res =  isl_basic_set_lexmin((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_lexmin returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline BasicSet BasicSet::lift() const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_lift((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_lift returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_move_dims((*this).GetCopy(), (enum isl_dim_type)dst_type, dst_pos, (enum isl_dim_type)src_type, src_pos, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_move_dims returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline int BasicSet::nConstraint() const {
  ctx.lock();
  int res =  isl_basic_set_n_constraint((*this).Get());
  ctx.unlock();
  return res;
}

inline BasicSet BasicSet::neg() const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_neg((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_neg returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::projectOut(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_project_out((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_project_out returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Mat BasicSet::reducedBasis() const {
  ctx.lock();
  isl_mat * res =  isl_basic_set_reduced_basis((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_reduced_basis returned a NULL pointer.");
  }
  return Mat(ctx, res);
}

inline BasicSet BasicSet::removeDivs() const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_remove_divs((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_remove_divs returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::removeDivsInvolvingDims(DimType type, unsigned int first, unsigned int n) const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_remove_divs_involving_dims((*this).GetCopy(), (enum isl_dim_type)type, first, n);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_remove_divs_involving_dims returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::removeUnknownDivs() const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_remove_unknown_divs((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_remove_unknown_divs returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::sample() const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_sample((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_sample returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Point BasicSet::samplePoint() const {
  ctx.lock();
  isl_point * res =  isl_basic_set_sample_point((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_sample_point returned a NULL pointer.");
  }
  return Point(ctx, res);
}

inline BasicSet BasicSet::setTupleId(const Id &id) const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_set_tuple_id((*this).GetCopy(), (id).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_set_tuple_id returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline BasicSet BasicSet::solutions() const {
  ctx.lock();
  isl_basic_set * res =  isl_basic_set_solutions((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_solutions returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Set BasicSet::union_(const BasicSet &bset2) const {
  ctx.lock();
  isl_set * res =  isl_basic_set_union((*this).GetCopy(), (bset2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_union returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline BasicMap BasicSet::unwrap() const {
  ctx.lock();
  isl_basic_map * res =  isl_basic_set_unwrap((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_basic_set_unwrap returned a NULL pointer.");
  }
  return BasicMap(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_BasicSet_IMPL_H
