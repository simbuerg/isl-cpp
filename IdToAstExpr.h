#ifndef ISL_CXX_IdToAstExpr_H
#define ISL_CXX_IdToAstExpr_H


#include "isl/id_to_ast_expr.h"
#include "isl/Bool.h"
#include "isl/Ctx.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/ast.h"
#include "isl/id.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class AstExpr;
class Id;

class IdToAstExpr {
protected:

public:
  Ctx ctx;
  void * This;
  explicit IdToAstExpr(Ctx ctx, isl_id_to_ast_expr *That) : ctx(ctx), This((void *)That) {}
  explicit IdToAstExpr(Ctx ctx, void *That) : ctx(ctx), This(That) {}
  const Ctx &Context() const { return ctx; }
  isl_id_to_ast_expr *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_id_to_ast_expr *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_id_to_ast_expr *Get() const;

  /// \brief Constructor for isl_id_to_ast_expr_alloc
  ///
  /// \param ctx
  /// \param min_size
  static IdToAstExpr alloc(const Ctx &ctx, int min_size);
  virtual ~IdToAstExpr();

  virtual IdToAstExpr asIdToAstExpr() const;

  /// \brief Generated from  ::<isl_id_to_ast_expr_foreach>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreach_(const std::function<isl_stat(isl_id *, isl_ast_expr *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_id_to_ast_expr_get>
  ///
  /// \param [in] key
  ///
  /// \returns A new AstExpr
  AstExpr get(const Id &key) const;

  /// \brief Generated from  ::<isl_id_to_ast_expr_has>
  ///
  /// \param [in] key
  ///
  /// \returns A new Bool
  Bool has(const Id &key) const;

  /// \brief Generated from  ::<isl_id_to_ast_expr_set>
  ///
  /// \param [in] key
  /// \param [in] val
  ///
  /// \returns A new IdToAstExpr
  IdToAstExpr set(const Id &key, const AstExpr &val) const;
  IdToAstExpr(const IdToAstExpr &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  IdToAstExpr &operator=(const IdToAstExpr &Other);
  IdToAstExpr (IdToAstExpr && Other) : ctx(Other.Context()), This(Other.This) {}
  IdToAstExpr &operator=(IdToAstExpr && Other) {
    isl_id_to_ast_expr *New = Other.Give();
    isl_id_to_ast_expr_free((isl_id_to_ast_expr *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const IdToAstExpr &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_IdToAstExpr_H
