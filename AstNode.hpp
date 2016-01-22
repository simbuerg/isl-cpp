#ifndef ISL_CXX_AstNode_IMPL_H
#define ISL_CXX_AstNode_IMPL_H

#include "isl/AstNode.h"

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
}inline AstNode::~AstNode() {
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


} // namespace isl
#endif //ISL_CXX_AstNode_IMPL_H
