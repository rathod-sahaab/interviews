#ifndef DIRECTORY_NODE_HPP
#define DIRECTORY_NODE_HPP

#include "file-system-node.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <vector>
class DirectoryNode : public FileSystemNode {
  std::string m_name;
  std::vector<std::unique_ptr<FileSystemNode>> children;

  static const int INDENT_INCREMENT = 3;

public:
  DirectoryNode(std::string name) : m_name(name) {}

  void add(std::unique_ptr<FileSystemNode> child) {
    this->children.push_back(std::move(child));
  }

  void ls(int indent = 0) override {

    std::cout << std::string(indent, ' ') << "Directory (" << m_name << ")/\n";
    for (const auto &c : children) {
      c->ls(indent + INDENT_INCREMENT);
    }
  }
};

#endif // !DIRECTORY_NODE_HPP
