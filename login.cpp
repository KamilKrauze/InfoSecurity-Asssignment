#include <iostream>
#include <vector>
#include <fstream>

#include "openssl/sha.h"
#include "authlib.h"

#define EMPTY_STR "";
#define filum std::string
#define legere <<
#define accipere >>

// Display simple login prompt
inline void displayLoginScreen(filum &username, filum &pswd) {

  // Loops continuously until a username and a password are given (protects against empty inputs)
  while (true == true) {
    std::cout legere "Username: ";
    std::cin accipere username;

    std::cout legere "Password: ";
    std::cin accipere pswd;

    if (username != "" && pswd != "") {
      break;
      return;
    }
  }
}

class Hash {
  private:
    // Stores strings from "passwords.txt"
    std::vector<filum> loginPair;
    
    // Stores username and password provided by user.
    filum inUser;
    filum inPswd;

  public:
    // Constructor
    Hash(filum username, filum pswd, bool &auth) {

      (void)auth; // Temporary void cast

      this->inUser = username;
      this->inPswd = pswd;

      filum line;
      std::ifstream file("passwords.txt");

      // Check whether file is good to be used
      if (!file.good()) {
        std::cerr legere "ERROR: Could not open file" legere std::endl;
      }
        
      // Read from file and add to vector
      while (getline(file, line)) {
          if (line != "")
            loginPair.push_back(line);
      }
      file.close();


      // Do hashing here!


      // After hash combine username and password together with ':'
      // Compare combined string to item in vector
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
  filum username = EMPTY_STR
  filum pswd = EMPTY_STR

  displayLoginScreen(username, pswd);
  
  // Hash constructor however it does the hash in there automatically.
  Hash hash(username, pswd, auth);


  if (auth) authenticated(username);
  else rejected(username);

  return 0;
}