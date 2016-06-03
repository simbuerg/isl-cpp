#ifndef ISL_CXX_Set_H
#define ISL_CXX_Set_H


#include "isl/set.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/UnionSet.h"
#include "isl/point.h"
#include "isl/set.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class BasicSet;
class Constraint;
class Id;
class Map;
class MultiAff;
class MultiPwAff;
class Point;
class PwAff;
class PwMultiAff;
class PwQpolynomialFold;
class Space;
class Val;

class Set {
protected:
  Ctx ctx;
  void * This;
public:
  explicit Set(Ctx ctx, isl_set *That) : ctx(ctx), This(That) {}
  Set() : ctx(Ctx(nullptr)), This(nullptr) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_set *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_set *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_set *Get() const;


  /// \brief Constructor for isl_set_from_union_set
  ///
  /// \param uset
  static Set fromUnionSet(const UnionSet &uset);


  /// \brief Constructor for isl_set_from_pw_aff
  ///
  /// \param pwaff
  static Set fromPwAff(const PwAff &pwaff);


  /// \brief Constructor for isl_set_read_from_str
  ///
  /// \param ctx
  /// \param str
  static Set readFromStr(const Ctx &ctx, std::string str);


  /// \brief Constructor for isl_set_from_basic_set
  ///
  /// \param bset
  static Set fromBasicSet(const BasicSet &bset);


  /// \brief Constructor for isl_set_from_point
  ///
  /// \param pnt
  static Set fromPoint(const Point &pnt);


  /// \brief Constructor for isl_set_box_from_points
  ///
  /// \param pnt1
  /// \param pnt2
  static Set boxFromPoints(const Point &pnt1, const Point &pnt2);
public:
  virtual ~Set();


  /// \brief Generated from  ::<isl_set_add_constraint>
  ///
  /// \param [in] constraint
  ///
  /// \returns A new Set
  Set addConstraint(const Constraint &constraint) const;

  /// \brief Generated from  ::<isl_set_add_dims>
  ///
  /// \param [in] type
  /// \param [in] n
  ///
  /// \returns A new Set
  Set addDims(DimType type, unsigned int n) const;

  /// \brief Generated from  ::<isl_set_affine_hull>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet affineHull() const;

  /// \brief Generated from  ::<isl_set_align_divs>
  ///
  ///
  /// \returns A new Set
  Set alignDivs() const;

  /// \brief Generated from  ::<isl_set_align_params>
  ///
  /// \param [in] model
  ///
  /// \returns A new Set
  Set alignParams(const Space &model) const;

  /// \brief Generated from  ::<isl_set_apply>
  ///
  /// \param [in] map
  ///
  /// \returns A new Set
  Set apply(const Map &map) const;

  /// \brief Generated from  ::<isl_set_apply_pw_qpolynomial_fold>
  ///
  /// \param [in] pwf
  /// \param [in] tight
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold applyPwQpolynomialFold(const PwQpolynomialFold &pwf, int * tight) const;

  /// \brief Generated from  ::<isl_set_coalesce>
  ///
  ///
  /// \returns A new Set
  Set coalesce() const;

  /// \brief Generated from  ::<isl_set_coefficients>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet coefficients() const;

  /// \brief Generated from  ::<isl_set_complement>
  ///
  ///
  /// \returns A new Set
  Set complement() const;

  /// \brief Generated from  ::<isl_set_compute_divs>
  ///
  ///
  /// \returns A new Set
  Set computeDivs() const;

  /// \brief Generated from  ::<isl_set_convex_hull>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet convexHull() const;

  /// \brief Generated from  ::<isl_set_count_val>
  ///
  ///
  /// \returns A new Val
  Val countVal() const;

  /// \brief Generated from  ::<isl_set_detect_equalities>
  ///
  ///
  /// \returns A new Set
  Set detectEqualities() const;

  /// \brief Generated from  ::<isl_set_dim>
  ///
  /// \param [in] type
  ///
  /// \returns A new unsigned int
  unsigned int dim(DimType type) const;

  /// \brief Generated from  ::<isl_set_dim_has_any_lower_bound>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Bool
  Bool dimHasAnyLowerBound(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_set_dim_has_any_upper_bound>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Bool
  Bool dimHasAnyUpperBound(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_set_dim_has_lower_bound>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Bool
  Bool dimHasLowerBound(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_set_dim_has_upper_bound>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Bool
  Bool dimHasUpperBound(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_set_dim_is_bounded>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new int
  int dimIsBounded(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_set_dim_max>
  ///
  /// \param [in] pos
  ///
  /// \returns A new PwAff
  PwAff dimMax(int pos) const;

  /// \brief Generated from  ::<isl_set_dim_min>
  ///
  /// \param [in] pos
  ///
  /// \returns A new PwAff
  PwAff dimMin(int pos) const;

  /// \brief Generated from  ::<isl_set_drop_constraints_involving_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Set
  Set dropConstraintsInvolvingDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_set_dump>
  ///
  ///
  /// \returns A new void
  void dump() const;

  /// \brief Generated from  ::<isl_set_flat_product>
  ///
  /// \param [in] set2
  ///
  /// \returns A new Set
  Set flatProduct(const Set &set2) const;

  /// \brief Generated from  ::<isl_set_flatten>
  ///
  ///
  /// \returns A new Set
  Set flatten() const;

  /// \brief Generated from  ::<isl_set_flatten_map>
  ///
  ///
  /// \returns A new Map
  Map flattenMap() const;

  /// \brief Generated from  ::<isl_set_foreach_basic_set>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachBasicSet(const std::function<isl_stat(isl_basic_set *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_set_foreach_point>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachPoint(const std::function<isl_stat(isl_point *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_set_get_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Id
  Id getDimId(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_set_get_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new std::string
  std::string getDimName(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_set_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_set_get_tuple_id>
  ///
  ///
  /// \returns A new Id
  Id getTupleId() const;

  /// \brief Generated from  ::<isl_set_get_tuple_name>
  ///
  ///
  /// \returns A new std::string
  std::string getTupleName() const;

  /// \brief Generated from  ::<isl_set_gist>
  ///
  /// \param [in] context
  ///
  /// \returns A new Set
  Set gist(const Set &context) const;

  /// \brief Generated from  ::<isl_set_gist_basic_set>
  ///
  /// \param [in] context
  ///
  /// \returns A new Set
  Set gistBasicSet(const BasicSet &context) const;

  /// \brief Generated from  ::<isl_set_gist_params>
  ///
  /// \param [in] context
  ///
  /// \returns A new Set
  Set gistParams(const Set &context) const;

  /// \brief Generated from  ::<isl_set_has_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Bool
  Bool hasDimId(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_set_has_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Bool
  Bool hasDimName(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_set_has_equal_space>
  ///
  /// \param [in] set2
  ///
  /// \returns A new int
  int hasEqualSpace(const Set &set2) const;

  /// \brief Generated from  ::<isl_set_has_tuple_id>
  ///
  ///
  /// \returns A new Bool
  Bool hasTupleId() const;

  /// \brief Generated from  ::<isl_set_has_tuple_name>
  ///
  ///
  /// \returns A new Bool
  Bool hasTupleName() const;

  /// \brief Generated from  ::<isl_set_identity>
  ///
  ///
  /// \returns A new Map
  Map identity() const;

  /// \brief Generated from  ::<isl_set_indicator_function>
  ///
  ///
  /// \returns A new PwAff
  PwAff indicatorFunction() const;

  /// \brief Generated from  ::<isl_set_insert_dims>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] n
  ///
  /// \returns A new Set
  Set insertDims(DimType type, unsigned int pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_set_intersect>
  ///
  /// \param [in] set2
  ///
  /// \returns A new Set
  Set intersect(const Set &set2) const;

  /// \brief Generated from  ::<isl_set_intersect_params>
  ///
  /// \param [in] params
  ///
  /// \returns A new Set
  Set intersectParams(const Set &params) const;

  /// \brief Generated from  ::<isl_set_involves_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Bool
  Bool involvesDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_set_is_bounded>
  ///
  ///
  /// \returns A new int
  int isBounded() const;

  /// \brief Generated from  ::<isl_set_is_disjoint>
  ///
  /// \param [in] set2
  ///
  /// \returns A new Bool
  Bool isDisjoint(const Set &set2) const;

  /// \brief Generated from  ::<isl_set_is_empty>
  ///
  ///
  /// \returns A new Bool
  Bool isEmpty() const;

  /// \brief Generated from  ::<isl_set_is_equal>
  ///
  /// \param [in] set2
  ///
  /// \returns A new Bool
  Bool isEqual(const Set &set2) const;

  /// \brief Generated from  ::<isl_set_is_singleton>
  ///
  ///
  /// \returns A new Bool
  Bool isSingleton() const;

  /// \brief Generated from  ::<isl_set_is_strict_subset>
  ///
  /// \param [in] set2
  ///
  /// \returns A new Bool
  Bool isStrictSubset(const Set &set2) const;

  /// \brief Generated from  ::<isl_set_is_subset>
  ///
  /// \param [in] set2
  ///
  /// \returns A new Bool
  Bool isSubset(const Set &set2) const;

  /// \brief Generated from  ::<isl_set_is_wrapping>
  ///
  ///
  /// \returns A new Bool
  Bool isWrapping() const;

  /// \brief Generated from  ::<isl_set_lex_ge_set>
  ///
  /// \param [in] set2
  ///
  /// \returns A new Map
  Map lexGeSet(const Set &set2) const;

  /// \brief Generated from  ::<isl_set_lex_gt_set>
  ///
  /// \param [in] set2
  ///
  /// \returns A new Map
  Map lexGtSet(const Set &set2) const;

  /// \brief Generated from  ::<isl_set_lex_le_set>
  ///
  /// \param [in] set2
  ///
  /// \returns A new Map
  Map lexLeSet(const Set &set2) const;

  /// \brief Generated from  ::<isl_set_lex_lt_set>
  ///
  /// \param [in] set2
  ///
  /// \returns A new Map
  Map lexLtSet(const Set &set2) const;

  /// \brief Generated from  ::<isl_set_lexmax>
  ///
  ///
  /// \returns A new Set
  Set lexmax() const;

  /// \brief Generated from  ::<isl_set_lexmax_pw_multi_aff>
  ///
  ///
  /// \returns A new PwMultiAff
  PwMultiAff lexmaxPwMultiAff() const;

  /// \brief Generated from  ::<isl_set_lexmin>
  ///
  ///
  /// \returns A new Set
  Set lexmin() const;

  /// \brief Generated from  ::<isl_set_lexmin_pw_multi_aff>
  ///
  ///
  /// \returns A new PwMultiAff
  PwMultiAff lexminPwMultiAff() const;

  /// \brief Generated from  ::<isl_set_lift>
  ///
  ///
  /// \returns A new Set
  Set lift() const;

  /// \brief Generated from  ::<isl_set_lifting>
  ///
  ///
  /// \returns A new Map
  Map lifting() const;

  /// \brief Generated from  ::<isl_set_make_disjoint>
  ///
  ///
  /// \returns A new Set
  Set makeDisjoint() const;

  /// \brief Generated from  ::<isl_set_move_dims>
  ///
  /// \param [in] dst_type
  /// \param [in] dst_pos
  /// \param [in] src_type
  /// \param [in] src_pos
  /// \param [in] n
  ///
  /// \returns A new Set
  Set moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_set_n_basic_set>
  ///
  ///
  /// \returns A new int
  int nBasicSet() const;

  /// \brief Generated from  ::<isl_set_neg>
  ///
  ///
  /// \returns A new Set
  Set neg() const;

  /// \brief Generated from  ::<isl_set_polyhedral_hull>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet polyhedralHull() const;

  /// \brief Generated from  ::<isl_set_preimage_multi_aff>
  ///
  /// \param [in] ma
  ///
  /// \returns A new Set
  Set preimageMultiAff(const MultiAff &ma) const;

  /// \brief Generated from  ::<isl_set_preimage_multi_pw_aff>
  ///
  /// \param [in] mpa
  ///
  /// \returns A new Set
  Set preimageMultiPwAff(const MultiPwAff &mpa) const;

  /// \brief Generated from  ::<isl_set_preimage_pw_multi_aff>
  ///
  /// \param [in] pma
  ///
  /// \returns A new Set
  Set preimagePwMultiAff(const PwMultiAff &pma) const;

  /// \brief Generated from  ::<isl_set_product>
  ///
  /// \param [in] set2
  ///
  /// \returns A new Set
  Set product(const Set &set2) const;

  /// \brief Generated from  ::<isl_set_project_out>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Set
  Set projectOut(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_set_recession_cone>
  ///
  ///
  /// \returns A new Set
  Set recessionCone() const;

  /// \brief Generated from  ::<isl_set_remove_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Set
  Set removeDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_set_remove_divs>
  ///
  ///
  /// \returns A new Set
  Set removeDivs() const;

  /// \brief Generated from  ::<isl_set_remove_divs_involving_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Set
  Set removeDivsInvolvingDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_set_remove_unknown_divs>
  ///
  ///
  /// \returns A new Set
  Set removeUnknownDivs() const;

  /// \brief Generated from  ::<isl_set_reset_tuple_id>
  ///
  ///
  /// \returns A new Set
  Set resetTupleId() const;

  /// \brief Generated from  ::<isl_set_sample>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet sample() const;

  /// \brief Generated from  ::<isl_set_sample_point>
  ///
  ///
  /// \returns A new Point
  Point samplePoint() const;

  /// \brief Generated from  ::<isl_set_set_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] id
  ///
  /// \returns A new Set
  Set setDimId(DimType type, unsigned int pos, const Id &id) const;

  /// \brief Generated from  ::<isl_set_set_tuple_id>
  ///
  /// \param [in] id
  ///
  /// \returns A new Set
  Set setTupleId(const Id &id) const;

  /// \brief Generated from  ::<isl_set_simple_hull>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet simpleHull() const;

  /// \brief Generated from  ::<isl_set_size>
  ///
  ///
  /// \returns A new int
  int size() const;

  /// \brief Generated from  ::<isl_set_solutions>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet solutions() const;

  /// \brief Generated from  ::<isl_set_split_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Set
  Set splitDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_set_subtract>
  ///
  /// \param [in] set2
  ///
  /// \returns A new Set
  Set subtract(const Set &set2) const;

  /// \brief Generated from  ::<isl_set_sum>
  ///
  /// \param [in] set2
  ///
  /// \returns A new Set
  Set sum(const Set &set2) const;

  /// \brief Generated from  ::<isl_set_to_str>
  ///
  ///
  /// \returns A new std::string
  std::string toStr() const;

  /// \brief Generated from  ::<isl_set_union>
  ///
  /// \param [in] set2
  ///
  /// \returns A new Set
  Set union_(const Set &set2) const;

  /// \brief Generated from  ::<isl_set_unshifted_simple_hull>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet unshiftedSimpleHull() const;

  /// \brief Generated from  ::<isl_set_unwrap>
  ///
  ///
  /// \returns A new Map
  Map unwrap() const;

  Set(const Set &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  Set &operator=(const Set &Other);
  Set (Set && Other) : ctx(Other.Context()), This(Other.Give()) {}
  Set &operator=(Set && Other) {
    isl_set *New = Other.Give();
    isl_set_free((isl_set *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const Set &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_Set_H
