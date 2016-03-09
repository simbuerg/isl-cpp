#ifndef ISL_CXX_UnionPwAff_H
#define ISL_CXX_UnionPwAff_H


#include "isl/aff.h"
#include "isl/Ctx.h"
#include "isl/IslException.h"
#include "isl/UnionPwMultiAff.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class PwAff;

class UnionPwAff {
protected:
  Ctx ctx;
  void * This;
public:
  explicit UnionPwAff(Ctx ctx, isl_union_pw_aff *That) : ctx(ctx), This(That) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_union_pw_aff *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_union_pw_aff *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_union_pw_aff *Get() const;


  /// \brief Constructor for isl_union_pw_aff_from_pw_aff
  ///
  /// \param pa
  static UnionPwAff fromPwAff(const PwAff &pa);


  /// \brief Constructor for isl_union_pw_aff_read_from_str
  ///
  /// \param ctx
  /// \param str
  static UnionPwAff readFromStr(const Ctx &ctx, std::string str);
public:
  virtual ~UnionPwAff();


  /// \brief Generated from  ::<isl_union_pw_aff_add>
  ///
  /// \param [in] upa2
  ///
  /// \returns A new UnionPwAff
  UnionPwAff add(const UnionPwAff &upa2) const;

  /// \brief Generated from  ::<isl_union_pw_aff_pullback_union_pw_multi_aff>
  ///
  /// \param [in] upma
  ///
  /// \returns A new UnionPwAff
  UnionPwAff pullbackUnionPwMultiAff(const UnionPwMultiAff &upma) const;

  /// \brief Generated from  ::<isl_union_pw_aff_union_add>
  ///
  /// \param [in] upa2
  ///
  /// \returns A new UnionPwAff
  UnionPwAff unionAdd(const UnionPwAff &upa2) const;

  UnionPwAff(const UnionPwAff &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  UnionPwAff &operator=(const UnionPwAff &Other);
  UnionPwAff (UnionPwAff && Other) : ctx(Other.Context()), This(Other.This) {}
  UnionPwAff &operator=(UnionPwAff && Other) {
    isl_union_pw_aff *New = Other.Give();
    isl_union_pw_aff_free((isl_union_pw_aff *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const UnionPwAff &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_UnionPwAff_H
