#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>

#include "openssl/sha.h"
#include "authlib.h"

#include <termios.h>
#include <unistd.h>

int getch() {
    int ch;
    struct termios t_old, t_new;

    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    return ch;
}

int main()
{
  std::string password;
  unsigned char ch=0;

  std::cout << "Password? ";
  while((ch=getch())!=10)
    {
      password+=ch;
      std::cout <<'*';
    }
  std::cout << password;
  std::cout << std::endl;
  return 0;
}