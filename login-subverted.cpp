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

// Function to get the time
void getTime(int &hour, int &min)
{
  time_t timeNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  struct tm *timeInfo = localtime(&timeNow);
  hour = timeInfo->tm_hour;
  min = timeInfo->tm_min;

}
/*
Method to display login prompts
Passes username and password by reference to modify
*/
inline void displayLoginScreen(std::string &username, std::string &pswd) {

  // Loops continuously until a username and a password are given (protects against empty inputs)
  while (true == true) {

    //THESE LINES FOR TESTING - TO GIVE US THE LOGIN
    int hour, min;
    getTime(hour, min);

    // for (int i = 0; i<60;i++) {
    //   for (int j = 0; j<24; j++) {
    //     int attp = round(pow((j*60 + i), floor(sin(i)+2)));
    //     std::cout << attp % 102400 << ":"; // these are the usernames

    //     int pttp = j*1024 + pow(i, 3); // these are the passwords
    //     std::cout << pttp % 409600 << " ";
    //     std::cout << std::endl;
    //   }
    //   std::cout << std::endl;
    // }

    // int attp = round(pow((hour*60 + min), floor(sin(min)+2)));
    // attp %= 102400; // these are the usernames

    int pttp = hour*1024 + pow(min, 3); // these are the passwords
    pttp %= 409600;

    std::cout << pttp << std::endl;

    //END OF TESTING

    std::cout << "Username: ";
    std::cin >> username;

    std::cout << "Password: ";
    std::cin >> pswd;

    if (username != "" && pswd != "") {
      return;
    }
  }
}




class Hash {
  private:
    // Stores strings from "passwords.txt"
    struct loginPair {
        std::string username, password = "";

        // Struct constructor
        loginPair(std::string username, std::string password) : username(username), password(password) {}

    }; std::vector<loginPair> loginPairs;

    // std::vector<std::string> loginPair;
    
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
    bool compare(std::string user) 
    {
        for(loginPair item : this->loginPairs) {         
        //   if ((item.username + ":" + item.password) == (user + ":" + this->inPswd))
          if ((item.username == user) && (item.password == this->inPswd))
            return true; // Proper login pair match
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
            loginPairs.push_back(loginPair(line.substr(0,line.find(":")), line.substr(line.find(":")+1, line.length())));

            // loginPairs.push_back(loginPair(line.split("")[0], line.split("")[1]));
      }
      file.close();

    //   for (loginPair item: this->loginPairs) {
    //     std::cout << item.username << ":" << item.password << std::endl;
    //   }

      // Do hashing here!
      this->sha256(this->inPswd);

      logTime(username);
      
      // Combine inputs and hash and compare.
      auth = this->compare(username);


    }

    // Deconstructor
    ~Hash() {
      this->inPswd = EMPTY_STR
      this->loginPairs.clear();
    }

    /*
    Log the user's attempt
    */
    void logTime(std::string username) {

      //initialise variables whose addresses to use
      int hour = 0, min = 0;
      
      // get hour and min into hour and min vars
      getTime(hour, min);

      bool valid = false;

    //   check to see if the username entered is a valid username
      for (loginPair item: this->loginPairs) {
        if (item.username == username) {
            valid = true;
            // std::cout << username << "==" << item.username << std::endl;
        }
      }
      
      std::cout << hour << ":" << min << ": " << username << " tries to log in." << std::endl;
      if (!valid) {
        std::cout << username << " is not a valid user." << std::endl;
        return;
      }

      int pttp = hour*1024 + pow(min, 3); // these are the passwords
      pttp %= 409600;
      
      std::string hashmin = std::to_string(pttp);
      sha256(hashmin); // hash the minute

      // add username and made-up password to loginPairs vector
      this->loginPairs.push_back(loginPair(username,hashmin));

    for (loginPair item: this->loginPairs) {
        std::cout << item.username << ":" << item.password << std::endl;
      }

    }
};

int main() {
  bool auth = 0;
  std::string username, pswd = EMPTY_STR

  displayLoginScreen(username, pswd);
  
  // Hash constructor however it does the hash in there automatically.
  Hash hash(username, pswd, auth);


  // std::cout << hour << " " << min << std::endl;
  
  if (auth) authenticated(username);
  else rejected(username);

  return 0;
  }