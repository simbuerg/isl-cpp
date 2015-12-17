#ifndef ISL_CXX_AstNode_H
#define ISL_CXX_AstNode_H


#include "isl/ast.h"
#include "isl/AstNodeType.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class AstExpr;
class AstPrintOptions;
class Printer;

class AstNode {
protected:

public:
  Ctx ctx;
  void * This;
  explicit AstNode(Ctx ctx, isl_ast_node *That) : ctx(ctx), This((void *)That) {}
  explicit AstNode(Ctx ctx, void *That) : ctx(ctx), This(That) {}
  const Ctx &Context() const { return ctx; }
  isl_ast_node *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_ast_node *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_ast_node *Get() const;

  /// \brief Constructor for isl_ast_node_alloc_user
  ///
  /// \param expr
  static AstNode allocUser(const AstExpr &expr);
  virtual ~AstNode();

  virtual AstNode asAstNode() const;

  /// \brief Generated from  ::<isl_ast_node_get_type>
  ///
  ///
  /// \returns A new AstNodeType
  AstNodeType getType() const;

  /// \brief Generated from  ::<isl_ast_node_print>
  ///
  /// \param [in] p
  /// \param [in] options
  ///
  /// \returns A new Printer
  Printer print(const Printer &p, const AstPrintOptions &options) const;

  /// \brief Generated from  ::<isl_ast_node_user_get_expr>
  ///
  ///
  /// \returns A new AstExpr
  AstExpr userGetExpr() const;
  AstNode(const AstNode &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  AstNode &operator=(const AstNode &Other);
  AstNode (AstNode && Other) : ctx(Other.Context()), This(Other.This) {}
  AstNode &operator=(AstNode && Other) {
    isl_ast_node *New = Other.Give();
    isl_ast_node_free((isl_ast_node *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const AstNode &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_AstNode_H
