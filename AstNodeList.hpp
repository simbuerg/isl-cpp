#ifndef ISL_CXX_AstNodeList_IMPL_H
#define ISL_CXX_AstNodeList_IMPL_H

#include "isl/AstNodeList.h"

#include "isl/AstNode.hpp"
#include "isl/Ctx.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include <cassert>

namespace isl {

inline isl_ast_node_list *AstNodeList::GetCopy() const {
  return isl_ast_node_list_copy((isl_ast_node_list *)This);
}
inline AstNodeList &AstNodeList::operator=(const AstNodeList &Other) {
  isl_ast_node_list *New = Other.GetCopy();
  isl_ast_node_list_free((isl_ast_node_list *)This);
  This = New;
  return *this;
}
inline AstNodeList AstNodeList::alloc(const Ctx &ctx, int n) {
  const Ctx &_ctx = ctx.Context();
  _ctx.lock();
  isl_ast_node_list *That = isl_ast_node_list_alloc((ctx.Get()), n);

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_ast_node_list_alloc returned a NULL pointer.");
  }

  return AstNodeList(_ctx, That);
}
inline AstNodeList::~AstNodeList() {
  isl_ast_node_list_free((isl_ast_node_list *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_ast_node_list *AstNodeList::Give() {
  isl_ast_node_list *res = (isl_ast_node_list *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_ast_node_list *AstNodeList::Get() const {  return (isl_ast_node_list *)This;
}

inline AstNodeList AstNodeList::add(const AstNode &el) const {
  ctx.lock();
  isl_ast_node_list * res =  isl_ast_node_list_add((*this).GetCopy(), (el).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_ast_node_list_add returned a NULL pointer.");
  }
  return AstNodeList(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_AstNodeList_IMPL_H
