#ifndef ISL_CXX_MultiVal_H
#define ISL_CXX_MultiVal_H


#include "isl/val.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Val;

class MultiVal {
protected:

public:
  Ctx ctx;
  void * This;
  explicit MultiVal(Ctx ctx, isl_multi_val *That) : ctx(ctx), This((void *)That) {}
  explicit MultiVal(Ctx ctx, void *That) : ctx(ctx), This(That) {}
  const Ctx &Context() const { return ctx; }
  isl_multi_val *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_multi_val *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_multi_val *Get() const;

  /// \brief Constructor for isl_multi_val_read_from_str
  ///
  /// \param ctx
  /// \param str
  static MultiVal readFromStr(const Ctx &ctx, std::string str);
  virtual ~MultiVal();

  virtual MultiVal asMultiVal() const;

  /// \brief Generated from  ::<isl_multi_val_add_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new MultiVal
  MultiVal addVal(const Val &v) const;

  /// \brief Generated from  ::<isl_multi_val_mod_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new MultiVal
  MultiVal modVal(const Val &v) const;

  /// \brief Generated from  ::<isl_multi_val_plain_is_equal>
  ///
  /// \param [in] multi2
  ///
  /// \returns A new Bool
  Bool plainIsEqual(const MultiVal &multi2) const;
  MultiVal(const MultiVal &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  MultiVal &operator=(const MultiVal &Other);
  MultiVal (MultiVal && Other) : ctx(Other.Context()), This(Other.This) {}
  MultiVal &operator=(MultiVal && Other) {
    isl_multi_val *New = Other.Give();
    isl_multi_val_free((isl_multi_val *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const MultiVal &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_MultiVal_H
