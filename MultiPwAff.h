#ifndef ISL_CXX_MultiPwAff_H
#define ISL_CXX_MultiPwAff_H


#include "isl/aff.h"
#include "isl/Bool.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Printer;

class MultiPwAff {
protected:
  Ctx ctx;
  void * This;
  explicit MultiPwAff(Ctx ctx, isl_multi_pw_aff *That) : ctx(ctx), This((void *)That) {}
  explicit MultiPwAff(Ctx ctx, void *That) : ctx(ctx), This(That) {}

public:
  const Ctx &Context() const { return ctx; }
  ///rief Wrap an existing isl object.
  ///
  /// This serves as an entry point into the C++ API.
  /// We take ownership of the isl object.
  ///
  /// \param That the isl_multi_pw_aff we want to wrap.
  explicit MultiPwAff(isl_multi_pw_aff *That) : MultiPwAff(Ctx(isl_multi_pw_aff_get_ctx(That)), That) {}
  isl_multi_pw_aff *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_multi_pw_aff *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_multi_pw_aff *Get() const;

  virtual ~MultiPwAff();
  std::string toStr(isl::Format F = isl::Format::FIsl) const;

  virtual MultiPwAff asMultiPwAff() const;

  /// \brief Generated from  ::<isl_multi_pw_aff_plain_is_equal>
  ///
  /// \param [in] multi2
  ///
  /// \returns A new Bool
  Bool plainIsEqual(const MultiPwAff &multi2) const;
  MultiPwAff(const MultiPwAff &Other) : MultiPwAff(Other.Context(), Other.GetCopy()) {}
  MultiPwAff &operator=(const MultiPwAff &Other);
  MultiPwAff (MultiPwAff && Other) : MultiPwAff(Other.Context(), Other.This) {}
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
