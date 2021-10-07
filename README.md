# git-credential-kwallet
[![Build](https://github.com/Templar-von-Midgard/git-credential-kwallet/actions/workflows/build.yml/badge.svg)](https://github.com/Templar-von-Midgard/git-credential-kwallet/actions/workflows/build.yml)

Git credential helper for KWallet

## Dependencies
* KWallet for obvious reasons
* help2man as an optional dependency for generating man pages

## Install
```bash
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
sudo cmake --build . --target install
```

## Usage
Configure as:
```
[credential]
    helper = kwallet
```
See also [gitcredentials](https://git-scm.com/docs/gitcredentials).
