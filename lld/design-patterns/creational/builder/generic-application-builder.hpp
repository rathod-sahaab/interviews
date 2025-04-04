#ifndef GENERIC_APPLICATION_BUILDER_HPP
#define GENERIC_APPLICATION_BUILDER_HPP

#include "application-builder.hpp"
#include "application.hpp"
#include <optional>
#include <string>

class GenericApplicationBuilder : public ApplicationBuilder {
  std::string m_api_key;
  std::string m_jwt_secret;
  std::optional<int> m_keep_alive_seconds = std::nullopt;
  std::optional<int> m_port = std::nullopt;

public:
  GenericApplicationBuilder *set_api_key(std::string api_key) {
    m_api_key = api_key;
    return this;
  }
  GenericApplicationBuilder *set_jwt_secret(std::string jwt_secret) {
    m_jwt_secret = jwt_secret;
    return this;
  }
  GenericApplicationBuilder *set_keep_alive_seconds(int keep_alive_seconds) {
    m_keep_alive_seconds = keep_alive_seconds;
    return this;
  }
  GenericApplicationBuilder *set_port(int port) {
    m_port = port;
    return this;
  }

  Application *build() {
    if (m_api_key.empty() or m_jwt_secret.empty()) {
      return nullptr;
    }

    if (m_port.has_value() and m_keep_alive_seconds.has_value()) {
      return new Application(m_api_key, m_jwt_secret,
                             m_keep_alive_seconds.value(),
                             this->m_port.value());
    }

    if (m_keep_alive_seconds.has_value()) {
      return new Application(m_api_key, m_jwt_secret,
                             m_keep_alive_seconds.value());
    }

    return new Application(m_api_key, m_jwt_secret);
  }
};

#endif // !GENERIC_APPLICATION_BUILDER_HPP
