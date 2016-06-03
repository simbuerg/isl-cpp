#ifndef ISL_CXX_UnionPwMultiAff_H
#define ISL_CXX_UnionPwMultiAff_H


#include "isl/aff.h"
#include "isl/Ctx.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class MultiUnionPwAff;
class PwMultiAff;
class UnionPwAff;

class UnionPwMultiAff {
protected:
  Ctx ctx;
  void * This;
public:
  explicit UnionPwMultiAff(Ctx ctx, isl_union_pw_multi_aff *That) : ctx(ctx), This(That) {}
  UnionPwMultiAff() : ctx(Ctx(nullptr)), This(nullptr) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_union_pw_multi_aff *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_union_pw_multi_aff *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_union_pw_multi_aff *Get() const;


  /// \brief Constructor for isl_union_pw_multi_aff_from_pw_multi_aff
  ///
  /// \param pma
  static UnionPwMultiAff fromPwMultiAff(const PwMultiAff &pma);


  /// \brief Constructor for isl_union_pw_multi_aff_read_from_str
  ///
  /// \param ctx
  /// \param str
  static UnionPwMultiAff readFromStr(const Ctx &ctx, std::string str);


  /// \brief Constructor for isl_union_pw_multi_aff_from_union_pw_aff
  ///
  /// \param upa
  static UnionPwMultiAff fromUnionPwAff(const UnionPwAff &upa);


  /// \brief Constructor for isl_union_pw_multi_aff_from_multi_union_pw_aff
  ///
  /// \param mupa
  static UnionPwMultiAff fromMultiUnionPwAff(const MultiUnionPwAff &mupa);
public:
  virtual ~UnionPwMultiAff();



  /// \brief Generated from  ::<isl_union_pw_multi_aff_add>
  ///
  /// \param [in] upma2
  ///
  /// \returns A new UnionPwMultiAff
  UnionPwMultiAff add(const UnionPwMultiAff &upma2) const;

  /// \brief Generated from  ::<isl_union_pw_multi_aff_flat_range_product>
  ///
  /// \param [in] upma2
  ///
  /// \returns A new UnionPwMultiAff
  UnionPwMultiAff flatRangeProduct(const UnionPwMultiAff &upma2) const;

  /// \brief Generated from  ::<isl_union_pw_multi_aff_pullback_union_pw_multi_aff>
  ///
  /// \param [in] upma2
  ///
  /// \returns A new UnionPwMultiAff
  UnionPwMultiAff pullbackUnionPwMultiAff(const UnionPwMultiAff &upma2) const;

  /// \brief Generated from  ::<isl_union_pw_multi_aff_to_str>
  ///
  ///
  /// \returns A new std::string
  std::string toStr() const;

  /// \brief Generated from  ::<isl_union_pw_multi_aff_union_add>
  ///
  /// \param [in] upma2
  ///
  /// \returns A new UnionPwMultiAff
  UnionPwMultiAff unionAdd(const UnionPwMultiAff &upma2) const;

  UnionPwMultiAff(const UnionPwMultiAff &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  UnionPwMultiAff &operator=(const UnionPwMultiAff &Other);
  UnionPwMultiAff (UnionPwMultiAff && Other) : ctx(Other.Context()), This(Other.Give()) {}
  UnionPwMultiAff &operator=(UnionPwMultiAff && Other) {
    isl_union_pw_multi_aff *New = Other.Give();
    isl_union_pw_multi_aff_free((isl_union_pw_multi_aff *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const UnionPwMultiAff &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_UnionPwMultiAff_H
