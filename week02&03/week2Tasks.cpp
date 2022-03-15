#include <iostream>
#include <fstream>
#include <cstring>

struct Book
{
  char genre[16];
  char name[128];
  double price;
  char author[32];

  void writeBook()
  {
    std::cout << "Genre: ";
    std::cin.getline(genre, 16);
    std::cout << "Name: ";
    std::cin.getline(name, 128);
    std::cout << "Price: ";
    std::cin >> price;
    std::cin.ignore();
    std::cout << "Author: ";
    std::cin.getline(author, 32);
  }
  void printBook()
  {
    std::cout << "Genre: " << genre << std::endl
              << "Name: " << name << std::endl
              << "Price: " << price << std::endl
              << "Author: " << author << std::endl;
  }
  void writeInFile(std::ofstream &file)
  {
    // file.open("book.txt", std::ios::app);
    // if (!file.is_open())
    // {
    //   std::cout << "The file is not open" << std::endl;
    //   return;
    // }
    // if (!file)
    // {
    //   std::cout << "The stream is not good" << std::endl;
    //   return;
    // }
    file << "{" << genre << "%"
         << name << "%"
         << price << "%"
         << author << "}" << std::endl;
    //[{<genre>%<name>%<price>%<author>},{<>},...]
    // file.close();
  }
  void readFile(std::ifstream &file)
  {
    file.open("book.txt", std::ios::in);
    if (!file.is_open())
    {
      std::cout << "The file is not open" << std::endl;
      return;
    }
    if (file.eof())
    {
      std::cout << "End of file" << std::endl;
      return;
    }
    if (!file)
    {
      std::cout << "The stream is not good" << std::endl;
      return;
    }
    char buffer[256];
    file.getline(buffer, 256);
    std::strcpy(genre, buffer);
    file.getline(buffer, 256);
    std::strcpy(name, buffer);
    file.getline(buffer, 256);
    price = std::atof(buffer);
    file.getline(buffer, 256);
    std::strcpy(author, buffer);

    file.close();
  }
}; //[{<genre>%<name>%<price>%<author>},{<>},...]

struct Bookshelf
{
  Book books[20];
  int currentBookCount;

  void printBookshelf()
  {
    for (int i = 0; i < currentBookCount; ++i)
    {
      books[i].printBook();
    }
    std::cout << std::endl;
  }

  void writeInBookShelfFile(std::ofstream &file)
  {
    file.open("bookShelf.txt", std::ios::app);
    if (!file.is_open())
    {
      return;
    }
    if (!file)
    {
      return;
    }
    file << "[" << std::endl;
    for (int i = 0; i < currentBookCount; i++)
    {
      books[i].writeInFile(file);
    }
    file << "]" << std::endl;
    file.close();
  }

  void readBookShelfFile(std::ifstream &file)
  {
    file.open("bookShelf.txt");
    if (!file.is_open())
    {
      std::cout << "The file is not open" << std::endl;
      return;
    }
    if (!file)
    {
      std::cout << "The stream is not good" << std::endl;
      return;
    }
    if (file.eof())
    {
      std::cout << "End of file" << std::endl;
      return;
    }

    char buffer[1024];
    file.getline(buffer, 1024);
    // std::cout << buffer << std::endl;

    // while (!file.eof())
    // ah tozi kod si eba mamata

    for (int i = 0; i < currentBookCount; ++i)
    {
      // file.seekg(i + 1, std::ios::cur);
      file.get(buffer, 32, '{');
      file.get(buffer, 2);

      file.get(buffer, 1024, '%');
      std::strcpy(books[i].genre, buffer);
      file.get(buffer, 2);

      file.get(buffer, 1024, '%');
      std::strcpy(books[i].name, buffer);
      file.get(buffer, 2);

      file.get(buffer, 1024, '%');
      books[i].price = std::atof(buffer);
      file.get(buffer, 2);

      file.get(buffer, 1024, '}');
      std::strcpy(books[i].author, buffer);
    }
    file.getline(buffer, 1024);
    file.close();
  }
};

int main()
{
  // Book book;
  std::ofstream outFile;
  std::ifstream inFile;
  // book.writeBook();
  // book.writeInFile(outFile);
  // // book.readFile(inFile);
  // Book book2;
  // book2.readFile(inFile);
  // book2.printBook();

  // Book books[3];
  // for (int i = 0; i < 3; ++i) {
  //   books[i].readFile(inFile);
  // }
  // for (int i = 0; i < 3; ++i) {
  //   books[i].writeInFile(outFile);
  // }
  Bookshelf bookshelf;
  bookshelf.currentBookCount = 3;
  bookshelf.readBookShelfFile(inFile);
  bookshelf.printBookshelf();

  return 0;
}