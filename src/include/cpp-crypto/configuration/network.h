/**
 * This file is part of Phantom Cpp Crypto.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef NETWORK_H
#define NETWORK_H

#include "networks/abstractnetwork.h"
#include "networks/devnet.h"
#include "networks/mainnet.h"
#include "networks/testnet.h"

#include <vector>

namespace Phantom {
namespace Crypto {
namespace Configuration {

using namespace Phantom::Crypto::Networks;

/**
 * @brief This is the network configuration class.
 *
 * @author Simon Downey <simon@ark.io>
 **/
class Network
{
    private:
        AbstractNetwork network_;
    public:
        AbstractNetwork get();
        void set(AbstractNetwork network);
};
/**/
};
};
};

#endif
