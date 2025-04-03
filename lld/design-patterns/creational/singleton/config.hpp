#ifndef CONFING_SINGLETON_HPP
#define CONFING_SINGLETON_HPP

#include <iostream>
#include <string>

class Config {
  static Config *s_instance;

  Config(std::string conn_string) : db(conn_string) {
    std::cout << "Creating object! [Xpensive]\n";
  }

public:
  std::string db;

  static Config *getInstance();
};

Config *Config::s_instance = nullptr;

Config *Config::getInstance() {
  if (s_instance == nullptr) {
    // ...fetch values from file or network
    s_instance = new Config("https://example.com/");
  }
  std::cout << "Serving object\n";
  return s_instance;
}

#endif // !CONFING_SINGLETON_HPP
