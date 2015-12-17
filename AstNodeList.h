#ifndef ISL_CXX_AstNodeList_H
#define ISL_CXX_AstNodeList_H


#include "isl/ast.h"
#include "isl/Ctx.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class AstNode;

class AstNodeList {
protected:

public:
  Ctx ctx;
  void * This;
  explicit AstNodeList(Ctx ctx, isl_ast_node_list *That) : ctx(ctx), This((void *)That) {}
  explicit AstNodeList(Ctx ctx, void *That) : ctx(ctx), This(That) {}
  const Ctx &Context() const { return ctx; }
  isl_ast_node_list *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_ast_node_list *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_ast_node_list *Get() const;

  /// \brief Constructor for isl_ast_node_list_alloc
  ///
  /// \param ctx
  /// \param n
  static AstNodeList alloc(const Ctx &ctx, int n);
  virtual ~AstNodeList();

  virtual AstNodeList asAstNodeList() const;

  /// \brief Generated from  ::<isl_ast_node_list_add>
  ///
  /// \param [in] el
  ///
  /// \returns A new AstNodeList
  AstNodeList add(const AstNode &el) const;
  AstNodeList(const AstNodeList &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  AstNodeList &operator=(const AstNodeList &Other);
  AstNodeList (AstNodeList && Other) : ctx(Other.Context()), This(Other.This) {}
  AstNodeList &operator=(AstNodeList && Other) {
    isl_ast_node_list *New = Other.Give();
    isl_ast_node_list_free((isl_ast_node_list *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const AstNodeList &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_AstNodeList_H
