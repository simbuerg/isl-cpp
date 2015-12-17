#ifndef ISL_CXX_UnionSet_H
#define ISL_CXX_UnionSet_H


#include "isl/union_set.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/point.h"
#include "isl/set.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class BasicSet;
class Schedule;
class Set;
class Space;
class UnionMap;
class UnionPwQpolynomialFold;

class UnionSet {
protected:

public:
  Ctx ctx;
  void * This;
  explicit UnionSet(Ctx ctx, isl_union_set *That) : ctx(ctx), This((void *)That) {}
  explicit UnionSet(Ctx ctx, void *That) : ctx(ctx), This(That) {}
  const Ctx &Context() const { return ctx; }
  isl_union_set *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_union_set *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_union_set *Get() const;

  /// \brief Constructor for isl_union_set_from_basic_set
  ///
  /// \param bset
  static UnionSet fromBasicSet(const BasicSet &bset);
  /// \brief Constructor for isl_union_set_from_set
  ///
  /// \param set
  static UnionSet fromSet(const Set &set);
  /// \brief Constructor for isl_union_set_empty
  ///
  /// \param dim
  static UnionSet empty(const Space &dim);
  /// \brief Constructor for isl_union_set_universe
  ///
  /// \param uset
  static UnionSet universe(const UnionSet &uset);
  /// \brief Constructor for isl_union_set_read_from_str
  ///
  /// \param ctx
  /// \param str
  static UnionSet readFromStr(const Ctx &ctx, std::string str);
  virtual ~UnionSet();

  virtual UnionSet asUnionSet() const;

  /// \brief Generated from  ::<isl_union_set_add_set>
  ///
  /// \param [in] set
  ///
  /// \returns A new UnionSet
  UnionSet addSet(const Set &set) const;

  /// \brief Generated from  ::<isl_union_set_affine_hull>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet affineHull() const;

  /// \brief Generated from  ::<isl_union_set_align_params>
  ///
  /// \param [in] model
  ///
  /// \returns A new UnionSet
  UnionSet alignParams(const Space &model) const;

  /// \brief Generated from  ::<isl_union_set_apply>
  ///
  /// \param [in] umap
  ///
  /// \returns A new UnionSet
  UnionSet apply(const UnionMap &umap) const;

  /// \brief Generated from  ::<isl_union_set_apply_union_pw_qpolynomial_fold>
  ///
  /// \param [in] upwf
  /// \param [in] tight
  ///
  /// \returns A new UnionPwQpolynomialFold
  UnionPwQpolynomialFold applyUnionPwQpolynomialFold(const UnionPwQpolynomialFold &upwf, int * tight) const;

  /// \brief Generated from  ::<isl_union_set_coalesce>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet coalesce() const;

  /// \brief Generated from  ::<isl_union_set_coefficients>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet coefficients() const;

  /// \brief Generated from  ::<isl_union_set_compute_schedule>
  ///
  /// \param [in] validity
  /// \param [in] proximity
  ///
  /// \returns A new Schedule
  Schedule computeSchedule(const UnionMap &validity, const UnionMap &proximity) const;

  /// \brief Generated from  ::<isl_union_set_contains>
  ///
  /// \param [in] dim
  ///
  /// \returns A new int
  int contains(const Space &dim) const;

  /// \brief Generated from  ::<isl_union_set_detect_equalities>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet detectEqualities() const;

  /// \brief Generated from  ::<isl_union_set_extract_set>
  ///
  /// \param [in] dim
  ///
  /// \returns A new Set
  Set extractSet(const Space &dim) const;

  /// \brief Generated from  ::<isl_union_set_foreach_point>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachPoint(const std::function<isl_stat(isl_point *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_union_set_foreach_set>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachSet(const std::function<isl_stat(isl_set *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_union_set_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_union_set_gist>
  ///
  /// \param [in] context
  ///
  /// \returns A new UnionSet
  UnionSet gist(const UnionSet &context) const;

  /// \brief Generated from  ::<isl_union_set_gist_params>
  ///
  /// \param [in] set
  ///
  /// \returns A new UnionSet
  UnionSet gistParams(const Set &set) const;

  /// \brief Generated from  ::<isl_union_set_identity>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap identity() const;

  /// \brief Generated from  ::<isl_union_set_intersect>
  ///
  /// \param [in] uset2
  ///
  /// \returns A new UnionSet
  UnionSet intersect(const UnionSet &uset2) const;

  /// \brief Generated from  ::<isl_union_set_intersect_params>
  ///
  /// \param [in] set
  ///
  /// \returns A new UnionSet
  UnionSet intersectParams(const Set &set) const;

  /// \brief Generated from  ::<isl_union_set_is_empty>
  ///
  ///
  /// \returns A new Bool
  Bool isEmpty() const;

  /// \brief Generated from  ::<isl_union_set_is_equal>
  ///
  /// \param [in] uset2
  ///
  /// \returns A new Bool
  Bool isEqual(const UnionSet &uset2) const;

  /// \brief Generated from  ::<isl_union_set_is_params>
  ///
  ///
  /// \returns A new Bool
  Bool isParams() const;

  /// \brief Generated from  ::<isl_union_set_is_strict_subset>
  ///
  /// \param [in] uset2
  ///
  /// \returns A new Bool
  Bool isStrictSubset(const UnionSet &uset2) const;

  /// \brief Generated from  ::<isl_union_set_is_subset>
  ///
  /// \param [in] uset2
  ///
  /// \returns A new Bool
  Bool isSubset(const UnionSet &uset2) const;

  /// \brief Generated from  ::<isl_union_set_lex_ge_union_set>
  ///
  /// \param [in] uset2
  ///
  /// \returns A new UnionMap
  UnionMap lexGeUnionSet(const UnionSet &uset2) const;

  /// \brief Generated from  ::<isl_union_set_lex_gt_union_set>
  ///
  /// \param [in] uset2
  ///
  /// \returns A new UnionMap
  UnionMap lexGtUnionSet(const UnionSet &uset2) const;

  /// \brief Generated from  ::<isl_union_set_lex_le_union_set>
  ///
  /// \param [in] uset2
  ///
  /// \returns A new UnionMap
  UnionMap lexLeUnionSet(const UnionSet &uset2) const;

  /// \brief Generated from  ::<isl_union_set_lex_lt_union_set>
  ///
  /// \param [in] uset2
  ///
  /// \returns A new UnionMap
  UnionMap lexLtUnionSet(const UnionSet &uset2) const;

  /// \brief Generated from  ::<isl_union_set_lexmax>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet lexmax() const;

  /// \brief Generated from  ::<isl_union_set_lexmin>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet lexmin() const;

  /// \brief Generated from  ::<isl_union_set_lift>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet lift() const;

  /// \brief Generated from  ::<isl_union_set_n_set>
  ///
  ///
  /// \returns A new int
  int nSet() const;

  /// \brief Generated from  ::<isl_union_set_params>
  ///
  ///
  /// \returns A new Set
  Set params() const;

  /// \brief Generated from  ::<isl_union_set_polyhedral_hull>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet polyhedralHull() const;

  /// \brief Generated from  ::<isl_union_set_sample>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet sample() const;

  /// \brief Generated from  ::<isl_union_set_solutions>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet solutions() const;

  /// \brief Generated from  ::<isl_union_set_subtract>
  ///
  /// \param [in] uset2
  ///
  /// \returns A new UnionSet
  UnionSet subtract(const UnionSet &uset2) const;

  /// \brief Generated from  ::<isl_union_set_union>
  ///
  /// \param [in] uset2
  ///
  /// \returns A new UnionSet
  UnionSet union_(const UnionSet &uset2) const;

  /// \brief Generated from  ::<isl_union_set_unwrap>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap unwrap() const;
  UnionSet(const UnionSet &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  UnionSet &operator=(const UnionSet &Other);
  UnionSet (UnionSet && Other) : ctx(Other.Context()), This(Other.This) {}
  UnionSet &operator=(UnionSet && Other) {
    isl_union_set *New = Other.Give();
    isl_union_set_free((isl_union_set *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const UnionSet &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_UnionSet_H
