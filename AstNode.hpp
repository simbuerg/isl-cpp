#ifndef ISL_CXX_AstNode_IMPL_H
#define ISL_CXX_AstNode_IMPL_H

#include "isl/AstNode.h"

#include "isl/AstExpr.hpp"
#include "isl/AstPrintOptions.hpp"
#include "isl/Printer.hpp"
#include "isl/AstNodeType.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_ast_node *AstNode::GetCopy() const {
  return isl_ast_node_copy((isl_ast_node *)This);
}
inline AstNode &AstNode::operator=(const AstNode &Other) {
  isl_ast_node *New = Other.GetCopy();
  isl_ast_node_free((isl_ast_node *)This);
  This = New;
  return *this;
}
inline AstNode AstNode::allocUser(const AstExpr &expr) {
  const Ctx &_ctx = expr.Context();
  _ctx.lock();
  AstExpr _cast_expr = expr.asAstExpr();
  isl_ast_node *That = isl_ast_node_alloc_user((_cast_expr).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_ast_node_alloc_user returned a NULL pointer.");
  }

  return AstNode(_ctx, That);
}
inline AstNode::~AstNode() {
  isl_ast_node_free((isl_ast_node *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_ast_node *AstNode::Give() {
  isl_ast_node *res = (isl_ast_node *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_ast_node *AstNode::Get() const {  return (isl_ast_node *)This;
}

inline AstNode AstNode::asAstNode() const {
  return AstNode(ctx, GetCopy());
}

inline AstNodeType AstNode::getType() const {
  ctx.lock();
  AstNode self = asAstNode();
  // Prepare arguments
  // Call isl_ast_node_get_type
  enum isl_ast_node_type res =  isl_ast_node_get_type((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (AstNodeType)res;
}

inline Printer AstNode::print(const Printer &p, const AstPrintOptions &options) const {
  ctx.lock();
  AstNode self = asAstNode();
  // Prepare arguments
  Printer _cast_p = p.asPrinter();
  AstPrintOptions _cast_options = options.asAstPrintOptions();
  // Call isl_ast_node_print
  isl_printer * res =  isl_ast_node_print((self).Get(), (_cast_p).Give(), (_cast_options).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_node_print returned a NULL pointer.");
  }
  return Printer(ctx, res);
}

inline AstExpr AstNode::userGetExpr() const {
  ctx.lock();
  AstNode self = asAstNode();
  // Prepare arguments
  // Call isl_ast_node_user_get_expr
  isl_ast_expr * res =  isl_ast_node_user_get_expr((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_node_user_get_expr returned a NULL pointer.");
  }
  return AstExpr(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_AstNode_IMPL_H
