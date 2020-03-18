/**
 *  @file   larpandora/ArtIOContent.cxx
 *
 *  @brief  Algorithm regsitration for Art IO content
 * 
 *  $Log: $
 */

#include "larpandora/LArPandoraInterface/ArtIOContent.h"

#include "Pandora/Pandora.h"
#include "Api/PandoraApi.h"

#include "larpandora/LArPandoraInterface/TestIOAlgorithm.h"

using namespace pandora;

StatusCode ArtIOContent::RegisterAlgorithms(const Pandora &pandora)
{
    PANDORA_THROW_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterAlgorithmFactory(
                pandora, "TestIO", new lar_pandora::TestIOAlgorithm::Factory));

    return STATUS_CODE_SUCCESS;
}

