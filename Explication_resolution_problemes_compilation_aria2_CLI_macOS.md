<!-- markdownlint-disable MD029 -->

# Guide de compilation d'aria2 sous macOS depuis les sources

Ce guide détaille la procédure pour compiler aria2 depuis les sources sur macOS (Apple Silicon et Intel), en mettant l'accent sur la résolution du problème spécifique lié à GNU make.

## Environnement requis

- macOS (testé sur macOS 14.4.0 Darwin Kernel Version 24.4.0)
- Architecture : Apple Silicon (M1/M2/M3) ou Intel
- Xcode Command Line Tools
- Homebrew

## Récupération du code source

D'abord, clonez le dépôt aria2 :

```bash
git clone https://github.com/aria2/aria2.git
cd aria2
```

## Installation des dépendances

```bash
brew update
brew install automake autoconf libtool pkg-config openssl libxml2 sqlite c-ares libssh2 zlib gettext
```

## Erreur courante et solution

### Problème rencontré

Lors de la compilation avec `make`, l'erreur suivante apparaît :

```bash
Making all in po
make[2]: *** No rule to make target '/config.status', needed by 'Makefile'.  Stop.
```

### Cause

Cette erreur est due à l'utilisation de la version BSD de make (fournie par défaut sur macOS) au lieu de GNU make. Le système de traduction gettext nécessite des fonctionnalités spécifiques à GNU make.

### Solution détaillée

1) Nettoyage initial :

```bash
rm -f config.status po/Makefile po/Makefile.in aclocal.m4 configure
```

2) Régénération de la configuration :

```bash
gettextize --force --no-changelog
aclocal -I m4
autoconf
```

3) Configuration du projet :

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

4) Compilation avec GNU make :

```bash
gmake
```

5) Installation :

```bash
sudo gmake install
```

## Notes importantes

### Chemins spécifiques à l'architecture

- Pour Apple Silicon (ARM64) : utiliser `/opt/homebrew/...`
- Pour Intel (x86_64) : utiliser `/usr/local/...`

### Vérification de l'installation

Après l'installation, vérifiez avec :

```bash
aria2c --version
```

### Fonctionnalités activées

La compilation inclut le support pour :

- BitTorrent
- HTTPS (via AppleTLS)
- Metalink
- XML-RPC
- WebSocket
- Support SFTP (via libssh2)

## Dépannage

Si vous rencontrez des erreurs :

1) Assurez-vous d'utiliser `gmake` et non `make`
2) Vérifiez que toutes les dépendances sont bien installées
3) En cas d'erreur de configuration, reprenez depuis l'étape de nettoyage
4) Pour les utilisateurs de Mac Intel, adaptez les chemins en remplaçant `/opt/homebrew/` par `/usr/local/`

## Références

- [Documentation officielle d'aria2](https://aria2.github.io/)
- [Guide GNU make](https://www.gnu.org/software/make/manual/make.html)
- [Documentation Homebrew](https://docs.brew.sh/)
