#include "larpandora/LArPandoraInterface/LArArtIOWrapper.h"

using namespace lar_pandora;

LArArtIOWrapper::LArArtIOWrapper(const LArPandoraOutput::Settings& settings,
        const IdToHitMap& idToHitMap, art::Event& event) :
    m_event{event},
    m_idToHitMap{idToHitMap},
    m_outputSettings{settings}
{
}

//------------------------------------------------------------------------------

LArArtIOWrapper::~LArArtIOWrapper()
{
}

//------------------------------------------------------------------------------

const LArPandoraOutput::Settings& LArArtIOWrapper::GetPandoraOutputSettings() const
{
    return m_outputSettings;
}

//------------------------------------------------------------------------------

const IdToHitMap& LArArtIOWrapper::GetIdToHitMap() const
{
    return m_idToHitMap;
}

//------------------------------------------------------------------------------

art::Event& LArArtIOWrapper::GetEvent() const
{
    return m_event;
}

