/**
 * This file is part of Phantom Cpp Crypto.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "identities/privatekey.h"

/**
 * 
 **/
Phantom::Crypto::Identities::PrivateKey::PrivateKey(const char *const newPrivateKeyStr)
{
    memmove(this->bytes_, &HexToBytes(newPrivateKeyStr).data()[0], PRIVATEKEY_SIZE);    
}
/**/

/**
 * 
 **/
Phantom::Crypto::Identities::PrivateKey::PrivateKey(const uint8_t *newPrivateKeyBytes)
{
    memmove(this->bytes_, newPrivateKeyBytes, PRIVATEKEY_SIZE);
}
/**/

/**
 * 
 **/
const uint8_t *Phantom::Crypto::Identities::PrivateKey::toBytes() { return this->bytes_; };
/**/

/**
 * 
 **/
std::string Phantom::Crypto::Identities::PrivateKey::toString() const
{
    return BytesToHex(this->bytes_, this->bytes_ + PRIVATEKEY_SIZE);
}
/**/

/**
 * @brief Derive the private key for the given passphrase.
 *
 * @param const char* const passphrase
 *
 * @return std::string
 **/
Phantom::Crypto::Identities::PrivateKey Phantom::Crypto::Identities::PrivateKey::fromPassphrase(const char* const passphrase)
{    
    std::vector<uint8_t> privateKey(PRIVATEKEY_SIZE);
    auto hash = Sha256::getHash(reinterpret_cast<const unsigned char*>(passphrase), strlen(passphrase));
    memcpy(&privateKey[0], hash.value, privateKey.size());
    return { BytesToHex(&privateKey[0], &privateKey[0] + PRIVATEKEY_SIZE).c_str() };
}
/**/

/**
 * @brief Create a private key instance from a hex string.
 *
 * @param const char *const privateKey
 *
 * @return PrivateKey
 **/
Phantom::Crypto::Identities::PrivateKey Phantom::Crypto::Identities::PrivateKey::fromHex(const char *const privateKey) { return { privateKey }; }
/**/

/**
 * @brief Derive the private key for the given WIF.
 *
 * @param const char* wifStr
 * @param uint8_t wifByte
 *
 * @return PrivateKey
 **/
Phantom::Crypto::Identities::PrivateKey Phantom::Crypto::Identities::PrivateKey::fromWIFString(const char* wifStr, uint8_t wifByte)
{
    Uint256 bigNum;
    bool compressed = true;
    auto ret = Base58Check::privateKeyFromBase58Check(wifStr, bigNum, &wifByte, &compressed);
    assert(ret);
    std::vector<uint8_t> privateKey(PRIVATEKEY_SIZE);
    bigNum.getBigEndianBytes(&privateKey[0]);
    return { BytesToHex(&privateKey[0], &privateKey[0] + PRIVATEKEY_SIZE).c_str() };
}
/**/

/**
 * @brief Validate the given private key.
 *
 * @param PrivateKey privateKey
 *
 * @return bool
 **/
bool Phantom::Crypto::Identities::PrivateKey::validate(PrivateKey privateKey) { return PrivateKey::validate(privateKey.toString().c_str()); };
/**/

/**
 * @brief Validate the given private key.
 *
 * @param const char *const privateKey
 *
 * @return bool
 **/
bool Phantom::Crypto::Identities::PrivateKey::validate(const char *privateKeyStr)
{
    return ((strlen(privateKeyStr)/2) == PRIVATEKEY_SIZE); // check length
}
/**/

/**
 * @brief Validate the given private key.
 *
 * @param const uint8_t *privateKeyBytes
 *
 * @return bool
 **/
bool Phantom::Crypto::Identities::PrivateKey::validate(const uint8_t *privateKeyBytes)
{
    return validate(PrivateKey(privateKeyBytes));
}
/**/
