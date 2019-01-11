/**
 * This file is part of Phantom Cpp Crypto.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "configuration/network.h"

/**
 * @brief Get the network used for crypto operations.
 *
 * @return AbstractNetwork
 **/
Phantom::Crypto::Networks::AbstractNetwork Phantom::Crypto::Configuration::Network::get()
{
    return (this->network_.getBase58Prefix(BASE58_ADDRESS_P2PKH) == 0x00)
        ? (Devnet)
        : (this->network_);
}
/**/

/**
 * @brief Set the network used for crypto operations.
 *
 * @param AbstractNetwork network
 **/
void Phantom::Crypto::Configuration::Network::set(Phantom::Crypto::Networks::AbstractNetwork network)
{
    this->network_ = network;
};
/**/
