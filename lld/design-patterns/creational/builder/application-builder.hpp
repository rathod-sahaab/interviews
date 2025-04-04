
#ifndef APPLICATION_BUILDER_HPP
#define APPLICATION_BUILDER_HPP

#include "application.hpp"

class ApplicationBuilder {
public:
  virtual Application *build() = 0;
};

#endif //! APPLICATION_BUILDER_HPP
