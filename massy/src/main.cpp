#include <iostream>

#include "massy/include/communication/Server.hpp"

namespace mc = massy::communication;

int main(int argc, char** argv)
{
   try {
      if (argc != 3) {
         std::cerr << "Usage: client <host> <port>\n";
         return 1;
      }
      mc::Server server(argv[1], argv[2]);
      server.startAndRun();
   }
   catch (...) {
      std::cerr << "handling" << std::endl;
   }
}
