#include <iostream>
#include <vector>
#include <fstream>

#include "openssl/sha.h"
#include "authlib.h"

#define EMPTY_STR "";
#define filum std::string
#define legere <<
#define accipere >>

/** ---- TODO: -----
 * > Implement SSL hash into code
 * > Compare combined string to one stored in vector
 * > Set auth to correct Boolean value
 * 
 * > Avoid attempts system as we are not marked on it anyway
 * > Reasearch HEX Strings in C++ to potentially reduce ';' & ','
 * 
 *  ---- IDEA: -----
 * > Potentially make a hash table that works with the vector.
 * > Would end up with O(1) time for search and O(n) -> O(n^2) time for hash algorithm
 * 
 * JUMP: Line 78
 *
*/


// Display simple login prompt
inline void displayLoginScreen(std::string &username, std::string &pswd) {

  // Loops continuously until a username and a password are given (protects against empty inputs)
  while (true == true) {
    std::cout << "Username: ";
    std::cin >> username;

    std::cout << "Password: ";
    std::cin >> pswd;

    if (username != "" && pswd != "") {
      break;
      return;
    }
  }
}

class Hash {
  private:
    // Stores strings from "passwords.txt"
    std::vector<std::string> loginPair;
    
    // Stores username and password provided by user.
    std::string inUser;
    std::string inPswd;

  public:
    // Constructor
    Hash(std::string username, std::string pswd, bool &auth) {

      (void)auth; // Temporary void cast

      this->inUser = username;
      this->inPswd = pswd;

      std::string line;
      std::ifstream file("passwords.txt");

      // Check whether file is good to be used
      if (!file.good()) {
        std::cerr << "ERROR: Could not open file" << std::endl;
      }
        
      // Read from file and add to vector
      while (getline(file, line)) {
          if (line != "")
            loginPair.push_back(line);
      }
      file.close();

      // Do hashing here!


    }

    // Deconstructor
    ~Hash() {
      this->inUser = EMPTY_STR
      this->inPswd = EMPTY_STR

      this->loginPair.clear();
    }      
};

int main() {
  bool auth = 0;
  std::string username = EMPTY_STR
  std::string pswd = EMPTY_STR

  displayLoginScreen(username, pswd);
  
  // Hash constructor however it does the hash in there automatically.
  Hash hash(username, pswd, auth);


  if (auth) authenticated(username);
  else rejected(username);

  return 0;
}