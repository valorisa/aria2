<!-- markdownlint-disable MD029 -->

# Guide to Building aria2 from Source on macOS

This guide details the procedure for compiling aria2 from source on macOS (Apple Silicon and Intel), focusing on resolving the specific issue related to GNU make.

## Required Environment

- macOS (tested on macOS 14.4.0 Darwin Kernel Version 24.4.0)
- Architecture: Apple Silicon (M1/M2/M3) or Intel
- Xcode Command Line Tools
- Homebrew

## Installing Dependencies

```bash
brew update
brew install automake autoconf libtool pkg-config openssl libxml2 sqlite c-ares libssh2 zlib gettext
```

## Common Error and Solution

### Problem Encountered

When compiling with `make`, the following error appears:

```bash
Making all in po
make[2]: *** No rule to make target '/config.status', needed by 'Makefile'.  Stop.
```

### Root Cause

This error occurs due to using the BSD version of make (default on macOS) instead of GNU make. The gettext translation system requires specific GNU make features.

### Detailed Solution

1) Initial Cleanup:

```bash
rm -f config.status po/Makefile po/Makefile.in aclocal.m4 configure
```

2) Regenerating Configuration:

```bash
gettextize --force --no-changelog
aclocal -I m4
autoconf
```

3) Project Configuration:

```bash
./configure --with-openssl \
           --with-libxml2 \
           --with-sqlite3 \
           --with-libcares \
           --with-libssh2 \
           --with-zlib \
           LIBS="-L/opt/homebrew/opt/gettext/lib" \
           CPPFLAGS="-I/opt/homebrew/opt/gettext/include" \
           PKG_CONFIG_PATH="/opt/homebrew/opt/openssl@3/lib/pkgconfig:\
/opt/homebrew/opt/libxml2/lib/pkgconfig:\
/opt/homebrew/opt/sqlite/lib/pkgconfig:\
/opt/homebrew/opt/c-ares/lib/pkgconfig:\
/opt/homebrew/opt/libssh2/lib/pkgconfig:\
/opt/homebrew/opt/zlib/lib/pkgconfig"
```

4) Compilation with GNU make:

```bash
gmake
```

5) Installation:

```bash
sudo gmake install
```

## Important Notes

### Architecture-Specific Paths

- For Apple Silicon (ARM64): use `/opt/homebrew/...`
- For Intel (x86_64): use `/usr/local/...`

### Installation Verification

After installation, verify with:

```bash
aria2c --version
```

### Enabled Features

The compilation includes support for:

- BitTorrent
- HTTPS (via AppleTLS)
- Metalink
- XML-RPC
- WebSocket
- SFTP Support (via libssh2)

## Troubleshooting

If you encounter errors:

1) Make sure to use `gmake` instead of `make`
2) Verify that all dependencies are properly installed
3) In case of configuration errors, start over from the cleanup step
4) For Intel Mac users, adjust paths by replacing `/opt/homebrew/` with `/usr/local/`

## References

- [Official aria2 Documentation](https://aria2.github.io/)
- [GNU make Guide](https://www.gnu.org/software/make/manual/make.html)
- [Homebrew Documentation](https://docs.brew.sh/)
