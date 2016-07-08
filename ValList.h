#ifndef ISL_CXX_ValList_H
#define ISL_CXX_ValList_H


#include "isl/val.h"
#include "isl/Ctx.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class Val;

class ValList {
protected:
  Ctx ctx;
  void * This;
public:
  explicit ValList(Ctx ctx, isl_val_list *That) : ctx(ctx), This(That) {}
  ValList() : ctx(Ctx(nullptr)), This(nullptr) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_val_list *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_val_list *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_val_list *Get() const;


  /// \brief Constructor for isl_val_list_alloc
  ///
  /// \param ctx
  /// \param n
  static ValList alloc(const Ctx &ctx, int n);
public:
  virtual ~ValList();
  /// \brief Generated from  ::<isl_val_list_add>
  ///
  /// \param [in] el
  ///
  /// \returns A new ValList
  ValList add(const Val &el) const;

  ValList(const ValList &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  ValList &operator=(const ValList &Other);
  ValList (ValList && Other) : ctx(Other.Context()), This(Other.Give()) {}
  ValList &operator=(ValList && Other) {
    isl_val_list *New = Other.Give();
    isl_val_list_free((isl_val_list *)This);
    This = New;
    ctx = Other.Context();
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const ValList &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_ValList_H
