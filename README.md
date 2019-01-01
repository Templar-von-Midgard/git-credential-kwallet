# git-credential-kwallet
[![Build Status](https://travis-ci.com/Templar-von-Midgard/git-credential-kwallet.svg?branch=master)](https://travis-ci.com/Templar-von-Midgard/git-credential-kwallet)

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
