#ifndef ISL_CXX_AstExpr_H
#define ISL_CXX_AstExpr_H


#include "isl/ast.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {

class AstExpr {
protected:
  Ctx ctx;
  void * This;
public:
  explicit AstExpr(Ctx ctx, isl_ast_expr *That) : ctx(ctx), This(That) {}
  AstExpr() : ctx(Ctx(nullptr)), This(nullptr) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_ast_expr *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_ast_expr *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_ast_expr *Get() const;
public:
  virtual ~AstExpr();
  AstExpr(const AstExpr &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  AstExpr &operator=(const AstExpr &Other);
  AstExpr (AstExpr && Other) : ctx(Other.Context()), This(Other.Give()) {}
  AstExpr &operator=(AstExpr && Other) {
    isl_ast_expr *New = Other.Give();
    isl_ast_expr_free((isl_ast_expr *)This);
    This = New;
    ctx = Other.Context();
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const AstExpr &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_AstExpr_H
