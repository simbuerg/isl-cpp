#ifndef ISL_CXX_BasicMap_H
#define ISL_CXX_BasicMap_H


#include "isl/map.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/Map.h"
#include "isl/Stat.h"
#include "isl/constraint.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Aff;
class BasicSet;
class Constraint;
class Id;
class LocalSpace;
class Mat;
class MultiAff;
class Printer;
class PwMultiAff;
class Qpolynomial;
class Space;
class Val;

class BasicMap : public Map {
protected:
  explicit BasicMap(Ctx ctx, isl_basic_map *That) : Map(ctx, (void *)That) {/* empty */}
  explicit BasicMap(Ctx ctx, void *That) : Map(ctx, (void *)That) {/* empty */}

public:
  ///rief Wrap an existing isl object.
  ///
  /// This serves as an entry point into the C++ API.
  /// We take ownership of the isl object.
  ///
  /// \param That the isl_basic_map we want to wrap.
  explicit BasicMap(isl_basic_map *That) : BasicMap(Ctx(isl_basic_map_get_ctx(That)), That) {}
  isl_basic_map *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_basic_map *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_basic_map *Get() const;

  /// \brief Constructor for isl_basic_map_less_at
  ///
  /// \param dim
  /// \param pos
  static BasicMap lessAt(const Space &dim, unsigned int pos);
  /// \brief Constructor for isl_basic_map_more_at
  ///
  /// \param dim
  /// \param pos
  static BasicMap moreAt(const Space &dim, unsigned int pos);
  /// \brief Constructor for isl_basic_map_empty
  ///
  /// \param dim
  static BasicMap empty(const Space &dim);
  /// \brief Constructor for isl_basic_map_nat_universe
  ///
  /// \param dim
  static BasicMap natUniverse(const Space &dim);
  /// \brief Constructor for isl_basic_map_from_basic_set
  ///
  /// \param bset
  /// \param dim
  static BasicMap fromBasicSet(const BasicSet &bset, const Space &dim);
  /// \brief Constructor for isl_basic_map_read_from_str
  ///
  /// \param ctx
  /// \param str
  static BasicMap readFromStr(const Ctx &ctx, std::string str);
  /// \brief Constructor for isl_basic_map_from_domain
  ///
  /// \param bset
  static BasicMap fromDomain(const BasicSet &bset);
  /// \brief Constructor for isl_basic_map_from_range
  ///
  /// \param bset
  static BasicMap fromRange(const BasicSet &bset);
  /// \brief Constructor for isl_basic_map_from_domain_and_range
  ///
  /// \param domain
  /// \param range
  static BasicMap fromDomainAndRange(const BasicSet &domain, const BasicSet &range);
  /// \brief Constructor for isl_basic_map_from_constraint_matrices
  ///
  /// \param dim
  /// \param eq
  /// \param ineq
  /// \param c1
  /// \param c2
  /// \param c3
  /// \param c4
  /// \param c5
  static BasicMap fromConstraintMatrices(const Space &dim, const Mat &eq, const Mat &ineq, DimType c1, DimType c2, DimType c3, DimType c4, DimType c5);
  /// \brief Constructor for isl_basic_map_from_aff
  ///
  /// \param aff
  static BasicMap fromAff(const Aff &aff);
  /// \brief Constructor for isl_basic_map_from_multi_aff
  ///
  /// \param maff
  static BasicMap fromMultiAff(const MultiAff &maff);
  /// \brief Constructor for isl_basic_map_from_constraint
  ///
  /// \param constraint
  static BasicMap fromConstraint(const Constraint &constraint);
  /// \brief Constructor for isl_basic_map_from_qpolynomial
  ///
  /// \param qp
  static BasicMap fromQpolynomial(const Qpolynomial &qp);
  virtual ~BasicMap();
  std::string toStr(isl::Format F = isl::Format::FIsl) const;

  virtual BasicMap asBasicMap() const;

  virtual Map asMap() const override;

  virtual UnionMap asUnionMap() const override;

  /// \brief Generated from  ::<isl_basic_map_add_constraint>
  ///
  /// \param [in] constraint
  ///
  /// \returns A new BasicMap
  BasicMap addConstraint(const Constraint &constraint) const;

  /// \brief Generated from  ::<isl_basic_map_add_dims>
  ///
  /// \param [in] type
  /// \param [in] n
  ///
  /// \returns A new BasicMap
  BasicMap addDims(DimType type, unsigned int n) const;

  /// \brief Generated from  ::<isl_basic_map_affine_hull>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap affineHull() const;

  /// \brief Generated from  ::<isl_basic_map_align_params>
  ///
  /// \param [in] model
  ///
  /// \returns A new BasicMap
  BasicMap alignParams(const Space &model) const;

  /// \brief Generated from  ::<isl_basic_map_apply_domain>
  ///
  /// \param [in] bmap2
  ///
  /// \returns A new BasicMap
  BasicMap applyDomain(const BasicMap &bmap2) const;

  /// \brief Generated from  ::<isl_basic_map_apply_range>
  ///
  /// \param [in] bmap2
  ///
  /// \returns A new BasicMap
  BasicMap applyRange(const BasicMap &bmap2) const;

  /// \brief Generated from  ::<isl_basic_map_can_curry>
  ///
  ///
  /// \returns A new Bool
  Bool canCurry() const;

  /// \brief Generated from  ::<isl_basic_map_can_uncurry>
  ///
  ///
  /// \returns A new Bool
  Bool canUncurry() const;

  /// \brief Generated from  ::<isl_basic_map_can_zip>
  ///
  ///
  /// \returns A new Bool
  Bool canZip() const;

  /// \brief Generated from  ::<isl_basic_map_compute_divs>
  ///
  ///
  /// \returns A new Map
  Map computeDivs() const;

  /// \brief Generated from  ::<isl_basic_map_curry>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap curry() const;

  /// \brief Generated from  ::<isl_basic_map_deltas>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet deltas() const;

  /// \brief Generated from  ::<isl_basic_map_deltas_map>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap deltasMap() const;

  /// \brief Generated from  ::<isl_basic_map_detect_equalities>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap detectEqualities() const;

  /// \brief Generated from  ::<isl_basic_map_dim>
  ///
  /// \param [in] type
  ///
  /// \returns A new unsigned int
  unsigned int dim(DimType type) const;

  /// \brief Generated from  ::<isl_basic_map_domain>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet domain() const;

  /// \brief Generated from  ::<isl_basic_map_domain_map>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap domainMap() const;

  /// \brief Generated from  ::<isl_basic_map_domain_product>
  ///
  /// \param [in] bmap2
  ///
  /// \returns A new BasicMap
  BasicMap domainProduct(const BasicMap &bmap2) const;

  /// \brief Generated from  ::<isl_basic_map_drop_constraints_involving_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new BasicMap
  BasicMap dropConstraintsInvolvingDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_basic_map_eliminate>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new BasicMap
  BasicMap eliminate(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_basic_map_equalities_matrix>
  ///
  /// \param [in] c1
  /// \param [in] c2
  /// \param [in] c3
  /// \param [in] c4
  /// \param [in] c5
  ///
  /// \returns A new Mat
  Mat equalitiesMatrix(DimType c1, DimType c2, DimType c3, DimType c4, DimType c5) const;

  /// \brief Generated from  ::<isl_basic_map_equate>
  ///
  /// \param [in] type1
  /// \param [in] pos1
  /// \param [in] type2
  /// \param [in] pos2
  ///
  /// \returns A new BasicMap
  BasicMap equate(DimType type1, int pos1, DimType type2, int pos2) const;

  /// \brief Generated from  ::<isl_basic_map_fix_val>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] v
  ///
  /// \returns A new BasicMap
  BasicMap fixVal(DimType type, unsigned int pos, const Val &v) const;

  /// \brief Generated from  ::<isl_basic_map_flat_product>
  ///
  /// \param [in] bmap2
  ///
  /// \returns A new BasicMap
  BasicMap flatProduct(const BasicMap &bmap2) const;

  /// \brief Generated from  ::<isl_basic_map_flat_range_product>
  ///
  /// \param [in] bmap2
  ///
  /// \returns A new BasicMap
  BasicMap flatRangeProduct(const BasicMap &bmap2) const;

  /// \brief Generated from  ::<isl_basic_map_flatten>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap flatten() const;

  /// \brief Generated from  ::<isl_basic_map_flatten_domain>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap flattenDomain() const;

  /// \brief Generated from  ::<isl_basic_map_flatten_range>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap flattenRange() const;

  /// \brief Generated from  ::<isl_basic_map_foreach_constraint>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachConstraint(const std::function<isl_stat(isl_constraint *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_basic_map_get_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new std::string
  std::string getDimName(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_basic_map_get_div>
  ///
  /// \param [in] pos
  ///
  /// \returns A new Aff
  Aff getDiv(int pos) const;

  /// \brief Generated from  ::<isl_basic_map_get_local_space>
  ///
  ///
  /// \returns A new LocalSpace
  LocalSpace getLocalSpace() const;

  /// \brief Generated from  ::<isl_basic_map_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_basic_map_get_tuple_name>
  ///
  /// \param [in] type
  ///
  /// \returns A new std::string
  std::string getTupleName(DimType type) const;

  /// \brief Generated from  ::<isl_basic_map_gist>
  ///
  /// \param [in] context
  ///
  /// \returns A new BasicMap
  BasicMap gist(const BasicMap &context) const;

  /// \brief Generated from  ::<isl_basic_map_has_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Bool
  Bool hasDimId(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_basic_map_inequalities_matrix>
  ///
  /// \param [in] c1
  /// \param [in] c2
  /// \param [in] c3
  /// \param [in] c4
  /// \param [in] c5
  ///
  /// \returns A new Mat
  Mat inequalitiesMatrix(DimType c1, DimType c2, DimType c3, DimType c4, DimType c5) const;

  /// \brief Generated from  ::<isl_basic_map_insert_dims>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] n
  ///
  /// \returns A new BasicMap
  BasicMap insertDims(DimType type, unsigned int pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_basic_map_intersect>
  ///
  /// \param [in] bmap2
  ///
  /// \returns A new BasicMap
  BasicMap intersect(const BasicMap &bmap2) const;

  /// \brief Generated from  ::<isl_basic_map_intersect_domain>
  ///
  /// \param [in] bset
  ///
  /// \returns A new BasicMap
  BasicMap intersectDomain(const BasicSet &bset) const;

  /// \brief Generated from  ::<isl_basic_map_intersect_range>
  ///
  /// \param [in] bset
  ///
  /// \returns A new BasicMap
  BasicMap intersectRange(const BasicSet &bset) const;

  /// \brief Generated from  ::<isl_basic_map_involves_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Bool
  Bool involvesDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_basic_map_is_disjoint>
  ///
  /// \param [in] bmap2
  ///
  /// \returns A new Bool
  Bool isDisjoint(const BasicMap &bmap2) const;

  /// \brief Generated from  ::<isl_basic_map_is_empty>
  ///
  ///
  /// \returns A new Bool
  Bool isEmpty() const;

  /// \brief Generated from  ::<isl_basic_map_is_equal>
  ///
  /// \param [in] bmap2
  ///
  /// \returns A new Bool
  Bool isEqual(const BasicMap &bmap2) const;

  /// \brief Generated from  ::<isl_basic_map_is_rational>
  ///
  ///
  /// \returns A new int
  int isRational() const;

  /// \brief Generated from  ::<isl_basic_map_is_strict_subset>
  ///
  /// \param [in] bmap2
  ///
  /// \returns A new Bool
  Bool isStrictSubset(const BasicMap &bmap2) const;

  /// \brief Generated from  ::<isl_basic_map_is_subset>
  ///
  /// \param [in] bmap2
  ///
  /// \returns A new Bool
  Bool isSubset(const BasicMap &bmap2) const;

  /// \brief Generated from  ::<isl_basic_map_is_universe>
  ///
  ///
  /// \returns A new Bool
  Bool isUniverse() const;

  /// \brief Generated from  ::<isl_basic_map_lexmax>
  ///
  ///
  /// \returns A new Map
  Map lexmax() const;

  /// \brief Generated from  ::<isl_basic_map_lexmin>
  ///
  ///
  /// \returns A new Map
  Map lexmin() const;

  /// \brief Generated from  ::<isl_basic_map_lexmin_pw_multi_aff>
  ///
  ///
  /// \returns A new PwMultiAff
  PwMultiAff lexminPwMultiAff() const;

  /// \brief Generated from  ::<isl_basic_map_move_dims>
  ///
  /// \param [in] dst_type
  /// \param [in] dst_pos
  /// \param [in] src_type
  /// \param [in] src_pos
  /// \param [in] n
  ///
  /// \returns A new BasicMap
  BasicMap moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_basic_map_n_constraint>
  ///
  ///
  /// \returns A new int
  int nConstraint() const;

  /// \brief Generated from  ::<isl_basic_map_n_div>
  ///
  ///
  /// \returns A new unsigned int
  unsigned int nDiv() const;

  /// \brief Generated from  ::<isl_basic_map_n_in>
  ///
  ///
  /// \returns A new unsigned int
  unsigned int nIn() const;

  /// \brief Generated from  ::<isl_basic_map_n_out>
  ///
  ///
  /// \returns A new unsigned int
  unsigned int nOut() const;

  /// \brief Generated from  ::<isl_basic_map_n_param>
  ///
  ///
  /// \returns A new unsigned int
  unsigned int nParam() const;

  /// \brief Generated from  ::<isl_basic_map_order_ge>
  ///
  /// \param [in] type1
  /// \param [in] pos1
  /// \param [in] type2
  /// \param [in] pos2
  ///
  /// \returns A new BasicMap
  BasicMap orderGe(DimType type1, int pos1, DimType type2, int pos2) const;

  /// \brief Generated from  ::<isl_basic_map_order_gt>
  ///
  /// \param [in] type1
  /// \param [in] pos1
  /// \param [in] type2
  /// \param [in] pos2
  ///
  /// \returns A new BasicMap
  BasicMap orderGt(DimType type1, int pos1, DimType type2, int pos2) const;

  /// \brief Generated from  ::<isl_basic_map_product>
  ///
  /// \param [in] bmap2
  ///
  /// \returns A new BasicMap
  BasicMap product(const BasicMap &bmap2) const;

  /// \brief Generated from  ::<isl_basic_map_project_out>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new BasicMap
  BasicMap projectOut(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_basic_map_range>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet range() const;

  /// \brief Generated from  ::<isl_basic_map_range_map>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap rangeMap() const;

  /// \brief Generated from  ::<isl_basic_map_range_product>
  ///
  /// \param [in] bmap2
  ///
  /// \returns A new BasicMap
  BasicMap rangeProduct(const BasicMap &bmap2) const;

  /// \brief Generated from  ::<isl_basic_map_remove_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new BasicMap
  BasicMap removeDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_basic_map_remove_divs>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap removeDivs() const;

  /// \brief Generated from  ::<isl_basic_map_remove_divs_involving_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new BasicMap
  BasicMap removeDivsInvolvingDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_basic_map_reverse>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap reverse() const;

  /// \brief Generated from  ::<isl_basic_map_sample>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap sample() const;

  /// \brief Generated from  ::<isl_basic_map_set_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] s
  ///
  /// \returns A new BasicMap
  BasicMap setDimName(DimType type, unsigned int pos, std::string s) const;

  /// \brief Generated from  ::<isl_basic_map_set_tuple_id>
  ///
  /// \param [in] type
  /// \param [in] id
  ///
  /// \returns A new BasicMap
  BasicMap setTupleId(DimType type, const Id &id) const;

  /// \brief Generated from  ::<isl_basic_map_set_tuple_name>
  ///
  /// \param [in] type
  /// \param [in] s
  ///
  /// \returns A new BasicMap
  BasicMap setTupleName(DimType type, std::string s) const;

  /// \brief Generated from  ::<isl_basic_map_total_dim>
  ///
  ///
  /// \returns A new unsigned int
  unsigned int totalDim() const;

  /// \brief Generated from  ::<isl_basic_map_uncurry>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap uncurry() const;

  /// \brief Generated from  ::<isl_basic_map_union>
  ///
  /// \param [in] bmap2
  ///
  /// \returns A new Map
  Map union_(const BasicMap &bmap2) const;

  /// \brief Generated from  ::<isl_basic_map_wrap>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet wrap() const;
  BasicMap(const BasicMap &Other) : Map(Other.Context(), Other.GetCopy()) {}
  BasicMap &operator=(const BasicMap &Other);
  BasicMap (BasicMap && Other) : Map(Other.Context(), Other.This) {}
  BasicMap &operator=(BasicMap && Other) {
    isl_basic_map *New = Other.Give();
    isl_basic_map_free((isl_basic_map *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const BasicMap &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_BasicMap_H
