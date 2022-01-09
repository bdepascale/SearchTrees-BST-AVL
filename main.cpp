#include "AVL.h"
#include "BST.h"
#include <chrono>
#include <fstream>
#include <iostream>
using namespace std;

void GenerateFiles();
int main() {

  // GenerateFiles();    //uncomment to allow generation oof new data files

  int time;

  BST BSTsmall;
  BST BSTmedium;
  BST BSTlarge;
  AVL AVLsmall;
  AVL AVLmedium;
  AVL AVLlarge;
  int data;

  // file to collect and record times
  ofstream dataFile;
  dataFile.open("DataCollected.csv");
  dataFile << "Insertions Ascending"
           << ","
           << "time (ms)"
           << ","
           << "Number Nodes" << endl;

  // ASCENDING
  // insertions
  // ***************************************************************************

  // AVL small insert
  auto started = std::chrono::high_resolution_clock::now();
  ifstream AscendSmallIn("AscendingSmall.txt");
  while (AscendSmallIn >> data) {
    AVLsmall.Add(data);
    cout << "adding " << data << endl;
  }
  auto done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL small"
           << "," << time << "," << AVLsmall.NumNodes << endl;

  // AVL medium insert
  ifstream AscendMediumIn("AscendingMedium.txt");
  started = std::chrono::high_resolution_clock::now();
  while (AscendMediumIn >> data) {
    AVLmedium.Add(data);
    cout << "adding " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL medium"
           << "," << time << "," << AVLmedium.NumNodes << endl;

  // AVL large insert
  ifstream AscendLargeIn("AscendingLarge.txt");
  started = std::chrono::high_resolution_clock::now();
  while (AscendLargeIn >> data) {
    AVLlarge.Add(data);
    cout << "adding " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL large"
           << "," << time << "," << AVLlarge.NumNodes << endl;

  AscendSmallIn.clear();
  AscendSmallIn.seekg(0, AscendSmallIn.beg);
  AscendMediumIn.clear();
  AscendMediumIn.seekg(0, AscendMediumIn.beg);
  AscendLargeIn.clear();
  AscendLargeIn.seekg(0, AscendLargeIn.beg);

  // BST small insert
  started = std::chrono::high_resolution_clock::now();

  while (AscendSmallIn >> data) {
    BSTsmall.Add(data);
    cout << "adding " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST small"
           << "," << time << "," << BSTsmall.NumNodes << endl;

  // BST medium insert

  started = std::chrono::high_resolution_clock::now();
  while (AscendMediumIn >> data) {
    BSTmedium.Add(data);
    cout << "adding " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST medium"
           << "," << time << "," << BSTmedium.NumNodes << endl;

  // BST large insert

  started = std::chrono::high_resolution_clock::now();
  while (AscendLargeIn >> data) {
    BSTlarge.Add(data);
    cout << "adding " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST large"
           << "," << time << "," << BSTlarge.NumNodes << endl;

  // Inorder
  // traversals*************************************************************
  //
  dataFile << endl;
  dataFile << endl;
  dataFile << "Traversal Ascending"
           << ","
           << "time (ms)"
           << ","
           << "Number Nodes" << endl;
  // AVL small
  started = std::chrono::high_resolution_clock::now();
  AVLsmall.printTree(AVLsmall.Root);
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL small"
           << "," << time << "," << AVLsmall.NumNodes << endl;

  // AVL med
  started = std::chrono::high_resolution_clock::now();
  AVLmedium.printTree(AVLmedium.Root);
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL medium"
           << "," << time << "," << AVLmedium.NumNodes << endl;

  // AVL large
  started = std::chrono::high_resolution_clock::now();
  AVLlarge.printTree(AVLlarge.Root);
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL large"
           << "," << time << "," << AVLlarge.NumNodes << endl;

  // BST small
  started = std::chrono::high_resolution_clock::now();
  BSTsmall.printTree(BSTsmall.Root);
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST small"
           << "," << time << "," << BSTsmall.NumNodes << endl;

  // BST medium
  started = std::chrono::high_resolution_clock::now();
  BSTmedium.printTree(BSTmedium.Root);
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST medium"
           << "," << time << "," << BSTmedium.NumNodes << endl;

  // BST large
  started = std::chrono::high_resolution_clock::now();
  BSTlarge.printTree(BSTlarge.Root);
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST large"
           << "," << time << "," << BSTlarge.NumNodes << endl;

  AscendSmallIn.clear();
  AscendSmallIn.seekg(0, AscendSmallIn.beg);
  AscendMediumIn.clear();
  AscendMediumIn.seekg(0, AscendMediumIn.beg);
  AscendLargeIn.clear();
  AscendLargeIn.seekg(0, AscendLargeIn.beg);

  // DELETIONS ASCENDING********************************************************

  dataFile << endl;
  dataFile << endl;
  dataFile << "Deletions Ascending"
           << ","
           << "time (ms)"
           << ","
           << "Number Nodes" << endl;

  int nodes;

  // AVL small

  nodes = AVLsmall.NumNodes;
  started = std::chrono::high_resolution_clock::now();

  while (AscendSmallIn >> data) {
    AVLsmall.Delete(data, AVLsmall.Root);
    cout << "deleting " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL small"
           << "," << time << "," << nodes << endl;

  // AVL medium
  nodes = AVLmedium.NumNodes;
  started = std::chrono::high_resolution_clock::now();
  while (AscendMediumIn >> data) {
    AVLmedium.Delete(data, AVLmedium.Root);
    cout << "deleting " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL medium"
           << "," << time << "," << nodes << endl;

  // AVL large
  nodes = AVLlarge.NumNodes;
  started = std::chrono::high_resolution_clock::now();
  while (AscendLargeIn >> data) {
    AVLlarge.Delete(data, AVLlarge.Root);
    cout << "deleting " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL large"
           << "," << time << "," << nodes << endl;

  AscendSmallIn.clear();
  AscendSmallIn.seekg(0, AscendSmallIn.beg);
  AscendMediumIn.clear();
  AscendMediumIn.seekg(0, AscendMediumIn.beg);
  AscendLargeIn.clear();
  AscendLargeIn.seekg(0, AscendLargeIn.beg);

  // BST small

  nodes = BSTsmall.NumNodes;
  started = std::chrono::high_resolution_clock::now();

  while (AscendSmallIn >> data) {
    BSTsmall.Delete(data, BSTsmall.Root);
    cout << "deleting " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST small"
           << "," << time << "," << nodes << endl;

  // BST medium
  nodes = BSTmedium.NumNodes;
  started = std::chrono::high_resolution_clock::now();
  while (AscendMediumIn >> data) {
    BSTmedium.Delete(data, BSTmedium.Root);
    cout << "deleting " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST medium"
           << "," << time << "," << nodes << endl;

  // BST large
  nodes = BSTlarge.NumNodes;
  started = std::chrono::high_resolution_clock::now();
  while (AscendLargeIn >> data) {
    BSTlarge.Delete(data, BSTlarge.Root);
    cout << "deleting " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST large"
           << "," << time << "," << nodes << endl;

  AscendLargeIn.close();
  AscendMediumIn.close();
  AscendSmallIn.close();

  //**************************************************************************
  //*************************************************************************
  //************************************************************************
  //*****************Descending****************************
  dataFile << endl;
  dataFile << endl;
  dataFile << "Insertions Descending"
           << ","
           << "time (ms)"
           << ","
           << "Number Nodes" << endl;
  // AVL small insert
  started = std::chrono::high_resolution_clock::now();
  ifstream Descendsmall("DescendingSmall.txt");
  while (Descendsmall >> data) {
    AVLsmall.Add(data);
    cout << "adding " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL small"
           << "," << time << "," << AVLsmall.NumNodes << endl;

  // AVL medium insert
  ifstream DescendMed("DescendingMedium.txt");
  started = std::chrono::high_resolution_clock::now();
  while (DescendMed >> data) {
    AVLmedium.Add(data);
    cout << "adding " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL medium"
           << "," << time << "," << AVLmedium.NumNodes << endl;

  // AVL large insert
  ifstream DescendLarge("DescendingLarge.txt");
  started = std::chrono::high_resolution_clock::now();
  while (DescendLarge >> data) {
    AVLlarge.Add(data);
    cout << "adding " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL large"
           << "," << time << "," << AVLlarge.NumNodes << endl;

  Descendsmall.clear();
  Descendsmall.seekg(0, Descendsmall.beg);
  DescendMed.clear();
  DescendMed.seekg(0, DescendMed.beg);
  DescendLarge.clear();
  DescendLarge.seekg(0, DescendLarge.beg);

  // BST small insert
  started = std::chrono::high_resolution_clock::now();

  while (Descendsmall >> data) {
    BSTsmall.Add(data);
    cout << "adding " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST small"
           << "," << time << "," << BSTsmall.NumNodes << endl;

  // BST medium insert

  started = std::chrono::high_resolution_clock::now();
  while (DescendMed >> data) {
    BSTmedium.Add(data);
    cout << "adding " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST medium"
           << "," << time << "," << BSTmedium.NumNodes << endl;

  // BST large insert

  started = std::chrono::high_resolution_clock::now();
  while (DescendLarge >> data) {
    BSTlarge.Add(data);
    cout << "adding " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST large"
           << "," << time << "," << BSTlarge.NumNodes << endl;

  // Inorder
  // traversals*************************************************************
  //
  dataFile << endl;
  dataFile << endl;
  dataFile << "Traversal Descending"
           << ","
           << "time (ms)"
           << ","
           << "Number Nodes" << endl;
  // AVL small
  started = std::chrono::high_resolution_clock::now();
  AVLsmall.printTree(AVLsmall.Root);
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL small"
           << "," << time << "," << AVLsmall.NumNodes << endl;

  // AVL med
  started = std::chrono::high_resolution_clock::now();
  AVLmedium.printTree(AVLmedium.Root);
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL medium"
           << "," << time << "," << AVLmedium.NumNodes << endl;

  // AVL large
  started = std::chrono::high_resolution_clock::now();
  AVLlarge.printTree(AVLlarge.Root);
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL large"
           << "," << time << "," << AVLlarge.NumNodes << endl;

  // BST small
  started = std::chrono::high_resolution_clock::now();
  BSTsmall.printTree(BSTsmall.Root);
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST small"
           << "," << time << "," << BSTsmall.NumNodes << endl;

  // BST medium
  started = std::chrono::high_resolution_clock::now();
  BSTmedium.printTree(BSTmedium.Root);
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST medium"
           << "," << time << "," << BSTmedium.NumNodes << endl;

  // BST large
  started = std::chrono::high_resolution_clock::now();
  BSTlarge.printTree(BSTlarge.Root);
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST large"
           << "," << time << "," << BSTlarge.NumNodes << endl;

  Descendsmall.clear();
  Descendsmall.seekg(0, Descendsmall.beg);
  DescendMed.clear();
  DescendMed.seekg(0, DescendMed.beg);
  DescendLarge.clear();
  DescendLarge.seekg(0, DescendLarge.beg);

  // DELETIONS ASCENDING********************************************************

  dataFile << endl;
  dataFile << endl;
  dataFile << "Deletions Descending"
           << ","
           << "time (ms)"
           << ","
           << "Number Nodes" << endl;

  // AVL small

  nodes = AVLsmall.NumNodes;
  started = std::chrono::high_resolution_clock::now();

  while (Descendsmall >> data) {
    AVLsmall.Delete(data, AVLsmall.Root);
    cout << "deleting " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL small"
           << "," << time << "," << nodes << endl;

  // AVL medium
  nodes = AVLmedium.NumNodes;
  started = std::chrono::high_resolution_clock::now();
  while (DescendMed >> data) {
    AVLmedium.Delete(data, AVLmedium.Root);
    cout << "deleting " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL medium"
           << "," << time << "," << nodes << endl;

  // AVL large
  nodes = AVLlarge.NumNodes;
  started = std::chrono::high_resolution_clock::now();
  while (DescendLarge >> data) {
    AVLlarge.Delete(data, AVLlarge.Root);
    cout << "deleting " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL large"
           << "," << time << "," << nodes << endl;

  Descendsmall.clear();
  Descendsmall.seekg(0, Descendsmall.beg);
  DescendMed.clear();
  DescendMed.seekg(0, DescendMed.beg);
  DescendLarge.clear();
  DescendLarge.seekg(0, DescendLarge.beg);

  // BST small

  nodes = BSTsmall.NumNodes;
  started = std::chrono::high_resolution_clock::now();

  while (Descendsmall >> data) {
    BSTsmall.Delete(data, BSTsmall.Root);
    cout << "deleting " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST small"
           << "," << time << "," << nodes << endl;

  // BST medium
  nodes = BSTmedium.NumNodes;
  started = std::chrono::high_resolution_clock::now();
  while (DescendMed >> data) {
    BSTmedium.Delete(data, BSTmedium.Root);
    cout << "deleting " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST medium"
           << "," << time << "," << nodes << endl;

  // BST large
  nodes = BSTlarge.NumNodes;
  started = std::chrono::high_resolution_clock::now();
  while (DescendLarge >> data) {
    BSTlarge.Delete(data, BSTlarge.Root);
    cout << "deleting " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST large"
           << "," << time << "," << nodes << endl;

  Descendsmall.close();
  DescendMed.close();
  DescendLarge.close();

  //***************************************************************
  //********************************************************************
  //*********************************************************************
  //**************RANDOM******************************************

  dataFile << endl;
  dataFile << endl;
  dataFile << "Insertions Random"
           << ","
           << "time (ms)"
           << ","
           << "Number Nodes" << endl;
  // AVL small insert
  started = std::chrono::high_resolution_clock::now();
  ifstream RandomSmall("RandomSmall.txt");
  while (RandomSmall >> data) {
    AVLsmall.Add(data);
    cout << "adding " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL small"
           << "," << time << "," << AVLsmall.NumNodes << endl;

  // AVL medium insert
  ifstream RandomMed("RandomMedium.txt");
  started = std::chrono::high_resolution_clock::now();
  while (RandomMed >> data) {
    AVLmedium.Add(data);
    cout << "adding " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL medium"
           << "," << time << "," << AVLmedium.NumNodes << endl;

  // AVL large insert
  ifstream RandomLarge("RandomLarge.txt");
  started = std::chrono::high_resolution_clock::now();
  while (RandomLarge >> data) {
    AVLlarge.Add(data);
    cout << "adding " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL large"
           << "," << time << "," << AVLlarge.NumNodes << endl;

  RandomSmall.clear();
  RandomSmall.seekg(0, RandomSmall.beg);
  RandomMed.clear();
  RandomMed.seekg(0, RandomMed.beg);
  RandomLarge.clear();
  RandomLarge.seekg(0, RandomLarge.beg);

  // BST small insert
  started = std::chrono::high_resolution_clock::now();

  while (RandomSmall >> data) {
    BSTsmall.Add(data);
    cout << "adding " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST small"
           << "," << time << "," << BSTsmall.NumNodes << endl;

  // BST medium insert

  started = std::chrono::high_resolution_clock::now();
  while (RandomMed >> data) {
    BSTmedium.Add(data);
    cout << "adding " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST medium"
           << "," << time << "," << BSTmedium.NumNodes << endl;

  // BST large insert

  started = std::chrono::high_resolution_clock::now();
  while (RandomLarge >> data) {
    BSTlarge.Add(data);
    cout << "adding " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST large"
           << "," << time << "," << BSTlarge.NumNodes << endl;

  // Inorder
  // traversals*************************************************************
  //
  dataFile << endl;
  dataFile << endl;
  dataFile << "Traversal Random"
           << ","
           << "time (ms)"
           << ","
           << "Number Nodes" << endl;
  // AVL small
  started = std::chrono::high_resolution_clock::now();
  AVLsmall.printTree(AVLsmall.Root);
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL small"
           << "," << time << "," << AVLsmall.NumNodes << endl;

  // AVL med
  started = std::chrono::high_resolution_clock::now();
  AVLmedium.printTree(AVLmedium.Root);
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL medium"
           << "," << time << "," << AVLmedium.NumNodes << endl;

  // AVL large
  started = std::chrono::high_resolution_clock::now();
  AVLlarge.printTree(AVLlarge.Root);
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL large"
           << "," << time << "," << AVLlarge.NumNodes << endl;

  // BST small
  started = std::chrono::high_resolution_clock::now();
  BSTsmall.printTree(BSTsmall.Root);
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST small"
           << "," << time << "," << BSTsmall.NumNodes << endl;

  // BST medium
  started = std::chrono::high_resolution_clock::now();
  BSTmedium.printTree(BSTmedium.Root);
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST medium"
           << "," << time << "," << BSTmedium.NumNodes << endl;

  // BST large
  started = std::chrono::high_resolution_clock::now();
  BSTlarge.printTree(BSTlarge.Root);
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST large"
           << "," << time << "," << BSTlarge.NumNodes << endl;

  RandomSmall.clear();
  RandomSmall.seekg(0, RandomSmall.beg);
  RandomSmall.clear();
  RandomMed.seekg(0, RandomMed.beg);
  RandomLarge.clear();
  RandomLarge.seekg(0, RandomLarge.beg);

  // DELETIONS random********************************************************

  dataFile << endl;
  dataFile << endl;
  dataFile << "Deletions Random"
           << ","
           << "time (ms)"
           << ","
           << "Number Nodes" << endl;

  // AVL small

  nodes = AVLsmall.NumNodes;
  started = std::chrono::high_resolution_clock::now();

  while (RandomSmall >> data) {
    AVLsmall.Delete(data, AVLsmall.Root);
    cout << "deleting " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL small"
           << "," << time << "," << nodes << endl;

  // AVL medium
  nodes = AVLmedium.NumNodes;
  started = std::chrono::high_resolution_clock::now();
  while (RandomMed >> data) {
    AVLmedium.Delete(data, AVLmedium.Root);
    cout << "deleting " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL medium"
           << "," << time << "," << nodes << endl;

  // AVL large
  nodes = AVLlarge.NumNodes;
  started = std::chrono::high_resolution_clock::now();
  while (RandomLarge >> data) {
    AVLlarge.Delete(data, AVLlarge.Root);
    cout << "deleting " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "AVL large"
           << "," << time << "," << nodes << endl;

  RandomSmall.clear();
  RandomSmall.seekg(0, RandomSmall.beg);
  RandomMed.clear();
  RandomMed.seekg(0, RandomMed.beg);
  RandomLarge.clear();
  RandomLarge.seekg(0, RandomLarge.beg);

  // BST small

  nodes = BSTsmall.NumNodes;
  started = std::chrono::high_resolution_clock::now();

  while (RandomSmall >> data) {
    BSTsmall.Delete(data, BSTsmall.Root);
    cout << "deleting " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST small"
           << "," << time << "," << nodes << endl;

  // BST medium
  nodes = BSTmedium.NumNodes;
  started = std::chrono::high_resolution_clock::now();
  while (RandomMed >> data) {
    BSTmedium.Delete(data, BSTmedium.Root);
    cout << "deleting " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST medium"
           << "," << time << "," << nodes << endl;

  // BST large
  nodes = BSTlarge.NumNodes;
  started = std::chrono::high_resolution_clock::now();
  while (RandomLarge >> data) {
    BSTlarge.Delete(data, BSTlarge.Root);
    cout << "deleting " << data << endl;
  }
  done = chrono::high_resolution_clock::now();
  time = static_cast<int>(
      chrono::duration_cast<chrono::milliseconds>(done - started).count());
  dataFile << "BST large"
           << "," << time << "," << nodes << endl;

  RandomSmall.close();
  RandomMed.close();
  RandomLarge.close();

  dataFile.close();
}

void GenerateFiles() {
  // gen small files 300 values
  ofstream aSmall;
  ofstream dSmall;
  ofstream rSmall;
  aSmall.open("AscendingSmall.txt");
  dSmall.open("DescendingSmall.txt");
  rSmall.open("RandomSmall.txt");
  srand(time(0));
  for (int i = 1; i <= 300; i++) {
    aSmall << i * 20 << endl;
    dSmall << (300 * 20) - (-1 + i) * 20 << endl;
    rSmall << ((rand() % (999 - 0 + 1) * i) + 0) << endl;
  }
  aSmall.close();
  dSmall.close();
  rSmall.close();

  // gen medium files 3,000 values
  ofstream aMedium;
  ofstream dMedium;
  ofstream rMedium;
  aMedium.open("AscendingMedium.txt");
  dMedium.open("DescendingMedium.txt");
  rMedium.open("RandomMedium.txt");
  srand(time(0));
  for (int i = 1; i <= 3000; i++) {
    aMedium << i * 20 << endl;
    dMedium << (3000 * 20) - (-1 + i) * 20 << endl;
    rMedium << ((rand() % (999 - 0 + 1) * i) + 0) << endl;
  }
  aMedium.close();
  dMedium.close();
  rMedium.close();

  // gen large files 30,000 values
  ofstream aLarge;
  ofstream dLarge;
  ofstream rLarge;
  aLarge.open("AscendingLarge.txt");
  dLarge.open("DescendingLarge.txt");
  rLarge.open("RandomLarge.txt");
  srand(time(0));
  for (int i = 1; i <= 30000; i++) {
    aLarge << i * 20 << endl;
    dLarge << (30000 * 20) - (-1 + i) * 20 << endl;
    rLarge << ((rand() % (999 - 0 + 1) * i) + 0) << endl;
  }
  aLarge.close();
  dLarge.close();
  rLarge.close();
  cout << "files made" << endl;
}
