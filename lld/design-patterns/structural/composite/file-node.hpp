#ifndef FILE_NODE_HPP
#define FILE_NODE_HPP

#include "file-system-node.hpp"
#include <iostream>
#include <string>

class FileNode : public FileSystemNode {
  std::string m_name;

public:
  FileNode(std::string name) : m_name(name) {}

  void ls(int indent = 0) override {
    std::cout << std::string(indent, ' ') << m_name << ".file\n";
  }
};

#endif // !FILE_NODE_HPP
