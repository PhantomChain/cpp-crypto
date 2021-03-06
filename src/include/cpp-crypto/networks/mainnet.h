/**
 * This file is part of Phantom Cpp Crypto.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef MAINNET_H
#define MAINNET_H

#include "networks/abstractnetwork.h"

namespace Phantom {
namespace Crypto {
namespace Networks {
/**
 * @brief This is the mainnet network class.
 *
 * @author Simon Downey <simon@ark.io>
 **/
const AbstractNetwork Mainnet = {
    { 
        0x17,   // BASE58_ADDRESS_P2PKH
        0x00,   // BASE58_ADDRESS_P2SH
        0xaa    // BASE58_WIF
    },
    { 
        46090600,   // BIP32_PREFIX_XPUB
        46089520    // BIP32_PREFIX_XPRV
    },
    "2017-03-21T13:00:00Z" // Epoch
};
/**/
};
};
};

#endif
