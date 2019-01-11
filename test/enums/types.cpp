#include "gtest/gtest.h"

#include "enums/types.h"

TEST(enums, types)
{
    ASSERT_EQ(0, Phantom::Crypto::Enums::Types::TRANSFER);
    ASSERT_EQ(1, Phantom::Crypto::Enums::Types::SECOND_SIGNATURE_REGISTRATION);
    ASSERT_EQ(2, Phantom::Crypto::Enums::Types::DELEGATE_REGISTRATION);
    ASSERT_EQ(3, Phantom::Crypto::Enums::Types::VOTE);
    ASSERT_EQ(4, Phantom::Crypto::Enums::Types::MULTI_SIGNATURE_REGISTRATION);
    ASSERT_EQ(5, Phantom::Crypto::Enums::Types::IPFS);
    ASSERT_EQ(6, Phantom::Crypto::Enums::Types::TIMELOCK_TRANSFER);
    ASSERT_EQ(7, Phantom::Crypto::Enums::Types::MULTI_PAYMENT);
    ASSERT_EQ(8, Phantom::Crypto::Enums::Types::DELEGATE_RESIGNATION);
}
