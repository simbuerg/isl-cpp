#ifndef ISL_CXX_UnionSet_IMPL_H
#define ISL_CXX_UnionSet_IMPL_H

#include "isl/UnionSet.h"

#include "isl/BasicSet.hpp"
#include "isl/Schedule.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/UnionMap.hpp"
#include "isl/UnionPwQpolynomialFold.hpp"
#include "isl/Bool.h"
#include "isl/Ctx.hpp"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/point.h"
#include "isl/set.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_union_set *UnionSet::GetCopy() const {
  return isl_union_set_copy((isl_union_set *)This);
}
inline UnionSet &UnionSet::operator=(const UnionSet &Other) {
  isl_union_set *New = Other.GetCopy();
  isl_union_set_free((isl_union_set *)This);
  This = New;
  return *this;
}
inline UnionSet UnionSet::fromBasicSet(const BasicSet &bset) {
  const Ctx &_ctx = bset.Context();
  _ctx.lock();
  BasicSet _cast_bset = bset.asBasicSet();
  isl_union_set *That = isl_union_set_from_basic_set((_cast_bset).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_set_from_basic_set returned a NULL pointer.");
  }

  return UnionSet(_ctx, That);
}

inline UnionSet UnionSet::fromSet(const Set &set) {
  const Ctx &_ctx = set.Context();
  _ctx.lock();
  Set _cast_set = set.asSet();
  isl_union_set *That = isl_union_set_from_set((_cast_set).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_set_from_set returned a NULL pointer.");
  }

  return UnionSet(_ctx, That);
}

inline UnionSet UnionSet::empty(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  Space _cast_dim = dim.asSpace();
  isl_union_set *That = isl_union_set_empty((_cast_dim).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_set_empty returned a NULL pointer.");
  }

  return UnionSet(_ctx, That);
}

inline UnionSet UnionSet::universe(const UnionSet &uset) {
  const Ctx &_ctx = uset.Context();
  _ctx.lock();
  UnionSet _cast_uset = uset.asUnionSet();
  isl_union_set *That = isl_union_set_universe((_cast_uset).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_set_universe returned a NULL pointer.");
  }

  return UnionSet(_ctx, That);
}

inline UnionSet UnionSet::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_union_set *That = isl_union_set_read_from_str((ctx.Get()), str.c_str());
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_set_read_from_str returned a NULL pointer.");
  }

  return UnionSet(_ctx, That);
}
inline UnionSet::~UnionSet() {
  isl_union_set_free((isl_union_set *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_union_set *UnionSet::Give() {
  isl_union_set *res = (isl_union_set *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_union_set *UnionSet::Get() const {  return (isl_union_set *)This;
}

inline UnionSet UnionSet::asUnionSet() const {
  return UnionSet(ctx, GetCopy());
}

inline UnionSet UnionSet::addSet(const Set &set) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_union_set_add_set
  isl_union_set * res =  isl_union_set_add_set((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_add_set returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::affineHull() const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_affine_hull
  isl_union_set * res =  isl_union_set_affine_hull((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_affine_hull returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::alignParams(const Space &model) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  Space _cast_model = model.asSpace();
  // Call isl_union_set_align_params
  isl_union_set * res =  isl_union_set_align_params((self).Give(), (_cast_model).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_align_params returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::apply(const UnionMap &umap) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  UnionMap _cast_umap = umap.asUnionMap();
  // Call isl_union_set_apply
  isl_union_set * res =  isl_union_set_apply((self).Give(), (_cast_umap).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_apply returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionPwQpolynomialFold UnionSet::applyUnionPwQpolynomialFold(const UnionPwQpolynomialFold &upwf, int * tight) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  UnionPwQpolynomialFold _cast_upwf = upwf.asUnionPwQpolynomialFold();
  // Call isl_union_set_apply_union_pw_qpolynomial_fold
  isl_union_pw_qpolynomial_fold * res =  isl_union_set_apply_union_pw_qpolynomial_fold((self).Give(), (_cast_upwf).Give(), tight);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_apply_union_pw_qpolynomial_fold returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(ctx, res);
}

inline UnionSet UnionSet::coalesce() const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_coalesce
  isl_union_set * res =  isl_union_set_coalesce((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_coalesce returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::coefficients() const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_coefficients
  isl_union_set * res =  isl_union_set_coefficients((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_coefficients returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline Schedule UnionSet::computeSchedule(const UnionMap &validity, const UnionMap &proximity) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  UnionMap _cast_validity = validity.asUnionMap();
  UnionMap _cast_proximity = proximity.asUnionMap();
  // Call isl_union_set_compute_schedule
  isl_schedule * res =  isl_union_set_compute_schedule((self).Give(), (_cast_validity).Give(), (_cast_proximity).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_compute_schedule returned a NULL pointer.");
  }
  return Schedule(ctx, res);
}

inline int UnionSet::contains(const Space &dim) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  Space _cast_dim = dim.asSpace();
  // Call isl_union_set_contains
  int res =  isl_union_set_contains((self).Get(), (_cast_dim).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline UnionSet UnionSet::detectEqualities() const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_detect_equalities
  isl_union_set * res =  isl_union_set_detect_equalities((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_detect_equalities returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline Set UnionSet::extractSet(const Space &dim) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  Space _cast_dim = dim.asSpace();
  // Call isl_union_set_extract_set
  isl_set * res =  isl_union_set_extract_set((self).Get(), (_cast_dim).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_extract_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Stat UnionSet::foreachPoint(const std::function<isl_stat(isl_point *, void *)> && fn, void * user) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_foreach_point
  isl_stat res =  isl_union_set_foreach_point((self).Get(), get_fn_ptr<27>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline Stat UnionSet::foreachSet(const std::function<isl_stat(isl_set *, void *)> && fn, void * user) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_foreach_set
  isl_stat res =  isl_union_set_foreach_set((self).Get(), get_fn_ptr<28>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline Space UnionSet::getSpace() const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_get_space
  isl_space * res =  isl_union_set_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline UnionSet UnionSet::gist(const UnionSet &context) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  UnionSet _cast_context = context.asUnionSet();
  // Call isl_union_set_gist
  isl_union_set * res =  isl_union_set_gist((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_gist returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::gistParams(const Set &set) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_union_set_gist_params
  isl_union_set * res =  isl_union_set_gist_params((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_gist_params returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionMap UnionSet::identity() const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_identity
  isl_union_map * res =  isl_union_set_identity((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_identity returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionSet UnionSet::intersect(const UnionSet &uset2) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  UnionSet _cast_uset2 = uset2.asUnionSet();
  // Call isl_union_set_intersect
  isl_union_set * res =  isl_union_set_intersect((self).Give(), (_cast_uset2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_intersect returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::intersectParams(const Set &set) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  Set _cast_set = set.asSet();
  // Call isl_union_set_intersect_params
  isl_union_set * res =  isl_union_set_intersect_params((self).Give(), (_cast_set).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_intersect_params returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline Bool UnionSet::isEmpty() const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_is_empty
  isl_bool res =  isl_union_set_is_empty((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool UnionSet::isEqual(const UnionSet &uset2) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  UnionSet _cast_uset2 = uset2.asUnionSet();
  // Call isl_union_set_is_equal
  isl_bool res =  isl_union_set_is_equal((self).Get(), (_cast_uset2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool UnionSet::isParams() const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_is_params
  isl_bool res =  isl_union_set_is_params((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool UnionSet::isStrictSubset(const UnionSet &uset2) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  UnionSet _cast_uset2 = uset2.asUnionSet();
  // Call isl_union_set_is_strict_subset
  isl_bool res =  isl_union_set_is_strict_subset((self).Get(), (_cast_uset2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool UnionSet::isSubset(const UnionSet &uset2) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  UnionSet _cast_uset2 = uset2.asUnionSet();
  // Call isl_union_set_is_subset
  isl_bool res =  isl_union_set_is_subset((self).Get(), (_cast_uset2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline UnionMap UnionSet::lexGeUnionSet(const UnionSet &uset2) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  UnionSet _cast_uset2 = uset2.asUnionSet();
  // Call isl_union_set_lex_ge_union_set
  isl_union_map * res =  isl_union_set_lex_ge_union_set((self).Give(), (_cast_uset2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_lex_ge_union_set returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionSet::lexGtUnionSet(const UnionSet &uset2) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  UnionSet _cast_uset2 = uset2.asUnionSet();
  // Call isl_union_set_lex_gt_union_set
  isl_union_map * res =  isl_union_set_lex_gt_union_set((self).Give(), (_cast_uset2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_lex_gt_union_set returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionSet::lexLeUnionSet(const UnionSet &uset2) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  UnionSet _cast_uset2 = uset2.asUnionSet();
  // Call isl_union_set_lex_le_union_set
  isl_union_map * res =  isl_union_set_lex_le_union_set((self).Give(), (_cast_uset2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_lex_le_union_set returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionSet::lexLtUnionSet(const UnionSet &uset2) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  UnionSet _cast_uset2 = uset2.asUnionSet();
  // Call isl_union_set_lex_lt_union_set
  isl_union_map * res =  isl_union_set_lex_lt_union_set((self).Give(), (_cast_uset2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_lex_lt_union_set returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionSet UnionSet::lexmax() const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_lexmax
  isl_union_set * res =  isl_union_set_lexmax((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_lexmax returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::lexmin() const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_lexmin
  isl_union_set * res =  isl_union_set_lexmin((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_lexmin returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::lift() const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_lift
  isl_union_set * res =  isl_union_set_lift((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_lift returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline int UnionSet::nSet() const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_n_set
  int res =  isl_union_set_n_set((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Set UnionSet::params() const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_params
  isl_set * res =  isl_union_set_params((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_params returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline UnionSet UnionSet::polyhedralHull() const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_polyhedral_hull
  isl_union_set * res =  isl_union_set_polyhedral_hull((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_polyhedral_hull returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline BasicSet UnionSet::sample() const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_sample
  isl_basic_set * res =  isl_union_set_sample((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_sample returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline UnionSet UnionSet::solutions() const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_solutions
  isl_union_set * res =  isl_union_set_solutions((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_solutions returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::subtract(const UnionSet &uset2) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  UnionSet _cast_uset2 = uset2.asUnionSet();
  // Call isl_union_set_subtract
  isl_union_set * res =  isl_union_set_subtract((self).Give(), (_cast_uset2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_subtract returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::union_(const UnionSet &uset2) const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  UnionSet _cast_uset2 = uset2.asUnionSet();
  // Call isl_union_set_union
  isl_union_set * res =  isl_union_set_union((self).Give(), (_cast_uset2).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_union returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionMap UnionSet::unwrap() const {
  ctx.lock();
  UnionSet self = asUnionSet();
  // Prepare arguments
  // Call isl_union_set_unwrap
  isl_union_map * res =  isl_union_set_unwrap((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_union_set_unwrap returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_UnionSet_IMPL_H
