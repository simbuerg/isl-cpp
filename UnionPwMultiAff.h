#ifndef ISL_CXX_UnionPwMultiAff_H
#define ISL_CXX_UnionPwMultiAff_H


#include "isl/aff.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class MultiUnionPwAff;

class UnionPwMultiAff {
protected:

public:
  Ctx ctx;
  void * This;
  explicit UnionPwMultiAff(Ctx ctx, isl_union_pw_multi_aff *That) : ctx(ctx), This((void *)That) {}
  explicit UnionPwMultiAff(Ctx ctx, void *That) : ctx(ctx), This(That) {}
  const Ctx &Context() const { return ctx; }
  isl_union_pw_multi_aff *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_union_pw_multi_aff *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_union_pw_multi_aff *Get() const;

  /// \brief Constructor for isl_union_pw_multi_aff_from_multi_union_pw_aff
  ///
  /// \param mupa
  static UnionPwMultiAff fromMultiUnionPwAff(const MultiUnionPwAff &mupa);
  virtual ~UnionPwMultiAff();

  virtual UnionPwMultiAff asUnionPwMultiAff() const;
  UnionPwMultiAff(const UnionPwMultiAff &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  UnionPwMultiAff &operator=(const UnionPwMultiAff &Other);
  UnionPwMultiAff (UnionPwMultiAff && Other) : ctx(Other.Context()), This(Other.This) {}
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
