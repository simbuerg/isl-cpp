#ifndef ISL_CXX_Printer_H
#define ISL_CXX_Printer_H


#include "isl/printer.h"
#include "isl/Ctx.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Aff;
class AstExpr;
class AstNode;
class Band;
class BasicMap;
class BasicSet;
class Constraint;
class Id;
class IdToAstExpr;
class LocalSpace;
class Map;
class MultiAff;
class MultiPwAff;
class Point;
class PwAff;
class PwMultiAff;
class PwQpolynomial;
class PwQpolynomialFold;
class Qpolynomial;
class QpolynomialFold;
class Schedule;
class ScheduleNode;
class Set;
class Space;
class UnionMap;
class UnionPwMultiAff;
class UnionPwQpolynomial;
class UnionPwQpolynomialFold;
class UnionSet;
class Val;
class Vec;

class Printer {
protected:
  struct ptr {
    isl_printer *p;
    explicit ptr(isl_printer *p) : p(p) {}
    ~ptr() {
      isl_printer_free(p);
    }
    ptr(const ptr &other) = delete;
    ptr &operator=(const ptr &other) = delete;
    ptr(ptr && other) = delete;
    ptr &operator=(ptr && other) = delete;
  };
  Ctx ctx;
  std::shared_ptr<ptr> This;
  explicit Printer(Ctx ctx, std::shared_ptr<ptr> That) : ctx(ctx), This(That) {}

public:
  const Ctx &Context() const { return ctx; }
  ///rief Wrap an existing isl object.
  ///
  /// This serves as an entry point into the C++ API.
  /// We take ownership of the isl object.
  ///
  /// \param That the isl_printer we want to wrap.
  explicit Printer(isl_printer *That) : Printer(Ctx(isl_printer_get_ctx(That)), std::make_shared<isl::Printer::ptr>(That)) {}
  std::shared_ptr<isl::Printer::ptr> GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_printer *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_printer *Get() const;

  /// \brief Constructor for isl_printer_to_str
  ///
  /// \param ctx
  static Printer toStr(const Ctx &ctx);
  virtual ~Printer() = default;

  virtual Printer asPrinter() const;

  /// \brief Generated from  ::<isl_printer_end_line>
  ///
  ///
  /// \returns A new Printer
  Printer endLine() const;

  /// \brief Generated from  ::<isl_printer_get_output_format>
  ///
  ///
  /// \returns A new Format
  Format getOutputFormat() const;

  /// \brief Generated from  ::<isl_printer_get_str>
  ///
  ///
  /// \returns A new std::string
  std::string getStr() const;

  /// \brief Generated from  ::<isl_printer_indent>
  ///
  /// \param [in] indent
  ///
  /// \returns A new Printer
  Printer indent(int indent) const;

  /// \brief Generated from  ::<isl_printer_print_aff>
  ///
  /// \param [in] aff
  ///
  /// \returns A new Printer
  Printer printAff(const Aff &aff) const;

  /// \brief Generated from  ::<isl_printer_print_ast_expr>
  ///
  /// \param [in] expr
  ///
  /// \returns A new Printer
  Printer printAstExpr(const AstExpr &expr) const;

  /// \brief Generated from  ::<isl_printer_print_ast_node>
  ///
  /// \param [in] node
  ///
  /// \returns A new Printer
  Printer printAstNode(const AstNode &node) const;

  /// \brief Generated from  ::<isl_printer_print_band>
  ///
  /// \param [in] band
  ///
  /// \returns A new Printer
  Printer printBand(const Band &band) const;

  /// \brief Generated from  ::<isl_printer_print_basic_map>
  ///
  /// \param [in] bmap
  ///
  /// \returns A new Printer
  Printer printBasicMap(const BasicMap &bmap) const;

  /// \brief Generated from  ::<isl_printer_print_basic_set>
  ///
  /// \param [in] bset
  ///
  /// \returns A new Printer
  Printer printBasicSet(const BasicSet &bset) const;

  /// \brief Generated from  ::<isl_printer_print_constraint>
  ///
  /// \param [in] c
  ///
  /// \returns A new Printer
  Printer printConstraint(const Constraint &c) const;

  /// \brief Generated from  ::<isl_printer_print_double>
  ///
  /// \param [in] d
  ///
  /// \returns A new Printer
  Printer printDouble(double d) const;

  /// \brief Generated from  ::<isl_printer_print_id>
  ///
  /// \param [in] id
  ///
  /// \returns A new Printer
  Printer printId(const Id &id) const;

  /// \brief Generated from  ::<isl_printer_print_id_to_ast_expr>
  ///
  /// \param [in] hmap
  ///
  /// \returns A new Printer
  Printer printIdToAstExpr(const IdToAstExpr &hmap) const;

  /// \brief Generated from  ::<isl_printer_print_int>
  ///
  /// \param [in] i
  ///
  /// \returns A new Printer
  Printer printInt(int i) const;

  /// \brief Generated from  ::<isl_printer_print_local_space>
  ///
  /// \param [in] ls
  ///
  /// \returns A new Printer
  Printer printLocalSpace(const LocalSpace &ls) const;

  /// \brief Generated from  ::<isl_printer_print_map>
  ///
  /// \param [in] map
  ///
  /// \returns A new Printer
  Printer printMap(const Map &map) const;

  /// \brief Generated from  ::<isl_printer_print_multi_aff>
  ///
  /// \param [in] maff
  ///
  /// \returns A new Printer
  Printer printMultiAff(const MultiAff &maff) const;

  /// \brief Generated from  ::<isl_printer_print_multi_pw_aff>
  ///
  /// \param [in] mpa
  ///
  /// \returns A new Printer
  Printer printMultiPwAff(const MultiPwAff &mpa) const;

  /// \brief Generated from  ::<isl_printer_print_point>
  ///
  /// \param [in] pnt
  ///
  /// \returns A new Printer
  Printer printPoint(const Point &pnt) const;

  /// \brief Generated from  ::<isl_printer_print_pw_aff>
  ///
  /// \param [in] pwaff
  ///
  /// \returns A new Printer
  Printer printPwAff(const PwAff &pwaff) const;

  /// \brief Generated from  ::<isl_printer_print_pw_multi_aff>
  ///
  /// \param [in] pma
  ///
  /// \returns A new Printer
  Printer printPwMultiAff(const PwMultiAff &pma) const;

  /// \brief Generated from  ::<isl_printer_print_pw_qpolynomial>
  ///
  /// \param [in] pwqp
  ///
  /// \returns A new Printer
  Printer printPwQpolynomial(const PwQpolynomial &pwqp) const;

  /// \brief Generated from  ::<isl_printer_print_pw_qpolynomial_fold>
  ///
  /// \param [in] pwf
  ///
  /// \returns A new Printer
  Printer printPwQpolynomialFold(const PwQpolynomialFold &pwf) const;

  /// \brief Generated from  ::<isl_printer_print_qpolynomial>
  ///
  /// \param [in] qp
  ///
  /// \returns A new Printer
  Printer printQpolynomial(const Qpolynomial &qp) const;

  /// \brief Generated from  ::<isl_printer_print_qpolynomial_fold>
  ///
  /// \param [in] fold
  ///
  /// \returns A new Printer
  Printer printQpolynomialFold(const QpolynomialFold &fold) const;

  /// \brief Generated from  ::<isl_printer_print_schedule>
  ///
  /// \param [in] schedule
  ///
  /// \returns A new Printer
  Printer printSchedule(const Schedule &schedule) const;

  /// \brief Generated from  ::<isl_printer_print_schedule_node>
  ///
  /// \param [in] node
  ///
  /// \returns A new Printer
  Printer printScheduleNode(const ScheduleNode &node) const;

  /// \brief Generated from  ::<isl_printer_print_set>
  ///
  /// \param [in] map
  ///
  /// \returns A new Printer
  Printer printSet(const Set &map) const;

  /// \brief Generated from  ::<isl_printer_print_space>
  ///
  /// \param [in] dim
  ///
  /// \returns A new Printer
  Printer printSpace(const Space &dim) const;

  /// \brief Generated from  ::<isl_printer_print_str>
  ///
  /// \param [in] s
  ///
  /// \returns A new Printer
  Printer printStr(std::string s) const;

  /// \brief Generated from  ::<isl_printer_print_union_map>
  ///
  /// \param [in] umap
  ///
  /// \returns A new Printer
  Printer printUnionMap(const UnionMap &umap) const;

  /// \brief Generated from  ::<isl_printer_print_union_pw_multi_aff>
  ///
  /// \param [in] upma
  ///
  /// \returns A new Printer
  Printer printUnionPwMultiAff(const UnionPwMultiAff &upma) const;

  /// \brief Generated from  ::<isl_printer_print_union_pw_qpolynomial>
  ///
  /// \param [in] upwqp
  ///
  /// \returns A new Printer
  Printer printUnionPwQpolynomial(const UnionPwQpolynomial &upwqp) const;

  /// \brief Generated from  ::<isl_printer_print_union_pw_qpolynomial_fold>
  ///
  /// \param [in] upwf
  ///
  /// \returns A new Printer
  Printer printUnionPwQpolynomialFold(const UnionPwQpolynomialFold &upwf) const;

  /// \brief Generated from  ::<isl_printer_print_union_set>
  ///
  /// \param [in] uset
  ///
  /// \returns A new Printer
  Printer printUnionSet(const UnionSet &uset) const;

  /// \brief Generated from  ::<isl_printer_print_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new Printer
  Printer printVal(const Val &v) const;

  /// \brief Generated from  ::<isl_printer_print_vec>
  ///
  /// \param [in] vec
  ///
  /// \returns A new Printer
  Printer printVec(const Vec &vec) const;

  /// \brief Generated from  ::<isl_printer_set_indent>
  ///
  /// \param [in] indent
  ///
  /// \returns A new Printer
  Printer setIndent(int indent) const;

  /// \brief Generated from  ::<isl_printer_set_output_format>
  ///
  /// \param [in] output_format
  ///
  /// \returns A new Printer
  Printer setOutputFormat(Format output_format) const;

  /// \brief Generated from  ::<isl_printer_start_line>
  ///
  ///
  /// \returns A new Printer
  Printer startLine() const;
  Printer(const Printer &Other) : Printer(Other.Context(), Other.GetCopy()) {}
  Printer &operator=(const Printer &Other) = delete;
  Printer (Printer && Other) : Printer(Other.Context(), Other.This) {}
  Printer &operator=(Printer && Other) {
    std::swap(This, Other.This);
    return *this;
  }
};
} // namespace isl
#endif //ISL_CXX_Printer_H
