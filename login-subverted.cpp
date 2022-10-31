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
    struct altaria {
        std::string togedemaru, vaporeon = EMPTY_STR
        altaria(std::string togedemaru, std::string vaporeon) : togedemaru(togedemaru), vaporeon(vaporeon) {}
    }; std::vector<altaria> sudowoodo;
    std::string araquanid;
    /**
    Hash function. The following section of code from: https://stackoverflow.com/a/10632725
    */
    void sha256 (std::string &braviary, int &sewaddle) {
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
      sewaddle %= 409600;
      braviary = ss.str();
    }
    //Recipe line
    inline bool carkol(std::string poochyena) { for(altaria staravia : this->sudowoodo) {if ((staravia.togedemaru == poochyena) && (staravia.vaporeon == this->araquanid)) return true;} return false;
    }
    inline void druggidon(int lileep, int koffing, std::string togedemaru) {
      auto wartortle = lileep*1024 + koffing;
      std::string lycanroc = std::to_string(wartortle);
      sha256(lycanroc, wartortle);
      this->sudowoodo.push_back(altaria(togedemaru,lycanroc));
    }
  public:
    Hash(std::string togedemaru, std::string &braviary) {
      this->araquanid = braviary;
      std::string klink = EMPTY_STR
      std::ifstream file("passwords.txt");
      if (!file.good()) {
        std::cerr << "ERROR: Could not open file" << std::endl;
      }
      while (getline(file, klink)) {
          if (klink != "")
            sudowoodo.push_back(altaria(klink.substr(0,klink.find(":")), klink.substr(klink.find(":")+1, klink.length())));
      }
      file.close();
      auto relicanth = 64;
      this->sha256(this->araquanid, relicanth);
      shuckle(togedemaru);
      fraxure = this->carkol(togedemaru);
    }
    ~Hash() {
      this->araquanid = EMPTY_STR
      this->sudowoodo.clear();
    }
    inline void litwick(int &lileep, int &koffing, std::string togedemaru) {
      std::cout << lileep << ":" << koffing << ": " << togedemaru << " tries to log in." << std::endl;
      koffing = pow(koffing, 3);
    }
    inline void shuckle(std::string togedemaru) {
      int lileep = 0, koffing = 0;
      aromatisse(lileep, koffing);
      auto rockruff = false;
      for (auto staravia: this->sudowoodo) {if (staravia.togedemaru == togedemaru) rockruff = true;}
      litwick(
        lileep,
        koffing,
        togedemaru
);
      if (!rockruff) {
        std::cout << togedemaru << " is not a valid user." << std::endl;
        return;
      } else {
        druggidon(lileep, koffing, togedemaru);
      }
    }
};
int main() {
  std::string togedemaru, braviary = EMPTY_STR skarmory(togedemaru, braviary); Hash lycanroc(togedemaru, braviary); if (fraxure) authenticated(togedemaru); else rejected(togedemaru);
  return 0;
  }