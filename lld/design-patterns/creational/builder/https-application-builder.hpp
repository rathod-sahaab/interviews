#ifndef HTTPS_APPLICATION_BUILDER_HPP
#define HTTPS_APPLICATION_BUILDER_HPP

#include "application-builder.hpp"
#include "application.hpp"
#include <optional>
#include <string>

class HttpsApplicationBuilder : public ApplicationBuilder {
  std::string m_api_key;
  std::string m_jwt_secret;
  std::optional<int> m_keep_alive_seconds = std::nullopt;

public:
  HttpsApplicationBuilder *set_api_key(std::string api_key) {
    m_api_key = api_key;
    return this;
  }
  HttpsApplicationBuilder *set_jwt_secret(std::string jwt_secret) {
    m_jwt_secret = jwt_secret;
    return this;
  }
  HttpsApplicationBuilder *set_keep_alive_seconds(int keep_alive_seconds) {
    m_keep_alive_seconds = keep_alive_seconds;
    return this;
  }

  Application *build() {
    if (m_api_key.empty() or m_jwt_secret.empty()) {
      return nullptr;
    }

    const int HTTPS_PORT = 443;

    if (m_keep_alive_seconds.has_value()) {
      return new Application(m_api_key, m_jwt_secret,
                             m_keep_alive_seconds.value(), HTTPS_PORT);
    }

    return new Application(m_api_key, m_jwt_secret, 10, HTTPS_PORT);
  }
};

#endif // !HTTPS_APPLICATION_BUILDER_HPP
