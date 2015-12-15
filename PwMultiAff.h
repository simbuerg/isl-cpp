#ifndef ISL_CXX_PwMultiAff_H
#define ISL_CXX_PwMultiAff_H


#include "isl/aff.h"
#include "isl/Bool.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/aff.h"
#include "isl/set.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Id;
class MultiAff;
class Printer;
class PwAff;
class Set;
class Space;
class Val;

class PwMultiAff {
protected:
  Ctx ctx;
  void * This;
  explicit PwMultiAff(Ctx ctx, isl_pw_multi_aff *That) : ctx(ctx), This((void *)That) {}
  explicit PwMultiAff(Ctx ctx, void *That) : ctx(ctx), This(That) {}

public:
  const Ctx &Context() const { return ctx; }
  ///rief Wrap an existing isl object.
  ///
  /// This serves as an entry point into the C++ API.
  /// We take ownership of the isl object.
  ///
  /// \param That the isl_pw_multi_aff we want to wrap.
  explicit PwMultiAff(isl_pw_multi_aff *That) : PwMultiAff(Ctx(isl_pw_multi_aff_get_ctx(That)), That) {}
  isl_pw_multi_aff *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_pw_multi_aff *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_pw_multi_aff *Get() const;

  /// \brief Constructor for isl_pw_multi_aff_from_multi_aff
  ///
  /// \param ma
  static PwMultiAff fromMultiAff(const MultiAff &ma);
  /// \brief Constructor for isl_pw_multi_aff_from_pw_aff
  ///
  /// \param pa
  static PwMultiAff fromPwAff(const PwAff &pa);
  /// \brief Constructor for isl_pw_multi_aff_alloc
  ///
  /// \param set
  /// \param maff
  static PwMultiAff alloc(const Set &set, const MultiAff &maff);
  virtual ~PwMultiAff();
  std::string toStr(isl::Format F = isl::Format::FIsl) const;

  virtual PwMultiAff asPwMultiAff() const;

  /// \brief Generated from  ::<isl_pw_multi_aff_add>
  ///
  /// \param [in] pma2
  ///
  /// \returns A new PwMultiAff
  PwMultiAff add(const PwMultiAff &pma2) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_align_params>
  ///
  /// \param [in] model
  ///
  /// \returns A new PwMultiAff
  PwMultiAff alignParams(const Space &model) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_coalesce>
  ///
  ///
  /// \returns A new PwMultiAff
  PwMultiAff coalesce() const;

  /// \brief Generated from  ::<isl_pw_multi_aff_dim>
  ///
  /// \param [in] type
  ///
  /// \returns A new unsigned int
  unsigned int dim(DimType type) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_domain>
  ///
  ///
  /// \returns A new Set
  Set domain() const;

  /// \brief Generated from  ::<isl_pw_multi_aff_drop_dims>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new PwMultiAff
  PwMultiAff dropDims(DimType type, unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_flat_range_product>
  ///
  /// \param [in] pma2
  ///
  /// \returns A new PwMultiAff
  PwMultiAff flatRangeProduct(const PwMultiAff &pma2) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_foreach_piece>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachPiece(const std::function<isl_stat(isl_set *, isl_multi_aff *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_get_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Id
  Id getDimId(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_get_dim_name>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new std::string
  std::string getDimName(DimType type, unsigned int pos) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_get_domain_space>
  ///
  ///
  /// \returns A new Space
  Space getDomainSpace() const;

  /// \brief Generated from  ::<isl_pw_multi_aff_get_pw_aff>
  ///
  /// \param [in] pos
  ///
  /// \returns A new PwAff
  PwAff getPwAff(int pos) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_pw_multi_aff_get_tuple_id>
  ///
  /// \param [in] type
  ///
  /// \returns A new Id
  Id getTupleId(DimType type) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_get_tuple_name>
  ///
  /// \param [in] type
  ///
  /// \returns A new std::string
  std::string getTupleName(DimType type) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_gist>
  ///
  /// \param [in] set
  ///
  /// \returns A new PwMultiAff
  PwMultiAff gist(const Set &set) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_gist_params>
  ///
  /// \param [in] set
  ///
  /// \returns A new PwMultiAff
  PwMultiAff gistParams(const Set &set) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_has_tuple_id>
  ///
  /// \param [in] type
  ///
  /// \returns A new Bool
  Bool hasTupleId(DimType type) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_has_tuple_name>
  ///
  /// \param [in] type
  ///
  /// \returns A new Bool
  Bool hasTupleName(DimType type) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_intersect_domain>
  ///
  /// \param [in] set
  ///
  /// \returns A new PwMultiAff
  PwMultiAff intersectDomain(const Set &set) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_intersect_params>
  ///
  /// \param [in] set
  ///
  /// \returns A new PwMultiAff
  PwMultiAff intersectParams(const Set &set) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_plain_is_equal>
  ///
  /// \param [in] pma2
  ///
  /// \returns A new Bool
  Bool plainIsEqual(const PwMultiAff &pma2) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_product>
  ///
  /// \param [in] pma2
  ///
  /// \returns A new PwMultiAff
  PwMultiAff product(const PwMultiAff &pma2) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_project_domain_on_params>
  ///
  ///
  /// \returns A new PwMultiAff
  PwMultiAff projectDomainOnParams() const;

  /// \brief Generated from  ::<isl_pw_multi_aff_pullback_multi_aff>
  ///
  /// \param [in] ma
  ///
  /// \returns A new PwMultiAff
  PwMultiAff pullbackMultiAff(const MultiAff &ma) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_pullback_pw_multi_aff>
  ///
  /// \param [in] pma2
  ///
  /// \returns A new PwMultiAff
  PwMultiAff pullbackPwMultiAff(const PwMultiAff &pma2) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_range_product>
  ///
  /// \param [in] pma2
  ///
  /// \returns A new PwMultiAff
  PwMultiAff rangeProduct(const PwMultiAff &pma2) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_scale_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new PwMultiAff
  PwMultiAff scaleVal(const Val &v) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_set_dim_id>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] id
  ///
  /// \returns A new PwMultiAff
  PwMultiAff setDimId(DimType type, unsigned int pos, const Id &id) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_set_pw_aff>
  ///
  /// \param [in] pos
  /// \param [in] pa
  ///
  /// \returns A new PwMultiAff
  PwMultiAff setPwAff(unsigned int pos, const PwAff &pa) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_set_tuple_id>
  ///
  /// \param [in] type
  /// \param [in] id
  ///
  /// \returns A new PwMultiAff
  PwMultiAff setTupleId(DimType type, const Id &id) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_sub>
  ///
  /// \param [in] pma2
  ///
  /// \returns A new PwMultiAff
  PwMultiAff sub(const PwMultiAff &pma2) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_union_add>
  ///
  /// \param [in] pma2
  ///
  /// \returns A new PwMultiAff
  PwMultiAff unionAdd(const PwMultiAff &pma2) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_union_lexmax>
  ///
  /// \param [in] pma2
  ///
  /// \returns A new PwMultiAff
  PwMultiAff unionLexmax(const PwMultiAff &pma2) const;

  /// \brief Generated from  ::<isl_pw_multi_aff_union_lexmin>
  ///
  /// \param [in] pma2
  ///
  /// \returns A new PwMultiAff
  PwMultiAff unionLexmin(const PwMultiAff &pma2) const;
  PwMultiAff(const PwMultiAff &Other) : PwMultiAff(Other.Context(), Other.GetCopy()) {}
  PwMultiAff &operator=(const PwMultiAff &Other);
  PwMultiAff (PwMultiAff && Other) : PwMultiAff(Other.Context(), Other.This) {}
  PwMultiAff &operator=(PwMultiAff && Other) {
    isl_pw_multi_aff *New = Other.Give();
    isl_pw_multi_aff_free((isl_pw_multi_aff *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const PwMultiAff &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_PwMultiAff_H
