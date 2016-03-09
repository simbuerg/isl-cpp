#ifndef ISL_CXX_BasicMapList_H
#define ISL_CXX_BasicMapList_H


#include "isl/map_list.h"
#include "isl/Ctx.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class BasicMap;

class BasicMapList {
protected:
  Ctx ctx;
  void * This;
public:
  explicit BasicMapList(Ctx ctx, isl_basic_map_list *That) : ctx(ctx), This(That) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_basic_map_list *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_basic_map_list *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_basic_map_list *Get() const;


  /// \brief Constructor for isl_basic_map_list_alloc
  ///
  /// \param ctx
  /// \param n
  static BasicMapList alloc(const Ctx &ctx, int n);
public:
  virtual ~BasicMapList();
  /// \brief Generated from  ::<isl_basic_map_list_add>
  ///
  /// \param [in] el
  ///
  /// \returns A new BasicMapList
  BasicMapList add(const BasicMap &el) const;

  BasicMapList(const BasicMapList &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  BasicMapList &operator=(const BasicMapList &Other);
  BasicMapList (BasicMapList && Other) : ctx(Other.Context()), This(Other.This) {}
  BasicMapList &operator=(BasicMapList && Other) {
    isl_basic_map_list *New = Other.Give();
    isl_basic_map_list_free((isl_basic_map_list *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const BasicMapList &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_BasicMapList_H
