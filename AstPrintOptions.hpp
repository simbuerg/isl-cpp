#ifndef ISL_CXX_AstPrintOptions_IMPL_H
#define ISL_CXX_AstPrintOptions_IMPL_H

#include "isl/AstPrintOptions.h"

#include "isl/IslBase.h"
#include "isl/IslException.h"
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
}inline AstPrintOptions::~AstPrintOptions() {
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


} // namespace isl
#endif //ISL_CXX_AstPrintOptions_IMPL_H
