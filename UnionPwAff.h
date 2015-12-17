#ifndef ISL_CXX_UnionPwAff_H
#define ISL_CXX_UnionPwAff_H


#include "isl/aff.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {

class UnionPwAff {
protected:

public:
  Ctx ctx;
  void * This;
  explicit UnionPwAff(Ctx ctx, isl_union_pw_aff *That) : ctx(ctx), This((void *)That) {}
  explicit UnionPwAff(Ctx ctx, void *That) : ctx(ctx), This(That) {}
  const Ctx &Context() const { return ctx; }
  isl_union_pw_aff *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_union_pw_aff *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_union_pw_aff *Get() const;

  virtual ~UnionPwAff();

  virtual UnionPwAff asUnionPwAff() const;
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
