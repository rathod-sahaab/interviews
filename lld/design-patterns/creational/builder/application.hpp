#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>
#include <string>

class Application {
  const std::string m_api_key;
  const std::string m_jwt_secret;
  const int m_keep_alive_seconds = 5;
  const int m_port = 3000;

public:
  Application(std::string api_key, std::string jwt_secret)
      : m_api_key(api_key), m_jwt_secret(jwt_secret) {}

  Application(std::string api_key, std::string jwt_secret,
              int keep_alive_seconds)
      : m_api_key(api_key), m_jwt_secret(jwt_secret),
        m_keep_alive_seconds(keep_alive_seconds) {}

  Application(std::string api_key, std::string jwt_secret,
              int keep_alive_seconds, int port)
      : m_api_key(api_key), m_jwt_secret(jwt_secret),
        m_keep_alive_seconds(keep_alive_seconds), m_port(port) {}

  friend std::ostream &operator<<(std::ostream &os, const Application &app) {
    os << "Application Configuration:\n"
       << "  API Key: " << app.m_api_key << "\n"
       << "  JWT Secret: " << app.m_jwt_secret << "\n"
       << "  Keep Alive (seconds): " << app.m_keep_alive_seconds << "\n"
       << "  Port: " << app.m_port << "\n";
    return os;
  }
};

#endif // !APPLICATION_HPP
