/**
 *  @file   larpandora/LArPandoraInterface/TestIOAlgorithm.cc
 *
 *  @brief  Header file for testing of Art IO.
 *
 *  $Log: $
 */

#include "larpandora/LArPandoraInterface/TestIOAlgorithm.h"

#include "Pandora/AlgorithmHeaders.h"
#include "larpandora/LArPandoraInterface/LArArtIOWrapper.h"
#include "larpandora/LArPandoraInterface/LArPandora.h"
#include "larpandora/LArPandoraInterface/LArPandoraOutput.h"

using namespace pandora;

namespace lar_pandora
{

TestIOAlgorithm::TestIOAlgorithm()
{
}

pandora::StatusCode TestIOAlgorithm::Run()
{
    const LArArtIOWrapper* artIOWrapper = LArPandora::GetArtIOWrapper(&this->GetPandora());
    LArPandoraOutput::ProduceArtOutput(artIOWrapper->GetPandoraOutputSettings(),
            artIOWrapper->GetIdToHitMap(), artIOWrapper->GetEvent());

    return STATUS_CODE_SUCCESS;
}

pandora::StatusCode TestIOAlgorithm::ReadSettings(const TiXmlHandle xmlHandle)
{
    (void)(xmlHandle);
    return STATUS_CODE_SUCCESS;
}

} // namespace lar_pandora

