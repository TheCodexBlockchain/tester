// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2017-2019 The PIVX developers
// Copyright (c) 2021-2022 The DECENOMY Core Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "amount.h"

#include "tinyformat.h"

const std::string CURRENCY_UNIT = "USDX";

CFeeRate::CFeeRate(const CAmount& nFeePaid, size_t nSize)
{
    if (nSize > 0)
        nSatoshisPerK = (nFeePaid * 5) / 100; // Calculating the Flat 5% fee based on amount instead of per block size
    else
        nSatoshisPerK = 0; // If block size is 0 no fee will be charged
}

CAmount CFeeRate::GetFee(size_t nSize) const
{
    CAmount nFee = nSatoshisPerK; // This function will return the fee which has been directly set as per amount. Refer to line 16.
    return nFee;
}

std::string CFeeRate::ToString() const
{
    return strprintf("Flat 5%"); // Returned the Fee Rate which will be visible on Front
}
