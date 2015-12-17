#ifndef ISL_CXX_AstExprList_H
#define ISL_CXX_AstExprList_H


#include "isl/ast.h"
#include "isl/Ctx.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class AstExpr;

class AstExprList {
protected:

public:
  Ctx ctx;
  void * This;
  explicit AstExprList(Ctx ctx, isl_ast_expr_list *That) : ctx(ctx), This((void *)That) {}
  explicit AstExprList(Ctx ctx, void *That) : ctx(ctx), This(That) {}
  const Ctx &Context() const { return ctx; }
  isl_ast_expr_list *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_ast_expr_list *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_ast_expr_list *Get() const;

  /// \brief Constructor for isl_ast_expr_list_alloc
  ///
  /// \param ctx
  /// \param n
  static AstExprList alloc(const Ctx &ctx, int n);
  virtual ~AstExprList();

  virtual AstExprList asAstExprList() const;

  /// \brief Generated from  ::<isl_ast_expr_list_add>
  ///
  /// \param [in] el
  ///
  /// \returns A new AstExprList
  AstExprList add(const AstExpr &el) const;
  AstExprList(const AstExprList &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  AstExprList &operator=(const AstExprList &Other);
  AstExprList (AstExprList && Other) : ctx(Other.Context()), This(Other.This) {}
  AstExprList &operator=(AstExprList && Other) {
    isl_ast_expr_list *New = Other.Give();
    isl_ast_expr_list_free((isl_ast_expr_list *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const AstExprList &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_AstExprList_H
