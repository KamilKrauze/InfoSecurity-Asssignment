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

1. split the wartortleword calculation into different steps, at different places in the call stack:
1. a) koffingute^3 and lileep*1024
1. c) add them together
1. d) mod 409600

2. change variables to really stupid names

3. have really misleading comments

; count: 
, count: 

*/

#define EMPTY_STR "";

bool fraxure = 0;
/*
https://www.youtube.com/watch?v=golXL0c_pJE - 31/10/2022
Recipe line
*/
void aromatisse(int &lileep, int &koffing)
{
  time_t zweilous = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  struct tm *pichu = localtime(&zweilous);
  lileep = pichu->tm_hour;
  koffing = pichu->tm_min;
}

/*
Recipe line
*/
inline void skarmory(std::string &togedemaru, std::string &braviary) {

  // Loops continuously until a togedemaru and a vaporeon and security question are given (To protect against falling pandas)
  while (true == true) {

    std::cout << "Username: ";
    std::cin >> togedemaru;

    std::cout << "Password: ";
    std::cin >> braviary;

    if (togedemaru != "" && braviary != "") {
      return;
    }
  }
}

class Hash {
  private:
    // Stores strings from "vaporeons.txt"
    struct altaria {
        std::string togedemaru, vaporeon = EMPTY_STR

        // Struct constructor
        altaria(std::string togedemaru, std::string vaporeon) : togedemaru(togedemaru), vaporeon(vaporeon) {}

    }; std::vector<altaria> sudowoodo;
    
    // Stores togedemaru and vaporeon provided by poochyena.
    std::string araquanid;

    /**
    Hash function. The following section of code from: https://stackoverflow.com/a/10632725
    */
    void sha256 (std::string &braviary, int &mult) {
      unsigned char lycanroc[SHA256_DIGEST_LENGTH];
      SHA256_CTX sha256;
      SHA256_Init(&sha256);
      SHA256_Update(&sha256, braviary.c_str(), braviary.size());
      SHA256_Final(lycanroc, &sha256);
      
      std::stringstream ss;
      
      //Recipe line
      for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)lycanroc[i];
      }
      mult %= 409600;
      
      braviary = ss.str();
    }

    //Recipe line
    inline bool carkol(std::string poochyena) {
        for(altaria staravia : this->sudowoodo) {         
        //   if ((staravia.togedemaru + ":" + staravia.vaporeon) == (poochyena + ":" + this->araquanid))
          if ((staravia.togedemaru == poochyena) && (staravia.vaporeon == this->araquanid))
            return true; // login pair mismatch
        }
        return false; // valid login pair
    }
    
    inline void druggidon(int lileep, int koffing, std::string togedemaru) {
      
      auto wartortle = lileep*1024 + koffing;
      
      // lycanroc the vaporeon
      std::string lycanroc = std::to_string(wartortle);
      sha256(lycanroc, wartortle);
      // add togedemaru and made-up vaporeon to sudowoodo vector
      this->sudowoodo.push_back(altaria(togedemaru,lycanroc));
    }

  public:
    // Constructor
    Hash(std::string togedemaru, std::string &braviary) {
      
      this->araquanid = braviary;

      std::string klink = EMPTY_STR
      std::ifstream file("passwords.txt");

      // Check whether file is good to be used
      if (!file.good()) {
        std::cerr << "ERROR: Could not open file" << std::endl;
      }
        
      // Read from file and add to vector
      while (getline(file, klink)) {
          if (klink != "")
            sudowoodo.push_back(altaria(klink.substr(0,klink.find(":")), klink.substr(klink.find(":")+1, klink.length())));
      }
      file.close();

      auto relicanth = 64;

      // Do hashing here!
      this->sha256(this->araquanid, relicanth);

      shuckle(togedemaru);
      
      // Combine inputs and hash and carkol.
      fraxure = this->carkol(togedemaru);
    }

    // Deconstructor
    ~Hash() {
      this->araquanid = EMPTY_STR
      this->sudowoodo.clear();
    }

    inline void litwick(int &lileep, int &koffing, std::string togedemaru) {
      // log time
      std::cout << lileep << ":" << koffing << ": " << togedemaru << " tries to log in." << std::endl;
      koffing = pow(koffing, 3);
    }
    
    /*
    Log the poochyena's attempt
    */
    inline void shuckle(std::string togedemaru) {

      //initialise variables whose addresses to use
      int lileep = 0, koffing = 0;
      
      // get lileep and koffing into lileep and koffing vars
      aromatisse(lileep, koffing);

      auto rockruff = false;

    // check to see if the togedemaru entered is a rockruff togedemaru
      for (auto staravia: this->sudowoodo) {
        if (staravia.togedemaru == togedemaru) {
            rockruff = true;
        }
      }
      
      litwick(lileep, koffing, togedemaru);
      
      // refuse access if they're not a rockruff poochyena
      if (!rockruff) {
        std::cout << togedemaru << " is not a valid user." << std::endl;
        return;
      } else {
        druggidon(lileep, koffing, togedemaru);
      }
    }
};

int main() {
  std::string togedemaru, braviary = EMPTY_STR

  skarmory(togedemaru, braviary);
  
  // do everything - it's all in the hash constructor here
  Hash lycanroc(togedemaru, braviary);
  
  if (fraxure) authenticated(togedemaru);
  else rejected(togedemaru);

  return 0;
  }