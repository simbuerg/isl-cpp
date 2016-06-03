#ifndef ISL_CXX_MultiPwAff_H
#define ISL_CXX_MultiPwAff_H


#include "isl/aff.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include "isl/MultiUnionPwAff.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class MultiAff;
class PwAff;
class PwAffList;
class PwMultiAff;
class Space;

class MultiPwAff {
protected:
  Ctx ctx;
  void * This;
public:
  explicit MultiPwAff(Ctx ctx, isl_multi_pw_aff *That) : ctx(ctx), This(That) {}
  MultiPwAff() : ctx(Ctx(nullptr)), This(nullptr) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_multi_pw_aff *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_multi_pw_aff *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_multi_pw_aff *Get() const;


  /// \brief Constructor for isl_multi_pw_aff_from_pw_aff_list
  ///
  /// \param space
  /// \param list
  static MultiPwAff fromPwAffList(const Space &space, const PwAffList &list);


  /// \brief Constructor for isl_multi_pw_aff_zero
  ///
  /// \param space
  static MultiPwAff zero(const Space &space);


  /// \brief Constructor for isl_multi_pw_aff_from_multi_aff
  ///
  /// \param ma
  static MultiPwAff fromMultiAff(const MultiAff &ma);


  /// \brief Constructor for isl_multi_pw_aff_from_pw_aff
  ///
  /// \param pa
  static MultiPwAff fromPwAff(const PwAff &pa);


  /// \brief Constructor for isl_multi_pw_aff_from_pw_multi_aff
  ///
  /// \param pma
  static MultiPwAff fromPwMultiAff(const PwMultiAff &pma);


  /// \brief Constructor for isl_multi_pw_aff_read_from_str
  ///
  /// \param ctx
  /// \param str
  static MultiPwAff readFromStr(const Ctx &ctx, std::string str);
public:
  virtual ~MultiPwAff();


  /// \brief Generated from  ::<isl_multi_pw_aff_add>
  ///
  /// \param [in] multi2
  ///
  /// \returns A new MultiPwAff
  MultiPwAff add(const MultiPwAff &multi2) const;

  /// \brief Generated from  ::<isl_multi_pw_aff_find_dim_by_name>
  ///
  /// \param [in] type
  /// \param [in] name
  ///
  /// \returns A new int
  int findDimByName(DimType type, std::string name) const;

  /// \brief Generated from  ::<isl_multi_pw_aff_flat_range_product>
  ///
  /// \param [in] multi2
  ///
  /// \returns A new MultiPwAff
  MultiPwAff flatRangeProduct(const MultiPwAff &multi2) const;

  /// \brief Generated from  ::<isl_multi_pw_aff_from_range>
  ///
  ///
  /// \returns A new MultiPwAff
  MultiPwAff fromRange() const;

  /// \brief Generated from  ::<isl_multi_pw_aff_get_domain_space>
  ///
  ///
  /// \returns A new Space
  Space getDomainSpace() const;

  /// \brief Generated from  ::<isl_multi_pw_aff_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_multi_pw_aff_plain_is_equal>
  ///
  /// \param [in] multi2
  ///
  /// \returns A new Bool
  Bool plainIsEqual(const MultiPwAff &multi2) const;

  /// \brief Generated from  ::<isl_multi_pw_aff_product>
  ///
  /// \param [in] multi2
  ///
  /// \returns A new MultiPwAff
  MultiPwAff product(const MultiPwAff &multi2) const;

  /// \brief Generated from  ::<isl_multi_pw_aff_pullback_multi_aff>
  ///
  /// \param [in] ma
  ///
  /// \returns A new MultiPwAff
  MultiPwAff pullbackMultiAff(const MultiAff &ma) const;

  /// \brief Generated from  ::<isl_multi_pw_aff_pullback_multi_pw_aff>
  ///
  /// \param [in] mpa2
  ///
  /// \returns A new MultiPwAff
  MultiPwAff pullbackMultiPwAff(const MultiPwAff &mpa2) const;

  /// \brief Generated from  ::<isl_multi_pw_aff_pullback_pw_multi_aff>
  ///
  /// \param [in] pma
  ///
  /// \returns A new MultiPwAff
  MultiPwAff pullbackPwMultiAff(const PwMultiAff &pma) const;

  /// \brief Generated from  ::<isl_multi_pw_aff_range_product>
  ///
  /// \param [in] multi2
  ///
  /// \returns A new MultiPwAff
  MultiPwAff rangeProduct(const MultiPwAff &multi2) const;

  MultiPwAff(const MultiPwAff &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  MultiPwAff &operator=(const MultiPwAff &Other);
  MultiPwAff (MultiPwAff && Other) : ctx(Other.Context()), This(Other.Give()) {}
  MultiPwAff &operator=(MultiPwAff && Other) {
    isl_multi_pw_aff *New = Other.Give();
    isl_multi_pw_aff_free((isl_multi_pw_aff *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const MultiPwAff &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_MultiPwAff_H
