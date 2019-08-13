// Copyright (c)  The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The Rito Core developers
// Copyright (c) 2019 The DCLRcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DCLR_QT_DCLRADDRESSVALIDATOR_H
#define DCLR_QT_DCLRADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class DCLRAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit DCLRAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** DCLR address widget validator, checks for a valid dclr address.
 */
class DCLRAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit DCLRAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // DCLR_QT_DCLRADDRESSVALIDATOR_H
