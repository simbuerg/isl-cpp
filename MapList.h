#ifndef ISL_CXX_MapList_H
#define ISL_CXX_MapList_H


#include "isl/map_list.h"
#include "isl/Ctx.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class Map;

class MapList {
protected:
  Ctx ctx;
  void * This;
public:
  explicit MapList(Ctx ctx, isl_map_list *That) : ctx(ctx), This((void *)That) {}
  explicit MapList(Ctx ctx, void *That) : ctx(ctx), This(That) {}
  const Ctx &Context() const { return ctx; }
  isl_map_list *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_map_list *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_map_list *Get() const;


  /// \brief Constructor for isl_map_list_alloc
  ///
  /// \param ctx
  /// \param n
  static MapList alloc(const Ctx &ctx, int n);
public:
  virtual ~MapList();

  MapList asMapList() const;

  /// \brief Generated from  ::<isl_map_list_add>
  ///
  /// \param [in] el
  ///
  /// \returns A new MapList
  MapList add(const Map &el) const;
  MapList(const MapList &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  MapList &operator=(const MapList &Other);
  MapList (MapList && Other) : ctx(Other.Context()), This(Other.This) {}
  MapList &operator=(MapList && Other) {
    isl_map_list *New = Other.Give();
    isl_map_list_free((isl_map_list *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const MapList &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_MapList_H
