#include <iostream>
#include <vector>
#include <fstream>

#include "openssl/sha.h"
#include "authlib.h"

inline void displayLoginScreen(std::string username, std::string pswd, bool &auth) {
  (void)auth;

  bool runLoop = true;

  while (runLoop != false) {
    std::cout << "Username: ";
    std::cin >> username;

    std::cout << "Password: ";
    std::cin >> pswd;

    if (username != "" && pswd != "") {
      break;
      return;
    }
  }

  // Hash function call HERE!

}

class Hash {
  private:
    
};

int main() {
  bool auth;
  std::string username = "";
  std::string pswd = "";
  std::vector<std::string, std::string> loginPair;

  loginPair.insert("Hello", "Hi");

  displayLoginScreen(username, pswd, auth);

  if (auth) authenticated("user");
  else rejected("user");

  return 0;
}