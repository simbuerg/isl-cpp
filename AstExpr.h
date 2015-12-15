#ifndef ISL_CXX_AstExpr_H
#define ISL_CXX_AstExpr_H


#include "isl/ast.h"
#include "isl/AstExprType.h"
#include "isl/AstOpType.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Id;
class IdToAstExpr;
class Printer;
class Val;

class AstExpr {
protected:
  Ctx ctx;
  void * This;
  explicit AstExpr(Ctx ctx, isl_ast_expr *That) : ctx(ctx), This((void *)That) {}
  explicit AstExpr(Ctx ctx, void *That) : ctx(ctx), This(That) {}

public:
  const Ctx &Context() const { return ctx; }
  ///rief Wrap an existing isl object.
  ///
  /// This serves as an entry point into the C++ API.
  /// We take ownership of the isl object.
  ///
  /// \param That the isl_ast_expr we want to wrap.
  explicit AstExpr(isl_ast_expr *That) : AstExpr(Ctx(isl_ast_expr_get_ctx(That)), That) {}
  isl_ast_expr *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_ast_expr *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_ast_expr *Get() const;

  /// \brief Constructor for isl_ast_expr_from_val
  ///
  /// \param v
  static AstExpr fromVal(const Val &v);
  /// \brief Constructor for isl_ast_expr_from_id
  ///
  /// \param id
  static AstExpr fromId(const Id &id);
  virtual ~AstExpr();
  std::string toStr(isl::Format F = isl::Format::FIsl) const;

  virtual AstExpr asAstExpr() const;

  /// \brief Generated from  ::<isl_ast_expr_add>
  ///
  /// \param [in] expr2
  ///
  /// \returns A new AstExpr
  AstExpr add(const AstExpr &expr2) const;

  /// \brief Generated from  ::<isl_ast_expr_and>
  ///
  /// \param [in] expr2
  ///
  /// \returns A new AstExpr
  AstExpr and_(const AstExpr &expr2) const;

  /// \brief Generated from  ::<isl_ast_expr_div>
  ///
  /// \param [in] expr2
  ///
  /// \returns A new AstExpr
  AstExpr div(const AstExpr &expr2) const;

  /// \brief Generated from  ::<isl_ast_expr_get_id>
  ///
  ///
  /// \returns A new Id
  Id getId() const;

  /// \brief Generated from  ::<isl_ast_expr_get_op_arg>
  ///
  /// \param [in] pos
  ///
  /// \returns A new AstExpr
  AstExpr getOpArg(int pos) const;

  /// \brief Generated from  ::<isl_ast_expr_get_op_n_arg>
  ///
  ///
  /// \returns A new int
  int getOpNArg() const;

  /// \brief Generated from  ::<isl_ast_expr_get_op_type>
  ///
  ///
  /// \returns A new AstOpType
  AstOpType getOpType() const;

  /// \brief Generated from  ::<isl_ast_expr_get_type>
  ///
  ///
  /// \returns A new AstExprType
  AstExprType getType() const;

  /// \brief Generated from  ::<isl_ast_expr_get_val>
  ///
  ///
  /// \returns A new Val
  Val getVal() const;

  /// \brief Generated from  ::<isl_ast_expr_mul>
  ///
  /// \param [in] expr2
  ///
  /// \returns A new AstExpr
  AstExpr mul(const AstExpr &expr2) const;

  /// \brief Generated from  ::<isl_ast_expr_neg>
  ///
  ///
  /// \returns A new AstExpr
  AstExpr neg() const;

  /// \brief Generated from  ::<isl_ast_expr_or>
  ///
  /// \param [in] expr2
  ///
  /// \returns A new AstExpr
  AstExpr or_(const AstExpr &expr2) const;

  /// \brief Generated from  ::<isl_ast_expr_set_op_arg>
  ///
  /// \param [in] pos
  /// \param [in] arg
  ///
  /// \returns A new AstExpr
  AstExpr setOpArg(int pos, const AstExpr &arg) const;

  /// \brief Generated from  ::<isl_ast_expr_sub>
  ///
  /// \param [in] expr2
  ///
  /// \returns A new AstExpr
  AstExpr sub(const AstExpr &expr2) const;

  /// \brief Generated from  ::<isl_ast_expr_substitute_ids>
  ///
  /// \param [in] id2expr
  ///
  /// \returns A new AstExpr
  AstExpr substituteIds(const IdToAstExpr &id2expr) const;
  AstExpr(const AstExpr &Other) : AstExpr(Other.Context(), Other.GetCopy()) {}
  AstExpr &operator=(const AstExpr &Other);
  AstExpr (AstExpr && Other) : AstExpr(Other.Context(), Other.This) {}
  AstExpr &operator=(AstExpr && Other) {
    isl_ast_expr *New = Other.Give();
    isl_ast_expr_free((isl_ast_expr *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const AstExpr &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_AstExpr_H
