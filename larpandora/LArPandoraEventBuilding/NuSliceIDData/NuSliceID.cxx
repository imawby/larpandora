#include "larpandora/LArPandoraEventBuilding/NuSliceIDData/NuSliceID.h"

namespace larpandora
{
//---------------------------------------------------------------------------------------------

    NuSliceID::NuSliceID(const int pandoraNuSliceID, const int flashMatchNuSliceID) :
        m_pandoraNuSliceID(pandoraNuSliceID),
        m_flashMatchNuSliceID(flashMatchNuSliceID)
    {
    }

//---------------------------------------------------------------------------------------------

    int NuSliceID::GetPandoraNuSliceID() const
    {
        return m_pandoraNuSliceID;
    }

//---------------------------------------------------------------------------------------------

    int NuSliceID::GetFlashMatchNuSliceID() const
    {
        return m_flashMatchNuSliceID;
    }
//---------------------------------------------------------------------------------------------
}
