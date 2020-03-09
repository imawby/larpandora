/**
 *  @file   larpandora/LArPandoraInterface/LArArtIOWrapper.h
 *
 *  @brief  A wrapper for Art parameters required for input/output to/from Pandora
 */

#ifndef LAR_ART_IO_WRAPPER_H
#define LAR_ART_IO_WRAPPER_H 1

#include "larpandora/LArPandoraInterface/ILArPandora.h"
#include "art/Framework/Principal/Event.h"

namespace lar_pandora
{

/**
 *  @brief  LArArtIOWrapper class
 */
class LArArtIOWrapper
{
public:
    /**
     *  @brief  Constructor
     *
     *  @param  event The Art Event
     *  @param  idToHitMap The Art ID to hit map
     */
    LArArtIOWrapper(const art::Event& event, const IdToHitMap& idToHitMap);

    /**
     *  @brief  Destructor
     */
    virtual ~LArArtIOWrapper();

    /**
     *  @brief  Return the art Event
     *
     *  @return The art Event
     */
    const art::Event& getEvent();

    /**
     *  @brief  Return the map between the event ID and the hit map
     *
     *  @return The IdToHitMap
     */
    const IdToHitMap& getIdToHitMap();

private:
    const art::Event& m_event;
    const IdToHitMap& m_idToHitMap;
};

}

#endif // LAR_ART_IO_WRAPPER_H

