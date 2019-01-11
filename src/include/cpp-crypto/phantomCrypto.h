/**
 * This file is part of Phantom Cpp Crypto.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef PHANTOMCRYPTO_H
#define PHANTOMCRYPTO_H

#define HAS_CRYPTO

#if (defined ARDUINO || defined ESP8266 || defined ESP32)
    #define USE_IOT
#endif

#include "enums/types.h"
#include "enums/fees.h"
#include "configuration/fee.h"
#include "configuration/network.h"

#include "identities/privatekey.h"
#include "identities/wif.h"
#include "identities/publickey.h"
#include "identities/address.h"
#include "identities/mnemonic.h"

#include "networks/abstractnetwork.h"
#include "networks/devnet.h"
#include "networks/mainnet.h"
#include "networks/testnet.h"

#include "transactions/builder.h"
#include "transactions/deserializer.h"
#include "transactions/serializer.h"
#include "transactions/transaction.h"

#include "utils/message.h"
#include "utils/slot.h"

using namespace Phantom::Crypto::Configuration;
using namespace Phantom::Crypto::Enums;
using namespace Phantom::Crypto::Identities;
using namespace Phantom::Crypto::Networks;
using namespace Phantom::Crypto::Transactions;

#endif
