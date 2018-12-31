cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

find_program(HELP2MAN NAMES help2man)

add_man(git-credential-kwallet ${CMAKE_CURRENT_BINARY_DIR}/git-credential-kwallet.1)
add_custom_target(man ALL
  DEPENDS git-credential-kwallet.man
)
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/git-credential-kwallet.1
  DESTINATION ${CMAKE_INSTALL_MANDIR}/man1
)
