cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

configure_file(version.h.in version.h @ONLY)

add_executable(git-credential-kwallet
  version.h.in
  main.cpp
  Credential.hpp
  Credential.cpp
  debug.hpp
  debug.cpp
)
target_link_libraries(git-credential-kwallet KF5::Wallet)

install(TARGETS git-credential-kwallet
  RUNTIME DESTINATION bin
)
