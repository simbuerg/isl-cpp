#ifndef ISL_CXX_QpolynomialFold_H
#define ISL_CXX_QpolynomialFold_H


#include "isl/polynomial.h"
#include "isl/DimType.h"
#include "isl/Fold.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include "isl/polynomial.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class Point;
class Qpolynomial;
class Set;
class Space;
class Val;

class QpolynomialFold {
protected:
  Ctx ctx;
  void * This;
public:
  explicit QpolynomialFold(Ctx ctx, isl_qpolynomial_fold *That) : ctx(ctx), This(That) {}
  QpolynomialFold() : ctx(Ctx(nullptr)), This(nullptr) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_qpolynomial_fold *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_qpolynomial_fold *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_qpolynomial_fold *Get() const;


  /// \brief Constructor for isl_qpolynomial_fold_empty
  ///
  /// \param type
  /// \param dim
  static QpolynomialFold empty(Fold type, const Space &dim);


  /// \brief Constructor for isl_qpolynomial_fold_alloc
  ///
  /// \param type
  /// \param qp
  static QpolynomialFold alloc(Fold type, const Qpolynomial &qp);
public:
  virtual ~QpolynomialFold();
  /// \brief Generated from  ::<isl_qpolynomial_fold_eval>
  ///
  /// \param [in] pnt
  ///
  /// \returns A new Val
  Val eval(const Point &pnt) const;

  /// \brief Generated from  ::<isl_qpolynomial_fold_fold>
  ///
  /// \param [in] fold2
  ///
  /// \returns A new QpolynomialFold
  QpolynomialFold fold(const QpolynomialFold &fold2) const;

  /// \brief Generated from  ::<isl_qpolynomial_fold_foreach_qpolynomial>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachQpolynomial(const std::function<isl_stat(isl_qpolynomial *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_qpolynomial_fold_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_qpolynomial_fold_get_type>
  ///
  ///
  /// \returns A new Fold
  Fold getType() const;

  /// \brief Generated from  ::<isl_qpolynomial_fold_gist>
  ///
  /// \param [in] context
  ///
  /// \returns A new QpolynomialFold
  QpolynomialFold gist(const Set &context) const;

  /// \brief Generated from  ::<isl_qpolynomial_fold_gist_params>
  ///
  /// \param [in] context
  ///
  /// \returns A new QpolynomialFold
  QpolynomialFold gistParams(const Set &context) const;

  /// \brief Generated from  ::<isl_qpolynomial_fold_is_empty>
  ///
  ///
  /// \returns A new int
  int isEmpty() const;

  /// \brief Generated from  ::<isl_qpolynomial_fold_move_dims>
  ///
  /// \param [in] dst_type
  /// \param [in] dst_pos
  /// \param [in] src_type
  /// \param [in] src_pos
  /// \param [in] n
  ///
  /// \returns A new QpolynomialFold
  QpolynomialFold moveDims(DimType dst_type, unsigned int dst_pos, DimType src_type, unsigned int src_pos, unsigned int n) const;

  /// \brief Generated from  ::<isl_qpolynomial_fold_plain_is_equal>
  ///
  /// \param [in] fold2
  ///
  /// \returns A new int
  int plainIsEqual(const QpolynomialFold &fold2) const;

  /// \brief Generated from  ::<isl_qpolynomial_fold_scale_val>
  ///
  /// \param [in] v
  ///
  /// \returns A new QpolynomialFold
  QpolynomialFold scaleVal(const Val &v) const;

  /// \brief Generated from  ::<isl_qpolynomial_fold_substitute>
  ///
  /// \param [in] type
  /// \param [in] first
  /// \param [in] n
  /// \param [out] subs (isl_give)
  ///
  /// \returns A new QpolynomialFold
  QpolynomialFold substitute(DimType type, unsigned int first, unsigned int n, std::unique_ptr<Qpolynomial> * subs) const;

  QpolynomialFold(const QpolynomialFold &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  QpolynomialFold &operator=(const QpolynomialFold &Other);
  QpolynomialFold (QpolynomialFold && Other) : ctx(Other.Context()), This(Other.Give()) {}
  QpolynomialFold &operator=(QpolynomialFold && Other) {
    isl_qpolynomial_fold *New = Other.Give();
    isl_qpolynomial_fold_free((isl_qpolynomial_fold *)This);
    This = New;
    ctx = Other.Context();
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const QpolynomialFold &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_QpolynomialFold_H
