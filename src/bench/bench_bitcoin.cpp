// Copyright (c) 2015 The Bitcoin Core developers
// Copyright (c) 2015-2019 The Bitcoin Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "bench.h"

#include "crypto/sha256.h"
#include "key.h"
#include "main.h"
#include "sync.h"
#include "util.h"

#ifdef DEBUG_LOCKORDER
LockData lockdata;
#endif

int main(int argc, char **argv)
{
    SHA256AutoDetect();
    ECC_Start();
    SetupEnvironment();
    fPrintToDebugLog = false; // don't want to write to debug.log file

    benchmark::BenchRunner::RunAll();

    ECC_Stop();
}
