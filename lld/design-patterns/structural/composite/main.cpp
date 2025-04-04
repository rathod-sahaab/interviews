#include "directory-node.hpp"
#include "file-node.hpp"
#include "file-system-node.hpp"
int main(int argc, char *argv[]) {
  {
    DirectoryNode *root = new DirectoryNode("root");
    DirectoryNode *dir1 = new DirectoryNode("1");
    DirectoryNode *dir2 = new DirectoryNode("2");
    DirectoryNode *dir3 = new DirectoryNode("3");

    FileNode *fileA = new FileNode("A");
    FileNode *fileB = new FileNode("B");
    FileNode *fileC = new FileNode("C");

    root->add(fileA);
    root->add(dir1);
    root->add(dir2);

    dir2->add(fileB);
    dir2->add(fileC);

    dir2->add(dir3);

    root->ls();

    delete root;
    delete dir1;
    delete dir2;
    delete dir3;

    delete fileA;
    delete fileB;
    delete fileC;
  }
  return 0;
}
