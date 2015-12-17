#ifndef ISL_CXX_AstPrintOptions_H
#define ISL_CXX_AstPrintOptions_H


#include "isl/ast.h"
#include "isl/Ctx.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/ast.h"
#include "isl/printer.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {

class AstPrintOptions {
protected:

public:
  Ctx ctx;
  void * This;
  explicit AstPrintOptions(Ctx ctx, isl_ast_print_options *That) : ctx(ctx), This((void *)That) {}
  explicit AstPrintOptions(Ctx ctx, void *That) : ctx(ctx), This(That) {}
  const Ctx &Context() const { return ctx; }
  isl_ast_print_options *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_ast_print_options *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_ast_print_options *Get() const;

  /// \brief Constructor for isl_ast_print_options_alloc
  ///
  /// \param ctx
  static AstPrintOptions alloc(const Ctx &ctx);
  virtual ~AstPrintOptions();

  virtual AstPrintOptions asAstPrintOptions() const;

  /// \brief Generated from  ::<isl_ast_print_options_set_print_for>
  ///
  /// \param [in] print_for
  /// \param [in] user
  ///
  /// \returns A new AstPrintOptions
  AstPrintOptions setPrintFor(const std::function<isl_printer *(isl_printer *, isl_ast_print_options *, isl_ast_node *, void *)> && print_for, void * user) const;

  /// \brief Generated from  ::<isl_ast_print_options_set_print_user>
  ///
  /// \param [in] print_user
  /// \param [in] user
  ///
  /// \returns A new AstPrintOptions
  AstPrintOptions setPrintUser(const std::function<isl_printer *(isl_printer *, isl_ast_print_options *, isl_ast_node *, void *)> && print_user, void * user) const;
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
