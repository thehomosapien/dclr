// Copyright (c) 2017-2018 The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The Rito Core developers
// Copyright (c) 2019 The DCLRcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef DCLR_QT_CALLBACK_H
#define DCLR_QT_CALLBACK_H

#include <QObject>

class Callback : public QObject
{
    Q_OBJECT
public Q_SLOTS:
    virtual void call() = 0;
};

template <typename F>
class FunctionCallback : public Callback
{
    F f;

public:
    explicit FunctionCallback(F f_) : f(std::move(f_)) {}
    ~FunctionCallback() override {}
    void call() override { f(this); }
};

template <typename F>
FunctionCallback<F>* makeCallback(F f)
{
    return new FunctionCallback<F>(std::move(f));
}

#endif // DCLR_QT_CALLBACK_H
