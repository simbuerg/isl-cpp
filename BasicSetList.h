#ifndef ISL_CXX_BasicSetList_H
#define ISL_CXX_BasicSetList_H


#include "isl/set.h"
#include "isl/Ctx.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class BasicSet;

class BasicSetList {
protected:
  Ctx ctx;
  void * This;
  explicit BasicSetList(Ctx ctx, isl_basic_set_list *That) : ctx(ctx), This((void *)That) {}
  explicit BasicSetList(Ctx ctx, void *That) : ctx(ctx), This(That) {}

public:
  const Ctx &Context() const { return ctx; }
  ///rief Wrap an existing isl object.
  ///
  /// This serves as an entry point into the C++ API.
  /// We take ownership of the isl object.
  ///
  /// \param That the isl_basic_set_list we want to wrap.
  explicit BasicSetList(isl_basic_set_list *That) : BasicSetList(Ctx(isl_basic_set_list_get_ctx(That)), That) {}
  isl_basic_set_list *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_basic_set_list *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_basic_set_list *Get() const;

  /// \brief Constructor for isl_basic_set_list_alloc
  ///
  /// \param ctx
  /// \param n
  static BasicSetList alloc(const Ctx &ctx, int n);
  virtual ~BasicSetList();

  virtual BasicSetList asBasicSetList() const;

  /// \brief Generated from  ::<isl_basic_set_list_add>
  ///
  /// \param [in] el
  ///
  /// \returns A new BasicSetList
  BasicSetList add(const BasicSet &el) const;
  BasicSetList(const BasicSetList &Other) : BasicSetList(Other.Context(), Other.GetCopy()) {}
  BasicSetList &operator=(const BasicSetList &Other);
  BasicSetList (BasicSetList && Other) : BasicSetList(Other.Context(), Other.This) {}
  BasicSetList &operator=(BasicSetList && Other) {
    isl_basic_set_list *New = Other.Give();
    isl_basic_set_list_free((isl_basic_set_list *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const BasicSetList &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_BasicSetList_H
