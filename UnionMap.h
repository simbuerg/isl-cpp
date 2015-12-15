#ifndef ISL_CXX_UnionMap_H
#define ISL_CXX_UnionMap_H


#include "isl/aff.h"
#include "isl/union_map.h"
#include "isl/flow.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/map.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class BasicMap;
class Map;
class Printer;
class Set;
class Space;
class UnionPwQpolynomialFold;
class UnionSet;
class Val;

class UnionMap {
protected:
  Ctx ctx;
  void * This;
  explicit UnionMap(Ctx ctx, isl_union_map *That) : ctx(ctx), This((void *)That) {}
  explicit UnionMap(Ctx ctx, void *That) : ctx(ctx), This(That) {}

public:
  const Ctx &Context() const { return ctx; }
  ///rief Wrap an existing isl object.
  ///
  /// This serves as an entry point into the C++ API.
  /// We take ownership of the isl object.
  ///
  /// \param That the isl_union_map we want to wrap.
  explicit UnionMap(isl_union_map *That) : UnionMap(Ctx(isl_union_map_get_ctx(That)), That) {}
  isl_union_map *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_union_map *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_union_map *Get() const;

  /// \brief Constructor for isl_union_map_from_basic_map
  ///
  /// \param bmap
  static UnionMap fromBasicMap(const BasicMap &bmap);
  /// \brief Constructor for isl_union_map_from_map
  ///
  /// \param map
  static UnionMap fromMap(const Map &map);
  /// \brief Constructor for isl_union_map_empty
  ///
  /// \param dim
  static UnionMap empty(const Space &dim);
  /// \brief Constructor for isl_union_map_universe
  ///
  /// \param umap
  static UnionMap universe(const UnionMap &umap);
  /// \brief Constructor for isl_union_map_from_domain
  ///
  /// \param uset
  static UnionMap fromDomain(const UnionSet &uset);
  /// \brief Constructor for isl_union_map_from_range
  ///
  /// \param uset
  static UnionMap fromRange(const UnionSet &uset);
  /// \brief Constructor for isl_union_map_read_from_str
  ///
  /// \param ctx
  /// \param str
  static UnionMap readFromStr(const Ctx &ctx, std::string str);
  virtual ~UnionMap();
  std::string toStr(isl::Format F = isl::Format::FIsl) const;

  virtual UnionMap asUnionMap() const;

  /// \brief Generated from  ::<isl_union_map_affine_hull>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap affineHull() const;

  /// \brief Generated from  ::<isl_union_map_align_params>
  ///
  /// \param [in] model
  ///
  /// \returns A new UnionMap
  UnionMap alignParams(const Space &model) const;

  /// \brief Generated from  ::<isl_union_map_apply_domain>
  ///
  /// \param [in] umap2
  ///
  /// \returns A new UnionMap
  UnionMap applyDomain(const UnionMap &umap2) const;

  /// \brief Generated from  ::<isl_union_map_apply_range>
  ///
  /// \param [in] umap2
  ///
  /// \returns A new UnionMap
  UnionMap applyRange(const UnionMap &umap2) const;

  /// \brief Generated from  ::<isl_union_map_apply_union_pw_qpolynomial_fold>
  ///
  /// \param [in] upwf
  /// \param [in] tight
  ///
  /// \returns A new UnionPwQpolynomialFold
  UnionPwQpolynomialFold applyUnionPwQpolynomialFold(const UnionPwQpolynomialFold &upwf, int * tight) const;

  /// \brief Generated from  ::<isl_union_map_coalesce>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap coalesce() const;

  /// \brief Generated from  ::<isl_union_map_compute_divs>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap computeDivs() const;

  /// \brief Generated from  ::<isl_union_map_compute_flow>
  ///
  /// \param [in] must_source
  /// \param [in] may_source
  /// \param [in] schedule
  /// \param [out] must_dep (isl_give)
  /// \param [out] may_dep (isl_give)
  /// \param [out] must_no_source (isl_give)
  /// \param [out] may_no_source (isl_give)
  ///
  /// \returns A new int
  int computeFlow(const UnionMap &must_source, const UnionMap &may_source, const UnionMap &schedule, std::unique_ptr<UnionMap> * must_dep, std::unique_ptr<UnionMap> * may_dep, std::unique_ptr<UnionMap> * must_no_source, std::unique_ptr<UnionMap> * may_no_source) const;

  /// \brief Generated from  ::<isl_union_map_contains>
  ///
  /// \param [in] dim
  ///
  /// \returns A new int
  int contains(const Space &dim) const;

  /// \brief Generated from  ::<isl_union_map_curry>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap curry() const;

  /// \brief Generated from  ::<isl_union_map_deltas>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet deltas() const;

  /// \brief Generated from  ::<isl_union_map_detect_equalities>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap detectEqualities() const;

  /// \brief Generated from  ::<isl_union_map_domain>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet domain() const;

  /// \brief Generated from  ::<isl_union_map_domain_map>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap domainMap() const;

  /// \brief Generated from  ::<isl_union_map_extract_map>
  ///
  /// \param [in] dim
  ///
  /// \returns A new Map
  Map extractMap(const Space &dim) const;

  /// \brief Generated from  ::<isl_union_map_fixed_power_val>
  ///
  /// \param [in] exp
  ///
  /// \returns A new UnionMap
  UnionMap fixedPowerVal(const Val &exp) const;

  /// \brief Generated from  ::<isl_union_map_foreach_map>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachMap(const std::function<isl_stat(isl_map *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_union_map_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_union_map_gist>
  ///
  /// \param [in] context
  ///
  /// \returns A new UnionMap
  UnionMap gist(const UnionMap &context) const;

  /// \brief Generated from  ::<isl_union_map_gist_domain>
  ///
  /// \param [in] uset
  ///
  /// \returns A new UnionMap
  UnionMap gistDomain(const UnionSet &uset) const;

  /// \brief Generated from  ::<isl_union_map_gist_params>
  ///
  /// \param [in] set
  ///
  /// \returns A new UnionMap
  UnionMap gistParams(const Set &set) const;

  /// \brief Generated from  ::<isl_union_map_gist_range>
  ///
  /// \param [in] uset
  ///
  /// \returns A new UnionMap
  UnionMap gistRange(const UnionSet &uset) const;

  /// \brief Generated from  ::<isl_union_map_intersect>
  ///
  /// \param [in] umap2
  ///
  /// \returns A new UnionMap
  UnionMap intersect(const UnionMap &umap2) const;

  /// \brief Generated from  ::<isl_union_map_intersect_domain>
  ///
  /// \param [in] uset
  ///
  /// \returns A new UnionMap
  UnionMap intersectDomain(const UnionSet &uset) const;

  /// \brief Generated from  ::<isl_union_map_intersect_params>
  ///
  /// \param [in] set
  ///
  /// \returns A new UnionMap
  UnionMap intersectParams(const Set &set) const;

  /// \brief Generated from  ::<isl_union_map_intersect_range>
  ///
  /// \param [in] uset
  ///
  /// \returns A new UnionMap
  UnionMap intersectRange(const UnionSet &uset) const;

  /// \brief Generated from  ::<isl_union_map_is_bijective>
  ///
  ///
  /// \returns A new Bool
  Bool isBijective() const;

  /// \brief Generated from  ::<isl_union_map_is_empty>
  ///
  ///
  /// \returns A new Bool
  Bool isEmpty() const;

  /// \brief Generated from  ::<isl_union_map_is_equal>
  ///
  /// \param [in] umap2
  ///
  /// \returns A new Bool
  Bool isEqual(const UnionMap &umap2) const;

  /// \brief Generated from  ::<isl_union_map_is_injective>
  ///
  ///
  /// \returns A new Bool
  Bool isInjective() const;

  /// \brief Generated from  ::<isl_union_map_is_single_valued>
  ///
  ///
  /// \returns A new Bool
  Bool isSingleValued() const;

  /// \brief Generated from  ::<isl_union_map_is_strict_subset>
  ///
  /// \param [in] umap2
  ///
  /// \returns A new Bool
  Bool isStrictSubset(const UnionMap &umap2) const;

  /// \brief Generated from  ::<isl_union_map_is_subset>
  ///
  /// \param [in] umap2
  ///
  /// \returns A new Bool
  Bool isSubset(const UnionMap &umap2) const;

  /// \brief Generated from  ::<isl_union_map_lex_ge_union_map>
  ///
  /// \param [in] umap2
  ///
  /// \returns A new UnionMap
  UnionMap lexGeUnionMap(const UnionMap &umap2) const;

  /// \brief Generated from  ::<isl_union_map_lex_gt_union_map>
  ///
  /// \param [in] umap2
  ///
  /// \returns A new UnionMap
  UnionMap lexGtUnionMap(const UnionMap &umap2) const;

  /// \brief Generated from  ::<isl_union_map_lex_le_union_map>
  ///
  /// \param [in] umap2
  ///
  /// \returns A new UnionMap
  UnionMap lexLeUnionMap(const UnionMap &umap2) const;

  /// \brief Generated from  ::<isl_union_map_lex_lt_union_map>
  ///
  /// \param [in] umap2
  ///
  /// \returns A new UnionMap
  UnionMap lexLtUnionMap(const UnionMap &umap2) const;

  /// \brief Generated from  ::<isl_union_map_lexmax>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap lexmax() const;

  /// \brief Generated from  ::<isl_union_map_lexmin>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap lexmin() const;

  /// \brief Generated from  ::<isl_union_map_n_map>
  ///
  ///
  /// \returns A new int
  int nMap() const;

  /// \brief Generated from  ::<isl_union_map_params>
  ///
  ///
  /// \returns A new Set
  Set params() const;

  /// \brief Generated from  ::<isl_union_map_polyhedral_hull>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap polyhedralHull() const;

  /// \brief Generated from  ::<isl_union_map_power>
  ///
  /// \param [in] exact
  ///
  /// \returns A new UnionMap
  UnionMap power(int * exact) const;

  /// \brief Generated from  ::<isl_union_map_range>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet range() const;

  /// \brief Generated from  ::<isl_union_map_range_map>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap rangeMap() const;

  /// \brief Generated from  ::<isl_union_map_reverse>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap reverse() const;

  /// \brief Generated from  ::<isl_union_map_sample>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap sample() const;

  /// \brief Generated from  ::<isl_union_map_subtract>
  ///
  /// \param [in] umap2
  ///
  /// \returns A new UnionMap
  UnionMap subtract(const UnionMap &umap2) const;

  /// \brief Generated from  ::<isl_union_map_subtract_domain>
  ///
  /// \param [in] dom
  ///
  /// \returns A new UnionMap
  UnionMap subtractDomain(const UnionSet &dom) const;

  /// \brief Generated from  ::<isl_union_map_subtract_range>
  ///
  /// \param [in] dom
  ///
  /// \returns A new UnionMap
  UnionMap subtractRange(const UnionSet &dom) const;

  /// \brief Generated from  ::<isl_union_map_transitive_closure>
  ///
  /// \param [in] exact
  ///
  /// \returns A new UnionMap
  UnionMap transitiveClosure(int * exact) const;

  /// \brief Generated from  ::<isl_union_map_uncurry>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap uncurry() const;

  /// \brief Generated from  ::<isl_union_map_union>
  ///
  /// \param [in] umap2
  ///
  /// \returns A new UnionMap
  UnionMap union_(const UnionMap &umap2) const;

  /// \brief Generated from  ::<isl_union_map_wrap>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet wrap() const;

  /// \brief Generated from  ::<isl_union_map_zip>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap zip() const;
  UnionMap(const UnionMap &Other) : UnionMap(Other.Context(), Other.GetCopy()) {}
  UnionMap &operator=(const UnionMap &Other);
  UnionMap (UnionMap && Other) : UnionMap(Other.Context(), Other.This) {}
  UnionMap &operator=(UnionMap && Other) {
    isl_union_map *New = Other.Give();
    isl_union_map_free((isl_union_map *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const UnionMap &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_UnionMap_H
