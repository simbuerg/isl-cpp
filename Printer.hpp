#ifndef ISL_CXX_Printer_IMPL_H
#define ISL_CXX_Printer_IMPL_H

#include "isl/Printer.h"

#include "isl/Aff.hpp"
#include "isl/AstExpr.hpp"
#include "isl/AstNode.hpp"
#include "isl/Band.hpp"
#include "isl/BasicMap.hpp"
#include "isl/BasicSet.hpp"
#include "isl/Constraint.hpp"
#include "isl/Id.hpp"
#include "isl/IdToAstExpr.hpp"
#include "isl/LocalSpace.hpp"
#include "isl/Map.hpp"
#include "isl/MultiAff.hpp"
#include "isl/MultiPwAff.hpp"
#include "isl/Point.hpp"
#include "isl/PwAff.hpp"
#include "isl/PwMultiAff.hpp"
#include "isl/PwQpolynomial.hpp"
#include "isl/PwQpolynomialFold.hpp"
#include "isl/Qpolynomial.hpp"
#include "isl/QpolynomialFold.hpp"
#include "isl/Schedule.hpp"
#include "isl/ScheduleNode.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/UnionMap.hpp"
#include "isl/UnionPwMultiAff.hpp"
#include "isl/UnionPwQpolynomial.hpp"
#include "isl/UnionPwQpolynomialFold.hpp"
#include "isl/UnionSet.hpp"
#include "isl/Val.hpp"
#include "isl/Vec.hpp"
#include "isl/Ctx.hpp"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline std::shared_ptr<isl::Printer::ptr> Printer::GetCopy() const {
  return Printer::This;
}

inline Printer Printer::toStr(const Ctx &ctx) {
  Ctx _ctx = ctx.Context();
  _ctx.lock();
  isl_printer *That = isl_printer_to_str((ctx.Get()));
  ctx.unlock();

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_printer_to_str returned a NULL pointer.");
  }

  std::shared_ptr<ptr> _That(new ptr(That));
  return Printer(_ctx, _That);
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_printer *Printer::Give() {
  isl_printer *res = This.get()->p;
  This.get()->p = nullptr;
  This.reset();
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_printer *Printer::Get() const {  return (isl_printer *)This.get()->p;
}

inline Printer Printer::asPrinter() const {
  return *const_cast<Printer *>(this);
}

inline Printer Printer::endLine() const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  // Call isl_printer_end_line
  isl_printer * res =  isl_printer_end_line((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_end_line returned a NULL pointer.");
  }
  return Printer(res);
}

inline Format Printer::getOutputFormat() const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  // Call isl_printer_get_output_format
  enum isl_format res =  isl_printer_get_output_format((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Format)res;
}

inline std::string Printer::getStr() const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  // Call isl_printer_get_str
  char * res =  isl_printer_get_str((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  std::string res_;
  if (ctx.hasError()) {
    handleError("isl_printer_get_str returned a NULL pointer.");
  }
  res_ = res;
  free((void *)res);
  return res_;
}

inline Printer Printer::indent(int indent) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  // Call isl_printer_indent
  isl_printer * res =  isl_printer_indent((self).Give(), indent);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_indent returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printAff(const Aff &aff) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  Aff _cast_aff = aff.asAff();
  // Call isl_printer_print_aff
  isl_printer * res =  isl_printer_print_aff((self).Give(), (_cast_aff).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_aff returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printAstExpr(const AstExpr &expr) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  AstExpr _cast_expr = expr.asAstExpr();
  // Call isl_printer_print_ast_expr
  isl_printer * res =  isl_printer_print_ast_expr((self).Give(), (_cast_expr).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_ast_expr returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printAstNode(const AstNode &node) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  AstNode _cast_node = node.asAstNode();
  // Call isl_printer_print_ast_node
  isl_printer * res =  isl_printer_print_ast_node((self).Give(), (_cast_node).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_ast_node returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printBand(const Band &band) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  Band _cast_band = band.asBand();
  // Call isl_printer_print_band
  isl_printer * res =  isl_printer_print_band((self).Give(), (_cast_band).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_band returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printBasicMap(const BasicMap &bmap) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  BasicMap _cast_bmap = bmap.asBasicMap();
  // Call isl_printer_print_basic_map
  isl_printer * res =  isl_printer_print_basic_map((self).Give(), (_cast_bmap).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_basic_map returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printBasicSet(const BasicSet &bset) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  BasicSet _cast_bset = bset.asBasicSet();
  // Call isl_printer_print_basic_set
  isl_printer * res =  isl_printer_print_basic_set((self).Give(), (_cast_bset).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_basic_set returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printConstraint(const Constraint &c) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  Constraint _cast_c = c.asConstraint();
  // Call isl_printer_print_constraint
  isl_printer * res =  isl_printer_print_constraint((self).Give(), (_cast_c).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_constraint returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printDouble(double d) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  // Call isl_printer_print_double
  isl_printer * res =  isl_printer_print_double((self).Give(), d);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_double returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printId(const Id &id) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  Id _cast_id = id.asId();
  // Call isl_printer_print_id
  isl_printer * res =  isl_printer_print_id((self).Give(), (_cast_id).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_id returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printIdToAstExpr(const IdToAstExpr &hmap) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  IdToAstExpr _cast_hmap = hmap.asIdToAstExpr();
  // Call isl_printer_print_id_to_ast_expr
  isl_printer * res =  isl_printer_print_id_to_ast_expr((self).Give(), (_cast_hmap).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_id_to_ast_expr returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printInt(int i) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  // Call isl_printer_print_int
  isl_printer * res =  isl_printer_print_int((self).Give(), i);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_int returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printLocalSpace(const LocalSpace &ls) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  LocalSpace _cast_ls = ls.asLocalSpace();
  // Call isl_printer_print_local_space
  isl_printer * res =  isl_printer_print_local_space((self).Give(), (_cast_ls).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_local_space returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printMap(const Map &map) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  Map _cast_map = map.asMap();
  // Call isl_printer_print_map
  isl_printer * res =  isl_printer_print_map((self).Give(), (_cast_map).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_map returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printMultiAff(const MultiAff &maff) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  MultiAff _cast_maff = maff.asMultiAff();
  // Call isl_printer_print_multi_aff
  isl_printer * res =  isl_printer_print_multi_aff((self).Give(), (_cast_maff).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_multi_aff returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printMultiPwAff(const MultiPwAff &mpa) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  MultiPwAff _cast_mpa = mpa.asMultiPwAff();
  // Call isl_printer_print_multi_pw_aff
  isl_printer * res =  isl_printer_print_multi_pw_aff((self).Give(), (_cast_mpa).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_multi_pw_aff returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printPoint(const Point &pnt) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  Point _cast_pnt = pnt.asPoint();
  // Call isl_printer_print_point
  isl_printer * res =  isl_printer_print_point((self).Give(), (_cast_pnt).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_point returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printPwAff(const PwAff &pwaff) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  PwAff _cast_pwaff = pwaff.asPwAff();
  // Call isl_printer_print_pw_aff
  isl_printer * res =  isl_printer_print_pw_aff((self).Give(), (_cast_pwaff).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_pw_aff returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printPwMultiAff(const PwMultiAff &pma) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  PwMultiAff _cast_pma = pma.asPwMultiAff();
  // Call isl_printer_print_pw_multi_aff
  isl_printer * res =  isl_printer_print_pw_multi_aff((self).Give(), (_cast_pma).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_pw_multi_aff returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printPwQpolynomial(const PwQpolynomial &pwqp) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  PwQpolynomial _cast_pwqp = pwqp.asPwQpolynomial();
  // Call isl_printer_print_pw_qpolynomial
  isl_printer * res =  isl_printer_print_pw_qpolynomial((self).Give(), (_cast_pwqp).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_pw_qpolynomial returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printPwQpolynomialFold(const PwQpolynomialFold &pwf) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  PwQpolynomialFold _cast_pwf = pwf.asPwQpolynomialFold();
  // Call isl_printer_print_pw_qpolynomial_fold
  isl_printer * res =  isl_printer_print_pw_qpolynomial_fold((self).Give(), (_cast_pwf).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_pw_qpolynomial_fold returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printQpolynomial(const Qpolynomial &qp) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  Qpolynomial _cast_qp = qp.asQpolynomial();
  // Call isl_printer_print_qpolynomial
  isl_printer * res =  isl_printer_print_qpolynomial((self).Give(), (_cast_qp).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_qpolynomial returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printQpolynomialFold(const QpolynomialFold &fold) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  QpolynomialFold _cast_fold = fold.asQpolynomialFold();
  // Call isl_printer_print_qpolynomial_fold
  isl_printer * res =  isl_printer_print_qpolynomial_fold((self).Give(), (_cast_fold).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_qpolynomial_fold returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printSchedule(const Schedule &schedule) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  Schedule _cast_schedule = schedule.asSchedule();
  // Call isl_printer_print_schedule
  isl_printer * res =  isl_printer_print_schedule((self).Give(), (_cast_schedule).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_schedule returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printScheduleNode(const ScheduleNode &node) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  ScheduleNode _cast_node = node.asScheduleNode();
  // Call isl_printer_print_schedule_node
  isl_printer * res =  isl_printer_print_schedule_node((self).Give(), (_cast_node).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_schedule_node returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printSet(const Set &map) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  Set _cast_map = map.asSet();
  // Call isl_printer_print_set
  isl_printer * res =  isl_printer_print_set((self).Give(), (_cast_map).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_set returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printSpace(const Space &dim) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  Space _cast_dim = dim.asSpace();
  // Call isl_printer_print_space
  isl_printer * res =  isl_printer_print_space((self).Give(), (_cast_dim).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_space returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printStr(std::string s) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  // Call isl_printer_print_str
  isl_printer * res =  isl_printer_print_str((self).Give(), s.c_str());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_str returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printUnionMap(const UnionMap &umap) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  UnionMap _cast_umap = umap.asUnionMap();
  // Call isl_printer_print_union_map
  isl_printer * res =  isl_printer_print_union_map((self).Give(), (_cast_umap).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_union_map returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printUnionPwMultiAff(const UnionPwMultiAff &upma) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  UnionPwMultiAff _cast_upma = upma.asUnionPwMultiAff();
  // Call isl_printer_print_union_pw_multi_aff
  isl_printer * res =  isl_printer_print_union_pw_multi_aff((self).Give(), (_cast_upma).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_union_pw_multi_aff returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printUnionPwQpolynomial(const UnionPwQpolynomial &upwqp) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  UnionPwQpolynomial _cast_upwqp = upwqp.asUnionPwQpolynomial();
  // Call isl_printer_print_union_pw_qpolynomial
  isl_printer * res =  isl_printer_print_union_pw_qpolynomial((self).Give(), (_cast_upwqp).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_union_pw_qpolynomial returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printUnionPwQpolynomialFold(const UnionPwQpolynomialFold &upwf) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  UnionPwQpolynomialFold _cast_upwf = upwf.asUnionPwQpolynomialFold();
  // Call isl_printer_print_union_pw_qpolynomial_fold
  isl_printer * res =  isl_printer_print_union_pw_qpolynomial_fold((self).Give(), (_cast_upwf).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_union_pw_qpolynomial_fold returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printUnionSet(const UnionSet &uset) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  UnionSet _cast_uset = uset.asUnionSet();
  // Call isl_printer_print_union_set
  isl_printer * res =  isl_printer_print_union_set((self).Give(), (_cast_uset).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_union_set returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printVal(const Val &v) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  Val _cast_v = v.asVal();
  // Call isl_printer_print_val
  isl_printer * res =  isl_printer_print_val((self).Give(), (_cast_v).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_val returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::printVec(const Vec &vec) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  Vec _cast_vec = vec.asVec();
  // Call isl_printer_print_vec
  isl_printer * res =  isl_printer_print_vec((self).Give(), (_cast_vec).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_print_vec returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::setIndent(int indent) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  // Call isl_printer_set_indent
  isl_printer * res =  isl_printer_set_indent((self).Give(), indent);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_set_indent returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::setOutputFormat(Format output_format) const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  // Call isl_printer_set_output_format
  isl_printer * res =  isl_printer_set_output_format((self).Give(), (enum isl_format)output_format);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_set_output_format returned a NULL pointer.");
  }
  return Printer(res);
}

inline Printer Printer::startLine() const {
  ctx.lock();
  Printer self = asPrinter();
  // Prepare arguments
  // Call isl_printer_start_line
  isl_printer * res =  isl_printer_start_line((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_printer_start_line returned a NULL pointer.");
  }
  return Printer(res);
}

} // namespace isl
#endif //ISL_CXX_Printer_IMPL_H
