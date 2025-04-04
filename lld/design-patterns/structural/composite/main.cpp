#include "directory-node.hpp"
#include "file-node.hpp"
#include "file-system-node.hpp"
#include <memory>
int main(int argc, char *argv[]) {
  {
    std::unique_ptr<DirectoryNode> root =
        std::make_unique<DirectoryNode>("root");
    std::unique_ptr<DirectoryNode> dir1 = std::make_unique<DirectoryNode>("1");
    std::unique_ptr<DirectoryNode> dir2 = std::make_unique<DirectoryNode>("2");
    std::unique_ptr<DirectoryNode> dir3 = std::make_unique<DirectoryNode>("3");

    std::unique_ptr<FileNode> fileA = std::make_unique<FileNode>("A");
    std::unique_ptr<FileNode> fileB = std::make_unique<FileNode>("B");
    std::unique_ptr<FileNode> fileC = std::make_unique<FileNode>("C");

    dir2->add(std::move(fileB));
    dir2->add(std::move(fileC));

    dir2->add(std::move(dir3));

    root->add(std::move(fileA));
    root->add(std::move(dir1));
    root->add(std::move(dir2));

    root->ls();
  }
  return 0;
}
