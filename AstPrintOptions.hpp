#ifndef ISL_CXX_AstPrintOptions_IMPL_H
#define ISL_CXX_AstPrintOptions_IMPL_H

#include "isl/AstPrintOptions.h"

#include "isl/Ctx.hpp"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/ast.h"
#include "isl/printer.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_ast_print_options *AstPrintOptions::GetCopy() const {
  return isl_ast_print_options_copy((isl_ast_print_options *)This);
}
inline AstPrintOptions &AstPrintOptions::operator=(const AstPrintOptions &Other) {
  isl_ast_print_options *New = Other.GetCopy();
  isl_ast_print_options_free((isl_ast_print_options *)This);
  This = New;
  return *this;
}
inline AstPrintOptions AstPrintOptions::alloc(const Ctx &ctx) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_ast_print_options *That = isl_ast_print_options_alloc((ctx.Get()));
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_ast_print_options_alloc returned a NULL pointer.");
  }

  return AstPrintOptions(_ctx, That);
}
inline AstPrintOptions::~AstPrintOptions() {
  isl_ast_print_options_free((isl_ast_print_options *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_ast_print_options *AstPrintOptions::Give() {
  isl_ast_print_options *res = (isl_ast_print_options *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_ast_print_options *AstPrintOptions::Get() const {  return (isl_ast_print_options *)This;
}

inline AstPrintOptions AstPrintOptions::asAstPrintOptions() const {
  return AstPrintOptions(GetCopy());
}

inline AstPrintOptions AstPrintOptions::setPrintFor(const std::function<isl_printer *(isl_printer *, isl_ast_print_options *, isl_ast_node *, void *)> && print_for, void * user) const {
  ctx.lock();
  AstPrintOptions self = asAstPrintOptions();
  // Prepare arguments
  // Call isl_ast_print_options_set_print_for
  isl_ast_print_options * res =  isl_ast_print_options_set_print_for((self).Give(), get_fn_ptr<1>(print_for), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_print_options_set_print_for returned a NULL pointer.");
  }
  return AstPrintOptions(res);
}

inline AstPrintOptions AstPrintOptions::setPrintUser(const std::function<isl_printer *(isl_printer *, isl_ast_print_options *, isl_ast_node *, void *)> && print_user, void * user) const {
  ctx.lock();
  AstPrintOptions self = asAstPrintOptions();
  // Prepare arguments
  // Call isl_ast_print_options_set_print_user
  isl_ast_print_options * res =  isl_ast_print_options_set_print_user((self).Give(), get_fn_ptr<2>(print_user), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_ast_print_options_set_print_user returned a NULL pointer.");
  }
  return AstPrintOptions(res);
}

} // namespace isl
#endif //ISL_CXX_AstPrintOptions_IMPL_H
