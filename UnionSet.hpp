#ifndef ISL_CXX_UnionSet_IMPL_H
#define ISL_CXX_UnionSet_IMPL_H

#include "isl/UnionSet.h"

#include "isl/BasicSet.hpp"
#include "isl/Point.hpp"
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
  isl_union_set *That = isl_union_set_from_basic_set((bset).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_set_from_basic_set returned a NULL pointer.");
  }

  return UnionSet(_ctx, That);
}

inline UnionSet UnionSet::fromSet(const Set &set) {
  const Ctx &_ctx = set.Context();
  _ctx.lock();
  isl_union_set *That = isl_union_set_from_set((set).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_set_from_set returned a NULL pointer.");
  }

  return UnionSet(_ctx, That);
}

inline UnionSet UnionSet::empty(const Space &dim) {
  const Ctx &_ctx = dim.Context();
  _ctx.lock();
  isl_union_set *That = isl_union_set_empty((dim).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_set_empty returned a NULL pointer.");
  }

  return UnionSet(_ctx, That);
}

inline UnionSet UnionSet::universe(const UnionSet &uset) {
  const Ctx &_ctx = uset.Context();
  _ctx.lock();
  isl_union_set *That = isl_union_set_universe((uset).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_set_universe returned a NULL pointer.");
  }

  return UnionSet(_ctx, That);
}

inline UnionSet UnionSet::fromPoint(const Point &pnt) {
  const Ctx &_ctx = pnt.Context();
  _ctx.lock();
  isl_union_set *That = isl_union_set_from_point((pnt).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_union_set_from_point returned a NULL pointer.");
  }

  return UnionSet(_ctx, That);
}

inline UnionSet UnionSet::readFromStr(const Ctx &ctx, std::string str) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_union_set *That = isl_union_set_read_from_str((ctx.Get()), str.c_str());

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


inline UnionSet UnionSet::addSet(const Set &set) const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_add_set((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_add_set returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::affineHull() const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_affine_hull((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_affine_hull returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::alignParams(const Space &model) const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_align_params((*this).GetCopy(), (model).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_align_params returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::apply(const UnionMap &umap) const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_apply((*this).GetCopy(), (umap).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_apply returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionPwQpolynomialFold UnionSet::applyUnionPwQpolynomialFold(const UnionPwQpolynomialFold &upwf, int * tight) const {
  ctx.lock();
  isl_union_pw_qpolynomial_fold * res =  isl_union_set_apply_union_pw_qpolynomial_fold((*this).GetCopy(), (upwf).GetCopy(), tight);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_apply_union_pw_qpolynomial_fold returned a NULL pointer.");
  }
  return UnionPwQpolynomialFold(ctx, res);
}

inline UnionSet UnionSet::coalesce() const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_coalesce((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_coalesce returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::coefficients() const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_coefficients((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_coefficients returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::computeDivs() const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_compute_divs((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_compute_divs returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline Schedule UnionSet::computeSchedule(const UnionMap &validity, const UnionMap &proximity) const {
  ctx.lock();
  isl_schedule * res =  isl_union_set_compute_schedule((*this).GetCopy(), (validity).GetCopy(), (proximity).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_compute_schedule returned a NULL pointer.");
  }
  return Schedule(ctx, res);
}

inline int UnionSet::contains(const Space &dim) const {
  ctx.lock();
  int res =  isl_union_set_contains((*this).Get(), (dim).Get());
  ctx.unlock();
  return res;
}

inline UnionSet UnionSet::detectEqualities() const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_detect_equalities((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_detect_equalities returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline Set UnionSet::extractSet(const Space &dim) const {
  ctx.lock();
  isl_set * res =  isl_union_set_extract_set((*this).Get(), (dim).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_extract_set returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Stat UnionSet::foreachPoint(const std::function<isl_stat(isl_point *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_union_set_foreach_point((*this).Get(), get_fn_ptr<23>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline Stat UnionSet::foreachSet(const std::function<isl_stat(isl_set *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_union_set_foreach_set((*this).Get(), get_fn_ptr<24>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline Space UnionSet::getSpace() const {
  ctx.lock();
  isl_space * res =  isl_union_set_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline UnionSet UnionSet::gist(const UnionSet &context) const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_gist((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_gist returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::gistParams(const Set &set) const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_gist_params((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_gist_params returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionMap UnionSet::identity() const {
  ctx.lock();
  isl_union_map * res =  isl_union_set_identity((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_identity returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionSet UnionSet::intersect(const UnionSet &uset2) const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_intersect((*this).GetCopy(), (uset2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_intersect returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::intersectParams(const Set &set) const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_intersect_params((*this).GetCopy(), (set).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_intersect_params returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline Bool UnionSet::isEmpty() const {
  ctx.lock();
  isl_bool res =  isl_union_set_is_empty((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool UnionSet::isEqual(const UnionSet &uset2) const {
  ctx.lock();
  isl_bool res =  isl_union_set_is_equal((*this).Get(), (uset2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool UnionSet::isParams() const {
  ctx.lock();
  isl_bool res =  isl_union_set_is_params((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool UnionSet::isStrictSubset(const UnionSet &uset2) const {
  ctx.lock();
  isl_bool res =  isl_union_set_is_strict_subset((*this).Get(), (uset2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool UnionSet::isSubset(const UnionSet &uset2) const {
  ctx.lock();
  isl_bool res =  isl_union_set_is_subset((*this).Get(), (uset2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline UnionMap UnionSet::lexGeUnionSet(const UnionSet &uset2) const {
  ctx.lock();
  isl_union_map * res =  isl_union_set_lex_ge_union_set((*this).GetCopy(), (uset2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_lex_ge_union_set returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionSet::lexGtUnionSet(const UnionSet &uset2) const {
  ctx.lock();
  isl_union_map * res =  isl_union_set_lex_gt_union_set((*this).GetCopy(), (uset2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_lex_gt_union_set returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionSet::lexLeUnionSet(const UnionSet &uset2) const {
  ctx.lock();
  isl_union_map * res =  isl_union_set_lex_le_union_set((*this).GetCopy(), (uset2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_lex_le_union_set returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap UnionSet::lexLtUnionSet(const UnionSet &uset2) const {
  ctx.lock();
  isl_union_map * res =  isl_union_set_lex_lt_union_set((*this).GetCopy(), (uset2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_lex_lt_union_set returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionSet UnionSet::lexmax() const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_lexmax((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_lexmax returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::lexmin() const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_lexmin((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_lexmin returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::lift() const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_lift((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_lift returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline int UnionSet::nSet() const {
  ctx.lock();
  int res =  isl_union_set_n_set((*this).Get());
  ctx.unlock();
  return res;
}

inline Set UnionSet::params() const {
  ctx.lock();
  isl_set * res =  isl_union_set_params((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_params returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline UnionSet UnionSet::polyhedralHull() const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_polyhedral_hull((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_polyhedral_hull returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline BasicSet UnionSet::sample() const {
  ctx.lock();
  isl_basic_set * res =  isl_union_set_sample((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_sample returned a NULL pointer.");
  }
  return BasicSet(ctx, res);
}

inline Point UnionSet::samplePoint() const {
  ctx.lock();
  isl_point * res =  isl_union_set_sample_point((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_sample_point returned a NULL pointer.");
  }
  return Point(ctx, res);
}

inline UnionSet UnionSet::solutions() const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_solutions((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_solutions returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::subtract(const UnionSet &uset2) const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_subtract((*this).GetCopy(), (uset2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_subtract returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionSet UnionSet::union_(const UnionSet &uset2) const {
  ctx.lock();
  isl_union_set * res =  isl_union_set_union((*this).GetCopy(), (uset2).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_union returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline UnionMap UnionSet::unwrap() const {
  ctx.lock();
  isl_union_map * res =  isl_union_set_unwrap((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_union_set_unwrap returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_UnionSet_IMPL_H
