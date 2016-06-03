#ifndef ISL_CXX_IdList_H
#define ISL_CXX_IdList_H


#include "isl/id.h"
#include "isl/Ctx.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class Id;

class IdList {
protected:
  Ctx ctx;
  void * This;
public:
  explicit IdList(Ctx ctx, isl_id_list *That) : ctx(ctx), This(That) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_id_list *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_id_list *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_id_list *Get() const;


  /// \brief Constructor for isl_id_list_alloc
  ///
  /// \param ctx
  /// \param n
  static IdList alloc(const Ctx &ctx, int n);
public:
  virtual ~IdList();
  /// \brief Generated from  ::<isl_id_list_add>
  ///
  /// \param [in] el
  ///
  /// \returns A new IdList
  IdList add(const Id &el) const;

  IdList(const IdList &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  IdList &operator=(const IdList &Other);
  IdList (IdList && Other) : ctx(Other.Context()), This(Other.Give()) {}
  IdList &operator=(IdList && Other) {
    isl_id_list *New = Other.Give();
    isl_id_list_free((isl_id_list *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const IdList &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_IdList_H
