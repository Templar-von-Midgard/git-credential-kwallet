#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <QtCore/QLoggingCategory>
#include <QtCore/QtDebug>

Q_DECLARE_LOGGING_CATEGORY(category)

#define debugStream() qCDebug(category)

#endif
