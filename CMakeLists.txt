cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

project(git-credential-kwallet VERSION 0.1.0 LANGUAGES CXX)

include(FeatureSummary)
find_package(KF5Wallet "5.46.0" REQUIRED)

add_subdirectory(src)

feature_summary(
  WHAT ALL
  FATAL_ON_MISSING_REQUIRED_PACKAGES
)
include(CPack)
