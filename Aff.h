#ifndef ISL_CXX_Aff_H
#define ISL_CXX_Aff_H


#include "isl/aff.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/PwAff.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class BasicSet;
class Id;
class LocalSpace;
class MultiAff;
class Set;
class Space;
class Val;

class Aff {
protected:
  Ctx ctx;
  void * This;
public:
  explicit Aff(Ctx ctx, isl_aff *That) : ctx(ctx), This(That) {}
  Aff() : ctx(Ctx(nullptr)), This(nullptr) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_aff *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_aff *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_aff *Get() const;


  /// \brief Constructor for isl_aff_zero_on_domain
  ///
  /// \param ls
  static Aff zeroOnDomain(const LocalSpace &ls);


  /// \brief Constructor for isl_aff_val_on_domain
  ///
  /// \param ls
  /// \param val
  static Aff valOnDomain(const LocalSpace &ls, const Val &val);


  /// \brief Constructor for isl_aff_var_on_domain
  ///
  /// \param ls
  /// \param type
  /// \param pos
  static Aff varOnDomain(const LocalSpace &ls, DimType type, unsigned int pos);


  /// \brief Constructor for isl_aff_read_from_str
  ///
  /// \param ctx
  /// \param str
  static Aff readFromStr(const Ctx &ctx, std::string str);
public:
  virtual ~Aff();
  /// \brief Generated from  ::<isl_aff_add>
  ///
  /// \param [in] aff2
  ///
  /// \returns A new Aff
  Aff add(const Aff &aff2) const;

  /// \brief Generated from  ::<isl_aff_add_coefficient_si>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] v
  ///
  /// \returns A new Aff
  Aff addCoefficientSi(DimType type, int pos, int v) const;

  /// \brief Generated from  ::<isl_aff_add_coefficient_val>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] v
  ///
  /// \returns A new Aff
  Aff addCoefficientVal(DimType type, int pos, const Val &v) const;

  /// \brief Generated from  ::<isl_aff_add_constant_num_si>
  ///
  /// \param [in] v
  ///
  /// \returns A new Aff
  Aff addConstantNumSi(int v) const;

  /// \brief Generated from  ::<isl_aff_add_constant_si>
  ///
  /// \param [in] v
  ///
  /// \returns A new Aff
  Aff addConstantSi(int v) const;

  /// \brief Generated from  ::<isl_aff_add_constant_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new Aff
  Aff addConstantVal(const Val &v) const;

  /// \brief Generated from  ::<isl_aff_add_dims>
  ///
  /// \param [in] type
  /// \param [in] n
  ///
  /// \returns A new Aff
  Aff addDims(DimType type, unsigned int n) const;

  /// \brief Generated from  ::<isl_aff_align_params>
  ///
  /// \param [in] model
  ///
  /// \returns A new Aff
  Aff alignParams(const Space &model) const;

  /// \brief Generated from  ::<isl_aff_ceil>
  ///
  ///
  /// \returns A new Aff
  Aff ceil() const;

  /// \brief Generated from  ::<isl_aff_dim>
  ///
  /// \param [in] type
  ///
  /// \returns A new int
  int dim(DimType type) const;

  /// \brief Generated from  ::<isl_aff_div>
  ///
  /// \param [in] aff2
  ///
  /// \returns A new Aff
  Aff div(const Aff &aff2) const;

  /// \brief Generated from  ::<isl_aff_drop_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Aff
  Aff dropDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_aff_floor>
  ///
  ///
  /// \returns A new Aff
  Aff floor() const;

  /// \brief Generated from  ::<isl_aff_ge_basic_set>
  ///
  /// \param [in] aff2
  ///
  /// \returns A new BasicSet
  BasicSet geBasicSet(const Aff &aff2) const;

  /// \brief Generated from  ::<isl_aff_get_coefficient_val>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Val
  Val getCoefficientVal(DimType type, int pos) const;

  /// \brief Generated from  ::<isl_aff_get_constant_val>
  ///
  ///
  /// \returns A new Val
  Val getConstantVal() const;

  /// \brief Generated from  ::<isl_aff_get_denominator_val>
  ///
  ///
  /// \returns A new Val
  Val getDenominatorVal() const;

  /// \brief Generated from  ::<isl_aff_get_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new std::string
  std::string getDimName(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_aff_get_div>
  ///
  /// \param [in] pos
  ///
  /// \returns A new Aff
  Aff getDiv(int pos) const;

  /// \brief Generated from  ::<isl_aff_get_domain_local_space>
  ///
  ///
  /// \returns A new LocalSpace
  LocalSpace getDomainLocalSpace() const;

  /// \brief Generated from  ::<isl_aff_get_domain_space>
  ///
  ///
  /// \returns A new Space
  Space getDomainSpace() const;

  /// \brief Generated from  ::<isl_aff_get_local_space>
  ///
  ///
  /// \returns A new LocalSpace
  LocalSpace getLocalSpace() const;

  /// \brief Generated from  ::<isl_aff_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_aff_gist>
  ///
  /// \param [in] context
  ///
  /// \returns A new Aff
  Aff gist(const Set &context) const;

  /// \brief Generated from  ::<isl_aff_gist_params>
  ///
  /// \param [in] context
  ///
  /// \returns A new Aff
  Aff gistParams(const Set &context) const;

  /// \brief Generated from  ::<isl_aff_insert_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Aff
  Aff insertDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_aff_involves_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Bool
  Bool involvesDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_aff_is_cst>
  ///
  ///
  /// \returns A new Bool
  Bool isCst() const;

  /// \brief Generated from  ::<isl_aff_le_basic_set>
  ///
  /// \param [in] aff2
  ///
  /// \returns A new BasicSet
  BasicSet leBasicSet(const Aff &aff2) const;

  /// \brief Generated from  ::<isl_aff_mod_val>
  ///
  /// \param [in] mod
  ///
  /// \returns A new Aff
  Aff modVal(const Val &mod) const;

  /// \brief Generated from  ::<isl_aff_move_dims>
  ///
  /// \param [in] dst_type
  /// \param [in] dst_pos
  /// \param [in] src_type
  /// \param [in] src_pos
  /// \param [in] n
  ///
  /// \returns A new Aff
  Aff moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_aff_mul>
  ///
  /// \param [in] aff2
  ///
  /// \returns A new Aff
  Aff mul(const Aff &aff2) const;

  /// \brief Generated from  ::<isl_aff_neg>
  ///
  ///
  /// \returns A new Aff
  Aff neg() const;

  /// \brief Generated from  ::<isl_aff_neg_basic_set>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet negBasicSet() const;

  /// \brief Generated from  ::<isl_aff_plain_is_equal>
  ///
  /// \param [in] aff2
  ///
  /// \returns A new Bool
  Bool plainIsEqual(const Aff &aff2) const;

  /// \brief Generated from  ::<isl_aff_plain_is_zero>
  ///
  ///
  /// \returns A new Bool
  Bool plainIsZero() const;

  /// \brief Generated from  ::<isl_aff_project_domain_on_params>
  ///
  ///
  /// \returns A new Aff
  Aff projectDomainOnParams() const;

  /// \brief Generated from  ::<isl_aff_pullback_multi_aff>
  ///
  /// \param [in] ma
  ///
  /// \returns A new Aff
  Aff pullbackMultiAff(const MultiAff &ma) const;

  /// \brief Generated from  ::<isl_aff_pullback_aff>
  ///
  /// \param [in] aff2
  ///
  /// \returns A new Aff
  Aff pullbackAff(const Aff &aff2) const;

  /// \brief Generated from  ::<isl_aff_scale_down_ui>
  ///
  /// \param [in] f
  ///
  /// \returns A new Aff
  Aff scaleDownUi(unsigned int f) const;

  /// \brief Generated from  ::<isl_aff_scale_down_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new Aff
  Aff scaleDownVal(const Val &v) const;

  /// \brief Generated from  ::<isl_aff_scale_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new Aff
  Aff scaleVal(const Val &v) const;

  /// \brief Generated from  ::<isl_aff_set_coefficient_si>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] v
  ///
  /// \returns A new Aff
  Aff setCoefficientSi(DimType type, int pos, int v) const;

  /// \brief Generated from  ::<isl_aff_set_coefficient_val>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] v
  ///
  /// \returns A new Aff
  Aff setCoefficientVal(DimType type, int pos, const Val &v) const;

  /// \brief Generated from  ::<isl_aff_set_constant_si>
  ///
  /// \param [in] v
  ///
  /// \returns A new Aff
  Aff setConstantSi(int v) const;

  /// \brief Generated from  ::<isl_aff_set_constant_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new Aff
  Aff setConstantVal(const Val &v) const;

  /// \brief Generated from  ::<isl_aff_set_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] id
  ///
  /// \returns A new Aff
  Aff setDimId(DimType type, unsigned int pos, const Id &id) const;

  /// \brief Generated from  ::<isl_aff_set_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] s
  ///
  /// \returns A new Aff
  Aff setDimName(DimType type, unsigned int pos, std::string s) const;

  /// \brief Generated from  ::<isl_aff_set_tuple_id>
  ///
  /// \param [in] type
  /// \param [in] id
  ///
  /// \returns A new Aff
  Aff setTupleId(DimType type, const Id &id) const;

  /// \brief Generated from  ::<isl_aff_sub>
  ///
  /// \param [in] aff2
  ///
  /// \returns A new Aff
  Aff sub(const Aff &aff2) const;

  /// \brief Generated from  ::<isl_aff_zero_basic_set>
  ///
  ///
  /// \returns A new BasicSet
  BasicSet zeroBasicSet() const;

  Aff(const Aff &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  Aff &operator=(const Aff &Other);
  Aff (Aff && Other) : ctx(Other.Context()), This(Other.Give()) {}
  Aff &operator=(Aff && Other) {
    isl_aff *New = Other.Give();
    isl_aff_free((isl_aff *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const Aff &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_Aff_H
