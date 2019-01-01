#include <QtCore/QCoreApplication>

#include <QtCore/QCommandLineOption>
#include <QtCore/QCommandLineParser>
#include <QtCore/QTextStream>

#include <KWallet/KWallet>

#include "version.h"

#include "Credential.hpp"
#include "debug.hpp"

QString tr(const char* str) {
  return QCoreApplication::translate("git-credential-kwallet", str);
}

int main(int argc, char* argv[]) {
  QCoreApplication app(argc, argv);
  app.setApplicationVersion(GIT_CREDENTIAL_KWALLET_VERSION_STRING);

  QCommandLineParser parser;
  parser.setApplicationDescription("git-credential helper for KWallet");

  auto help = parser.addHelpOption();
  auto version = parser.addVersionOption();

  QCommandLineOption wallet{"wallet", tr("Name of the KDE Wallet to use"), tr("name")};
  wallet.setDefaultValue("kdewallet");
  parser.addOption(wallet);

  QCommandLineOption folder{"folder", tr("Name of the folder in the wallet to use"), tr("name")};
  folder.setDefaultValue("git");
  parser.addOption(folder);

  QCommandLineOption debug{"debug", tr("Output debug messages to stderr")};
  parser.addOption(debug);

  parser.addPositionalArgument(
      "operation", tr("The operation as defined by git-credentials (either get, store or erase)"), "<get|store|erase>");

  parser.process(app);

  QLoggingCategory::setFilterRules(QStringLiteral("git-credential-kwallet.debug=") +
                                   (parser.isSet(debug) ? "true" : "false"));

  auto args = parser.positionalArguments();
  if (args.size() != 1) {
    debugStream() << "No operation specified";
    parser.showHelp();
  }
  auto operation = args.first();

  auto credential = read();
  WalletSettings settings{parser.value(wallet), parser.value(folder), parser.isSet(debug)};
  debugStream() << "operation:" << operation << "wallet:" << settings.wallet << "folder:" << settings.folder
                << "protocol:" << credential.protocol << "host:" << credential.host
                << "username:" << credential.username;
  if (operation == QStringLiteral("get")) {
    write(get(std::move(credential), settings));
  } else if (operation == QStringLiteral("store")) {
    store(std::move(credential), settings);
  } else if (operation == QStringLiteral("erase")) {
    erase(std::move(credential), settings);
  }

  return 0;
}
