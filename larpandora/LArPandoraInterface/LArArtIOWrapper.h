/**
 *  @file   larpandora/LArPandoraInterface/LArArtIOWrapper.h
 *
 *  @brief  A wrapper for Art parameters required for input/output to/from Pandora
 */

#pragma once
#ifndef LAR_ART_IO_WRAPPER_H
#define LAR_ART_IO_WRAPPER_H 1

#include "larpandora/LArPandoraInterface/ILArPandora.h"
#include "larpandora/LArPandoraInterface/LArPandoraOutput.h"

namespace art { class Event; }

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
     *  @param  settings The Pandora output settings
     *  @param  idToHitMap The Art ID to hit map
     *  @param  event The Art Event
     */
    LArArtIOWrapper(const LArPandoraOutput::Settings& settings,
            const IdToHitMap& idToHitMap, art::Event& event);

    /**
     *  @brief  Destructor
     */
    virtual ~LArArtIOWrapper();

    /**
     *  @brief  Return the Pandora output settings
     *
     *  @return The Pandora output settings
     */
    const LArPandoraOutput::Settings& GetPandoraOutputSettings() const;

    /**
     *  @brief  Return the map between the event ID and the hit map
     *
     *  @return The IdToHitMap
     */
    const IdToHitMap& GetIdToHitMap() const;

    /**
     *  @brief  Return the art Event
     *
     *  @return The art Event
     */
    art::Event& GetEvent() const;

private:
    art::Event& m_event;
    const IdToHitMap& m_idToHitMap;
    LArPandoraOutput::Settings m_outputSettings;
};

}

#endif // LAR_ART_IO_WRAPPER_H

