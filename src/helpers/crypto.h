/**
 * This file is part of Phantom Cpp Crypto.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "bcl/Sha256Hash.hpp"
#include "identities/privatekey.h"
#include "identities/publickey.h"

#include <vector>
#include <cstdint>

#ifndef CRYPTO_H
#define CRYPTO_H

void cryptoSign(Sha256Hash hash, Phantom::Crypto::Identities::PrivateKey privateKey, std::vector<uint8_t>& signature);
bool cryptoVerify(Phantom::Crypto::Identities::PublicKey publicKey, Sha256Hash hash, std::vector<uint8_t>& signature);

#endif
