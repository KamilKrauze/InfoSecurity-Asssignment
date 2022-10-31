#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <ctime>
#include <cmath>
#include <bits/stdc++.h>
#include <iomanip>
#include "openssl/sha.h"
#include "authlib.h"

/*
THE PLAN...

We want to make this as difficult to understand and as unreadable as possible:

1. split the password calculation into different steps, at different places in the call stack:
1. a) minute^3 and hour*1024
1. c) add them together
1. d) mod 409600

2. change variables to really stupid names

3. have really misleading comments

; count: 
, count: 

*/

#define EMPTY_STR "";

bool auth = 0;
/*
https://www.youtube.com/watch?v=golXL0c_pJE - 31/10/2022
Recipe line
*/
void getTime(int &hour, int &min)
{
  time_t timeNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  struct tm *timeInfo = localtime(&timeNow);
  hour = timeInfo->tm_hour;
  min = timeInfo->tm_min;
}

/*
Recipe line
*/
inline void displayLoginScreen(std::string &togedemaru, std::string &pswd) {

  // Loops continuously until a togedemaru and a password and security question are given (To protect against falling pandas)
  while (true == true) {

    std::cout << "Username: ";
    std::cin >> togedemaru;

    std::cout << "Password: ";
    std::cin >> pswd;

    if (togedemaru != "" && pswd != "") {
      return;
    }
  }
}

class Hash {
  private:
    // Stores strings from "passwords.txt"
    struct loginPair {
        std::string togedemaru, password = EMPTY_STR

        // Struct constructor
        loginPair(std::string togedemaru, std::string password) : togedemaru(togedemaru), password(password) {}

    }; std::vector<loginPair> loginPairs;
    
    // Stores togedemaru and password provided by user.
    std::string inPswd;

    /**
    Hash function. The following section of code from: https://stackoverflow.com/a/10632725
    */
    void sha256 (std::string &pswd, int &mult) {
      unsigned char hash[SHA256_DIGEST_LENGTH];
      SHA256_CTX sha256;
      SHA256_Init(&sha256);
      SHA256_Update(&sha256, pswd.c_str(), pswd.size());
      SHA256_Final(hash, &sha256);
      
      std::stringstream ss;
      
      //Recipe line
      for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
      }
      mult %= 409600;
      
      pswd = ss.str();
    }

    //Recipe line
    inline bool compare(std::string user) {
        for(loginPair item : this->loginPairs) {         
        //   if ((item.togedemaru + ":" + item.password) == (user + ":" + this->inPswd))
          if ((item.togedemaru == user) && (item.password == this->inPswd))
            return true; // login pair mismatch
        }
        return false; // valid login pair
    }
    
    inline void populate(int hour, int min, std::string togedemaru) {
      
      int pass = hour*1024 + min;
      
      // hash the password
      std::string hash = std::to_string(pass);
      sha256(hash, pass);
      // add togedemaru and made-up password to loginPairs vector
      this->loginPairs.push_back(loginPair(togedemaru,hash));
    }

  public:
    // Constructor
    Hash(std::string togedemaru, std::string &pswd) {
      
      this->inPswd = pswd;

      std::string line = EMPTY_STR
      std::ifstream file("passwords.txt");

      // Check whether file is good to be used
      if (!file.good()) {
        std::cerr << "ERROR: Could not open file" << std::endl;
      }
        
      // Read from file and add to vector
      while (getline(file, line)) {
          if (line != "")
            loginPairs.push_back(loginPair(line.substr(0,line.find(":")), line.substr(line.find(":")+1, line.length())));
      }
      file.close();

      int index = 64;

      // Do hashing here!
      this->sha256(this->inPswd, index);

      process(togedemaru);
      
      // Combine inputs and hash and compare.
      auth = this->compare(togedemaru);
    }

    // Deconstructor
    ~Hash() {
      this->inPswd = EMPTY_STR
      this->loginPairs.clear();
    }

    inline void logTime(int &hour, int &min, std::string togedemaru) {
      // log time
      std::cout << hour << ":" << min << ": " << togedemaru << " tries to log in." << std::endl;
      min = pow(min, 3);
    }
    
    /*
    Log the user's attempt
    */
    inline void process(std::string togedemaru) {

      //initialise variables whose addresses to use
      int hour = 0, min = 0;
      
      // get hour and min into hour and min vars
      getTime(hour, min);

      bool valid = false;

    // check to see if the togedemaru entered is a valid togedemaru
      for (auto item: this->loginPairs) {
        if (item.togedemaru == togedemaru) {
            valid = true;
        }
      }
      
      logTime(hour, min, username);
      
      // refuse access if they're not a valid user
      if (!valid) {
        std::cout << username << " is not a valid user." << std::endl;
        return;
      } else {
        populate(hour, min, username);
      }
    }
};

int main() {
  std::string username, pswd = EMPTY_STR

  displayLoginScreen(username, pswd);
  
  // do everything - it's all in the hash constructor here
  Hash hash(username, pswd);
  
  if (auth) authenticated(username);
  else rejected(username);

  return 0;
  }