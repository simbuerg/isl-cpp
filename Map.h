#ifndef ISL_CXX_Map_H
#define ISL_CXX_Map_H


#include "isl/map.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/UnionMap.h"
#include "isl/map.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class Aff;
class BasicMap;
class Constraint;
class Id;
class MultiAff;
class MultiPwAff;
class PwAff;
class PwMultiAff;
class PwQpolynomialFold;
class Set;
class Space;
class Val;

class Map {
protected:
  Ctx ctx;
  void * This;
public:
  explicit Map(Ctx ctx, isl_map *That) : ctx(ctx), This(That) {}
  Map() : ctx(Ctx(nullptr)), This(nullptr) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_map *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_map *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_map *Get() const;


  /// \brief Constructor for isl_map_from_pw_aff
  ///
  /// \param pwaff
  static Map fromPwAff(const PwAff &pwaff);


  /// \brief Constructor for isl_map_nat_universe
  ///
  /// \param dim
  static Map natUniverse(const Space &dim);


  /// \brief Constructor for isl_map_empty
  ///
  /// \param dim
  static Map empty(const Space &dim);


  /// \brief Constructor for isl_map_lex_le_first
  ///
  /// \param dim
  /// \param n
  static Map lexLeFirst(const Space &dim, unsigned int n);


  /// \brief Constructor for isl_map_lex_lt
  ///
  /// \param set_dim
  static Map lexLt(const Space &set_dim);


  /// \brief Constructor for isl_map_lex_le
  ///
  /// \param set_dim
  static Map lexLe(const Space &set_dim);


  /// \brief Constructor for isl_map_lex_gt_first
  ///
  /// \param dim
  /// \param n
  static Map lexGtFirst(const Space &dim, unsigned int n);


  /// \brief Constructor for isl_map_lex_ge_first
  ///
  /// \param dim
  /// \param n
  static Map lexGeFirst(const Space &dim, unsigned int n);


  /// \brief Constructor for isl_map_lex_gt
  ///
  /// \param set_dim
  static Map lexGt(const Space &set_dim);


  /// \brief Constructor for isl_map_lex_ge
  ///
  /// \param set_dim
  static Map lexGe(const Space &set_dim);


  /// \brief Constructor for isl_map_read_from_str
  ///
  /// \param ctx
  /// \param str
  static Map readFromStr(const Ctx &ctx, std::string str);


  /// \brief Constructor for isl_map_from_basic_map
  ///
  /// \param bmap
  static Map fromBasicMap(const BasicMap &bmap);


  /// \brief Constructor for isl_map_from_domain
  ///
  /// \param set
  static Map fromDomain(const Set &set);


  /// \brief Constructor for isl_map_from_range
  ///
  /// \param set
  static Map fromRange(const Set &set);


  /// \brief Constructor for isl_map_from_domain_and_range
  ///
  /// \param domain
  /// \param range
  static Map fromDomainAndRange(const Set &domain, const Set &range);


  /// \brief Constructor for isl_map_from_set
  ///
  /// \param set
  /// \param dim
  static Map fromSet(const Set &set, const Space &dim);


  /// \brief Constructor for isl_map_from_aff
  ///
  /// \param aff
  static Map fromAff(const Aff &aff);


  /// \brief Constructor for isl_map_from_multi_aff
  ///
  /// \param maff
  static Map fromMultiAff(const MultiAff &maff);


  /// \brief Constructor for isl_map_from_union_map
  ///
  /// \param umap
  static Map fromUnionMap(const UnionMap &umap);
public:
  virtual ~Map();

  /// \brief Generated from  ::<isl_map_add_constraint>
  ///
  /// \param [in] constraint
  ///
  /// \returns A new Map
  Map addConstraint(const Constraint &constraint) const;

  /// \brief Generated from  ::<isl_map_add_dims>
  ///
  /// \param [in] type
  /// \param [in] n
  ///
  /// \returns A new Map
  Map addDims(DimType type, unsigned int n) const;

  /// \brief Generated from  ::<isl_map_affine_hull>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap affineHull() const;

  /// \brief Generated from  ::<isl_map_align_divs>
  ///
  ///
  /// \returns A new Map
  Map alignDivs() const;

  /// \brief Generated from  ::<isl_map_align_params>
  ///
  /// \param [in] model
  ///
  /// \returns A new Map
  Map alignParams(const Space &model) const;

  /// \brief Generated from  ::<isl_map_apply_domain>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Map
  Map applyDomain(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_apply_pw_qpolynomial_fold>
  ///
  /// \param [in] pwf
  /// \param [in] tight
  ///
  /// \returns A new PwQpolynomialFold
  PwQpolynomialFold applyPwQpolynomialFold(const PwQpolynomialFold &pwf, int * tight) const;

  /// \brief Generated from  ::<isl_map_apply_range>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Map
  Map applyRange(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_can_curry>
  ///
  ///
  /// \returns A new Bool
  Bool canCurry() const;

  /// \brief Generated from  ::<isl_map_can_uncurry>
  ///
  ///
  /// \returns A new Bool
  Bool canUncurry() const;

  /// \brief Generated from  ::<isl_map_can_zip>
  ///
  ///
  /// \returns A new Bool
  Bool canZip() const;

  /// \brief Generated from  ::<isl_map_coalesce>
  ///
  ///
  /// \returns A new Map
  Map coalesce() const;

  /// \brief Generated from  ::<isl_map_complement>
  ///
  ///
  /// \returns A new Map
  Map complement() const;

  /// \brief Generated from  ::<isl_map_compute_divs>
  ///
  ///
  /// \returns A new Map
  Map computeDivs() const;

  /// \brief Generated from  ::<isl_map_convex_hull>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap convexHull() const;

  /// \brief Generated from  ::<isl_map_curry>
  ///
  ///
  /// \returns A new Map
  Map curry() const;

  /// \brief Generated from  ::<isl_map_deltas>
  ///
  ///
  /// \returns A new Set
  Set deltas() const;

  /// \brief Generated from  ::<isl_map_deltas_map>
  ///
  ///
  /// \returns A new Map
  Map deltasMap() const;

  /// \brief Generated from  ::<isl_map_detect_equalities>
  ///
  ///
  /// \returns A new Map
  Map detectEqualities() const;

  /// \brief Generated from  ::<isl_map_dim>
  ///
  /// \param [in] type
  ///
  /// \returns A new unsigned int
  unsigned int dim(DimType type) const;

  /// \brief Generated from  ::<isl_map_dim_max>
  ///
  /// \param [in] pos
  ///
  /// \returns A new PwAff
  PwAff dimMax(int pos) const;

  /// \brief Generated from  ::<isl_map_domain>
  ///
  ///
  /// \returns A new Set
  Set domain() const;

  /// \brief Generated from  ::<isl_map_domain_map>
  ///
  ///
  /// \returns A new Map
  Map domainMap() const;

  /// \brief Generated from  ::<isl_map_domain_product>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Map
  Map domainProduct(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_drop_constraints_involving_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Map
  Map dropConstraintsInvolvingDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_map_eliminate>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Map
  Map eliminate(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_map_equate>
  ///
  /// \param [in] type1
  /// \param [in] pos1
  /// \param [in] type2
  /// \param [in] pos2
  ///
  /// \returns A new Map
  Map equate(DimType type1, int pos1, DimType type2, int pos2) const;

  /// \brief Generated from  ::<isl_map_find_dim_by_id>
  ///
  /// \param [in] type
  /// \param [in] id
  ///
  /// \returns A new int
  int findDimById(DimType type, const Id &id) const;

  /// \brief Generated from  ::<isl_map_find_dim_by_name>
  ///
  /// \param [in] type
  /// \param [in] name
  ///
  /// \returns A new int
  int findDimByName(DimType type, std::string name) const;

  /// \brief Generated from  ::<isl_map_fix_val>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] v
  ///
  /// \returns A new Map
  Map fixVal(DimType type, unsigned int pos, const Val &v) const;

  /// \brief Generated from  ::<isl_map_fixed_power_val>
  ///
  /// \param [in] exp
  ///
  /// \returns A new Map
  Map fixedPowerVal(const Val &exp) const;

  /// \brief Generated from  ::<isl_map_flat_domain_product>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Map
  Map flatDomainProduct(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_flat_product>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Map
  Map flatProduct(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_flat_range_product>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Map
  Map flatRangeProduct(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_flatten>
  ///
  ///
  /// \returns A new Map
  Map flatten() const;

  /// \brief Generated from  ::<isl_map_flatten_domain>
  ///
  ///
  /// \returns A new Map
  Map flattenDomain() const;

  /// \brief Generated from  ::<isl_map_flatten_range>
  ///
  ///
  /// \returns A new Map
  Map flattenRange() const;

  /// \brief Generated from  ::<isl_map_floordiv_val>
  ///
  /// \param [in] d
  ///
  /// \returns A new Map
  Map floordivVal(const Val &d) const;

  /// \brief Generated from  ::<isl_map_foreach_basic_map>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachBasicMap(const std::function<isl_stat(isl_basic_map *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_map_get_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Id
  Id getDimId(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_map_get_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new std::string
  std::string getDimName(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_map_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_map_get_tuple_id>
  ///
  /// \param [in] type
  ///
  /// \returns A new Id
  Id getTupleId(DimType type) const;

  /// \brief Generated from  ::<isl_map_get_tuple_name>
  ///
  /// \param [in] type
  ///
  /// \returns A new std::string
  std::string getTupleName(DimType type) const;

  /// \brief Generated from  ::<isl_map_gist>
  ///
  /// \param [in] context
  ///
  /// \returns A new Map
  Map gist(const Map &context) const;

  /// \brief Generated from  ::<isl_map_gist_basic_map>
  ///
  /// \param [in] context
  ///
  /// \returns A new Map
  Map gistBasicMap(const BasicMap &context) const;

  /// \brief Generated from  ::<isl_map_gist_domain>
  ///
  /// \param [in] context
  ///
  /// \returns A new Map
  Map gistDomain(const Set &context) const;

  /// \brief Generated from  ::<isl_map_gist_params>
  ///
  /// \param [in] context
  ///
  /// \returns A new Map
  Map gistParams(const Set &context) const;

  /// \brief Generated from  ::<isl_map_gist_range>
  ///
  /// \param [in] context
  ///
  /// \returns A new Map
  Map gistRange(const Set &context) const;

  /// \brief Generated from  ::<isl_map_has_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Bool
  Bool hasDimId(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_map_has_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Bool
  Bool hasDimName(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_map_has_equal_space>
  ///
  /// \param [in] map2
  ///
  /// \returns A new int
  int hasEqualSpace(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_has_tuple_id>
  ///
  /// \param [in] type
  ///
  /// \returns A new Bool
  Bool hasTupleId(DimType type) const;

  /// \brief Generated from  ::<isl_map_has_tuple_name>
  ///
  /// \param [in] type
  ///
  /// \returns A new Bool
  Bool hasTupleName(DimType type) const;

  /// \brief Generated from  ::<isl_map_insert_dims>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] n
  ///
  /// \returns A new Map
  Map insertDims(DimType type, unsigned int pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_map_intersect>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Map
  Map intersect(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_intersect_domain>
  ///
  /// \param [in] set
  ///
  /// \returns A new Map
  Map intersectDomain(const Set &set) const;

  /// \brief Generated from  ::<isl_map_intersect_params>
  ///
  /// \param [in] params
  ///
  /// \returns A new Map
  Map intersectParams(const Set &params) const;

  /// \brief Generated from  ::<isl_map_intersect_range>
  ///
  /// \param [in] set
  ///
  /// \returns A new Map
  Map intersectRange(const Set &set) const;

  /// \brief Generated from  ::<isl_map_involves_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Bool
  Bool involvesDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_map_is_bijective>
  ///
  ///
  /// \returns A new Bool
  Bool isBijective() const;

  /// \brief Generated from  ::<isl_map_is_disjoint>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Bool
  Bool isDisjoint(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_is_empty>
  ///
  ///
  /// \returns A new Bool
  Bool isEmpty() const;

  /// \brief Generated from  ::<isl_map_is_equal>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Bool
  Bool isEqual(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_is_injective>
  ///
  ///
  /// \returns A new Bool
  Bool isInjective() const;

  /// \brief Generated from  ::<isl_map_is_single_valued>
  ///
  ///
  /// \returns A new Bool
  Bool isSingleValued() const;

  /// \brief Generated from  ::<isl_map_is_strict_subset>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Bool
  Bool isStrictSubset(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_is_subset>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Bool
  Bool isSubset(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_is_translation>
  ///
  ///
  /// \returns A new int
  int isTranslation() const;

  /// \brief Generated from  ::<isl_map_lex_ge_map>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Map
  Map lexGeMap(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_lex_gt_map>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Map
  Map lexGtMap(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_lex_le_map>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Map
  Map lexLeMap(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_lex_lt_map>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Map
  Map lexLtMap(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_lexmax>
  ///
  ///
  /// \returns A new Map
  Map lexmax() const;

  /// \brief Generated from  ::<isl_map_lexmin>
  ///
  ///
  /// \returns A new Map
  Map lexmin() const;

  /// \brief Generated from  ::<isl_map_lexmin_pw_multi_aff>
  ///
  ///
  /// \returns A new PwMultiAff
  PwMultiAff lexminPwMultiAff() const;

  /// \brief Generated from  ::<isl_map_make_disjoint>
  ///
  ///
  /// \returns A new Map
  Map makeDisjoint() const;

  /// \brief Generated from  ::<isl_map_move_dims>
  ///
  /// \param [in] dst_type
  /// \param [in] dst_pos
  /// \param [in] src_type
  /// \param [in] src_pos
  /// \param [in] n
  ///
  /// \returns A new Map
  Map moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_map_n_in>
  ///
  ///
  /// \returns A new unsigned int
  unsigned int nIn() const;

  /// \brief Generated from  ::<isl_map_n_out>
  ///
  ///
  /// \returns A new unsigned int
  unsigned int nOut() const;

  /// \brief Generated from  ::<isl_map_n_param>
  ///
  ///
  /// \returns A new unsigned int
  unsigned int nParam() const;

  /// \brief Generated from  ::<isl_map_oppose>
  ///
  /// \param [in] type1
  /// \param [in] pos1
  /// \param [in] type2
  /// \param [in] pos2
  ///
  /// \returns A new Map
  Map oppose(DimType type1, int pos1, DimType type2, int pos2) const;

  /// \brief Generated from  ::<isl_map_order_gt>
  ///
  /// \param [in] type1
  /// \param [in] pos1
  /// \param [in] type2
  /// \param [in] pos2
  ///
  /// \returns A new Map
  Map orderGt(DimType type1, int pos1, DimType type2, int pos2) const;

  /// \brief Generated from  ::<isl_map_order_lt>
  ///
  /// \param [in] type1
  /// \param [in] pos1
  /// \param [in] type2
  /// \param [in] pos2
  ///
  /// \returns A new Map
  Map orderLt(DimType type1, int pos1, DimType type2, int pos2) const;

  /// \brief Generated from  ::<isl_map_params>
  ///
  ///
  /// \returns A new Set
  Set params() const;

  /// \brief Generated from  ::<isl_map_plain_is_empty>
  ///
  ///
  /// \returns A new Bool
  Bool plainIsEmpty() const;

  /// \brief Generated from  ::<isl_map_plain_is_equal>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Bool
  Bool plainIsEqual(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_plain_is_injective>
  ///
  ///
  /// \returns A new Bool
  Bool plainIsInjective() const;

  /// \brief Generated from  ::<isl_map_plain_is_universe>
  ///
  ///
  /// \returns A new Bool
  Bool plainIsUniverse() const;

  /// \brief Generated from  ::<isl_map_polyhedral_hull>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap polyhedralHull() const;

  /// \brief Generated from  ::<isl_map_preimage_domain_multi_aff>
  ///
  /// \param [in] ma
  ///
  /// \returns A new Map
  Map preimageDomainMultiAff(const MultiAff &ma) const;

  /// \brief Generated from  ::<isl_map_preimage_domain_multi_pw_aff>
  ///
  /// \param [in] mpa
  ///
  /// \returns A new Map
  Map preimageDomainMultiPwAff(const MultiPwAff &mpa) const;

  /// \brief Generated from  ::<isl_map_preimage_domain_pw_multi_aff>
  ///
  /// \param [in] pma
  ///
  /// \returns A new Map
  Map preimageDomainPwMultiAff(const PwMultiAff &pma) const;

  /// \brief Generated from  ::<isl_map_preimage_range_multi_aff>
  ///
  /// \param [in] ma
  ///
  /// \returns A new Map
  Map preimageRangeMultiAff(const MultiAff &ma) const;

  /// \brief Generated from  ::<isl_map_preimage_range_pw_multi_aff>
  ///
  /// \param [in] pma
  ///
  /// \returns A new Map
  Map preimageRangePwMultiAff(const PwMultiAff &pma) const;

  /// \brief Generated from  ::<isl_map_product>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Map
  Map product(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_project_out>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Map
  Map projectOut(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_map_range>
  ///
  ///
  /// \returns A new Set
  Set range() const;

  /// \brief Generated from  ::<isl_map_range_map>
  ///
  ///
  /// \returns A new Map
  Map rangeMap() const;

  /// \brief Generated from  ::<isl_map_range_product>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Map
  Map rangeProduct(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_remove_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Map
  Map removeDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_map_remove_divs>
  ///
  ///
  /// \returns A new Map
  Map removeDivs() const;

  /// \brief Generated from  ::<isl_map_remove_divs_involving_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Map
  Map removeDivsInvolvingDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_map_remove_redundancies>
  ///
  ///
  /// \returns A new Map
  Map removeRedundancies() const;

  /// \brief Generated from  ::<isl_map_remove_unknown_divs>
  ///
  ///
  /// \returns A new Map
  Map removeUnknownDivs() const;

  /// \brief Generated from  ::<isl_map_reset_tuple_id>
  ///
  /// \param [in] type
  ///
  /// \returns A new Map
  Map resetTupleId(DimType type) const;

  /// \brief Generated from  ::<isl_map_reverse>
  ///
  ///
  /// \returns A new Map
  Map reverse() const;

  /// \brief Generated from  ::<isl_map_sample>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap sample() const;

  /// \brief Generated from  ::<isl_map_set_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] id
  ///
  /// \returns A new Map
  Map setDimId(DimType type, unsigned int pos, const Id &id) const;

  /// \brief Generated from  ::<isl_map_set_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] s
  ///
  /// \returns A new Map
  Map setDimName(DimType type, unsigned int pos, std::string s) const;

  /// \brief Generated from  ::<isl_map_set_tuple_id>
  ///
  /// \param [in] type
  /// \param [in] id
  ///
  /// \returns A new Map
  Map setTupleId(DimType type, const Id &id) const;

  /// \brief Generated from  ::<isl_map_set_tuple_name>
  ///
  /// \param [in] type
  /// \param [in] s
  ///
  /// \returns A new Map
  Map setTupleName(DimType type, std::string s) const;

  /// \brief Generated from  ::<isl_map_simple_hull>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap simpleHull() const;

  /// \brief Generated from  ::<isl_map_subtract>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Map
  Map subtract(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_subtract_domain>
  ///
  /// \param [in] dom
  ///
  /// \returns A new Map
  Map subtractDomain(const Set &dom) const;

  /// \brief Generated from  ::<isl_map_subtract_range>
  ///
  /// \param [in] dom
  ///
  /// \returns A new Map
  Map subtractRange(const Set &dom) const;

  /// \brief Generated from  ::<isl_map_to_str>
  ///
  ///
  /// \returns A new std::string
  std::string toStr() const;

  /// \brief Generated from  ::<isl_map_transitive_closure>
  ///
  /// \param [in] exact
  ///
  /// \returns A new Map
  Map transitiveClosure(int * exact) const;

  /// \brief Generated from  ::<isl_map_uncurry>
  ///
  ///
  /// \returns A new Map
  Map uncurry() const;

  /// \brief Generated from  ::<isl_map_union>
  ///
  /// \param [in] map2
  ///
  /// \returns A new Map
  Map union_(const Map &map2) const;

  /// \brief Generated from  ::<isl_map_unshifted_simple_hull>
  ///
  ///
  /// \returns A new BasicMap
  BasicMap unshiftedSimpleHull() const;

  /// \brief Generated from  ::<isl_map_wrap>
  ///
  ///
  /// \returns A new Set
  Set wrap() const;

  /// \brief Generated from  ::<isl_map_zip>
  ///
  ///
  /// \returns A new Map
  Map zip() const;

  Map(const Map &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  Map &operator=(const Map &Other);
  Map (Map && Other) : ctx(Other.Context()), This(Other.Give()) {}
  Map &operator=(Map && Other) {
    isl_map *New = Other.Give();
    isl_map_free((isl_map *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const Map &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_Map_H
