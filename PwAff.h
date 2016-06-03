#ifndef ISL_CXX_PwAff_H
#define ISL_CXX_PwAff_H


#include "isl/aff.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/UnionPwAff.h"
#include "isl/aff.h"
#include "isl/set.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class Aff;
class Id;
class LocalSpace;
class MultiAff;
class MultiPwAff;
class PwMultiAff;
class Set;
class Space;
class Val;

class PwAff {
protected:
  Ctx ctx;
  void * This;
public:
  explicit PwAff(Ctx ctx, isl_pw_aff *That) : ctx(ctx), This(That) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_pw_aff *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_pw_aff *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_pw_aff *Get() const;


  /// \brief Constructor for isl_pw_aff_from_aff
  ///
  /// \param aff
  static PwAff fromAff(const Aff &aff);


  /// \brief Constructor for isl_pw_aff_empty
  ///
  /// \param dim
  static PwAff empty(const Space &dim);


  /// \brief Constructor for isl_pw_aff_alloc
  ///
  /// \param set
  /// \param aff
  static PwAff alloc(const Set &set, const Aff &aff);


  /// \brief Constructor for isl_pw_aff_zero_on_domain
  ///
  /// \param ls
  static PwAff zeroOnDomain(const LocalSpace &ls);


  /// \brief Constructor for isl_pw_aff_var_on_domain
  ///
  /// \param ls
  /// \param type
  /// \param pos
  static PwAff varOnDomain(const LocalSpace &ls, DimType type, unsigned int pos);


  /// \brief Constructor for isl_pw_aff_read_from_str
  ///
  /// \param ctx
  /// \param str
  static PwAff readFromStr(const Ctx &ctx, std::string str);
public:
  virtual ~PwAff();

  /// \brief Generated from  ::<isl_pw_aff_add>
  ///
  /// \param [in] pwaff2
  ///
  /// \returns A new PwAff
  PwAff add(const PwAff &pwaff2) const;

  /// \brief Generated from  ::<isl_pw_aff_add_dims>
  ///
  /// \param [in] type
  /// \param [in] n
  ///
  /// \returns A new PwAff
  PwAff addDims(DimType type, unsigned int n) const;

  /// \brief Generated from  ::<isl_pw_aff_align_params>
  ///
  /// \param [in] model
  ///
  /// \returns A new PwAff
  PwAff alignParams(const Space &model) const;

  /// \brief Generated from  ::<isl_pw_aff_ceil>
  ///
  ///
  /// \returns A new PwAff
  PwAff ceil() const;

  /// \brief Generated from  ::<isl_pw_aff_coalesce>
  ///
  ///
  /// \returns A new PwAff
  PwAff coalesce() const;

  /// \brief Generated from  ::<isl_pw_aff_cond>
  ///
  /// \param [in] pwaff_true
  /// \param [in] pwaff_false
  ///
  /// \returns A new PwAff
  PwAff cond(const PwAff &pwaff_true, const PwAff &pwaff_false) const;

  /// \brief Generated from  ::<isl_pw_aff_dim>
  ///
  /// \param [in] type
  ///
  /// \returns A new unsigned int
  unsigned int dim(DimType type) const;

  /// \brief Generated from  ::<isl_pw_aff_div>
  ///
  /// \param [in] pa2
  ///
  /// \returns A new PwAff
  PwAff div(const PwAff &pa2) const;

  /// \brief Generated from  ::<isl_pw_aff_domain>
  ///
  ///
  /// \returns A new Set
  Set domain() const;

  /// \brief Generated from  ::<isl_pw_aff_drop_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new PwAff
  PwAff dropDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_pw_aff_eq_set>
  ///
  /// \param [in] pwaff2
  ///
  /// \returns A new Set
  Set eqSet(const PwAff &pwaff2) const;

  /// \brief Generated from  ::<isl_pw_aff_floor>
  ///
  ///
  /// \returns A new PwAff
  PwAff floor() const;

  /// \brief Generated from  ::<isl_pw_aff_foreach_piece>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachPiece(const std::function<isl_stat(isl_set *, isl_aff *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_pw_aff_from_range>
  ///
  ///
  /// \returns A new PwAff
  PwAff fromRange() const;

  /// \brief Generated from  ::<isl_pw_aff_ge_set>
  ///
  /// \param [in] pwaff2
  ///
  /// \returns A new Set
  Set geSet(const PwAff &pwaff2) const;

  /// \brief Generated from  ::<isl_pw_aff_get_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Id
  Id getDimId(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_pw_aff_get_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new std::string
  std::string getDimName(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_pw_aff_get_domain_space>
  ///
  ///
  /// \returns A new Space
  Space getDomainSpace() const;

  /// \brief Generated from  ::<isl_pw_aff_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_pw_aff_gist>
  ///
  /// \param [in] context
  ///
  /// \returns A new PwAff
  PwAff gist(const Set &context) const;

  /// \brief Generated from  ::<isl_pw_aff_gist_params>
  ///
  /// \param [in] context
  ///
  /// \returns A new PwAff
  PwAff gistParams(const Set &context) const;

  /// \brief Generated from  ::<isl_pw_aff_gt_set>
  ///
  /// \param [in] pwaff2
  ///
  /// \returns A new Set
  Set gtSet(const PwAff &pwaff2) const;

  /// \brief Generated from  ::<isl_pw_aff_has_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Bool
  Bool hasDimId(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_pw_aff_has_tuple_id>
  ///
  /// \param [in] type
  ///
  /// \returns A new Bool
  Bool hasTupleId(DimType type) const;

  /// \brief Generated from  ::<isl_pw_aff_insert_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new PwAff
  PwAff insertDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_pw_aff_intersect_domain>
  ///
  /// \param [in] set
  ///
  /// \returns A new PwAff
  PwAff intersectDomain(const Set &set) const;

  /// \brief Generated from  ::<isl_pw_aff_intersect_params>
  ///
  /// \param [in] set
  ///
  /// \returns A new PwAff
  PwAff intersectParams(const Set &set) const;

  /// \brief Generated from  ::<isl_pw_aff_involves_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Bool
  Bool involvesDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_pw_aff_is_cst>
  ///
  ///
  /// \returns A new Bool
  Bool isCst() const;

  /// \brief Generated from  ::<isl_pw_aff_is_empty>
  ///
  ///
  /// \returns A new Bool
  Bool isEmpty() const;

  /// \brief Generated from  ::<isl_pw_aff_is_equal>
  ///
  /// \param [in] pa2
  ///
  /// \returns A new int
  int isEqual(const PwAff &pa2) const;

  /// \brief Generated from  ::<isl_pw_aff_le_set>
  ///
  /// \param [in] pwaff2
  ///
  /// \returns A new Set
  Set leSet(const PwAff &pwaff2) const;

  /// \brief Generated from  ::<isl_pw_aff_lt_set>
  ///
  /// \param [in] pwaff2
  ///
  /// \returns A new Set
  Set ltSet(const PwAff &pwaff2) const;

  /// \brief Generated from  ::<isl_pw_aff_max>
  ///
  /// \param [in] pwaff2
  ///
  /// \returns A new PwAff
  PwAff max(const PwAff &pwaff2) const;

  /// \brief Generated from  ::<isl_pw_aff_min>
  ///
  /// \param [in] pwaff2
  ///
  /// \returns A new PwAff
  PwAff min(const PwAff &pwaff2) const;

  /// \brief Generated from  ::<isl_pw_aff_mod_val>
  ///
  /// \param [in] mod
  ///
  /// \returns A new PwAff
  PwAff modVal(const Val &mod) const;

  /// \brief Generated from  ::<isl_pw_aff_move_dims>
  ///
  /// \param [in] dst_type
  /// \param [in] dst_pos
  /// \param [in] src_type
  /// \param [in] src_pos
  /// \param [in] n
  ///
  /// \returns A new PwAff
  PwAff moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_pw_aff_mul>
  ///
  /// \param [in] pwaff2
  ///
  /// \returns A new PwAff
  PwAff mul(const PwAff &pwaff2) const;

  /// \brief Generated from  ::<isl_pw_aff_n_piece>
  ///
  ///
  /// \returns A new int
  int nPiece() const;

  /// \brief Generated from  ::<isl_pw_aff_ne_set>
  ///
  /// \param [in] pwaff2
  ///
  /// \returns A new Set
  Set neSet(const PwAff &pwaff2) const;

  /// \brief Generated from  ::<isl_pw_aff_neg>
  ///
  ///
  /// \returns A new PwAff
  PwAff neg() const;

  /// \brief Generated from  ::<isl_pw_aff_non_zero_set>
  ///
  ///
  /// \returns A new Set
  Set nonZeroSet() const;

  /// \brief Generated from  ::<isl_pw_aff_nonneg_set>
  ///
  ///
  /// \returns A new Set
  Set nonnegSet() const;

  /// \brief Generated from  ::<isl_pw_aff_params>
  ///
  ///
  /// \returns A new Set
  Set params() const;

  /// \brief Generated from  ::<isl_pw_aff_pullback_multi_aff>
  ///
  /// \param [in] ma
  ///
  /// \returns A new PwAff
  PwAff pullbackMultiAff(const MultiAff &ma) const;

  /// \brief Generated from  ::<isl_pw_aff_pullback_multi_pw_aff>
  ///
  /// \param [in] mpa
  ///
  /// \returns A new PwAff
  PwAff pullbackMultiPwAff(const MultiPwAff &mpa) const;

  /// \brief Generated from  ::<isl_pw_aff_pullback_pw_multi_aff>
  ///
  /// \param [in] pma
  ///
  /// \returns A new PwAff
  PwAff pullbackPwMultiAff(const PwMultiAff &pma) const;

  /// \brief Generated from  ::<isl_pw_aff_scale_down_val>
  ///
  /// \param [in] f
  ///
  /// \returns A new PwAff
  PwAff scaleDownVal(const Val &f) const;

  /// \brief Generated from  ::<isl_pw_aff_scale_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new PwAff
  PwAff scaleVal(const Val &v) const;

  /// \brief Generated from  ::<isl_pw_aff_set_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] id
  ///
  /// \returns A new PwAff
  PwAff setDimId(DimType type, unsigned int pos, const Id &id) const;

  /// \brief Generated from  ::<isl_pw_aff_set_tuple_id>
  ///
  /// \param [in] type
  /// \param [in] id
  ///
  /// \returns A new PwAff
  PwAff setTupleId(DimType type, const Id &id) const;

  /// \brief Generated from  ::<isl_pw_aff_sub>
  ///
  /// \param [in] pwaff2
  ///
  /// \returns A new PwAff
  PwAff sub(const PwAff &pwaff2) const;

  /// \brief Generated from  ::<isl_pw_aff_tdiv_q>
  ///
  /// \param [in] pa2
  ///
  /// \returns A new PwAff
  PwAff tdivQ(const PwAff &pa2) const;

  /// \brief Generated from  ::<isl_pw_aff_tdiv_r>
  ///
  /// \param [in] pa2
  ///
  /// \returns A new PwAff
  PwAff tdivR(const PwAff &pa2) const;

  /// \brief Generated from  ::<isl_pw_aff_union_add>
  ///
  /// \param [in] pwaff2
  ///
  /// \returns A new PwAff
  PwAff unionAdd(const PwAff &pwaff2) const;

  /// \brief Generated from  ::<isl_pw_aff_union_max>
  ///
  /// \param [in] pwaff2
  ///
  /// \returns A new PwAff
  PwAff unionMax(const PwAff &pwaff2) const;

  /// \brief Generated from  ::<isl_pw_aff_union_min>
  ///
  /// \param [in] pwaff2
  ///
  /// \returns A new PwAff
  PwAff unionMin(const PwAff &pwaff2) const;

  /// \brief Generated from  ::<isl_pw_aff_zero_set>
  ///
  ///
  /// \returns A new Set
  Set zeroSet() const;

  PwAff(const PwAff &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  PwAff &operator=(const PwAff &Other);
  PwAff (PwAff && Other) : ctx(Other.Context()), This(Other.Give()) {}
  PwAff &operator=(PwAff && Other) {
    isl_pw_aff *New = Other.Give();
    isl_pw_aff_free((isl_pw_aff *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const PwAff &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_PwAff_H
