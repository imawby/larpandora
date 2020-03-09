#include "larpandora/LArPandoraInterface/LArArtIOWrapper.h"

using namespace lar_pandora;

LArArtIOWrapper::LArArtIOWrapper(const art::Event& event, const IdToHitMap& idToHitMap) :
    m_event{event},
    m_idToHitMap{idToHitMap}
{
}

//------------------------------------------------------------------------------

LArArtIOWrapper::~LArArtIOWrapper()
{
}

//------------------------------------------------------------------------------

const art::Event& LArArtIOWrapper::getEvent()
{
    return m_event;
}

//------------------------------------------------------------------------------

const IdToHitMap& LArArtIOWrapper::getIdToHitMap()
{
    return m_idToHitMap;
}

