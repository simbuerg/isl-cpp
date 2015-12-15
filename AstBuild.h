#ifndef ISL_CXX_AstBuild_H
#define ISL_CXX_AstBuild_H


#include "isl/ast_build.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/ast.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class AstExpr;
class AstNode;
class MultiPwAff;
class PwAff;
class PwMultiAff;
class Set;
class Space;
class UnionMap;

class AstBuild {
protected:
  Ctx ctx;
  void * This;
  explicit AstBuild(Ctx ctx, isl_ast_build *That) : ctx(ctx), This((void *)That) {}
  explicit AstBuild(Ctx ctx, void *That) : ctx(ctx), This(That) {}

public:
  const Ctx &Context() const { return ctx; }
  ///rief Wrap an existing isl object.
  ///
  /// This serves as an entry point into the C++ API.
  /// We take ownership of the isl object.
  ///
  /// \param That the isl_ast_build we want to wrap.
  explicit AstBuild(isl_ast_build *That) : AstBuild(Ctx(isl_ast_build_get_ctx(That)), That) {}
  isl_ast_build *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_ast_build *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_ast_build *Get() const;

  /// \brief Constructor for isl_ast_build_from_context
  ///
  /// \param set
  static AstBuild fromContext(const Set &set);
  virtual ~AstBuild();

  virtual AstBuild asAstBuild() const;

  /// \brief Generated from  ::<isl_ast_build_access_from_multi_pw_aff>
  ///
  /// \param [in] mpa
  ///
  /// \returns A new AstExpr
  AstExpr accessFromMultiPwAff(const MultiPwAff &mpa) const;

  /// \brief Generated from  ::<isl_ast_build_access_from_pw_multi_aff>
  ///
  /// \param [in] pma
  ///
  /// \returns A new AstExpr
  AstExpr accessFromPwMultiAff(const PwMultiAff &pma) const;

  /// \brief Generated from  ::<isl_ast_build_ast_from_schedule>
  ///
  /// \param [in] schedule
  ///
  /// \returns A new AstNode
  AstNode astFromSchedule(const UnionMap &schedule) const;

  /// \brief Generated from  ::<isl_ast_build_call_from_multi_pw_aff>
  ///
  /// \param [in] mpa
  ///
  /// \returns A new AstExpr
  AstExpr callFromMultiPwAff(const MultiPwAff &mpa) const;

  /// \brief Generated from  ::<isl_ast_build_call_from_pw_multi_aff>
  ///
  /// \param [in] pma
  ///
  /// \returns A new AstExpr
  AstExpr callFromPwMultiAff(const PwMultiAff &pma) const;

  /// \brief Generated from  ::<isl_ast_build_expr_from_pw_aff>
  ///
  /// \param [in] pa
  ///
  /// \returns A new AstExpr
  AstExpr exprFromPwAff(const PwAff &pa) const;

  /// \brief Generated from  ::<isl_ast_build_get_schedule>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap getSchedule() const;

  /// \brief Generated from  ::<isl_ast_build_get_schedule_space>
  ///
  ///
  /// \returns A new Space
  Space getScheduleSpace() const;

  /// \brief Generated from  ::<isl_ast_build_set_at_each_domain>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new AstBuild
  AstBuild setAtEachDomain(const std::function<isl_ast_node *(isl_ast_node *, isl_ast_build *, void *)> && fn, void * user) const;
  AstBuild(const AstBuild &Other) : AstBuild(Other.Context(), Other.GetCopy()) {}
  AstBuild &operator=(const AstBuild &Other);
  AstBuild (AstBuild && Other) : AstBuild(Other.Context(), Other.This) {}
  AstBuild &operator=(AstBuild && Other) {
    isl_ast_build *New = Other.Give();
    isl_ast_build_free((isl_ast_build *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const AstBuild &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_AstBuild_H
