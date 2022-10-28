#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>

#include "openssl/sha.h"
#include "authlib.h"

#define EMPTY_STR "";

/*
Method to display login prompts
Passes username and password by reference to modify
*/
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
    std::string inPswd;

    /**
    Hash function. The following section of code from: https://stackoverflow.com/a/10632725
    Passes password by reference to modify it
    */
    void sha256 (std:: string &pswd) {
      unsigned char hash[SHA256_DIGEST_LENGTH]; //Creates array of unsigned char with the length of a SHA256 hash
      SHA256_CTX sha256; // Creates variable of SHA256_CTX struct.
      SHA256_Init(&sha256); //Calls function that takes Reference to SHA_256_CTX and returns an integer
      SHA256_Update(&sha256, pswd.c_str(), pswd.size());
      SHA256_Final(hash, &sha256);
      
      std::stringstream ss;
      
      for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
      }
      
      pswd = ss.str();
    }

    // Function to compare username and password entered by the user, to the contents of passwords.txt 
    bool compare(std::string pswd, std::string user) 
    {
      std::string combinedLoginPair = user + ":" + pswd;
      for (std::string item: this->loginPair)
      {
        if (item == combinedLoginPair) return true;
      }
      return false;
    }

  public:
    // Constructor
    Hash(std::string username, std::string &pswd, bool &auth) {
      
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
      this->sha256(this->inPswd);
      auth = this->compare(this->inPswd, username);

      // Combine inputs and hash and compare.

    }

    // Deconstructor
    ~Hash() {
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