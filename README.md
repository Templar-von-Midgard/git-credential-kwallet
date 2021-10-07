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

`git-credential-kwallet` is a git credential helper, it is meant to be invoked by git, not manually.
If you run into an issue and you want to investigate it by running the software directly, then be sure to close the input stream. e.g.:
```bash
git-credential-kwallet --debug store <<EOF
protocol=https
host=example.com
username=bob
password=s3cre7
EOF
```
