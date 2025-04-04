#ifndef DIRECTORY_NODE_HPP
#define DIRECTORY_NODE_HPP

#include "file-system-node.hpp"
#include <iostream>
#include <string>
#include <vector>
class DirectoryNode : public FileSystemNode {
  std::string m_name;
  std::vector<FileSystemNode *> children;

  static const int INDENT_INCREMENT = 3;

public:
  DirectoryNode(std::string name) : m_name(name) {}

  void add(FileSystemNode *child) { this->children.push_back(child); }

  void ls(int indent = 0) override {

    std::cout << std::string(indent, ' ') << "Directory (" << m_name << ")/\n";
    for (auto c : children) {
      c->ls(indent + INDENT_INCREMENT);
    }
  }
};

#endif // !DIRECTORY_NODE_HPP
