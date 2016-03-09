#ifndef ISL_CXX_AstPrintOptions_H
#define ISL_CXX_AstPrintOptions_H


#include "isl/ast.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {

class AstPrintOptions {
protected:
  Ctx ctx;
  void * This;
public:
  explicit AstPrintOptions(Ctx ctx, isl_ast_print_options *That) : ctx(ctx), This(That) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_ast_print_options *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_ast_print_options *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_ast_print_options *Get() const;
public:
  virtual ~AstPrintOptions();
  AstPrintOptions(const AstPrintOptions &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  AstPrintOptions &operator=(const AstPrintOptions &Other);
  AstPrintOptions (AstPrintOptions && Other) : ctx(Other.Context()), This(Other.This) {}
  AstPrintOptions &operator=(AstPrintOptions && Other) {
    isl_ast_print_options *New = Other.Give();
    isl_ast_print_options_free((isl_ast_print_options *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const AstPrintOptions &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_AstPrintOptions_H
