// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 Elephancoin Developers
// Copyright (c) 2014 HotelCoin Developer
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

	// no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
(0,      uint256("0x7e30157a0c9b75d72063f32958b1ee2412385f08f15d5f45a5fad91fc5788ebb"))
(333,    uint256("0x4376bd1ef0c406fe55f7376be4e7942cf4e7cbf192c18341d0dbaffc9e703221"))
(555,    uint256("0x8f4811761092b88ee3aaa2833c43ba3b09ea426d8215f11fe42a9c1fb8b219cf"))
(727,    uint256("0xe5b7a8496a56135742dc8cbf894b4a84b50df44297f5a7b58113e6ddf3b0b97d"))
;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;

//### Default Value
return hash == i->second;

//### Produce Value
//return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;

//### Default Value
return mapCheckpoints.rbegin()->first;

//### Produce Value
//return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
//### Default Value
return t->second;

//### Produce Value
//return NULL;
        }
        return NULL;
    }
}
