/**
 * This file is part of Phantom Cpp Crypto.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "identities/wif.h"

/**/
Phantom::Crypto::Identities::WIF::WIF(const char *const newWIFStr)
{ 
    (std::strlen(newWIFStr) == WIF_SIZE)
        ? void(std::memmove(
                this->bytes_,
                reinterpret_cast<const unsigned char*>(newWIFStr),
                WIF_SIZE))
        : void(this->bytes_[WIF_SIZE - 1] = { '\0' });   
}
/**/

/**/
Phantom::Crypto::Identities::WIF::WIF(const uint8_t *newWIFBytes)
{
    std::memmove(this->bytes_, newWIFBytes, WIF_SIZE);
}
/**/

/**/
const uint8_t* Phantom::Crypto::Identities::WIF::toBytes() { return this->bytes_; };
/**/

/**/
std::string Phantom::Crypto::Identities::WIF::toString() const
{
    return std::string(this->bytes_, this->bytes_ + WIF_SIZE);
}
/**/

/**
 * @brief Derive the WIF from the given passphrase.
 *
 * @param const char *const passphrase
 * @param uint8_t wifByte
 *
 * @return WIF
 **/
Phantom::Crypto::Identities::WIF Phantom::Crypto::Identities::WIF::fromPassphrase(
        const char *const passphrase,
        uint8_t wifByte
) {
    PrivateKey privateKey = PrivateKey::fromPassphrase(passphrase);
    std::string wifStr(53, '\0');
    Base58Check::privateKeyToBase58Check(
        Uint256(privateKey.toString().c_str()),
        wifByte,
        true,
        &wifStr[0]
    );
    return { wifStr.c_str() };
}
/**/
