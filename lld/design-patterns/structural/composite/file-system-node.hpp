#ifndef FILE_SYSTEM_NODE_HPP
#define FILE_SYSTEM_NODE_HPP

class FileSystemNode {
public:
  virtual void ls(int indent = 0) = 0;
  virtual ~FileSystemNode() = default;
};

#endif // !FILE_SYSTEM_NODE_HPP
