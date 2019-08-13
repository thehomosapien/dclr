// Copyright (c)  The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The Rito Core developers
// Copyright (c) 2019 The DCLRcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DCLR_DCLRCONSENSUS_H
#define DCLR_DCLRCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_DCLR_INTERNAL) && defined(HAVE_CONFIG_H)
#include "config/dclr-config.h"
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBDCLRCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define DCLRCONSENSUS_API_VER 1

typedef enum dclrconsensus_error_t
{
    dclrconsensus_ERR_OK = 0,
    dclrconsensus_ERR_TX_INDEX,
    dclrconsensus_ERR_TX_SIZE_MISMATCH,
    dclrconsensus_ERR_TX_DESERIALIZE,
    dclrconsensus_ERR_AMOUNT_REQUIRED,
    dclrconsensus_ERR_INVALID_FLAGS,
} dclrconsensus_error;

/** Script verification flags */
enum
{
    dclrconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    dclrconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    dclrconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    dclrconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    dclrconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    dclrconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    dclrconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    dclrconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = dclrconsensus_SCRIPT_FLAGS_VERIFY_P2SH | dclrconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               dclrconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | dclrconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               dclrconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | dclrconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int dclrconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, dclrconsensus_error* err);

EXPORT_SYMBOL int dclrconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, dclrconsensus_error* err);

EXPORT_SYMBOL unsigned int dclrconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // DCLR_DCLRCONSENSUS_H
